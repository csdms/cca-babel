/*
 * File:          sidl_rmi_NetworkException_Skel.c
 * Symbol:        sidl.rmi.NetworkException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.rmi.NetworkException
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

#include "sidl_rmi_NetworkException_IOR.h"
#include "sidl_rmi_NetworkException.h"
#include <stddef.h>
#include "sidl_rmi_NetworkException_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void sidl_rmi_NetworkException__superEPV(
struct sidl_io_IOException__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct sidl_rmi_NetworkException__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct sidl_rmi_NetworkException__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
  _externals = sidl_rmi_NetworkException__externals();
  return _externals;
}

#define _getExternals() (_externals ? _externals : _loadIOR())


#ifdef WITH_RMI
#ifndef included_sidl_io_Deserializer_h
#include "sidl_io_Deserializer.h"
#endif
#ifndef included_sidl_io_Serializer_h
#include "sidl_io_Serializer.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern void sidl_rmi_NetworkException__superEPV(
struct sidl_io_IOException__epv*);

extern
void
impl_sidl_rmi_NetworkException__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException__ctor(
  /* in */ sidl_rmi_NetworkException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException__ctor2(
  /* in */ sidl_rmi_NetworkException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException__dtor(
  /* in */ sidl_rmi_NetworkException self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
int32_t
impl_sidl_rmi_NetworkException_getHopCount(
  /* in */ sidl_rmi_NetworkException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException_packObj(
  /* in */ sidl_rmi_NetworkException self,
  /* in */ sidl_io_Serializer ser,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException_unpackObj(
  /* in */ sidl_rmi_NetworkException self,
  /* in */ sidl_io_Deserializer des,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_rmi_NetworkException_setErrno(
  /* in */ sidl_rmi_NetworkException self,
  /* in */ int32_t err,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidl_rmi_NetworkException_getErrno(
  /* in */ sidl_rmi_NetworkException self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_rmi_NetworkException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_rmi_NetworkException__set_epv(struct sidl_rmi_NetworkException__epv *epv)
{
  epv->f__ctor = impl_sidl_rmi_NetworkException__ctor;
  epv->f__ctor2 = impl_sidl_rmi_NetworkException__ctor2;
  epv->f__dtor = impl_sidl_rmi_NetworkException__dtor;
  epv->f_getHopCount = impl_sidl_rmi_NetworkException_getHopCount;
  epv->f_packObj = impl_sidl_rmi_NetworkException_packObj;
  epv->f_unpackObj = impl_sidl_rmi_NetworkException_unpackObj;
  epv->f_setErrno = impl_sidl_rmi_NetworkException_setErrno;
  epv->f_getErrno = impl_sidl_rmi_NetworkException_getErrno;

  sidl_rmi_NetworkException__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_rmi_NetworkException__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_rmi_NetworkException__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_io_Deserializer__object* 
  skel_sidl_rmi_NetworkException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Deserializer__connectI(url, ar, _ex);
}

struct sidl_io_Serializer__object* 
  skel_sidl_rmi_NetworkException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Serializer__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidl_rmi_NetworkException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_rmi_NetworkException__data*
sidl_rmi_NetworkException__get_data(sidl_rmi_NetworkException self)
{
  return (struct sidl_rmi_NetworkException__data*)(self ? self->d_data : NULL);
}

void sidl_rmi_NetworkException__set_data(
  sidl_rmi_NetworkException self,
  struct sidl_rmi_NetworkException__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
