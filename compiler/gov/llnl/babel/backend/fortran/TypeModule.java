//
// File:        TypeModule.java
// Package:     gov.llnl.babel.backend.fortran
// Copyright:   (c) 2003 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6399 $
// Date:        $Date: 2008-06-11 14:41:51 -0700 (Wed, 11 Jun 2008) $
// Description: Generate an F90 module containing a derived type
// 

package gov.llnl.babel.backend.fortran;

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.writers.LanguageWriter;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.Extendable;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Version;
import java.util.TreeMap;

/**
 * This class generates a FORTRAN 90 module holding the derived type for
 * client-side users.
 *
 * The type is held separately to avoid circular dependencies.
 *
 * If d_sym is null, we generate a type for generic arrays.  Since this is 
 * A special case, the code is now full of little hacks to deal with it.
 */
public class TypeModule {
  static private final int s_maxArray = BabelConfiguration.getMaximumArray();

  /**
   * This holds the output device where the file will be written.
   */
  private LanguageWriterForFortran d_lw;

  /**
   * This is the extendable (i.e., class or interface) that is being
   * generated.
   */
  private Symbol d_sym;

  public TypeModule(LanguageWriterForFortran writer,
                    Symbol sym)
  {
    d_lw = writer;
    d_sym = sym;
  }

  private void describeFile()
  {
    d_lw.beginBlockComment(false);
    d_lw.println("This file contains a FORTRAN 90 derived type for the");
    if(d_sym == null)
      d_lw.println("sidl type sidl_array.");
    else
      d_lw.println("sidl type " + d_sym.getFullName() + ".");
    d_lw.endBlockComment(false);
  }

   static void writeArrayType(LanguageWriter lw,
                             SymbolID id,
                             String implDataType,
                             Context context)
  {

    for(int i = 1; i <= s_maxArray; ++i) {

      lw.println("type " + Fortran.getArrayName(id, i));
      lw.tab();
      if (Fortran.hasBindC(context)) {
          lw.println("type(c_ptr) :: d_array");
      } else {
        lw.println("sequence");
        lw.println("integer (kind=sidl_arrayptr) :: d_array");
      }
      if (implDataType != null){
        lw.println(implDataType + ", pointer, &");
        lw.tab();
        lw.print("dimension(:");
        for(int j = 1; j < i; ++j) {
          lw.print(",:");
        }
        lw.println(") :: d_data");
        lw.backTab();
      }
      
      lw.backTab();
      lw.println("end type " + Fortran.getArrayName(id, i));
      lw.println();
    }
  }

  private void writeGenericArrayType(SymbolID id,
                                    Context context)
  {
    d_lw.println("type sidl__array");
    d_lw.tab();
    if (Fortran.hasBindC(context)) {
      d_lw.println("type(c_ptr) :: d_array");
    } else { 
      d_lw.println("sequence");
      d_lw.println("integer (kind=sidl_arrayptr) :: d_array");
    }
    d_lw.backTab();
    d_lw.println("end type sidl__array");
    d_lw.println();
  
  }

  private void writeModule(Context context)
  {
    SymbolID id = null;
    if(d_sym == null)
      id = new SymbolID("sidl.array", new Version());
    else
      id = d_sym.getSymbolID();
    
    d_lw.println("module " + Fortran.getTypeModule(id));
    d_lw.tab();
    d_lw.generateUse("sidl", new TreeMap());
    if (Fortran.hasBindC(context)) {
      d_lw.generateUse(",intrinsic :: iso_c_binding",new TreeMap());
    }
    //There are only array types for generic arrays! (d_sym == null)
    if (d_sym != null && d_sym instanceof Extendable) {
      d_lw.println("type " + Fortran.getTypeName(id));
      d_lw.tab();
      d_lw.println("sequence");
      d_lw.println("integer (kind=sidl_iorptr) :: d_ior");
      d_lw.backTab();
      d_lw.println("end type " + Fortran.getTypeName(id));
      d_lw.println();
    }
    
    //Write generic arrays, or write normal ones.
    if (d_sym == null) {
      writeGenericArrayType(id,context);
    } else {
      writeArrayType(d_lw, id, null,context);
    }
    d_lw.backTab();
    d_lw.println("end module " + Fortran.getTypeModule(id));
    
  }

  public void generateCode(Context context)
  {
    SymbolID id = null;
    if(d_sym == null)
      id = new SymbolID("sidl.array", new Version());
    else
      id = d_sym.getSymbolID();
    
    if(d_sym != null) 
      d_lw.writeBanner(d_sym, Fortran.getTypeFile(id), false,
                       CodeConstants.C_FORTRAN_TYPE_MODULE_PREFIX +
                       id.getFullName());

    try {
      d_lw.pushLineBreak(false);
      d_lw.generateInclude( Fortran.getStubNameFile(id) );
    }
    finally {
      d_lw.popLineBreak();
    }
    d_lw.println();
    describeFile();
    writeModule(context);
  }

  /**
   * Generate the FORTRAN 90 type module for a sidl extendable (i.e., class
   * or interface).
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   * a catch all exception to indicate problems in the code generation
   * phase.
   */
  public static void generateCode(Symbol sym,
                                  LanguageWriterForFortran writer,
                                  Context context)
    throws CodeGenerationException
  {
    TypeModule tm = new TypeModule(writer, sym);
    tm.generateCode(context);
  }
}
