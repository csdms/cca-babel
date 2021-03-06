//
// File:        ImplSource.java
// Package:     gov.llnl.babel.backend.c
// Revision:    @(#) $Revision: 6482 $
// Date:        $Date: 2008-08-21 15:50:53 -0700 (Thu, 21 Aug 2008) $
// Description: generate C server code to be edited by the developer
//
// Copyright (c) 2000-2007, Lawrence Livermore National Security, LLC
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

package gov.llnl.babel.backend.c;

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.backend.c.C;
import gov.llnl.babel.backend.c.StubSource;
import gov.llnl.babel.backend.CodeConstants;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.backend.writers.LanguageWriterForC;
import gov.llnl.babel.Context;
import gov.llnl.babel.symbols.Argument;
import gov.llnl.babel.symbols.Class;
import gov.llnl.babel.symbols.Method;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import java.util.HashSet;
import java.util.Iterator;

/**
 * <p>
 * Class <code>ImplSource</code> generates a C implementation source to a
 * language writer output stream.  The constructor takes a language writer
 * stream and method <code>generateCode</code> generates the implementation
 * header file for the specified symbol to the output stream.  The language
 * writer stream is not closed by this object.
 * </p>
 * <p>
 * The implementation source contains definitions of the non-abstract
 * methods. Unlike most files generated by <code>babel</code>, this file
 * is intended to be edited by the developer. The developer needs to insert
 * the implementation of the class in this file or insert calls to something
 * that implements the class.
 * </p>
 * <p>
 * The code splicer is used to maintain code the developer has written when
 * overwriting an implementation source file. The splicer stores code
 * fragments from the previous file that can be insert into the new file.
 * </p>
 */
public class ImplSource {
  /**
   * The splicer is used when replacing an existing file. Sections from the
   * previous file are stored in the splicer and can be grafted back into
   * the file being generated.
   */
  private CodeSplicer        d_splicer;

  /**
   * The writer is the output stream for the new file. The content of the
   * new file is writtern to this writer.
   */
  private LanguageWriterForC d_writer;

  private Context d_context;

  /**
   * Create a <code>ImplSource</code> object that will write symbol
   * information to the provided output language writer stream.  The
   * code splicer object may be used to save state between the old
   * source file and the new source file.  If the code splicer object
   * is null, then no state is transferred to the new source file.
   *
   * @param writer  the output writer for the new implementation source
   *                file. This writer will not be closed by this method.
   * @param splicer If not <code>null</code>, this splicer contains
   *                code fragments from a implementation source file
   *                that is being overwritten. The new implementation
   *                will try to incorporate those fragments into the
   *                new file.
   */
  public ImplSource(LanguageWriterForC writer, 
                    CodeSplicer splicer,
                    Context context) {
    d_splicer = splicer;
    d_writer  = writer;
    d_context = context;
  }

  /**
   * This is a convenience utility function that writes the symbol
   * source information into the provided language writer output stream.
   * The output stream is not closed on exit.
   *
   * @param cls     the class whose implementation source is to be created.
   * @param writer  the output writer with which the new file is created.
   * @param splicer If not <code>null</code>, the splicer contains
   *                code fragments from a previous implementation source
   *                file that is being overwritten. The new implementation
   *                will incorporate those fragments into the new file.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   *
   */
  public static void generateCode(Class cls, 
                                  LanguageWriterForC writer,
                                  CodeSplicer splicer,
                                  Context context)
    throws CodeGenerationException
  {
    ImplSource source = new ImplSource(writer, splicer, context);
    source.generateCode(cls);
  }

  /**
   * Start the source file with a large banner.
   *
   * @param cls     the class whose implementation source is to be created.
   */
  private void writePrologue(Class cls) {
    String header = C.getImplSourceFile(cls);
    d_writer.writeBanner(cls, header, true, CodeConstants.C_DESC_IMPL_PREFIX 
      + cls.getFullName());
    d_writer.beginBlockComment(false);
    d_writer.println("DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS");
    d_writer.println("FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.");
    d_writer.endBlockComment(false);
    d_writer.writeComment(cls, false);
  }

  /**
   * Output the include for the main header file.  Include a code
   * splicer block where the developer can include additional header files.
   *
   * @param cls     the class whose implementation source is to be created.
   */
  private void writeIncludeSection(Class cls) {
    String includes = cls.getFullName() + "." + "_includes";
    d_writer.generateInclude(C.getImplHeaderFile(cls), false);
    d_writer.generateInclude(C.getHeaderFile(d_context.getSymbolTable().
             lookupSymbol(BabelConfiguration.getNotImplemented())), false);
    d_writer.generateInclude("sidl_Exception.h", false);
    d_writer.generateInclude(C.getHeaderFile(d_context.getSymbolTable().
             lookupSymbol(BabelConfiguration.getMemoryAllocationException())), 
                          true);
    writeStructIncludes(cls);

    d_writer.println();
    //If this class overwrites parent methods, we need to generate
    //ways to access those super methods.

    d_splicer.splice(includes, d_writer, "includes and arbitrary code");
    d_writer.println();
  }

  private void writeStructIncludes(Class cls) {
    HashSet  already = new HashSet();
    Iterator i       = cls.getMethods(false).iterator();
    while (i.hasNext()) {
      Method   m  = (Method)i.next();
      Iterator aa = m.getArgumentList().iterator();
      while (aa.hasNext()) {
        Argument arg = (Argument) aa.next();
        if (arg.getType().getDetailedType() == Type.STRUCT) {
          SymbolID id = arg.getType().getSymbolID();
          if (!already.contains(id)) {
            d_writer.generateInclude (C.getHeaderFile(id), true);
            already.add(id);
          }
        }
      }
    }
  }

  /**
   * Write the body of an implementation method using code from the splicer
   * if available; otherwise, write a splicer block for the developer to
   * replace.
   *
   * @param id     the name of the symbol who owns the method.
   * @param name   the formal name of the method.
   * @param desc   a terse human grokable name for the method.
   * @param defaultSplicer True if we want to fill in an empty splicer block
   *                       with the default boilerplate code
   */
  private void writeMethodBody(SymbolID id, String name, String desc, 
                               boolean defaultSplicer) 
  {
    String splicerTag = id.getFullName() + '.' + name;
    if(defaultSplicer) {
      if (IOR.getBuiltinName(IOR.CONSTRUCTOR, false).equals(name)) {
        final String pstruct = C.getDataName(id);
        SymbolID memAllocId = d_context.getSymbolTable().
          lookupSymbol(BabelConfiguration.getMemoryAllocationException());
        String defaultCtor[] = {
          "// boilerplate constructor",
          pstruct + " *dptr = (" + pstruct + "*)malloc(sizeof(" + pstruct +
          "));",
          "if (dptr) {",
          "  memset(dptr, 0, sizeof(" + pstruct + "));",
          "  // initialize elements of dptr here",
          C.getDataSetName(id) + "(self, dptr);", 
          "} else {",
          "  " + C.getSymbolName(memAllocId) + " ex = " 
               + C.getFullMethodName(memAllocId, "getSingletonException")
               + "(_ex);",
          "  SIDL_CHECK(*_ex);",
          "  " + C.getFullMethodName(memAllocId, "setNote") 
               + "(ex, \"Out of memory.\", _ex); SIDL_CHECK(*_ex);",
          "  " + C.getFullMethodName(memAllocId, "add") 
               + "(ex, __FILE__, __LINE__, \"" + splicerTag + "\", _ex);",
          "  SIDL_CHECK(*_ex);",
          "  *_ex = (sidl_BaseInterface)ex;",
          "}",
          "EXIT:;"
        }; 
        if ( d_context.getConfig().getCCAMode()==true) { 
          d_splicer.splice(splicerTag, d_writer, desc + " method",defaultCtor);
        } else { 
          d_splicer.splice(splicerTag, d_writer, null ,defaultCtor);
        }
      } else if (IOR.getBuiltinName(IOR.DESTRUCTOR, false).equals(name)) {
        final String pstruct = C.getDataName(id);
        String defaultDtor[] = {
          "// boilerplate destructor",
          pstruct + " *dptr = " + C.getDataGetName(id) + "(self);",
          "if (dptr) {",
          "  // free contained in dtor before next line",
          "  free(dptr);",
          "  " + C.getDataSetName(id) + "(self, NULL);",
          "}"
        };
        if ( d_context.getConfig().getCCAMode()==true) { 
          d_splicer.splice(splicerTag, d_writer, desc + " method",defaultDtor);
        } else { 
          d_splicer.splice(splicerTag, d_writer, null ,defaultDtor);
        }
      } else {
        if ( d_context.getConfig().getCCAMode()==true ) { 
          String defaultComment[] = {
            "This method has not been implemented" 
          };
          String defaultCode[] = {
            "    /* DO-DELETE-WHEN-IMPLEMENTING exception.begin(" + splicerTag 
                 + ") */",
            "    SIDL_THROW(*_ex, sidl_NotImplementedException, "+
            "    \"This method has not been implemented\");",
            "  EXIT:;",
            "    /* DO-DELETE-WHEN-IMPLEMENTING exception.end(" + splicerTag 
                 + ") */"
          };
          d_splicer.splice(splicerTag, d_writer, desc + " method",
                         defaultComment, defaultCode);
        } else { 
          d_splicer.splice(splicerTag, d_writer, desc, null, null );
        }
      }
    } else {
      d_splicer.splice(splicerTag, d_writer, desc + " method");
    }
  }

  /**
   * Write a method definition with a body from the previous implementation
   * or a code splicer block where the developer can insert the
   * implementation.
   *
   * @param m      the method description
   * @param id     the name of the symbol who owns the method
   * @param desc   a human grokable description of the method
   * @param defaultSplicer True if we want to fill in an empty splicer block
   *                       with the default boilerplate code
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  private void writeMethodShell(Method m, SymbolID id, String desc, 
                                boolean defaultSplicer)
    throws CodeGenerationException
  {
    String name        = m.getLongMethodName();
    String method_name = C.getMethodImplName(id, name);

    d_writer.writeComment(m, false);
    
    d_writer.printlnUnformatted("#undef __FUNC__");
    d_writer.printlnUnformatted("#define __FUNC__ \"" + method_name + "\"");
    d_writer.println();
    ImplHeader.writeMethodSignature(d_writer, m, Utilities.s_self,
                                    false, false, true, id, d_context);
    d_writer.println();
    d_writer.backTab();
    d_writer.println("{");
    d_writer.tab();
    if (!m.getThrows().isEmpty()) {
      d_writer.println("*" + Utilities.s_exception + " = 0;");
      d_writer.println("{");
      d_writer.tab();
    }
    writeMethodBody(id, name, desc, defaultSplicer);
    if (!m.getThrows().isEmpty()) {
      d_writer.backTab();
      d_writer.println("}");
    }
    d_writer.backTab();
    d_writer.println("}");
  }

  /**
   * Write the implementation shell for the constructor or destructor. These
   * methods are implicitly defined.
   *
   * @param id         the name of the <code>Class</code> whose
   *                   constructor/destructor is being written.
   * @param methodName the name of the method being written.
   * @param methodDesc a terse human grokable description of the method
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  private void writeBuiltinMethods(Class cls) throws CodeGenerationException {
    StubSource.generateSupers(cls.getOverwrittenClassMethods(), cls, d_writer, 
                              d_context);
    writeMethodShell(IOR.getBuiltinMethod(IOR.LOAD, cls, d_context), cls, 
                     "static class initializer", true);
    writeMethodShell(IOR.getBuiltinMethod(IOR.CONSTRUCTOR, cls, d_context), cls,
                     "constructor", true);
    d_writer.println();
    writeMethodShell(IOR.getBuiltinMethod(IOR.CONSTRUCTOR2, cls, d_context), 
                     cls, "special constructor", true);
    writeMethodShell(IOR.getBuiltinMethod(IOR.DESTRUCTOR, cls, d_context), cls,
                     "destructor", true);
  }

  /**
   * Write definitions for the non-<code>abstract</code> methods of the
   * class.
   *
   * @param cls      the class whose implementation source is to be
   *                 created.
   * @param isStatic <code>true</code> means write only static methods;
   *                 <code>false</code> means write only non-static
   *                 methods.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  private void writeMethods(Class cls, boolean isStatic)
    throws CodeGenerationException
  {
    Iterator i = null;
    if (isStatic) {
      i = cls.getStaticMethods(false).iterator();
    } else {
      i = cls.getNonstaticMethods(false).iterator();
    }

    while (i.hasNext()) {
      Method m = (Method) i.next();
      if (!m.isAbstract()) {
        d_writer.println();
        if (IOR.generateHookMethods(cls, d_context)) {
          Method pre  = m.spawnPreHook();
          Method post = m.spawnPostHook();
          writeMethodShell(pre, cls, pre.getLongMethodName(), false);
          d_writer.println();
          writeMethodShell(m, cls, m.getLongMethodName(), true);
          d_writer.println();
          writeMethodShell(post, cls, post.getLongMethodName(), false);

        } else {
          writeMethodShell(m, cls, m.getLongMethodName(), true);
        }
      }
    }
  }

  private void writeIORVersion()
  {
    d_writer.printUnformatted("#define SIDL_IOR_MAJOR_VERSION ");
    d_writer.printlnUnformatted(Integer.toString(IOR.MAJOR_VERSION));
    d_writer.printUnformatted("#define SIDL_IOR_MINOR_VERSION ");
    d_writer.printlnUnformatted(Integer.toString(IOR.MINOR_VERSION));
  }

  /**
   * Write C implementation source information for the provided class
   * to the language writer output stream provided in the constructor.
   * This method does not close the writer output stream.
   *
   * @param cls     the class whose implementation source is to be created.
   * @exception gov.llnl.babel.backend.CodeGenerationException
   *    this is a catch all exception. It can be caused by I/O trouble or
   *    violations of the data type invariants.
   */
  public void generateCode(Class cls) throws CodeGenerationException {
    writePrologue(cls);
    writeIncludeSection(cls);
    writeIORVersion();
    writeBuiltinMethods(cls);
    writeMethods(cls, true);    // static methods
    writeMethods(cls, false);   // object methods
    d_writer.writeCommentLine("Babel internal methods, Users should not "
                             + "edit below this line.");
    
    d_writer.println();
    d_splicer.splice("_misc", d_writer, "miscellaneous code");
    d_writer.println();

    if (d_splicer.hasUnusedSymbolEdits()) {
      d_writer.println();
      d_writer.printlnUnformatted("#error File has unused splicer blocks.");
      d_writer.beginBlockComment(true);
      d_writer.println(CodeConstants.C_BEGIN_UNREFERENCED_METHODS);
      d_writer.println(CodeConstants.C_UNREFERENCED_COMMENT1);
      d_writer.println(CodeConstants.C_UNREFERENCED_COMMENT2);
      d_writer.println(CodeConstants.C_UNREFERENCED_COMMENT3);
      d_writer.endBlockComment(true);
      d_splicer.outputUnusedSymbolEdits(d_writer);
      d_writer.writeCommentLine(CodeConstants.C_END_UNREFERENCED_METHODS);
    }
  }
}
