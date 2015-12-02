/*
 * File:          sidlx_rmi_SimpleTicketBook_Skel.c
 * Symbol:        sidlx.rmi.SimpleTicketBook-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.SimpleTicketBook
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_SimpleTicketBook_IOR.h"
#include "sidlx_rmi_SimpleTicketBook.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_rmi_Ticket_h
#include "sidl_rmi_Ticket.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_SimpleTicketBook__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicketBook__ctor(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicketBook__ctor2(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicketBook__dtor(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_rmi_Ticket__object* 
  impl_sidlx_rmi_SimpleTicketBook_fconnect_sidl_rmi_Ticket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleTicketBook_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_SimpleTicketBook_insertWithID(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* in */ sidl_rmi_Ticket t,
  /* in */ int32_t id,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_SimpleTicketBook_insert(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* in */ sidl_rmi_Ticket t,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_SimpleTicketBook_removeReady(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_rmi_Ticket* t,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleTicketBook_isEmpty(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleTicketBook_block(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleTicketBook_test(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_TicketBook
impl_sidlx_rmi_SimpleTicketBook_createEmptyTicketBook(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_rmi_Response
impl_sidlx_rmi_SimpleTicketBook_getResponse(
  /* in */ sidlx_rmi_SimpleTicketBook self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_rmi_Ticket__object* 
  impl_sidlx_rmi_SimpleTicketBook_fconnect_sidl_rmi_Ticket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleTicketBook_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_SimpleTicketBook__set_epv(struct sidlx_rmi_SimpleTicketBook__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_SimpleTicketBook__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_SimpleTicketBook__ctor2;
  epv->f__dtor = impl_sidlx_rmi_SimpleTicketBook__dtor;
  epv->f_insertWithID = impl_sidlx_rmi_SimpleTicketBook_insertWithID;
  epv->f_insert = impl_sidlx_rmi_SimpleTicketBook_insert;
  epv->f_removeReady = impl_sidlx_rmi_SimpleTicketBook_removeReady;
  epv->f_isEmpty = impl_sidlx_rmi_SimpleTicketBook_isEmpty;
  epv->f_block = impl_sidlx_rmi_SimpleTicketBook_block;
  epv->f_test = impl_sidlx_rmi_SimpleTicketBook_test;
  epv->f_createEmptyTicketBook = 
    impl_sidlx_rmi_SimpleTicketBook_createEmptyTicketBook;
  epv->f_getResponse = impl_sidlx_rmi_SimpleTicketBook_getResponse;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_SimpleTicketBook__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_SimpleTicketBook__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_rmi_Ticket__object* 
  skel_sidlx_rmi_SimpleTicketBook_fconnect_sidl_rmi_Ticket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_rmi_Ticket__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimpleTicketBook_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_SimpleTicketBook__data*
sidlx_rmi_SimpleTicketBook__get_data(sidlx_rmi_SimpleTicketBook self)
{
  return (struct sidlx_rmi_SimpleTicketBook__data*)(self ? self->d_data : NULL);
}

void sidlx_rmi_SimpleTicketBook__set_data(
  sidlx_rmi_SimpleTicketBook self,
  struct sidlx_rmi_SimpleTicketBook__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
