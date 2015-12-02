/*
 * File:          sidl_ContractClass_IOR.h
 * Symbol:        sidl.ContractClass-v0.9.17
 * Symbol Type:   enumeration
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.ContractClass
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

#ifndef included_sidl_ContractClass_IOR_h
#define included_sidl_ContractClass_IOR_h

#ifndef included_sidlType_h
#include "sidlType.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidl.ContractClass" (version 0.9.17)
 * 
 * Contract classification.  The classification is used to filter
 * contract clauses by the corresponding characteristic(s).
 */


/* Opaque forward declaration of array struct */
struct sidl_ContractClass__array;

enum sidl_ContractClass__enum {
  sidl_ContractClass_ALLCLASSES  = 0,

  sidl_ContractClass_CONSTANT    = 1,

  sidl_ContractClass_CUBIC       = 2,

  sidl_ContractClass_INVARIANTS  = 3,

  sidl_ContractClass_INVPOST     = 4,

  sidl_ContractClass_INVPRE      = 5,

  sidl_ContractClass_LINEAR      = 6,

  sidl_ContractClass_METHODCALLS = 7,

  sidl_ContractClass_POSTCONDS   = 8,

  sidl_ContractClass_PRECONDS    = 9,

  sidl_ContractClass_PREPOST     = 10,

  sidl_ContractClass_QUADRATIC   = 11,

  sidl_ContractClass_QUARTIC     = 12,

  sidl_ContractClass_QUINTIC     = 13,

  sidl_ContractClass_RESULTS     = 14,

  sidl_ContractClass_SEPTIC      = 15,

  sidl_ContractClass_SEXTIC      = 16,

  sidl_ContractClass_SIMPLEEXPRS = 17

};

#ifdef __cplusplus
}
#endif
#endif
