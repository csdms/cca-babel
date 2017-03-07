/*
 * File:          sidlx_rmi_SimpleTicket_Impl.c
 * Symbol:        sidlx.rmi.SimpleTicket-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sidlx.rmi.SimpleTicket
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidlx.rmi.SimpleTicket" (version 0.1)
 * 
 * implementation of a Ticket 
 */

#include "sidlx_rmi_SimpleTicket_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket._includes) */
#include <stdlib.h>
#include <stdio.h>
#include "sidlx_rmi_SimpleTicketBook.h"
#include "sidl_Exception.h"
#include "sidl_rmi_TimeOutException.h"
#include "sidl_MemAllocException.h"
/* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket._load) */
  /* Insert-Code-Here {sidlx.rmi.SimpleTicket._load} (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket__ctor(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket._ctor) */
  struct sidlx_rmi_SimpleTicket__data *dptr = malloc(sizeof(struct sidlx_rmi_SimpleTicket__data));
  if(NULL == dptr) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.SimpleTicket._ctor", _ex);
    *_ex = (sidl_BaseInterface)ex;
    goto EXIT;
  }
  dptr->d_response = NULL;
  sidlx_rmi_SimpleTicket__set_data(self, dptr);
  EXIT:
  return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket__ctor2(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket._ctor2) */
  /* Insert-Code-Here {sidlx.rmi.SimpleTicket._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket__dtor(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket._dtor) */
  struct sidlx_rmi_SimpleTicket__data *dptr = 
    sidlx_rmi_SimpleTicket__get_data(self);
  if ( dptr->d_response != NULL ) { 
    sidlx_rmi_Simsponse_deleteRef(dptr->d_response,_ex); SIDL_CHECK(*_ex);
    dptr->d_response=NULL;
  }
  free(dptr);
  sidlx_rmi_SimpleTicket__set_data(self, NULL);  
 EXIT:
  return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket._dtor) */
  }
}

/*
 * Method:  setResponse[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket_setResponse"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket_setResponse(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* in */ sidl_rmi_Response r,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket.setResponse) */
  struct sidlx_rmi_SimpleTicket__data *dptr = 
    sidlx_rmi_SimpleTicket__get_data(self);
  sidlx_rmi_Simsponse sr = sidlx_rmi_Simsponse__cast(r,_ex); SIDL_CHECK(*_ex);
  sidl_rmi_Response_deleteRef(r,_ex); SIDL_CHECK(*_ex);
  if ( sr != dptr->d_response ) { 
    if ( dptr->d_response != NULL ) { 
      sidlx_rmi_Simsponse_deleteRef( dptr->d_response, _ex); SIDL_CHECK(*_ex);
      dptr->d_response = NULL;
    }
    if ( sr != NULL ) { 
      dptr->d_response = sr;
      sidlx_rmi_Simsponse_addRef( dptr->d_response, _ex ); SIDL_CHECK(*_ex);
    }
  }
 EXIT:
  return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket.setResponse) */
  }
}

/*
 *  blocks until the Response is received 
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket_block"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimpleTicket_block(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket.block) */
  struct sidlx_rmi_SimpleTicket__data *dptr = 
    sidlx_rmi_SimpleTicket__get_data(self);
  sidl_bool ready = FALSE;
  if(dptr && dptr->d_response) { 
    /* negative time implies wait forever */
    ready = sidlx_rmi_Simsponse_test( dptr->d_response, -1, -1, _ex); SIDL_CHECK(*_ex);
  }
  if ( ! ready ) { 
    SIDL_THROW(*_ex, sidl_rmi_TimeOutException, "Timed out after 1 hour.");
  }
 EXIT:
  return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket.block) */
  }
}

/*
 *  
 * returns immediately: true iff the Response is already
 * received 
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket_test"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_sidlx_rmi_SimpleTicket_test(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket.test) */
  struct sidlx_rmi_SimpleTicket__data *dptr = 
    sidlx_rmi_SimpleTicket__get_data(self);
  if(dptr && dptr->d_response) { 
    return sidlx_rmi_Simsponse_test( dptr->d_response, 0, 0,_ex); 
  }
  return FALSE;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket.test) */
  }
}

/*
 *  creates an empty container specialized for Tickets 
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket_createEmptyTicketBook"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_TicketBook
impl_sidlx_rmi_SimpleTicket_createEmptyTicketBook(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket.createEmptyTicketBook) */
    sidlx_rmi_SimpleTicketBook book = NULL; 
    sidl_rmi_TicketBook tb = NULL; 
    book = sidlx_rmi_SimpleTicketBook__create(_ex); SIDL_CHECK(*_ex);
    tb = sidl_rmi_TicketBook__cast( book, _ex ); SIDL_CHECK(*_ex);
    sidlx_rmi_SimpleTicketBook_deleteRef(book, _ex); SIDL_CHECK(*_ex);
    return tb;
  EXIT:
    return NULL;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket.createEmptyTicketBook) */
  }
}

/*
 *  returns immediately: returns Response or null 
 * (NOTE: needed for implementors of communication
 * libraries, not expected for general use).
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimpleTicket_getResponse"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_Response
impl_sidlx_rmi_SimpleTicket_getResponse(
  /* in */ sidlx_rmi_SimpleTicket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleTicket.getResponse) */
  struct sidlx_rmi_SimpleTicket__data *dptr = 
    sidlx_rmi_SimpleTicket__get_data(self);
  if ( dptr && dptr->d_response) { 
    sidl_rmi_Response retval = sidl_rmi_Response__cast(dptr->d_response, _ex); SIDL_CHECK(*_ex);
    sidlx_rmi_Simsponse_pullData( dptr->d_response, _ex); SIDL_CHECK(*_ex);    
    return retval;
  }
 EXIT:
  return NULL;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleTicket.getResponse) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

