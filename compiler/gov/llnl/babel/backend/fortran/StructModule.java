//
// File:        StructModule.java
// Package:     gov.llnl.babel.backend.fortran
// Copyright:   (c) 2003 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6171 $
// Date:        $Date: 2007-10-08 17:39:28 -0600 (Mon, 08 Oct 2007) $
// Description: Generate a module containing some derived types
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
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.fortran.Babel2BindCType;
import gov.llnl.babel.backend.fortran.Fortran;
import gov.llnl.babel.backend.fortran.ImplSource;
import gov.llnl.babel.backend.mangler.NameMangler;
import gov.llnl.babel.backend.mangler.NonMangler;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.AssertionExpression;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Struct;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolTable;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.io.UnsupportedEncodingException;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.TreeMap;
/**
 * This class provides the ability to write a BIND(C) module file
 * containing the derived type defined in the SIDL file.
 */
public class StructModule
{
  private Babel2BindCType d_bbc;

  private LanguageWriterForFortran d_lw;

  private NameMangler d_mang;

  private Struct d_struct;

  private Context d_context;

  private SymbolID d_id;


  /**
   * When Struct Module use cases are being generated, we need to keep track of 
   * what use cases have been already generated.
   */
  private static HashSet useWritten = null;

  public StructModule(LanguageWriterForFortran writer,
                    CodeSplicer              splicer,
                    Struct                   strct,
                      Context                context)
    throws NoSuchAlgorithmException
  {
    d_context = context;
    d_mang = new NonMangler();
    d_bbc = new Babel2BindCType();
    d_lw = writer;
    d_struct = strct;
    d_id = strct.getSymbolID();
  }

  public void generateCode()
    throws CodeGenerationException
  {
    SymbolID bi_id = d_context.getSymbolTable().
      lookupSymbol(BabelConfiguration.getBaseInterface()).getSymbolID();

    useWritten = new HashSet();

    String name = d_struct.getFullName();
    d_lw.writeBanner(d_struct, Fortran.getImplModuleFile(d_id, d_context), 
                     true,
                     CodeConstants.C_FORTRAN_IMPL_MODULE_PREFIX + 
                     d_id.getFullName());
    d_lw.generateInclude( Fortran.getStubNameFile(bi_id) );
    d_lw.generateInclude( Fortran.getStubNameFile(d_id));
    d_lw.println();
    d_lw.println();
    try {
      d_lw.println("module " + 
                   d_mang.shortName(name, ""));
      d_lw.tab();
      
      d_lw.println("use,intrinsic :: iso_c_binding");

      /* generate use statements for different array types */
      /* put in a case statement -spm */
      boolean check=false;
      for(Iterator i = d_struct.getItems().iterator(); i.hasNext(); ) { 
        Struct.Item e = (Struct.Item) i.next();
        Type t = e.getType();
        int type = t.getDetailedType();
        if (type==Type.ARRAY){
          final Type aType = t.getArrayType();
          if (aType.isPrimitive()){
            if(!useWritten.contains(aType.getTypeName())) {
              d_lw.println("use sidl_"+aType.getTypeName()+"_array");
              useWritten.add(aType.getTypeName());
            }
          }
        }
      /* generate use statements for structs that themselves contain struct members */
        if (type==Type.STRUCT){
          check=true;
          SymbolID idTest=t.getSymbolID();
          d_lw.generateUse(Fortran.getModule(idTest), new TreeMap());
        }
      }

      /* Put the dummy DIM in the module.  If an r-array requires it the
       * declaration is hidden from the user, otherwise it's an unused parameter */
        d_lw.println();
      if (!check)  {
        d_lw.println("! Dummy DIMS to get C_F_POINTER Shape set");
        d_lw.println("integer,parameter :: DIM=100000000");
        d_lw.println();
      }

      d_lw.println("type,bind(c) :: " + d_mang.shortName(name, "_t"));
      d_lw.tab();

      for(Iterator i = d_struct.getItems().iterator(); i.hasNext(); ) { 
        Struct.Item e = (Struct.Item) i.next();
        Type t = e.getType();
        int type = t.getDetailedType();
        Integer objInt = new Integer(type);
        switch(type) {
        case Type.VOID:
          /* do nothing */
          break;
        case Type.ARRAY:
          final Type arrayType = t.getArrayType();
          if (null != arrayType) {
            if (t.isRarray()) {
              if (t.isNumericArray()){
                generateRarrayMember(e);
              }
            }
            else{
              /* for now naively treat everything as C_PTR */
              if (arrayType.getDetailedType() <= Type.STRING) {
                d_lw.println("type(c_ptr) :: "+e.getName());
              }
              else {
                d_lw.println("type(c_ptr) :: "+e.getName());
              }
            }
          }
          else {
            d_lw.println("type(sidl__array) :: "+e.getName());
          }
          break;
        case Type.STRUCT:
          SymbolID idTest=t.getSymbolID();
          d_lw.println("type("+Fortran.getModule(idTest)+"_t) :: "+e.getName());
          break;
          /* fall through intended */
        case Type.DOUBLE:
        case Type.FLOAT:
        case Type.INT:
        case Type.LONG:
          default:
            d_lw.println(d_bbc.getBindCType(objInt)+" :: "+e.getName());
          }
      }
      d_lw.backTab();
      d_lw.println("end type " + d_mang.shortName(name, "_t"));

      d_lw.backTab();
      d_lw.println("end module " + 
                   d_mang.shortName(name, ""));
    }
    catch (UnsupportedEncodingException uee) {
      throw new CodeGenerationException("UnsupportedEncodingException: " +
                                        uee.getMessage());
    }
  }

  public static void generateCode(Struct strct,
                                  LanguageWriterForFortran writer,
                                  CodeSplicer splicer,
                                  Context context)
    throws CodeGenerationException, NoSuchAlgorithmException
  {
    StructModule mod = new StructModule(writer, splicer,strct, context);
    mod.generateCode();
  }

  private void generateRarrayMember(Struct.Item e)
    throws CodeGenerationException
    {

      Type t = e.getType();
      Type aType = t.getArrayType();
      Integer objInt = new Integer(aType.getBasicType());
      StringBuffer rawString = new StringBuffer();
      Iterator indexVar = t.getArrayIndexExprs().iterator();
      AssertionExpression ae = (AssertionExpression)indexVar.next();
      String checkInt = ae.toString();
      if (ImplSource.isInt(checkInt)){
        rawString.append(d_bbc.getBindCType(objInt)+"::"+e.getName()+"("+checkInt);                       
      } else {
        rawString.append("type(c_ptr) :: "+e.getName());
      }

      final int dims=t.getArrayDimension();

      int count=1;
      while(indexVar.hasNext()) {
        ae = (AssertionExpression)indexVar.next();
        checkInt = ae.toString();

        /* Only need to add dimensions if explicitly defined */
        if (ImplSource.isInt(checkInt)){
          rawString.append(","+checkInt);
        }
        count++;
      }
      if (ImplSource.isInt(checkInt)){
        rawString.append(")");
      }
      d_lw.println(rawString.toString()); 

      if (count != dims){
        throw new CodeGenerationException("Babel: Error in Rarray dimensions. Dimensions="+dims+" of type don't match those given in name "+e.getName()+" (dimensions="+count+").");
      }
    }
}
