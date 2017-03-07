/*
 * File:          sidlx_rmi_ServerSocket_Skel.c
 * Symbol:        sidlx.rmi.ServerSocket-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.ServerSocket
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_ServerSocket_IOR.h"
#include "sidlx_rmi_ServerSocket.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_ServerSocket__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ServerSocket__ctor(
  /* in */ sidlx_rmi_ServerSocket self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ServerSocket__ctor2(
  /* in */ sidlx_rmi_ServerSocket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ServerSocket__dtor(
  /* in */ sidlx_rmi_ServerSocket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ServerSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
int32_t
impl_sidlx_rmi_ServerSocket_init(
  /* in */ sidlx_rmi_ServerSocket self,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_ServerSocket_initLocal(
  /* in */ sidlx_rmi_ServerSocket self,
  /* in */ int32_t port,
  /* in */ sidl_bool loopback,
  /* out */ sidl_BaseInterface *_ex);

extern
sidlx_rmi_Socket
impl_sidlx_rmi_ServerSocket_accept(
  /* in */ sidlx_rmi_ServerSocket self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_ServerSocket_close(
  /* in */ sidlx_rmi_ServerSocket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ServerSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_ServerSocket__set_epv(struct sidlx_rmi_ServerSocket__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_ServerSocket__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_ServerSocket__ctor2;
  epv->f__dtor = impl_sidlx_rmi_ServerSocket__dtor;
  epv->f_init = impl_sidlx_rmi_ServerSocket_init;
  epv->f_initLocal = impl_sidlx_rmi_ServerSocket_initLocal;
  epv->f_accept = impl_sidlx_rmi_ServerSocket_accept;
  epv->f_close = impl_sidlx_rmi_ServerSocket_close;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_ServerSocket__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_ServerSocket__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_ServerSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_ServerSocket__data*
sidlx_rmi_ServerSocket__get_data(sidlx_rmi_ServerSocket self)
{
  return (struct sidlx_rmi_ServerSocket__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_ServerSocket__set_data(
  sidlx_rmi_ServerSocket self,
  struct sidlx_rmi_ServerSocket__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
