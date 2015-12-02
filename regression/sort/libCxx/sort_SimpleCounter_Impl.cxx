// 
// File:          sort_SimpleCounter_Impl.cxx
// Symbol:        sort.SimpleCounter-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.SimpleCounter
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_SimpleCounter_Impl.hxx"

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
// DO-NOT-DELETE splicer.begin(sort.SimpleCounter._includes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(sort.SimpleCounter._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::SimpleCounter_impl::SimpleCounter_impl() : StubBase(reinterpret_cast< 
  void*>(::sort::SimpleCounter::_wrapObj(reinterpret_cast< void*>(this))),
  false) , _wrapped(true){ 
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor2)
  // Insert-Code-Here {sort.SimpleCounter._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor2)
}

// user defined constructor
void sort::SimpleCounter_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor)
  d_counter = 0;
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor)
}

// user defined destructor
void sort::SimpleCounter_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor)
}

// static class initializer
void sort::SimpleCounter_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Set the count to zero.
 */
void
sort::SimpleCounter_impl::reset_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset)
  d_counter = 0;
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset)
}

/**
 * Return the current count.
 */
int32_t
sort::SimpleCounter_impl::getCount_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount)
  return d_counter;
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount)
}

/**
 * Increment the count (i.e. add one).
 */
int32_t
sort::SimpleCounter_impl::inc_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc)
  return ++d_counter;
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc)
}


// DO-NOT-DELETE splicer.begin(sort.SimpleCounter._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.SimpleCounter._misc)

