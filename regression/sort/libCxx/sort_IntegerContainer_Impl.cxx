// 
// File:          sort_IntegerContainer_Impl.cxx
// Symbol:        sort.IntegerContainer-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.IntegerContainer
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "sort_IntegerContainer_Impl.hxx"

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
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
// DO-NOT-DELETE splicer.begin(sort.IntegerContainer._includes)
#include <stdio.h>
#include "synch_RegOut.hxx"

static std::string
intToString(int i)
{
  char buf[64];
  sprintf(buf,"%d", i);
  return buf;
}
// DO-NOT-DELETE splicer.end(sort.IntegerContainer._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
sort::IntegerContainer_impl::IntegerContainer_impl() : StubBase(
  reinterpret_cast< void*>(::sort::IntegerContainer::_wrapObj(reinterpret_cast< 
  void*>(this))),false) , _wrapped(true){ 
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor2)
  // Insert-Code-Here {sort.IntegerContainer._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor2)
}

// user defined constructor
void sort::IntegerContainer_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor)
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor)
}

// user defined destructor
void sort::IntegerContainer_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor)
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor)
}

// static class initializer
void sort::IntegerContainer_impl::_load() {
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * This sets the container length and pseudo-randomly orders the
 * Integer elements contained.
 */
void
sort::IntegerContainer_impl::setLength_impl (
  /* in */int32_t len ) 
{
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength)
  int32_t i, j;
  d_elements = ::sidl::array< ::sort::Integer>::create1d(len);
  for(i = 0; i < len; ++i){
    ::sort::Integer intObj = ::sort::Integer::_create();
    intObj.setValue(i);
    d_elements.set(i, intObj);
  }
  for(i = len - 1; i > 0; --i) {
    j = random() % (i + 1);
    if (j != i) {
      swap(i, j);
    }
  }
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength)
}

/**
 * Return the number of elements in the container.
 */
int32_t
sort::IntegerContainer_impl::getLength_impl () 

{
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength)
  return 1 + d_elements.upper(0) - d_elements.lower(0);
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength)
}

/**
 * Return -1 if element i is less than element j, 0 if element i
 * is equal to element j, or otherwise 1.
 */
int32_t
sort::IntegerContainer_impl::compare_impl (
  /* in */int32_t i,
  /* in */int32_t j,
  /* in */::sort::Comparator& comp ) 
{
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare)
  ::sidl::BaseInterface i1(d_elements.get(i));
  ::sidl::BaseInterface i2(d_elements.get(j));
  return comp.compare(i1, i2);
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare)
}

/**
 * Swap elements i and j.
 */
void
sort::IntegerContainer_impl::swap_impl (
  /* in */int32_t i,
  /* in */int32_t j ) 
{
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap)
  const int32_t len = getLength();
  if (i >= 0 && j >= 0 && i < len && j < len) {
    ::sort::Integer 
      i1(d_elements.get(i)),
      i2(d_elements.get(j));
    d_elements.set(i, i2);
    d_elements.set(j, i1);
  }
  else {
    std::string msg = 
      std::string("sort::IntegerContainer::swap index out of bounds ") +
      intToString(i) + ", " + intToString(j) + ") len (" + 
      intToString(len) + ")\n";
    ::synch::RegOut::getInstance().writeComment(msg);
    ::synch::RegOut::getInstance().forceFailure();
  }
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap)
}

/**
 * Print elements s through e-1
 */
void
sort::IntegerContainer_impl::output_impl (
  /* in */int32_t s,
  /* in */int32_t e ) 
{
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output)
  std::string msg = "list";
  while (s < e) {
    msg += ' ';
    msg += intToString(d_elements.get(s++).getValue());
  }
  ::synch::RegOut::getInstance().writeComment(msg);
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer.output)
}


// DO-NOT-DELETE splicer.begin(sort.IntegerContainer._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(sort.IntegerContainer._misc)

