/*
 * File:          ExceptionTest_FibException_Impl.c
 * Symbol:        ExceptionTest.FibException-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for ExceptionTest.FibException
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "ExceptionTest.FibException" (version 1.0)
 * 
 * This exception is a base class for the Fibonacci exceptions that are
 * thrown if the value is too large or the recursion depth is too deep.
 */

#include "ExceptionTest_FibException_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._includes) */
/* Put additional includes or other arbitrary code here... */
/* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_FibException__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_FibException__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_FibException__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_FibException__ctor(
  /* in */ ExceptionTest_FibException self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_FibException__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_FibException__ctor2(
  /* in */ ExceptionTest_FibException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor2) */
  /* Insert-Code-Here {ExceptionTest.FibException._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_FibException__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_FibException__dtor(
  /* in */ ExceptionTest_FibException self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.FibException._dtor) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

