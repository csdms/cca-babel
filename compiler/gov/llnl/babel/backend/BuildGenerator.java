//
// File:        BuildGenerator.java
// Package:     gov.llnl.babel.backend
// Revision:    @(#) $Revision: 6482 $
// Date:        $Date: 2008-08-21 15:50:53 -0700 (Thu, 21 Aug 2008) $
// Description: An interface for Makefile and build system generators
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

package gov.llnl.babel.backend;

import java.util.Set;
import java.io.IOException;


/**
 * This interface is used by backends to provide the basic information
 * needed by a build system such as Makefile or Python distutils.
 * In general, BuildGenerators as a group are invoked after the
 * CodeGenerators for a given language, but in no particular order.
 * 
 * @version $Id: BuildGenerator.java 6482 2008-08-21 22:50:53Z epperly $
 */
public interface BuildGenerator {
  /**
   * Generate the files needed to support the building of Babel generated
   * files. For example, this could create <code>babel.make</code> files
   * or a Python setup.py for distutils.
   *
   * @exception java.io.IOException this is a exception that contains
   * all the I/O exceptions that occurred during file generation.
   */
  public void createAll()
    throws IOException;

  /**
   * Return the set of languages that this build generator serves. Each build
   * generator serves a Set of languages.
   * @return a {@link java.util.Set} of strings. Each string in the set
   * represents a language supported by the build generator.
   */
  public Set getLanguages();
}
