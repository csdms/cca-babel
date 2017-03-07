/*
 * File:          sidl_rmi_ConnectRegistry_Skel.c
 * Symbol:        sidl.rmi.ConnectRegistry-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.rmi.ConnectRegistry
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

#include "sidl_rmi_ConnectRegistry_IOR.h"
#include "sidl_rmi_ConnectRegistry.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidl_rmi_ConnectRegistry__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ConnectRegistry__ctor(
  /* in */ sidl_rmi_ConnectRegistry self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ConnectRegistry__ctor2(
  /* in */ sidl_rmi_ConnectRegistry self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ConnectRegistry__dtor(
  /* in */ sidl_rmi_ConnectRegistry self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ConnectRegistry_registerConnect(
  /* in */ const char* key,
  /* in */ void* func,
  /* out */ sidl_BaseInterface *_ex);

extern
void*
impl_sidl_rmi_ConnectRegistry_getConnect(
  /* in */ const char* key,
  /* out */ sidl_BaseInterface *_ex);

extern
void*
impl_sidl_rmi_ConnectRegistry_removeConnect(
  /* in */ const char* key,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_ConnectRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_ConnectRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_rmi_ConnectRegistry__set_epv(struct sidl_rmi_ConnectRegistry__epv *epv)
{
  epv->f__ctor = impl_sidl_rmi_ConnectRegistry__ctor;
  epv->f__ctor2 = impl_sidl_rmi_ConnectRegistry__ctor2;
  epv->f__dtor = impl_sidl_rmi_ConnectRegistry__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidl_rmi_ConnectRegistry__set_sepv(struct sidl_rmi_ConnectRegistry__sepv *sepv)
{
  sepv->f_registerConnect = impl_sidl_rmi_ConnectRegistry_registerConnect;
  sepv->f_getConnect = impl_sidl_rmi_ConnectRegistry_getConnect;
  sepv->f_removeConnect = impl_sidl_rmi_ConnectRegistry_removeConnect;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_rmi_ConnectRegistry__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_rmi_ConnectRegistry__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidl_rmi_ConnectRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_rmi_ConnectRegistry__data*
sidl_rmi_ConnectRegistry__get_data(sidl_rmi_ConnectRegistry self)
{
  return (struct sidl_rmi_ConnectRegistry__data*)(self ? self->d_data : NULL);
}

void sidl_rmi_ConnectRegistry__set_data(
  sidl_rmi_ConnectRegistry self,
  struct sidl_rmi_ConnectRegistry__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
