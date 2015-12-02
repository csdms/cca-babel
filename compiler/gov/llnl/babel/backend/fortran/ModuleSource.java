//
// File:        ModuleSource.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6494 $
// Description: Generate a module file for FORTRAN 90 clients
//
// Copyright (c) 2002-2003, Lawrence Livermore National Security, LLC
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

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.fortran.Fortran;
import gov.llnl.babel.backend.fortran.StubSource;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.FortranExprString;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Comment;
import gov.llnl.babel.symbols.Enumeration;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.Inverter;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolTable;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

/**
 * This class provides the ability to write a FORTRAN 90 module for
 * a sidl class/interface. 
 */
public class ModuleSource {
  private Context d_context;

  private static final int s_CASTS_PER_LINE = 7;

  /**
   * If Fortran90 is being generated, we need to keep track of 
   * what explicit method interfaces have been already generated.
   */
  private static HashSet interfacesWritten = null;

  /**
   * If Fortran90 is being generated, we need to keep track of
   * what explicit method dispatches have been already generated.
   */
  private static HashSet dispatchesWritten = null;

  /**
   * This is the output device.
   */
  private LanguageWriterForFortran d_lw;

  private static final String[] s_intent_spec = {
    ", intent(in)",
    ", intent(inout)",
    ", intent(out)"
  };

  /**
   * Generate an instance to write the module for a FORTRAN 90
   * client.
   * 
   * @param writer  the output device to which the FORTRAN 90 module
   *                  should be written.
   */
  public ModuleSource(LanguageWriterForFortran writer,
                      Context context) {
    d_lw = writer;
    d_context = context;
  }

  /**
   * This is a convenience utility function specifically for the generation
   * of super "Stub" functions in the Impl files. 
   * The output stream is not closed on exit.  A code
   * generation exception is thrown if an error is detected.
   *
   * @param writer the output writer to which the stub source will
   *               be written. This will not be closed.
   *
   * @param cls The class in which these supers are to be generated      
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  public static void generateSupers(Class             cls,
                                    LanguageWriterForFortran writer,
                                    CodeSplicer              splicer,
                                    Context                  context,
                                    NameMangler mang)
    throws CodeGenerationException
  {
    ModuleSource source = new ModuleSource(writer, context);
    source.generateSupers(cls, splicer, mang);
  }  

  public void generateSupers(Class cls, CodeSplicer splicer, NameMangler mang)
    throws CodeGenerationException
  {
    Collection methods = cls.getOverwrittenClassMethods();
    for (Iterator m = methods.iterator(); m.hasNext(); ) {
      Method method = (Method) m.next();
      extendAndGenerateSuper(cls, method, splicer, mang);
    }
  }  


  /**
   * Generate the argument list for the subroutine, including the
   * opening and closing parens.
   *
   * @param List     List of arguments to be printed
   */
  private void printArgs(List args)
  {
    d_lw.print("(");
    Iterator i = args.iterator();
    while (i.hasNext()) {
      d_lw.print(((Argument)i.next()).getFormalName());
      if (i.hasNext()) {
        d_lw.print(", ");
      }
    }
    d_lw.println(")");
  }

  /**
   * Write out the declaration of an argument.
   */
  private void declareArgument(Argument a,
                               boolean showIntent)
    throws CodeGenerationException
  {
    Type argType = a.getType();
    d_lw.writeCommentLine(a.getArgumentString());
    d_lw.print(Fortran.getReturnString(argType, d_context));
    if (showIntent) {
      d_lw.print(" " + s_intent_spec[a.getMode()]);
    }
    if (argType.isRarray()) {
      Iterator indexVar = argType.getArrayIndexExprs().iterator();
      AssertionExpression ae = (AssertionExpression)indexVar.next();
      final int dimen = argType.getArrayDimension();
      d_lw.print(", dimension(:");
      int count = 1;
      while(indexVar.hasNext()) {
        ae = (AssertionExpression)indexVar.next();
        d_lw.print(", :");
        count++;
      }

      if (count != dimen){
        throw new CodeGenerationException("Babel: Error in Rarray dimensions. Dimensions="+dimen+" of type don't match those given in name "+a.getFormalName()+" (dimensions="+count+").");
      }

      d_lw.print(")");
    }
    d_lw.println(" :: " + a.getFormalName());
  }


  /**
   * Write the FORTRAN 90 module for a subroutine that corresponds to a 
   * sidl class/interface method. This writes method signatures and declares 
   * the types of the arguments.
   * 
   * @param m     the method whose module method is to be written.
   * @param id    the name of the class that owns this method.
   * @param suffix string to add to method name
   * @param convertRarray <code>true</code> means that rarray arguments
   *                      should be converted to normal arrays before
   *                      writing them out.
   * @exception   gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void writeMethodStub(Method   m,
                               SymbolID id,
                               String suffix,
                               boolean convertRarray,
                               boolean isBuiltin)
    throws CodeGenerationException
  {

    List extendedArgs = StubSource.extendArgs(id, m, d_context, false);
    Map indexMap;
    final String methodName = m.getLongMethodName() + suffix;
    if(isBuiltin) {
      m.setMethodName("_"+m.getShortMethodName());
    }
    String stubName = 
      (convertRarray ? Fortran.getAltStubName(id, m) 
       : Fortran.getMethodStubName(id, m, d_context));

    d_lw.print("recursive subroutine " + methodName);
    if (convertRarray) {
      extendedArgs = StubSource.convertRarrayToArray(extendedArgs, d_context);
      indexMap = new HashMap(0);
    }
    else {
      indexMap = m.getRarrayInfo();
    }
    printArgs(extendedArgs);

    d_lw.tab();

    if (Fortran.hasBindC(d_context)){
      d_lw.println("use, intrinsic :: iso_c_binding");

      Iterator i = extendedArgs.iterator();
      while (i.hasNext()) {
        Argument a = (Argument)i.next();
        Type t=a.getType();
        if (t.isStruct()){
          SymbolID idTest=t.getSymbolID();
          d_lw.generateUse(Fortran.getModule(idTest), new TreeMap());
        }
      }
    }

    d_lw.println("implicit none");

    Iterator i = extendedArgs.iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      declareArgument(a, true);
    }
    // declare array indices
    i = indexMap.entrySet().iterator();
    while (i.hasNext()) {
      Map.Entry ent = (Map.Entry)i.next();
      String indexVar = (String)ent.getKey();
      Collection choice = (Collection)ent.getValue();
      if (choice.size() > 0) {
        Method.RarrayInfo info = (Method.RarrayInfo)choice.iterator().next();
        declareArgument(info.index, false);
      }
    }
    d_lw.println();
    d_lw.println("external " + stubName);
    i = indexMap.entrySet().iterator();
    while (i.hasNext()) {
      Map.Entry ent = (Map.Entry)i.next();
      String indexVar = (String)ent.getKey();
      Collection choice = (Collection)ent.getValue();
      if (choice.size() > 0) {
        Method.RarrayInfo info = (Method.RarrayInfo)choice.iterator().next();
        d_lw.print(indexVar + " = ");
        d_lw.println(FortranExprString.
                   toFortranString(Inverter.invertExpr
                                   ((AssertionExpression)
                                    info.rarray.getType().
                                    getArrayIndexExprs().get(info.dim),
                                    "size(" +
                                    info.rarray.getFormalName() + ", " +
                                    (info.dim+1) + ')', d_context)));
      }
    }
    d_lw.print("call " + stubName);
    if (convertRarray) {
      printArgs(extendedArgs);
    }
    else {
      printArgs(StubSource.extendArgs(id, m, d_context, true));
    }
    d_lw.backTab();
    d_lw.println();
    d_lw.println("end subroutine " + methodName);
  }

  /**
   * Write the FORTRAN 90 module for a subroutine that corresponds to a 
   * sidl class/interface method. This writes method signatures and declares 
   * the types of the arguments.
   * 
   * @param m     the method whose module method is to be written.
   * @param id    the name of the class that owns this method.
   * @param isInterface true iff the method is in an interface (as opposed
   *                    to a class.
   * @exception   gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void extendAndGenerate(Method   m,
                                 SymbolID id)
    throws CodeGenerationException
  {
    d_lw.println();
    d_lw.println();

    if (m.hasRarray()) {
      writeMethodStub(m, id, "_1s", true, false);
      d_lw.println();
      writeMethodStub(m, id, "_2s", false, false);
    }
    else {
      writeMethodStub(m, id, "_s", false,false);
    }
  }
  
  /**
   * Generate the extended argument list for a method and then generate the
   * stub code for the method.
   * 
   * @param m           the method to be generated.
   * @param id          the name of the class/interface who owns the method.
   * @param isInterface is the method owned by a class or interface.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception for problems in the code generation phase.
   */
  private void extendAndGenerateSuper(Class cls, 
                                      Method   m,
                                      CodeSplicer              splicer,
                                      NameMangler mang)
    throws CodeGenerationException
  {
    SymbolID id = cls.getSymbolID();
    List extendedArgs = StubSource.extendArgs(id, m, d_context, false);
    final String methodName = Fortran.getMethodSuperImplName(id,m,mang,
                                                             d_context);//"super_"+ m.getLongMethodName() + "_s";
    final String stubName = Fortran.getMethodSuperName(id, m, mang, d_context);
    d_lw.print("recursive subroutine " + methodName);
    printArgs(extendedArgs);

    ImplSource.useStatementsForSupers(m,id,d_lw, splicer, d_context);

    d_lw.tab();
    d_lw.println("implicit none");

    Iterator i = extendedArgs.iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      d_lw.writeCommentLine(a.getArgumentString());
      d_lw.println(Fortran.getReturnString(a.getType(), d_context) + " " +
                   s_intent_spec[a.getMode()] + " :: " 
                   + a.getFormalName());
    }
    d_lw.println();
    d_lw.println("external " + stubName);
    d_lw.print("call " + stubName);
    printArgs(extendedArgs);

    d_lw.backTab();
    d_lw.println();
    d_lw.println("end subroutine " + methodName);
    d_lw.println();
  }




  /**
   * Generate a create method object.
   */
  private Method create(SymbolID id)
  {
    Method m = new Method(d_context);
    m.setMethodName("new", "Local");
    m.setDefinitionModifier(Method.STATIC);
    String[] s = new String[1];
    s[0] = "Create an instance of class " + id.getFullName();
    m.setComment(new Comment(s));
    m.setReturnType(new Type(id, d_context));
    m.addImplicitThrows(IOR.getRuntimeException(d_context));
    return m;
  }

  public static Set extendedReferences(Extendable ext, Context context)
    throws CodeGenerationException
  {
    Set s = StubSource.extendedReferences(ext, context);
    s.add(ext.getSymbolID());
    Iterator i = ext.getParents(true).iterator();
    while (i.hasNext()) {
      s.add(((Symbol)i.next()).getSymbolID());
    }
    return s;
  }


  /**
   * Add the implicit stub methods to the list of those that must
   * be included.
   *
   * @param ext the class whose module file is being written.
   */
  private Collection extendMethods(Extendable ext)
  {
    Collection allMethods = ext.getMethods(true);
    final SymbolID id = ext.getSymbolID();
    ArrayList  extendedMethods = new ArrayList(allMethods.size()+1);
    if (!ext.isAbstract()) {
      extendedMethods.add(create(id));
      extendedMethods.add(Fortran.createRemoteMethod(ext, d_context, ( Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context) )));
    }
    extendedMethods.add(Fortran.connectRemoteMethod(ext, d_context, Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)));
    
    extendedMethods.addAll(allMethods);
    return extendedMethods;
  }


  /**
   * Write #include for all the abbreviation files for
   * referenced symbols.
   */
  private void writeIncludes(Extendable ext)
    throws CodeGenerationException
  {
    Set s = extendedReferences(ext, d_context);
    s.add(ext.getSymbolID());
    Iterator i = s.iterator();
    try {
      d_lw.pushLineBreak(false);
      while (i.hasNext()) {
        SymbolID id = (SymbolID)i.next();
        d_lw.generateInclude( Fortran.getStubNameFile(id) );
      }
    }
    finally {
      d_lw.popLineBreak();
    }
  }

  private void includeType(SymbolID id)
  {
    d_lw.generateUse( Fortran.getTypeModule(id), new TreeMap());
  }

  private static void checkType(Type t, Set result)
  {
    if (t.getDetailedType() == Type.ARRAY) {
      final Type arrayType = t.getArrayType();
      if (null != arrayType) {
        final int detailedType = arrayType.getDetailedType();
        if ((detailedType > Type.VOID) && (detailedType <= Type.STRING)) {
          result.add(new SymbolID("sidl." + arrayType.getTypeString(),
                                  new Version()));
        }
      }
      else {
        result.add(new SymbolID("sidl.array", new Version()));
      }
    }
  }

  private static Set basicArrayReferences(Extendable ext)
  {
    HashSet result = new HashSet();
    Iterator i = ext.getMethods(true).iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      checkType(m.getReturnType(), result);
      Iterator j = m.getArgumentList().iterator();
      while (j.hasNext()) {
        checkType(((Argument)j.next()).getType(), result);
      }
    }
    return result;
  }

  private void includeTypes(Extendable ext) 
    throws CodeGenerationException
  {
    final SymbolID id = ext.getSymbolID();
    final SymbolTable table = d_context.getSymbolTable();
    Set s = extendedReferences(ext, d_context);
    d_lw.generateUse("sidl", new TreeMap());
    s.add(id);
    Iterator i = s.iterator();
    while (i.hasNext()) {
      SymbolID current = (SymbolID)i.next();
      Symbol sym = table.lookupSymbol(current);
      if ((sym instanceof Extendable) || (sym instanceof Enumeration)) {
        includeType(current);
      }
    }
    includeType(table.lookupSymbol("sidl.rmi.Call").getSymbolID());
    includeType(table.lookupSymbol("sidl.rmi.Return").getSymbolID());
    includeType(table.lookupSymbol("sidl.rmi.Ticket").getSymbolID());

    TreeMap emptyMap = new TreeMap();
    s = basicArrayReferences(ext);
    i = s.iterator();
    while (i.hasNext()) {
      SymbolID basic_array = (SymbolID)i.next();
      d_lw.generateUse(Fortran.getArrayModule(basic_array),emptyMap);
    }
  }

  /**
   * Generate a CAST function in the module.
   */
  private void generateCast(SymbolID oldType,
                            SymbolID newType,
                            int      num)
    throws CodeGenerationException
  {
    SymbolID exceptType = Utilities.lookupSymbol(d_context, BabelConfiguration.getBaseExceptionType());
    String castMethod = Fortran.getMethodStubName
      (newType, Fortran.createCast(d_context, newType), d_context);
    d_lw.beginBlockComment(false);
    d_lw.println("Static function to cast from " + oldType.getFullName());
    d_lw.println("to " + newType.getFullName() + ".");
    d_lw.endBlockComment(false);
    d_lw.println("subroutine cast_" + num + "(oldType, newType, exception)");
    d_lw.tab();
    d_lw.println("implicit none");
    d_lw.println("type(" + Fortran.getTypeName(oldType) + 
                 "), intent(in) :: oldType");
    d_lw.println("type(" + Fortran.getTypeName(newType) + 
                 "), intent(out) :: newType");
    d_lw.println("type(" + Fortran.getTypeName(exceptType) + 
                 "), intent(out) :: exception");
    d_lw.println("external " + castMethod);
    d_lw.println();
    d_lw.println("call " + castMethod + "(oldType, newType, exception)");
    d_lw.backTab();
    d_lw.println("end subroutine cast_" + num);
    d_lw.println();
  }

  private void generateCastMethods(Extendable ext,
                                   Collection parents)
    throws CodeGenerationException
  {
    /*
     * Experience has shown that we cannot count on parents to
     * have a consistent ordering from run to run. Therefore we
     * must sort parents.
     */
    final Object[] parentArray = parents.toArray();
    final SymbolID  id = ext.getSymbolID();
    int num = 0;
    Arrays.sort(parentArray);
    for(int i = 0; i < parentArray.length; ++i) {
      SymbolID parentID = ((Extendable)parentArray[i]).getSymbolID();
      generateCast(id, parentID, num++);
      generateCast(parentID, id, num++);
    }
  }

  private void writeCastList(int numCasts)
  {
    d_lw.print("cast_0");
    for(int i = 1; i < numCasts; ++i) {
      if (((numCasts % s_CASTS_PER_LINE) == 0) 
          && (i < (numCasts - 1))) {
        d_lw.println(", &");
        if (numCasts == 7) {
          d_lw.tab();
        }
      }
      else {
        d_lw.print(", ");
      }
      d_lw.print("cast_" + i);
    }
  }

  private void writeCastInterface(int numCasts)
  {
    if (numCasts > 0) {
      d_lw.print("private :: ");
      writeCastList(numCasts);
      d_lw.println();
      if (numCasts > 7) {
        d_lw.backTab();
      }
      d_lw.println("interface cast");
      d_lw.tab();
      d_lw.print("module procedure ");
      writeCastList(numCasts);
      d_lw.println();
      if (numCasts > 7) {
        d_lw.backTab();
      }
      d_lw.backTab();
      d_lw.println("end interface");
    }
  }

  private void generateNullSubroutines(Extendable ext)
  {
    d_lw.println("logical function is_null_s(ext)");
    d_lw.tab();
    d_lw.println("type(" + Fortran.getTypeName(ext.getSymbolID()) +
                 "), intent(in) :: ext");
    d_lw.println("is_null_s = (ext%d_ior .eq. 0)");
    d_lw.backTab();
    d_lw.println("end function is_null_s");
    d_lw.println();
    d_lw.println("logical function not_null_s(ext)");
    d_lw.tab();
    d_lw.println("type(" + Fortran.getTypeName(ext.getSymbolID()) +
                 "), intent(in) :: ext");
    d_lw.println("not_null_s = (ext%d_ior .ne. 0)");
    d_lw.backTab();
    d_lw.println("end function not_null_s");
    d_lw.println();
    d_lw.println("subroutine set_null_s(ext)");
    d_lw.tab();
    d_lw.println("type(" + Fortran.getTypeName(ext.getSymbolID()) +
                 "), intent(out) :: ext");
    d_lw.println("ext%d_ior = 0");
    d_lw.backTab();
    d_lw.println("end subroutine set_null_s");
    d_lw.println();
  }
  //write the interface for generated (non-user) methods
  private void writeMethodInterface(SymbolID id, String methodName, 
                                    boolean extendIfcName)
  {
    String sIfcName;
    d_lw.println("private :: " + methodName + "_s");
    if (extendIfcName) {
      sIfcName = Fortran.getExtendedMethodName(id, methodName);
    } else {
      sIfcName = methodName;
    }
    d_lw.println("interface " + sIfcName);
    d_lw.tab();
    d_lw.println("module procedure " + methodName + "_s");
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void writeMethodInterface(Extendable ext, Method m, 
                                    boolean extendIfcName)
  {
    SymbolID id  = ext.getSymbolID();
    String sName = m.getCorrectMethodName();
    String sIfcName;
    Collection overloadedMethods = ext.getOverloadedMethodsByName(sName);

    if(sName.compareTo("new") == 0) {
      overloadedMethods.add(create(ext.getSymbolID()));
      overloadedMethods.add(Fortran.createRemoteMethod(ext, d_context, (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context) )));
    }

    //TODO: Is this irrelevent now?  I think so.
    //This is only empty in one wierd case for the method new.
    if(overloadedMethods.isEmpty()) {
      writeMethodInterface(id, sName, extendIfcName);
    } else {
      //This simply lists all the long method names as private (it only
      //looks complex)
      d_lw.print("private :: "); 
      d_lw.tab();
      for(Iterator i = overloadedMethods.iterator(); i.hasNext();) {
        Method meth = (Method) i.next();
        //Rarrays actually map to 2 different methods, one takes rarrays,
        //the other sidl arrays.  We do this in F90 and C++
        if(meth.hasRarray()) {
          d_lw.println(meth.getLongMethodName() + "_1s, &");
          d_lw.print(meth.getLongMethodName() + "_2s");
        } else {
          d_lw.print(meth.getLongMethodName() + "_s");
        }
        if(i.hasNext()) {
          d_lw.println(", &");
        } else {
          d_lw.println();
          //d_lw.println();
        }
      }
      d_lw.backTab();
      d_lw.println();
      
      //This maps the method short name to all the long names.
      if (extendIfcName) {
        sIfcName = Fortran.getExtendedMethodName(id, sName);
      } else {
        sIfcName = sName;
      }
      d_lw.println("interface " + sIfcName);
      d_lw.tab();
      d_lw.print("module procedure ");
      for(Iterator i = overloadedMethods.iterator(); i.hasNext();) {
        Method meth = (Method) i.next();
        if(meth.hasRarray()) {
          d_lw.println(meth.getLongMethodName() + "_1s, &");
          d_lw.print(meth.getLongMethodName() + "_2s");
        } else {
          d_lw.print(meth.getLongMethodName() + "_s");
        }
        if(i.hasNext()) {
          d_lw.println(", &");
        } else {
          d_lw.println();
        }
      }
      d_lw.backTab();
      d_lw.println("end interface");
      d_lw.println();
      d_lw.println();
    } 
  }


  private void writeMethodInterface(Extendable ext, Method m)
  {
    writeMethodInterface(ext, m, false);
  }


  private void writeMethodInterfaces(Extendable ext, boolean doLocal) 
    throws CodeGenerationException 
  {
    Collection methods = doLocal ? ext.getMethods(false) : extendMethods(ext);

    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if(!interfacesWritten.contains(m.getShortMethodName())) {
        writeMethodInterface(ext, m);
        interfacesWritten.add(m.getShortMethodName());
      }
      if ( m.getCommunicationModifier() == Method.NONBLOCKING ) { 
        Method send = m.spawnNonblockingSend();
        if(!interfacesWritten.contains(send.getCorrectMethodName())) {
          writeMethodInterface(ext, send); 
          interfacesWritten.add(send.getCorrectMethodName());
        }
        Method recv = m.spawnNonblockingRecv();
        if(!interfacesWritten.contains(recv.getCorrectMethodName())) {
          writeMethodInterface(ext, recv); 
          interfacesWritten.add(recv.getCorrectMethodName());
        }
      }
    }
  }
  

  private void writeBuiltinMethodInterfaces(Extendable ext) throws CodeGenerationException 
  {
    SymbolID id = ext.getSymbolID();
    Method bi = IOR.getBuiltinMethod(IOR.EXEC,id,d_context,false);
    bi.setMethodName("exec");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());
    
    bi = IOR.getBuiltinMethod(IOR.GETURL,id, d_context,false);
    bi.setMethodName("getURL");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());
    
    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id,d_context,false);
    bi.setMethodName("isRemote");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());

    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id,d_context,false);
    bi.setMethodName("isLocal");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());

    bi = IOR.getBuiltinMethod(IOR.HOOKS,id,d_context,false);
    bi.setMethodName("set_hooks");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());

/* TODO/ToDo/TBD: Correct?
    bi = IOR.getBuiltinMethod(IOR.CONTRACTS, id, d_context, false);
    bi.setMethodName("set_contracts");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());

    bi = IOR.getBuiltinMethod(IOR.DUMP_STATS, id, d_context, false);
    bi.setMethodName("dump_stats");
    d_lw.println();
    writeMethodInterface(ext, bi);
    interfacesWritten.add(bi.getShortMethodName());
*/

    if(ext.hasStaticMethod(true)) {
      bi = IOR.getBuiltinMethod(IOR.HOOKS,id,d_context,true);
      bi.setMethodName("set_hooks_static");
      d_lw.println();
      writeMethodInterface(ext, bi, true);
      interfacesWritten.add(bi.getShortMethodName());

/* TODO/ToDo/TBD:  Correct?
      bi = IOR.getBuiltinMethod(IOR.CONTRACTS, id, d_context, true);
      bi.setMethodName("set_contracts_static");
      d_lw.println();
      writeMethodInterface(ext, bi, true);
      interfacesWritten.add(bi.getShortMethodName());

      bi = IOR.getBuiltinMethod(IOR.DUMP_STATS, id, d_context, true);
      bi.setMethodName("dump_stats_static");
      d_lw.println();
      writeMethodInterface(ext, bi, true);
      interfacesWritten.add(bi.getShortMethodName());
*/
    }

  }

  private void generateBuiltinMethods(Extendable ext) throws CodeGenerationException
  {
    SymbolID id = ext.getSymbolID();
    Method bi = IOR.getBuiltinMethod(IOR.EXEC,id,d_context,false);
    bi.setMethodName("exec");
    d_lw.println();
    writeMethodStub(bi,id,"_s",false,true);

    
    bi = IOR.getBuiltinMethod(IOR.GETURL,id,d_context,false);
    bi.setMethodName("getURL");
    d_lw.println();
    //    extendAndGenerate(bi, id);
    writeMethodStub(bi,id,"_s",false,true);
    

    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id,d_context,false);
    bi.setMethodName("isRemote");
    d_lw.println();
    writeMethodStub(bi,id,"_s",false,true);

    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id,d_context,false);
    bi.setMethodName("isLocal");
    d_lw.println();
    writeMethodStub(bi,id,"_s",false,true);

/* TODO/ToDo/TBD:  RESUME DUPS HERE */
    bi = IOR.getBuiltinMethod(IOR.HOOKS,id,d_context,false);
    bi.setMethodName("set_hooks");
    d_lw.println();
    writeMethodStub(bi,id,"_s",false,true);

    if(ext.hasStaticMethod(true)) {
      bi = IOR.getBuiltinMethod(IOR.HOOKS,id,d_context,true);
      bi.setMethodName("set_hooks_static");
      d_lw.println();
      writeMethodStub(bi,id,"_s",false,true);
    }
  }


  private void generateMethodDispatches(Extendable ext, boolean doLocal)
    throws CodeGenerationException
  {
    Collection methods = doLocal ? ext.getMethods(false) : extendMethods(ext);
    final SymbolID id  = ext.getSymbolID();

    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if( (!dispatchesWritten.contains(m.getLongMethodName()))
        && (!m.getLongMethodName().equals("new"))) {
        extendAndGenerate(m, id);

        dispatchesWritten.add(m.getLongMethodName());
        if ( m.getCommunicationModifier() == Method.NONBLOCKING ) {
          Method send = m.spawnNonblockingSend();
          extendAndGenerate(send, id);
          dispatchesWritten.add(send.getLongMethodName());
          Method recv = m.spawnNonblockingRecv();
          extendAndGenerate(recv, id);
          dispatchesWritten.add(recv.getLongMethodName());
        }
      }
    }
  }

  /**
   * Generate the FORTRAN 90 module file for a sidl class.  
   * 
   * @param ext    the sidl class whose module is to be written.
   * @exception    gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void generateCode(Extendable ext)
    throws CodeGenerationException
  {
    Collection parents = ext.getParents(true);
    final SymbolID id = ext.getSymbolID();
    final String name = Fortran.getModule(id);
    interfacesWritten = new HashSet();
    dispatchesWritten = new HashSet();
    d_lw.println();
    d_lw.writeComment(ext, false);
    d_lw.println();
    writeIncludes(ext);
    d_lw.println();
    d_lw.println("module " + name);
    d_lw.println();
    d_lw.tab();

    includeTypes(ext);

    d_lw.println();
    writeCastInterface(parents.size()*2);
    d_lw.println();
    writeMethodInterfaces(ext, true); /* Write local method interfaces */
    writeMethodInterfaces(ext, false); /* Write parent/extended interfaces */
    writeBuiltinMethodInterfaces(ext);

    writeMethodInterface(id, "not_null", false);
    writeMethodInterface(id, "is_null", false);
    writeMethodInterface(id, "set_null", false);

    d_lw.println();
    d_lw.backTab();
    d_lw.println("contains");
    d_lw.println();

    d_lw.tab();
    generateMethodDispatches(ext, true);  /* Generate local methods first */
    generateMethodDispatches(ext, false); /* Generate parent/extended methods */
    d_lw.println();
    generateCastMethods(ext, parents);
    generateBuiltinMethods(ext);
    generateNullSubroutines(ext);

    d_lw.backTab();
    d_lw.println();
    d_lw.println("end module " + name);
  }

  /**
   * Generate the FORTRAN 90 module file for a sidl enumerated type.  
   * 
   * @param enm    the sidl enumeration whose module is to be written.
   * @exception    gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void generateCode(Enumeration enm)
    throws CodeGenerationException
  {
    final SymbolID id = enm.getSymbolID();
    final String name = Fortran.getModule(id);
    d_lw.println();
    d_lw.println("module " + name);
    d_lw.writeComment(enm, false);
    d_lw.tab();
    d_lw.println();
    d_lw.generateUse("sidl", new TreeMap());
    Iterator  i = enm.getEnumerators().iterator();
    while (i.hasNext()){
      String sym = (String)i.next();
      Comment cmt = enm.getEnumeratorComment(sym);
      d_lw.writeComment(cmt, true);
      d_lw.print(Fortran.getReturnString(new Type(id, d_context), d_context));
      d_lw.print(", parameter :: ");
      d_lw.print(sym);
      d_lw.println(" = " + enm.getEnumeratorValue(sym));
      if (cmt != null) {
        d_lw.println();
      }
    }
    d_lw.backTab();
    d_lw.println("end module " + name);
  }


  /**
   * Generate the FORTRAN 90 module file for a sidl class.  
   *
   * Note:  This is the assumed entry point; otherwise, the test for
   * the version of the language should be repeated.
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
  */
  public static void generateCode(Symbol                   sym,
                                  LanguageWriterForFortran writer,
                                  Context                  context)
    throws CodeGenerationException
  {
    if (Fortran.isFortran90(context) || Fortran.hasBindC(context)) {
      if (sym instanceof Extendable) {
        ModuleSource modFile = new ModuleSource(writer, context);
        modFile.generateCode((Extendable)sym);
      }
      else if (sym instanceof Enumeration) {
        ModuleSource modFile = new ModuleSource(writer, context);
        modFile.generateCode((Enumeration)sym);
      }
    } else {  // Assuming this means F77
      throw new CodeGenerationException("Generation of module files only " +
                                        "supported for FORTRAN 90");
    }
  }
}
