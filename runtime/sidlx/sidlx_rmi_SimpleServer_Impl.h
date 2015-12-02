/*
 * File:          sidlx_rmi_SimpleServer_Impl.h
 * Symbol:        sidlx.rmi.SimpleServer-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sidlx.rmi.SimpleServer
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sidlx_rmi_SimpleServer_Impl_h
#define included_sidlx_rmi_SimpleServer_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#ifndef included_sidl_rmi_ServerInfo_h
#include "sidl_rmi_ServerInfo.h"
#endif
#ifndef included_sidlx_rmi_SimpleServer_h
#include "sidlx_rmi_SimpleServer.h"
#endif
#ifndef included_sidlx_rmi_Socket_h
#include "sidlx_rmi_Socket.h"
#endif
/* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleServer._hincludes) */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "sidlx_rmi_ServerSocket.h"
#include "sidlx_rmi_Socket.h"
/* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleServer._hincludes) */

/*
 * Private data for class sidlx.rmi.SimpleServer
 */

struct sidlx_rmi_SimpleServer__data {
  /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimpleServer._data) */
  /*int d_listen_socket;
    struct sockaddr_in d_serv_addr;*/
  sidlx_rmi_ServerSocket s_sock;
  int d_port;
  int32_t d_flags;
  char* d_hostname;
  /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimpleServer._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sidlx_rmi_SimpleServer__data*
sidlx_rmi_SimpleServer__get_data(
  sidlx_rmi_SimpleServer);

extern void
sidlx_rmi_SimpleServer__set_data(
  sidlx_rmi_SimpleServer,
  struct sidlx_rmi_SimpleServer__data*);

extern
void
impl_sidlx_rmi_SimpleServer__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__ctor(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__ctor2(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer__dtor(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sidlx_rmi_SimpleServer_setMaxThreadPool(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t max,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestPort(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_requestPortInRange(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ int32_t minport,
  /* in */ int32_t maxport,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sidlx_rmi_SimpleServer_getPort(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleServer_getServerName(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sidlx_rmi_SimpleServer_getServerURL(
  /* in */ sidlx_rmi_SimpleServer self,
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex);

extern
int64_t
impl_sidlx_rmi_SimpleServer_run(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer_shutdown(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_SimpleServer_shutdownNoWait(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

extern
sidl_bool
impl_sidlx_rmi_SimpleServer_isRunning(
  /* in */ sidlx_rmi_SimpleServer self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidlx_rmi_Socket__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_SimpleServer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
