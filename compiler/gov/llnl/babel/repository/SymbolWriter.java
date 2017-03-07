//
// File:        SymbolWriter.java
// Package:     gov.llnl.babel.repository
// Revision:    @(#) $Id$
// Description: interface for writing symbols to an external repository
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
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

package gov.llnl.babel.repository;

import gov.llnl.babel.repository.RepositoryException;
import java.util.Set;

/**
 * The <code>SymbolWriter</code> interface is implemented by repository
 * concrete classes that write sidl symbols to an external repository.
 */
public interface SymbolWriter {
   /**
    * Write the symbols in the <code>Set</code> from the symbol table
    * to the repository.  Each set entry is a <code>SymbolID</code> of
    * the symbol to be written to the repository.
    */
  public void writeSymbols(Set symbol_names)
    throws RepositoryException;
}
