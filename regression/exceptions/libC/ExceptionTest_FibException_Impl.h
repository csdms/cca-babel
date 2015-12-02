/*
 * File:          ExceptionTest_FibException_Impl.h
 * Symbol:        ExceptionTest.FibException-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for ExceptionTest.FibException
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_ExceptionTest_FibException_Impl_h
#define included_ExceptionTest_FibException_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_ExceptionTest_FibException_h
#include "ExceptionTest_FibException.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
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
#ifndef included_sidl_io_Deserializer_h
#include "sidl_io_Deserializer.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#ifndef included_sidl_io_Serializer_h
#include "sidl_io_Serializer.h"
#endif
/* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._hincludes) */

/*
 * Private data for class ExceptionTest.FibException
 */

struct ExceptionTest_FibException__data {
  /* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct ExceptionTest_FibException__data*
ExceptionTest_FibException__get_data(
  ExceptionTest_FibException);

extern void
ExceptionTest_FibException__set_data(
  ExceptionTest_FibException,
  struct ExceptionTest_FibException__data*);

extern
void
impl_ExceptionTest_FibException__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_FibException__ctor(
  /* in */ ExceptionTest_FibException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_FibException__ctor2(
  /* in */ ExceptionTest_FibException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_FibException__dtor(
  /* in */ ExceptionTest_FibException self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_io_Deserializer(const char* url,
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_io_Deserializer(const char* url,
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_ExceptionTest_FibException_fconnect_sidl_io_Serializer(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
