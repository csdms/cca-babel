/*
 * File:          sidlx_rmi_SimpleTicket_Skel.c
 * Symbol:        sidlx.rmi.SimpleTicket-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side glue code for sidlx.rmi.SimpleTicket
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_SimpleTicket_IOR.h"
#include "sidlx_rmi_SimpleTicket.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_rmi_Response_h
#include "sidl_rmi_Response.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_SimpleTicket__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicket__ctor(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicket__ctor2(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicket__dtor(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_rmi_Response__object* 
  impl_sidlx_rmi_SimpleTicket_fconnect_sidl_rmi_Response(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleTicket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_SimpleTicket_setResponse(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* in */ sidl_rmi_Response r,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicket_block(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleTicket_test(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_TicketBook
impl_sidlx_rmi_SimpleTicket_createEmptyTicketBook(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_Response
impl_sidlx_rmi_SimpleTicket_getResponse(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_rmi_Response__object* 
  impl_sidlx_rmi_SimpleTicket_fconnect_sidl_rmi_Response(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleTicket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimpleTicket__set_epv(struct sidlx_rmi_SimpleTicket__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_SimpleTicket__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_SimpleTicket__ctor2;
  epv->f__dtor = impl_sidlx_rmi_SimpleTicket__dtor;
  epv->f_setResponse = impl_sidlx_rmi_SimpleTicket_setResponse;
  epv->f_block = impl_sidlx_rmi_SimpleTicket_block;
  epv->f_test = impl_sidlx_rmi_SimpleTicket_test;
  epv->f_createEmptyTicketBook = 
    impl_sidlx_rmi_SimpleTicket_createEmptyTicketBook;
  epv->f_getResponse = impl_sidlx_rmi_SimpleTicket_getResponse;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_SimpleTicket__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_SimpleTicket__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_rmi_Response__object* 
  skel_sidlx_rmi_SimpleTicket_fconnect_sidl_rmi_Response(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_rmi_Response__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimpleTicket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_SimpleTicket__data*
sidlx_rmi_SimpleTicket__get_data(sidlx_rmi_SimpleTicket self)
{
  return (struct sidlx_rmi_SimpleTicket__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_SimpleTicket__set_data(
  sidlx_rmi_SimpleTicket self,
  struct sidlx_rmi_SimpleTicket__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
