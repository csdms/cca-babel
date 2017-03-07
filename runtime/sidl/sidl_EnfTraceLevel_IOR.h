/*
 * File:          sidl_EnfTraceLevel_IOR.h
 * Symbol:        sidl.EnfTraceLevel-v0.9.17
 * Symbol Type:   enumeration
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.EnfTraceLevel
 * 
 * Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 */

#ifndef included_sidl_EnfTraceLevel_IOR_h
#define included_sidl_EnfTraceLevel_IOR_h

#ifndef included_sidlType_h
#include "sidlType.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidl.EnfTraceLevel" (version 0.9.17)
 * 
 * Contract enforcement tracing levels.  Enforcement traces rely on
 * runtime timing automatically inserted within the middleware.
 */


/* Opaque forward declaration of array struct */
struct sidl_EnfTraceLevel__array;

enum sidl_EnfTraceLevel__enum {
  sidl_EnfTraceLevel_NONE     = 0,

  sidl_EnfTraceLevel_CORE     = 1,

  sidl_EnfTraceLevel_BASIC    = 2,

  sidl_EnfTraceLevel_OVERHEAD = 3

};

#ifdef __cplusplus
}
#endif
#endif
