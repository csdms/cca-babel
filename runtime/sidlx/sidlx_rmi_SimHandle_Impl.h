/*
 * File:          sidlx_rmi_SimHandle_Impl.h
 * Symbol:        sidlx.rmi.SimHandle-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sidlx.rmi.SimHandle
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sidlx_rmi_SimHandle_Impl_h
#define included_sidlx_rmi_SimHandle_Impl_h

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
#ifndef included_sidl_rmi_InstanceHandle_h
#include "sidl_rmi_InstanceHandle.h"
#endif
#ifndef included_sidl_rmi_Invocation_h
#include "sidl_rmi_Invocation.h"
#endif
#ifndef included_sidlx_rmi_SimHandle_h
#include "sidlx_rmi_SimHandle.h"
#endif
/* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimHandle._hincludes) */
#include "sidlx_rmi_ClientSocket.h"
#include "sidlx_rmi_Socket.h"
#include "sidl_rmi_NetworkException.h"
#include "sidlx_rmi_Simsponse.h"
#include "sidlx_rmi_Simvocation.h"
#include "sidl_Exception.h"
/* DO-NOT-DELETE splicer.end(sidlx.rmi.SimHandle._hincludes) */

/*
 * Private data for class sidlx.rmi.SimHandle
 */

struct sidlx_rmi_SimHandle__data {
  /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimHandle._data) */
  char * d_prefix;    /* The beginning prefix of a URL... also called scheme*/
  char * d_server;    /* The domain name of URL... also called host */
  int32_t d_port;     /* port */
  char * d_objectID;  /* As determined by the InstanceRegistry */
  char * d_typeName;  /* The SIDL type */
  int32_t d_IP;       /* IP address of the server */
  /*sidlx_rmi_Socket d_sock; */ /* may be needed for SOCKET_KEEPALIVE */
  /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimHandle._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sidlx_rmi_SimHandle__data*
sidlx_rmi_SimHandle__get_data(
  sidlx_rmi_SimHandle);

extern void
sidlx_rmi_SimHandle__set_data(
  sidlx_rmi_SimHandle,
  struct sidlx_rmi_SimHandle__data*);

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

/*
 * User-defined object methods
 */

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

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
