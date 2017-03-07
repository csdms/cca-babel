// 
// File:          sort_QuickSort_Impl.cxx
// Symbol:        sort.QuickSort-v0.1
// Symbol Type:   class
// Babel Version: 2.0.0 (Revision: 7435  trunk)
// Description:   Server-side implementation for sort.QuickSort
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_QuickSort_Impl.hxx"

// 
// Includes for all method dependencies.
// 
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sort_Comparator_hxx
#include "sort_Comparator.hxx"
#endif
#ifndef included_sort_Container_hxx
#include "sort_Container.hxx"
#endif
#ifndef included_sort_Counter_hxx
#include "sort_Counter.hxx"
#endif
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
// DO-NOT-DELETE splicer.begin(sort.QuickSort._includes)
/**
 * Choose the middle of the first, middle and last element of the
 * list.  For small lists, return the middle without checking.
 */
static int32_t
choosePivot(::sort::Container  &elems,
            ::sort::Comparator &comp,
            ::sort::Counter    &cmp,
            int32_t           start,
            int32_t           end)
{
  int32_t pivot = (start + end) >> 1;
  if ((end - start) > 4) {
    int32_t mid = pivot;
    cmp.inc();
    if (elems.compare(start, mid, comp) <= 0) {
      cmp.inc();
      if (elems.compare(mid, end - 1, comp) > 0) {
        cmp.inc();
        if (elems.compare( start, end - 1, comp) < 0) {
          pivot = end - 1;
        }
        else {
          pivot = start;
        }
      }
    }
    else {
      cmp.inc();
      if (elems.compare( mid, end - 1, comp) < 0) {
        cmp.inc();
        if (elems.compare( start, end - 1, comp) > 0) {
          pivot = end - 1;
        }
        else {
          pivot = start;
        }
      }
    }
  }
  return pivot;
}

static void 
quickSort(::sort::Container  &elems,
          ::sort::Comparator &comp,
          ::sort::Counter    &cmp,
          ::sort::Counter    &swp,
          int32_t           start,
          int32_t           end)
{
  if ((end - start) > 1) {
    int32_t pivot = choosePivot(elems, comp, cmp, start, end);
    int32_t i = start;
    int32_t j = end;
    if (pivot != start) {
      swp.inc();
      elems.swap(start, pivot);
    }
    for(;;) {
      do {
        --j;
        cmp.inc();
      } while (elems.compare( start, j, comp) < 0);
      while (++i < j) {
        cmp.inc();
        if (elems.compare( start, i, comp) < 0) break;
      }
      if (i >= j) break;
      swp.inc();
      elems.swap(i, j);
    }
    if (j != start) {
      swp.inc();
      elems.swap(start, j);
    }
    quickSort(elems, comp, cmp, swp, start, j);
    quickSort(elems, comp, cmp, swp, j + 1, end);
  }
}
// DO-NOT-DELETE splicer.end(sort.QuickSort._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::QuickSort_impl::QuickSort_impl() : StubBase(reinterpret_cast< void*>(
  ::sort::QuickSort::_wrapObj(reinterpret_cast< void*>(this))),false) , 
  _wrapped(true){ 
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor2)
  // Insert-Code-Here {sort.QuickSort._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.QuickSort._ctor2)
}

// user defined constructor
void sort::QuickSort_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor)
  // add construction details here
  // DO-NOT-DELETE splicer.end(sort.QuickSort._ctor)
}

// user defined destructor
void sort::QuickSort_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.QuickSort._dtor)
}

// static class initializer
void sort::QuickSort_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.QuickSort._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Sort elements using Quick Sort.
 */
void
sort::QuickSort_impl::sort_impl (
  /* in */::sort::Container& elems,
  /* in */::sort::Comparator& comp ) 
{
  // DO-NOT-DELETE splicer.begin(sort.QuickSort.sort)
  const int32_t num = elems.getLength();
  ::sort::Counter cmp = getCompareCounter();
  ::sort::Counter swp = getSwapCounter();
  quickSort(elems, comp, cmp, swp, 0, num);
  // DO-NOT-DELETE splicer.end(sort.QuickSort.sort)
}

/**
 * Return quick sort.
 */
::std::string
sort::QuickSort_impl::getName_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.QuickSort.getName)
  return "Quick sort";
  // DO-NOT-DELETE splicer.end(sort.QuickSort.getName)
}


// DO-NOT-DELETE splicer.begin(sort.QuickSort._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.QuickSort._misc)

