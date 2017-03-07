/*
 * File:          sidlx_rmi_SimpleOrb_Skel.c
 * Symbol:        sidlx.rmi.SimpleOrb-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.SimpleOrb
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_SimpleOrb_IOR.h"
#include "sidlx_rmi_SimpleOrb.h"
#include <stddef.h>
#include "sidlx_rmi_SimpleOrb_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void sidlx_rmi_SimpleOrb__superEPV(
struct sidlx_rmi_SimpleServer__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct sidlx_rmi_SimpleOrb__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct sidlx_rmi_SimpleOrb__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _externals = sidlx_rmi_SimpleOrb__externals();
#else
  _externals = (struct sidlx_rmi_SimpleOrb__external*)sidl_dynamicLoadIOR(
    "sidlx.rmi.SimpleOrb","sidlx_rmi_SimpleOrb__externals") ;
  sidl_checkIORVersion("sidlx.rmi.SimpleOrb", _externals->d_ior_major_version, 
    _externals->d_ior_minor_version, 2, 0);
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
extern void sidlx_rmi_SimpleOrb__superEPV(
struct sidlx_rmi_SimpleServer__epv*);

extern
void
impl_sidlx_rmi_SimpleOrb__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleOrb__ctor(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleOrb__ctor2(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleOrb__dtor(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleOrb_fconnect_sidlx_rmi_Socket(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleOrb_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_SimpleOrb_setCookie(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in rarray[len] */ char* cookie,
  /* in */ int32_t len,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleOrb_setNumSecurityRetries(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ int32_t retries,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleOrb_serviceRequest(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ sidlx_rmi_Socket sock,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleOrb_getServerURL(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleOrb_isLocalObject(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleOrb_getProtocol(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex);

extern
struct sidl_io_Serializable__array*
impl_sidlx_rmi_SimpleOrb_getExceptions(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleOrb_fconnect_sidlx_rmi_Socket(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleOrb_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
static void
skel_sidlx_rmi_SimpleOrb_setCookie(
  /* in */ struct sidlx_rmi_SimpleOrb__object*self,
  /* in rarray[len] */ struct sidl_char__array* cookie,
/* out */ struct sidl_BaseInterface__object **_ex)
{
  struct sidl_char__array* cookie_proxy = sidl_char__array_ensure(cookie, 1, 
    sidl_column_major_order);
  char* cookie_tmp = cookie_proxy->d_firstElement;
  int32_t len = sidlLength(cookie_proxy,0);
  impl_sidlx_rmi_SimpleOrb_setCookie(
    self,
    cookie_tmp,
    len,
    _ex);
  sidl_char__array_deleteRef(cookie_proxy);
}

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimpleOrb__set_epv(struct sidlx_rmi_SimpleOrb__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_SimpleOrb__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_SimpleOrb__ctor2;
  epv->f__dtor = impl_sidlx_rmi_SimpleOrb__dtor;
  epv->f_setCookie = skel_sidlx_rmi_SimpleOrb_setCookie;
  epv->f_setNumSecurityRetries = impl_sidlx_rmi_SimpleOrb_setNumSecurityRetries;
  epv->f_serviceRequest = impl_sidlx_rmi_SimpleOrb_serviceRequest;
  epv->f_getServerURL = impl_sidlx_rmi_SimpleOrb_getServerURL;
  epv->f_isLocalObject = impl_sidlx_rmi_SimpleOrb_isLocalObject;
  epv->f_getProtocol = impl_sidlx_rmi_SimpleOrb_getProtocol;
  epv->f_getExceptions = impl_sidlx_rmi_SimpleOrb_getExceptions;

  sidlx_rmi_SimpleOrb__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_SimpleOrb__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_SimpleOrb__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_SimpleOrb_fconnect_sidlx_rmi_Socket(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return sidlx_rmi_Socket__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimpleOrb_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_SimpleOrb__data*
sidlx_rmi_SimpleOrb__get_data(sidlx_rmi_SimpleOrb self)
{
  return (struct sidlx_rmi_SimpleOrb__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_SimpleOrb__set_data(
  sidlx_rmi_SimpleOrb self,
  struct sidlx_rmi_SimpleOrb__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
