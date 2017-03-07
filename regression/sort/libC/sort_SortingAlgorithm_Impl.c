/*
 * File:          sort_SortingAlgorithm_Impl.c
 * Symbol:        sort.SortingAlgorithm-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.SortingAlgorithm
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.SortingAlgorithm" (version 0.1)
 * 
 * An abstract sorting algorithm.
 */

#include "sort_SortingAlgorithm_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._includes) */
#include <stdlib.h>
#include "sort_SimpleCounter.h"
#include "sidl_Exception.h"
/* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortingAlgorithm__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortingAlgorithm__ctor(
  /* in */ sort_SortingAlgorithm self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor) */
  struct sort_SortingAlgorithm__data *dptr = 
    malloc(sizeof(struct sort_SortingAlgorithm__data ));
  if (dptr) {
    sort_SimpleCounter sc;
    dptr->d_swp = NULL;
    dptr->d_cmp = NULL;
    sc = sort_SimpleCounter__create(_ex); SIDL_REPORT(*_ex);
    dptr->d_swp = sort_Counter__cast(sc, _ex); SIDL_REPORT(*_ex);
    sort_SimpleCounter_deleteRef(sc, _ex); SIDL_REPORT(*_ex);
    sc = sort_SimpleCounter__create(_ex); SIDL_REPORT(*_ex);
    dptr->d_cmp = sort_Counter__cast(sc, _ex); SIDL_REPORT(*_ex);
    sort_SimpleCounter_deleteRef(sc, _ex); SIDL_REPORT(*_ex);
  }
  sort_SortingAlgorithm__set_data(self, dptr);
  return;
 EXIT:
  {
    sidl_BaseInterface throwaway_exception;
    if (dptr) {
      if (dptr->d_swp)
        sort_Counter_deleteRef(dptr->d_swp, &throwaway_exception);
      if (dptr->d_cmp)
        sort_Counter_deleteRef(dptr->d_cmp, &throwaway_exception);
      free(dptr);
    }
  } 
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortingAlgorithm__ctor2(
  /* in */ sort_SortingAlgorithm self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor2) */
  /* Insert-Code-Here {sort.SortingAlgorithm._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortingAlgorithm__dtor(
  /* in */ sort_SortingAlgorithm self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor) */
  sidl_BaseInterface throwaway_exception;
  struct sort_SortingAlgorithm__data *dptr = 
    sort_SortingAlgorithm__get_data(self);
  if (dptr) {
    sort_Counter_deleteRef(dptr->d_swp, &throwaway_exception);
    dptr->d_swp = NULL;
    sort_Counter_deleteRef(dptr->d_cmp, &throwaway_exception);
    dptr->d_cmp = NULL;
    free((void *)dptr);
  }
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor) */
  }
}

/*
 * Return the comparison counter.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm_getCompareCounter"

#ifdef __cplusplus
extern "C"
#endif
sort_Counter
impl_sort_SortingAlgorithm_getCompareCounter(
  /* in */ sort_SortingAlgorithm self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter) */
  struct sort_SortingAlgorithm__data *dptr = 
    sort_SortingAlgorithm__get_data(self);
  sort_Counter result = NULL;
  if (dptr) {
    sort_Counter_addRef(dptr->d_cmp, _ex); SIDL_REPORT(*_ex);
    result = dptr->d_cmp;
  }
 EXIT:
  return result;
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter) */
  }
}

/*
 * Return the swap counter.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm_getSwapCounter"

#ifdef __cplusplus
extern "C"
#endif
sort_Counter
impl_sort_SortingAlgorithm_getSwapCounter(
  /* in */ sort_SortingAlgorithm self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter) */
  struct sort_SortingAlgorithm__data *dptr = 
    sort_SortingAlgorithm__get_data(self);
  sort_Counter result = NULL;
  if (dptr) {
    sort_Counter_addRef(dptr->d_swp, _ex); SIDL_REPORT(*_ex);
    result = dptr->d_swp;
  }
 EXIT:
  return result;
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter) */
  }
}

/*
 * Reset the comparison and swap counter.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SortingAlgorithm_reset"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SortingAlgorithm_reset(
  /* in */ sort_SortingAlgorithm self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset) */
  struct sort_SortingAlgorithm__data *dptr = 
    sort_SortingAlgorithm__get_data(self);
  if (dptr) {
    sort_Counter_reset(dptr->d_swp, _ex); SIDL_REPORT(*_ex);
    sort_Counter_reset(dptr->d_cmp, _ex); SIDL_REPORT(*_ex);
  }
 EXIT:;
    /* DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

