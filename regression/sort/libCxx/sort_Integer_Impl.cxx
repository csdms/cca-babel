// 
// File:          sort_Integer_Impl.cxx
// Symbol:        sort.Integer-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.Integer
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_Integer_Impl.hxx"

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
// DO-NOT-DELETE splicer.begin(sort.Integer._includes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(sort.Integer._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::Integer_impl::Integer_impl() : StubBase(reinterpret_cast< void*>(
  ::sort::Integer::_wrapObj(reinterpret_cast< void*>(this))),false) , _wrapped(
  true){ 
  // DO-NOT-DELETE splicer.begin(sort.Integer._ctor2)
  // Insert-Code-Here {sort.Integer._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.Integer._ctor2)
}

// user defined constructor
void sort::Integer_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.Integer._ctor)
  d_num = 0;
  // DO-NOT-DELETE splicer.end(sort.Integer._ctor)
}

// user defined destructor
void sort::Integer_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.Integer._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.Integer._dtor)
}

// static class initializer
void sort::Integer_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.Integer._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.Integer._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Method:  getValue[]
 */
int32_t
sort::Integer_impl::getValue_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.Integer.getValue)
  return d_num;
  // DO-NOT-DELETE splicer.end(sort.Integer.getValue)
}

/**
 * Method:  setValue[]
 */
void
sort::Integer_impl::setValue_impl (
  /* in */int32_t value ) 
{
  // DO-NOT-DELETE splicer.begin(sort.Integer.setValue)
  d_num = value;
  // DO-NOT-DELETE splicer.end(sort.Integer.setValue)
}


// DO-NOT-DELETE splicer.begin(sort.Integer._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.Integer._misc)

