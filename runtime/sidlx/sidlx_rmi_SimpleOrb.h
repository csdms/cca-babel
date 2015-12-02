/*
 * File:          sidlx_rmi_SimpleOrb.h
 * Symbol:        sidlx.rmi.SimpleOrb-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Client-side glue code for sidlx.rmi.SimpleOrb
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_SimpleOrb_h
#define included_sidlx_rmi_SimpleOrb_h

/**
 * Symbol "sidlx.rmi.SimpleOrb" (version 0.1)
 * 
 * A simple example orb, using the simhandle protocol (written by Jim)
 */
struct sidlx_rmi_SimpleOrb__object;
struct sidlx_rmi_SimpleOrb__array;
typedef struct sidlx_rmi_SimpleOrb__object* sidlx_rmi_SimpleOrb;

/*
 * Includes for all header dependencies.
 */

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_sidl_BaseException_h
#include "sidl_BaseException.h"
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
#ifndef included_sidl_SIDLException_h
#include "sidl_SIDLException.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#ifndef included_sidlx_rmi_Socket_h
#include "sidlx_rmi_Socket.h"
#endif

#ifndef included_sidl_rmi_Call_h
#include "sidl_rmi_Call.h"
#endif
#ifndef included_sidl_rmi_Return_h
#include "sidl_rmi_Return.h"
#endif
#ifdef SIDL_C_HAS_INLINE
#ifndef included_sidlx_rmi_SimpleOrb_IOR_h
#include "sidlx_rmi_SimpleOrb_IOR.h"
#endif
#endif /* SIDL_C_HAS_INLINE */
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(SIDLX_RMI_SIMPLEORB_INLINE_DECL) && defined(SIDL_C_HAS_INLINE)
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || defined(__INTEL_COMPILER) || !defined(__GNUC__)
#define SIDLX_RMI_SIMPLEORB_INLINE_DECL inline
#else
#define SIDLX_RMI_SIMPLEORB_INLINE_DECL extern inline
#endif
#endif /* inline preprocessor definitions */
/**
 * Constructor function for the class.
 */
struct sidlx_rmi_SimpleOrb__object*
sidlx_rmi_SimpleOrb__create(sidl_BaseInterface* _ex);

/**
 * Wraps up the private data struct pointer (struct sidlx_rmi_SimpleOrb__data) passed in rather than running the constructor.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__wrapObj(void * data, sidl_BaseInterface *_ex);

#ifdef WITH_RMI

/**
 * RMI constructor function for the class.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__createRemote(const char * url, sidl_BaseInterface *_ex);

/**
 * RMI connector function for the class.(addrefs)
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__connect(const char *, sidl_BaseInterface *_ex);


#endif /*WITH_RMI*/
/**
 * Method to enable/disable interface contract enforcement.
 */
void
sidlx_rmi_SimpleOrb__set_contracts(
  sidlx_rmi_SimpleOrb self,
  sidl_bool   enable,
  const char* enfFilename,
  sidl_bool   resetCounters,
  struct sidl_BaseInterface__object **_ex);

/**
 * Method to dump interface contract enforcement statistics.
 */
void
sidlx_rmi_SimpleOrb__dump_stats(
  sidlx_rmi_SimpleOrb self,
  const char* filename,
  const char* prefix,
  struct sidl_BaseInterface__object **_ex);

/**
 * Set a cookie.  All incoming RMI's without matching cookie are 
 * discarded.  setCookie must be called before run, if not, the results
 * are undefined. 
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_setCookie(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in rarray[len] */ char* cookie,
  /* in */ int32_t len,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  int32_t cookie_lower[1], cookie_upper[1], cookie_stride[1]; 
  struct sidl_char__array cookie_real;
  struct sidl_char__array* cookie_tmp = &cookie_real;
  cookie_upper[0] = len-1;
  sidl_char__array_init(cookie, cookie_tmp, 1, cookie_lower, cookie_upper, 
    cookie_stride);
  (*self->d_epv->f_setCookie)(
    self,
    cookie_tmp,
    _ex);
#ifdef SIDL_DEBUG_REFCOUNT
  sidl__array_deleteRef((struct sidl__array*)cookie_tmp);
#endif /* SIDL_DEBUG_REFCOUNT */
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * If a cookie has been set, any RMI that does not authenticate with 
 * the cookie will be discarded.  setNumSecurityRetries sets a maximum 
 * number of times the Orb will discard RMIs before shutting down.
 * In other words, if more than 'retries' unauthenticateable RMIs are 
 * recieved, the Orb shutsdown on abnormally with an error message.
 * This call can be called before or after setCookie, but if a cookie
 * is not set, this call has no functional effect.  
 * setNumSecurityRetries  must be called before run, if not, the results
 * are undefined. 
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_setNumSecurityRetries(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ int32_t retries,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_setNumSecurityRetries)(
    self,
    retries,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Method:  serviceRequest[]
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_serviceRequest(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ sidlx_rmi_Socket sock,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_serviceRequest)(
    self,
    sock,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Needed by Babel to determine if a url points to a local or remote object
 * users should never need this.  Returns the objectID if is local, Null otherwise. 
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
char*
sidlx_rmi_SimpleOrb_isLocalObject(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  char* _result;
  _result = (*self->d_epv->f_isLocalObject)(
    self,
    url,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Get the short name of the protocol this ORB supports
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
char*
sidlx_rmi_SimpleOrb_getProtocol(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  char* _result;
  _result = (*self->d_epv->f_getProtocol)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * This gets an array of logged exceptions.  If an exception can
 * not be thrown back to the caller, we log it with the Server.  This 
 * gets the array of all those exceptions.
 * THIS IS SOMETHING OF A TEST! THIS MAY CHANGE!
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
struct sidl_io_Serializable__array*
sidlx_rmi_SimpleOrb_getExceptions(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  struct sidl_io_Serializable__array* _result;
  _result = (*self->d_epv->f_getExceptions)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Set the maximum size of the client thread pool.
 * (default = 1024)
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_setMaxThreadPool(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ int32_t max,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_setMaxThreadPool)(
    self,
    max,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * request a specific port number
 * returns true iff request is satisfied
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb_requestPort(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ int32_t port,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f_requestPort)(
    self,
    port,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Request the minimum available port in 
 * a range.  Returns true iff request is satisfied
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb_requestPortInRange(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ int32_t minport,
  /* in */ int32_t maxport,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f_requestPortInRange)(
    self,
    minport,
    maxport,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * get the port that this Server is bound to
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
int32_t
sidlx_rmi_SimpleOrb_getPort(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  int32_t _result;
  _result = (*self->d_epv->f_getPort)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * get the network name of this computer
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
char*
sidlx_rmi_SimpleOrb_getServerName(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  char* _result;
  _result = (*self->d_epv->f_getServerName)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * get the full URL for exporting objects
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
char*
sidlx_rmi_SimpleOrb_getServerURL(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  char* _result;
  _result = (*self->d_epv->f_getServerURL)(
    self,
    objID,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * run the server (must have port specified first), if a threaded server,
 * returns the tid of the server thread for joining.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
int64_t
sidlx_rmi_SimpleOrb_run(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  int64_t _result;
  _result = (*self->d_epv->f_run)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Cleanly shutdown the orb.  Method blocks until orb is fully shutdown.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_shutdown(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_shutdown)(
    self,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Starts the shutodwn process, but does not wait for shutdown to 
 * complete before returning.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_shutdownNoWait(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_shutdownNoWait)(
    self,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Check if the ORB is running.  NOT REALLY THREAD SAFE.  DON'T TRY TO USE
 * THIS WHEN THREAD SAFETY IS AN ISSUE.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb_isRunning(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f_isRunning)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * <p>
 * Add one to the intrinsic reference count in the underlying object.
 * Object in <code>sidl</code> have an intrinsic reference count.
 * Objects continue to exist as long as the reference count is
 * positive. Clients should call this method whenever they
 * create another ongoing reference to an object or interface.
 * </p>
 * <p>
 * This does not have a return value because there is no language
 * independent type that can refer to an interface or a
 * class.
 * </p>
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_addRef(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_addRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Decrease by one the intrinsic reference count in the underlying
 * object, and delete the object if the reference is non-positive.
 * Objects in <code>sidl</code> have an intrinsic reference count.
 * Clients should call this method whenever they remove a
 * reference to an object or interface.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb_deleteRef(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f_deleteRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Return true if and only if <code>obj</code> refers to the same
 * object as this object.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb_isSame(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ sidl_BaseInterface iobj,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f_isSame)(
    self,
    iobj,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Return whether this object is an instance of the specified type.
 * The string name must be the <code>sidl</code> type name.  This
 * routine will return <code>true</code> if and only if a cast to
 * the string type name would succeed.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb_isType(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* name,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f_isType)(
    self,
    name,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Return the meta-data about the class implementing this interface.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_ClassInfo
sidlx_rmi_SimpleOrb_getClassInfo(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_ClassInfo _result;
  _result = (*self->d_epv->f_getClassInfo)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */


/**
 * Cast method for interface and class type conversions.
 */
struct sidlx_rmi_SimpleOrb__object*
sidlx_rmi_SimpleOrb__cast(
  void* obj,
  sidl_BaseInterface* _ex);

/**
 * String cast method for interface and class type conversions.
 */
void*
sidlx_rmi_SimpleOrb__cast2(
  void* obj,
  const char* type,
  sidl_BaseInterface *_ex);

/**
 * Select and execute a method by name
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb__exec(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ const char* methodName,
  /* in */ sidl_rmi_Call inArgs,
  /* in */ sidl_rmi_Return outArgs,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f__exec)(
    self,
    methodName,
    inArgs,
    outArgs,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */

/**
 * Get the URL of the Implementation of this object (for RMI)
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
char*
sidlx_rmi_SimpleOrb__getURL(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  char* _result;
  _result = (*self->d_epv->f__getURL)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */

/**
 * On a remote object, addrefs the remote instance.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb__raddRef(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f__raddRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */

/**
 * TRUE if this object is remote, false if local
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
sidl_bool
sidlx_rmi_SimpleOrb__isRemote(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  sidl_bool _result;
  _result = (*self->d_epv->f__isRemote)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */

/**
 * TRUE if this object is remote, false if local
 */
sidl_bool
sidlx_rmi_SimpleOrb__isLocal(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* out */ sidl_BaseInterface *_ex);
/**
 * Method to enable/disable method hooks invocation.
 */
SIDLX_RMI_SIMPLEORB_INLINE_DECL
void
sidlx_rmi_SimpleOrb__set_hooks(
  /* in */ sidlx_rmi_SimpleOrb self,
  /* in */ sidl_bool enable,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDLX_RMI_SIMPLEORB_INLINE_DECL
{
  (*self->d_epv->f__set_hooks)(
    self,
    enable,
    _ex);
}
#else
;
#endif /* SIDLX_RMI_SIMPLEORB_INLINE_DECL */

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in column-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in row-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

/**
 * Create a contiguous one-dimensional array with a lower index
 * of 0 and an upper index of len-1. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_create1d(int32_t len);

/**
 * Create a dense one-dimensional vector with a lower
 * index of 0 and an upper index of len-1. The initial data for this
 * new array is copied from data. This will increment the reference
 * count of each non-NULL object/interface reference in data.
 * 
 * This array owns and manages its data.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_create1dInit(
  int32_t len, 
  sidlx_rmi_SimpleOrb* data);

/**
 * Create a contiguous two-dimensional array in column-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_create2dCol(int32_t m, int32_t n);

/**
 * Create a contiguous two-dimensional array in row-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_create2dRow(int32_t m, int32_t n);

/**
 * Create an array that uses data (memory) from another
 * source. The initial contents are determined by the
 * data being borrowed.
 * Any time an element in the borrowed array is replaced
 * via a set call, deleteRef will be called on the
 * value being replaced if it is not NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_borrow(
  sidlx_rmi_SimpleOrb* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[]);

/**
 * If array is borrowed, allocate a new self-sufficient
 * array and copy the borrowed array into the new array;
 * otherwise, increment the reference count and return
 * the array passed in. Use this whenever you want to
 * make a copy of a method argument because arrays
 * passed into methods aren't guaranteed to exist after
 * the method call.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_smartCopy(
  struct sidlx_rmi_SimpleOrb__array *array);

/**
 * Increment the array's internal reference count by one.
 */
void
sidlx_rmi_SimpleOrb__array_addRef(
  struct sidlx_rmi_SimpleOrb__array* array);

/**
 * Decrement the array's internal reference count by one.
 * If the reference count goes to zero, destroy the array.
 * If the array isn't borrowed, this releases all the
 * object references held by the array.
 */
void
sidlx_rmi_SimpleOrb__array_deleteRef(
  struct sidlx_rmi_SimpleOrb__array* array);

/**
 * Retrieve element i1 of a(n) 1-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get1(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1);

/**
 * Retrieve element (i1,i2) of a(n) 2-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get2(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2);

/**
 * Retrieve element (i1,i2,i3) of a(n) 3-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get3(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3);

/**
 * Retrieve element (i1,i2,i3,i4) of a(n) 4-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get4(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4);

/**
 * Retrieve element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get5(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5);

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get6(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6);

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get7(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7);

/**
 * Retrieve element indices of an n-dimensional array.
 * indices is assumed to have the right number of elements
 * for the dimension of array.
 */
sidlx_rmi_SimpleOrb
sidlx_rmi_SimpleOrb__array_get(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t indices[]);

/**
 * Set element i1 of a(n) 1-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set1(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2) of a(n) 2-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set2(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2,i3) of a(n) 3-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set3(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2,i3,i4) of a(n) 4-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set4(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set5(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set6(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array to value.
 */
void
sidlx_rmi_SimpleOrb__array_set7(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  sidlx_rmi_SimpleOrb const value);

/**
 * Set element indices of an n-dimensional array to value.indices is assumed to have the right number of elements
 * for the dimension of array.
 */
void
sidlx_rmi_SimpleOrb__array_set(
  struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t indices[],
  sidlx_rmi_SimpleOrb const value);

/**
 * Return the dimension of array. If the array pointer is
 * NULL, zero is returned.
 */
int32_t
sidlx_rmi_SimpleOrb__array_dimen(
  const struct sidlx_rmi_SimpleOrb__array* array);

/**
 * Return the lower bound of dimension ind.
 * If ind is not a valid dimension, 0 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_SimpleOrb__array_lower(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t ind);

/**
 * Return the upper bound of dimension ind.
 * If ind is not a valid dimension, -1 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_SimpleOrb__array_upper(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t ind);

/**
 * Return the length of dimension ind.
 * If ind is not a valid dimension, -1 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_SimpleOrb__array_length(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t ind);

/**
 * Return the stride of dimension ind.
 * If ind is not a valid dimension, 0 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_SimpleOrb__array_stride(
  const struct sidlx_rmi_SimpleOrb__array* array,
  const int32_t ind);

/**
 * Return a true value iff the array is a contiguous
 * column-major ordered array. A NULL array argument
 * causes 0 to be returned.
 */
int
sidlx_rmi_SimpleOrb__array_isColumnOrder(
  const struct sidlx_rmi_SimpleOrb__array* array);

/**
 * Return a true value iff the array is a contiguous
 * row-major ordered array. A NULL array argument
 * causes 0 to be returned.
 */
int
sidlx_rmi_SimpleOrb__array_isRowOrder(
  const struct sidlx_rmi_SimpleOrb__array* array);

/**
 * Create a sub-array of another array. This resulting
 * array shares data with the original array. The new
 * array can be of the same dimension or potentially
 * less assuming the original array has dimension
 * greater than 1.  If you are removing dimension,
 * indicate the dimensions to remove by setting
 * numElem[i] to zero for any dimension i wthat should
 * go away in the new array.  The meaning of each
 * argument is covered below.
 * 
 * src       the array to be created will be a subset
 *           of this array. If this argument is NULL,
 *           NULL will be returned. The array returned
 *           borrows data from src, so modifying src or
 *           the returned array will modify both
 *           arrays.
 * 
 * dimen     this argument must be greater than zero
 *           and less than or equal to the dimension of
 *           src. An illegal value will cause a NULL
 *           return value.
 * 
 * numElem   this specifies how many elements from src
 *           should be taken in each dimension. A zero
 *           entry indicates that the dimension should
 *           not appear in the new array.  This
 *           argument should be an array with an entry
 *           for each dimension of src.  Passing NULL
 *           here will cause NULL to be returned.  If
 *           srcStart[i] + numElem[i]*srcStride[i] is
 *           greater than upper[i] for src or if
 *           srcStart[i] + numElem[i]*srcStride[i] is
 *           less than lower[i] for src, NULL will be
 *           returned.
 * 
 * srcStart  this array holds the coordinates of the
 *           first element of the new array. If this
 *           argument is NULL, the first element of src
 *           will be the first element of the new
 *           array. If non-NULL, this argument should
 *           be an array with an entry for each
 *           dimension of src.  If srcStart[i] is less
 *           than lower[i] for the array src, NULL will
 *           be returned.
 * 
 * srcStride this array lets you specify the stride
 *           between elements in each dimension of
 *           src. This stride is relative to the
 *           coordinate system of the src array. If
 *           this argument is NULL, the stride is taken
 *           to be one in each dimension.  If non-NULL,
 *           this argument should be an array with an
 *           entry for each dimension of src.
 * 
 * newLower  this argument is like lower in a create
 *           method. It sets the coordinates for the
 *           first element in the new array.  If this
 *           argument is NULL, the values indicated by
 *           srcStart will be used. If non-NULL, this
 *           should be an array with dimen elements.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_slice(
  struct sidlx_rmi_SimpleOrb__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart);

/**
 * Copy the contents of one array (src) to a second array
 * (dest). For the copy to take place, both arrays must
 * exist and be of the same dimension. This method will
 * not modify dest's size, index bounds, or stride; only
 * the array element values of dest may be changed by
 * this function. No part of src is ever changed by copy.
 * 
 * On exit, dest[i][j][k]... = src[i][j][k]... for all
 * indices i,j,k...  that are in both arrays. If dest and
 * src have no indices in common, nothing is copied. For
 * example, if src is a 1-d array with elements 0-5 and
 * dest is a 1-d array with elements 2-3, this function
 * will make the following assignments:
 *   dest[2] = src[2],
 *   dest[3] = src[3].
 * The function copied the elements that both arrays have
 * in common.  If dest had elements 4-10, this function
 * will make the following assignments:
 *   dest[4] = src[4],
 *   dest[5] = src[5].
 */
void
sidlx_rmi_SimpleOrb__array_copy(
  const struct sidlx_rmi_SimpleOrb__array* src,
  struct sidlx_rmi_SimpleOrb__array* dest);

/**
 * If necessary, convert a general matrix into a matrix
 * with the required properties. This checks the
 * dimension and ordering of the matrix.  If both these
 * match, it simply returns a new reference to the
 * existing matrix. If the dimension of the incoming
 * array doesn't match, it returns NULL. If the ordering
 * of the incoming array doesn't match the specification,
 * a new array is created with the desired ordering and
 * the content of the incoming array is copied to the new
 * array.
 * 
 * The ordering parameter should be one of the constants
 * defined in enum sidl_array_ordering
 * (e.g. sidl_general_order, sidl_column_major_order, or
 * sidl_row_major_order). If you specify
 * sidl_general_order, this routine will only check the
 * dimension because any matrix is sidl_general_order.
 * 
 * The caller assumes ownership of the returned reference
 * unless it's NULL.
 */
struct sidlx_rmi_SimpleOrb__array*
sidlx_rmi_SimpleOrb__array_ensure(
  struct sidlx_rmi_SimpleOrb__array* src,
  int32_t dimen,
  int     ordering);


#pragma weak sidlx_rmi_SimpleOrb__connectI

/**
 * RMI connector function for the class. (no addref)
 */
struct sidlx_rmi_SimpleOrb__object*
sidlx_rmi_SimpleOrb__connectI(const char * url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
