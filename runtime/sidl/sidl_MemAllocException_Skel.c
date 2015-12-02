/*
 * File:          sidl_MemAllocException_Skel.c
 * Symbol:        sidl.MemAllocException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.MemAllocException
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
 * 
 */

#include "sidl_MemAllocException_IOR.h"
#include "sidl_MemAllocException.h"
#include <stddef.h>
#include "sidl_MemAllocException_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void sidl_MemAllocException__superEPV(
struct sidl_SIDLException__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct sidl_MemAllocException__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct sidl_MemAllocException__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
  _externals = sidl_MemAllocException__externals();
  return _externals;
}

#define _getExternals() (_externals ? _externals : _loadIOR())


#ifdef WITH_RMI
#ifndef included_sidl_io_Deserializer_h
#include "sidl_io_Deserializer.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_io_Serializer_h
#include "sidl_io_Serializer.h"
#endif
#endif /* WITH_RMI */
extern void sidl_MemAllocException__superEPV(
struct sidl_SIDLException__epv*);

extern
void
impl_sidl_MemAllocException__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException__ctor(
  /* in */ sidl_MemAllocException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException__ctor2(
  /* in */ sidl_MemAllocException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException__dtor(
  /* in */ sidl_MemAllocException self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_MemAllocException
impl_sidl_MemAllocException_getSingletonException(
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_MemAllocException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_MemAllocException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_MemAllocException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
char*
impl_sidl_MemAllocException_getNote(
  /* in */ sidl_MemAllocException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException_setNote(
  /* in */ sidl_MemAllocException self,
  /* in */ const char* message,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_MemAllocException_getTrace(
  /* in */ sidl_MemAllocException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException_addLine(
  /* in */ sidl_MemAllocException self,
  /* in */ const char* traceline,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_MemAllocException_add(
  /* in */ sidl_MemAllocException self,
  /* in */ const char* filename,
  /* in */ int32_t lineno,
  /* in */ const char* methodname,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_MemAllocException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_MemAllocException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_MemAllocException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_MemAllocException__set_epv(struct sidl_MemAllocException__epv *epv)
{
  epv->f__ctor = impl_sidl_MemAllocException__ctor;
  epv->f__ctor2 = impl_sidl_MemAllocException__ctor2;
  epv->f__dtor = impl_sidl_MemAllocException__dtor;
  epv->f_getNote = impl_sidl_MemAllocException_getNote;
  epv->f_setNote = impl_sidl_MemAllocException_setNote;
  epv->f_getTrace = impl_sidl_MemAllocException_getTrace;
  epv->f_addLine = impl_sidl_MemAllocException_addLine;
  epv->f_add = impl_sidl_MemAllocException_add;

  sidl_MemAllocException__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidl_MemAllocException__set_sepv(struct sidl_MemAllocException__sepv *sepv)
{
  sepv->f_getSingletonException = 
    impl_sidl_MemAllocException_getSingletonException;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_MemAllocException__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_MemAllocException__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_io_Deserializer__object* 
  skel_sidl_MemAllocException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Deserializer__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidl_MemAllocException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

struct sidl_io_Serializer__object* 
  skel_sidl_MemAllocException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Serializer__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_MemAllocException__data*
sidl_MemAllocException__get_data(sidl_MemAllocException self)
{
  return (struct sidl_MemAllocException__data*)(self ? self->d_data : NULL);
}

void sidl_MemAllocException__set_data(
  sidl_MemAllocException self,
  struct sidl_MemAllocException__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
