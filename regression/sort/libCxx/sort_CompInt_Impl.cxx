// 
// File:          sort_CompInt_Impl.cxx
// Symbol:        sort.CompInt-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.CompInt
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_CompInt_Impl.hxx"

// 
// Includes for all method dependencies.
// 
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
// DO-NOT-DELETE splicer.begin(sort.CompInt._includes)
#include "sort_Integer.hxx"
// DO-NOT-DELETE splicer.end(sort.CompInt._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::CompInt_impl::CompInt_impl() : StubBase(reinterpret_cast< void*>(
  ::sort::CompInt::_wrapObj(reinterpret_cast< void*>(this))),false) , _wrapped(
  true){ 
  // DO-NOT-DELETE splicer.begin(sort.CompInt._ctor2)
  // Insert-Code-Here {sort.CompInt._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.CompInt._ctor2)
}

// user defined constructor
void sort::CompInt_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.CompInt._ctor)
  d_increasing = true;
  // DO-NOT-DELETE splicer.end(sort.CompInt._ctor)
}

// user defined destructor
void sort::CompInt_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.CompInt._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.CompInt._dtor)
}

// static class initializer
void sort::CompInt_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.CompInt._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.CompInt._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * If increasing is true, this will cause the comparator to
 * report a normal definition of less than; otherwise, it will
 * reverse the normal ordering.
 */
void
sort::CompInt_impl::setSortIncreasing_impl (
  /* in */bool increasing ) 
{
  // DO-NOT-DELETE splicer.begin(sort.CompInt.setSortIncreasing)
  d_increasing = increasing;
  // DO-NOT-DELETE splicer.end(sort.CompInt.setSortIncreasing)
}

/**
 * This method is used to define an ordering of objects.  This method
 * will return -1 if i1 < i2, 0 if i1 = i2; and 1 if i1 > i2.
 */
int32_t
sort::CompInt_impl::compare_impl (
  /* in */::sidl::BaseInterface& i1,
  /* in */::sidl::BaseInterface& i2 ) 
{
  // DO-NOT-DELETE splicer.begin(sort.CompInt.compare)
  int32_t result = 0;
  ::sort::Integer int1 = ::sidl::babel_cast< ::sort::Integer>(i1);
  ::sort::Integer int2 = ::sidl::babel_cast< ::sort::Integer>(i2);
  if (int1._not_nil() && int2._not_nil()) {
    const int32_t val1 = int1.getValue();
    const int32_t val2 = int2.getValue();
    if (val1 < val2) result = -1;
    if (val1 > val2) result = 1;
    if (!d_increasing) result = -result;
  }
  return result;
  // DO-NOT-DELETE splicer.end(sort.CompInt.compare)
}


// DO-NOT-DELETE splicer.begin(sort.CompInt._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.CompInt._misc)

