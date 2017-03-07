/*
 * File:          sidlx_rmi_ChildSocket_Skel.c
 * Symbol:        sidlx.rmi.ChildSocket-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.ChildSocket
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_ChildSocket_IOR.h"
#include "sidlx_rmi_ChildSocket.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_ChildSocket__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ChildSocket__ctor(
  /* in */ sidlx_rmi_ChildSocket self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ChildSocket__ctor2(
  /* in */ sidlx_rmi_ChildSocket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_ChildSocket__dtor(
  /* in */ sidlx_rmi_ChildSocket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ChildSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_ChildSocket_init(
  /* in */ sidlx_rmi_ChildSocket self,
  /* in */ int32_t fileDes,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_ChildSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_ChildSocket__set_epv(struct sidlx_rmi_ChildSocket__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_ChildSocket__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_ChildSocket__ctor2;
  epv->f__dtor = impl_sidlx_rmi_ChildSocket__dtor;
  epv->f_init = impl_sidlx_rmi_ChildSocket_init;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_ChildSocket__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_ChildSocket__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_ChildSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_ChildSocket__data*
sidlx_rmi_ChildSocket__get_data(sidlx_rmi_ChildSocket self)
{
  return (struct sidlx_rmi_ChildSocket__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_ChildSocket__set_data(
  sidlx_rmi_ChildSocket self,
  struct sidlx_rmi_ChildSocket__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
