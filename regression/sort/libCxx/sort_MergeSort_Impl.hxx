// 
// File:          sort_MergeSort_Impl.hxx
// Symbol:        sort.MergeSort-v0.1
// Symbol Type:   class
// Babel Version: 2.0.0 (Revision: 7435  trunk)
// Description:   Server-side implementation for sort.MergeSort
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_sort_MergeSort_Impl_hxx
#define included_sort_MergeSort_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_sort_MergeSort_IOR_h
#include "sort_MergeSort_IOR.h"
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
#ifndef included_sort_MergeSort_hxx
#include "sort_MergeSort.hxx"
#endif
#ifndef included_sort_SortingAlgorithm_hxx
#include "sort_SortingAlgorithm.hxx"
#endif


// DO-NOT-DELETE splicer.begin(sort.MergeSort._hincludes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(sort.MergeSort._hincludes)

namespace sort { 

  /**
   * Symbol "sort.MergeSort" (version 0.1)
   * 
   * Merge sort
   */
  class MergeSort_impl : public virtual ::sort::MergeSort 
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(sort.MergeSort._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(sort.MergeSort._implementation)
    // Put additional implementation details here...
    // DO-NOT-DELETE splicer.end(sort.MergeSort._implementation)

  public:
    // default constructor, used for data wrapping(required)
    MergeSort_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
    MergeSort_impl( struct sort_MergeSort__object * ior ) : StubBase(ior,true) ,
      _wrapped(false) {
      ior->d_data = this;
      _ctor();
    }


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~MergeSort_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:


    /**
     * Sort elements using Merge Sort.
     */
    void
    sort_impl (
      /* in */::sort::Container& elems,
      /* in */::sort::Comparator& comp
    )
    ;


    /**
     * Return merge sort.
     */
    ::std::string
    getName_impl() ;
  };  // end class MergeSort_impl

} // end namespace sort

// DO-NOT-DELETE splicer.begin(sort.MergeSort._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(sort.MergeSort._hmisc)

#endif
