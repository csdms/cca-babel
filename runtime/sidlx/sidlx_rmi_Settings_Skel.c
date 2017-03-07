/*
 * File:          sidlx_rmi_Settings_Skel.c
 * Symbol:        sidlx.rmi.Settings-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.Settings
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_Settings_IOR.h"
#include "sidlx_rmi_Settings.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_Settings__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings__ctor(
  /* in */ sidlx_rmi_Settings self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings__ctor2(
  /* in */ sidlx_rmi_Settings self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings__dtor(
  /* in */ sidlx_rmi_Settings self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Settings_getMaxAcceptRetries(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings_setMaxAcceptRetries(
  /* in */ int32_t retries,
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Settings_getAcceptRetryInitialSleep(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings_setAcceptRetryInitialSleep(
  /* in */ int64_t usecs,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Settings_getMaxConnectRetries(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings_setMaxConnectRetries(
  /* in */ int32_t retries,
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_Settings_getConnectRetryInitialSleep(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Settings_setConnectRetryInitialSleep(
  /* in */ int64_t usecs,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Settings_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Settings_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Settings__set_epv(struct sidlx_rmi_Settings__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_Settings__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_Settings__ctor2;
  epv->f__dtor = impl_sidlx_rmi_Settings__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Settings__set_sepv(struct sidlx_rmi_Settings__sepv *sepv)
{
  sepv->f_getMaxAcceptRetries = impl_sidlx_rmi_Settings_getMaxAcceptRetries;
  sepv->f_setMaxAcceptRetries = impl_sidlx_rmi_Settings_setMaxAcceptRetries;
  sepv->f_getAcceptRetryInitialSleep = 
    impl_sidlx_rmi_Settings_getAcceptRetryInitialSleep;
  sepv->f_setAcceptRetryInitialSleep = 
    impl_sidlx_rmi_Settings_setAcceptRetryInitialSleep;
  sepv->f_getMaxConnectRetries = impl_sidlx_rmi_Settings_getMaxConnectRetries;
  sepv->f_setMaxConnectRetries = impl_sidlx_rmi_Settings_setMaxConnectRetries;
  sepv->f_getConnectRetryInitialSleep = 
    impl_sidlx_rmi_Settings_getConnectRetryInitialSleep;
  sepv->f_setConnectRetryInitialSleep = 
    impl_sidlx_rmi_Settings_setConnectRetryInitialSleep;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_Settings__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_Settings__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_Settings_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_Settings__data*
sidlx_rmi_Settings__get_data(sidlx_rmi_Settings self)
{
  return (struct sidlx_rmi_Settings__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_Settings__set_data(
  sidlx_rmi_Settings self,
  struct sidlx_rmi_Settings__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
