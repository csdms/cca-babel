/*
 * File:          sidlx_rmi_ClientSocket_Impl.c
 * Symbol:        sidlx.rmi.ClientSocket-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sidlx.rmi.ClientSocket
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidlx.rmi.ClientSocket" (version 0.1)
 * 
 * Automatically sets up a port for listening for new connections
 */

#include "sidlx_rmi_ClientSocket_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket._includes) */
#include "sidlx_rmi_Socket.h"
#include "sidlx_rmi_Common.h"
#include "sidlx_common.h"
#include "sidlx_rmi_UnrecognizedNetworkException.h"
#include "sidl_MemAllocException.h"
/* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_ClientSocket__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_ClientSocket__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket._load) */
  /* insert implementation here: sidlx.rmi.ClientSocket._load (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_ClientSocket__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_ClientSocket__ctor(
  /* in */ sidlx_rmi_ClientSocket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket._ctor) */
  /* insert implementation here: sidlx.rmi.ClientSocket._ctor (constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_ClientSocket__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_ClientSocket__ctor2(
  /* in */ sidlx_rmi_ClientSocket self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket._ctor2) */
  /* Insert-Code-Here {sidlx.rmi.ClientSocket._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_ClientSocket__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_ClientSocket__dtor(
  /* in */ sidlx_rmi_ClientSocket self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket._dtor) */
  /* insert implementation here: sidlx.rmi.ClientSocket._dtor (destructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket._dtor) */
  }
}

/*
 * Method:  init[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_ClientSocket_init"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sidlx_rmi_ClientSocket_init(
  /* in */ sidlx_rmi_ClientSocket self,
  /* in */ int32_t IP,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.ClientSocket.init) */
    int sockfd;
    struct sidlx_rmi_ClientSocket__data client_data;
    sidl_BaseInterface _throwaway_exception = NULL;
    
    client_data.d_serv_addr.sin_family = AF_INET;
    client_data.d_serv_addr.sin_addr.s_addr = htonl(IP);
    client_data.d_serv_addr.sin_port = htons( port );
    client_data.addrlen = sizeof(struct sockaddr_in);
    
    if ( (sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0 ) { 
      sidlx_throwException(errno, _ex);
      SIDL_CHECK(*_ex);
    }

    if(client_data.d_serv_addr.sin_addr.s_addr == 0) {
      sidl_BaseInterface _throwaway_exception = NULL;
      sidlx_rmi_UnrecognizedNetworkException tmpEx = 
        sidlx_rmi_UnrecognizedNetworkException__create(&_throwaway_exception);       
      sidlx_rmi_UnrecognizedNetworkException_setNote(tmpEx, "IP address connot be 0", 
                                                     &_throwaway_exception);
      sidlx_rmi_UnrecognizedNetworkException_setErrno(tmpEx, 24, &_throwaway_exception);
      sidlx_rmi_UnrecognizedNetworkException_add(tmpEx, __FILE__, __LINE__, __FUNC__, &_throwaway_exception);
      *_ex = (sidl_BaseInterface) tmpEx;
    }

    s_connect( sockfd, (struct sockaddr *) &(client_data.d_serv_addr),
               client_data.addrlen, _ex);
    if ( *_ex) { 
      sidlx_rmi_ClientSocket_setFileDescriptor(self, sockfd,
                                               &_throwaway_exception);
      SIDL_CHECK(*_ex);
    }
    
    sidlx_rmi_ClientSocket_setFileDescriptor(self, sockfd, _ex); SIDL_CHECK(*_ex);
    return 0;
  EXIT:
    return -1;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.ClientSocket.init) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

