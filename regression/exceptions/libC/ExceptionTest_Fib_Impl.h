/*
 * File:          ExceptionTest_Fib_Impl.h
 * Symbol:        ExceptionTest.Fib-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for ExceptionTest.Fib
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_ExceptionTest_Fib_Impl_h
#define included_ExceptionTest_Fib_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_ExceptionTest_Fib_h
#include "ExceptionTest_Fib.h"
#endif
#ifndef included_ExceptionTest_FibException_h
#include "ExceptionTest_FibException.h"
#endif
#ifndef included_ExceptionTest_NegativeValueException_h
#include "ExceptionTest_NegativeValueException.h"
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
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
#ifndef included_sidl_SIDLException_h
#include "sidl_SIDLException.h"
#endif
/* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._hincludes) */

/*
 * Private data for class ExceptionTest.Fib
 */

struct ExceptionTest_Fib__data {
  /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct ExceptionTest_Fib__data*
ExceptionTest_Fib__get_data(
  ExceptionTest_Fib);

extern void
ExceptionTest_Fib__set_data(
  ExceptionTest_Fib,
  struct ExceptionTest_Fib__data*);

extern
void
impl_ExceptionTest_Fib__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_Fib__ctor(
  /* in */ ExceptionTest_Fib self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_Fib__ctor2(
  /* in */ ExceptionTest_Fib self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_ExceptionTest_Fib__dtor(
  /* in */ ExceptionTest_Fib self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_ExceptionTest_Fib_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_ExceptionTest_Fib_fconnect_sidl_BaseClass(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
int32_t
impl_ExceptionTest_Fib_getFib(
  /* in */ ExceptionTest_Fib self,
  /* in */ int32_t n,
  /* in */ int32_t max_depth,
  /* in */ int32_t max_value,
  /* in */ int32_t depth,
  /* out */ sidl_BaseInterface *_ex);

extern
struct sidl_int__array*
impl_ExceptionTest_Fib_noLeak(
  /* in */ ExceptionTest_Fib self,
  /* in array<int,2,column-major> */ struct sidl_int__array* a1,
  /* inout array<int,2,column-major> */ struct sidl_int__array** a2,
  /* out array<int,2,column-major> */ struct sidl_int__array** a3,
  /* in rarray[m,n] */ int32_t* r1,
  /* inout rarray[m,n] */ int32_t* r2,
  /* in */ int32_t m,
  /* in */ int32_t n,
  /* in array<int> */ struct sidl_int__array* c1,
  /* inout array<int> */ struct sidl_int__array** c2,
  /* out array<int> */ struct sidl_int__array** c3,
  /* in */ const char* s1,
  /* inout */ char** s2,
  /* out */ char** s3,
  /* in */ sidl_BaseClass o1,
  /* inout */ sidl_BaseClass* o2,
  /* out */ sidl_BaseClass* o3,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_ExceptionTest_Fib_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_ExceptionTest_Fib_fconnect_sidl_BaseClass(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
