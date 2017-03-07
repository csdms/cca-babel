/*
 * File:          sidlx_rmi_SimHandle_Skel.c
 * Symbol:        sidlx.rmi.SimHandle-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.SimHandle
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_SimHandle_IOR.h"
#include "sidlx_rmi_SimHandle.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_SimHandle__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimHandle__ctor(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimHandle__ctor2(
  /* in */ sidlx_rmi_SimHandle self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimHandle__dtor(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimHandle_setCookie(
  /* in rarray[len] */ char* cookie,
  /* in */ int32_t len,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimHandle_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
sidl_bool
impl_sidlx_rmi_SimHandle_initCreate(
  /* in */ sidlx_rmi_SimHandle self,
  /* in */ const char* url,
  /* in */ const char* typeName,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimHandle_initConnect(
  /* in */ sidlx_rmi_SimHandle self,
  /* in */ const char* url,
  /* in */ const char* typeName,
  /* in */ sidl_bool ar,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_io_Serializable
impl_sidlx_rmi_SimHandle_initUnserialize(
  /* in */ sidlx_rmi_SimHandle self,
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimHandle_getProtocol(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimHandle_getObjectID(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimHandle_getObjectURL(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_Invocation
impl_sidlx_rmi_SimHandle_createInvocation(
  /* in */ sidlx_rmi_SimHandle self,
  /* in */ const char* methodName,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimHandle_close(
  /* in */ sidlx_rmi_SimHandle self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimHandle_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
static void
skel_sidlx_rmi_SimHandle_setCookie(
  /* in rarray[len] */ struct sidl_char__array* cookie,
/* out */ struct sidl_BaseInterface__object **_ex)
{
  struct sidl_char__array* cookie_proxy = sidl_char__array_ensure(cookie, 1, 
    sidl_column_major_order);
  char* cookie_tmp = cookie_proxy->d_firstElement;
  int32_t len = sidlLength(cookie_proxy,0);
  impl_sidlx_rmi_SimHandle_setCookie(
    cookie_tmp,
    len,
    _ex);
  sidl_char__array_deleteRef(cookie_proxy);
}

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimHandle__set_epv(struct sidlx_rmi_SimHandle__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_SimHandle__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_SimHandle__ctor2;
  epv->f__dtor = impl_sidlx_rmi_SimHandle__dtor;
  epv->f_initCreate = impl_sidlx_rmi_SimHandle_initCreate;
  epv->f_initConnect = impl_sidlx_rmi_SimHandle_initConnect;
  epv->f_initUnserialize = impl_sidlx_rmi_SimHandle_initUnserialize;
  epv->f_getProtocol = impl_sidlx_rmi_SimHandle_getProtocol;
  epv->f_getObjectID = impl_sidlx_rmi_SimHandle_getObjectID;
  epv->f_getObjectURL = impl_sidlx_rmi_SimHandle_getObjectURL;
  epv->f_createInvocation = impl_sidlx_rmi_SimHandle_createInvocation;
  epv->f_close = impl_sidlx_rmi_SimHandle_close;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimHandle__set_sepv(struct sidlx_rmi_SimHandle__sepv *sepv)
{
  sepv->f_setCookie = skel_sidlx_rmi_SimHandle_setCookie;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_SimHandle__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_SimHandle__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimHandle_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_SimHandle__data*
sidlx_rmi_SimHandle__get_data(sidlx_rmi_SimHandle self)
{
  return (struct sidlx_rmi_SimHandle__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_SimHandle__set_data(
  sidlx_rmi_SimHandle self,
  struct sidlx_rmi_SimHandle__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
