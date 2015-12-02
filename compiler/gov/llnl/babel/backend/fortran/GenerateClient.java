////
// File:        GenerateClient.java
// Package:     gov.llnl.babel.backend.fortran
// Revision:    @(#) $Revision: 6525 $
// Description: generate C code to allow FORTRAN to access BABEL
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
import gov.llnl.babel.Generator;
import gov.llnl.babel.ResourceLoader;
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeGenerator;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.fortran.ModuleSource;
import gov.llnl.babel.backend.fortran.StubDoc;
import gov.llnl.babel.backend.fortran.StubSource;
import gov.llnl.babel.backend.writers.LanguageWriterForC;
import gov.llnl.babel.backend.writers.LanguageWriterForFortran;
import gov.llnl.babel.symbols.Struct;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolTable;
import gov.llnl.babel.symbols.Type;
import gov.llnl.babel.symbols.Version;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.security.NoSuchAlgorithmException;
import java.io.Writer;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;


/**
 * This class implements the {@link gov.llnl.babel.backend.CodeGenerator
 * CodeGenerator} interface for the FORTRAN client side code generator.
 * This generator creates C source code to provide the glue between
 * FORTRAN clients and the IOR.
 */
public class GenerateClient implements CodeGenerator
{
  private String d_name = "f77";

  private Context d_context = null;

  private final static int[] s_basic_array_types = {
    Type.BOOLEAN,
    Type.CHAR,
    Type.DCOMPLEX,
    Type.DOUBLE,
    Type.FCOMPLEX,
    Type.FLOAT,
    Type.INT,
    Type.LONG,
    Type.OPAQUE,
    Type.STRING
  };

  private final static String [] s_generic_array_types = {
    // ordering here must match the ordering in sidl_array_type in sidlArray.h
    "bool",
    "char",
    "dcomplex",
    "double", 
    "fcomplex",
    "float",
    "int", 
    "long",
    "opaque",
    "string",
    "interface"
  };

  private boolean d_writeBasicArrayStubs = false;
  
  /**
   * Create a new instance.
   */
  public GenerateClient() {
    
  }

  private void copyArrayStub(String typeName,
                             Writer out)
    throws CodeGenerationException
  {
    final String context =
      "gov/llnl/babel/backend/fortran/" +
      d_context.getConfig().getTargetLanguage();
    ResourceLoader rl = new ResourceLoader();
    InputStream in = null;
    byte[] buffer = new byte[1024];
    int count;
    try {
      try {
        in = rl.getResourceStream(context + "/sidl_" + typeName + "_fStub.c");
        while ((count = in.read(buffer)) >= 0) {
          String str = new String(buffer,0,count);
          out.write(str);
        }
      }
      finally {
        if (in != null) {
          in.close();
        }
      }
    }
    catch (IOException ioe) {
      throw new CodeGenerationException(ioe.getMessage());
    }
  }

  private void copyArrayAbbrev(String typeName,
                               Writer out)
    throws CodeGenerationException
  {
    final String context = "gov/llnl/babel/backend/fortran/" +
      d_context.getConfig().getTargetLanguage();
    ResourceLoader rl = new ResourceLoader();
    InputStream in = null;
    byte[] buffer = new byte[1024];
    int count;
    try {
      try {
        in = rl.getResourceStream(context + 
                                  "/sidl_" + typeName + "_fAbbrev.h");
        while ((count = in.read(buffer)) >= 0) {
          String str = new String(buffer,0,count);
          out.write(str);
        }
      }
      finally {
        if (in != null) {
          in.close();
        }
      }
    }
    catch (IOException ioe) {
      throw new CodeGenerationException(ioe.getMessage());
    }
  }

  private void generateSIDLTypesFile()
    throws CodeGenerationException
  {
    final Symbol pkg = Utilities.lookupSymbol(d_context, "sidl");
    final SymbolID id = pkg.getSymbolID();
    final boolean includeExternal =
      !d_context.getConfig().excludeExternal();
    PrintWriter pw = null;
    LanguageWriterForFortran forWriter = null;
    if ((includeExternal || Generator.isIncluded(id, d_context)) &&
        Generator.notExcluded(id, d_context)) {
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        try {
          pw = d_context.getFileManager().createFile(id, Type.PACKAGE,
                                                    "BASICMODULESRC",
                                                    "sidl.F90");
          forWriter = new LanguageWriterForFortran(pw, d_context);
          forWriter.writeBanner(pkg, "sidl.F90", false,
                                CodeConstants.C_FORTRAN_MODULE_PREFIX +
                                id.getFullName());
          if (Fortran.hasBindC(d_context)) {
            forWriter.printlnUnformatted("#include \"babel_config.h\"");
            forWriter.println();
            forWriter.println("module sidl");
            forWriter.tab();
            forWriter.println("use, intrinsic :: iso_c_binding");
            forWriter.writeCommentLine("Define types for common numeric types");
            forWriter.println("integer, parameter :: sidl_int=c_int32_t");
            forWriter.println("integer, parameter :: sidl_long=c_int64_t");
            forWriter.println("integer, parameter :: sidl_opaque=c_int64_t");
            forWriter.println("integer, parameter :: sidl_arrayptr=c_int64_t");
            forWriter.println("integer, parameter :: sidl_iorptr=c_int64_t");
            forWriter.println("integer, parameter :: sidl_enum=c_int64_t");
            forWriter.println("integer, parameter :: sidl_dcomplex=c_double_complex");
            forWriter.println("integer, parameter :: sidl_fcomplex=c_float_complex");
            forWriter.println("integer, parameter :: sidl_double=c_double");
            forWriter.println("integer, parameter :: sidl_float=c_float");
            forWriter.println();
            forWriter.printlnUnformatted("#ifndef SIDL_HAS_FORTRAN_C_ASSOC");
            forWriter.println("interface");
            forWriter.tab();
            forWriter.println("logical function c_associated(ptr) bind(c)");
            forWriter.tab();
            forWriter.println("use, intrinsic :: iso_c_binding");
            forWriter.println("type(c_ptr) :: ptr");
            forWriter.backTab();
            forWriter.println("end function c_associated");
            forWriter.backTab();
            forWriter.println("end interface");
            forWriter.printlnUnformatted("#endif");
          }
          else {
            forWriter.println();
            forWriter.println("module sidl");
            forWriter.tab();
            forWriter.writeCommentLine("Define types for common numeric types");
            forWriter.println("integer, parameter :: sidl_int=selected_int_kind(9)");
            forWriter.println("integer, parameter :: sidl_long=selected_int_kind(18)");
            forWriter.println("integer, parameter :: sidl_opaque=selected_int_kind(18)");
            forWriter.println("integer, parameter :: sidl_arrayptr=selected_int_kind(18)");
            forWriter.println("integer, parameter :: sidl_iorptr=selected_int_kind(18)");
            
            forWriter.println("integer, parameter :: sidl_enum=selected_int_kind(18)");
            forWriter.println("integer, parameter :: sidl_dcomplex=selected_real_kind(15,307)");
            forWriter.println("integer, parameter :: sidl_fcomplex=selected_real_kind(6,37)");
            forWriter.println("integer, parameter :: sidl_double=selected_real_kind(15,307)");
            forWriter.println("integer, parameter :: sidl_float=selected_real_kind(6,37)");
            forWriter.println();
          }
          forWriter.writeCommentLine("Define generic array types");
          for(int i = 0 ; i < s_generic_array_types.length; ++i) {
            forWriter.println("integer, parameter :: sidl_" + 
                              s_generic_array_types[i] +
                              "_array_t=" + Integer.toString(i+1));
          }
          forWriter.backTab();
          forWriter.println("end module sidl");
        }
        finally {
          if (pw != null) {
            pw.flush();
            pw.close();
          }
        }
        if (Fortran.hasBindC(d_context)) {
          pw = null;
          try {
            pw = d_context.getFileManager().createFile(id, Type.PACKAGE,
                                                       "STUBSRCS",
                                                       "sidl_fStub.c");
            LanguageWriterForC writer= new LanguageWriterForC(pw, d_context);
            writer.writeBanner(pkg, "sidl_fStub.c", false,
                                CodeConstants.C_DESC_STUB_PREFIX +
                                id.getFullName());
            writer.printlnUnformatted("#include \"babel_config.h\"");
            writer.printlnUnformatted("#ifndef SIDL_HAS_FORTRAN_C_ASSOC");
            writer.printlnUnformatted("#include \"sidlfortran.h\"");
            writer.printlnUnformatted("#ifdef __cplusplus");
            writer.println("extern \"C\"");
            writer.printlnUnformatted("#endif");
            writer.println("SIDL_F90_Bool");
            writer.println("c_associated(void **ptr) {");
            writer.tab();
            writer.println("return (*ptr) ? SIDL_F90_TRUE : SIDL_F90_FALSE;");
            writer.backTab();
            writer.println("}");
            writer.println();
            writer.printlnUnformatted("#endif");
          }
          finally {
            if (pw != null) {
              pw.flush();
              pw.close();
            }
          }
        }
      }
      else {
        try {
          pw = d_context.getFileManager().createFile(id, Type.PACKAGE,
                                                    "STUBFORTRANINC",
                                                    "sidl.inc");
          forWriter = new LanguageWriterForFortran(pw, d_context);
          forWriter.writeBanner(pkg, "sidl.inc", false,
                                CodeConstants.C_FORTRAN_MODULE_PREFIX + 
                                id.getFullName());
          forWriter.println();
          for(int i = 0 ; i < s_generic_array_types.length ; ++i) {
            final String param = "SIDL_" + 
              s_generic_array_types[i].toUpperCase() + "_ARRAY";
            forWriter.println("integer*4 " + param);
            forWriter.println("parameter (" + param + " = " +
                              Integer.toString(i+1) + ")");
          }
        }
        finally {
          if (pw != null) {
            pw.flush();
            pw.close();
          }
        }
      }
    }
  }

  /**
   * Write F90array stubs for all the basic types.
   *
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception.
   */
  private void generateBasicArrayStubs()
    throws CodeGenerationException
  {
    PrintWriter pw = null;
    Writer w = null;
    LanguageWriterForFortran forWriter = null;
    final boolean isF90 = Fortran.isFortran90(d_context);
    final boolean includeExternal = 
      !d_context.getConfig().excludeExternal();


    try {
      int i;
 

      for(i = 0; i < s_basic_array_types.length; ++i) {
        final int type = s_basic_array_types[i];
        final String typeName = (new Type(type)).getTypeString();
        final SymbolID id = new SymbolID("sidl." + typeName,
                                         new Version());
        if ((includeExternal || Generator.isIncluded(id, d_context)) &&
            Generator.notExcluded(id, d_context)) {
          if (isF90 || Fortran.hasBindC(d_context)) {
            final String filename = Fortran.getArrayFile(id);
            pw = d_context.getFileManager().createFile(id, type, 
                                                      "ARRAYMODULESRCS",
                                                      filename);
            forWriter = new LanguageWriterForFortran(pw, d_context);
            ArrayModule am = new ArrayModule(id, type, forWriter, d_context);
            am.generateStub();
            forWriter.close();
          }
          w = d_context.getFileManager().createFile(id, type,
                                                   "STUBSRCS",
                                                   Fortran.getStubFile(id));
          copyArrayStub(typeName, w);
          w.close();

          if (Fortran.needsAbbrev(d_context)) {
            w = d_context.getFileManager().
              createFile(id, type, "STUBHDRS",
                         Fortran.getStubNameFile(id));
            copyArrayAbbrev(typeName, w);
            w.flush(); /* Sun appears to need this!?! */
            w.close(); /* close should imply flush */
          }
        }
      }

      if(includeExternal) {
        generateGenericArray();
      }

    }
    catch (IOException ioe) {
      throw new CodeGenerationException(ioe.getMessage());
    }
    finally {
      try {
        if (w != null) {
          w.close();
        }
      }
      catch (IOException ioe) {
        throw new CodeGenerationException(ioe.getMessage());
      }
      finally {
        if (pw != null) {
          pw.close();
        }
      }
    }
  }

  private void generateGenericArray() throws CodeGenerationException {
    PrintWriter pw = null;
    Writer w = null;
    LanguageWriterForFortran forWriter = null;
    try {
      final int type = Type.ARRAY;
      final String typeName = "array";
      final SymbolID id = new SymbolID("sidl.array",
                                       new Version());
      if (Fortran.isFortran90(d_context) || Fortran.hasBindC(d_context)) {
        //final SymbolID id1 = new SymbolID("sidl.",
        //                                 new Version());
        String filename = "sidl_array_array."+CodeConstants.C_F90_IMPL_EXTENSION;
        pw = d_context.getFileManager().createFile(id, type, 
                                                  "ARRAYMODULESRCS",
                                                  filename);
        forWriter = new LanguageWriterForFortran(pw, d_context);
        ArrayModule am = new ArrayModule(forWriter, d_context);
        am.generateStub();
        forWriter.close();

        filename = "sidl_array_type."+CodeConstants.C_F90_IMPL_EXTENSION;
        pw = d_context.getFileManager().createFile(id, type, 
                                                  "TYPEMODULESRCS",
                                                  filename);
        forWriter = new LanguageWriterForFortran(pw, d_context);
        TypeModule.generateCode(null, forWriter,d_context);
        //am.generateStub();
        forWriter.close();

      }
      w = d_context.getFileManager().createFile(id, type,
                                               "STUBSRCS",
                                               Fortran.getStubFile(id));
      copyArrayStub(typeName, w);
      w.close();

      if (Fortran.needsAbbrev(d_context)) {
        w = d_context.getFileManager().
          createFile(id, type, "STUBHDRS",
                     "sidl_array_fAbbrev.h");
        copyArrayAbbrev(typeName, w);
        w.flush(); /* Sun appears to need this!?! */
        w.close(); /* close should imply flush */
      }
    }
    catch (IOException ioe) {
      throw new CodeGenerationException(ioe.getMessage());
    }
    finally {
      try {
        if (w != null) {
          w.close();
        }
      }
      catch (IOException ioe) {
        throw new CodeGenerationException(ioe.getMessage());
      }
      finally {
        if (pw != null) {
          pw.close();
        }
      }
    }   
  }




  /**
   * If <code>symbol</code> is a class or interface, create a stub file for
   * it.
   *
   * @param symbol  a particlar symbol.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *  a catch all exception.
   */
  private void generateStubSource(Symbol symbol)
    throws CodeGenerationException 
  {
    PrintWriter pw = null, dw = null, nw = null, mw = null;
    LanguageWriterForFortran forWriter;
    final SymbolID id = symbol.getSymbolID();
    final int type = symbol.getSymbolType();
    boolean isF90 = Fortran.isFortran90(d_context);
    switch (type){
    case Symbol.CLASS:
    case Symbol.INTERFACE:
      try {
        String h = Fortran.getHeaderFile(id);
        pw       = d_context.getFileManager().createFile(id, type, 
                                                        "STUBHDRS", h);
        
        LanguageWriterForC writer = new LanguageWriterForC(pw, d_context);
        StubHeader.generateCode(symbol, writer);
        writer.close();
        
        String f = Fortran.getStubFile(id);
        pw       = d_context.getFileManager().createFile(id, type, 
                                                        "STUBSRCS", f);
        writer = new LanguageWriterForC(pw, d_context);
        StubSource.generateCode(symbol, writer, d_context);
        d_writeBasicArrayStubs = true;

        if (Fortran.needsAbbrev(d_context)) {
          String nf = Fortran.getStubNameFile(id);
          nw        = d_context.getFileManager().
            createFile(id, type, "STUBHDRS", nf);
          writer    = new LanguageWriterForC(nw, d_context);
          AbbrevHeader.generateCode(symbol, writer, d_context);
          writer.close();
        }

        if (isF90 || Fortran.hasBindC(d_context)) {
          String mf = Fortran.getModuleFile(id);
          mw        = d_context.getFileManager().
            createFile(id, type, "STUBMODULESRCS", mf);
	  forWriter = new LanguageWriterForFortran(mw, d_context);
          forWriter.writeBanner(symbol, mf, false,
                                CodeConstants.C_FORTRAN_TYPE_MODULE_PREFIX +
                                symbol.getFullName());
          ModuleSource.generateCode(symbol, forWriter, d_context);
          ArrayModule am = new ArrayModule(id, type, forWriter, d_context);
          am.generateStub();
          forWriter.close();
          String tf = Fortran.getTypeFile(id);
          mw        = d_context.getFileManager().
            createFile(id, type, "TYPEMODULESRCS", tf);
          forWriter = new LanguageWriterForFortran(mw, d_context);
          TypeModule.generateCode(symbol, forWriter,d_context);
          forWriter.close();
        } else {
          String df = Fortran.getStubDocFile(id);
          dw        = d_context.getFileManager().
            createFile(id, type, "STUBDOCS", df);
	  forWriter = new LanguageWriterForFortran(dw, d_context);
          StubDoc.generateCode(symbol, forWriter, d_context);
        }
      }
      finally {
        if (pw != null) {
          pw.close();
        }
        if (dw != null) {
          dw.close();
        }
        if (nw != null) {
          nw.close();
        }
        if (mw != null) {
          mw.close();
        }
      }
      break;
    case Symbol.ENUM:
      try {
        String nf = Fortran.getStubNameFile(id);
        String f = Fortran.getEnumStubImpl(id);
        d_writeBasicArrayStubs = true;
        pw = d_context.getFileManager().createFile(id, type, "STUBSRCS", f);
        LanguageWriterForC clw = new LanguageWriterForC(pw, d_context);
        StubSource.generateCode(symbol, clw, d_context);
        clw.close();
        if (Fortran.needsAbbrev(d_context)) {
          nw  = d_context.getFileManager().
            createFile(id, type, "STUBHDRS", nf);
          clw = new LanguageWriterForC(nw, d_context);
          AbbrevHeader.generateCode(symbol, clw, d_context);
          clw.close();
        }
        if (isF90 || Fortran.hasBindC(d_context)) {
          String mf = Fortran.getModuleFile(id);
          mw        = d_context.getFileManager().
            createFile(id, type, "STUBMODULESRCS", mf);
	  forWriter = new LanguageWriterForFortran(mw, d_context);
          ArrayModule am = new ArrayModule(id, type,
                                           forWriter, d_context);
          forWriter.writeBanner(symbol, mf, false,
                                CodeConstants.C_FORTRAN_TYPE_MODULE_PREFIX +
                                symbol.getFullName());
          ModuleSource.generateCode(symbol, forWriter, d_context);
          am.generateStub();
          forWriter.close();

          String tf = Fortran.getTypeFile(id);
          mw        = d_context.getFileManager().
            createFile(id, type, "TYPEMODULESRCS", tf);
          forWriter = new LanguageWriterForFortran(mw, d_context);
          TypeModule.generateCode(symbol, forWriter,d_context);
        }
        else {
          f = Fortran.getEnumStubFile(id);
          pw = d_context.getFileManager().
            createFile(id, type, "STUBFORTRANINC", f);
          LanguageWriterForFortran writer = new LanguageWriterForFortran(pw, d_context);
          StubSource.generateCode(symbol, writer, d_context);
          writer.close();
        }
      }
      finally {
        if (pw != null) {
          pw.close();
        }
        if (nw != null) {
          nw.close();
        }
        if (mw != null) {
          mw.close();
        }
      }
      break;
    case Symbol.STRUCT:
      try {
        {
          nw = d_context.getFileManager().
            createFile(id, type, "STUBSRCS", Fortran.getStubFile(id));
          LanguageWriterForC writer = new LanguageWriterForC(nw, d_context);
          StubSource.generateCode(symbol, writer, d_context);
          writer.close();
        }
        nw = null;
        if (Fortran.needsAbbrev(d_context)) {
          String nf = Fortran.getStubNameFile(id);
          nw        = d_context.getFileManager().
            createFile(id, type, "STUBHDRS", nf);
          LanguageWriterForC writer    = new LanguageWriterForC(nw, d_context);
          AbbrevHeader.generateCode(symbol, writer, d_context);
          writer.close();
        }

        Struct structSym = (Struct)symbol;
        String f = Fortran.getStructModuleFile(id, d_context);
        CodeSplicer splicer =
          d_context.getFileManager().getCodeSplicer(id, type, f, false, true);
        pw       = d_context.getFileManager().
          createFile(id, type, "TYPEMODULESRCS", f);
        LanguageWriterForFortran writer = 
          new LanguageWriterForFortran(pw, d_context);
        StructModule.generateCode(structSym, writer, splicer, d_context);
        writer.close();

      } 
        catch ( IOException ex ) { 
          throw new CodeGenerationException( ex.getMessage() );
        } 
        catch ( NoSuchAlgorithmException nsae) {
        throw new CodeGenerationException( "NoSuchAlgorithmException: " +
                                           nsae.getMessage());
      }
      finally {
        if (nw != null) {
          nw.close();
        }
      }
      break;
    }
  }
  
  /**
   * Given a set of symbol ids, this method will generate FORTRAN stubs
   * (written in C) for all the symbols in the set as needed.  Some symbol
   * types may not require a stub file, for example packages, and these are 
   * silently skipped.
   *
   * @param symbols    a set of symbol id (symbol names) for whom stubs
   *                   should be written as needed.  Each object in the
   *                   set should be a {@link
   *                   gov.llnl.babel.symbols.SymbolID SymbolID}.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *   a catch all exception to indicate problems in the code generation
   *   phase.
   */
  public void generateCode(Set symbols)
    throws CodeGenerationException 
  {
    Iterator i = symbols.iterator();
    SymbolTable table = d_context.getSymbolTable();
    while (i.hasNext()) {
      SymbolID id     = (SymbolID)i.next();
      Symbol   symbol = table.lookupSymbol(id);
      if (symbol != null) {
        generateStubSource(symbol);
      }
    }
    if (d_writeBasicArrayStubs) {
      generateSIDLTypesFile();
      generateBasicArrayStubs();
    }
  }

  public String getType()
  {
    return "stub";
  }

  public boolean getUserSymbolsOnly()
  {
    return false;
  }

  public Set getLanguages()
  {
    Set result = new TreeSet();
    result.add("f77");
    result.add("f77_31");
    result.add("f90");
    result.add("f03");
    return result;
  }

  public void setName(String name)
    throws CodeGenerationException
 {
    if (getLanguages().contains(name)) {
      d_name = name;
    }
    else {
      throw new CodeGenerationException
        ("\"" +name + "\" is not a valid name for the Fortran generator.");
    }
  }

  public String getName() { return d_name; }

  public void setContext(Context context)
  {
    d_context = context;
  }
}
