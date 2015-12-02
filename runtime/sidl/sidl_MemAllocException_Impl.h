/*
 * File:          sidl_MemAllocException_Impl.h
 * Symbol:        sidl.MemAllocException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side implementation for sidl.MemAllocException
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

#ifndef included_sidl_MemAllocException_Impl_h
#define included_sidl_MemAllocException_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_sidl_MemAllocException_IOR_h
#include "sidl_MemAllocException_IOR.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseException_h
#include "sidl_BaseException.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
#ifndef included_sidl_SIDLException_h
#include "sidl_SIDLException.h"
#endif
#ifndef included_sidl_io_Deserializer_h
#include "sidl_io_Deserializer.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#ifndef included_sidl_io_Serializer_h
#include "sidl_io_Serializer.h"
#endif
/* DO-NOT-DELETE splicer.begin(sidl.MemAllocException._hincludes) */
#define MESSAGE_SIZE 256
#define TRACE_SIZE 2048
/* DO-NOT-DELETE splicer.end(sidl.MemAllocException._hincludes) */

/*
 * Private data for class sidl.MemAllocException
 */

struct sidl_MemAllocException__data {
  /* DO-NOT-DELETE splicer.begin(sidl.MemAllocException._data) */
  char d_message[MESSAGE_SIZE];
  char d_trace[TRACE_SIZE];
  unsigned long int d_trace_length;
  /* DO-NOT-DELETE splicer.end(sidl.MemAllocException._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sidl_MemAllocException__data*
sidl_MemAllocException__get_data(
  sidl_MemAllocException);

extern void
sidl_MemAllocException__set_data(
  sidl_MemAllocException,
  struct sidl_MemAllocException__data*);

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

/*
 * User-defined object methods
 */

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

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
