/*
 * File:          sidl_rmi_ServerRegistry_Skel.c
 * Symbol:        sidl.rmi.ServerRegistry-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.rmi.ServerRegistry
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

#include "sidl_rmi_ServerRegistry_IOR.h"
#include "sidl_rmi_ServerRegistry.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_rmi_ServerInfo_h
#include "sidl_rmi_ServerInfo.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidl_rmi_ServerRegistry__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ServerRegistry__ctor(
  /* in */ sidl_rmi_ServerRegistry self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ServerRegistry__ctor2(
  /* in */ sidl_rmi_ServerRegistry self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ServerRegistry__dtor(
  /* in */ sidl_rmi_ServerRegistry self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_ServerRegistry_registerServer(
  /* in */ sidl_rmi_ServerInfo si,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_ServerInfo
impl_sidl_rmi_ServerRegistry_getServer(
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_rmi_ServerRegistry_getServerURL(
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_rmi_ServerRegistry_isLocalObject(
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex);

extern
struct sidl_io_Serializable__array*
impl_sidl_rmi_ServerRegistry_getExceptions(
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_ServerRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_rmi_ServerInfo__object* 
  impl_sidl_rmi_ServerRegistry_fconnect_sidl_rmi_ServerInfo(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_ServerRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_rmi_ServerInfo__object* 
  impl_sidl_rmi_ServerRegistry_fconnect_sidl_rmi_ServerInfo(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_rmi_ServerRegistry__set_epv(struct sidl_rmi_ServerRegistry__epv *epv)
{
  epv->f__ctor = impl_sidl_rmi_ServerRegistry__ctor;
  epv->f__ctor2 = impl_sidl_rmi_ServerRegistry__ctor2;
  epv->f__dtor = impl_sidl_rmi_ServerRegistry__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidl_rmi_ServerRegistry__set_sepv(struct sidl_rmi_ServerRegistry__sepv *sepv)
{
  sepv->f_registerServer = impl_sidl_rmi_ServerRegistry_registerServer;
  sepv->f_getServer = impl_sidl_rmi_ServerRegistry_getServer;
  sepv->f_getServerURL = impl_sidl_rmi_ServerRegistry_getServerURL;
  sepv->f_isLocalObject = impl_sidl_rmi_ServerRegistry_isLocalObject;
  sepv->f_getExceptions = impl_sidl_rmi_ServerRegistry_getExceptions;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_rmi_ServerRegistry__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_rmi_ServerRegistry__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidl_rmi_ServerRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

struct sidl_rmi_ServerInfo__object* 
  skel_sidl_rmi_ServerRegistry_fconnect_sidl_rmi_ServerInfo(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_rmi_ServerInfo__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_rmi_ServerRegistry__data*
sidl_rmi_ServerRegistry__get_data(sidl_rmi_ServerRegistry self)
{
  return (struct sidl_rmi_ServerRegistry__data*)(self ? self->d_data : NULL);
}

void sidl_rmi_ServerRegistry__set_data(
  sidl_rmi_ServerRegistry self,
  struct sidl_rmi_ServerRegistry__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
