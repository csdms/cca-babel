/*
 * File:          sidl_EnforceFreq_IOR.h
 * Symbol:        sidl.EnforceFreq-v0.9.17
 * Symbol Type:   enumeration
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.EnforceFreq
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
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 */

#ifndef included_sidl_EnforceFreq_IOR_h
#define included_sidl_EnforceFreq_IOR_h

#ifndef included_sidlType_h
#include "sidlType.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidl.EnforceFreq" (version 0.9.17)
 * 
 * Contract clause enforcement frequency.
 */


/* Opaque forward declaration of array struct */
struct sidl_EnforceFreq__array;

enum sidl_EnforceFreq__enum {
  sidl_EnforceFreq_NEVER       = 0,

  sidl_EnforceFreq_ALWAYS      = 1,

  sidl_EnforceFreq_ADAPTFIT    = 2,

  sidl_EnforceFreq_ADAPTTIMING = 3,

  sidl_EnforceFreq_PERIODIC    = 4,

  sidl_EnforceFreq_RANDOM      = 5,

  sidl_EnforceFreq_SIMANNEAL   = 6

};

#ifdef __cplusplus
}
#endif
#endif
