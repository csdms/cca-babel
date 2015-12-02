//
// File:        ArrayModule.java
// Package:     gov.llnl.babel.backend.fortran
// Copyright:   (c) 2003 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6521 $
// Date:        $Date: 2008-09-17 16:21:01 -0700 (Wed, 17 Sep 2008) $
// Description: Create a F90 module to provide stubs for arrays
// 
// Copyright (c) 2003, Lawrence Livermore National Security, LLC
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
import gov.llnl.babel.backend.fortran.AbbrevHeader;
import gov.llnl.babel.backend.mangler.FortranMangler;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.io.UnsupportedEncodingException;
import java.security.NoSuchAlgorithmException;
import java.util.TreeMap;

/**
 * Create a FORTRAN 90 module to provide client-side bindings for arrays of 
 * classes and interfaces.
 */
public class ArrayModule {
  private final static int GENERIC = -1;
  private final static int BASETYPE = 0;
  private final static int BASEINTERFACE = 1;
  private final static int USERDEFINED = 2;

  static private final int s_maxArray = BabelConfiguration.getMaximumArray();

  private NameMangler d_mang;

  private LanguageWriterForFortran d_lw;
  
  private SymbolID d_id;

  private String d_privateSuffix = "_p";

  private String d_intType;
  
  private boolean d_access;

  private Context d_context;

  private boolean d_borrow;

  private boolean d_is_base_type;

  private boolean d_is_generic_array;

  private int d_type;
  private int d_casttype;

  private static final String[] s_constant_methods = {
    "copy",
    "createCol",
    "createRow",
    "ensure",
    "addRef",
    "deleteRef",
    "dimen",
    "isColumnOrder",
    "isRowOrder",
    "is_null",
    "lower",
    "not_null",
    "set_null",
    "smartCopy",
    "stride",
    "upper",
    "length"
  };

  private static final String[] s_generic_methods = {
    "addRef",
    "deleteRef",
    "dimen",
    "type",
    "isColumnOrder",
    "isRowOrder",
    "is_null",
    "lower",
    "not_null",
    "set_null",
    "smartCopy",
    "stride",
    "upper",
    "length"
  };


  /**
   * The name of the type use to hold values going in/out.
   */
  private String d_implDataType;

  private SymbolID d_implID;

  private String getImplArrayType(int dim)
  {
    return "type(" + Fortran.getArrayName(d_id, dim) + ")";
  }

  private String getPrivateName(String name, int dim)
  {
    if(dim == 0) {
      return name + d_privateSuffix;
    }
    return name + dim + d_privateSuffix;
  }

  /**
   * The function returns an int that determines what sort of cast functions
   * should be written out.  There are 3 possibilities:
   * if d_is_base_type is true, we need to be able to cast to and from
   * generic arrays.
   * if this is a base interface, we also need to be able to cast to and
   * from generic arrays
   * However, if niether of those are true, we should only be able cast to
   * generic arrays, not from them.
   */
  private int castType() {
    if(d_is_base_type)
      return BASETYPE;
    else if (d_id.getFullName().compareTo(BabelConfiguration.getBaseInterface()) == 0)
      return BASEINTERFACE;
    else
      return USERDEFINED;
  }

  private void initImplID(int type)
    throws CodeGenerationException
  {
    d_access = true;
    d_borrow = true;
    d_is_generic_array = false;
    switch (type) {
    case Type.VOID:
      throw new CodeGenerationException("Cannot create an array for a void");
    case Type.CLASS:
    case Type.SYMBOL:
    case Type.INTERFACE:
      d_access = false;
      d_borrow = false;
      d_is_base_type = false;
      d_implID = d_id;
      break;
    case Type.ENUM:
      d_is_base_type = false;
      d_access = false;
      d_borrow = false;
      d_implID = new SymbolID("sidl.long", new Version());
      break;
    case Type.CHAR:
    case Type.OPAQUE:
    case Type.STRING:
    case Type.BOOLEAN:
      d_access = false;
      d_borrow = false;
      // fall through intended!
    default:
      d_is_base_type = true;
      d_implID = new SymbolID("sidl." + (new Type(type)).getTypeString(),
                              new Version());
      break;
    }
  }
    
  /**
   * Create an object to create a FORTRAN 90 module to provide
   * client-side bindings for arrays of classes, interfaces, and
   * enumerated types.
   *
   * @param id    the array module should be created for this
   *              id. This can be a real id or a fake id (for
   *              sidl.double and the like).
   * @param type  this should be a constant from 
   *              {@link gov.llnl.babel.symbols.Type}. It indicates
   *              the type of id.
   * @param lw    here is where the file is created.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  this means the arguments were incorrect
   */
  public ArrayModule(SymbolID id,
                     int      type,
                     LanguageWriterForFortran lw,
                     Context context)
    throws CodeGenerationException
  {
    try {
      d_id = id;
      d_lw = lw;
      d_type = type;
      d_context = context;
      d_mang = new FortranMangler(AbbrevHeader.MAXNAME,
                                  AbbrevHeader.MAXUNMANGLED);
      if (type <= Type.STRING) {
        d_implDataType = Fortran.getReturnString(new Type(type), d_context);
      }
      else {
        d_implDataType = Fortran.getReturnString(new Type(id, d_context), 
                                                 d_context);
      }
      d_intType = Fortran.getReturnString(new Type(Type.INT), d_context);
      initImplID(type);
      d_casttype = castType();
    }
    catch (NoSuchAlgorithmException nsae) {
      throw new CodeGenerationException(nsae.getMessage());
    }
  }

    
  /**
   * SPECIAL CONSTRUCTOR for creating the GENERIC ARRAY MODULE.
   * DO NOT CALL FOR ANY OTHER REASON!
   *
   * @param lw    here is where the file is created.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  this means the arguments were incorrect
   */
  public ArrayModule(LanguageWriterForFortran lw,
                     Context context)
    throws CodeGenerationException
  {
    try {
      d_context = context;
      d_id = new SymbolID("sidl.array", new Version());
      d_lw = lw;
      d_type = -1;
      d_mang = new FortranMangler(AbbrevHeader.MAXNAME,
                                  AbbrevHeader.MAXUNMANGLED);
      d_implDataType = null;
      d_intType = Fortran.getReturnString(new Type(Type.INT), d_context);
      // Instead of calling initImplID(type), we do this directly.
      d_access = false;
      d_borrow = false;
      d_is_base_type = false;
      d_is_generic_array = true;
      d_implID = new SymbolID("sidl", new Version());
      d_casttype = GENERIC;
    }
    catch (NoSuchAlgorithmException nsae) {
      throw new CodeGenerationException(nsae.getMessage());
    }
  }

  private void generateIsNull(int dim)
  {
    d_lw.println("logical function " + getPrivateName("is_null", dim) +
                 "(array)");
    d_lw.tab();
    if (Fortran.hasBindC(d_context)) {
      d_lw.println("use,intrinsic :: iso_c_binding");
      d_lw.println("use :: sidl");
    }
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: array");
    if (Fortran.hasBindC(d_context)) {
      d_lw.println(getPrivateName("is_null", dim) +
                 " = (.not. c_associated(array%d_array))");
    } else {
      d_lw.println(getPrivateName("is_null", dim) +
                 " = (array%d_array .eq. 0)");
    }
    d_lw.backTab();
    d_lw.println("end function " + getPrivateName("is_null", dim));
    d_lw.println();
  }

  private void generateNotNull(int dim)
  {
    d_lw.println("logical function " + getPrivateName("not_null", dim) +
                 "(array)");
    d_lw.tab();
    if (Fortran.hasBindC(d_context)) {
      d_lw.println("use,intrinsic :: iso_c_binding");
      d_lw.println("use :: sidl");
    }
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: array");
    if (Fortran.hasBindC(d_context)) {
      d_lw.println(getPrivateName("not_null", dim) +
                 " = c_associated(array%d_array)");
    } else {
      d_lw.println(getPrivateName("not_null", dim) +
                 " = (array%d_array .ne. 0)");
    }
    d_lw.backTab();
    d_lw.println("end function " + getPrivateName("not_null", dim));
    d_lw.println();
  }

  private void generateSetNull(int dim)
  {
    d_lw.println("subroutine " + getPrivateName("set_null", dim) +
                 "(array)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(out) :: array");
    if (Fortran.hasBindC(d_context)) {
      d_lw.println("array%d_array=C_NULL_PTR");
    } else {
      d_lw.println("array%d_array = 0");
    }
    if (d_access) {
      d_lw.println("nullify(array%d_data)");
    }
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName("set_null", dim));
    d_lw.println();
  }

  private void generateNullRelated(int dim)
  {
    generateIsNull(dim);
    generateNotNull(dim);
    generateSetNull(dim);
  }

  private void generateCreate(String type, int dim)
    throws UnsupportedEncodingException
  {
    final String createFunc = "create" + type;
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), createFunc, "_m");
    d_lw.beginBlockComment(false);
    d_lw.println("The size of lower determines the dimension of the");
    d_lw.println("array.");
    d_lw.endBlockComment(false);
    d_lw.println("subroutine " + getPrivateName(createFunc, dim) +
                 "(lower, upper, array)");
    d_lw.tab();
    d_lw.println(d_intType + ", dimension(" + dim + "), intent(in) :: lower");
    d_lw.println(d_intType +
                 ", dimension(" + dim + "), intent(in) :: upper");
    d_lw.println(getImplArrayType(dim) + ", intent(out) :: array");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(" + dim + ", lower, upper, array)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(createFunc, dim));
    d_lw.println();
  }

  private void generateCreate1d()
    throws UnsupportedEncodingException
  {
    final String createFunc = "create1d";
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), createFunc, "_m");
    d_lw.println("subroutine " + getPrivateName(createFunc, 1) +
                 "(len, array)");
    d_lw.tab();
    d_lw.println(d_intType + ", intent(in) :: len");
    d_lw.println(getImplArrayType(1) + ", intent(out) :: array");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(len, array)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(createFunc, 1));
    d_lw.println();
  }
  
  private void generateCreate2d(String type)
    throws UnsupportedEncodingException
  {
    final String createFunc = "create2d" + type;
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), createFunc, "_m");
    d_lw.println("subroutine " + getPrivateName(createFunc, 2) +
                 "(m, n, array)");
    d_lw.tab();
    d_lw.println(d_intType + ", intent(in) :: m, n");
    d_lw.println(getImplArrayType(2) + ", intent(out) :: array");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(m, n, array)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(createFunc, 2));
    d_lw.println();
  }
  

  private void generateCreates(int dim)
    throws UnsupportedEncodingException
  {
    generateCreate("Col", dim);
    generateCreate("Row", dim);
    if (dim == 1) generateCreate1d();
    if (dim == 2) {
      generateCreate2d("Col");
      generateCreate2d("Row");
    }
  }

  private void generateCopy(String func, int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println("subroutine " + getPrivateName(func, dim) +
                 "(src, dest)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: src");
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: dest");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(src, dest)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateSmartCopy(String func, int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println("subroutine " + getPrivateName(func, dim) +
                 "(src, dest)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: src");
    d_lw.println(getImplArrayType(dim) + ", intent(out) :: dest");
    d_lw.println("integer(sidl_int) :: dim");
    d_lw.println("external " + function);
    d_lw.println("dim = " + dim);
    d_lw.println("call " + function + "(src, " + dim +", dest)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateEnsure(int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), "ensure", "_m");
    d_lw.println("subroutine " + getPrivateName("ensure", dim) +
                 "(src, dim, ordering, result)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: src");
    d_lw.println(getImplArrayType(dim) + ", intent(out) :: result");
    d_lw.println(d_intType + ", intent(in) :: dim, ordering");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(src, " + dim + ", ordering, result)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName("ensure", dim));
    d_lw.println();
  }

  private void generateSlice(int dim)
    throws UnsupportedEncodingException
  {
    for(int j = 1; j <= dim; ++j) {
      final String function = d_mang.shortArrayName
        (d_implID.getFullName(), "slice", "_m");
      d_lw.println("subroutine " + getPrivateName("slice" + j, dim) +
                   "(src, numElem, srcStart, srcStride, newLower, result)");
      d_lw.tab();
      d_lw.println(getImplArrayType(dim) + ", intent(in)  :: src");
      d_lw.println(d_intType + ", dimension(" + dim + "), intent(in) :: numElem");
      d_lw.println
        (d_intType + 
         ", dimension(" + dim + "), intent(in) :: srcStart, srcStride");
      d_lw.println(getImplArrayType(j) + ", intent(out) :: result");
      d_lw.println(d_intType + ", dimension(:), intent(in) :: newLower");
      d_lw.println("external " + function);
      d_lw.println("call " + function + 
                   "(src, " + j + ", numElem, srcStart, srcStride, newLower, result)");
      d_lw.backTab();
      d_lw.println("end subroutine " + getPrivateName("slice" + j, dim));
      d_lw.println();
    }
  }

  private void slicePrivateNames()
  {
    int i, j;
    for(i = 1; i <= s_maxArray; ++i) {
      for(j = 1; j <= i; ++j) {
        d_lw.print(getPrivateName("slice" + j, i));
        if ((i < s_maxArray) || (j < s_maxArray)) {
          d_lw.println(", &");
        }
      }
    }
    d_lw.println();
  }
  
  private void writeSliceInterface()
  {
    d_lw.println("private :: &");
    d_lw.tab();
    slicePrivateNames();
    d_lw.backTab();
    d_lw.println();
    d_lw.println("interface slice");
    d_lw.tab();
    d_lw.println("module procedure &");
    d_lw.tab();
    slicePrivateNames();
    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void generateQuery(String func, String returnType, int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println(returnType + " function  " + getPrivateName(func, dim) +
                 "(array)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array, " + getPrivateName(func, dim) + ")");
    d_lw.backTab();
    d_lw.println("end function " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateCasts()
    throws UnsupportedEncodingException
  {
    //Actually, this should never be called on a generic array at all.
    //Double check
    if(d_casttype >= BASETYPE) {
      //Functions that cast TO a generic array
      for(int dim = 1; dim <= s_maxArray; ++dim) {
        generateCastToGeneric(d_type, dim); 
      }      
      d_lw.println();

      //USER Defined class array cannot be cast to from a generic array.
      if(d_casttype != USERDEFINED) {
        //Functions that cast FROM a generic array
        for(int dim = 1; dim <= s_maxArray; ++dim) {
          generateCastFromGeneric(d_type, dim);
        }
        d_lw.println();
      }
    }
    // If we're using the F2003 BindC module, convert from c_ptr to a sidl array
    // for all arrays EXCEPT interface arrays
    if (d_id.isSymbolBindC() && Fortran.hasBindC(d_context)){
        for(int dim = 1; dim <= s_maxArray; ++dim) {
          generateCastFromPtr(d_type, dim);
        }
        d_lw.println();
    }
  }

  private void generateCastFromPtr(int type, int dim)
    throws UnsupportedEncodingException
  {
    String typeString = null;
    typeString = "CptrTosidl_"+BabelConfiguration.arrayType(d_type);
    
    String funcname = d_mang.shortName("cast" + typeString + dim+"d",d_privateSuffix);

    final String function = d_mang.shortName
      ("sidl_"+BabelConfiguration.arrayType(d_type)+"__array_vcast", "_m");

    String newTypeName = typeString+"_"+dim+"d";

    d_lw.println("subroutine " + funcname + "(oldType, newType)");
    d_lw.tab();
    d_lw.println("use,intrinsic :: iso_c_binding");
    d_lw.println("type(c_ptr), intent(in) :: oldType");
    d_lw.println("type(sidl_"+BabelConfiguration.arrayType(d_type)+"_"+dim+"d), intent(out) :: newType");
    d_lw.println("external " + function);
    d_lw.println("call "+function+"(oldType,"+dim+",newType)");

    d_lw.backTab();
    d_lw.println("end subroutine " + funcname);  
    d_lw.println();
  }

  //Doesn't exist for non-base types! (except BaseInterface)
  private void generateCastFromGeneric(int type, int dim)
    throws UnsupportedEncodingException
  {
    String typeString = "sidl_"+BabelConfiguration.arrayType(d_type);
    String funcname = d_mang.shortName("castGenericTo"+typeString+dim+"d",d_privateSuffix);
    String oldTypeName = typeString+"_"+dim+"d";
    String extfunc = d_mang.shortArrayName(typeString, "cast", "_m");  

    d_lw.println("subroutine " + funcname + "(oldType, newType)");
    d_lw.tab();    
    d_lw.println("type(sidl__array), intent(in) :: oldType");
    d_lw.println("type("+oldTypeName+"), intent(out) :: newType");
    

    //There is no BaseInterface array cast, so do that manually
    if(d_casttype == BASEINTERFACE) {
      d_lw.println("if(sidl__array_dimen_m(oldType%d_array) .ne. "+dim+" .or. sidl__array_type_m(oldType%d_array) .ne. "+type+") then");
      d_lw.tab();
    if (Fortran.hasBindC(d_context)){
        d_lw.println("newType%d_array=C_NULL_PTR");
      } else {
        d_lw.println("newType%d_array=0");
      }
      d_lw.backTab();
      d_lw.println("else");
      d_lw.tab();
      d_lw.println("newType%d_array = oldType%d_array");
      d_lw.backTab();
      d_lw.println("end if"); 
    } else { //A Base type (int, bool, etc.) has a cast function, use it.
      d_lw.println("external " + extfunc);
      d_lw.println("call " + extfunc + "(oldType%d_array, "+dim+", newType)");
    }

    d_lw.backTab();
    d_lw.println("end subroutine " + funcname);
    d_lw.println();

  }

  private void generateCastToGeneric(int type, int dim)
    throws UnsupportedEncodingException
  {
    String typeString = null;
    if(d_casttype == USERDEFINED)  //Not a base type or sidl.BaseInterface
      typeString = d_id.getFullName().replace('.','_');
    else
      typeString = "sidl_"+BabelConfiguration.arrayType(d_type);
    
    String funcname = d_mang.shortName("cast" + typeString + dim+"dToGeneric", d_privateSuffix);
    String newTypeName = typeString+"_"+dim+"d";

    d_lw.println("subroutine " + funcname + "(oldType, newType)");
    d_lw.tab();
    d_lw.println("type(sidl__array), intent(out) :: newType");
    d_lw.println("type("+newTypeName+"), intent(in) :: oldType");

    //Anything can get cast to a generic array.  That's no big deal.
    d_lw.println("newType%d_array = oldType%d_array");
    
    d_lw.backTab();
    d_lw.println("end subroutine " + funcname);  
    d_lw.println();
  }

  private void generateOrderingTests(int dim)
    throws UnsupportedEncodingException
  {
    generateQuery("isColumnOrder", "logical", dim);
    generateQuery("isRowOrder", "logical", dim);
  }

  private void generateIndexedQuery(String func, int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println(d_intType + " function  " + getPrivateName(func,dim) +
                 "(array, index)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    d_lw.println(d_intType + ", intent(in) :: index");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array, index, " + getPrivateName(func, dim) + ")");
    d_lw.backTab();
    d_lw.println("end function " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateSizeQueries(int dim)
    throws UnsupportedEncodingException
  {
    generateQuery("dimen", d_intType, dim);
    generateIndexedQuery("stride", dim);
    generateIndexedQuery("lower", dim);
    generateIndexedQuery("upper", dim);
    generateIndexedQuery("length", dim);
  }

  private void generateGenericGet(int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), "get", "_m");
    d_lw.println("subroutine " + getPrivateName("getg", dim) +
                 "(array, index, value)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    d_lw.println(d_intType + ", intent(in), dimension(" + dim + ") :: index");
    d_lw.println(d_implDataType + ", intent(out) :: value");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array, index, value)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName("getg", dim));
    d_lw.println();
  }

  private void generateGet(int dim)
    throws UnsupportedEncodingException
  {
    final String func = "get";
    int i;
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func + dim, "_m");
    d_lw.println("subroutine " + getPrivateName(func, dim) +
                 "(array, &");
    d_lw.tab();
    d_lw.tab();
    for(i = 1; i <= dim; ++i){
      d_lw.println("i" + i + ", &");
    }
    d_lw.println("value)");
    d_lw.backTab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    for(i = 1; i <= dim; ++i) {
      d_lw.println(d_intType + ", intent(in) :: i" + i);
    }
    d_lw.println(d_implDataType + ", intent(out) :: value");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(array, &");
    d_lw.tab();
    for(i = 1; i <= dim; ++i) {
      d_lw.println("i" + i + ", &");
    }
    d_lw.println("value)");
    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func,dim));
    d_lw.println();
  }

  private void generateGenericSet(int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), "set", "_m");
    d_lw.println("subroutine " + getPrivateName("setg", dim) +
                 "(array, index, value)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    d_lw.println(d_intType + ", intent(in), dimension(" + dim +
                 ") :: index");
    d_lw.println(d_implDataType + ", intent(in) :: value");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array, index, value)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName("setg",dim));
    d_lw.println();
  }

  private void generateSet(int dim)
    throws UnsupportedEncodingException
  {
    final String func = "set";
    int i;
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func + dim, "_m");
    d_lw.println("subroutine " + getPrivateName(func, dim)+
                 "(array, &");
    d_lw.tab();
    d_lw.tab();
    for(i = 1; i <= dim; ++i){
      d_lw.println("i" + i + ", &");
    }
    d_lw.println("value)");
    d_lw.backTab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    for(i = 1; i <= dim; ++i) {
      d_lw.println(d_intType + ", intent(in) :: i" + i);
    }
    d_lw.println(d_implDataType + ", intent(in) :: value");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array, &");
    d_lw.tab();
    for(i = 1; i <= dim; ++i) {
      d_lw.println("i" + i + ", &");
    }
    d_lw.println("value)");
    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateGetSet(int dim)
    throws UnsupportedEncodingException
  {
    generateGenericGet(dim);
    generateGenericSet(dim);
    generateGet(dim);
    generateSet(dim);
  }

  private void writePrivate(String method)
  {
    int i;
    d_lw.println("private :: &");
    d_lw.tab();
    if(d_is_generic_array) {
      d_lw.print(getPrivateName(method, 0));
    } else {
      d_lw.print(getPrivateName(method, 1));
      for(i = 2; i <= s_maxArray; ++i ){
        d_lw.println(", &");
        d_lw.print(getPrivateName(method, i));
      }
    }
    d_lw.println();
    d_lw.backTab();
    d_lw.println();
  }

  private void writeInterface(String method)
  {
    final String generic = method + "g";
    int i;
    writePrivate(generic);
    writePrivate(method);
    d_lw.println("interface " + method);
    d_lw.tab();
    d_lw.println("module procedure &");
    d_lw.tab();
    for(i = 1; i <= s_maxArray; ++i) {
      d_lw.println(getPrivateName(generic, i) + ", &");
      d_lw.print(getPrivateName(method, i));
      if (i < s_maxArray) {
        d_lw.println(", &");
      }
    }
    d_lw.backTab();
    d_lw.println();
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void writeSingleInterface(String func, int dim)
  {
    d_lw.println("private :: " + getPrivateName(func, dim));
    d_lw.println();
    d_lw.println("interface " + func);
    d_lw.tab();
    d_lw.println("module procedure " + getPrivateName(func, dim));
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void writeGenericCastInterfaces()
    throws UnsupportedEncodingException
  {
   
    String typeString = null;
    if(d_casttype == USERDEFINED)  //Not a base type or sidl.BaseInterface
      typeString = d_id.getFullName().replace('.','_');
    else
      typeString = "sidl_"+BabelConfiguration.arrayType(d_type);

    d_lw.println();
    d_lw.println("private :: &");
    d_lw.tab(); 
    //Functions that cast FROM a generic array 
    for(int dim = 1; dim <= s_maxArray; ++dim) {
      d_lw.print(d_mang.shortName("cast" + typeString +dim+"dToGeneric",
                                  d_privateSuffix));
      if(dim < s_maxArray) //So the last declaration doesn't end with a &
        d_lw.println(", &"); 
      else
        d_lw.println();
    }
    d_lw.backTab();
    
    if(d_casttype != USERDEFINED) {
      d_lw.println();
      d_lw.println("private :: &");
      d_lw.tab(); 
      //Functions that cast TO a generic array
      for(int dim = 1; dim <= s_maxArray; ++dim) {
        d_lw.print(d_mang.shortName("castGenericTo" + typeString+dim+"d",
                                    d_privateSuffix));
        if(dim < s_maxArray) //So the last declaration doesn't end with a &
          d_lw.println(", &"); 
        else
          d_lw.println();
      }
    }
    d_lw.backTab();
    //interface if F2003 BindC is used
    if (d_id.isSymbolBindC() && Fortran.hasBindC(d_context)) {
      d_lw.println();
      d_lw.println("private :: &");
      d_lw.tab(); 
      //Functions that cast TO a generic array
      for(int dim = 1; dim <= s_maxArray; ++dim) {
        d_lw.print(d_mang.shortName("castCptrTo" + typeString+dim+"d",
                                    d_privateSuffix));
        if(dim < s_maxArray) //So the last declaration doesn't end with a &
          d_lw.println(", &"); 
        else
          d_lw.println();
      }
    }
    d_lw.backTab();
    d_lw.println();

    //Interface declaration

    d_lw.println("interface cast");
    d_lw.tab();

    d_lw.println("module procedure &");
    d_lw.tab(); 
    //Functions that cast FROM a generic array
    for(int dim = 1; dim <= s_maxArray; ++dim) {
      d_lw.print(d_mang.shortName("cast" + typeString+dim+"dToGeneric",
                                  d_privateSuffix));
      if(dim < s_maxArray) //So the last declaration doesn't end with a &
        d_lw.println(", &"); 
      else
        d_lw.println(); 
    }

    
    if(d_casttype != USERDEFINED) {
      d_lw.backTab();
      d_lw.println("module procedure &");
      d_lw.tab();
      //Functions that cast TO a generic array
      for(int dim = 1; dim <= s_maxArray; ++dim) {
        d_lw.print(d_mang.shortName("castGenericTo" + typeString+dim+"d",
                                    d_privateSuffix));
        if(dim < s_maxArray) //So the last declaration doesn't end with a &
          d_lw.println(", &"); 
        else
          d_lw.println();
      }
    }

    //interface if F2003 BindC is used
    if (d_id.isSymbolBindC() && Fortran.hasBindC(d_context)){
      d_lw.backTab();
      d_lw.println("module procedure &");
      d_lw.tab();
      //Functions that cast TO a generic array
      for(int dim = 1; dim <= s_maxArray; ++dim) {
        d_lw.print(d_mang.shortName("castCptrTo" + typeString+dim+"d",
                                    d_privateSuffix));
        if(dim < s_maxArray) //So the last declaration doesn't end with a &
          d_lw.println(", &"); 
        else
          d_lw.println();
      }
    }

    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void writeGenericInterface(String func)
  {
    int i;
    writePrivate(func);
    d_lw.println("interface " + func);
    d_lw.tab();
    d_lw.println("module procedure &");
    d_lw.tab();
 
    if(d_is_generic_array) {
      d_lw.print(getPrivateName(func, 0));
    } else {
      d_lw.print(getPrivateName(func, 1));
      for(i = 2; i <= s_maxArray; ++i) {
        d_lw.println(", &");
        d_lw.print(getPrivateName(func, i));
      }
    }
    d_lw.println();
    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("end interface");
    d_lw.println();
  }

  private void generateAccess(int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), "access", "_m");
    d_lw.println("subroutine " + getPrivateName("access", dim) +
                 "(array, ref, low, up, str, index)");
    d_lw.tab();
    d_lw.println("implicit none");
    d_lw.println(getImplArrayType(dim) + ", intent(in) :: array");
    d_lw.println(d_implDataType + ", dimension(1), intent(in) :: ref");
    d_lw.println(d_intType + ", intent(out), dimension(:) :: low, up, str");
    d_lw.println(d_intType + ", intent(out) :: index");
    d_lw.println("external " + function);
    d_lw.println("call " + function +
                 "(array, ref, low, up, str, index)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName("access", dim));
  }

  private void generateBorrow(int dim, boolean common)
    throws UnsupportedEncodingException
  {
    final String func = (common ? "cborrow" : "borrow");
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println("subroutine " + getPrivateName(func, dim) +
                 "(first, low, up, astr, result)");
    d_lw.tab();
    d_lw.println(d_implDataType + ", intent(in) :: first");
    d_lw.println(d_intType + ", dimension(" + dim +"), intent(in) :: low, up, astr");
    d_lw.println(getImplArrayType(dim) + ", intent(out) :: result");
    d_lw.println("external " + function);
    d_lw.println("call " + function + "(first, " + dim + ", low, up, astr, result)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func, dim));
    d_lw.println();
  }


  private void generateDeclarations()
    throws UnsupportedEncodingException
  {
    int i;
    if (d_is_base_type) {
      TypeModule.writeArrayType(d_lw, d_id, 
                                (d_access ? d_implDataType : null),
                                d_context);
    }
    if(d_is_generic_array) {  //The methods available in generic arrays.
      for(i = 0; i < s_generic_methods.length ; ++i){
        writeGenericInterface(s_generic_methods[i]);
      }
 
    }else {

      for(i = 0; i < s_constant_methods.length ; ++i){
        writeGenericInterface(s_constant_methods[i]);
      }      
      writeSingleInterface("create1d",1);
      writeSingleInterface("create2dRow", 2);
      writeSingleInterface("create2dCol", 2);
      
      writeSliceInterface();
      writeInterface("get");
      writeInterface("set");
    
      writeGenericCastInterfaces();
      if (d_access) {
        writeGenericInterface("access");
      }
      if (d_borrow) {
        writeGenericInterface("borrow");
        writeGenericInterface("cborrow");
      }
    }
  }

  private void generateRef(String func, int dim)
    throws UnsupportedEncodingException
  {
    final String function = d_mang.shortArrayName
      (d_implID.getFullName(), func, "_m");
    d_lw.println("subroutine  " + getPrivateName(func, dim) +
                 "(array)");
    d_lw.tab();
    d_lw.println(getImplArrayType(dim) + ", intent(in)  :: array");
    d_lw.println("external " + function);
    d_lw.println("call " + function + 
                 "(array)");
    d_lw.backTab();
    d_lw.println("end subroutine " + getPrivateName(func, dim));
    d_lw.println();
  }

  private void generateRefCounting(int dim)
    throws UnsupportedEncodingException
  {
    generateRef("addRef", dim);
    generateRef("deleteRef", dim);
  }

  private void generateImplementations()
    throws UnsupportedEncodingException
  {
    if(d_is_generic_array) {
      generateSmartCopy("smartCopy", 0);
      generateOrderingTests(0);
      generateSizeQueries(0);
      generateQuery("type", d_intType, 0);
      generateRefCounting(0);
      generateNullRelated(0);

    } else {
      for(int i = 1; i <= s_maxArray; ++i) {
        generateCreates(i );
        generateCopy("copy", i);
        generateEnsure(i);
        generateSlice(i);
        generateGetSet(i);

        generateSmartCopy("smartCopy", i);
        generateOrderingTests(i);
        generateSizeQueries(i);
        generateRefCounting(i);
        generateNullRelated(i);
        if (d_access) {
          generateAccess(i);
        }
        if (d_borrow) {
          generateBorrow(i, false);
          generateBorrow(i, true);
        }
      }
      generateCasts();  //have their own interfal for loop
    }
  }
  
  public void generateStub()
    throws CodeGenerationException
  {
    try {
      d_lw.println();
      if (d_is_generic_array) {
        d_lw.generateInclude("sidl_array_fAbbrev.h");      
      }
      d_lw.println("module " + Fortran.getArrayModule(d_id));
      d_lw.tab();
      TreeMap emptyMap = new TreeMap();
      d_lw.generateUse("sidl", emptyMap);
      if (!d_is_generic_array) { 
        if (!d_is_base_type) {
          d_lw.generateUse(Fortran.getTypeModule(d_id), emptyMap);
        }
      }
      d_lw.generateUse("sidl_array_type", emptyMap); //Everyone needs the generic module!
      if (d_id.isSymbolBindC() && Fortran.hasBindC(d_context)){
        d_lw.println("use,intrinsic :: iso_c_binding");
      }

      d_lw.println();
      emptyMap = null;
      
      generateDeclarations();

      d_lw.println();
      d_lw.backTab();
      d_lw.println("contains");
      d_lw.tab();
      d_lw.println();
      d_lw.println();

      generateImplementations();
      d_lw.backTab();
      d_lw.println("end module " +  Fortran.getArrayModule(d_id));
    }
    catch (UnsupportedEncodingException uee) {
      throw new CodeGenerationException(uee.getMessage());
    }
  }
}
