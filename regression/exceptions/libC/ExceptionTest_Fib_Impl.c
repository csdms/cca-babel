/*
 * File:          ExceptionTest_Fib_Impl.c
 * Symbol:        ExceptionTest.Fib-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for ExceptionTest.Fib
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "ExceptionTest.Fib" (version 1.0)
 * 
 * This class holds the method <code>getFib</code> that generates the
 * requested Fibonacci numbers.
 */

#include "ExceptionTest_Fib_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._includes) */
#include "sidl_Exception.h"
#include "ExceptionTest_NegativeValueException.h"
#include "ExceptionTest_TooDeepException.h"
#include "ExceptionTest_TooBigException.h"
#include <stdlib.h>
#include <stddef.h>
/* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_Fib__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_Fib__ctor(
  /* in */ ExceptionTest_Fib self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._ctor) */
  /* nothing needed */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_Fib__ctor2(
  /* in */ ExceptionTest_Fib self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._ctor2) */
  /* Insert-Code-Here {ExceptionTest.Fib._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_ExceptionTest_Fib__dtor(
  /* in */ ExceptionTest_Fib self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib._dtor) */
  /* nothing needed */
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib._dtor) */
  }
}

/*
 * <p>
 * Generate the requested Fibonacci number or generate exceptions if
 * the input Fibonacci number is invalid or if any of the maximum depth
 * or maximum value parameters are exceeded.  The last argument of the
 * method should be zero.
 * </p>
 * <p>
 * The algorithm should be similar to the <code>Java</code> code below.
 * </p>
 * <pre>
 * public int getFib(int n, int max_depth, int max_value, int depth)
 * throws NegativeValueException, FibException {
 * 
 * if (n < 0) {
 * throw new NegativeValueException("n negative");
 * 
 * } else if (depth > max_depth) {
 * throw new TooDeepException("too deep");
 * 
 * } else if (n == 0) {
 * return 1;
 * 
 * } else if (n == 1) {
 * return 1;
 * 
 * } else {
 * int a = getFib(n-1, max_depth, max_value, depth+1);
 * int b = getFib(n-2, max_depth, max_value, depth+1);
 * if (a + b > max_value) {
 * throw new TooBigException("too big");
 * }
 * return a + b;
 * }
 * } 
 * </pre>
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib_getFib"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_ExceptionTest_Fib_getFib(
  /* in */ ExceptionTest_Fib self,
  /* in */ int32_t n,
  /* in */ int32_t max_depth,
  /* in */ int32_t max_value,
  /* in */ int32_t depth,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib.getFib) */
  int32_t a;
  int32_t b;
  int32_t theValue = 0;

  if (n < 0) {
    SIDL_THROW(*_ex,
               ExceptionTest_NegativeValueException,
               "called with negative n");
  } else if (depth > max_depth) {
    SIDL_THROW(*_ex,
               ExceptionTest_TooDeepException,
               "exceeded specified recursion depth");
  } else if (n == 0) {
    theValue = 1;
  } else if (n == 1) {
    theValue = 1;
  } else {
    a = impl_ExceptionTest_Fib_getFib(
      self,
      n-1,
      max_depth,
      max_value, 
      depth+1,
      _ex); SIDL_CHECK(*_ex);
    b = impl_ExceptionTest_Fib_getFib(
      self,
      n-2,
      max_depth,
      max_value, 
      depth+1,
      _ex); SIDL_CHECK(*_ex);
    theValue = a + b;
    if (theValue > max_value) {
      /* Reset the value since returning an exception */
      theValue = 0;
      SIDL_THROW(*_ex,
                 ExceptionTest_TooBigException,
                 "result exceeds specified maximum value");
    }
  }

  EXIT:;
    return theValue;
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib.getFib) */
  }
}

/*
 * Check for memory/reference leaks in the presence of an exception.
 * The impl will throw an exception and assign random values to
 * out parameters to prove that out values are ignored.
 * The intent is that row-major arrays should be passed to parameters
 * a1, a2, a3.
 */

#undef __FUNC__
#define __FUNC__ "impl_ExceptionTest_Fib_noLeak"

#ifdef __cplusplus
extern "C"
#endif
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
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(ExceptionTest.Fib.noLeak) */
    if (*a2) sidl_int__array_deleteRef(*a2); 
    *a2 = (struct sidl_int__array*)(ptrdiff_t)random();
    *a3 = (struct sidl_int__array*)(ptrdiff_t)random();
    if (*c2) sidl_int__array_deleteRef(*c2);
    *c2 = (struct sidl_int__array*)(ptrdiff_t)random();
    *c3 = (struct sidl_int__array*)(ptrdiff_t)random();
    if (*s2) free((void*)*s2);
    *s2 = (char *)(ptrdiff_t)random();
    *s3 = (char *)(ptrdiff_t)random();
    *o3 = (sidl_BaseClass)(ptrdiff_t)random();
    if (*o2) sidl_BaseClass_deleteRef(*o2, _ex); SIDL_REPORT(*_ex);
    *o2 = (sidl_BaseClass)(ptrdiff_t)random();
    SIDL_THROW(*_ex, sidl_SIDLException, "This method is supposed to throw an exception.");
  EXIT:;
    return (struct sidl_int__array *)(ptrdiff_t)random();
    /* DO-NOT-DELETE splicer.end(ExceptionTest.Fib.noLeak) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

