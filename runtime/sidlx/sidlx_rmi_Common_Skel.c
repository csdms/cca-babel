/*
 * File:          sidlx_rmi_Common_Skel.c
 * Symbol:        sidlx.rmi.Common-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.Common
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_Common_IOR.h"
#include "sidlx_rmi_Common.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_Common__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Common__ctor(
  /* in */ sidlx_rmi_Common self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Common__ctor2(
  /* in */ sidlx_rmi_Common self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_Common__dtor(
  /* in */ sidlx_rmi_Common self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Common_fork(
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_Common_getHostIP(
  /* in */ const char* hostname,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_Common_getCanonicalName(
  /* in */ const char* hostname,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Common_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_Common_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Common__set_epv(struct sidlx_rmi_Common__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_Common__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_Common__ctor2;
  epv->f__dtor = impl_sidlx_rmi_Common__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_Common__set_sepv(struct sidlx_rmi_Common__sepv *sepv)
{
  sepv->f_fork = impl_sidlx_rmi_Common_fork;
  sepv->f_getHostIP = impl_sidlx_rmi_Common_getHostIP;
  sepv->f_getCanonicalName = impl_sidlx_rmi_Common_getCanonicalName;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_Common__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_Common__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_Common_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_Common__data*
sidlx_rmi_Common__get_data(sidlx_rmi_Common self)
{
  return (struct sidlx_rmi_Common__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_Common__set_data(
  sidlx_rmi_Common self,
  struct sidlx_rmi_Common__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif