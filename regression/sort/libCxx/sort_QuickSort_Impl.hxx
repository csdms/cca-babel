// 
// File:          sort_QuickSort_Impl.hxx
// Symbol:        sort.QuickSort-v0.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for sort.QuickSort
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_sort_QuickSort_Impl_hxx
#define included_sort_QuickSort_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_sort_QuickSort_IOR_h
#include "sort_QuickSort_IOR.h"
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
#ifndef included_sort_Counter_hxx
#include "sort_Counter.hxx"
#endif
#ifndef included_sort_QuickSort_hxx
#include "sort_QuickSort.hxx"
#endif
#ifndef included_sort_SortingAlgorithm_hxx
#include "sort_SortingAlgorithm.hxx"
#endif


// DO-NOT-DELETE splicer.begin(sort.QuickSort._hincludes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(sort.QuickSort._hincludes)

namespace sort { 

  /**
   * Symbol "sort.QuickSort" (version 0.1)
   * 
   * Quick sort
   */
  class QuickSort_impl : public virtual ::sort::QuickSort 
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(sort.QuickSort._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(sort.QuickSort._implementation)
    // Put additional implementation details here...
    // DO-NOT-DELETE splicer.end(sort.QuickSort._implementation)

  public:
    // default constructor, used for data wrapping(required)
    QuickSort_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
    QuickSort_impl( struct sort_QuickSort__object * ior ) : StubBase(ior,true) ,
      _wrapped(false) {_ctor();}


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~QuickSort_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:


    /**
     * Sort elements using Quick Sort.
     */
    void
    sort_impl (
      /* in */::sort::Container& elems,
      /* in */::sort::Comparator& comp
    )
    ;


    /**
     * Return quick sort.
     */
    ::std::string
    getName_impl() ;
  };  // end class QuickSort_impl

} // end namespace sort

// DO-NOT-DELETE splicer.begin(sort.QuickSort._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(sort.QuickSort._hmisc)

#endif
