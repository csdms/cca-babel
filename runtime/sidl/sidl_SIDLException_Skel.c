/*
 * File:          sidl_SIDLException_Skel.c
 * Symbol:        sidl.SIDLException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.SIDLException
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

#include "sidl_SIDLException_IOR.h"
#include "sidl_SIDLException.h"
#include <stddef.h>

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
extern
void
impl_sidl_SIDLException__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException__ctor(
  /* in */ sidl_SIDLException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException__ctor2(
  /* in */ sidl_SIDLException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException__dtor(
  /* in */ sidl_SIDLException self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_SIDLException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_SIDLException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_SIDLException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
char*
impl_sidl_SIDLException_getNote(
  /* in */ sidl_SIDLException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException_setNote(
  /* in */ sidl_SIDLException self,
  /* in */ const char* message,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_SIDLException_getTrace(
  /* in */ sidl_SIDLException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException_addLine(
  /* in */ sidl_SIDLException self,
  /* in */ const char* traceline,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException_add(
  /* in */ sidl_SIDLException self,
  /* in */ const char* filename,
  /* in */ int32_t lineno,
  /* in */ const char* methodname,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException_packObj(
  /* in */ sidl_SIDLException self,
  /* in */ sidl_io_Serializer ser,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_SIDLException_unpackObj(
  /* in */ sidl_SIDLException self,
  /* in */ sidl_io_Deserializer des,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidl_SIDLException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidl_SIDLException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidl_SIDLException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidl_SIDLException__set_epv(struct sidl_SIDLException__epv *epv)
{
  epv->f__ctor = impl_sidl_SIDLException__ctor;
  epv->f__ctor2 = impl_sidl_SIDLException__ctor2;
  epv->f__dtor = impl_sidl_SIDLException__dtor;
  epv->f_getNote = impl_sidl_SIDLException_getNote;
  epv->f_setNote = impl_sidl_SIDLException_setNote;
  epv->f_getTrace = impl_sidl_SIDLException_getTrace;
  epv->f_addLine = impl_sidl_SIDLException_addLine;
  epv->f_add = impl_sidl_SIDLException_add;
  epv->f_packObj = impl_sidl_SIDLException_packObj;
  epv->f_unpackObj = impl_sidl_SIDLException_unpackObj;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_SIDLException__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_SIDLException__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_io_Deserializer__object* 
  skel_sidl_SIDLException_fconnect_sidl_io_Deserializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Deserializer__connectI(url, ar, _ex);
}

struct sidl_io_Serializer__object* 
  skel_sidl_SIDLException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Serializer__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidl_SIDLException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_SIDLException__data*
sidl_SIDLException__get_data(sidl_SIDLException self)
{
  return (struct sidl_SIDLException__data*)(self ? self->d_data : NULL);
}

void sidl_SIDLException__set_data(
  sidl_SIDLException self,
  struct sidl_SIDLException__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
