/*
 * File:          sidl_rmi_InstanceRegistry_Impl.h
 * Symbol:        sidl.rmi.InstanceRegistry-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side implementation for sidl.rmi.InstanceRegistry
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
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sidl_rmi_InstanceRegistry_Impl_h
#define included_sidl_rmi_InstanceRegistry_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
#ifndef included_sidl_rmi_InstanceRegistry_h
#include "sidl_rmi_InstanceRegistry.h"
#endif
/* DO-NOT-DELETE splicer.begin(sidl.rmi.InstanceRegistry._hincludes) */
#include "sidl_hashtable.h"
/* DO-NOT-DELETE splicer.end(sidl.rmi.InstanceRegistry._hincludes) */

/*
 * Private data for class sidl.rmi.InstanceRegistry
 */

struct sidl_rmi_InstanceRegistry__data {
  /* DO-NOT-DELETE splicer.begin(sidl.rmi.InstanceRegistry._data) */
  int d_dummy; /* prevent compilers from complaining about empty struct */
  /* DO-NOT-DELETE splicer.end(sidl.rmi.InstanceRegistry._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sidl_rmi_InstanceRegistry__data*
sidl_rmi_InstanceRegistry__get_data(
  sidl_rmi_InstanceRegistry);

extern void
sidl_rmi_InstanceRegistry__set_data(
  sidl_rmi_InstanceRegistry,
  struct sidl_rmi_InstanceRegistry__data*);

extern
void
impl_sidl_rmi_InstanceRegistry__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_InstanceRegistry__ctor(
  /* in */ sidl_rmi_InstanceRegistry self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_InstanceRegistry__ctor2(
  /* in */ sidl_rmi_InstanceRegistry self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_InstanceRegistry__dtor(
  /* in */ sidl_rmi_InstanceRegistry self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

extern
char*
impl_sidl_rmi_InstanceRegistry_registerInstance(
  /* in */ sidl_BaseClass instance,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_rmi_InstanceRegistry_registerInstanceByString(
  /* in */ sidl_BaseClass instance,
  /* in */ const char* instanceID,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_BaseClass
impl_sidl_rmi_InstanceRegistry_getInstanceByString(
  /* in */ const char* instanceID,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_rmi_InstanceRegistry_getInstanceByClass(
  /* in */ sidl_BaseClass instance,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_BaseClass
impl_sidl_rmi_InstanceRegistry_removeInstanceByString(
  /* in */ const char* instanceID,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_rmi_InstanceRegistry_removeInstanceByClass(
  /* in */ sidl_BaseClass instance,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseClass(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseClass(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
