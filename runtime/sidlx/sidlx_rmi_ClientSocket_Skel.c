/*
 * File:          sidlx_rmi_ClientSocket_Skel.c
 * Symbol:        sidlx.rmi.ClientSocket-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.ClientSocket
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_ClientSocket_IOR.h"
#include "sidlx_rmi_ClientSocket.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_ClientSocket__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ClientSocket__ctor(
  /* in */ sidlx_rmi_ClientSocket self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ClientSocket__ctor2(
  /* in */ sidlx_rmi_ClientSocket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ClientSocket__dtor(
  /* in */ sidlx_rmi_ClientSocket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ClientSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
int32_t
impl_sidlx_rmi_ClientSocket_init(
  /* in */ sidlx_rmi_ClientSocket self,
  /* in */ int32_t IP,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ClientSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_ClientSocket__set_epv(struct sidlx_rmi_ClientSocket__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_ClientSocket__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_ClientSocket__ctor2;
  epv->f__dtor = impl_sidlx_rmi_ClientSocket__dtor;
  epv->f_init = impl_sidlx_rmi_ClientSocket_init;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_ClientSocket__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_ClientSocket__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_ClientSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_ClientSocket__data*
sidlx_rmi_ClientSocket__get_data(sidlx_rmi_ClientSocket self)
{
  return (struct sidlx_rmi_ClientSocket__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_ClientSocket__set_data(
  sidlx_rmi_ClientSocket self,
  struct sidlx_rmi_ClientSocket__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
