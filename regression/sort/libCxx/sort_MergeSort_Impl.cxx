// 
// File:          sort_MergeSort_Impl.cxx
// Symbol:        sort.MergeSort-v0.1
// Symbol Type:   class
// Babel Version: 2.0.0 (Revision: 7435  trunk)
// Description:   Server-side implementation for sort.MergeSort
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_MergeSort_Impl.hxx"

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
// DO-NOT-DELETE splicer.begin(sort.MergeSort._includes)
static void
mergeLists(::sort::Container  &elems,
           ::sort::Comparator &comp,
           ::sort::Counter    &cmp,
           ::sort::Counter    &swp,
           int32_t          start,
           int32_t          mid,
           const int32_t    end)
{
  int32_t j;
  while ((start < mid) && (mid < end)) {
    cmp.inc();
    if (elems.compare(start, mid, comp) > 0) {
      /* move first element of upper list into place */
      for(j = mid;j > start; --j) {
	swp.inc();
	elems.swap(j, j - 1);
      }
      ++mid;
    }
    ++start;
  }
}

/**
 * end is one past the end
 */
static void
mergeSort(::sort::Container  &elems,
          ::sort::Comparator &comp,
          ::sort::Counter    &cmp,
          ::sort::Counter    &swp,
          const int32_t   start,
          const int32_t   end)
{
  if ((end - start) > 1) {
    int32_t mid = (start + end) >> 1;
    mergeSort(elems, comp, cmp, swp, start, mid);
    mergeSort(elems, comp, cmp, swp, mid, end);
    mergeLists(elems, comp, cmp, swp, start, mid, end);
  }
}
// DO-NOT-DELETE splicer.end(sort.MergeSort._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::MergeSort_impl::MergeSort_impl() : StubBase(reinterpret_cast< void*>(
  ::sort::MergeSort::_wrapObj(reinterpret_cast< void*>(this))),false) , 
  _wrapped(true){ 
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor2)
  // Insert-Code-Here {sort.MergeSort._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.MergeSort._ctor2)
}

// user defined constructor
void sort::MergeSort_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor)
  // add construction details here
  // DO-NOT-DELETE splicer.end(sort.MergeSort._ctor)
}

// user defined destructor
void sort::MergeSort_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.MergeSort._dtor)
}

// static class initializer
void sort::MergeSort_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.MergeSort._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Sort elements using Merge Sort.
 */
void
sort::MergeSort_impl::sort_impl (
  /* in */::sort::Container& elems,
  /* in */::sort::Comparator& comp ) 
{
  // DO-NOT-DELETE splicer.begin(sort.MergeSort.sort)
  const int32_t num = elems.getLength();
  ::sort::Counter cmp = getCompareCounter();
  ::sort::Counter swp = getSwapCounter();
  mergeSort(elems, comp, cmp, swp, 0, num);
  // DO-NOT-DELETE splicer.end(sort.MergeSort.sort)
}

/**
 * Return merge sort.
 */
::std::string
sort::MergeSort_impl::getName_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.MergeSort.getName)
  return "Merge sort";
  // DO-NOT-DELETE splicer.end(sort.MergeSort.getName)
}


// DO-NOT-DELETE splicer.begin(sort.MergeSort._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.MergeSort._misc)

