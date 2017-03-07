/*
 * File:          sidlx_rmi_SimpleServer_Skel.c
 * Symbol:        sidlx.rmi.SimpleServer-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.SimpleServer
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_SimpleServer_IOR.h"
#include "sidlx_rmi_SimpleServer.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidlx_rmi_Socket_h
#include "sidlx_rmi_Socket.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_SimpleServer__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__ctor(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__ctor2(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__dtor(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_SimpleServer_setMaxThreadPool(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t max,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestPort(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestPortInRange(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t minport,
  /* in */ int32_t maxport,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestLocalPort(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestLocalPortInRange(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t minport,
  /* in */ int32_t maxport,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_SimpleServer_getPort(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleServer_getServerName(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleServer_getServerURL(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_SimpleServer_run(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer_shutdown(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer_shutdownNoWait(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_isRunning(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimpleServer__set_epv(struct sidlx_rmi_SimpleServer__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_SimpleServer__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_SimpleServer__ctor2;
  epv->f__dtor = impl_sidlx_rmi_SimpleServer__dtor;
  epv->f_setMaxThreadPool = impl_sidlx_rmi_SimpleServer_setMaxThreadPool;
  epv->f_requestPort = impl_sidlx_rmi_SimpleServer_requestPort;
  epv->f_requestPortInRange = impl_sidlx_rmi_SimpleServer_requestPortInRange;
  epv->f_requestLocalPort = impl_sidlx_rmi_SimpleServer_requestLocalPort;
  epv->f_requestLocalPortInRange = 
    impl_sidlx_rmi_SimpleServer_requestLocalPortInRange;
  epv->f_getPort = impl_sidlx_rmi_SimpleServer_getPort;
  epv->f_getServerName = impl_sidlx_rmi_SimpleServer_getServerName;
  epv->f_getServerURL = impl_sidlx_rmi_SimpleServer_getServerURL;
  epv->f_run = impl_sidlx_rmi_SimpleServer_run;
  epv->f_shutdown = impl_sidlx_rmi_SimpleServer_shutdown;
  epv->f_shutdownNoWait = impl_sidlx_rmi_SimpleServer_shutdownNoWait;
  epv->f_isRunning = impl_sidlx_rmi_SimpleServer_isRunning;
  epv->f_serviceRequest = NULL;
  epv->f_getExceptions = NULL;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_SimpleServer__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_SimpleServer__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_SimpleServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidlx_rmi_Socket__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimpleServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_SimpleServer__data*
sidlx_rmi_SimpleServer__get_data(sidlx_rmi_SimpleServer self)
{
  return (struct sidlx_rmi_SimpleServer__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_SimpleServer__set_data(
  sidlx_rmi_SimpleServer self,
  struct sidlx_rmi_SimpleServer__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
