/*
 * File:          sort_MergeSort_Impl.c
 * Symbol:        sort.MergeSort-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.MergeSort
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.MergeSort" (version 0.1)
 * 
 * Merge sort
 */

#include "sort_MergeSort_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.MergeSort._includes) */
#include "sort_Container.h"
#include "sort_Comparator.h"
#include "sort_Counter.h"
#include "sidl_String.h"
#include "sidl_Exception.h"

static void
mergeLists(sort_Container  elems,
           sort_Comparator comp,
           sort_Counter    cmp,
           sort_Counter    swp,
           int32_t         start,
           int32_t         mid,
           const int32_t   end, 
           sidl_BaseInterface *_ex)
{
  int32_t j;
  while ((start < mid) && (mid < end)) {
    sort_Counter_inc(cmp, _ex); SIDL_REPORT(*_ex);
    if (sort_Container_compare(elems, start, mid, comp, _ex) > 0) {
      SIDL_REPORT(*_ex);
      /* move first element of upper list into place */
      for(j = mid;j > start; --j) {
        sort_Counter_inc(swp, _ex);  SIDL_REPORT(*_ex);
        sort_Container_swap(elems, j, j - 1, _ex); SIDL_REPORT(*_ex);
      }
      ++mid;
    }
    ++start;
  }
 EXIT:;
}

/**
 * end is one past the end
 */
static void
mergeSort(sort_Container  elems,
          sort_Comparator comp,
          sort_Counter    cmp,
          sort_Counter    swp,
          const int32_t   start,
          const int32_t   end,
          sidl_BaseInterface *_ex)
{
  if ((end - start) > 1) {
    int32_t mid = (start + end) >> 1;
    mergeSort(elems, comp, cmp, swp, start, mid, _ex); SIDL_REPORT(*_ex);
    mergeSort(elems, comp, cmp, swp, mid, end, _ex); SIDL_REPORT(*_ex);
    mergeLists(elems, comp, cmp, swp, start, mid, end, _ex); SIDL_REPORT(*_ex);
  }
 EXIT:;
}
/* DO-NOT-DELETE splicer.end(sort.MergeSort._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_MergeSort__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.MergeSort._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_MergeSort__ctor(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.MergeSort._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_MergeSort__ctor2(
  /* in */ sort_MergeSort self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor2) */
  /* Insert-Code-Here {sort.MergeSort._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.MergeSort._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_MergeSort__dtor(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.MergeSort._dtor) */
  }
}

/*
 * Sort elements using Merge Sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort_sort"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_MergeSort_sort(
  /* in */ sort_MergeSort self,
  /* in */ sort_Container elems,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort.sort) */
  sort_Counter cmp = NULL;
  sort_Counter swp = NULL;
  const int32_t num = sort_Container_getLength(elems, _ex); SIDL_REPORT(*_ex);
  cmp = sort_MergeSort_getCompareCounter(self, _ex); SIDL_REPORT(*_ex);
  swp = sort_MergeSort_getSwapCounter(self, _ex); SIDL_REPORT(*_ex);
  mergeSort(elems, comp, cmp, swp, 0, num, _ex); SIDL_REPORT(*_ex);
 EXIT:
  {
    sidl_BaseInterface throwaway_exception = NULL;
    if (cmp) sort_Counter_deleteRef(cmp,&throwaway_exception);
    if (swp) sort_Counter_deleteRef(swp, &throwaway_exception);
  }
    /* DO-NOT-DELETE splicer.end(sort.MergeSort.sort) */
  }
}

/*
 * Return merge sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_MergeSort_getName"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sort_MergeSort_getName(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.MergeSort.getName) */
  return sidl_String_strdup("Merge sort");
    /* DO-NOT-DELETE splicer.end(sort.MergeSort.getName) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

