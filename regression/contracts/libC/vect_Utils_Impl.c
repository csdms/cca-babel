/*
 * File:          vect_Utils_Impl.c
 * Symbol:        vect.Utils-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for vect.Utils
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "vect.Utils" (version 1.0)
 */

#include "vect_Utils_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(vect.Utils._includes) */
/************************** Includes **************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sidlArray.h"
#include "sidl_Exception.h"
#include "vect_vExcept.h"
#include "vect_vDivByZeroExcept.h"
#include "vect_vNegValExcept.h"

/* DO-NOT-DELETE splicer.end(vect.Utils._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_vect_Utils__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils._load) */
    /* Nothing needed here. */
    /* DO-NOT-DELETE splicer.end(vect.Utils._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_vect_Utils__ctor(
  /* in */ vect_Utils self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils._ctor) */
    /* Nothing needed here. */
    /* DO-NOT-DELETE splicer.end(vect.Utils._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_vect_Utils__ctor2(
  /* in */ vect_Utils self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils._ctor2) */
    /* Nothing needed here. */
    /* DO-NOT-DELETE splicer.end(vect.Utils._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_vect_Utils__dtor(
  /* in */ vect_Utils self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils._dtor) */
    /* Nothing needed here. */
    /* DO-NOT-DELETE splicer.end(vect.Utils._dtor) */
  }
}

/*
 * boolean result operations 
 * Return TRUE if the specified vector is the zero vector, within the
 * given tolerance level; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuIsZero"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuIsZero(
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuIsZero) */
    sidl_bool is = TRUE;
    int       i, maxI;
    double    absVal;
  
    if (u != NULL) 
    {
      maxI = sidl_double__array_upper(u, 0);
      for (i=sidl_double__array_lower(u, 0); (i <= maxI) && is; i++) 
      {
        absVal = fabs(sidl_double__array_get1(u, i));
        if ( absVal > fabs(tol) ) {
           is = FALSE;
        } 
      }
    } else {
      is = FALSE;
    }

    return is;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuIsZero) */
  }
}

/*
 * Return TRUE if the specified vector is the unit vector, within the
 * given tolerance level; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuIsUnit"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuIsUnit(
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuIsUnit) */
    sidl_bool is   = FALSE;

    double absDiff = fabs(impl_vect_Utils_vuNorm(u, tol, 0, _ex) 
                          - 1.0); SIDL_CHECK(*_ex);
    if ( absDiff <= fabs(tol) ) {
      is = TRUE;
    } else {
      is = FALSE;
    }
  
    EXIT:;
    return is;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuIsUnit) */
  }
}

/*
 * Return TRUE if the specified vectors are equal, within the given
 * tolerance level; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuAreEqual"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuAreEqual(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuAreEqual) */
    sidl_bool are = FALSE;
    int       i, lenU, lenV;
    double    absDiff;
  
    if ( (u != NULL) && (v != NULL) ) 
    {
      lenU = sidlLength(u, 0);
      lenV = sidlLength(v, 0);
      if (  (lenU == lenV)
         && (sidlArrayDim(u) == 1) 
         && (sidlArrayDim(v) == 1) ) 
      {
        are = TRUE;
        for (i=0; (i < lenU) && are; i++) 
        {
          absDiff = fabs(sidl_double__array_get1(u, i) 
                    - sidl_double__array_get1(v, i));
          if ( absDiff > fabs(tol) ) {
            are = FALSE;
          } 
        } 
      }
    }
  
    return are;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuAreEqual) */
  }
}

/*
 * Return TRUE if the specified vectors are orthogonal, within the given
 * tolerance; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuAreOrth"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuAreOrth(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuAreOrth) */
    sidl_bool are    = FALSE;
    double    absVal;
  
    if ( (u != NULL) && (v != NULL) ) 
    {
      absVal = fabs(impl_vect_Utils_vuDot(u, v, tol, 0, 
                                            _ex)); SIDL_CHECK(*_ex);
      if ( absVal <= fabs(tol) ) {
        are = TRUE;
      } else {
        are = FALSE;
      }
    }
  
    EXIT:;
    return are;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuAreOrth) */
  }
}

/*
 * Return TRUE if the Schwarz (or Cauchy-Schwarz) inequality holds, within
 * the given tolerance; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuSchwarzHolds"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuSchwarzHolds(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuSchwarzHolds) */
    sidl_bool holds    = FALSE;
    double    absDot, absNorms;
  
    if ( (u != NULL) && (v != NULL) ) 
    {
      absDot = fabs(impl_vect_Utils_vuDot(u, v, tol, 0, 
                                            _ex)); SIDL_CHECK(*_ex);
      absNorms = fabs(impl_vect_Utils_vuNorm(u, tol, 0, _ex) 
                 * impl_vect_Utils_vuNorm(v, tol, 0, _ex)); SIDL_CHECK(*_ex);
      if ( absDot <= (absNorms + fabs(tol)) ) {
        holds = TRUE;
      } else {
        holds = FALSE;
      }
    }
  
    EXIT:;
    return holds;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuSchwarzHolds) */
  }
}

/*
 * Return TRUE if the Minkowski (or triangle) inequality holds, within the
 * given tolerance; otherwise, return FALSE.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuTriIneqHolds"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_vect_Utils_vuTriIneqHolds(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ double tol,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuTriIneqHolds) */
    sidl_bool                  holds = FALSE;
    struct sidl_double__array* sum   = NULL;
    double absNormSum, normU, normV, absSumNorms;

    if ( (u != NULL) && (v != NULL) ) 
    {
      if (  (sidlArrayDim(u) == 1) && (sidlArrayDim(v) == 1) ) 
      {
        sum = impl_vect_Utils_vuSum(u,v,0,_ex); SIDL_CHECK(*_ex);
        absNormSum = fabs(impl_vect_Utils_vuNorm(sum, tol, 0, 
                          _ex)); SIDL_CHECK(*_ex);
        normU = impl_vect_Utils_vuNorm(u, tol, 0, _ex); SIDL_CHECK(*_ex);
        normV = impl_vect_Utils_vuNorm(v, tol, 0, _ex); SIDL_CHECK(*_ex);
        absSumNorms = fabs(normU + normV);
        if ( absNormSum <= (absSumNorms + fabs(tol)) ) {
          holds = TRUE;
        } else {
          holds = FALSE;
        }
      }
    }
  
    EXIT:;
    if (sum != NULL) sidl_double__array_deleteRef(sum);
    return holds;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuTriIneqHolds) */
  }
}

/*
 * double result operations 
 * Return the norm (or length) of the specified vector.
 * 
 * Note that the size exception is given here simply because the
 * implementation is leveraging the vuDot() method.  Also the tolerance
 * is included to enable the caller to specify the tolerance used in
 * contract checking.
 * 
 * Also note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a negative result (regardless of input);
 * 2 = Return a positive result not near zero (regardless of input), 
 * which means a violation will occur only if u is the zero
 * vector; and
 * 3 = Return a zero result (regardless of input), which means a
 * violation will occur only if u is not the zero vector.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuNorm"

#ifdef __cplusplus
extern "C"
#endif
double
impl_vect_Utils_vuNorm(
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ double tol,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuNorm) */
    double dot;
    double res = 0.0;
    char*  msg = "vuNorm: vNegValExcept: Cannot sqrt() a negative value.";
  
    if (badLevel == 0) 
    {
      if (u != NULL) 
      {
        dot = impl_vect_Utils_vuDot(u, u, tol, 0, _ex); SIDL_CHECK(*_ex);
        if (dot > 0.0) {
          res = (double) sqrt(dot);
        } else if (dot < 0.0) {
          /* Note that this should NEVER happen! */
          res = -5.0;
          SIDL_THROW(*_ex, vect_vNegValExcept, msg);
        }
      } 
    } else if (badLevel == 1) {
      res = -5.0;
    } else if (badLevel == 2) {
      res = 5.0;
    } else if (badLevel == 3) {
      res = 0.0;
    } else {
      res = -5.0;
    }
  
    EXIT:;
    return res;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuNorm) */
  }
}

/*
 * Return the dot (, inner, or scalar) product of the specified vectors.
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a negative result (regardless of input); and
 * 2 = Return a positive result not near zero (regardless of input), 
 * which means a violation will occur only if u and v are the zero
 * vector.
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuDot"

#ifdef __cplusplus
extern "C"
#endif
double
impl_vect_Utils_vuDot(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ double tol,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuDot) */
    double dot = 0.0;
    int    i, lenU, lenV;
  
    if (badLevel == 0) {
      if ( (u != NULL) && (v != NULL) ) 
      {
        lenU = sidlLength(u, 0);
        lenV = sidlLength(v, 0);
        if (  (lenU == lenV)
           && (sidlArrayDim(u) == 1) 
           && (sidlArrayDim(v) == 1) ) 
        {
          for (i=0; i < lenU; ++i) {
            dot += (sidlArrayElem1(u, i) * sidlArrayElem1(v, i));
          }
        }
      } 
    } else if (badLevel == 1) {
      dot = -5.0;
    } else if (badLevel == 2) {
      dot = 5.0;
    } else {
      dot = -1.0;
    }

    return dot;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuDot) */
  }
}

/*
 * vector result operations 
 * Return the (scalar) product of the specified vector.
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a null result (regardless of input);
 * 2 = Return a 2D array result (regardless of input); and
 * 3 = Return an array of a different size (regardless of input).
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuProduct"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_double__array*
impl_vect_Utils_vuProduct(
  /* in */ double a,
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuProduct) */
    struct sidl_double__array* prod = NULL;
    int    i, lenU;
  
    if (u != NULL) { lenU = sidlLength(u, 0); } else { lenU = 0; }
    if (badLevel == 0) 
    {
      if (u != NULL) 
      {
        prod = sidl_double__array_create1d(lenU);
        memset(sidl_double__array_first(prod), 0, 
               (size_t)(lenU * sizeof(double)));
        for (i=0; i < lenU; i++) {
          sidl_double__array_set1(prod, i, a * sidl_double__array_get1(u,i));
        }
      } 
    } else if (badLevel == 1) {
      prod = NULL;
    } else if (badLevel == 2) {
      prod = sidl_double__array_create2dCol(lenU, lenU);
    } else if (badLevel == 3) {
      prod = sidl_double__array_create1d(lenU+5);
    } else {
      prod = NULL;
    }

    return prod;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuProduct) */
  }
}

/*
 * Return the negation of the specified vector.
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a null result (regardless of input);
 * 2 = Return a 2D array result (regardless of input); and
 * 3 = Return an array of a different size (regardless of input).
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuNegate"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_double__array*
impl_vect_Utils_vuNegate(
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuNegate) */
    struct sidl_double__array* negU  = NULL;
    int                        lenU;
  
    if (u != NULL) { lenU = sidlLength(u, 0); } else { lenU = 0; }
    if (badLevel == 0) {
      if (u != NULL) {
        negU = impl_vect_Utils_vuProduct(-1.0, u, 0, _ex);  SIDL_CHECK(*_ex);
      } 
    } else if (badLevel == 1) {
      negU = NULL;
    } else if (badLevel == 2) {
      negU = sidl_double__array_create2dCol(lenU, lenU);
    } else if (badLevel == 3) {
      negU = sidl_double__array_create1d(lenU+5);
    } else {
      negU = NULL;
    }

    EXIT:;
    return negU;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuNegate) */
  }
}

/*
 * Return the normalizaton of the specified vector.
 * 
 * Note the tolerance is included because the implementation invokes 
 * vuDot().
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a null result (regardless of input);
 * 2 = Return a 2D array result (regardless of input); and
 * 3 = Return an array of a different size (regardless of input).
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuNormalize"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_double__array*
impl_vect_Utils_vuNormalize(
  /* in array<double> */ struct sidl_double__array* u,
  /* in */ double tol,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuNormalize) */
    struct sidl_double__array* prod  = NULL;
    int                        lenU;
    double                     val;
  
    if (u != NULL) { lenU = sidlLength(u, 0); } else { lenU = 0; }
    if (badLevel == 0) {
      if (u != NULL)
      {
        val = impl_vect_Utils_vuNorm(u, tol, 0, _ex); SIDL_CHECK(*_ex);
        if (val != 0.0) {
          prod = impl_vect_Utils_vuProduct(1.0/val, u, 0, 
                                             _ex); SIDL_CHECK(*_ex);
        } else {
          SIDL_THROW(*_ex, vect_vDivByZeroExcept, 
            "vuNormalize: vDivByZeroExcept: Cannot divide by zero."); 
        }
      }
    } else if (badLevel == 1) {
      prod = NULL;
    } else if (badLevel == 2) {
      prod = sidl_double__array_create2dCol(lenU, lenU);
    } else if (badLevel == 3) {
      prod = sidl_double__array_create1d(lenU+5);
    } else {
      prod = NULL;
    }
  
    EXIT:;
    return prod;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuNormalize) */
  }
}

/*
 * Return the sum of the specified vectors.
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a null result (regardless of input);
 * 2 = Return a 2D array result (regardless of input); and
 * 3 = Return an array of a different size (regardless of input).
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuSum"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_double__array*
impl_vect_Utils_vuSum(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuSum) */
    struct sidl_double__array* sum = NULL;
    int                        i, lenU, lenV;
  
    if (u != NULL) { lenU = sidlLength(u, 0); } else { lenU = 0; }
    if (badLevel == 0) 
    {
      if ( (u != NULL) && (v != NULL) ) 
      {
      lenV = sidlLength(v, 0);
        if (  (lenU == lenV)
           && (sidlArrayDim(u) == 1) 
           && (sidlArrayDim(v) == 1) ) 
        {
          sum = sidl_double__array_create1d(lenU);
          memset(sidl_double__array_first(sum), 0,
                 (size_t)(lenU * sizeof(double)));
          for (i=0; i < lenU; i++) {
            sidl_double__array_set1(sum, i, 
              sidl_double__array_get1(u,i) + sidl_double__array_get1(v,i));
          }
        }
      }
    } else if (badLevel == 1) {
      sum = NULL;
    } else if (badLevel == 2) {
      sum = sidl_double__array_create2dCol(lenU, lenU);
    } else if (badLevel == 3) {
      sum = sidl_double__array_create1d(lenU+5);
    } else {
      sum = NULL;
    }

    return sum;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuSum) */
  }
}

/*
 * Return the difference of the specified vectors.
 * 
 * Note that badLevel has been added only to facilitate regression
 * testing of postconditions.  The levels are:
 * 0 = NONE  (i.e., no deliberate postcondition violation);
 * 1 = Return a null result (regardless of input);
 * 2 = Return a 2D array result (regardless of input); and
 * 3 = Return an array of a different size (regardless of input).
 */

#undef __FUNC__
#define __FUNC__ "impl_vect_Utils_vuDiff"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_double__array*
impl_vect_Utils_vuDiff(
  /* in array<double> */ struct sidl_double__array* u,
  /* in array<double> */ struct sidl_double__array* v,
  /* in */ int32_t badLevel,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(vect.Utils.vuDiff) */
    struct sidl_double__array* diff  = NULL;
    int                        i, lenU, lenV;
  
    if (u != NULL) { lenU = sidlLength(u, 0); } else { lenU = 0; }
    if (badLevel == 0) 
    {
      if ( (u != NULL) && (v != NULL) ) 
      {
      lenV = sidlLength(v, 0);
        if (  (lenU == lenV)
           && (sidlArrayDim(u) == 1) 
           && (sidlArrayDim(v) == 1) ) 
        {
          diff = sidl_double__array_create1d(lenU);
          memset(sidl_double__array_first(diff), 0,
                 (size_t)(lenU * sizeof(double)));
          for (i=0; i < lenU; i++) {
            sidl_double__array_set1(diff, i, 
              sidl_double__array_get1(u,i) - sidl_double__array_get1(v,i));
          }
        }
      }
    } else if (badLevel == 1) {
      diff = NULL;
    } else if (badLevel == 2) {
      diff = sidl_double__array_create2dCol(lenU, lenU);
    } else if (badLevel == 3) {
      diff = sidl_double__array_create1d(lenU+5);
    } else {
      diff = NULL;
    }

    return diff;
    /* DO-NOT-DELETE splicer.end(vect.Utils.vuDiff) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Nothing needed here. */
/* DO-NOT-DELETE splicer.end(_misc) */

