//
// File:        GenerateDoc.java
// Package:     gov.llnl.babel.backend.html
// Revision:    @(#) $Id: GenerateDoc.java 6482 2008-08-21 22:50:53Z epperly $
// Description: generate C client code based on a set of symbol identifiers
//
// Copyright (c) 2000-2001, Lawrence Livermore National Security, LLC
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

package gov.llnl.babel.backend.html;

import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeGenerator;
import gov.llnl.babel.parsers.xml.SymbolToDOM;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolTable;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

/**
 * Class <code>GenerateDoc</code> is the main entry point for the html
 * documentation backend. This code generates documentation for the
 * symbols on the command line.
 */
public class GenerateDoc implements CodeGenerator {

  private Context d_context = null;

  /**
   * The constructor does nothing interesting.  The entry point for
   * the <code>GenerateDoc</code> class is <code>generateCode</code>.
   */
  public GenerateDoc() { }

  /**
   * Generate HTML documentation for each symbol identifier in the set
   * argument.  This routine assumes that all necessary symbol references
   * are available in the symbol table.
   */
  public void generateCode(Set symbols) throws CodeGenerationException {
    ArrayList sortedSymbols = new ArrayList(symbols);
    SymbolTable table = d_context.getSymbolTable();
    ArrayList files = new ArrayList(symbols.size());
    Collections.sort(sortedSymbols);
    for (Iterator s = sortedSymbols.iterator(); s.hasNext(); ) {
      SymbolID id     = (SymbolID) s.next();
      Symbol   symbol = table.lookupSymbol(id);
      
      if (symbol != null) {
        try {
          String xmlString = SymbolToDOM.convertToString(symbol, d_context);
          File xmlFile = File.createTempFile("babel",".xml");
          xmlFile.deleteOnExit();
          FileWriter out = new FileWriter(xmlFile);
          out.write(xmlString);
          out.close();
          files.add(xmlFile.getAbsolutePath());
        }
        catch( IOException ioe) {
          
        }
      }
    }
    BabelDoc doc = new BabelDoc(d_context);
    try {
      doc.docify(files.toArray());
    }
    catch (BabelDocException bde) {
      throw new CodeGenerationException(bde.getMessage());
    }
  }


  public String getType() {
    return "text";
  }

  public boolean getUserSymbolsOnly() {
    return false;
  }

  public Set getLanguages() {
    Set result = new TreeSet();
    result.add("html");
    return result;
  }

  public void setName(String name)
    throws CodeGenerationException
  {
    if (!"html".equals(name)) {
      throw new CodeGenerationException
        ("\"" +name + "\" is not a valid name for the html generator.");
    }
  }


  public String getName() { return "html"; }

  public void setContext(Context context) {
    d_context = context;
  }
}
