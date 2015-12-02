/*
 * File:          sidlx_rmi_Statistics_Skel.c
 * Symbol:        sidlx.rmi.Statistics-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.Statistics
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_Statistics_IOR.h"
#include "sidlx_rmi_Statistics.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_Statistics__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Statistics__ctor(
  /* in */ sidlx_rmi_Statistics self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Statistics__ctor2(
  /* in */ sidlx_rmi_Statistics self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Statistics__dtor(
  /* in */ sidlx_rmi_Statistics self,
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalAcceptsFirstTry(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalAcceptRequests(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalAcceptSucceded(
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Statistics_getMaxAcceptRetries(
  /* out */ sidl_BaseInterface *_ex);

extern
double
impl_sidlx_rmi_Statistics_getAvgAcceptRetries(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalConnectsFirstTry(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalConnectRequests(
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Statistics_getTotalConnectSucceded(
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Statistics_getMaxConnectRetries(
  /* out */ sidl_BaseInterface *_ex);

extern
double
impl_sidlx_rmi_Statistics_getAvgConnectRetries(
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Statistics_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Statistics_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Statistics__set_epv(struct sidlx_rmi_Statistics__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_Statistics__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_Statistics__ctor2;
  epv->f__dtor = impl_sidlx_rmi_Statistics__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Statistics__set_sepv(struct sidlx_rmi_Statistics__sepv *sepv)
{
  sepv->f_getTotalAcceptsFirstTry = 
    impl_sidlx_rmi_Statistics_getTotalAcceptsFirstTry;
  sepv->f_getTotalAcceptRequests = 
    impl_sidlx_rmi_Statistics_getTotalAcceptRequests;
  sepv->f_getTotalAcceptSucceded = 
    impl_sidlx_rmi_Statistics_getTotalAcceptSucceded;
  sepv->f_getMaxAcceptRetries = impl_sidlx_rmi_Statistics_getMaxAcceptRetries;
  sepv->f_getAvgAcceptRetries = impl_sidlx_rmi_Statistics_getAvgAcceptRetries;
  sepv->f_getTotalConnectsFirstTry = 
    impl_sidlx_rmi_Statistics_getTotalConnectsFirstTry;
  sepv->f_getTotalConnectRequests = 
    impl_sidlx_rmi_Statistics_getTotalConnectRequests;
  sepv->f_getTotalConnectSucceded = 
    impl_sidlx_rmi_Statistics_getTotalConnectSucceded;
  sepv->f_getMaxConnectRetries = impl_sidlx_rmi_Statistics_getMaxConnectRetries;
  sepv->f_getAvgConnectRetries = impl_sidlx_rmi_Statistics_getAvgConnectRetries;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_Statistics__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_Statistics__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_Statistics_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_Statistics__data*
sidlx_rmi_Statistics__get_data(sidlx_rmi_Statistics self)
{
  return (struct sidlx_rmi_Statistics__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_Statistics__set_data(
  sidlx_rmi_Statistics self,
  struct sidlx_rmi_Statistics__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
