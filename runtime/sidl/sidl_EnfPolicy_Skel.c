/*
 * File:          sidl_EnfPolicy_Skel.c
 * Symbol:        sidl.EnfPolicy-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side glue code for sidl.EnfPolicy
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

#include "sidl_EnfPolicy_IOR.h"
#include "sidl_EnfPolicy.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidl_EnfPolicy__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy__ctor(
  /* in */ sidl_EnfPolicy self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy__ctor2(
  /* in */ sidl_EnfPolicy self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy__dtor(
  /* in */ sidl_EnfPolicy self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_setEnforceAll(
  /* in */ enum sidl_ContractClass__enum contractClass,
  /* in */ sidl_bool clearStats,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_setEnforceNone(
  /* in */ sidl_bool clearStats,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_setPolicy(
  /* in */ enum sidl_ContractClass__enum contractClass,
  /* in */ enum sidl_EnforceFreq__enum enforceFreq,
  /* in */ int32_t interval,
  /* in */ double overheadLimit,
  /* in */ double appAvgPerCall,
  /* in */ double annealLimit,
  /* in */ sidl_bool clearStats,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidl_EnfPolicy_areEnforcing(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidl_EnfPolicy_getContractClass(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidl_EnfPolicy_getEnforceFreq(
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidl_EnfPolicy_getSamplingInterval(
  /* out */ sidl_BaseInterface *_ex);

extern
double
impl_sidl_EnfPolicy_getOverheadLimit(
  /* out */ sidl_BaseInterface *_ex);

extern
double
impl_sidl_EnfPolicy_getAppAvgPerCall(
  /* out */ sidl_BaseInterface *_ex);

extern
double
impl_sidl_EnfPolicy_getAnnealLimit(
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_EnfPolicy_getPolicyName(
  /* in */ sidl_bool useAbbrev,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_dumpStats(
  /* in */ const char* filename,
  /* in */ sidl_bool header,
  /* in */ const char* prefix,
  /* in */ sidl_bool compressed,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_startTrace(
  /* in */ const char* filename,
  /* in */ enum sidl_EnfTraceLevel__enum traceLevel,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidl_EnfPolicy_areTracing(
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidl_EnfPolicy_getTraceFilename(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidl_EnfPolicy_getTraceLevel(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidl_EnfPolicy_endTrace(
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_EnfPolicy_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidl_EnfPolicy_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
static void
skel_sidl_EnfPolicy_setEnforceAll(
  /* in */ int64_t contractClass,
  /* in */ sidl_bool clearStats,
/* out */ struct sidl_BaseInterface__object **_ex)
{
  impl_sidl_EnfPolicy_setEnforceAll(
    contractClass,
    clearStats,
    _ex);
}

static void
skel_sidl_EnfPolicy_setPolicy(
  /* in */ int64_t contractClass,
  /* in */ int64_t enforceFreq,
  /* in */ int32_t interval,
  /* in */ double overheadLimit,
  /* in */ double appAvgPerCall,
  /* in */ double annealLimit,
  /* in */ sidl_bool clearStats,
/* out */ struct sidl_BaseInterface__object **_ex)
{
  impl_sidl_EnfPolicy_setPolicy(
    contractClass,
    enforceFreq,
    interval,
    overheadLimit,
    appAvgPerCall,
    annealLimit,
    clearStats,
    _ex);
}

static int64_t
skel_sidl_EnfPolicy_getContractClass(
/* out */ struct sidl_BaseInterface__object **_ex)
{
  int64_t _return;
  _return =
    impl_sidl_EnfPolicy_getContractClass(
      _ex);
  return _return;
}

static int64_t
skel_sidl_EnfPolicy_getEnforceFreq(
/* out */ struct sidl_BaseInterface__object **_ex)
{
  int64_t _return;
  _return =
    impl_sidl_EnfPolicy_getEnforceFreq(
      _ex);
  return _return;
}

static void
skel_sidl_EnfPolicy_startTrace(
  /* in */ const char* filename,
  /* in */ int64_t traceLevel,
/* out */ struct sidl_BaseInterface__object **_ex)
{
  impl_sidl_EnfPolicy_startTrace(
    filename,
    traceLevel,
    _ex);
}

static int64_t
skel_sidl_EnfPolicy_getTraceLevel(
/* out */ struct sidl_BaseInterface__object **_ex)
{
  int64_t _return;
  _return =
    impl_sidl_EnfPolicy_getTraceLevel(
      _ex);
  return _return;
}

#ifdef __cplusplus
extern "C" {
#endif

void
sidl_EnfPolicy__set_epv(struct sidl_EnfPolicy__epv *epv)
{
  epv->f__ctor = impl_sidl_EnfPolicy__ctor;
  epv->f__ctor2 = impl_sidl_EnfPolicy__ctor2;
  epv->f__dtor = impl_sidl_EnfPolicy__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidl_EnfPolicy__set_sepv(struct sidl_EnfPolicy__sepv *sepv)
{
  sepv->f_setEnforceAll = skel_sidl_EnfPolicy_setEnforceAll;
  sepv->f_setEnforceNone = impl_sidl_EnfPolicy_setEnforceNone;
  sepv->f_setPolicy = skel_sidl_EnfPolicy_setPolicy;
  sepv->f_areEnforcing = impl_sidl_EnfPolicy_areEnforcing;
  sepv->f_getContractClass = skel_sidl_EnfPolicy_getContractClass;
  sepv->f_getEnforceFreq = skel_sidl_EnfPolicy_getEnforceFreq;
  sepv->f_getSamplingInterval = impl_sidl_EnfPolicy_getSamplingInterval;
  sepv->f_getOverheadLimit = impl_sidl_EnfPolicy_getOverheadLimit;
  sepv->f_getAppAvgPerCall = impl_sidl_EnfPolicy_getAppAvgPerCall;
  sepv->f_getAnnealLimit = impl_sidl_EnfPolicy_getAnnealLimit;
  sepv->f_getPolicyName = impl_sidl_EnfPolicy_getPolicyName;
  sepv->f_dumpStats = impl_sidl_EnfPolicy_dumpStats;
  sepv->f_startTrace = skel_sidl_EnfPolicy_startTrace;
  sepv->f_areTracing = impl_sidl_EnfPolicy_areTracing;
  sepv->f_getTraceFilename = impl_sidl_EnfPolicy_getTraceFilename;
  sepv->f_getTraceLevel = skel_sidl_EnfPolicy_getTraceLevel;
  sepv->f_endTrace = impl_sidl_EnfPolicy_endTrace;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidl_EnfPolicy__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidl_EnfPolicy__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidl_EnfPolicy_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidl_EnfPolicy__data*
sidl_EnfPolicy__get_data(sidl_EnfPolicy self)
{
  return (struct sidl_EnfPolicy__data*)(self ? self->d_data : NULL);
}

void sidl_EnfPolicy__set_data(
  sidl_EnfPolicy self,
  struct sidl_EnfPolicy__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
