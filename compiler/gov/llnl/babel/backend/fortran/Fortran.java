//
// File:        Fortran.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6482 $
// Description: Collection of static methods for the FORTRAN binding
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
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.writers.LanguageWriterForC;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.Comment;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.FortranExprString;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

/**
 * Provide a collection of static methods to provide the mapping of sidl
 * concepts into FORTRAN.  This class provides the mapping of symbol names
 * to FORTRAN symbols, the mapping of the wrapper code to a set of files,
 * and the mapping of types.
 */
public class Fortran implements CodeConstants 
{

  public static final String s_return = "retval";

  /**
   * The order of all of the following arrays must match the ordering of 
   * the constants in the Type class.  A separate version is maintained to
   * facilitate translation for each version of fortran.
   *
   * @see gov.llnl.babel.symbols.Type
   */
  private final static String s_f77_types[] = {
    "void",                     // void
    "logical",                  // bool
    "character",                // character
    "double complex",           // dcomplex
    "double precision",         // double
    "complex",                  // fcomplex
    "real",                     // float
    "integer*4",                // int
    "integer*8",                // long
    "integer*8",                // opaque
    "character*(*)",            // string
    "integer*8",                // enum
    "void",                     // struct
    "integer*8",                // class
    "integer*8",                // interface
    "void",                     // package
    "integer*8"                 // symbol
  };

  private final static String s_f90_types[] = {
    "void",  					// void
    "logical",  				// bool
    "character (len=1)",  			// character
    "complex (kind=sidl_dcomplex)",             // dcomplex
    "real (kind=sidl_double)",          	// double
    "complex (kind=sidl_fcomplex)",     	// fcomplex
    "real (kind=sidl_float)",		        // float
    "integer (kind=sidl_int)",		        // int
    "integer (kind=sidl_long)",		        // long
    "integer (kind=sidl_opaque)",		// opaque
    "character (len=*)",       			// string
    "integer (kind=sidl_enum)",		        // enum
    "void"                                      // struct
  };
  
  private final static String s_f03_types[] = {
    "void",  					// void
    "logical",  				// bool
    "character (len=1)",  			// character
    "complex (kind=sidl_dcomplex)",             // dcomplex
    "real (kind=sidl_double)",          	// double
    "complex (kind=sidl_fcomplex)",     	// fcomplex
    "real (kind=sidl_float)",		        // float
    "integer (kind=sidl_int)",		        // int
    "integer (kind=sidl_long)",		        // long
    "integer (kind=sidl_opaque)",		// opaque
    "character (len=*)",       			// string
    "integer (kind=sidl_enum)"		        // enum
  };

  /**
   * This array stores the name of the C type that corresponds to the FORTRAN
   * type for a particular sidl type.  For example, an opaque maps into
   * <code>integer*8</code> in FORTRAN.  When the <code>integer*8</code>
   * comes into C, it is a <code>int64_t</code>.
   */
  private final static String[] s_cTypeMatchingFortran = {
    "void",                     // void
    "SIDL_F77_Bool",            // bool
    "char",                     // character
    "struct sidl_dcomplex",     // dcomplex
    "double",                   // double
    "struct sidl_fcomplex",     // fcomplex
    "float",                    // float
    "int32_t",                  // int
    "int64_t",                  // long
    "int64_t",                  // opaque
    "char *",                   // string
    "int64_t",                  // enum
    "void",                   // struct
    "int64_t",                  // class
    "int64_t",                  // interface
    "void",                     // package
    "int64_t",                  // symbol
    "int64_t"                   // array
  };
  private final static int    s_Fortran_Bool = 1;
  private final static String s_F90_Bool = "SIDL_F90_Bool";
  private final static String s_F90_Array = "struct sidl_fortran_array";


  /**
   * This class is not intended for public instantiation.
   */
  private Fortran()
  {
    // not intended for instantiation
  }

  /**
   * Convert a symbol name into string with the pieces of the symbol joined
   * together with underline characters.
   *
   * @param id  the symbol id to convert.
   * @return a string representation of the symbol with periods replaced
   * with underline characters.
   */
  public static String getSymbolName(SymbolID id) {
      return id.getFullName().replace('.', '_');
  }

  /**
   * Convert a symbol name into string with the pieces of the symbol joined
   * together with underline characters. Generate short file names 
   * if the options for generating code in package-dependent subdirectories
   * and excluding external symbols are enabled (--generate-subdirs and
   * --exclude-external).
   *
   * @param id  the symbol id to convert.
   * @return a string representation of the symbol with periods replaced
   * with underline characters.
   */
  public static String getSymbolNameForFile(SymbolID id) {
    return id.getFullName().replace('.', '_');
  }
	
  /** 
   * Same as above method, but use an extra argument for determining 
   * when the file whose name is to be generated corresponds to an impl.
   */
  public static String getSymbolNameForFile(SymbolID id, boolean isImpl,
                                            Context context) {
    if (context.getConfig().makePackageSubdirs() && 
        context.getConfig().getShortFileNames()) {
      return id.getShortName().replace('.','_');
    } else {
      return id.getFullName().replace('.', '_');
    }
  }


  /**
   * Return the name of the stub file for a particular symbol.
   * The stub file is a C file that receives calls from FORTRAN client.
   *
   * @param id  the symbol whose stub file will be returned
   * @return the filename of a C file containing the implementation of
   *         the FORTRAN stubs.
   */
  public static String getStubFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_fStub.c";
  }

  public static String getStubNameFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_fAbbrev.h";
  }

  /**
   * Return the name of the stub header file for a particular symbol.
   * The stub header file is a C file that globablly externs a few 
   * special functions in the fStub.
   *
   * @param id  the symbol whose stub file will be returned
   * @return the filename of a C file containing the implementation of
   *         the FORTRAN stubs.
   */
  public static String getHeaderFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_fStub.h";
  }

  /**
   * Return the name of the F77 stub documentation file for a particular
   * symbol. The documentation file is FORTRAN pseudo-code to
   * document the calling interface for FORTRAN clients.
   *
   * @param id  the symbol whose stub documentation file will be returned
   * @return the filename of a text file containing the documentation
   *         of the FORTRAN stubs.
   */
  public static String getStubDocFile(SymbolID id) {
    return getSymbolNameForFile(id) + ".fif";
  }

  /**
   * Return the name of the F90 stub module file for a particular
   * symbol. The module file is an F90 file used to package "global
   * data, derived types and their associated operations, interface
   * blocks, and namelist groups."
   *
   * @param id  the symbol whose stub documentation file will be returned
   * @return the filename of a text file containing the documentation
   *         of the FORTRAN stubs.
   */
  public static String getModuleFile(SymbolID id) {
    return getSymbolNameForFile(id) + "." + CodeConstants.C_F90_IMPL_EXTENSION;
  }

  /**
   * Return the name of the F90 type module file for a particular
   * symbol. The module file is an F90 file used to package the
   * derived type for the symbol.
   *
   * @param id  the symbol whose stub documentation file will be returned
   * @return the filename of a text file containing the documentation
   *         of the FORTRAN stubs.
   */
  public static String getTypeFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_type." + CodeConstants.C_F90_IMPL_EXTENSION;
  }

  public static String getTypeModule(SymbolID id) {
    return getSymbolName(id) + "_type";
  }

  public static String getArrayModule(SymbolID id) {
    return getSymbolName(id) + "_array";
  }

  public static String getArrayFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_array." + CodeConstants.C_F90_IMPL_EXTENSION;
  }

  public static String getTypeName(SymbolID id) {
    return getSymbolName(id) + "_t";
  }

  public static String getArrayName(SymbolID id, int dim) {
    if(dim == 0) {//If dim == 0, we'll assume it's a generic array
      return "sidl__array";
    }
    return getSymbolName(id) + "_" + dim + "d";
  }

  public static String getModule(SymbolID id) {
    return getSymbolName(id);
  }

  /**
   * Reorder an argument list to guarantee that all raw arrays occur at the
   * end of the argument list. The relative position of non-raw arrays
   * arguments is unchanged by this function.
   *
   * @param args  the incoming list of arguments
   * @return  the incoming list has been reordered such that all raw arrays
   *          appear at the end.
   */
  public static List reorderArguments(List args)
  {
    ArrayList result = new ArrayList(args.size());
    ArrayList deferred = new ArrayList(args.size());
    Iterator i = args.iterator();
    while (i.hasNext()) {
      Argument a = (Argument)i.next();
      if (a.getType().isRarray()) {
        deferred.add(a);
      }
      else {
        result.add(a);
      }
    }
    result.addAll(deferred);
    return result;
  }

  static public String structSerializeStub(SymbolID id,
                                           boolean serialize)
  {
    return id.getFullName().replace('.', '_') +
      (serialize ? "__serialize_c" : "__deserialize_c");
  }

  

  static public String arrayIndices(List indices)
  {
    StringBuffer result = new StringBuffer();
    Iterator i = indices.iterator();
    result.append('(');
    while (i.hasNext()) {
      AssertionExpression ae = (AssertionExpression)i.next();
      result.append("0:");
      result.append(ae.accept(new FortranExprString(), null).toString());
      result.append("-1");
      if (i.hasNext()) {
        result.append(", ");
      }
    }
    result.append(')');
    return result.toString();
  }

  public static boolean hasDirectAccess(Type t)
  {
    if (t.getDetailedType() == Type.ARRAY) {
      final Type arrayType = t.getArrayType();
      if (null != arrayType) {
        switch(arrayType.getDetailedType()) {
        case Type.DCOMPLEX:
        case Type.DOUBLE:
        case Type.FCOMPLEX:
        case Type.FLOAT:
        case Type.INT:
        case Type.LONG:
          return true;
        }
      }
    }
    return false;
  }

  /**
   * Return the name of the stub file for a particular enumeration.
   * The stub file is a DEC FORTRAN include file that defines
   * integer parameters that hold the values of the enumerations.
   *
   * @param id  the symbol whose stub file will be returned
   * @return the filename of a FORTRAN inc file containing the implementation of
   *         the FORTRAN stubs.
   */
  public static String getEnumStubFile(SymbolID id) {
    return getSymbolNameForFile(id) + ".inc";
  }

  public static String getEnsureArray(Type arrayType) {
    switch(arrayType.getDetailedType()) {
    case Type.INTERFACE:
    case Type.CLASS:
      return "sidl_interface__array_ensure((struct sidl_interface__array *)";
    case Type.ENUM:
      return "sidl_long__array_ensure((struct sidl_long__array *)";
    default:
      return "sidl_" + arrayType.getTypeString() + "__array_ensure(";
    }
  }

  public static String getInitArray(Type arrayType) {
    return "sidl_" + arrayType.getTypeString() + "__array_init(";
  }

  public static String getDelRefArray(Type arrayType) {
    return "sidl__array_deleteRef((struct sidl__array *)";
  }

  /**
   * Return the name of the stub impl file for a particular enumeration.
   * The stub file is a C source file that holds the array of enumeration
   * stubs.
   *
   * @param id  the symbol whose stub file will be returned
   * @return the filename of a C file containing the implementation of
   *         the FORTRAN enum array stubs.
   */
  public static String getEnumStubImpl(SymbolID id) {
    return getSymbolNameForFile(id) + "_fStub.c";
  }

  /**
   * Return the name of the file that holds the implementation of the
   * skeletons for FORTRAN. The skeleton file is written in C, and it is
   * the glue between the IOR and a FORTRAN.
   */
  public static String getSkelFile(SymbolID id) {
    return getSymbolNameForFile(id) + "_fSkel.c";
  }

  /**
   * Return the appropriate FORTRAN extension.
   *
   * @return the FORTRAN file extension.
   */
  public static String getImplExtension(Context context) {
    if (isFortran90(context) || hasBindC(context)) {
      return CodeConstants.C_F90_IMPL_EXTENSION;
    } else {
      if (isFortran7731(context)) {
        return CodeConstants.C_F7731_IMPL_EXTENSION;
      }
      else {
        return CodeConstants.C_F77_IMPL_EXTENSION;
      }
    }
  }

  /**
   * Return the name of the file that hold the implementation of the
   * FORTRAN sidl object. The BABEL system generates the subroutine
   * declarations, but the user needs to fill in the subroutine bodies.
   *
   * @param id the name of the symbol
   * @return the filename for the sidl object implementation.
   */
  public static String getImplFile(SymbolID id, Context context) {
    return getSymbolNameForFile(id, true, context) + "_Impl." + 
      getImplExtension(context);
  }

  /**
   * Return the name of the file that hold the derived types for
   * implementation of the FORTRAN sidl object.
   *
   * @param id the name of the symbol
   * @return the filename for the sidl impl module file.
   */
  public static String getImplModuleFile(SymbolID id, Context context) {
    return getSymbolNameForFile(id, true, context) + "_Mod." + 
      getImplExtension(context);
  }

  /**
   * Return the name of the file that hold the derived types for
   * Fortran/BindC to C/C++ interoperability.
   *
   * @param id the name of the symbol
   * @return the filename for the sidl struct module file.
   */
  public static String getStructModuleFile(SymbolID id, Context context) {
    return getSymbolNameForFile(id, true, context) + "."+ 
      getImplExtension(context);
  }

  /**
   * Get the function name that should be used for the FORTRAN stubs to the
   * sidl object methods.  This method does not take into account the
   * compiler specific issues (i.e. whether the symbol should be all upper
   * or lower case or whether it has underscores appended); it provides
   * the starting name with potentially mixed case.
   *
   * @param  id     the name of the symbol who has the method.
   * @param  method information about the method to be named.
   * @return the name of the function to be used in the FORTRAN stub.
   */
  public static String getMethodStubName(SymbolID id, 
                                         Method method,
                                         Context context) {
    return getSymbolName(id) + "_" + method.getLongMethodName() 
           + getMethodSuffix(context);
  }

  /**
   * Get the function name that should be used for the FORTRAN stubs to the
   * sidl object methods.  This method does not take into account the
   * compiler specific issues (i.e. whether the symbol should be all upper
   * or lower case or whether it has underscores appended); it provides
   * the starting name with potentially mixed case.
   *
   * @param  id     the name of the symbol who has the method.
   * @param  method information about the method to be named.
   * @return the name of the function to be used in the FORTRAN stub.
   */
  public static String getAltStubName(SymbolID id, Method method) {
    return getSymbolName(id) + "_" + method.getLongMethodName() 
           + getAltSuffix();
  }

  /**
   * Get the function name that should be used for the FORTRAN super method
   * in the skels (availible in this Impls). This method does not take into account the
   * compiler specific issues (i.e. whether the symbol should be all upper
   * or lower case or whether it has underscores appended); it provides
   * the starting name with potentially mixed case.
   *
   * @param  id     the name of the symbol who has the method.
   * @param  method information about the method to be named.
   * @return the name of the function to be used in the FORTRAN stub.
   */
  public static String getMethodSuperName(SymbolID id, 
                                          Method method,
                                          NameMangler mang,
                                          Context context)
    throws CodeGenerationException
  {
    
    try {
      return mang.shortName(id.getFullName(),
                            "super_" + method.getLongMethodName(),
                            getMethodSuffix(context));
    }
    catch (java.io.UnsupportedEncodingException uee) {
      throw new CodeGenerationException(uee.getMessage());
    }
  }


  /**
   * Return the appropriate version of Fortran (i.e., 77 or 90).
   *
   * @return the version of Fortran being generated
   */
  public static int getFortranVersion(Context context) {
    int fversion;
    if (isFortran90(context) || hasBindC(context)) {
      fversion = CodeConstants.C_F90_VERSION;
    } else {
      fversion = CodeConstants.C_F77_VERSION;
    }
    return fversion;
  }

  /**
   * Return the appropriate FORTRAN method name suffix based on the version.
   *
   * @return the FORTRAN method name suffix.
   */
  public static String getMethodSuffix(Context context) {
    if (isFortran90(context) || hasBindC(context)) {
      return CodeConstants.C_F90_METHOD_SUFFIX;
    } else {
      return CodeConstants.C_F77_METHOD_SUFFIX;
    }
  }

  /**
   * Return the appropriate FORTRAN alternative stub name.
   *
   * @return the FORTRAN method name suffix.
   */
  public static String getAltSuffix() {
    return CodeConstants.C_F90_ALT_SUFFIX;
  }

  /**
   * Return the appropriate FORTRAN impl method name suffix based.
   *
   * @return the FORTRAN impl method name suffix.
   */
  public static String getImplMethodSuffix(Context context) {
    if (isFortran90(context) || hasBindC(context)) {
      return CodeConstants.C_F90_IMPL_METHOD_SUFFIX;
    } else {
      return CodeConstants.C_F77_IMPL_METHOD_SUFFIX;
    }
  }

  /**
   * Return the appropriate version of SIDLFortran##Symbol.
   *
   * @return the appropriate version of SIDLFortran##Symbol.
   */
  public static String getFortranSymbol(Context context) {
    return "SIDLFortran" + getFortranVersion(context) + "Symbol";
  }

  /**
   * Generate the name of the array destructor function.
   */
  public static String getArrayDestructor(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_deleteRef" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array constructor function.
   */
  public static String getArrayConstructor(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_createRow" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array set element function.
   */
  public static String getArraySet(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_set" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array set element function.
   */
  public static String getArraySet(SymbolID id, int numArgs, Context context)
  {
    return getSymbolName(id) + "__array_set" +
      Integer.toString(numArgs) + getMethodSuffix(context);
  }

  /**
   * Generate the name of the array get element function.
   */
  public static String getArrayGet(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_get" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array get element function.
   */
  public static String getArrayGet(SymbolID id, int numArgs,
                                   Context context) {
    return getSymbolName(id) + "__array_get" +
      Integer.toString(numArgs) + getMethodSuffix(context);
  }

  /**
   * Generate the name of the array dimension access function.
   */
  public static String getArrayDimen(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_dimen" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array lower bound access function.
   */
  public static String getArrayLower(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_lower" + 
      getMethodSuffix(context);
  }

  /**
   * Generate the name of the array upper bound access function.
   */
  public static String getArrayUpper(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_upper" + getMethodSuffix(context);
  }

  /**
   * Generate the name of the array length access function.
   */
  public static String getArrayLength(SymbolID id, Context context) {
    return getSymbolName(id) + "__array_length" + getMethodSuffix(context);
  }

  /**
   * Return the function name that should be used for the FORTRAN subroutine
   * that implements a particular method.  The returned string leaves
   * the cast of the components of the name unchanged.  If <code>id</code>
   * and the method name have mixed case, this method returns a mixed case
   * string.
   *
   * @param  id     the name of the symbol who has the method.
   * @param  method the information about the method.
   * @param  mang   the name mangler being used to address long names.
   * @return the name of the FORTRAN subroutine that implements this method.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    the name mangler is broken.
   */
  public static String getMethodImplName(SymbolID id,
                                         Method method,
                                         NameMangler mang,
                                         Context context)
    throws CodeGenerationException
  {
    try {
      return mang.shortName(id.getFullName(), 
                            method.getLongMethodName(),
                            getImplMethodSuffix(context));
    }
    catch (java.io.UnsupportedEncodingException uee) {
      throw new CodeGenerationException(uee.getMessage());
    }
  }

  /**
   * Return the extended function name (i.e., one with the full name
   * prepended).
   *
   * @param  id       the name of the symbol who has the method.
   * @param  baseName the base method name.
   *
   * @return the name of the FORTRAN subroutine that implements this method.
   */
  public static String getExtendedMethodName(SymbolID id, String baseName)
  {
    return id.getFullName().replace('.','_') + "__" + baseName;
  }

  /**
   * Return the function name that should be used for the FORTRAN subroutine
   * that implements a particular SUPER method.  The returned string leaves
   * the cast of the components of the name unchanged.  If <code>id</code>
   * and the method name have mixed case, this method returns a mixed case
   * string.
   *
   * @param  id     the name of the symbol who has the method.
   * @param  method the information about the method.
   * @param  mang   the name mangler being used to address long names.
   * @return the name of the FORTRAN subroutine that implements this method.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    the name mangler is broken.
   */
  public static String getMethodSuperImplName(SymbolID id,
                                         Method method,
                                         NameMangler mang,
                                              Context context)
    throws CodeGenerationException
  {
    try {
      return mang.shortName(id.getFullName(), 
                            "super_"+method.getLongMethodName(),
                            getImplMethodSuffix(context));
    }
    catch (java.io.UnsupportedEncodingException uee) {
      throw new CodeGenerationException(uee.getMessage());
    }
  }

  /**
   * Return the C function name that should be used for the skeleton
   * method.  This is a C function that is called by the IOR.
   *
   * @param  id     the name of the symbol who has the method
   * @param  method information about the method.
   * @return the name of the C skeleton function.
   */
  public static String getMethodSkelName(SymbolID id, Method method) {
    return "skel_" + method.getLongMethodName();
  }

  /**
   * Return the C type corresponding to the FORTRAN type corresponding to
   * a particular sidl type.  This is the type that a C subroutine would
   * need to pass to FORTRAN, or the type that a C subroutine could expect
   * to receive from a FORTRAN caller.
   *
   * @param type  the sidl type description.
   * @return the C type corresponding to the FORTRAN type corresponding
   *         to the sidl type.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    the type is unsupported.
   */
  public static String getFortranTypeInC(Type type, Context context)
    throws CodeGenerationException
  {
    final int t = type.getDetailedType();
    if (t >= 0 && t < s_cTypeMatchingFortran.length) {
      if (isFortran90(context) || hasBindC(context)) {
        if (t == s_Fortran_Bool) return s_F90_Bool;
        if (t == Type.ARRAY) return s_F90_Array;
      }
      return s_cTypeMatchingFortran[t];
    }
    throw new CodeGenerationException("Unknown supported " + t);
  }

  /**
   * Return the sidl Fortran prefix for macros and types.
   *
   * @return the sidl Fortran prefix
   */
  public static String getFortranPrefix(Context context) {
    return "SIDL_F" + getFortranVersion(context);
  }

  public static boolean needsAbbrev(Context context)
  {
    return ! "f77".
      equals(context.getConfig().getTargetLanguage());
  }

  public static boolean isFortran90(Context context)
  {
    return "f90".equals(context.getConfig().getTargetLanguage());
  }

  public static boolean hasBindC(Context context)
  {
    return "f03".equals(context.getConfig().getTargetLanguage());
  
  }

  public static boolean isFortran7731(Context context)
  {
    return "f77_31".equals(context.getConfig().getTargetLanguage());
  }

  public static String arrayIOR(Context context)
  {
    return (isFortran90(context) || hasBindC(context)) ? ".d_ior" : "";
  }

  public static Method createCast(Context context,
                                  SymbolID id)
  {
    Method m = new Method(context);
    m.setMethodName("_cast");
    m.setDefinitionModifier(Method.STATIC);
    String[] s = new String[1];
    s[0] = "Cast method for interface and type conversions.";
    m.setComment(new Comment(s));
    m.setReturnType(new Type(id, context));
    Argument a = new
      Argument(Argument.IN, new Type(Type.OPAQUE), "ref");
    m.addArgument(a);
    m.addThrows(IOR.getRuntimeException(context));
    return m;
  }

  public static  Method createCastTwo(Context context, SymbolID id)
    throws CodeGenerationException
  {
    Method m = IOR.getBuiltinMethod(IOR.CAST, id, context).cloneMethod();
    m.setMethodName("_cast2");
    return m;
  }

  /**
   * Return the FORTRAN type declaration corresponding to <code>type</code>,
   * a particular sidl type.
   *
   * @param  type  a sidl type description.
   * @return the FORTRAN type used to some something of the given sidl
   * type.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    the type is unsupported.
   */
  public static String getReturnString(Type type,
                                       Context context)
    throws CodeGenerationException
  {
    final int t = type.getDetailedType();
    if (isFortran90(context)) {
      if (t >= 0 && t < s_f90_types.length) {
        return s_f90_types[t];
      } else {
        switch(t) {
        case Type.INTERFACE:
        case Type.CLASS:
          return "type(" + getTypeName(type.getSymbolID()) + ")";
        case Type.ARRAY:
          Type arrayType = type.getArrayType();
          if (null != arrayType) {
            if (type.isRarray()) {
              return getReturnString(arrayType, context);
            }
            else{
              if (arrayType.getDetailedType() <= Type.STRING) {
                return "type(" +
                  getArrayName(new SymbolID("sidl." + arrayType.getTypeString(),
                                            new Version()),
                               type.getArrayDimension()) + ")";
              }
              else {
                return "type(" + getArrayName(arrayType.getSymbolID(),
                                              type.getArrayDimension()) + ")";
              }
            }
          }
          else {
            return "type(sidl__array)";
          }
        default:
          throw new CodeGenerationException("Unknown supported " + t);
        }
      }
    } else if (hasBindC(context)) {
      if (t >= 0 && t < s_f03_types.length) {
        return s_f03_types[t];
      } else {
        switch(t) {
        case Type.INTERFACE:
        case Type.STRUCT:
          return "type(" + getTypeName(type.getSymbolID()) + ")";
        case Type.CLASS:
          return "type(" + getTypeName(type.getSymbolID()) + ")";
        case Type.ARRAY:
          Type arrayType = type.getArrayType();
          if (null != arrayType) {
            if (type.isRarray()) {
              return getReturnString(arrayType, context);
            }
            else{
              if (arrayType.getDetailedType() <= Type.STRING) {
                return "type(" +
                  getArrayName(new SymbolID("sidl." + arrayType.getTypeString(),
                                            new Version()),
                               type.getArrayDimension()) + ")";
              }
              else {
                return "type(" + getArrayName(arrayType.getSymbolID(),
                                              type.getArrayDimension()) + ")";
              }
            }
          }
          else {
            return "type(sidl__array)";
          }
        default:
          throw new CodeGenerationException("Unknown supported " + t);
        }
      }
    } else {
      if (t >= 0 && t < s_f77_types.length) {
        return s_f77_types[t];
      }
      else if (type.isArray()) {
        return type.isRarray() ? getReturnString(type.getArrayType(), context) 
          : "integer*8";
      }
      throw new CodeGenerationException("Unknown supported " + t);
    }
  }


  /**
   * Generates include directives for all the Babel clases used in this 
   * fortran stub or skel
   * 
   * @param writer Language writer for C
   * @param ext Extendible (Class or Interface) to generate dependencies
    */
  public static Set generateStubIncludes( LanguageWriterForC writer,
                                            Extendable ext) 
    throws CodeGenerationException 
  {
    Set includes = new HashSet();
    includes.addAll(Utilities.sort(ext.getObjectDependencies()));
   
    /*    ArrayList dependencies = Utilities.sort(cls.getObjectDependencies());
          for (Iterator i = dependencies.iterator(); i.hasNext(); ) {
          
          
          for( Iterator i = ext.getMethods(true).iterator(); i.hasNext(); ) { 
      Method method = (Method) i.next();
      Set argTypes = method.getSymbolReferences();
      //includes.addAll(method.getSymbolReferences());
      for(Iterator j = argTypes.iterator(); j.hasNext();) {
        SymbolID argID = (SymbolID) j.next();
        Symbol symbol = (Symbol) Utilities.lookupSymbol(argID);
        if(symbol.getSymbolType() == Type.CLASS ||
           symbol.getSymbolType() == Type.INTERFACE)
          includes.add(argID);
      }
    }
    */
    
    if (!includes.isEmpty()){
      writer.writeComment("Includes for all method dependencies.",false);
      
      List entries = Utilities.sort(includes);
      
      for (Iterator i = entries.iterator(); i.hasNext(); ) { 
        String header = Fortran.getHeaderFile( (SymbolID) i.next());

        writer.generateInclude( header, true );
      }
    } 
    return includes;
  } 
  
    public static Method createRemoteMethod(Extendable ext, 
                                            Context context, 
                                            boolean isF90) {
    SymbolID id = ext.getSymbolID();
    Method ret = new Method(context);
    Argument url = new Argument(Argument.IN, new Type(Type.STRING), "url");
    Argument self = new Argument(Argument.OUT, new Type(id, context), "self");
    if(isF90) {
      ret.setMethodName("new","Remote");
    } else {
      ret.setMethodName("_create","Remote");
    }
    ret.setDefinitionModifier(Method.STATIC);
    ret.setReturnType(new Type(Type.VOID)); 
    ret.addThrows(context.getSymbolTable().lookupSymbol("sidl.rmi.NetworkException").getSymbolID());
    ret.addArgument(self);
    ret.addArgument(url);
    return ret;
  }

  public static Method connectRemoteMethod(Extendable ext, 
                                           Context context,
                                           boolean isF90) {
    SymbolID id = ext.getSymbolID();
    Method ret = new Method(context);
    Argument url = new Argument(Argument.IN, new Type(Type.STRING), "url");
    Argument self = new Argument(Argument.OUT, new Type(id, context), "self");
    if(isF90) {
      ret.setMethodName("rConnect");
    } else {
      ret.setMethodName("_connect");
    }
    ret.setDefinitionModifier(Method.STATIC);
    ret.addThrows(context.getSymbolTable().lookupSymbol("sidl.rmi.NetworkException").getSymbolID());
    ret.addArgument(self);
    ret.setReturnType(new Type(Type.VOID)); 
    ret.addArgument(url);
    return ret;
  }
  
}
