/*
 * File:          sort_SortTest_Impl.c
 * Symbol:        sort.SortTest-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.SortTest
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.SortTest" (version 0.1)
 * 
 * Run a bunch of sorts through a stress test.
 */

#include "sort_SortTest_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.SortTest._includes) */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort_CompInt.h"
#include "sort_IntegerContainer.h"
#include "synch.h"
#include "sidl_BaseInterface.h"
#include "sidl_Exception.h"

static const int32_t s_testSizes[] = {
  0,
  1,
  2,
  3,
  4,
  7,
  10,
  51,
  64,
  -1
};

static int
notSorted(sort_Container cont,
          sort_Comparator comp)
{
  sidl_BaseInterface exception;
  int32_t i;
  const int32_t length = sort_Container_getLength(cont, &exception);
  SIDL_REPORT(exception);
  for(i = 1 ; i < length ; ++i ){
    const int32_t cmp = sort_Container_compare(cont, i-1, i, comp, &exception);
    SIDL_REPORT(exception);
    if (cmp > 0) return TRUE;
  }
  return FALSE;
 EXIT:
  SIDL_CLEAR(exception);
  return TRUE;
}

static void
sortAndReport(sort_SortingAlgorithm alg,
              sort_Container cont,
              sort_Comparator comp,
              sidl_bool *result)
{
  sidl_BaseInterface exception = NULL;
  char buffer[64];
  int32_t comp_count, swap_count;
  sort_Counter swpCnt = NULL;
  sort_Counter cmpCnt = NULL;
  synch_RegOut tracker = synch_RegOut_getInstance(&exception);
  SIDL_REPORT(exception);
  sort_SortingAlgorithm_reset(alg, &exception); SIDL_REPORT(exception);
  sort_SortingAlgorithm_sort(alg, cont, comp, &exception); 
  SIDL_REPORT(exception);
  swpCnt = sort_SortingAlgorithm_getSwapCounter(alg, &exception);
  SIDL_REPORT(exception);
  cmpCnt = sort_SortingAlgorithm_getCompareCounter(alg, &exception);
  SIDL_REPORT(exception);
  comp_count = sort_Counter_getCount(cmpCnt, &exception); SIDL_REPORT(exception);
  swap_count = sort_Counter_getCount(swpCnt, &exception); SIDL_REPORT(exception);
  sprintf(buffer, "compares (%d) swaps (%d)", comp_count, swap_count);
  synch_RegOut_writeComment(tracker, buffer, &exception); SIDL_REPORT(exception);
  if (notSorted(cont, comp)) {
    *result = FALSE;
    synch_RegOut_writeComment(tracker, "sort failed!!", &exception);
    SIDL_REPORT(exception);
  }
 EXIT:
  {
    sidl_BaseInterface throwaway_exception;
    if (exception) {
      *result = FALSE;
      if (tracker) synch_RegOut_forceFailure(tracker, &throwaway_exception);
      SIDL_CLEAR(exception);
    }
    if (tracker) synch_RegOut_deleteRef(tracker, &throwaway_exception);
    if (cmpCnt) sort_Counter_deleteRef(cmpCnt, &throwaway_exception);
    if (swpCnt) sort_Counter_deleteRef(swpCnt, &throwaway_exception);
  }
}
/* DO-NOT-DELETE splicer.end(sort.SortTest._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortTest__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortTest__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortTest._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.SortTest._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortTest__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortTest__ctor(
  /* in */ sort_SortTest self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortTest._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.SortTest._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortTest__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortTest__ctor2(
  /* in */ sort_SortTest self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortTest._ctor2) */
  /* Insert-Code-Here {sort.SortTest._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.SortTest._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortTest__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortTest__dtor(
  /* in */ sort_SortTest self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortTest._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.SortTest._dtor) */
  }
}

/*
 * Perform the array stress test.
 * 
 * Return true if all the algorithms work okay.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortTest_stressTest"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_sort_SortTest_stressTest(
  /* in array<sort.SortingAlgorithm> */ struct sort_SortingAlgorithm__array* 
    algs,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortTest.stressTest) */
  sidl_bool result = FALSE;
  if (algs) {
    const int32_t lower = sort_SortingAlgorithm__array_lower(algs, 0);
    const int32_t upper = sort_SortingAlgorithm__array_upper(algs, 0);
    int32_t i,j;
    result = TRUE;
    for(i = lower; i <= upper; ++i) {
      sort_SortingAlgorithm alg =
        sort_SortingAlgorithm__array_get1(algs, i);
      if (alg) {
        synch_RegOut tracker = NULL;
        sort_IntegerContainer data = NULL;
        sort_Container cont = NULL;
        sort_CompInt intcomp = NULL;
        sort_Comparator comp = NULL;
        char *name = NULL;
        char *buffer = NULL;
        name = sort_SortingAlgorithm_getName(alg, _ex); SIDL_REPORT(*_ex);
        buffer = malloc(25 + strlen(name) + 14);
        tracker = synch_RegOut_getInstance(_ex); SIDL_REPORT(*_ex);
        data = sort_IntegerContainer__create(_ex); SIDL_REPORT(*_ex);
        cont  = sort_Container__cast(data, _ex); SIDL_REPORT(*_ex);
        intcomp = sort_CompInt__create(_ex); SIDL_REPORT(*_ex);
        comp = sort_Comparator__cast(intcomp, _ex); SIDL_REPORT(*_ex);
        j = 0;
        sprintf(buffer, "****ALGORITHM IS %s****", name);
        synch_RegOut_writeComment(tracker, buffer, _ex); SIDL_REPORT(*_ex);
        free((void *)name);
        while (s_testSizes[j] >= 0) {
          sort_CompInt_setSortIncreasing(intcomp, TRUE, _ex); SIDL_REPORT(*_ex);
          sprintf(buffer, "DATA SIZE %d", s_testSizes[j]);
          synch_RegOut_writeComment(tracker, buffer, _ex); SIDL_REPORT(*_ex);
          sort_IntegerContainer_setLength(data, s_testSizes[j], _ex); SIDL_REPORT(*_ex);
          sortAndReport(alg, cont, comp, &result);
          synch_RegOut_writeComment(tracker, "pre-sorted list", _ex); SIDL_REPORT(*_ex);
          sortAndReport(alg, cont, comp, &result);
          synch_RegOut_writeComment(tracker, "reverse sorted list", _ex); SIDL_REPORT(*_ex);
          sort_CompInt_setSortIncreasing(intcomp, FALSE, _ex); SIDL_REPORT(*_ex);
          sortAndReport(alg, cont, comp, &result);
          ++j;
        }
        if (buffer) free(buffer);
      EXIT:
        {
          sidl_BaseInterface throwaway_exception;
          if (*_ex) {
            result = FALSE;
            if (tracker) 
              synch_RegOut_forceFailure(tracker, &throwaway_exception);
          }
          if (cont) sort_Container_deleteRef(cont, &throwaway_exception);
          if (data)
            sort_IntegerContainer_deleteRef(data, &throwaway_exception);
          if (alg) sort_SortingAlgorithm_deleteRef(alg, &throwaway_exception);
          if (comp) sort_Comparator_deleteRef(comp, &throwaway_exception);
          if (intcomp) sort_CompInt_deleteRef(intcomp, &throwaway_exception);
          if (tracker) synch_RegOut_deleteRef(tracker, &throwaway_exception);
        }
      }
      else{
        result = FALSE;
      }
    }
  }
  fflush(stdout);
  return result;
    /* DO-NOT-DELETE splicer.end(sort.SortTest.stressTest) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

