//
// File:        ImplSource.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6482 $
// Description: Generate a skeleton implementation in Fortran
//
// Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory.
// Written by the Components Team <components@llnl.gov>
// UCRL-CODE-2002-054
// All rights reserved.
//
// This file is part of Babel. For more information, see
// http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
// for Our Notice and the LICENSE file for the GNU Lesser General Public
// License.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License (as published by
// the Free Software Foundation) version 2.1 dated February 1999.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
// conditions of the GNU Lesser General Public License for more details.
//
// You should have recieved a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA


package gov.llnl.babel.backend.fortran;

import gov.llnl.babel.Context;
import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.fortran.Fortran;
import gov.llnl.babel.backend.fortran.StubSource;
import gov.llnl.babel.backend.mangler.FortranMangler;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.mangler.NonMangler;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.CExprString;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.Struct;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolTable;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

/**
 * This class provides the ability to write a FORTRAN file with a
 * subroutine template for each method the end user has to implement for
 * a sidl class. The class will retain the previous user provided
 * implementation when overwriting a implementation file.
 */
public class ImplSource 
{
  private static final String s_use = ".use";

  /**
   * The code splicer stores the source code from the previous
   * implementation when overwriting an impl file.
   */
  private CodeSplicer          d_splicer;

  private Context              d_context;

  /**
    * Keep track of the local splicer declarations that are written
    * for rarrays since we don't want multiple splicer blocks.
    */

   private static HashSet spliceWritten = null;

  /**
   * This is the output device.
   */
  private LanguageWriterForFortran d_lw;

  /**
   * Hold a FORTRAN name mangler.
   */
  private NameMangler d_mang;

  /**
   * Generate an instance to generate a FORTRAN implementation template.
   * 
   * @param writer    the output device to which the FORTRAN implementation
   *                  should be written.
   * @param splicer   this stores the previous implementation when one
   *                  exists.
   * @exception java.security.NoSuchAlgorithmException
   *                  thrown when the JVM has not SHA hash algorithm.
   */
  public ImplSource(LanguageWriterForFortran writer,
                    CodeSplicer              splicer,
                    Context                  context)
    throws java.security.NoSuchAlgorithmException
  {
    d_lw      = writer;
    d_splicer = splicer;
    d_context = context;
    if (Fortran.needsAbbrev(context)) {
      d_mang =  new FortranMangler(AbbrevHeader.MAXNAME,
                                   AbbrevHeader.MAXUNMANGLED);
    }
    else {
      d_mang  =  new NonMangler();
    }
  }

  public static void useStatementsForSupers(Method m, SymbolID id, 
                                            LanguageWriterForFortran writer,
                                            CodeSplicer              splicer,
                                            Context                  context)
  throws CodeGenerationException {
    try{
      writer.tab();
      ImplSource source = new ImplSource(writer, splicer, context);
      source.useStatementsForSupers(m,id);
      writer.backTab();
    } catch (java.security.NoSuchAlgorithmException ex) {
      throw new CodeGenerationException("NoSuchAlgorithmException caught in Impl Source");
    }
  }
  
  public void useStatementsForSupers(Method m, SymbolID id) 
  throws CodeGenerationException {
    addUseForReferences(m, id);
    
  }

  /**
   * Return the function declaration, tailored to BindC.
   *
   * @param a    the argument
   * @param MethodName    the name of the current function name
   *
   * @return     the argument declaration string
   *
   * Function return types in Fortran are the name of the function itself and
   * as of 070208 this should only be called for 
   *   1) primitive SIDL types.
   *   2) From within a logical branch that selects only BindC.
   *
   */
  public String getFunctionRetTypeDecl(Argument a,String methodName)
    throws CodeGenerationException
  {
    final Type argType = a.getType();
    StringBuffer result = 
      new StringBuffer(Fortran.getReturnString(argType, d_context));
      result.append(" :: ");
      result.append(methodName);
    return result.toString();
  }

  /**
   * Return the argument declaration, tailored to the specific flavor
   * of FORTRAN.
   *
   * @param a    the argument
   *
   * @return     the argument declaration string
   */
  public String getArgumentDeclaration(Argument a)
    throws CodeGenerationException
  {
    final Type argType = a.getType();
    StringBuffer result = 
      new StringBuffer(Fortran.getReturnString(argType, d_context));
    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context) ) {
      if (argType.isRarray()) {
        result.append(", dimension");
        result.append(Fortran.arrayIndices(argType.getArrayIndexExprs()));
      }
      result.append(" :: ");
      result.append(a.getFormalName());
    } else {
      result.append(' ');
      result.append(a.getFormalName());
      if (argType.isRarray()) {
        result.append(Fortran.arrayIndices(argType.getArrayIndexExprs()));
      }
    }
    return result.toString();
  }

  /**
   * Generate the list of referenced symbols (including implied ones like
   * sidl.SIDLException when the method has exceptions).
   */
  private Set extendedReferences(Method m, SymbolID id)
  {
    Set refs = m.getSymbolReferences();
    HashSet set = new HashSet(refs.size() + 2);
    set.addAll(refs);
    if (!m.getThrows().isEmpty()) {
      Symbol baseInterface = d_context.getSymbolTable().lookupSymbol
        (BabelConfiguration.getBaseInterface());
      set.add(baseInterface.getSymbolID());
    }
    set.add(id);
    return set;
  }

  private static void checkType(Type t, Set result)
    throws CodeGenerationException
  {
    if (Type.ARRAY == t.getDetailedType()) {
      final Type arrayType = t.getArrayType();
      if (null != arrayType) {
        switch (arrayType.getDetailedType()) {
        case Type.ENUM:
        case Type.CLASS:
        case Type.INTERFACE:
        case Type.SYMBOL:
          result.add(arrayType.getSymbolID());
          break;
        case Type.ARRAY:
        case Type.PACKAGE:
          throw new CodeGenerationException
            ("Bad argument type in method");
        case Type.VOID:
          // no action
          break;
        default:
          result.add(new SymbolID("sidl." + arrayType.getTypeString(),
                                  new Version()));
          break;
        }
      }
      else {
        result.add(new SymbolID("sidl.array", new Version()));
      }
    }
  }

  private static Set arrayReferences(Method m)
    throws CodeGenerationException
  {
    Collection args = m.getArgumentList();
    HashSet result = new HashSet(args.size());
    Iterator i = args.iterator();
    while (i.hasNext()) {
      final Type t = ((Argument)i.next()).getType();
      checkType(t, result);
    }
    checkType(m.getReturnType(), result);
    return result;
  }

  private static String uniqueName(String name, int num)
  {
    final String numStr = Integer.toString(num);
    if (name.length() + numStr.length() + 1 <= 31) {
      return name + '_' + numStr;
    }
    return name.substring(0,30 - numStr.length()) + '_' + numStr;
  }

  private static F90Method convertMethod(Method m, SymbolID id, 
                                         Context context)
    throws CodeGenerationException
  {
    List extendedArgs = StubSource.extendArgs(id, m, context, true);
    return new F90Method(m.getShortMethodName(), extendedArgs);
  }

  public Map findCollisions(Map methodsSeen,
                            Symbol sym)
    throws CodeGenerationException
  {
    HashMap result = new HashMap();
    if (sym instanceof Extendable) {
      final Extendable ext = (Extendable)sym;
      final SymbolID id = ext.getSymbolID();
      Collection methods = ext.getMethods(true);
      Iterator i = methods.iterator();
      while (i.hasNext()) {
        F90Method f90m = convertMethod((Method)i.next(), id, d_context);
        if (methodsSeen.containsKey(f90m)) {
          final Integer value = (Integer)methodsSeen.get(f90m);
          final int newValue = value.intValue() + 1;
          methodsSeen.put(f90m, new Integer(newValue));
          result.put(f90m.getName(), 
                     uniqueName(f90m.getName(), newValue));
        }
        else {
          methodsSeen.put(f90m, new Integer(1));
        }
      }
    }
    return result;
  }

  private class RefComp implements Comparator
  {
    public int compare(Object o1, Object o2)
    {
      final SymbolID sid1 = (SymbolID)o1;
      final SymbolID sid2 = (SymbolID)o2;
      final SymbolTable table = d_context.getSymbolTable();
      final Symbol sym1 = table.lookupSymbol(sid1);
      final Symbol sym2 = table.lookupSymbol(sid2);
      final int depth1 = (sym1 == null) ? -1 : sym1.getDepth();
      final int depth2 = (sym2 == null) ? -1 : sym2.getDepth();
      final int depthCompare = depth1 - depth2;
      if (depthCompare == 0) {
        return sid1.compareTo(sid2);
      }
      return depthCompare;
    }
  }

  private List sortReferences(Collection refs)
  {
    Object[] objs = refs.toArray();
    Arrays.sort(objs, new RefComp());
    ArrayList result = new ArrayList(objs.length);
    for(int i = 0; i < objs.length; ++i) {
      result.add(objs[i]);
    }
    return result;
  }

  public void addUseForReferences(Method m,
                                   SymbolID id)
    throws CodeGenerationException
  {
    List refs      = sortReferences(extendedReferences(m, id));
    HashSet appeared = new HashSet(refs.size());
    HashMap methodsSeen = new HashMap();
    d_lw.generateUse("sidl", methodsSeen);
    d_lw.generateUse(BabelConfiguration.getNotImplemented().replace('.', '_'), methodsSeen);
    Iterator i = refs.iterator();
    while (i.hasNext()) {
      final SymbolID refid = (SymbolID)i.next();
      if (!appeared.contains(refid)) {
        final Map renameMap = 
          findCollisions(methodsSeen, Utilities.lookupSymbol(d_context,refid));
        d_lw.generateUse(Fortran.getModule(refid), renameMap);
        appeared.add(refid);
      }
    }
    // do array references now
    refs = sortReferences(arrayReferences(m));
    appeared.clear();
    i = refs.iterator();
    TreeMap emptyMap = new TreeMap();
    while (i.hasNext()) {
      final SymbolID refid = (SymbolID)i.next();
      if (!appeared.contains(refid)) {
        d_lw.generateUse(Fortran.getArrayModule(refid), emptyMap);
        appeared.add(refid);
      }
    }
  }

  private String[] initialContent(SymbolID id,
                                  String method)
  {
    if (IOR.getBuiltinName(IOR.CONSTRUCTOR).equals(method)) {
      final String fullName = id.getFullName().replace('.', '_');
      String defaultCtor[] = {
        "! boilerplate contructor",
        "type(" + fullName + "_wrap" + ") :: dp",
        "allocate(dp%d_private_data)",
        "! initialize contents of dp%d_private_data here",
        "call " + fullName + "__set_data_m(self, dp)"
      };
      return defaultCtor;
    }
    else if (IOR.getBuiltinName(IOR.DESTRUCTOR).equals(method)) {
      final String fullName = id.getFullName().replace('.', '_');
      String defaultDtor[] = {
        "! boilerplate contructor",
        "type(" + fullName + "_wrap" + ") :: dp",
        "call " + fullName + "__get_data_m(self, dp)",
        "! release resources in dp%d_private_data here",
        "deallocate(dp%d_private_data)",
      };
      return defaultDtor;
    }
    return null;
  }

  /**
   * Write the FORTRAN server side implementation subroutine 
   * that corresponds to a sidl method. This writes the method
   * signature, declares the type of the argument, and then includes
   * a {@link gov.llnl.babel.backend.CodeSplicer CodeSplicer} section and
   * its contents.
   * 
   * @param m     the method whose implementation template is to be
   *              written.
   * @param id    the name of the class that owns this method.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void extendAndGenerate(Method   m,
                                 SymbolID id)
    throws CodeGenerationException
  {
    spliceWritten = new HashSet();
    List extendedArgs    = StubSource.extendArgs(id, m, d_context, true);
    String splicerTag    = id.getFullName() + '.' + m.getLongMethodName();
    String splicerTagUse = splicerTag + s_use;
    String splicerTagLocal = splicerTag+".local_declarations";
    String methodImplName = Fortran.getMethodImplName(id, m, d_mang, 
                                                      d_context);
    boolean gotFunc=isFortranFunction(m.getReturnType());

    d_lw.println();
    d_lw.println();

    d_lw.writeComment(m, false);

    if (gotFunc && Fortran.hasBindC(d_context)) {
      /**
        * Right now functions are only for the F03 binding 
      **/
        d_lw.print("function " + methodImplName + "(");
        Iterator i = extendedArgs.iterator();
        while (i.hasNext()) {
          String argName = ((Argument)i.next()).getFormalName();
          if (!(argName.equals(Fortran.s_return))) {
            d_lw.print(argName);
            if (i.hasNext()) {
              d_lw.print(", ");
            }
          }
        }
        d_lw.println(")");
    } else {
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        d_lw.print("recursive ");
      }
      d_lw.print("subroutine " + methodImplName + "(");
      Iterator i = extendedArgs.iterator();
      while (i.hasNext()) {
        d_lw.print(((Argument)i.next()).getFormalName());
        if (i.hasNext()) {
          d_lw.print(", ");
        }
      }
      d_lw.println(")");
    }

    if (Fortran.hasBindC(d_context)){
      d_lw.tab();
      d_lw.println("use, intrinsic :: iso_c_binding");
      d_lw.backTab();
    }

    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
      d_lw.tab();
      addUseForReferences(m, id);
      d_lw.generateUse( id.getFullName().replace('.','_') + "_impl", new TreeMap());
      d_splicer.splice (splicerTagUse, d_lw, "use statements");
    }

    d_lw.println("implicit none");
    Iterator i = Fortran.reorderArguments(extendedArgs).iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      String decl = getArgumentDeclaration(a); 
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        //Retarded special case to make ctor2 work
        if(m.equals(IOR.getBuiltinMethod(IOR.CONSTRUCTOR2,id,d_context)) &&
          a.getType().getType() == Type.OPAQUE && 
          a.getFormalName().equals("private_data")) {
          d_lw.println("type(" + id.getFullName().replace('.', '_') + 
                      "_wrap" + ") :: private_data");
        } else {
          //Some ugly logic--for later cleanup-SPM
          if (gotFunc && Fortran.hasBindC(d_context)) {
            if (!a.getFormalName().equals(Fortran.s_return)){
              d_lw.println(decl);
            } else {
              String fDecl = getFunctionRetTypeDecl(a,methodImplName); 
              d_lw.println(fDecl);
            }  
          } else {
            d_lw.println(decl);
          }
        d_lw.writeCommentLine(a.getModeString());
        }
      } else {
        d_lw.writeCommentLine(a.getArgumentString());
        d_lw.println(decl);
      }
    }

    d_lw.println();
    d_lw.println();

    /** Additional code to handle the case where we are using F2003 (bindC) struct
     *  support and there is a raw-array within that struct.  In this case we
     *  need to convert the c pointer into a fortran pointer--SPM 
     * 
     *  First pass for the declarations **/
    i = Fortran.reorderArguments(extendedArgs).iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      String decl = getArgumentDeclaration(a); 
      if (Fortran.hasBindC(d_context)){
        Type type = a.getType();
        int t=type.getDetailedType();
        switch(t) {
        case Type.ARRAY:
          /*no-op*/
          break;
        case Type.STRUCT:
          SymbolTable table = d_context.getSymbolTable();
          Symbol sym = table.lookupSymbol(type.getSymbolID());
          if (sym != null) {
            if (sym instanceof Struct) {
              Struct strct=(Struct)sym;
              generateImplDeclaration(strct,a,splicerTagLocal,methodImplName);
            }
          }
          break;
        default:
          /*no-op*/
          break;
        } 
      }
    }


    /** Second pass for the C_F_Pointer calls **/
    i = Fortran.reorderArguments(extendedArgs).iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      String decl = getArgumentDeclaration(a); 
      if (Fortran.hasBindC(d_context)){
        Type type = a.getType();
        int t=type.getDetailedType();
        switch(t) {
        case Type.ARRAY:
          /*no-op*/
          break;
        case Type.STRUCT:
          SymbolTable table = d_context.getSymbolTable();
          Symbol sym = table.lookupSymbol(type.getSymbolID());
          if (sym != null) {
            if (sym instanceof Struct) {
              Struct strct=(Struct)sym;
              generateImplCall(strct,a,splicerTagLocal);
            }
          }
          break;
        default:
          /*no-op*/
          break;
        } 
      }
    }

    d_lw.println();
    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
      d_lw.backTab();
    }

    spliceInitialContent(m, splicerTag);
    if (gotFunc && Fortran.hasBindC(d_context)){
      /**
        * Right now functions are only for the F03 binding 
      **/
      if (Fortran.hasBindC(d_context)){
        d_lw.println("end function " + methodImplName);
      } 
    }else {
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        d_lw.println("end subroutine " + methodImplName);
      } else {
        d_lw.println("end");
      }
    }
  }

  private void spliceInitialContent(Method m, String splicerTab) {
    String sName   = m.getShortMethodName();
    String alt_msg          = sName + " method";
    String defaultComment[] = {
      "This method has not been implemented" 
    };
    
    if (  (!sName.endsWith("_pre")) && (!sName.endsWith("_post")) ) {
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        String defaultCode[] = {};
        String notImplExWithCCA[] = {
          "  ! DO-DELETE-WHEN-IMPLEMENTING exception.begin(" + splicerTab + ")",
          "  type(sidl_BaseInterface_t) :: throwaway",
          "  type(sidl_NotImplementedException_t) :: notImpl",
          "  call new(notImpl, exception)",
          "  call setNote(notImpl, \'Not Implemented\', exception)",
          "  call cast(notImpl, exception,throwaway)",
          "  call deleteRef(notImpl,throwaway)",
          "  return",
          "  ! DO-DELETE-WHEN-IMPLEMENTING exception.end(" + splicerTab + ")",
        };
        if (  d_context.getConfig().getCCAMode() == true ) { 
          defaultCode = notImplExWithCCA;
        }
        d_splicer.splice(splicerTab, d_lw, alt_msg, defaultComment, 
                         defaultCode);
      } else {
        String defaultCode[] = {};
        String notImplExWithCCA[] = {
          "C       DO-DELETE-WHEN-IMPLEMENTING exception.begin(" + splicerTab + ")",
          "        integer*8 throwaway",
          "        call sidl_NotImplementedException__create_f",
          "     $      (exception, throwaway)",
          "        if (exception .ne. 0) then",
          "           call sidl_NotImplementedException_setNote_f(",
          "     $         exception,", 
          "     $         \'This method has not been implemented\',",
          "     $         throwaway)",
          "        endif",
          "        return",
          "C       DO-DELETE-WHEN-IMPLEMENTING exception.end(" + splicerTab + ")"
        };
        if ( d_context.getConfig().getCCAMode() == true ) { 
            defaultCode = notImplExWithCCA;
        }
        d_splicer.splice(splicerTab, d_lw, alt_msg, defaultComment, 
                         defaultCode);
      } 
    } else {
      d_splicer.splice(splicerTab, d_lw, alt_msg, defaultComment);
    }

  }
  

  /**
   * Add the builtin methods to the list of methods that must be
   * implemented.
   *
   * @param ext the class whose implementation is being written.
   */
  private Collection extendMethods(Class ext) throws CodeGenerationException {
    Collection localMethods = ext.getMethods(false);
    final SymbolID id = ext.getSymbolID();
    ArrayList  extendedMethods = new ArrayList(localMethods.size()+2);
    extendedMethods.
      add(IOR.getBuiltinMethod(IOR.CONSTRUCTOR, id, d_context));
    extendedMethods.
      add(IOR.getBuiltinMethod(IOR.CONSTRUCTOR2, id, d_context));
    extendedMethods.
      add(IOR.getBuiltinMethod(IOR.DESTRUCTOR, id, d_context));
    extendedMethods.
	add(IOR.getBuiltinMethod(IOR.LOAD, id, d_context));
    extendedMethods.addAll(localMethods);
    return extendedMethods;
  }

  private void addMiscCodeSection(String sectionName)
  {
    d_splicer.splice(sectionName, d_lw, "extra code");
  }

  /**
   * Write #include for all the abbreviation files for
   * referenced symbols.
   */
  private void writeIncludes(Class cls)
    throws CodeGenerationException
  {
    Iterator i = ModuleSource.extendedReferences(cls, d_context).iterator();
    try {
      d_lw.pushLineBreak(false);
      d_lw.generateInclude( Fortran.getStubNameFile(d_context.getSymbolTable().lookupSymbol(BabelConfiguration.getNotImplemented()).getSymbolID()) );
      while (i.hasNext()) {
        SymbolID id = (SymbolID)i.next();
        d_lw.generateInclude( Fortran.getStubNameFile(id) );
      }
      i = cls.getBasicArrayRefs().iterator();
      while (i.hasNext()) {
        SymbolID id = (SymbolID)i.next();
        d_lw.generateInclude( Fortran.getStubNameFile(id) );
      }
    }
    finally {
      d_lw.popLineBreak();
    }
  }

  /**
   * Generate the implementation FORTRAN file for a sidl class.  The
   * implementation file contains all the subroutines that need to be
   * implemented for the class, and when replacing an implementation file, 
   * the previous implementation is retained.
   * 
   * @param cls    the sidl class whose implementation is to be written.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void generateCode(Class cls)
    throws CodeGenerationException
  {
    Collection methods = extendMethods(cls);
    final SymbolID id = cls.getSymbolID();

    d_lw.writeBanner(cls, Fortran.getImplFile(id, d_context), true, 
                     CodeConstants.C_DESC_IMPL_PREFIX + id.getFullName());
    d_lw.println();
    d_lw.writeComment(cls, false);
    d_lw.println();

    if (Fortran.needsAbbrev(d_context)) {
      writeIncludes(cls);
    }

    addMiscCodeSection("_miscellaneous_code_start");
    d_lw.println();
    d_lw.println();

    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if (!m.isAbstract()) {
        if ( (IOR.generateHookMethods(cls, d_context)) && (!m.isBuiltIn()) ) {
          extendAndGenerate(m.spawnPreHook(), id);
          extendAndGenerate(m, id);
          extendAndGenerate(m.spawnPostHook(false, false), id);
        } else {
          extendAndGenerate(m, id);
        }
      }
    }
    d_lw.println();
    d_lw.println();
    addMiscCodeSection("_miscellaneous_code_end");



    /*
     * Finally, output unreferenced edit blocks, if any.
     */
    if (d_splicer.hasUnusedSymbolEdits()) {
      d_lw.println();
      d_lw.beginBlockComment(true);
      d_lw.println(CodeConstants.C_BEGIN_UNREFERENCED_METHODS);
      d_lw.println(CodeConstants.C_UNREFERENCED_COMMENT1);
      d_lw.println(CodeConstants.C_UNREFERENCED_COMMENT2);
      d_lw.println(CodeConstants.C_UNREFERENCED_COMMENT3);
      d_lw.endBlockComment(true);
      d_splicer.outputUnusedSymbolEdits(d_lw); 
      d_lw.writeCommentLine(CodeConstants.C_END_UNREFERENCED_METHODS);
    }
  }

  /**
   * Generate the implementation FORTRAN file for a sidl class.  The
   * implementation file contains all the subroutines that need to be
   * implemented for the class, and when replacing an implementation file, 
   * the previous implementation is retained.
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   * @exception java.security.NoSuchAlgorithmException
   *   A problem with the name mangler.
  */
  public static void generateCode(Class cls,
                                  LanguageWriterForFortran writer,
                                  CodeSplicer splicer,
                                  Context context)
    throws CodeGenerationException, NoSuchAlgorithmException
  {
    ImplSource source = new ImplSource(writer, splicer, context);
    source.generateCode(cls);
  }

public static boolean isInt (String s) {

  /**
   * If a String can be parsed into an Integer return true.
   * Used to check r-array indices.
  */

   try {
     int i = Integer.parseInt(s.trim());
     return true;
   } catch (NumberFormatException nfe) {
     return false;
   }
  }

private void generateImplDeclaration(Struct strct,
                                     Argument a,
                                     String splicerTagLocal,
                                     String methodImplName)
  {

    String strctName=a.getFormalName();

    Iterator ii = strct.getItems().iterator(); 
    while (ii.hasNext()){

      final Struct.Item item = (Struct.Item)ii.next();

      Type tt = item.getType();

      /* ttype is the Type integer of the Array */
      int ttype = tt.getDetailedType();
      if (ttype==Type.ARRAY){
        Type aType = tt.getArrayType();
        if (null != aType){
          if (tt.isRarray()){
            Iterator indexVar = tt.getArrayIndexExprs().iterator();
            AssertionExpression ae = (AssertionExpression)indexVar.next();
            String checkInt = ae.toString();
            if (!isInt(checkInt)){
              if (tt.isNumericArray()){

                /* Only want one local splicer block per method iff a
                struct w/rarray is present */
                if(!spliceWritten.contains(methodImplName)) {
                  /* splicer block so implementor can add local declarations */
                  d_splicer.splice (splicerTagLocal, d_lw, "local declarations");
                  d_lw.println();
                  spliceWritten.add(methodImplName);
                }

                Babel2BindCType bbc = new Babel2BindCType();
                Integer objInt = new Integer(aType.getBasicType());
      
                StringBuffer ptrString=new StringBuffer();
                ptrString.append(bbc.getBindCType(objInt)+",dimension(:");                       
    
                int dims=tt.getArrayDimension();
    
                for(int ij = 1 ; ij < dims; ij++){
                  ptrString.append(",:"); 
                }
                String fptr=strctName+"_"+item.getName()+"_fptr";
                ptrString.append("),pointer :: "+fptr);
    
                d_lw.println(ptrString.toString());
                d_lw.println();

              }
            }
          }
        }
      }
    }
  }

private void generateImplCall(Struct strct,
                                     Argument a,
                                     String splicerTagLocal)
  throws CodeGenerationException 
  {
    String strctName=a.getFormalName();

    /* Now take care of C_F_POINTER calls */

    Iterator ii = strct.getItems().iterator(); 
    while (ii.hasNext()){
      final Struct.Item item = (Struct.Item)ii.next();
      Type tt = item.getType();


      /* ttype is the Type integer of the Array */
      int ttype = tt.getDetailedType();
      if (ttype==Type.ARRAY){
        Type aType = tt.getArrayType();
        if (null != aType){
          if (tt.isRarray()){
            if (tt.isNumericArray()){
              Iterator indexVar = tt.getArrayIndexExprs().iterator();
              AssertionExpression ae = (AssertionExpression)indexVar.next();
              String checkInt = ae.toString();
              if (!isInt(checkInt)){

                String fptr=strctName+"_"+item.getName()+"_fptr";
                final int dims=tt.getArrayDimension();

                d_lw.println("call C_F_POINTER(CPTR="+strctName+"%"+item.getName()+", & "); 
                d_lw.println("                 FPTR="+fptr+", & "); 

                StringBuffer dimString = new StringBuffer();
                dimString.append("                 SHAPE=(/");

                dimString.append("DIM");

                for(int ij = 1; ij < dims && indexVar.hasNext(); ij++ ) {
                  dimString.append(",DIM");
                }

                dimString.append("/))"); 

                d_lw.println(dimString.toString()); 
                d_lw.println(); 
              }
            }else{
              throw new CodeGenerationException("Babel: Error Rarrays in Structs with BindC must have a numeric Type."); 
            }
          }
        }
      }
    }
  }


  /**
   * Utility function that checks if we have a fortran function
   * that returns primitve types.
   *
   * @param Type is m.getReturnType()
   */
  public static boolean isFortranFunction(Type check)
  {
    boolean gotFunc=false;
    if (check.isF03FuncRetType()) {
      gotFunc=true;
    } else {
      gotFunc=false;
    }
    return gotFunc;
  }

}
