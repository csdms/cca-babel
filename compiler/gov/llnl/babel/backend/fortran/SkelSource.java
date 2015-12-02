//
// File:        SkelSource.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6482 $
// Description: Generate to allow the IOR to call FORTRAN implementations
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

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.c.C;
import gov.llnl.babel.backend.fortran.Fortran;
import gov.llnl.babel.backend.fortran.ImplSource;
import gov.llnl.babel.backend.fortran.StubSource;
import gov.llnl.babel.backend.mangler.FortranMangler;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.mangler.NonMangler;
import gov.llnl.babel.backend.writers.LanguageWriter;
import gov.llnl.babel.backend.writers.LanguageWriterForC;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.CExprString;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.Inverter;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * The purpose of this class is to generate the C skeleton code to support
 * sidl objects implemented in FORTRAN. The skeleton code makes the link
 * between the independent object representation (IOR) and the FORTRAN 
 * implementation of a sidl class.
 * 
 * The skeleton must map datatypes in C to datatypes in FORTRAN. It must
 * must also provide C functions to populate the static and object entry
 * point vectors for the IOR.
 */
public class SkelSource {

  private static final String s_ensureOrderConstant[] = {
    "sidl_general_order",
    "sidl_column_major_order",
    "sidl_row_major_order"
  };

  private static final String s_epv       = "epv";
  private static final String s_pre_epv   = "pre_epv";
  private static final String s_post_epv  = "post_epv";
  private static final String s_sepv      = "sepv";
  private static final String s_pre_sepv  = "pre_sepv";
  private static final String s_post_sepv = "post_sepv";

  /**
   * This string is prepended to the name of an argument to get the name of
   * a proxy variable. A proxy variable is a stand in for an argument that
   * has incompatible representations in the C and FORTRAN.
   */
  private static final String s_proxy = "_proxy_";

  /**
   * This string is prepended to the name of an argument to get the name of
   * a proxy variable. A proxy variable is a stand in for an argument that
   * has incompatible representations in the C and FORTRAN.
   */
  private static final String s_proxyTwo = "_alt_";

  /**
   * This string is prepended to the name of an argument to get the name of
   * a buffer variables for a CHAR argument.
   */
  private static final String s_buffer = "_buf_";

  /**
   * Store the name of the fundamental base exception type used in BABEL.
   */
  private static final String s_exceptionFundamentalType = 
    BabelConfiguration.getBaseExceptionType();

  /**
   * This stores the output device to be used when generating the skeleton.
   */
  private LanguageWriterForC d_writer;

  private NameMangler d_mang;
  
  private Context d_context;

  /**
   * Create an object to generate the skeleton code in C for a FORTRAN 
   * object.
   *
   * @param writer   the skeleton code is written to this device.
   * @exception java.security.NoSuchAlgorithmException
   *   problem with the name mangler.
   */
  public SkelSource(LanguageWriterForC writer,
                    Context context) 
    throws NoSuchAlgorithmException 
  {
    d_writer = writer;
    d_context = context;
    if (Fortran.needsAbbrev(context)) {
      d_mang =  new FortranMangler(AbbrevHeader.MAXNAME, 
                                   AbbrevHeader.MAXUNMANGLED);
    } else {
      d_mang  =  new NonMangler();
    }
  }

  /**
   * Generate the external declaration for the FORTRAN subroutine.
   * This uses C preprocessor macros to handle the various compiler
   * specific relationship between C and FORTRAN.
   *
   * @param name  the name of the method.
   * @param args  the extended argument list.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void generateExtern(String name, List args, Method m)
    throws CodeGenerationException
  {
    boolean gotFunc=ImplSource.isFortranFunction(m.getReturnType());
    StubSource.generateSignature(d_writer, name, args, d_context, m, gotFunc);
    d_writer.println(";");
  }

  /**
   * Write something to take the value of the arguments.
   *
   * @param argName  the name of the argument.
   * @param mode     the mode of the argument.
   */
  private void writeArgValue(String argName, int mode) {
    if (mode != Argument.IN && !Fortran.s_return.equals(argName)) {
      d_writer.print("*");
    }
    d_writer.print(argName);
  }

  private String getArgValueStr(String argName, int mode) {
    return 
      ((mode != Argument.IN && !Fortran.s_return.equals(argName)) 
       ? "*" : "" ) + argName;
  }

  /**
   * Write the argument list for the skeleton function.  The signature of
   * the skeleton function must match the declaration in the EPV.
   *
   * @param  args     the extended list of arguments.
   * @param  builtIn  the method is built-in (e.g., pre/post hooks) so
   *                  do want the return added to the argument list.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void writeSkelArgs(List args, boolean builtIn) 
     throws CodeGenerationException 
  {
    int argsWritten = 0;
    Iterator i = args.iterator();
    boolean comma = false;
    while (i.hasNext() ) {
      Argument a = (Argument)i.next();
      if ( (!Fortran.s_return.equals(a.getFormalName())) || (builtIn) )  {
        if (comma) {
          d_writer.println(",");
        }
        d_writer.print(IOR.getArgumentWithFormal(a, d_context, true, false, false));
        ++argsWritten;
        comma = true;
      }
    }
    if (argsWritten == 0) {
      d_writer.print("void");
    }
  }

  /**
   * Declare the proxy variables.  The proxy variable is a FORTRAN 
   * compatible stand in for the argument from the IOR.
   * 
   * @param argName   the name of the original argument.
   * @param argType   the type of the original argument.
   * @param argMode   the calling mode of the argument.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void declareProxy(String argName, Type argType, int argMode)
    throws CodeGenerationException
  {
    final String pre = "fortran.SkelSource.declareProxy: ";
    switch(argType.getDetailedType()) {
    case Type.BOOLEAN:
      d_writer.println(Fortran.getFortranPrefix(d_context) + 
                       "_Bool " + s_proxy 
        + argName + ";");
      break;
    case Type.ARRAY:
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        if (argType.isRarray()) {
          d_writer.println(getReturnString(argType) + " " + s_proxy + argName 
            + " = 0;");
        } else {
          d_writer.println(Fortran.getFortranTypeInC(argType, d_context) 
            + " " + s_proxy + argName + " = { 0 };");
          if (Fortran.hasDirectAccess(argType) && 
              (Argument.OUT != argMode)) {
            d_writer.println(getReturnString(argType) + " " + s_proxyTwo 
              + argName + " = 0;");
          }
        }
      } else {
        d_writer.println((argType.isRarray() ? getReturnString(argType)
          : Fortran.getFortranTypeInC(argType,d_context)) +
                         " " + s_proxy + argName 
            + " = 0;");
      }
      break;
    case Type.CLASS:
    case Type.INTERFACE:
    case Type.OPAQUE:
      d_writer.println("int64_t " + s_proxy + argName + " = 0;");
      break;
    case Type.STRING:
      d_writer.println(Fortran.getFortranPrefix(d_context) +
                       "_STR_LOCAL(" + s_proxy 
        + argName + ");");
      break;
    case Type.CHAR:
      d_writer.printlnUnformatted(StubSource.charCheck(d_context));
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL(" + s_proxy 
        + argName + ");");
      d_writer.println("char " + s_buffer + argName + "[2];");
      d_writer.printlnUnformatted("#endif");
      break;
    case Type.SYMBOL:
      throw new CodeGenerationException(pre + "Unable to process " 
                  + argType.getTypeString() + ' ' + argName);
    default:
      if (Fortran.s_return.equals(argName)) {
        d_writer.println(getReturnString(argType) + ' ' + s_proxy + argName
          + ";");
      }
      break;
    }
  }

  /**
   * Loop through the list of arguments and declare proxies for those that
   * need them.
   *
   * @param args the extended list of arguments.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void declareProxies(List args) throws CodeGenerationException {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      int      mode = a.getMode();
      declareProxy(name, t, mode);
    }
  }

  private void declareIndexAndInit(Argument rawArray, Argument index, int dimen)
    throws CodeGenerationException
  {
    d_writer.print(Fortran.getFortranTypeInC(index.getType(), d_context) + ' ' 
      + index.getFormalName() + " = ");
    d_writer.print(CExprString.
                   toCString(Inverter.invertExpr
                             ((AssertionExpression)
                              rawArray.getType().
                              getArrayIndexExprs().get(dimen),
                              "sidlLength(" + 
                              getArgValueStr(rawArray.getFormalName(),
                                             rawArray.getMode()) +
                              ", " + dimen + ")",d_context)));
    d_writer.println(";");
  }

  private void declareIndices(Map indexArgs) throws CodeGenerationException {
    if (indexArgs != null) {
      Iterator i = indexArgs.keySet().iterator();
      while(i.hasNext()) {
        Collection choice = (Collection)indexArgs.get(i.next());
        if (choice.size() > 0) {
          Method.RarrayInfo info = (Method.RarrayInfo)choice.iterator().next();
          declareIndexAndInit(info.rarray, info.index, info.dim);
        }
      }
    }
  }

  /**
   * Provide an expression to provide the array value in a specified
   * ordering, if necessary.
   *
   * @param array      the type of the array.
   * @param argName    the name of the variable holding the current array.
   * @param mode       the argument mode
   */
  private void ensureArray(Type array, String argName, int mode) {
    if (array.hasArrayOrderSpec()) {
      Type elemType = array.getArrayType();
      d_writer.println();
      d_writer.tab();
      d_writer.println(Fortran.getEnsureArray(elemType));
      d_writer.tab();
      writeArgValue(argName, mode);
      d_writer.println(",");
      d_writer.println(array.getArrayDimension() + ",");
      d_writer.println(s_ensureOrderConstant[array.getArrayOrder()] + ")");
      d_writer.backTab();
      d_writer.backTab();
    } else {
      writeArgValue(argName, mode);
    }
  }

  /**
   * Provide initial values for the proxy variables. For <code>in</code> and
   * <code>inout</code> arguments, this generates code to translate the
   * incoming value to a FORTRAN compatible version.
   *
   * @param argName the formal name of the original arugment.
   * @param argType the type of the argument.
   * @param mode    the mode of the argument.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void initializeProxy(Method m,String argName, Type argType, int mode)
    throws CodeGenerationException
  {
    final String pre = "fortran.SkelSource.initializeProxy: ";
    switch(argType.getDetailedType()) {
    case Type.ARRAY:
      if (mode != Argument.OUT) {
        Type dataType = argType.getArrayType();
        if ((Fortran.isFortran90(d_context)||
             Fortran.hasBindC(d_context)) && 
            Fortran.hasDirectAccess(argType)) {
          if (argType.isRarray()) {
            d_writer.print(s_proxy + argName + " = ");
            ensureArray(argType, argName, mode);
            d_writer.println(";");
          } else {
            d_writer.print(s_proxyTwo + argName + " = ");
            ensureArray(argType, argName, mode);
            d_writer.println(";");
            d_writer.println("if (sidl_" + dataType.getTypeString() 
              + "__array_convert2f90(" + s_proxyTwo + argName + ", " 
              + argType.getArrayDimension() + ", &" + s_proxy + argName 
              + ")) {");
            d_writer.tab();
            if (!argType.hasArrayOrderSpec()) {
              d_writer.println(s_proxyTwo + argName + " = " 
                + Fortran.getEnsureArray(dataType) + s_proxyTwo + argName 
                + ", " + argType.getArrayDimension() 
                + ", sidl_column_major_order);");
              d_writer.println("if (sidl_" + dataType.getTypeString() 
                + "__array_convert2f90(" + s_proxyTwo + argName + ", " 
                + argType.getArrayDimension() + ", &" + s_proxy + argName 
                + ")) {");
              d_writer.tab();
            }
            d_writer.writeCommentLine("We're S.O.L");
            d_writer.println("fprintf(stderr, \"convert2f90 failed: %p %d\\n\","
              + " (void*)" + argName + ", " + argType.getArrayDimension() 
              + ");");
            d_writer.println("exit(1); /*NOTREACHED*/");
            if (!argType.hasArrayOrderSpec()) {
              d_writer.backTab();
              d_writer.println("}");
            }
            d_writer.backTab();
            d_writer.println("}");
          }
        } else {
          d_writer.print(s_proxy + argName + Fortran.arrayIOR(d_context) + 
                         " = (");
          if (!argType.isRarray()) {
            d_writer.print("(ptrdiff_t)");
          }
          ensureArray(argType, argName, mode);
          d_writer.println(");");
        }
        if ((mode == Argument.INOUT) && argType.hasArrayOrderSpec()) {
          d_writer.print(Fortran.getDelRefArray(argType.getArrayType()));
          writeArgValue(argName, mode);
          d_writer.println(");");
        }
      }
      break;
    case Type.OPAQUE:
      if (mode != Argument.OUT) {
        d_writer.print(s_proxy + argName + " = ((ptrdiff_t)");
        writeArgValue(argName, mode);
        d_writer.println(");");
      }
      break;

    case Type.CLASS:
    case Type.INTERFACE:
      if (mode != Argument.OUT) {
        d_writer.print(s_proxy + argName + " = ((ptrdiff_t)");
        writeArgValue(argName, mode);
        d_writer.println(");");
      }
      break;
    case Type.BOOLEAN:
      d_writer.print(s_proxy + argName + " = ");
      if (mode != Argument.OUT) { 
        d_writer.print("(((");
        writeArgValue(argName, mode);
        d_writer.println(")== TRUE) ? " + Fortran.getFortranPrefix(d_context) + "_TRUE "
          + ": " + Fortran.getFortranPrefix(d_context) + "_FALSE);"); 
      } else {
        d_writer.println(Fortran.getFortranPrefix(d_context) + "_TRUE;");
      }
      break;
    case Type.STRING:
      if ((mode == Argument.IN) || (mode == Argument.INOUT)) {
        d_writer.print(Fortran.getFortranPrefix(d_context) + "_STR_COPY(" + s_proxy 
          + argName + ", ");
        writeArgValue(argName, mode);
        if (mode == Argument.IN) {
          d_writer.println(", 0);");
        } else {
          d_writer.println(", " + Fortran.getFortranPrefix(d_context) +"_STR_MINSIZE);");
          d_writer.print("free((void *)");
          writeArgValue(argName, mode);
          d_writer.println(");");
          writeArgValue(argName, mode);
          d_writer.println(" = NULL;");
        }
      } else {
        d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_COPY(" + s_proxy 
          + argName + ", NULL, " + Fortran.getFortranPrefix(d_context) + "_STR_MINSIZE)"
          + ";");
      }
      break;
    case Type.CHAR:
      d_writer.printlnUnformatted(StubSource.charCheck(d_context));
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_LEN(" 
        + s_proxy + argName + ") = 1;");
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_STR(" 
        + s_proxy + argName + ") = " + s_buffer + argName + ";");
      d_writer.print(s_buffer + argName + "[0] = ");
      if (Argument.OUT != mode) {
        writeArgValue(argName, mode);
      } else {
        d_writer.println("' '");
      }
      d_writer.println(";");
      d_writer.println(s_buffer + argName + "[1] = '\\0';");
      d_writer.printlnUnformatted("#endif");
      break;
    case Type.SYMBOL:
      throw new CodeGenerationException(pre + "Unable to process " 
                  + argType.getTypeString() + ' ' + argName);
    }
  }

  /**
   * Loop through the argument list and write the code to initialize
   * the proxy variables.
   *
   * @param args  the list of arguments.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void initializeProxies(Method m, List args) throws CodeGenerationException {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      initializeProxy(m, name, t, a.getMode());
    }
  }

  /**
   * Deal with Function args for FORTRAN function call.
   *
   * @param args   the list of arguments.
   *
   *  This should only be called if this is BindC AND it's a function
   */
  private void listFuncArgs(List args) {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();

      if (!Fortran.s_return.equals(name)){
      if (StubSource.hasProxy(t) || (Fortran.s_return.equals(name))) {
        switch(t.getDetailedType()) {
        case Type.STRING:
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_ARG(" 
            + s_proxy + name + ")");
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_NEAR_LEN(" 
            + s_proxy + name + ")");
          break;
        case Type.CHAR:
            d_writer.printlnUnformatted(StubSource.charCheck(d_context));
            d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_ARG(" 
              + s_proxy + name + ")");
            d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_NEAR_LEN(" 
              + s_proxy + name + ")");
            d_writer.printlnUnformatted("#else");
            d_writer.println("&" + s_proxy + name);
            d_writer.printlnUnformatted("#endif");
          break;
        case Type.ARRAY:
          if (t.isRarray()) {
            d_writer.print(s_proxy + name + "->d_firstElement");
            break;
          }
          // fall through to default intended
        default:
            d_writer.print("&" + s_proxy + name);
          break;
        }
      } else {
          if (a.getMode() == Argument.IN && t.getDetailedType() != Type.STRUCT) {
            d_writer.print("&");
          }
          d_writer.print(name);
        }
        if (i.hasNext()) {
          d_writer.println(",");
        }
      }
    }
  }
  /**
   * List each normal argument for the FORTRAN subroutine call.
   *
   * @param args   the list of arguments.
   */
  private void listNormalArguments(List args) {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      if (StubSource.hasProxy(t) || Fortran.s_return.equals(name)) {
        switch(t.getDetailedType()) {
        case Type.STRING:
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_ARG(" 
            + s_proxy + name + ")");
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_NEAR_LEN(" 
            + s_proxy + name + ")");
          break;
        case Type.CHAR:
          d_writer.printlnUnformatted(StubSource.charCheck(d_context));
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_ARG(" 
            + s_proxy + name + ")");
          d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_NEAR_LEN(" 
            + s_proxy + name + ")");
          d_writer.printlnUnformatted("#else");
          d_writer.println("&" + s_proxy + name);
          d_writer.printlnUnformatted("#endif");
          break;
        case Type.ARRAY:
          if (t.isRarray()) {
            d_writer.print(s_proxy + name + "->d_firstElement");
            break;
          }
          // fall through to default intended
        default:
          d_writer.print("&" + s_proxy + name);
          break;
        }
      } else {
        if (a.getMode() == Argument.IN && t.getDetailedType() != Type.STRUCT) {
          d_writer.print("&");
        }
        d_writer.print(name);
      }
      if (i.hasNext()) {
        d_writer.println(",");
      }
    }
  }

  /**
   * Deal with characters as Function return types.  This should ONLY be called
   * if the F2003 binding is being used and we are writing a function in the fSkel
   * files.
   *
   * @param args  the list of arguments.
   */
  private void listStringLengthFuncArgs(List args)
  {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      if (!Fortran.s_return.equals(name)){
        switch (t.getDetailedType()) {
          case Type.STRING:
            d_writer.println("#error Strings not supported as F03 function return types");
            break;
          case Type.CHAR:
            d_writer.println("#error Characters not supported as F03 function return types");
            break;
        }
      }
    }
  }

  /**
   * On some compilers, the string lengths are passed as extra arguments at
   * the end of the argument list.  List the length of each string argument.
   *
   * @param args  the list of arguments.
   */
  private void listStringLengthArguments(List args)
  {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      Type     t    = a.getType();
      String   name = a.getFormalName();
      switch (t.getDetailedType()) {
      case Type.STRING:
        d_writer.println();
        d_writer.print(Fortran.getFortranPrefix(d_context) + "_STR_FAR_LEN(" + s_proxy 
          + name + ")");
        break;
      case Type.CHAR:
        d_writer.println();
        d_writer.printlnUnformatted(StubSource.charCheck(d_context));
        d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_FAR_LEN(" + s_proxy
          + name + ")");
        d_writer.printlnUnformatted("#endif");
        break;
      }
    }
  }

  /**
   * Generate the code to call the FORTRAN implementation method.
   * This is complicated by the fact that the signature for a FORTRAN
   * method is compiler dependent. This generated code uses
   * a combination of preprocessor macros to handle compiler
   * specific changes.
   *
   * @param methodName   the name of the FORTRAN subroutine.
   * @param args         the extended list of arguments.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void callMethod(String methodName, List args,boolean gotFunc)
    throws CodeGenerationException
  {
    if (gotFunc && Fortran.hasBindC(d_context)){
      d_writer.print("_proxy_retval = ");
    }

    d_writer.println(Fortran.getFortranSymbol(d_context) + "(" + methodName.toLowerCase()
      + "," + methodName.toUpperCase() + "," + methodName + ")(");
    d_writer.tab();
    if (gotFunc && Fortran.hasBindC(d_context)){
      listFuncArgs(args);
      listStringLengthFuncArgs(args);
    } else {
      listNormalArguments(args);
      listStringLengthArguments(args);
    }
    d_writer.println(");");
    d_writer.backTab();
  }

  /**
   * When dealing with a method that throws exceptions, generate code to
   * check whether an exception has occured.  The generated code will
   * process the exception if it has occured.
   * 
   * @param method   details of the method.
   */
  private void checkExceptionBlock(Method m) throws CodeGenerationException {
    if (!m.getThrows().isEmpty()) {
      Symbol symbol = Utilities.lookupSymbol(d_context, 
                                             s_exceptionFundamentalType);
      d_writer.println("if (" + s_proxy + StubSource.s_exception + ") {");
      d_writer.tab();
      switch (m.getReturnType().getDetailedType()) {
      case Type.VOID: 
	  break;
      case Type.DCOMPLEX:
      case Type.FCOMPLEX:
        d_writer.println(Fortran.s_return + ".real = 0;");
        d_writer.println(Fortran.s_return + ".imaginary = 0;");
        break;
      default:
	  d_writer.println(Fortran.s_return + " = 0;");
      }
      d_writer.println("*" + StubSource.s_exception + " = (" 
        + IOR.getSymbolType(symbol) + ")");
      d_writer.tab();
      d_writer.println("(ptrdiff_t)(" + s_proxy + StubSource.s_exception 
        + ");");
      d_writer.backTab();
      d_writer.backTab();
      d_writer.println("} else {");
      d_writer.tab();
    }
  }

  /**
   * When dealing with a method that throws exceptions, this method 
   * generates code to close the exception block.
   *
   * @param m  details of the method.
   */
  private void endExceptionBlock(Method m) {
    if (!m.getThrows().isEmpty()) {
      d_writer.backTab();
      d_writer.println("}");
    }
  }

  /**
   * For <code>out</code> and <code>inout</code> parameters, convert the
   * values from the proxy variables into something that the 
   * IOR can handle.
   * 
   * @param argType   the type of the argument.
   * @param argName   the original name of the formal argument.
   * @param mode      the mode of the argument.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void doOutArg(Type argType, String argName, int mode)
    throws CodeGenerationException
  {
    final String pre = "fortran.SkelSource.doOutArg: ";
    switch(argType.getDetailedType()) {
    case Type.ARRAY:
      if (Argument.IN != mode) {
        String modName = "(" + getReturnString(argType) + ")" 
                         + (argType.isRarray() ? ( s_proxy + argName )
                           : ("(ptrdiff_t)(" + s_proxy + argName 
                             + Fortran.arrayIOR(d_context) + ")"));
        writeArgValue(argName, mode);
        d_writer.print(" = (" + getReturnString(argType) + ")");
        ensureArray(argType, modName, Argument.IN);
        d_writer.println(";");
        if (argType.hasArrayOrderSpec()) {
          d_writer.print(Fortran.getDelRefArray(argType.getArrayType()) 
                         + (argType.isRarray() ? "(" : "(ptrdiff_t)("));
          d_writer.println(s_proxy + argName 
                     + (argType.isRarray() ? "" :
                        Fortran.arrayIOR(d_context))+ "));");
          if (argType.isRarray()) {
            d_writer.println(s_proxy + argName + " = NULL;");
          }
        }
      }
      break;
    case Type.OPAQUE:
    case Type.CLASS:
    case Type.INTERFACE:
      writeArgValue(argName, mode);
      d_writer.print(" = (" + getReturnString(argType) + ")(ptrdiff_t)");
      d_writer.println(s_proxy + argName + ";");
      break;
    case Type.BOOLEAN:
      writeArgValue(argName, mode);
      d_writer.println(" = ((" + Fortran.getFortranPrefix(d_context) + "_TRUE == " 
        +  s_proxy + argName + ") ? TRUE : FALSE);");
      break;
    case Type.STRING:
      writeArgValue(argName, mode);
      d_writer.println(" = sidl_trim_trailing_space(");
      d_writer.tab();
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_STR(" 
        + s_proxy + argName + "),(ptrdiff_t)");
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_LEN(" 
        + s_proxy + argName + "));");
      d_writer.backTab();
      d_writer.println(Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_STR(" 
        + s_proxy + argName + ") = NULL;");
      break;
    case Type.CHAR:
      d_writer.printlnUnformatted(StubSource.charCheck(d_context));
      writeArgValue(argName, mode);
      d_writer.println(" = *(" + Fortran.getFortranPrefix(d_context) + "_STR_LOCAL_STR("
        + s_proxy + argName + "));");
      d_writer.printlnUnformatted("#endif");
      break;
    case Type.SYMBOL:
      throw new CodeGenerationException(pre + "Unable to process " 
                  + argType.getTypeString() + ' ' + argName);
    case Type.STRUCT:
      if (argName.equals(Fortran.s_return)) {
        writeArgValue(argName, mode);
        d_writer.println(" = &" + s_proxy + argName + ";");
      }
      break;
    default:
      if (argName.equals(Fortran.s_return)) {
        writeArgValue(argName, mode);
        d_writer.println(" = " + s_proxy + argName + ";");
      }
      break;
    }
  }

  private void releaseIncomingRefs(List args) throws CodeGenerationException {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument  a    = (Argument)i.next();
      final Type argType = a.getType();
      if (((Argument.IN == a.getMode()) && argType.hasArrayOrderSpec()) ||
          argType.isRarray()) {
        final String argName = a.getFormalName();
        d_writer.print(Fortran.getDelRefArray(argType.getArrayType()) 
                       + (argType.isRarray() ? "(" : "(ptrdiff_t)("));
        d_writer.println(s_proxy + argName 
                         + (argType.isRarray() ? "" 
                            :Fortran.arrayIOR(d_context))+ "));");
      }
    }
  }

  /**
   * Loop through the list of arguments and generate code to
   * process the <code>out</code> and <code>inout</code> parameters.
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void processOutgoing(List args) throws CodeGenerationException {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument  a    = (Argument)i.next();
      final Type t   = a.getType();
      final int mode = a.getMode();
      if ((Argument.IN != mode) || t.hasArrayOrderSpec()) {
        doOutArg(a.getType(), a.getFormalName(), mode);
      }
    }
  }

  /**
   * Free resources that were temporarily allocated for the method call.
   * For example, free the memory allocated for a string.
   *
   * @param args  the extended list of arguments.
   */
  private void freeResources(Method m, List args) {
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a    = (Argument)i.next();
      String   name = a.getFormalName();
      Type     t    = a.getType();
      if (t.getDetailedType() == Type.STRING){
        d_writer.println("free((void *)" + Fortran.getFortranPrefix(d_context) 
          + "_STR_LOCAL_STR(" + s_proxy + name + "));");
      }
    }
    if ((Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) &&
        m.getLongMethodName().equals(IOR.getBuiltinName(IOR.DESTRUCTOR))) {
      d_writer.println("if (self->d_data) free(self->d_data);");
    }
  }

  /**
   * Declare a variable to hold the return value of the method.
   * 
   * @param t  the type of the method's return value.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void declareReturn(Type t) throws CodeGenerationException {
    if (Type.VOID != t.getDetailedType()) {
      switch (t.getDetailedType()) {
        case Type.STRUCT:
          //Structs as return values should be pointers.
          d_writer.print(getReturnString(t) + " *" + Fortran.s_return+"=NULL");
          break;
        default:
          d_writer.print(getReturnString(t) + " " + Fortran.s_return);
          if (Utilities.isPointer(t)) {
            d_writer.print(" = NULL");
          }
          break;
        }

      d_writer.println(";"); 
    }
  }

  /**
   * The statement that actually returns the return value of the method.
   * 
   * @param t  the type of the method's return value.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void addReturnStatement(Type t) throws CodeGenerationException {
    if (Type.VOID != t.getDetailedType()) {
      switch (t.getDetailedType()) {
        case Type.STRUCT:
          d_writer.println("return *" + Fortran.s_return + ";");
          break;
        default:
          d_writer.println("return " + Fortran.s_return + ";");
          break;
      }
    }
  }

  /**
   * This manages the generation of a skeleton function for a particular
   * method.
   * 
   * @param args   the extended argument list for the method.
   * @param argsWithInidices the extended argument list for the method plus
   *                         the index variables.
   * @param m      other information about the method.
   * @param id     the name of the symbol who owns the method.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void generateMethod(List args, List argsWithIndices, Method m,
                              SymbolID id)
    throws CodeGenerationException
  {

    boolean gotFunc=ImplSource.isFortranFunction(m.getReturnType());

    d_writer.println("static " + getReturnString(m.getReturnType()));
    d_writer.println(Fortran.getMethodSkelName(id, m) + "(");
    d_writer.tab();
    writeSkelArgs(args, m.isBuiltIn());
    d_writer.println(")");
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    /*
     * If this is not one of the built-in methods (e.g., pre/post hooks),
     * then be sure to declare the return type.
     */
    if (!m.isBuiltIn()) {
      declareReturn(m.getReturnType());
    }
    declareProxies(args);
    declareIndices(m.getRarrayInfo());
    initializeProxies(m,args);
    callMethod(Fortran.getMethodImplName(id, m, d_mang, d_context), 
               argsWithIndices,gotFunc);
    checkExceptionBlock(m);
    processOutgoing(args);
    endExceptionBlock(m);
    releaseIncomingRefs(args);
    freeResources(m, args);
    addReturnStatement(m.getReturnType());
    d_writer.backTab();
    d_writer.println("}");
  }

  /**
    * Generate a return string for the specified SIDL type.  Most
    * of the SIDL return strings are listed in the static structures defined
    * at the start of this class.  Symbol types and array types require
    * special processing.
    */
  public String getReturnString(Type type)
     throws CodeGenerationException
   {
     return IOR.getReturnString(type, d_context, true, false);
   }

  /**
   * Extend the argument list to include implicit arguments, generate the
   * extern declaration for the FORTRAN subroutine and then generate the
   * skeleton code for the method.
   * 
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  private void extendAndGenerate(Method m, SymbolID id)
    throws CodeGenerationException
  {
    List extendedArgs = StubSource.extendArgs(id, m, d_context, false);
    List extendedArgsWithIndices = StubSource.extendArgs(id, m, d_context,
                                                         true);

    d_writer.println();
    d_writer.println();
    generateExtern(Fortran.getMethodImplName(id, m, d_mang, d_context), 
                   extendedArgsWithIndices, m);
    d_writer.println();
    generateMethod(extendedArgs, extendedArgsWithIndices, m, id);
  }

  /**
   * Add the implicit builtin methods to the list of methods. There are
   * implicit functions for the constructor and destructor.
   * 
   * @param cls   the class object.
   */
  private Collection extendMethods(Class cls) throws CodeGenerationException {
    Collection localMethods = cls.getMethods(false);
    final SymbolID id = cls.getSymbolID();
    ArrayList  extendedMethods = new ArrayList(localMethods.size()+2);
    extendedMethods.add(IOR.getBuiltinMethod(IOR.CONSTRUCTOR, id, d_context));
    if (!Fortran.isFortran90(d_context) && !Fortran.hasBindC(d_context)) {
      extendedMethods.add(IOR.getBuiltinMethod(IOR.CONSTRUCTOR2, id, d_context ));
    }
    extendedMethods.add(IOR.getBuiltinMethod(IOR.DESTRUCTOR, id, d_context));
    extendedMethods.addAll(localMethods);
    return extendedMethods;
  }

  /**
   * Write a function to initialize entries in the static entry point vector
   * for a particular class. This will generate an assignment statement for
   * each <code>static</code> method defined locally in the class.
   * 
   * @param cls    the class for which an routine will be written.
   * @param writer the output writer to which the routine will be written.
   */
  private static void writeInitializeSEPV(Class              cls, 
                                          Collection         methods,
                                          LanguageWriterForC writer,
                                          Context            context)
     throws CodeGenerationException
  {
    SymbolID id = cls.getSymbolID();
    writer.openCxxExtern();
    writer.println("void");
    writer.print(IOR.getSetSEPVName(id) + "(" + IOR.getSEPVName(id) + " * ");
    writer.print(s_sepv);
    if (IOR.generateHookMethods(cls, context)) {
      writer.println(",");
      writer.tab();
      writer.println(IOR.getPreSEPVName(id) + " *" + s_pre_sepv + ", ");
      writer.println(IOR.getPostSEPVName(id) + " *" + s_post_sepv + ") ");
      writer.backTab();
    } else {
      writer.print(") ");
    } 
    writer.println("{");
    writer.tab();
    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if (m.isStatic()) {
        initializeMethodPointer(writer, m, cls, true, context);
      }
    }
    writer.backTab();
    writer.println("}");
    writer.closeCxxExtern();
    writer.println();
  }

  private void writeDataAccess(SymbolID id)
    throws java.io.UnsupportedEncodingException
  {
    String getData = d_mang.shortName(id.getFullName(), "_get_data", 
                                      Fortran.getMethodSuffix(d_context));
    String setData = d_mang.shortName(id.getFullName(), "_set_data", 
                                      Fortran.getMethodSuffix(d_context));
    String humanGetName = id.getFullName().replace('.','_') 
                          + "__get_data" + Fortran.getMethodSuffix(d_context);
    String humanSetName = id.getFullName().replace('.','_') 
                          + "__set_data" + Fortran.getMethodSuffix(d_context);
    d_writer.beginBlockComment(false);
    d_writer.println("The FORTRAN impl calls this to get the data pointer.");
    d_writer.println("This function name may be a mangled form of");
    d_writer.println(humanGetName);
    d_writer.endBlockComment(false);
    d_writer.println("void");
    d_writer.println(Fortran.getFortranSymbol(d_context) + "(" + getData.toLowerCase() 
      + ',');
    d_writer.tab();
    d_writer.println(getData.toUpperCase() + ',');
    d_writer.println(getData + ')');
    d_writer.print("(int64_t *object, ");
    d_writer.println((Fortran.isFortran90(d_context)||
                      Fortran.hasBindC(d_context)) ? "void *data)" : "int64_t *data)");
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    d_writer.println(IOR.getObjectName(id) + " *local = ");
    d_writer.tab();
    d_writer.println("((" + IOR.getObjectName(id) + " *)(ptrdiff_t)*object);");
    d_writer.backTab();
                     
    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
      d_writer.println("if (local && local->d_data) {");
      d_writer.tab();
      d_writer.println("memcpy(data, local->d_data, SIDL_F90_POINTER_SIZE);");
      d_writer.backTab();
      d_writer.println("} else {");
      d_writer.tab();
      d_writer.println("/* _get_data called before _set_data */");
      d_writer.printlnUnformatted("fputs(\"Babel:" + humanGetName 
        + " called before " + humanSetName + "! FATAL ERROR (unitialized "
        + "pointer)!\", stderr);");
      d_writer.println("abort();/*NOTREACHED*/");
      d_writer.backTab();
      d_writer.println("}");
    } else {
      d_writer.println("*data = local ? (ptrdiff_t)(local->d_data) : "
        + "(ptrdiff_t)0;");
    }
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();

    d_writer.beginBlockComment(false);
    d_writer.println("The FORTRAN impl calls this to set the data pointer.");
    d_writer.println("This function name may be a mangled form of");
    d_writer.println(humanSetName);
    d_writer.endBlockComment(false);
    d_writer.println("void");
    d_writer.println(Fortran.getFortranSymbol(d_context) + "(" + setData.toLowerCase() 
      + ',');
    d_writer.tab();
    d_writer.println(setData.toUpperCase() + ',');
    d_writer.println(setData + ')');
    d_writer.print("(int64_t *object, ");
    d_writer.println((Fortran.isFortran90(d_context)||
                      Fortran.hasBindC(d_context)) 
                     ? "void *data)" : "int64_t *data)");
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    d_writer.println(IOR.getObjectName(id) + " *local = ");
    d_writer.tab();
    d_writer.println("((" + IOR.getObjectName(id) + " *)(ptrdiff_t)*object);");
    d_writer.backTab();
    d_writer.println("if (local) {");
    d_writer.tab();
    // I decided not to throw a MemAlloc exception here, since the malloc
    // already has a failure mode, and no good way to throw exceptions.
    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
      d_writer.println("if (!(local->d_data)) {");
      d_writer.tab();
      d_writer.println("local->d_data = malloc(SIDL_F90_POINTER_SIZE);");
      d_writer.backTab();
      d_writer.println("}");
      d_writer.println("if (local->d_data) {");
      d_writer.tab();
      d_writer.println("memcpy(local->d_data, data, SIDL_F90_POINTER_SIZE);");
      d_writer.backTab();
      d_writer.println("} else {");
      d_writer.tab();
      d_writer.printlnUnformatted("fputs(\"" + humanSetName + " failed in a "
        + "malloc call!\", stderr);");
      d_writer.backTab();
      d_writer.println("}");
    } else {
      d_writer.println("local->d_data = (void *)(ptrdiff_t)*data;");
    }
    d_writer.backTab();
    d_writer.println("}");
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }

  /**
   * Write the function assignment for the specified var and method name
   * to the specified value.
   *
   * @param writer     the output writer to which the assignment statement
   *                   is written.
   * @param var        the pointer variable representing the EPV.
   * @param mname      the method name.
   * @param value      the desired value, or RHS.
   */
  private static void writeMethodAssignment(LanguageWriter writer, String var,
                                            String mname, String value)
  {
    writer.println(var + "->" + mname + " = " + value + ";");
  }

  /**
   * Include initializations of pre- and post-method hooks.
   * 
   * @param writer     the output writer to which the assignment statement
   *                   is written.
   * @param m          a description of the method to initialize
   * @param cls        the class that owns the method
   * @param doStatic   TRUE if initializing a static epv; FALSE otherwise
   */
  private static void initializePointers(LanguageWriter writer, 
                                         Method         m,
                                         Class          cls,
                                         boolean        doStatic,
                                         Context        context)
     throws CodeGenerationException
  {
    final SymbolID id       = cls.getSymbolID();
    final String methodName = m.getLongMethodName();
    final String ename      = IOR.getVectorEntry(methodName);
    final String sname      = Fortran.getMethodSkelName(id, m);
    String epvStr           = doStatic ? s_sepv : s_epv;

    if ( IOR.generateHookMethods(cls, context) && (!m.isBuiltIn()) ) {
      String preEpv  = doStatic ? s_pre_sepv : s_pre_epv;
      String postEpv = doStatic ? s_post_sepv : s_post_epv;
      Method hook    = m.spawnPreHook();
      writeMethodAssignment(writer, preEpv, 
                            IOR.getVectorEntry(hook.getLongMethodName()), 
                            Fortran.getMethodSkelName(id, hook));
      writeMethodAssignment(writer, epvStr, ename, sname);
      hook = m.spawnPostHook(false, false);
      writeMethodAssignment(writer, postEpv, 
                            IOR.getVectorEntry(hook.getLongMethodName()), 
                            Fortran.getMethodSkelName(id, hook));
    } else {
      writeMethodAssignment(writer, epvStr, ename, sname);
    }
  }

  /**
   * Write an assignment statement to * initialize a particular membor of 
   * the entry point vector. 
   * 
   * @param writer     the output writer to which the assignment statement
   *                   is written.
   * @param m          a description of the method to initialize
   * @param cls        the class that owns the method
   * @param doStatic   TRUE if initializing a static epv; FALSE otherwise
   */
  private static void initializeMethodPointer(LanguageWriter writer, 
                                              Method         m,
                                              Class          cls,
                                              boolean        doStatic,
                                              Context        context)
     throws CodeGenerationException
  {
    if (doStatic) {
      initializePointers(writer, m, cls, doStatic, context);
    } else {
      switch (m.getDefinitionModifier()) {
        case Method.FINAL:
        case Method.NORMAL:
          initializePointers(writer, m, cls, doStatic, context);
          break;
        case Method.ABSTRACT:
          String methodName = m.getLongMethodName();
          writeMethodAssignment (writer, s_epv, IOR.getVectorEntry(methodName),
                                 "NULL");
          break;
        default:
          /* do nothing */
          break;
        }
    }
  }

  /**
   * Write a function to initialize entries in the entry point vector for
   * a particular class. This will generate an assignment statement for
   * each non-<code>static</code> method defined locally in the class.
   * 
   * @param cls    the class for which an routine will be written.
   * @param writer the output writer to which the routine will be written.
   */
  private static void writeInitializeEPV(Class              cls,
                                         Collection         methods,
                                         LanguageWriterForC writer, 
                                         boolean            isSuper,
                                         Context            context) 
     throws CodeGenerationException
  {
    SymbolID id = cls.getSymbolID();
    writer.openCxxExtern();
    writer.println("void");
    writer.print(IOR.getSetEPVName(id) + "(" + IOR.getEPVName(id) + " * ");
    writer.print(s_epv);
    if (IOR.generateHookMethods(cls, context)) {
      writer.println(",");
      writer.tab();
      writer.println(IOR.getPreEPVName(id) + " *" + s_pre_epv + ", ");
      writer.println(IOR.getPostEPVName(id) + " *" + s_post_epv + ") ");
      writer.backTab();
    } else {
      writer.print(") ");
    } 
    writer.println("{");
    writer.tab();
    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if (!m.isStatic()) {
        initializeMethodPointer(writer, m, cls, false, context);
      }
    }

    if(isSuper)
      writer.println("superEPV = _getIOR()->getSuperEPV();");

    writer.backTab();
    writer.println("}");
    writer.closeCxxExtern();
    writer.println();
  }

  private void generateCtor2(SymbolID id)
    throws CodeGenerationException
  {
    Method m = IOR.getBuiltinMethod(IOR.CONSTRUCTOR2, id, d_context);
    final String implMethod = Fortran.getMethodImplName(id, m, d_mang,
                                                        d_context);
    List extendedArgs = StubSource.extendArgs(id, m, d_context, false);
    Type type=m.getReturnType();
    try {
      d_writer.pushLineBreak(false);
      StubSource.generateMethodSymbol(d_writer, implMethod, d_context,m.getReturnType(),false);
      d_writer.tab();
      d_writer.println("int64_t *self,");
      d_writer.println("void    *private_data,");
      d_writer.println("int64_t *exception");
      d_writer.backTab();
      d_writer.println(");");
    }
    finally {
      d_writer.popLineBreak();
    }
    d_writer.println();
    
    d_writer.println("static void");
    d_writer.println(Fortran.getMethodSkelName(id, m) + "(");
    d_writer.tab();
    writeSkelArgs(extendedArgs, m.isBuiltIn());
    d_writer.println(")");
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    d_writer.println("int64_t _proxy_self = (ptrdiff_t)self;");
    d_writer.println("int64_t _proxy_" + StubSource.s_exception + 
                     " = 0;");
    d_writer.println(Fortran.getFortranSymbol(d_context) + "(" + 
                     implMethod.toLowerCase()
                     + "," + implMethod.toUpperCase() + "," + 
                     implMethod + ")(");
    d_writer.tab();
    d_writer.println("&_proxy_self, private_data, &_proxy_" +
                     StubSource.s_exception);
    d_writer.backTab();
    d_writer.println(");");
    d_writer.println("*"  + StubSource.s_exception + 
                     " = (struct sidl_BaseInterface__object *)" +
                     "(ptrdiff_t)_proxy_"+  StubSource.s_exception + ";");
    d_writer.backTab();
    d_writer.println("}");

  }

  /**
   * This method creates a skeleton file for a class.  The
   * skeleton file is a C module that is the glue between the IOR and
   * the implementation of a class written in FORTRAN.
   *
   * @param cls  the class to create.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void generateCode(Class cls) throws CodeGenerationException {
    final String pre = "fortran.SkelSource.generateCode: ";
    Collection methods = extendMethods(cls);
    final SymbolID id = cls.getSymbolID();

    d_writer.writeBanner(cls, Fortran.getSkelFile(id), false,
                         CodeConstants.C_DESC_SKEL_PREFIX + id.getFullName());
    d_writer.println();

    StubSource.generateIncludes(d_writer, cls, d_context);
    d_writer.generateSystemInclude("string.h");
    d_writer.generateSystemInclude("stdio.h");

    d_writer.println();

    if(cls.hasOverwrittenMethods()) {
      //Generate the code necessary for super methods
      StubSource.generateSupers(cls, d_writer, d_context);
    }

    Iterator i = methods.iterator();
    while (i.hasNext()) {
      Method m = (Method)i.next();
      if (!m.isAbstract()) {
        if (IOR.generateHookMethods(cls, d_context) && (!m.isBuiltIn()) ) {
          extendAndGenerate(m.spawnPreHook(), id);
          extendAndGenerate(m, id);
          extendAndGenerate(m.spawnPostHook(false, false), id);
        } else {
          extendAndGenerate(m, id);
        } 
      }
    }
    if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
      generateCtor2(id);
      methods.add(IOR.getBuiltinMethod(IOR.CONSTRUCTOR2, id, d_context));
    }
    
    writeRMIAccessFunctions(cls); 

    /* now do _load (which is special (not extern, fancy name, etc)). */
    Method load_meth = IOR.getBuiltinMethod(IOR.LOAD, id, d_context);
    List load_args = StubSource.extendArgs(id, load_meth, d_context, false);
    generateExtern(Fortran.getMethodImplName(id, load_meth, d_mang, d_context),
                   load_args, load_meth);
    d_writer.println();
    d_writer.println("void " + IOR.getSymbolName(id) + "__call_load(void) { ");
    d_writer.tab();
    d_writer.println("int64_t _proxy_exception;");
    callMethod(Fortran.getMethodImplName(id,load_meth,d_mang, d_context),
               load_args,false);
    d_writer.backTab();
    d_writer.println("}");

    d_writer.println();
    d_writer.println();
    writeInitializeEPV(cls, methods, d_writer, cls.hasOverwrittenMethods(), 
                       d_context);
    if (cls.hasStaticMethod(true)) {
      d_writer.println();
      writeInitializeSEPV(cls, methods, d_writer, d_context);
      d_writer.println();
    }

    try {
      writeDataAccess(id);
    } catch (java.io.UnsupportedEncodingException uee) {
      throw new CodeGenerationException(pre + uee.getMessage());
    }
  }

  /**
   * This is a convenience routine to create a skeleton file for a class
   * without having to make an instance of <code>SkelSource</code>.  The
   * skeleton file is a C module that is the glue between the IOR and
   * the implementation of a class written in FORTRAN.
   *
   * @param cls    the class for whom a skeleton will be made.
   * @param writer the output device where the skeleton file will be
   *               sent.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   * @exception java.security.NoSuchAlgorithmException
   *   problem with the name mangler.
   */
  public static void generateCode(Class              cls,
                                  LanguageWriterForC writer,
                                  Context            context)
    throws CodeGenerationException, NoSuchAlgorithmException
  {
    SkelSource source = new SkelSource(writer, context);
    source.generateCode(cls);
  }

  /**
   * Write functions to call each RMI fconnect function
   *
   * @param cls    the class for which an routine will be written.
   * @param writer the output writer to which the routine will be written.
   */
  private void writeRMIAccessFunctions(Class cls) 
    throws CodeGenerationException
  {
    SymbolID id = cls.getSymbolID();

    Set fconnectSIDs = IOR.getFConnectSymbolIDs(cls);
    d_writer.printlnUnformatted("#ifdef WITH_RMI");

    for (Iterator i = fconnectSIDs.iterator(); i.hasNext(); ) {        
      SymbolID destination_id = (SymbolID) i.next();
      d_writer.println(C.getSymbolObjectPtr(destination_id) + " " + IOR.getSkelFConnectName(id,destination_id)+ 
                       "(const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { ");
      d_writer.tab();
      d_writer.println("return "+C.getFullMethodName(destination_id, "_connectI")+"(url, ar, _ex);");
      d_writer.backTab();
      d_writer.println("}");
      d_writer.println();
    }

    d_writer.printlnUnformatted("#endif /*WITH_RMI*/");
   
    Iterator i = IOR.getStructSymbolIDs(cls, true).iterator();
    while(i.hasNext()) {
      writeStructSerialize(cls, (SymbolID)i.next(), true);
    }
    i = IOR.getStructSymbolIDs(cls, false).iterator();
    while(i.hasNext()) {
      writeStructSerialize(cls, (SymbolID)i.next(), false);
    }
  }


  private void writeStructSerialize(Extendable ext,
                                    SymbolID structid,
                                    boolean serialize)
    throws CodeGenerationException
  {
    final String pipeType = 
      (serialize ? "sidl_io_Serializer" : "sidl_io_Deserializer");
    StubSource.writeStructSerializeSig(d_writer, structid, serialize);
    d_writer.println("void");
    d_writer.println(IOR.getSkelSerializationName(ext, structid, serialize) +
                     "(");
    d_writer.tab();
    d_writer.println((serialize ? "const " : "") +
                     IOR.getStructName(structid) + " *strct,");
    d_writer.println("struct sidl_rmi_" +
                     (serialize ? "Return" : "Call") +
                     "__object *pipe,");
    d_writer.println("const char *name,");
    d_writer.println("sidl_bool copy,");
    d_writer.println("sidl_BaseInterface *_ex)");
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    d_writer.println("sidl_BaseInterface throwaway_exception;");
    d_writer.println("sidl_BaseInterface bipipe = (sidl_BaseInterface)pipe;");
    d_writer.println("struct " + pipeType + "__object *uppipe =");
    d_writer.tab();
    d_writer.println("(struct " + pipeType + "__object *)");
    d_writer.println("(*bipipe->d_epv->f__cast)(bipipe->d_object,");
    d_writer.println("\"" + pipeType.replace('_','.') + "\",");
    d_writer.println("&throwaway_exception);");
    d_writer.backTab();
    d_writer.println(Fortran.structSerializeStub(structid, serialize) + "(");
    d_writer.tab();
    d_writer.println("strct, uppipe, name, copy, _ex);");
    d_writer.backTab();
    d_writer.backTab();
    d_writer.println("}");
    d_writer.println();
  }
}
