/*
 * File:          sort_HeapSort_Impl.c
 * Symbol:        sort.HeapSort-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.HeapSort
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.HeapSort" (version 0.1)
 * 
 * Heap sort
 */

#include "sort_HeapSort_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.HeapSort._includes) */
#include "sidl_String.h"
#include "sort_Container.h"

static void remakeHeap(sort_Container elem,
                       sort_Comparator comp,
                       sort_Counter cmp,
                       sort_Counter swp,
                       const int32_t last,
                       int32_t first)
{
  sidl_BaseInterface throwaway_exception;
  const int32_t half = (last >> 1) - 1;
  int32_t child;
  while (first <= half) {
    child = first + first + 1;
    if ((child+1) < last) {
      sort_Counter_inc(cmp, &throwaway_exception);
      if (sort_Container_compare(elem, child, child+1, comp, &throwaway_exception) < 0) ++child;
    }
    sort_Counter_inc(cmp, &throwaway_exception);
    if (sort_Container_compare(elem,first, child,comp, &throwaway_exception) >= 0) break;
    sort_Counter_inc(swp, &throwaway_exception);
    sort_Container_swap(elem, first, child, &throwaway_exception);
    first = child;
  }
}
/* DO-NOT-DELETE splicer.end(sort.HeapSort._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_HeapSort__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.HeapSort._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_HeapSort__ctor(
  /* in */ sort_HeapSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.HeapSort._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_HeapSort__ctor2(
  /* in */ sort_HeapSort self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor2) */
  /* Insert-Code-Here {sort.HeapSort._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.HeapSort._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_HeapSort__dtor(
  /* in */ sort_HeapSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(sort.HeapSort._dtor) */
  }
}

/*
 * Sort elements using Heap Sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort_sort"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_HeapSort_sort(
  /* in */ sort_HeapSort self,
  /* in */ sort_Container elems,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort.sort) */
  int32_t i;
  const int32_t num = sort_Container_getLength(elems, _ex);
  sort_Counter cmp = sort_HeapSort_getCompareCounter(self, _ex);
  sort_Counter swp = sort_HeapSort_getSwapCounter(self, _ex);
  /* make the heap */
  for(i = ((num/2) - 1); i >= 0; --i) {
    remakeHeap(elems, comp, cmp, swp, num, i);
  }
  /* put top of heap at back and remake the heap */
  i = num - 1;
  while (i > 0) {
    sort_Counter_inc(swp, _ex);
    sort_Container_swap(elems, 0, i, _ex);
    remakeHeap(elems, comp, cmp, swp, i--, 0);
  }
  sort_Counter_deleteRef(cmp, _ex);
  sort_Counter_deleteRef(swp, _ex);
    /* DO-NOT-DELETE splicer.end(sort.HeapSort.sort) */
  }
}

/*
 * Return heap sort.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_HeapSort_getName"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sort_HeapSort_getName(
  /* in */ sort_HeapSort self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.HeapSort.getName) */
  return sidl_String_strdup("Heap sort");
    /* DO-NOT-DELETE splicer.end(sort.HeapSort.getName) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

