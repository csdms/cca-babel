// 
// File:          sort_IntegerContainer_Impl.hxx
// Symbol:        sort.IntegerContainer-v0.1
// Symbol Type:   class
// Babel Version: 2.0.0 (Revision: 7435  trunk)
// Description:   Server-side implementation for sort.IntegerContainer
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_sort_IntegerContainer_Impl_hxx
#define included_sort_IntegerContainer_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_sort_IntegerContainer_IOR_h
#include "sort_IntegerContainer_IOR.h"
#endif
#ifndef included_sidl_BaseClass_hxx
#include "sidl_BaseClass.hxx"
#endif
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
#ifndef included_sort_IntegerContainer_hxx
#include "sort_IntegerContainer.hxx"
#endif


// DO-NOT-DELETE splicer.begin(sort.IntegerContainer._hincludes)
#include "sort_Integer.hxx"
// DO-NOT-DELETE splicer.end(sort.IntegerContainer._hincludes)

namespace sort { 

  /**
   * Symbol "sort.IntegerContainer" (version 0.1)
   * 
   * Integer container.
   */
  class IntegerContainer_impl : public virtual ::sort::IntegerContainer 
  // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(sort.IntegerContainer._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(sort.IntegerContainer._implementation)
    ::sidl::array< ::sort::Integer> d_elements;
    // DO-NOT-DELETE splicer.end(sort.IntegerContainer._implementation)

  public:
    // default constructor, used for data wrapping(required)
    IntegerContainer_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
      IntegerContainer_impl( struct sort_IntegerContainer__object * ior ) : 
        StubBase(ior,true), 
    ::sort::Container((ior==NULL) ? NULL : &((*ior).d_sort_container)) , 
      _wrapped(false) {
      ior->d_data = this;
      _ctor();
    }


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~IntegerContainer_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:


    /**
     * This sets the container length and pseudo-randomly orders the
     * Integer elements contained.
     */
    void
    setLength_impl (
      /* in */int32_t len
    )
    ;


    /**
     * Return the number of elements in the container.
     */
    int32_t
    getLength_impl() ;

    /**
     * Return -1 if element i is less than element j, 0 if element i
     * is equal to element j, or otherwise 1.
     */
    int32_t
    compare_impl (
      /* in */int32_t i,
      /* in */int32_t j,
      /* in */::sort::Comparator& comp
    )
    ;


    /**
     * Swap elements i and j.
     */
    void
    swap_impl (
      /* in */int32_t i,
      /* in */int32_t j
    )
    ;


    /**
     * Print elements s through e-1
     */
    void
    output_impl (
      /* in */int32_t s,
      /* in */int32_t e
    )
    ;

  };  // end class IntegerContainer_impl

} // end namespace sort

// DO-NOT-DELETE splicer.begin(sort.IntegerContainer._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(sort.IntegerContainer._hmisc)

#endif
