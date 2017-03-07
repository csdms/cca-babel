/*
 * File:          sidl_DLL_Skel.c
 * Symbol:        sidl.DLL-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.DLL
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
 * 
 */

#include "sidl_DLL_IOR.h"
#include "sidl_DLL.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidl_DLL__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_DLL__ctor(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_DLL__ctor2(
  /* in */ sidl_DLL self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_DLL__dtor(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_DLL_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
sidl_bool
impl_sidl_DLL_loadLibrary(
  /* in */ sidl_DLL self,
  /* in */ const char* uri,
  /* in */ sidl_bool loadGlobally,
  /* in */ sidl_bool loadLazy,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_DLL_getName(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidl_DLL_isGlobal(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidl_DLL_isLazy(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_DLL_unloadLibrary(
  /* in */ sidl_DLL self,
  /* out */ sidl_BaseInterface *_ex);

extern
void*
impl_sidl_DLL_lookupSymbol(
  /* in */ sidl_DLL self,
  /* in */ const char* linker_name,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_BaseClass
impl_sidl_DLL_createClass(
  /* in */ sidl_DLL self,
  /* in */ const char* sidl_name,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_DLL_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_DLL__set_epv(struct sidl_DLL__epv *epv)
{
  epv->f__ctor = impl_sidl_DLL__ctor;
  epv->f__ctor2 = impl_sidl_DLL__ctor2;
  epv->f__dtor = impl_sidl_DLL__dtor;
  epv->f_loadLibrary = impl_sidl_DLL_loadLibrary;
  epv->f_getName = impl_sidl_DLL_getName;
  epv->f_isGlobal = impl_sidl_DLL_isGlobal;
  epv->f_isLazy = impl_sidl_DLL_isLazy;
  epv->f_unloadLibrary = impl_sidl_DLL_unloadLibrary;
  epv->f_lookupSymbol = impl_sidl_DLL_lookupSymbol;
  epv->f_createClass = impl_sidl_DLL_createClass;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_DLL__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_DLL__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* skel_sidl_DLL_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_DLL__data*
sidl_DLL__get_data(sidl_DLL self)
{
  return (struct sidl_DLL__data*)(self ? self->d_data : NULL);
}

void sidl_DLL__set_data(
  sidl_DLL self,
  struct sidl_DLL__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
