/*
 * File:          sort_QuickSort_Impl.c
 * Symbol:        sort.QuickSort-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.QuickSort
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.QuickSort" (version 0.1)
 * 
 * Quick sort
 */

#include "sort_QuickSort_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.QuickSort._includes) */
#include "sort_Container.h"
#include "sort_Counter.h"
#include "sort_Comparator.h"
#include "sidl_String.h"
#include <stdio.h>
#include "sidl_Exception.h"

/**
 * Choose the middle of the first, middle and last element of the
 * list.  For small lists, return the middle without checking.
 */
static int32_t
choosePivot(sort_Container  elems,
            sort_Comparator comp,
            sort_Counter    cmp,
            int32_t         start,
            int32_t         end, 
            sidl_BaseInterface *_ex)
{
  int32_t pivot = (start + end) >> 1;
  if ((end - start) > 4) {
    int32_t mid = pivot;
    sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
    if (sort_Container_compare(elems, start, mid, comp, _ex) <= 0) {
      SIDL_REPORT(*_ex);
      sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
      if (sort_Container_compare(elems, mid, end - 1, comp, _ex) > 0) {
        SIDL_REPORT(*_ex);
        sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
        if (sort_Container_compare(elems, start, end - 1, comp, _ex) < 0) {
          SIDL_REPORT(*_ex);
          pivot = end - 1;
        }
        else {
          SIDL_REPORT(*_ex);
          pivot = start;
        }
      }
    }
    else {
      SIDL_REPORT(*_ex);
      sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
      if (sort_Container_compare(elems, mid, end - 1, comp, _ex) < 0) {
        SIDL_REPORT(*_ex);
        sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
        if (sort_Container_compare(elems, start, end - 1, comp, _ex) > 0) {
          SIDL_REPORT(*_ex);
          pivot = end - 1;
        }
        else {
          SIDL_REPORT(*_ex);
          pivot = start;
        }
      }
    }
  }
 EXIT:
  return pivot;
}

static void 
quickSort(sort_Container  elems,
          sort_Comparator comp,
          sort_Counter    cmp,
          sort_Counter    swp,
          int32_t         start,
          int32_t         end,
          sidl_BaseInterface *_ex)
{
  if ((end - start) > 1) {
    int32_t i = start;
    int32_t j = end;
    int32_t pivot = choosePivot(elems, comp, cmp, start, end, _ex); SIDL_REPORT(*_ex);
    if (pivot != start) {
      sort_Counter_inc(swp, _ex); SIDL_REPORT(*_ex);

      sort_Container_swap(elems, start, pivot, _ex); SIDL_REPORT(*_ex);
    }
    for(;;) {
      do {
        SIDL_REPORT(*_ex);
        --j;
        sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
      } while (sort_Container_compare(elems, start, j, comp, _ex) < 0);
      SIDL_REPORT(*_ex);
      while (++i < j) {
        const int icmp = sort_Container_compare(elems, start, i, comp, _ex); 
        SIDL_REPORT(*_ex);
        sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
        if (icmp < 0) break;
      }
      if (i >= j) break;
      sort_Counter_inc(swp, _ex); SIDL_REPORT(*_ex);
      sort_Container_swap(elems, i, j, _ex); SIDL_REPORT(*_ex);
    }
    if (j != start) {
      sort_Counter_inc(swp, _ex); SIDL_REPORT(*_ex);
      sort_Container_swap(elems, start, j, _ex); SIDL_REPORT(*_ex);
    }
    quickSort(elems, comp, cmp, swp, start, j, _ex); SIDL_REPORT(*_ex);
    quickSort(elems, comp, cmp, swp, j + 1, end, _ex); SIDL_REPORT(*_ex);
  }
 EXIT:;
}
/* DO-NOT-DELETE splicer.end(sort.QuickSort._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_QuickSort__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.QuickSort._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_QuickSort__ctor(
  /* in */ sort_QuickSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.QuickSort._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_QuickSort__ctor2(
  /* in */ sort_QuickSort self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor2) */
  /* Insert-Code-Here {sort.QuickSort._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.QuickSort._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_QuickSort__dtor(
  /* in */ sort_QuickSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.QuickSort._dtor) */
  }
}

/*
 * Sort elements using Quick Sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort_sort"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_QuickSort_sort(
  /* in */ sort_QuickSort self,
  /* in */ sort_Container elems,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort.sort) */
  sort_Counter cmp = NULL;
  sort_Counter swp = NULL;
  const int32_t num = sort_Container_getLength(elems, _ex); SIDL_REPORT(*_ex);
  cmp = sort_QuickSort_getCompareCounter(self, _ex); SIDL_REPORT(*_ex);
  swp = sort_QuickSort_getSwapCounter(self, _ex); SIDL_REPORT(*_ex);
  quickSort(elems, comp, cmp, swp, 0, num, _ex); SIDL_REPORT(*_ex);
 EXIT:
  {
    sidl_BaseInterface throwaway_exception;
    if (cmp) sort_Counter_deleteRef(cmp, &throwaway_exception);
    if (swp) sort_Counter_deleteRef(swp, &throwaway_exception);
  }
    /* DO-NOT-DELETE splicer.end(sort.QuickSort.sort) */
  }
}

/*
 * Return quick sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_QuickSort_getName"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sort_QuickSort_getName(
  /* in */ sort_QuickSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.QuickSort.getName) */
  return sidl_String_strdup("Quick sort");
    /* DO-NOT-DELETE splicer.end(sort.QuickSort.getName) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

