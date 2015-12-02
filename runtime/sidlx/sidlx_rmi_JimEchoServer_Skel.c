/*
 * File:          sidlx_rmi_JimEchoServer_Skel.c
 * Symbol:        sidlx.rmi.JimEchoServer-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.JimEchoServer
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_JimEchoServer_IOR.h"
#include "sidlx_rmi_JimEchoServer.h"
#include <stddef.h>
#include "sidlx_rmi_JimEchoServer_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void sidlx_rmi_JimEchoServer__superEPV(
struct sidlx_rmi_SimpleServer__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct sidlx_rmi_JimEchoServer__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct sidlx_rmi_JimEchoServer__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _externals = sidlx_rmi_JimEchoServer__externals();
#else
  _externals = (struct sidlx_rmi_JimEchoServer__external*)sidl_dynamicLoadIOR(
    "sidlx.rmi.JimEchoServer","sidlx_rmi_JimEchoServer__externals") ;
  sidl_checkIORVersion("sidlx.rmi.JimEchoServer", 
    _externals->d_ior_major_version, _externals->d_ior_minor_version, 2, 0);
#endif
  return _externals;
}

#define _getExternals() (_externals ? _externals : _loadIOR())


#ifdef WITH_RMI
#ifndef included_sidlx_rmi_Socket_h
#include "sidlx_rmi_Socket.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern void sidlx_rmi_JimEchoServer__superEPV(
struct sidlx_rmi_SimpleServer__epv*);

extern
void
impl_sidlx_rmi_JimEchoServer__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_JimEchoServer__ctor(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_JimEchoServer__ctor2(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_JimEchoServer__dtor(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_JimEchoServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_JimEchoServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_JimEchoServer_serviceRequest(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* in */ sidlx_rmi_Socket sock,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_JimEchoServer_getServerURL(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_JimEchoServer_isLocalObject(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex);

extern
struct sidl_io_Serializable__array*
impl_sidlx_rmi_JimEchoServer_getExceptions(
  /* in */ sidlx_rmi_JimEchoServer self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_JimEchoServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_JimEchoServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_JimEchoServer__set_epv(struct sidlx_rmi_JimEchoServer__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_JimEchoServer__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_JimEchoServer__ctor2;
  epv->f__dtor = impl_sidlx_rmi_JimEchoServer__dtor;
  epv->f_serviceRequest = impl_sidlx_rmi_JimEchoServer_serviceRequest;
  epv->f_getServerURL = impl_sidlx_rmi_JimEchoServer_getServerURL;
  epv->f_isLocalObject = impl_sidlx_rmi_JimEchoServer_isLocalObject;
  epv->f_getExceptions = impl_sidlx_rmi_JimEchoServer_getExceptions;

  sidlx_rmi_JimEchoServer__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_JimEchoServer__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_JimEchoServer__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_JimEchoServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidlx_rmi_Socket__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_JimEchoServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_JimEchoServer__data*
sidlx_rmi_JimEchoServer__get_data(sidlx_rmi_JimEchoServer self)
{
  return (struct sidlx_rmi_JimEchoServer__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_JimEchoServer__set_data(
  sidlx_rmi_JimEchoServer self,
  struct sidlx_rmi_JimEchoServer__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
