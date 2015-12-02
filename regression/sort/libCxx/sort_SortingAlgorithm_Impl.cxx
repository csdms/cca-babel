// 
// File:          sort_SortingAlgorithm_Impl.cxx
// Symbol:        sort.SortingAlgorithm-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.SortingAlgorithm
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_SortingAlgorithm_Impl.hxx"

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
// DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._includes)
#include "sort_SimpleCounter.hxx"
// DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._includes)

// default constructor, not to be used!
// user defined constructor
void sort::SortingAlgorithm_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor)
  d_cmp = ::sort::SimpleCounter::_create();
  d_swp = ::sort::SimpleCounter::_create();
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor)
}

// user defined destructor
void sort::SortingAlgorithm_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor)
}

// static class initializer
void sort::SortingAlgorithm_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Return the comparison counter.
 */
::sort::Counter
sort::SortingAlgorithm_impl::getCompareCounter_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter)
  return d_cmp;
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter)
}

/**
 * Return the swap counter.
 */
::sort::Counter
sort::SortingAlgorithm_impl::getSwapCounter_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter)
  return d_swp;
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter)
}

/**
 * Reset the comparison and swap counter.
 */
void
sort::SortingAlgorithm_impl::reset_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset)
  d_cmp.reset();
  d_swp.reset();
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset)
}


// DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._misc)

