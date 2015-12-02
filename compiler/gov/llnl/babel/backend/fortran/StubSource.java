//
// File:        StubSource.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6596 $
// Description: Generate code to allow FORTRAN calls to BABEL
//
// Copyright (c) 2000-2003, Lawrence Livermore National Security, LLC
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
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.c.C;
import gov.llnl.babel.backend.fortran.Fortran;
import gov.llnl.babel.backend.mangler.FortranMangler;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.mangler.NonMangler;
import gov.llnl.babel.backend.rmi.RMI;
import gov.llnl.babel.backend.rmi.RMIStubSource;
import gov.llnl.babel.backend.writers.LanguageWriter;
import gov.llnl.babel.backend.writers.LanguageWriterForC;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.CExprString;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Comment;
import gov.llnl.babel.symbols.Enumeration;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.Struct;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

/**
 * This class generates the C code that sits between a FORTRAN client and
 * the internal object representation (IOR) of a sidl object/interface.
 *
 * For each method, this generates a C function that will be called from
 * FORTRAN.  This C function massages the arguments from Fortran, calls
 * the IOR, massages the out values from the IOR call, and returns the
 * outgoing values to the Fortran caller.
 */
public class StubSource {

  /**
   * The argument name that holds the object/interface pointer in
   * a call to an object method. It's conceptually like the this pointer in
   * C++.  In FORTRAN, the object has to be passed explicitly.
   */
  public static final String s_self = "self";

  /**
   * The argument name that holds the exception pointer which a method may
   * throw an exception.
   */
  public static final String s_exception = "exception";


  /**
   * An <code>#ifdef</code> to check whether character argument should be
   * treated like strings.
   */
  public final static String charCheck(Context context)
  {
    return "#ifdef " 
      + Fortran.getFortranPrefix(context) 
      + "_CHAR_AS_STRING";
  }

  /**
   * This string is prepended to a proxy variable (a variable that takes the
   * place of another variable).  A proxy variable exists when the IOR and
   * Fortran representations are not directly compatible.
   */
  private static final String s_proxy = "_proxy_";

  /**
   * This string is prepended to a proxy variable (a variable that takes the
   * place of another variable).  A proxy variable exists when the IOR and
   * Fortran representations are not directly compatible.
   */
  private static final String s_proxyTwo = "_alt_";

  /**
   * The name of the variable holding the static entry point vector for the
   * class.
   */
  private static final String s_epv = "_epv";

  /**
   * A local cache of the names of the fundamental and base exception types.
   */
  private static final String s_exceptionFundamentalType = 
    BabelConfiguration.getBaseExceptionType();
  private static final String s_exceptionInterfaceType = 
    BabelConfiguration.getBaseExceptionInterface();

  /**
   * This writer controls where the generated C code goes.
   */
  private LanguageWriter d_writer;

  private Context d_context;

  /**
   * This is a convenience utility function specifically for the generation
   * of super "Stub" functions in the Impl files. 
   * The output stream is not closed on exit.  A code
   * generation exception is thrown if an error is detected.
   *
   * @param cls The class in which these supers are to be generated      
   *
   * @param writer the output writer to which the stub source will
   *               be written. This will not be closed.
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  public static void generateSupers(Class cls, LanguageWriter writer,
                                    Context context)
    throws CodeGenerationException
  {
    StubSource source = new StubSource(writer, context);
    source.generateSupers(cls);
  }  

  public void generateSupers(Class cls) throws CodeGenerationException {
    generateSuperEPV(cls);
    generateGetIOR(cls.getSymbolID());
    generateSuperMethods(cls);
  }  

  /**
   * Create an object to generate the stub code for a sidl class/interface.
   * This is frequently called from {@link #generateCode(Symbol,
   * LanguageWriter) generateCode} rather than used directly.
   *
   * @param writer the stub code is generated to this output device.
   */
  public StubSource(LanguageWriter writer,
                    Context context) {
    d_writer = writer;
    d_context = context;
  }

  /**
   * Write a comma and newline to <code>writer</code> iff
   * <code>needComma</code> is  <code>true</code>.  This always returns
   * <code>false</code>.
   *
   * @param writer    the device to which the comma should be output.
   * @param needComma If <code>true</code>, this method will write a
   *                  comma followed by a newline; otherwise, this
   *                  method takes no action.
   * @return <code>false</code> is always returned.
   */
  public static boolean comma(LanguageWriter writer, boolean needComma) {
    if (needComma) {
      writer.println(",");
    }
    return false;
  }

  /**
   * Write an argument declaration in C for an argument being passed in from
   * a FORTRAN caller or from C to a FORTRAN subroutine.
   *
   * @param writer    the place where the code is generated.
   * @param argName   the formal name of the argument.
   * @param argType   the type of the argument.
   * @param needComma whether a comma is needed or not.
   * @return <code>true</code> means a comma is needed before
   *         the next argument; <code>false</code> means a comma
   *         is not needed.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    the type of the argument is unsupported.
   */
  public static boolean declareArgument(LanguageWriter writer, String argName, 
                                        Type argType, boolean needComma,
                                        Context context,
                                        Method method)
    throws CodeGenerationException
  {
    final String pre = "fortran.StubSource.declareArgument: ";
    switch(argType.getDetailedType()) {
    case Type.VOID:
      // do nothing
      break;
    case Type.ARRAY:
      if (argType.isRarray()) {
        writer.print(Fortran.getFortranTypeInC(argType.getArrayType(), 
                                               context) 
          + " *" + argName);
        needComma = true;
        break;
      }
      // fall through intended
    case Type.DCOMPLEX:
    case Type.DOUBLE:
    case Type.FCOMPLEX:
    case Type.FLOAT:
    case Type.BOOLEAN:
    case Type.ENUM:
    case Type.INT:
    case Type.LONG:
    case Type.CLASS:
    case Type.INTERFACE:
      writer.print(Fortran.getFortranTypeInC(argType, context) +
                   " *" + argName);
      needComma = true;
      break;
    case Type.STRUCT:
      //breaking out STRUCT case for STRUCTS that are function return vars.
        Type returnType = method.getReturnType();
        if (returnType.getDetailedType() == Type.STRUCT) {
          writer.print( IOR.getReturnString(argType, context, true, false) +
                    " *" + argName);
        } else {
          writer.print(Fortran.getFortranTypeInC(argType, context) +
                    " *" + argName);
        }
      needComma = true;
      break;
    case Type.OPAQUE:
      writer.print(Fortran.getFortranTypeInC(argType, context) +
                   " *" + argName);
      needComma = true;
      break;
    case Type.STRING:
      writer.println(Fortran.getFortranPrefix(context) + "_String " + argName);
      writer.print(Fortran.getFortranPrefix(context) + 
                   "_STR_NEAR_LEN_DECL(" + argName 
        + ")");
      needComma = true;
      break;
    case Type.CHAR:
      writer.printlnUnformatted(charCheck(context));
      writer.println(Fortran.getFortranPrefix(context) + "_String " + argName);
      writer.println(Fortran.getFortranPrefix(context) + "_STR_NEAR_LEN_DECL(" 
        + argName + ")");
      writer.printlnUnformatted("#else");
      writer.println("char *" + argName);
      writer.printlnUnformatted("#endif");
      needComma = true;
      break;
    default:
      throw new CodeGenerationException(pre + "Unsupported Fortran argument "
                  + "type: " + argType.getTypeString() + " " + argName);
    }
    return needComma;
  }

  /**
   * Generate the compiler independent form of the function name.
   *
   * @param writer     the place where the symbol is written
   * @param methodName  the potentially mixed case form of the function
   *                    name.
   */
  public static void generateMethodSymbol(LanguageWriter writer,
                                          String methodName,
                                          Context context,
                                          Type type,
                                          boolean fromSkelFunc)
    throws CodeGenerationException
  {
    if (fromSkelFunc && Fortran.hasBindC(context)){
      switch(type.getDetailedType()) {
      case Type.BOOLEAN:
        writer.println(Fortran.getFortranPrefix(context) + 
                       "_Bool ");
        break;
      default:
        writer.println(IOR.getReturnString(type,context, true, false));
        break;
      }
    } else {
      writer.println("void");
    }
    writer.println(Fortran.getFortranSymbol(context) + 
                   "(" + methodName.toLowerCase() 
                   + ',' + methodName.toUpperCase() + ',' + methodName + ")");
    writer.println("(");
  }

  /**
   * Write declarations for each of the normal arguments for the
   * FORTRAN compatible method declaration.  This writes one argument
   * for each <code>Argument</code> in the iterator. This does not
   * write the extra arguments that are required by the FORTRAN compiler.
   * The FORTRAN compiler may pass string lengths as separate extra
   * argument.
   *
   * @param writer  where the arguments are declared.
   * @param i       a iterator to the collection of {@link
   *                gov.llnl.babel.symbols.Argument Arguments}.
   * @return <code>true</code> if a comma is needed before the
   *         next parameter declaration.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    a general catch all exception for problems generating the stub.
   */
  private static boolean declareNormalArguments(LanguageWriter writer,
                                                Iterator i,
                                                Context context,
                                                Method method,
                                                boolean gotFunc)
    throws CodeGenerationException
  {
    boolean needComma = false;
    while (i.hasNext()) {
      needComma = comma(writer, needComma);
      Argument a = (Argument)i.next();
      String argName = a.getFormalName();
      if (gotFunc && Fortran.hasBindC(context)) {
        if ( !(argName.equals(Fortran.s_return))){
          needComma = 
            declareArgument(writer, a.getFormalName(), a.getType(), needComma,
                          context, method);
        }
      } else {
        needComma = 
          declareArgument(writer, a.getFormalName(), a.getType(), needComma,
                        context, method);
      }
    }
    return needComma;
  }
  
  /**
   * Write declarations for the extra arguments that are required by some
   * FORTRAN compilers for things like string lengths.  There may or may
   * not be any extra arguments.
   *
   * @param writer    where the arguments are declared.
   * @param i         a iterator to the collection of {@link
   *                gov.llnl.babel.symbols.Argument Arguments}.
   * @param needComma whether a comma is needed before the next argument.
   * @return <code>true</code> if a comma is needed before the
   *         next parameter declaration.
   */
  private static boolean declareExtraArguments(LanguageWriter writer,
                                               Iterator i, 
                                               boolean needComma,
                                               Context context)
  {
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      final int t = a.getType().getDetailedType();
      if ((Type.STRING == t) || (Type.CHAR == t)) {
        if (needComma) {
          writer.println();
          needComma = false;
        }
        if (Type.CHAR == t) {
          writer.printlnUnformatted(charCheck(context));
        }
        writer.println(Fortran.getFortranPrefix(context) +
                      "_STR_FAR_LEN_DECL(" 
          + a.getFormalName() + ")");
        if (Type.CHAR == t) {
          writer.printlnUnformatted("#endif");
        }
      }
    }
    return needComma;
  }

  /**
   * Generate the C signature for a FORTRAN subroutine to be called from C
   * or for a C function to be called from FORTRAN.  This uses a set of
   * preprocessor macros to handle the conventions of the FORTRAN compiler.
   *
   * @param writer     the place where the signature is written.
   * @param methodName the name of the function.
   * @param arguments   a list of {@link gov.llnl.babel.symbols.Argument
   *                   Argument} objects.
   * @param fromSkelFunc   Need different logic to deal with Fortran Functions in
   *                       the skel file.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    something went wrong -- probably an unsupported type.
   */
  public static void generateSignature(LanguageWriter writer,
                                       String methodName, 
                                       List arguments,
                                       Context context,
                                       Method method,
                                       boolean fromSkelFunc)
    throws CodeGenerationException
  {
    try {
      writer.pushLineBreak(false);
      generateMethodSymbol(writer, methodName, context,method.getReturnType(),fromSkelFunc);

      if (arguments.isEmpty()) {
        writer.print("void");
      } else {
        boolean needComma;
        writer.tab();
        needComma = declareNormalArguments(writer, arguments.iterator(), 
                                           context, method,fromSkelFunc);
        needComma =
          declareExtraArguments(writer, arguments.iterator(), needComma,
                                context);
        
        if (needComma) {
          writer.println();
        }
        writer.backTab();
      }
      writer.print(")");
    }
    finally {
      writer.popLineBreak();
    }
  }

  /**
   * Return <code>true</code> iff the type present requires a proxy.  A
   * proxy is required when the FORTRAN types is not directly compatible
   * with the C type for a particular sidl type.
   *
   * @param t   the sidl type description
   * @return <code>true</code> means that <code>t</code> requires a proxy;
   *  <code>false</code> means that <code>t</code> does not require a
   * proxy.
   */
  static public boolean hasProxy(Type t) {
    switch (t.getDetailedType()) {
    case Type.BOOLEAN:
    case Type.CHAR:
    case Type.OPAQUE:
    case Type.STRING:
    case Type.CLASS:
    case Type.INTERFACE:
    case Type.ARRAY:
      return true;
    default:
      return false;
    }
  }

  /**
   * Return <code>true</code> if a particular sidl type is implemented using
   * a pointer type.
   * 
   * @param t    the sidl type description.
   * @return <code>true</code> means the type is implemented using a pointer
   * type; <code>false</code> means the type is not implemented using a
   * pointer type.
   */
  public static boolean isPointer(Type t) {
    switch(t.getDetailedType()) {
    case Type.ARRAY:
    case Type.STRING:
    case Type.OPAQUE:
    case Type.CLASS:
    case Type.INTERFACE:
      return true;
    default:
      return false;
    }
  }

  private String getArrayStruct(Type type) throws CodeGenerationException
  {
    final String pointerType = getReturnString(type);
    return pointerType.substring(0, pointerType.length() - 1);
  }

  /**
   * Generate a return string for the specified SIDL type.  Most
   * of the SIDL return strings are listed in the static structures defined
   * at the start of this class.  Symbol types and array types require
   * special processing.
   */
  private String getReturnString(Type type)
    throws CodeGenerationException
  {
    return IOR.getReturnString(type, d_context, true, false);
  }

  /**
   * Declare C variables to act as proxies (stand ins) for things whose
   * FORTRAN type is not directly compatible with the IOR.
   *
   * @param arguments a list of <code>Argument</code> objects.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   * a general catch all exception for something going wrong.
   */
  private void declareProxies(List arguments) throws CodeGenerationException {
    Iterator i = arguments.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      if (hasProxy(t)) {
        if (t.isRarray()) { // rarray's have lots of stuff
          final int dimen = t.getArrayDimension();
          d_writer.println(getArrayStruct(t) + ' ' + s_proxyTwo + name + ';');
          d_writer.println(getReturnString(t) + ' ' + s_proxy + name 
            + " = &" + s_proxyTwo + name + ';');
          d_writer.println("int32_t " + name + "_lower[" + dimen + "], " 
            + name + "_upper[" + dimen + "], " + name + "_stride[" + dimen 
            + "];");
        } else {
          d_writer.print(getReturnString(t) + " " + s_proxy + name);
          if (isPointer(t)) {
            d_writer.println(" = NULL;");
          } else {
            d_writer.println(";");
          }
        }
      }
    }
  }

  /**
   * Write assignment statements (conceptually speaking) to copy material
   * from the actually incoming parameters to the corresponding proxy
   * variables.  In some cases, copying the incoming values requires
   * something more complex than a simple assignment statement.
   *
   * @param arguments  the list of all parameters.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   something went wrong while generating the statements.
   */
  private void copyIncomingValues(List arguments)
    throws CodeGenerationException
  {
    Iterator i = arguments.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      if (Argument.OUT != a.getMode()) {
        Type     t    = a.getType();
        String   name = a.getFormalName();
        switch (t.getDetailedType()) {
        case Type.BOOLEAN:
          d_writer.println(s_proxy + name + " = ((*" + name + " == " 
            + Fortran.getFortranPrefix(d_context) + "_TRUE) ? TRUE : FALSE);");
          break;
        case Type.CHAR:
          d_writer.printlnUnformatted(charCheck(d_context));
          d_writer.println(s_proxy + name + " = *" + 
                           Fortran.getFortranPrefix(d_context) 
            + "_STR(" + name + ");");
          d_writer.printlnUnformatted("#else");
          d_writer.println(s_proxy + name + " = *" + name + ";");
          d_writer.printlnUnformatted("#endif");
          break;
        case Type.STRING:
          d_writer.println(s_proxy + name + " =");
          d_writer.tab();
          d_writer.println("sidl_copy_fortran_str(" + 
                           Fortran.getFortranPrefix(d_context)
            + "_STR(" + name + "),(ptrdiff_t)");
          d_writer.tab();
          d_writer.println(Fortran.getFortranPrefix(d_context) + 
                           "_STR_LEN(" + name 
            + "));");
          d_writer.backTab();
          d_writer.backTab();
          break;
        case Type.ARRAY:
          if (t.isRarray()) {
            Iterator indexVar = t.getArrayIndexExprs().iterator();
            final int dimen = t.getArrayDimension();
            for(int j = 0; j < dimen && indexVar.hasNext(); ++j ) {
              AssertionExpression ae = (AssertionExpression)indexVar.next();
              d_writer.println(name + "_upper[" + j + "] = (" +
                               ae.accept(new CExprString("*"), null).toString()
                               + ")-1;");
            }
            d_writer.println(Fortran.getInitArray(t.getArrayType()) 
              + name + ", " + s_proxy + name + ", " + dimen + ", " + name 
              + "_lower, " + name + "_upper, " + name + "_stride);");
          } else {
            d_writer.println(s_proxy + name + " =");
            d_writer.tab();
            d_writer.println("(" + getReturnString(t) + ")");
            if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
              d_writer.println("(ptrdiff_t)(" + name + "->d_ior);");
            } else {
              d_writer.println("(ptrdiff_t)(*" + name + ");");
            }
            d_writer.backTab();
          }
          break;
        case Type.OPAQUE:
        case Type.CLASS:
        case Type.INTERFACE:
          d_writer.println(s_proxy + name + " =");
          d_writer.tab();
          d_writer.println("(" + getReturnString(t) + ")");
          d_writer.println("(ptrdiff_t)(*" + name + ");");
          d_writer.backTab();
          break;
        }
      }
    }
  }

  /**
   * Copy values from the proxy variables to the actual parameters.  It is
   * assumed that the parameters are <code>out</code> or <code>inout</code>
   * parameters.
   *
   * @param arguments the list of all arguments.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   something went wrong while generating the statements.
   */
  private void copyOutgoingValues(List arguments)
    throws CodeGenerationException
  {
    final String pre = "fortran.StubSource.copyOutgoingValues: ";
    Iterator i = arguments.iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      String name = a.getFormalName();
      if (Argument.IN != a.getMode() && !name.equals(s_exception)) {
        Type   t    = a.getType();
        switch (t.getDetailedType()) {
        case Type.BOOLEAN:
          d_writer.println("*" + name + " = ((" + s_proxy + name
            + " == TRUE) ? " + Fortran.getFortranPrefix(d_context) +
                           "_TRUE : " 
            + Fortran.getFortranPrefix(d_context) + "_FALSE);");
          break;
        case Type.ARRAY:
          if (t.isRarray()) break;
          if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
            if (Fortran.hasDirectAccess(t)) {
              Type dataType = t.getArrayType();
              d_writer.println("if (sidl_" + dataType.getTypeString() 
                + "__array_convert2f90(" + s_proxy + name + ", " 
                + t.getArrayDimension() + ", " + name + ")) {");
              d_writer.tab();
              d_writer.writeCommentLine("Copy to contiguous column-order");
              d_writer.println(getReturnString(t) + " " + s_proxyTwo + name 
                + " =");
              d_writer.tab();
              d_writer.print(Fortran.getEnsureArray(dataType));
              d_writer.println(s_proxy + name + ", " + t.getArrayDimension() 
                + ",");
              d_writer.tab();
              d_writer.println("sidl_column_major_order);");
              d_writer.backTab();
              d_writer.backTab();
              d_writer.println(Fortran.getDelRefArray(dataType) + s_proxy 
                + name + ");");
              d_writer.println("if (sidl_" + dataType.getTypeString() 
                + "__array_convert2f90(" + s_proxyTwo + name + ", " 
                + t.getArrayDimension() + ", " + name + ")) {");
              d_writer.tab();
              d_writer.writeCommentLine("We're S.O.L.");
              d_writer.println("fprintf(stderr, \"convert2f90 failed: %p "
                + "%d\\n\", (void*)" + s_proxyTwo + name + ", " 
                + t.getArrayDimension() + ");");
              d_writer.println("exit(1); /*NOTREACHED*/");
              d_writer.backTab();
              d_writer.println("}");
              d_writer.backTab();
              d_writer.println("}");
            } else {
              d_writer.println(name + "->d_ior = (ptrdiff_t)" + s_proxy 
                + name + ";");
            }
          } else {
            d_writer.println("*" + name + " = (ptrdiff_t)" + s_proxy + name 
              + ";");
          }
          break;
        case Type.CLASS:
        case Type.INTERFACE:
        case Type.OPAQUE:
          d_writer.println("*" + name + " = (ptrdiff_t)" + s_proxy + name 
            + ";");
          break;
        case Type.CHAR:
          d_writer.printlnUnformatted(charCheck(d_context));
          d_writer.println("*" + Fortran.getFortranPrefix(d_context) + "_STR(" + name 
            + ") = " + s_proxy + name + ";");
          d_writer.printlnUnformatted("#else");
          d_writer.println("*" + name + " = " + s_proxy + name + ";");
          d_writer.printlnUnformatted("#endif");
          break;
        case Type.STRING:
          d_writer.println("sidl_copy_c_str(");
          d_writer.tab();
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR(" + name + "),(size_t)");
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LEN(" + name 
            + "),");
          d_writer.println(s_proxy + name + ");");
          d_writer.backTab();
          d_writer.println("if (" + s_proxy + name + ") free(" + 
                           s_proxy + name + ");");
          break;
        case Type.SYMBOL:
          throw new CodeGenerationException(pre + "Unsupported Type: " 
                      + t.getTypeString());
        }
      }
    }
  }

  /**
   * Write the code to free any resources allocated by the stub function or
   * by the IOR that is no longer needed.
   *
   * @param arguments  the list of arguments for which resources may have
   *                   been allocated.
   */
  private void freeResources(List arguments) {
    Iterator i = arguments.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      if ((Type.STRING == a.getType().getDetailedType()) &&
          (a.getMode() == Argument.IN)) {
        String name = a.getFormalName();
        d_writer.println("free((void *)" + s_proxy + name + ");");
      }
    }
  }

  /**
   * Write a declaration for the entry point vector pointer.
   *
   * @param isStatic <code>true</code> means the static method
   *                 entry point vector should be used, and
   *                 <code>false</code> means the object entry
   *                 point vector should be used.
   * @param id       the symbol whose EPV or SEPV is needed.
   */
  private void declareEntryPointVector(boolean isStatic, SymbolID id) {
    if (isStatic) {
      d_writer.println("const " + IOR.getSEPVName(id) + " *" + s_epv 
        + " = _getSEPV();");
    } else {
      d_writer.println(IOR.getEPVName(id) + " *" + s_epv + " = NULL;");
    }
  }
  
  /**
   *  Just generates the variable superEPV
   */
  private void generateSuperEPV(Class cls) {
    d_writer.println("static const struct " 
      + C.getObjectName(cls.getParentClass().getSymbolID()) 
      + "__epv* superEPV = NULL;");
    d_writer.println();
  }

  /**
   * Generates the super methods
   */
  private void generateSuperMethods(Class cls)  throws CodeGenerationException {
    NameMangler mang;
    try {
      if (Fortran.needsAbbrev(d_context)) {
        mang = new FortranMangler(AbbrevHeader.MAXNAME,
                                  AbbrevHeader.MAXUNMANGLED);
      }
      else {
        mang = new NonMangler();
      }
    } catch (NoSuchAlgorithmException ex) {
      throw new CodeGenerationException("Caught NoSuchAlgorithm exception from new FortranMangler");
    }
    Collection methods = cls.getOverwrittenClassMethods();
    for (Iterator m = methods.iterator(); m.hasNext(); ) {
      Method method = (Method) m.next();
      extendAndGenerateSuper(cls, method, cls.getSymbolID(), false, mang);
    }
  }

  /**
   * Generate the _getIOR function that provides access to the IOR functions
   * either through static linking or dynamic loading.
   */
  private void generateGetIOR(SymbolID id) {
    final String ext_name = IOR.getExternalName(id);
    d_writer.writeComment("Return pointer to internal IOR functions.", false);

    d_writer.println("static const " + ext_name + "* _getIOR(void)");
    d_writer.println("{");
    d_writer.tab();
    d_writer.println("static const " + ext_name + " *_ior = NULL;");
    d_writer.println("if (!_ior) {");
    d_writer.tab();
    if (BabelConfiguration.isSIDLBaseClass(id)) {
      d_writer.println("_ior = " + IOR.getExternalFunc(id) + "();");
    } else {
      d_writer.printlnUnformatted("#ifdef SIDL_STATIC_LIBRARY");
      d_writer.println("_ior = " + IOR.getExternalFunc(id) + "();");
      d_writer.printlnUnformatted("#else");
      d_writer.println("_ior = ("+ext_name+"*)sidl_dynamicLoadIOR(\""+id.getFullName()+"\",\""+IOR.getExternalFunc(id)+"\") ;");
      d_writer.println("sidl_checkIORVersion(\"" + id.getFullName() + 
                       "\", _ior->d_ior_major_version, _ior->d_ior_minor_version, " +
                       Integer.toString(IOR.MAJOR_VERSION) + ", " +
                       Integer.toString(IOR.MINOR_VERSION) + ");");
      d_writer.printlnUnformatted("#endif");
    }
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println("return _ior;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }

  /**
   * Return the pointer that provides access to the static EPV.
   */
  private void generateGetStaticEPV(SymbolID id) {
    String sepv_name = IOR.getSEPVName(id);
    d_writer.writeComment("Return pointer to static functions.", false);
    d_writer.println("static const " + sepv_name + "* _getSEPV(void)");
    d_writer.println("{");
    d_writer.tab();
    d_writer.println("static const " + sepv_name + " *_sepv = NULL;");
    d_writer.println("if (!_sepv) {");
    d_writer.tab();
    d_writer.println("_sepv = (*(_getIOR()->getStaticEPV))();");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println("return _sepv;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }

  /**
   * Write the code to fetch the entry point vector needed for a method
   * call. If the case of a static EPV, it requires a function call, and
   * in the case of an object EPV, it requires dereferencing the IOR
   * pointer.
   *
   * @param isStatic <code>true</code> means it is a static method.
   * @param id       the name of the symbol who's EPV is needed.
   */
  private void getEntryPointVector(boolean isStatic, SymbolID id) {
    if (!isStatic) {
      d_writer.println(s_epv + " = " + s_proxy + s_self + "->d_epv;");
    }
  }

  /**
   * Write an argument to be passed to an IOR method call.  This is a helper
   * function for <code>makeMethodCall</code>.
   *
   * @param a           an Argument.
   * @param isInterface indicate whether then method is being called on
   *                    an object or interface.
   * @param needComma   whether a comma is needed before the next argument.
   * @return <code>true</code> means a comma is needed before the next
   *         argument; <code>false</code> means a comma is not needed.
   */
  private boolean passArgument(Argument a, boolean isInterface, 
                               boolean needComma)
  {
    String varName = a.getFormalName();
    if (!Fortran.s_return.equals(varName)) {
      needComma = comma(d_writer, needComma);
      if (hasProxy(a.getType())) {
        if (Argument.IN != a.getMode()) {
          d_writer.print("&");
        }
        d_writer.print(s_proxy + varName);
        if (isInterface && s_self.equals(varName)) {
          d_writer.print("->d_object");
        }
      } else {
        if (Argument.IN == a.getMode()) {
          if(a.getType().getDetailedType()!=Type.STRUCT) {
            d_writer.print("*");
          } 
        }
        d_writer.print(varName);
      }
      needComma = true;
    }
    return needComma;
  }

  /**
   * Write the code to call the IOR.  This uses the original parameters
   * where possible and proxies otherwise.
   *
   * @param arguments   the list of arguments.  This list may have
   *                    implicitly defined arguments like the object, return
   *                    value and exception arguments.
   * @param m           the method to call on the IOR.
   * @param isInterface <code>true</code> means the method call of
   *                    an interface; <code>false</code> means the method
   *                    call to an object.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    something bad happened.
   */
  private void makeMethodCall(Extendable ext, List arguments, Method m,
                              boolean isInterface, boolean isSuper)
    throws CodeGenerationException
  {
    Type returnType = m.getReturnType();
    Iterator i = arguments.iterator();
    boolean needComma = false;
    if (Type.VOID != returnType.getDetailedType()) {
      if (hasProxy(returnType)) {
        d_writer.print(s_proxy);
      } else {
        d_writer.print("*");
      }
      d_writer.println(Fortran.s_return + " = ");
      d_writer.tab();
    }
    if(isSuper) {
      Class cls = (Class) ext;
      d_writer.println("(*(superEPV->"
        + IOR.getVectorEntry(m.getLongMethodName()) + "))(("
        + IOR.getObjectName(cls.getParentClass().getSymbolID()) + "*) ");
    } else {
      //One special case, if we're generating the builtin isLocal,
      //internally it's actually just !isremote, do that here.

      if(m.getLongMethodName().compareTo("_isLocal") == 0) {
        d_writer.println("!(*(" + s_epv + "->" 
                         + IOR.getVectorEntry(IOR.getBuiltinMethod(IOR.ISREMOTE,ext.getSymbolID(), d_context,false).getLongMethodName()) 
                         + "))(");
      } else {
        //normal case
        d_writer.println("(*(" + s_epv + "->" 
                         + IOR.getVectorEntry(m.getLongMethodName()) + "))(");
      }

    }
    d_writer.tab();
    while (i.hasNext()) {
      needComma = passArgument((Argument)i.next(), isInterface, needComma);
    }
    d_writer.println();
    d_writer.backTab();
    d_writer.println(");");
    if (Type.VOID != returnType.getDetailedType()) {
      d_writer.backTab();
    }
  }

  /**
   * If a sidl method, <code>m</code>, can thrown an exception, the stub
   * must check the exception argument. If the exception argument indicates
   * that an exception occured, it must be translated back to FORTRAN and
   * the other argument values should be ignored.
   *
   * @param m add exception handling if this sidl method can throw an 
   *              exception.
   */
  private void checkExceptionBlock(Method m) {
    if (!m.getThrows().isEmpty()) {
      d_writer.println("if (" + s_proxy + s_exception + ") {");
      d_writer.tab();
      d_writer.println("*" + s_exception + " = (ptrdiff_t)" + s_proxy 
        + s_exception + ";");
      d_writer.backTab();
      d_writer.println("}");
      d_writer.println("else {");
      d_writer.tab();
      d_writer.println("*" + s_exception + " = (ptrdiff_t)NULL;");
    }
  }

  /**
   * Write the end of the exception block if the sidl method can throw an
   * exception.
   *
   * @param m   close the exception block if this method can throw an
   *            exception.
   */
  private void endExceptionBlock(Method m) {
    if (!m.getThrows().isEmpty()) {
      d_writer.backTab();
      d_writer.println("}");
    }
  }

  private void cleanupRarrays(Collection args)
    throws CodeGenerationException
  {
    d_writer.printlnUnformatted("#ifdef SIDL_DEBUG_REFCOUNT");
    //Get a list of rarrays
    for(Iterator a = args.iterator(); a.hasNext();) {
      Argument arg = (Argument)a.next();
      if(arg.getType().isRarray()) {
        d_writer.println("sidl__array_deleteRef((struct sidl__array*)" +
                         s_proxy + arg.getFormalName() + ");");
      }
    }
    d_writer.printlnUnformatted("#endif /* SIDL_DEBUG_REFCOUNT */");
  }

  /**
   * Generate the stub for a particular method. This generates the
   * signature, declares proxies, translates incoming values, makes the
   * call, and then does outgoing value processing.
   *
   * @param name      the name of the method. This may be different than the
   *                  original name of the method in <code>m</code>..
   * @param arguments the extended list of arguments. This has the argument
   *                  for <code>m</code> with extra arguments as needed for
   *                  the self pointer, the return value, and the exception
   *                  argument.
   * @param argumentsWithIndices argument plus any raw array index arguments
   * @param m         information about the argument to be written.
   * @param id        the name of the symbol who owns the method.
   * @param isInterface whether the symbol who owns the method is a class
   *                    or an interface.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  this exception provides feedback that something went wrong.
   */
  private void generateMethod(Extendable ext, String name, List arguments, 
                              List argumentsWithIndices, Method  m, SymbolID id,
                              boolean isInterface, boolean isSuper) 
    throws CodeGenerationException 
  {
    d_writer.writeComment(m, false);
    generateSignature(d_writer, name, argumentsWithIndices, d_context,m,false);
    d_writer.println();
    d_writer.println("{");
    d_writer.tab();
    declareEntryPointVector(m.isStatic(), id);
    declareProxies(arguments);
    copyIncomingValues(arguments);
    getEntryPointVector(m.isStatic(), id);
    makeMethodCall(ext, arguments, m, isInterface, isSuper);
    checkExceptionBlock(m);
    copyOutgoingValues(arguments);
    endExceptionBlock(m);
    if (m.hasRarray()) {
      cleanupRarrays(arguments);
    }
    freeResources(arguments);
    d_writer.backTab();
    d_writer.println("}");
  }

  static private Type convertRarrayToArray(Type array,
                                           Context context) {
    if (array.isRarray()) {
      return new Type(array.getArrayType(), array.getArrayDimension(),
                      array.getArrayOrder(), context);
    }
    return array;
  }

  /**
   * Convert any rarray arguments to normal array arguments.
   */
  static public List convertRarrayToArray(List args,
                                          Context context) {
    ArrayList result  = new ArrayList(args.size());
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      if (a.getType().isRarray()) {
        Argument newArg = new Argument(a.getMode(),
                                       convertRarrayToArray(a.getType(), 
                                                            context),
                                       a.getFormalName());
        if (a.isCopy()) {
          newArg.setAttribute("copy");
        }
        result.add(newArg);
      } else {
        result.add(a);
      }
    }
    return result;
  }

  /**
   * Add extra arguments to the original argument list of a method as needed
   * for the self pointer, the return value and the exception argument.
   * This makes these implicit arguments explicit and prevents having each
   * of these be a special case throughout the code.
   *
   * @param selfId   the name of the class/interface who owns the method.
   * @param m        the method whose argument list will be extended.
   * @param indices If true, get the argument list including rarray
   *                 indices.  Should be true for places that support rarrays.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception for problems in the code generation phase.
   */
  public static List extendArgs(SymbolID selfId, Method m, 
                                Context context, boolean indices) 
    throws CodeGenerationException
  {
    List origArgs = null;
    if(indices) {
      origArgs = m.getArgumentListWithIndices();
    } else { 
      origArgs = m.getArgumentListWithOutIndices();
    }

    ArrayList result = new ArrayList(origArgs.size() + 3);
    if (Method.STATIC != m.getDefinitionModifier()) {
      result.add(new Argument(Argument.IN, new Type(selfId, context), 
                              s_self));
    }
    result.addAll(origArgs);
    if (Type.VOID != m.getReturnType().getDetailedType()) {
      result.add(new Argument(Argument.OUT, m.getReturnType(), 
                              Fortran.s_return));
    }
    if (!m.getThrows().isEmpty()) {
      Symbol ex = Utilities.lookupSymbol(context, 
                                         s_exceptionFundamentalType);
      result.add(new Argument(Argument.OUT, 
                              new Type(ex.getSymbolID(), context),
                              s_exception));
    }
    return result;
  }

  /**
   * Generate the expanded set of referenced <code>SymbolID</code>'s. This 
   * includes <code>sidl.BaseException</code> if any of the methods throws
   * an exception.
   *
   * @param ext       the class or interface to generate includes for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems in the code generation phase.
   */
  public static Set extendedReferences(Extendable ext,
                                Context context)
    throws CodeGenerationException
  {
    Set result = new HashSet();
    for(Iterator i = ext.getMethods(true).iterator(); i.hasNext(); ) {
      Method method = (Method)i.next();
      result.addAll(method.getSymbolReferences());
      if (!method.getThrows().isEmpty()) {
        Symbol symbol = Utilities.lookupSymbol(context,
                                               s_exceptionInterfaceType);
        result.add(symbol.getSymbolID());
      }
    }
    return result;
  }

  /**
   * Generate a sequence of <code>#include</code> preprocessor directives
   * required by the stub.
   * 
   * @param writer    the output device where output is sent.
   * @param ext       the class or interface to generate includes for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems in the code generation phase.
   */
  public static void generateIncludes(LanguageWriterForC writer,
                                      Extendable ext,
                                      Context context) 
    throws CodeGenerationException
  {
    final SymbolID id = ext.getSymbolID();

    writer.generateInclude(Fortran.getHeaderFile(id), true);
    writer.generateSystemInclude("stddef.h");
    writer.generateSystemInclude("stdlib.h");
    writer.generateSystemInclude("string.h");
    writer.generateInclude("sidlfortran.h", false);
    writer.generateInclude("sidl_io_Serializer.h", true);
    writer.generateInclude("sidl_io_Deserializer.h", true);
    if (Fortran.isFortran90(context) || Fortran.hasBindC(context)) {
      writer.generateInclude("sidlf90array.h", true);
    }
    writer.generateInclude("sidl_header.h", false);
    writer.generateInclude("sidl_interface_IOR.h", true);
    writer.generateInclude("sidl_Exception.h", true);
    writer.generateSystemInclude("stdio.h");
    if (!BabelConfiguration.isSIDLBaseClass(id)) {
      writer.generateInclude("babel_config.h",false);
      writer.printlnUnformatted("#ifdef SIDL_DYNAMIC_LIBRARY");
      writer.generateInclude("sidl_Loader.h", false);
      writer.printlnUnformatted("#endif");
    }
    writer.generateInclude(IOR.getHeaderFile(id), false);
    if (Fortran.needsAbbrev(context)) {
      writer.generateInclude(Fortran.getStubNameFile(id), false);
    }

    Set includes = extendedReferences(ext, context);
    includes.remove(id);

    for(Iterator i = Utilities.sort(includes).iterator(); i.hasNext(); ) {
      writer.generateInclude(IOR.getHeaderFile((SymbolID)i.next()), false);
    }
    writer.generateInclude("sidl_rmi_ConnectRegistry.h", true);
    writer.generateInclude("sidlOps.h", true);

    Fortran.generateStubIncludes(writer, ext);

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
  private void extendAndGenerate(Extendable ext, Method m, SymbolID id,
                                 boolean isInterface) 
    throws CodeGenerationException
  {
    String name = Fortran.getMethodStubName(id, m, d_context);
    List extendedArgs = extendArgs(id, m, d_context, false);
    List extendedArgsWithIndices = extendArgs(id, m, d_context, true);

    d_writer.println();
    generateMethod(ext, name, extendedArgs, extendedArgsWithIndices,
                   m, id, isInterface, false);
    if ((Fortran.isFortran90(d_context)||
         Fortran.hasBindC(d_context)) && m.hasRarray()) {
      extendedArgs = convertRarrayToArray(extendedArgs, d_context);
      generateMethod(ext, Fortran.getAltStubName(id, m),
                     extendedArgs, extendedArgs, m, id, isInterface, false);
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
  private void extendAndGenerateSuper(Class cls, Method m, SymbolID id,
                                      boolean isInterface, NameMangler mang) 
    throws CodeGenerationException
  {
    String name = Fortran.getMethodSuperName(id, m, mang, d_context);
    List extendedArgs = extendArgs(id, m, d_context, false);
    List extendedArgsWithIndices = extendArgs(id, m, d_context, true);
    generateMethod(cls, name, extendedArgs, extendedArgsWithIndices,
                   m, id, isInterface, true);
  }

  /**
   * Generate the create method for a class.  The create method makes a new
   * wrapped instance of a class.
   *
   * @param id    the name of the class to write a creation method for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems during the code generation phase.
   */
  private void generateCreateMethod(SymbolID id) throws CodeGenerationException
  {
    String newName = (Fortran.isFortran90(d_context) || 
                      Fortran.hasBindC(d_context)) ? "_newLocal" : "__create";

    String methodName = id.getFullName().replace('.', '_') + newName 
        + Fortran.getMethodSuffix(d_context);


    d_writer.writeComment("Constructor for the class.", false);
    try {
      d_writer.pushLineBreak(false);
      d_writer.println("void");
      d_writer.println(Fortran.getFortranSymbol(d_context) +
                       "(" + methodName.toLowerCase()
      + ',' + methodName.toUpperCase() + ',' + methodName + ")");
    }
    finally {
      d_writer.popLineBreak();
    }
    d_writer.println("(");
    d_writer.tab();
    d_writer.println("int64_t *" + s_self + ",");
    d_writer.println("int64_t *" + s_exception);
    d_writer.backTab();
    d_writer.println(")");
    d_writer.println("{");
    d_writer.tab();
    d_writer.println(IOR.getExceptionFundamentalType() + "_ior_exception = NULL;");
    d_writer.println("*" + s_self + 
                     " = (ptrdiff_t) (*(_getIOR()->createObject))(NULL,&_ior_exception);");
    d_writer.println("*" + s_exception +
                     " = (ptrdiff_t)_ior_exception;");
    d_writer.println("if (_ior_exception) *" + s_self + " = 0;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }

  /**
   * Generate the wrapObj method for a class.  The wrapObj method makes a new
   * class and puts the passed in data pointer in d_data.
   *
   * @param id    the name of the class to write a creation method for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems during the code generation phase.
   */
  private void generateWrapObjMethod(SymbolID id) throws CodeGenerationException
  {
    if(!IOR.isSIDLSymbol(id)) {
      if(Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context) ) {
        String wrapName = "_wrapObj";
        String methodWrapName = id.getFullName().replace('.', '_') + wrapName 
          + Fortran.getMethodSuffix(d_context);
      
        d_writer.writeComment("Data Wrapper for the class.", false);
        try{
          d_writer.pushLineBreak(false);
          d_writer.println("void");
          d_writer.println(Fortran.getFortranSymbol(d_context) + "(" + methodWrapName.toLowerCase()
                         + ',' + methodWrapName.toUpperCase() + ',' + methodWrapName + ")");
        }
        finally {
          d_writer.popLineBreak();
        }
        d_writer.println("(");
        d_writer.tab();
        d_writer.println("void ** private_data,");
        d_writer.println("int64_t *" + s_self + ",");
        d_writer.println("int64_t *" + s_exception);
        d_writer.backTab();
        d_writer.println(")");
        d_writer.println("{");
        d_writer.tab();
        d_writer.println(IOR.getExceptionFundamentalType() + "_ior_exception = NULL;");
        d_writer.println("void* _proxy_private_data = "+C.NULL+";");
        d_writer.println("_proxy_private_data = sidl_malloc(SIDL_F90_POINTER_SIZE,");
        d_writer.tab();
        d_writer.println("\"Memory allocation failure\",");
        d_writer.println("__FILE__, __LINE__,");
        d_writer.println("\"" + methodWrapName + "\", &_ior_exception);");
        d_writer.backTab();
        d_writer.println("if (_proxy_private_data) { ");
        d_writer.tab();
        d_writer.println("memcpy(_proxy_private_data, private_data, SIDL_F90_POINTER_SIZE);");
        d_writer.println("*" + s_self + 
                         " = (ptrdiff_t) (*(_getIOR()->createObject))(_proxy_private_data,"+
                         "&_ior_exception);");
        d_writer.backTab();
        d_writer.println("}");
        d_writer.println("*" + s_exception +
                         " = (ptrdiff_t)_ior_exception;");
        d_writer.println("if (_ior_exception) *" + s_self + " = 0;");
        d_writer.backTab();
        d_writer.println("}");
        d_writer.println();
      
      } else {
        String wrapName = "__wrapObj";
        String methodWrapName = id.getFullName().replace('.', '_') + wrapName 
          + Fortran.getMethodSuffix(d_context);
      
        d_writer.writeComment("Data Wrapper for the class.", false);
        try {
          d_writer.pushLineBreak(false);
          d_writer.println("void");
          d_writer.println(Fortran.getFortranSymbol(d_context) + 
                           "(" + methodWrapName.toLowerCase()
                         + ',' + methodWrapName.toUpperCase() + ',' + methodWrapName + ")");
        }
        finally {
          d_writer.popLineBreak();
        }
        d_writer.println("(");
        d_writer.tab();
        d_writer.println("int64_t * private_data,");
        d_writer.println("int64_t *" + s_self + ",");
        d_writer.println("int64_t *" + s_exception);
        d_writer.backTab();
        d_writer.println(")");
        d_writer.println("{");
        d_writer.tab();
        d_writer.println(IOR.getExceptionFundamentalType() + "_ior_exception = NULL;");
        d_writer.println("*" + s_self + 
                         " = (ptrdiff_t) (*(_getIOR()->createObject))((void*)(ptrdiff_t)*private_data,"+
                         "&_ior_exception);");
        d_writer.println("*" + s_exception +
                         " = (ptrdiff_t)_ior_exception;");
        d_writer.println("if (_ior_exception) *" + s_self + " = 0;");
        d_writer.backTab();
        d_writer.println("}");
        d_writer.println();
      }
    }
  }

  /**
   * Generate the remote create method for a class.  The remote create
   * method makes a new wrapped instance of a class the refers to a remote
   * instance.
   *
   * @param id    the name of the class to write a creation method for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems during the code generation phase.
   */
  private void generateCreateRemoteMethod(Extendable ext) 
    throws CodeGenerationException
  {
    SymbolID id = ext.getSymbolID();
    Method m = Fortran.createRemoteMethod(ext, d_context, 
         (Fortran.isFortran90(d_context)||Fortran.hasBindC(d_context)));
    List arguments = extendArgs(id, m, d_context, false);
    List argumentsWithIndicies =   extendArgs(id, m, d_context, true);
    String name = Fortran.getMethodStubName(id, m, d_context);
    String cName = C.getFullMethodName(ext.getSymbolID(), "_remoteCreate");

    d_writer.println();
    d_writer.println();
    d_writer.writeComment("Remote Constructor for the class.", false);
    generateSignature(d_writer, name, argumentsWithIndicies, d_context,m,false);
    d_writer.println();
    d_writer.println("{");
    d_writer.tab();
    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    declareProxies(arguments);
    copyIncomingValues(arguments);
    d_writer.println(s_proxy+"self = "+cName+"("+s_proxy+"url, &"
                     +s_proxy+s_exception+");");
    checkExceptionBlock(m);
    copyOutgoingValues(arguments);
    endExceptionBlock(m);
    freeResources(arguments);
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();

  }

  /**
   * Generate the remote create method for a class.  The remote create
   * method makes a new wrapped instance of a class the refers to a remote
   * instance.
   *
   * @param id    the name of the class to write a creation method for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception for problems during the code generation phase.
   */
  private void generateConnectRemoteMethod(Extendable ext) 
    throws CodeGenerationException
  {
    SymbolID id = ext.getSymbolID();
    Method m = Fortran.connectRemoteMethod(ext, d_context, 
       (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)));
    List arguments = extendArgs(id, m, d_context, false);
    List argumentsWithIndicies =   extendArgs(id, m, d_context, true);
    String name = Fortran.getMethodStubName(id, m, d_context);
    String cName = C.getFullMethodName(ext.getSymbolID(), "_remoteConnect");

    d_writer.writeComment("Remote Connector for the class.", false);
    generateSignature(d_writer, name, argumentsWithIndicies, d_context,m,false);
    d_writer.println();
    d_writer.println("{");
    d_writer.tab();
    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    declareProxies(arguments);
    copyIncomingValues(arguments);
    d_writer.println(s_proxy+"self = "+cName+"("+s_proxy+"url, 1, &"
                     +s_proxy+s_exception+");");
    checkExceptionBlock(m);
    copyOutgoingValues(arguments);
    endExceptionBlock(m);
    freeResources(arguments);
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
    d_writer.backTab();
    d_writer.println("}");

  }

  private void generateCast(SymbolID id) throws CodeGenerationException {
    Method m = Fortran.createCast(d_context, id);
    List extendedArgs = extendArgs(id, m, d_context, false);
    String name = Fortran.getMethodStubName(id, m, d_context);
    d_writer.writeComment(m, false);
    generateSignature(d_writer, name, extendedArgs, d_context,m,false);
    d_writer.println();
    d_writer.println("{");
    d_writer.tab();
    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    d_writer.println("static int connect_loaded = 0;");
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
    d_writer.println("struct sidl_BaseInterface__object  *_base =");
    d_writer.tab();
    d_writer.println("(struct sidl_BaseInterface__object *)(ptrdiff_t)*ref;");
    d_writer.backTab();
    d_writer.println(IOR.getExceptionFundamentalType() + "proxy_exception;");
    d_writer.println();   

    d_writer.println("*retval = 0;");

    d_writer.println();
    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    d_writer.println();
    d_writer.println("if(!connect_loaded) {");
    d_writer.tab();
    d_writer.println("sidl_rmi_ConnectRegistry_registerConnect(\""+id.getFullName()+
                     "\", (void*)"+IOR.getSymbolName(id)+"__IHConnect, &proxy_exception);");
    d_writer.println("SIDL_CHECK(proxy_exception);");
    d_writer.println("connect_loaded = 1;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
    d_writer.println();

    d_writer.println("if (_base) {");
    d_writer.tab();
    d_writer.println("*retval = (ptrdiff_t)(");
    d_writer.tab();
    d_writer.println("*_base->d_epv->" 
      + IOR.getVectorEntry(IOR.getBuiltinName(IOR.CAST)) + ")(");
    d_writer.println("_base->d_object,");
    d_writer.println("\"" + id.getFullName() + "\", &proxy_exception);");
    d_writer.backTab();
    d_writer.backTab();
    d_writer.println("} else {");
    d_writer.tab();
    d_writer.println("*retval = 0;");
    d_writer.println("proxy_exception = 0;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    d_writer.println("EXIT:");
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
    d_writer.println("*exception = (ptrdiff_t)proxy_exception;");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }

  private void generateCastTwo(Extendable ext, SymbolID id, boolean isInterface)
    throws CodeGenerationException
  {
    Method m = IOR.getBuiltinMethod(IOR.CAST, id, d_context);
    List args = extendArgs(id, m, d_context, false);
    generateMethod(ext, Fortran.getMethodStubName
                   (id, 
                    Fortran.createCastTwo(d_context, id), d_context),
                   args, args, m, id, isInterface, false);
  }

  private void generateRMIForwardDecls(Extendable ext) 
    throws CodeGenerationException
  {
    SymbolID id = ext.getSymbolID();

    d_writer.printlnUnformatted("#ifdef WITH_RMI");
    if (!ext.isAbstract()) {
      d_writer.println("static " + C.getSymbolObjectPtr(id) + " " 
                       + IOR.getRemoteName(id) + "(const char* url, sidl_BaseInterface *_ex);");
    }
    d_writer.println("static " + C.getSymbolObjectPtr(id) + " " 
                     + C.getFullMethodName(id,"_remoteConnect") + 
                     "(const char* url, sidl_bool ar, sidl_BaseInterface *_ex);");
    
    d_writer.println("static " + C.getSymbolObjectPtr(id) + " " 
                     + C.getFullMethodName(id,"_IHConnect")  
                     + "(struct sidl_rmi_InstanceHandle__object *instance, struct sidl_BaseInterface__object **_ex);");
    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");

    Iterator i = IOR.getStructSymbolIDs(ext, true).iterator();
    while (i.hasNext()) {
      final SymbolID sid = (SymbolID)i.next();
      writeStructSerializeSig(d_writer, sid, true);
      d_writer.printlnUnformatted("#define RMI_" +
                                  IOR.getSymbolName(sid) + "_serialize(strct, pipe, name, copyArg, exc) { \\");
      d_writer.printlnUnformatted("  sidl_io_Serializer __pipe = sidl_io_Serializer__cast((pipe), (exc)); SIDL_CHECK(*(exc)); \\");
      d_writer.printlnUnformatted("  if (__pipe) { \\");
      d_writer.printlnUnformatted("    sidl_BaseInterface __throwaway__; \\");
      d_writer.printlnUnformatted("    " +     
                                  IOR.getSymbolName(sid) + 
                                  "__serialize_c((strct),__pipe, (name), (copyArg), (exc)); \\");
      d_writer.printlnUnformatted("    sidl_io_Serializer_deleteRef(__pipe, &__throwaway__); \\");
      d_writer.printlnUnformatted("  } \\");
      d_writer.printlnUnformatted("}");
      d_writer.println();
    }
    i = IOR.getStructSymbolIDs(ext, false).iterator();
    while (i.hasNext()) {
      final SymbolID sid = (SymbolID)i.next();
      writeStructSerializeSig(d_writer, sid, false);
      d_writer.printlnUnformatted("#define RMI_" +
                                  IOR.getSymbolName(sid) + "_deserialize(strct, pipe, name, copyArg, exc) { \\");
      d_writer.printlnUnformatted("  sidl_io_Deserializer __pipe = sidl_io_Deserializer__cast((pipe), (exc)); SIDL_CHECK(*(exc)); \\");
      d_writer.printlnUnformatted("  if (__pipe) { \\");
      d_writer.printlnUnformatted("    sidl_BaseInterface __throwaway__; \\");
      d_writer.printlnUnformatted("    " +     
                                  IOR.getSymbolName(sid) + 
                                  "__deserialize_c((strct),__pipe, (name), (copyArg), (exc)); \\");
      d_writer.printlnUnformatted("    sidl_io_Deserializer_deleteRef(__pipe, &__throwaway__); \\");
      d_writer.printlnUnformatted("  } \\");
      d_writer.printlnUnformatted("}");
      d_writer.println();
    }
  }

  private void generateBuiltins(Extendable ext)
    throws CodeGenerationException
  {
    SymbolID id = ext.getSymbolID();
    boolean isInterface = ext.isInterface();

    Method bi = IOR.getBuiltinMethod(IOR.EXEC,id, d_context,false);
    d_writer.println();
    extendAndGenerate(ext, bi, id, isInterface);

    bi = IOR.getBuiltinMethod(IOR.GETURL,id, d_context,false);
    d_writer.println();
    extendAndGenerate(ext, bi, id, isInterface);

    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id, d_context,false);
    d_writer.println();
    extendAndGenerate(ext, bi, id, isInterface);

    bi = IOR.getBuiltinMethod(IOR.ISREMOTE,id, d_context, false);
    bi.setMethodName("_isLocal");
    d_writer.println();
    extendAndGenerate(ext, bi, id, isInterface);

    bi = IOR.getBuiltinMethod(IOR.HOOKS,id, d_context, false);
    d_writer.println();
    extendAndGenerate(ext, bi, id, isInterface);

    if (ext.hasStaticMethod(true)) {
      bi = IOR.getBuiltinMethod(IOR.HOOKS,id, d_context, true);
      d_writer.println();
      extendAndGenerate(ext, bi, id, isInterface);
    }

  }  

  /**
   * This procedure writes the whole stub file for a class/interface.
   * It writes a banner, writes the includes needed, generates a create
   * method for classes, generates the cast methods, and then creates
   * stubs for all the methods.
   *
   * @param ext   a class/interface for which a stub file will be written.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception for problems during the code generation phase.
   */
  private void generateExtendable(Extendable ext)
    throws CodeGenerationException
  {
    Iterator i  = ext.getMethods(true).iterator();
    final SymbolID id = ext.getSymbolID();
    final boolean isInterface = ext.isInterface();

    d_writer.writeBanner(ext, Fortran.getStubFile(id), false, 
                         CodeConstants.C_DESC_STUB_PREFIX + id.getFullName());
    d_writer.writeComment(ext, false);

    generateIncludes((LanguageWriterForC) d_writer, ext, d_context);
    d_writer.println();

    //No Language specific RMI initialization for C
    d_writer.printlnUnformatted("#define "+RMI.LangSpecificInit());
    
    generateRMIForwardDecls(ext);
    
    if ((!ext.isAbstract()) || ext.hasStaticMethod(true)) {
      generateGetIOR(id);
    }
    if (ext.hasStaticMethod(true)) {
      generateGetStaticEPV(id);
    }

    if (!ext.isAbstract()) {
      generateCreateMethod(id);
      generateCreateRemoteMethod(ext);
      generateWrapObjMethod(id);
    }
    generateConnectRemoteMethod(ext);

    generateCast(id);
    generateCastTwo(ext, id, isInterface);

    generateBuiltins(ext);
    
    while (i.hasNext()) {
      Method method = (Method) i.next();
      extendAndGenerate(ext, method, id, isInterface);
      if ( method.getCommunicationModifier() == Method.NONBLOCKING ) { 
        Method send = method.spawnNonblockingSend();
        extendAndGenerate(ext, send, id, isInterface);
        Method recv = method.spawnNonblockingRecv();
        extendAndGenerate(ext, recv, id, isInterface);
      }
    }

    d_writer.println();
    FortArrayMethods fam = new FortArrayMethods(id, false, d_context);
    fam.generateStub(d_writer);
  }

  /**
   * Generate a FORTRAN include file containing integer constants for the
   * members of an enumerated type.
   * 
   * @param enm an enumeration object to provide an include file for.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception to indicate problems during the code generation
   *  phase of the sidl processing.
   */
  public void generateEnum(Enumeration enm) throws CodeGenerationException {
    final SymbolID id = enm.getSymbolID();
    if (d_writer instanceof LanguageWriterForFortran) {
      Iterator i;
      d_writer.writeBanner(enm, Fortran.getEnumStubFile(id), false,
                           CodeConstants.C_DESC_STUB_PREFIX + id.getFullName());
      d_writer.println();
      d_writer.writeComment(enm, false);
      d_writer.println();
      i = enm.getEnumerators().iterator();
      while (i.hasNext()){
        String sym = (String)i.next();
        Comment cmt = enm.getEnumeratorComment(sym);
        d_writer.writeComment(cmt, true);
        d_writer.print(Fortran.getReturnString(new Type(id, d_context), 
                                               d_context));
        if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
          d_writer.print(" :: ");
        } else {
          d_writer.print(" ");
        }
        d_writer.println(sym);
        d_writer.println("parameter (" + sym + " = " 
          + enm.getEnumeratorValue(sym) + ")");
        if (cmt != null) {
          d_writer.println();
        }
      }
    } else {
      // we just magically assume if it isn't fortran writer must be C. hrmmm.
      d_writer.writeBanner(enm, Fortran.getEnumStubImpl(id), false,
                           CodeConstants.C_DESC_STUB_PREFIX + id.getFullName());
      ((LanguageWriterForC)d_writer).generateInclude("sidl_long_IOR.h", true);
      ((LanguageWriterForC)d_writer).generateInclude("sidlfortran.h", true);
      ((LanguageWriterForC)d_writer).generateSystemInclude("stddef.h");
      if (Fortran.needsAbbrev(d_context)) {
        ((LanguageWriterForC)d_writer).
          generateInclude(Fortran.getStubNameFile(id), false);
      }
      FortArrayMethods fam = new FortArrayMethods(id, true, d_context);
      fam.generateStub(d_writer);
    }
  }

  private Set referencedStructs(Struct strct)
    throws CodeGenerationException
  {
    HashSet result = new HashSet();
    Iterator i = strct.getSymbolReferences().iterator();
    while (i.hasNext()) {
      SymbolID id = (SymbolID)i.next();
      Symbol sym = Utilities.lookupSymbol(d_context, id);
      if (sym instanceof Struct) {
        result.add(sym);
      }
    }
    return result;
  }

  private void generateStruct(Struct strct)
    throws CodeGenerationException
  {
    LanguageWriterForC cwriter = (LanguageWriterForC)d_writer;
    d_writer.writeBanner(strct, Fortran.getStubFile(strct), false,
                         CodeConstants.C_DESC_STUB_PREFIX + 
                         strct.getFullName());
    d_writer.writeComment(strct, false);
    cwriter.generateInclude(IOR.getHeaderFile(strct), false);
    cwriter.printlnUnformatted("#include <string.h>");
    cwriter.printlnUnformatted("#include <stdlib.h>");
    cwriter.generateInclude("sidl_BaseInterface_IOR.h", true);
    cwriter.generateInclude("sidl_io_Serializer.h", true);
    cwriter.generateInclude("sidl_io_Deserializer.h", true);
    cwriter.generateInclude("sidl_Exception.h", true);
    Set refs = referencedStructs(strct);
    Iterator i = refs.iterator();
    while (i.hasNext()) {
      final SymbolID id = (SymbolID)i.next();
      writeStructSerializeSig(d_writer, id, true);
      d_writer.printlnUnformatted("#define RMI_" +
                                  IOR.getSymbolName(id) + "_serialize " +
                                  IOR.getSymbolName(id) + "__serialize_c");
      writeStructSerializeSig(d_writer, id, false);
      d_writer.printlnUnformatted("#define RMI_" +
                                  IOR.getSymbolName(id) + "_deserialize " +
                                  IOR.getSymbolName(id) + "__deserialize_c");
    }
    d_writer.println();
    writeStructSerialize(strct, true);
    writeStructSerialize(strct, false);
  }
    

  /**
   * Generate a C file to provide FORTRAN stubs for a sidl
   * object/interface. The stubs allow FORTRAN clients to make calls on
   * objects and interfaces or static methods.  No stub code is generated
   * enumerated types and packages.  Outside clients typically use 
   * {@link #generateCode generateCode} instead of calling this method
   * directly.
   *
   * @param symbol  the symbol for which stubs will be generated.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception to indicate problems during the code generation
   *  phase of the sidl processing.
   */
  public void generateCode(Symbol symbol) throws CodeGenerationException {
    final String pre = "fortran.StubSource.generateCode: ";
    switch(symbol.getSymbolType()) {
    case Symbol.STRUCT:
      generateStruct((Struct)symbol);
      break;
    case Symbol.CLASS:
    case Symbol.INTERFACE:
      if (d_writer instanceof LanguageWriterForC) {
        generateExtendable((Extendable)symbol);
        RMIStubSource.generateCode( symbol, (LanguageWriterForC) d_writer, d_context );
      } else {
        throw new CodeGenerationException(pre + "Extendable stub requires C "
                    + "language writer.");
      }
      break;
    case Symbol.ENUM:
      generateEnum((Enumeration)symbol);
      break;
    case Symbol.PACKAGE:
      break;
    default:
      throw new CodeGenerationException(pre + "Unsupported symbol type.");
    }
  }

  /**
   * Generate a C file to provide FORTRAN stubs for a sidl
   * object/interface. The stubs allow FORTRAN clients to make calls on
   * objects and interfaces or static methods.  No stub code is generated
   * enumerated types and packages.
   *
   * @param ext     the symbol for which stubs will be generated.
   * @param writer  the output device where the stub should be written.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception to indicate problems during the code generation
   *  phase of the sidl processing.
   */
  public static void generateCode(Symbol ext, LanguageWriter writer,
                                  Context context)
    throws CodeGenerationException
  {
    StubSource source = new StubSource(writer, context);
    source.generateCode(ext);
  }

  public static void writeStructSerializeSig(LanguageWriter writer,
                                             SymbolID structid,
                                             boolean serialize)
    throws CodeGenerationException
  {
    final String pipeType = 
      (serialize ? "sidl_io_Serializer" : "sidl_io_Deserializer");
    writer.printlnUnformatted("#ifdef __cplusplus");
    writer.println("extern \"C\"");
    writer.printlnUnformatted("#endif /* __cplusplus */");
    writer.println("void");
    writer.println(Fortran.structSerializeStub(structid, serialize) + "(");
    writer.tab();
    writer.println((serialize ? "const " : "") + 
                   IOR.getStructName(structid) + " *arg,");
    writer.println("struct " + pipeType + "__object *pipe,");
    writer.println("const char *,");
    writer.println("sidl_bool,");
    writer.println("sidl_BaseInterface *);");
    writer.backTab();
    writer.println();
  }

  private void writeStructSerialize(Struct strct,
                                    boolean serialize)
    throws CodeGenerationException
  {
    writeStructSerializeSig(d_writer, strct, serialize);
    if (serialize) {
      gov.llnl.babel.backend.c.StubSource.
        writeStructSerialize(d_writer, strct, "_c");
    }
    else {
      gov.llnl.babel.backend.c.StubSource.
        writeStructDeserialize(d_writer, strct, "_c", d_context);
    }
  }
}
