//
// File:        CookieCrumbleException.java
// Package:     gov.llnl.babel.url.cookie
// Revision:    @(#) $Id$
// Description: An exception for cookie management
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

package gov.llnl.babel.url.cookie;

/**
 * This is an exception for cookie management and cookie problems.
 */
public class CookieCrumbleException extends java.lang.Exception {

   /**
	* 
	*/
   private static final long serialVersionUID = 4791802678446646126L;

   /**
    * Create a <code>CookieCrumbleException</code>.  This exception usually
    * means that the client attempted to make an illegal cookie or
    * assign an illegal cookie attribute.
    */
   CookieCrumbleException(String mesg) {
      super(mesg);
   }
}
