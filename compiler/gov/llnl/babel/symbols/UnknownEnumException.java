//
// File:        UnknownEnumException.java
// Package:     gov.llnl.babel.symbols
// Revision:    @(#) $Revision: 6482 $
// Date:        $Date: 2008-08-21 15:50:53 -0700 (Thu, 21 Aug 2008) $
// Description: Client requested an unknown enumeration.
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

package gov.llnl.babel.symbols;

/**
 * This runtime exception is thrown when you attempt to get the value of an
 * enumeration symbol that is undefined.
 */
public class UnknownEnumException extends RuntimeException {

   /**
	 * 
	 */
	private static final long serialVersionUID = 846227056106610091L;
private String d_enumerator;
   
   /**
    * Create an enumeration exception.
    */
   public UnknownEnumException(String enumerator)
   {
      super(enumerator + " is not defined");
      d_enumerator = enumerator;
   }

   /**
    * Get the enumerator that was unknown.
    */
   public String getEnumerator() {
      return d_enumerator;
   }
}
