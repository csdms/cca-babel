// 
// File:          s_StructTest_Impl.hxx
// Symbol:        s.StructTest-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
// Description:   Server-side implementation for s.StructTest
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_s_StructTest_Impl_hxx
#define included_s_StructTest_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_s_StructTest_IOR_h
#include "s_StructTest_IOR.h"
#endif
#ifndef included_s_CombRarray_hxx
#include "s_CombRarray.hxx"
#endif
#ifndef included_s_Combined_hxx
#include "s_Combined.hxx"
#endif
#ifndef included_s_Empty_hxx
#include "s_Empty.hxx"
#endif
#ifndef included_s_Hard_hxx
#include "s_Hard.hxx"
#endif
#ifndef included_s_HardRarray_hxx
#include "s_HardRarray.hxx"
#endif
#ifndef included_s_Simple_hxx
#include "s_Simple.hxx"
#endif
#ifndef included_s_StructTest_hxx
#include "s_StructTest.hxx"
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


// DO-NOT-DELETE splicer.begin(s.StructTest._hincludes)
// insert code here (includes or arbitrary code)
// DO-NOT-DELETE splicer.end(s.StructTest._hincludes)

namespace s { 

  /**
   * Symbol "s.StructTest" (version 1.0)
   */
  class StructTest_impl : public virtual ::s::StructTest 
  // DO-NOT-DELETE splicer.begin(s.StructTest._inherits)
  // insert code here (optional inheritance here)
  // DO-NOT-DELETE splicer.end(s.StructTest._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(s.StructTest._implementation)
    // insert code here (additional details)
    // DO-NOT-DELETE splicer.end(s.StructTest._implementation)

  public:
    // default constructor, used for data wrapping(required)
    StructTest_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
    StructTest_impl( struct s_StructTest__object * ior ) : StubBase(ior,true) , 
      _wrapped(false) {_ctor();}


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~StructTest_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:

    /**
     * user defined non-static method.
     */
    ::s::Empty
    returnEmpty_impl() ;
    /**
     * user defined non-static method.
     */
    bool
    passinEmpty_impl (
      /* in */const ::s::Empty& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passoutEmpty_impl (
      /* out */::s::Empty& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutEmpty_impl (
      /* inout */::s::Empty& s
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Empty
    passeverywhereEmpty_impl (
      /* in */const ::s::Empty& s1,
      /* out */::s::Empty& s2,
      /* inout */::s::Empty& s3
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Simple
    returnSimple_impl() ;
    /**
     * user defined non-static method.
     */
    bool
    passinSimple_impl (
      /* in */const ::s::Simple& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passoutSimple_impl (
      /* out */::s::Simple& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutSimple_impl (
      /* inout */::s::Simple& s
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Simple
    passeverywhereSimple_impl (
      /* in */const ::s::Simple& s1,
      /* out */::s::Simple& s2,
      /* inout */::s::Simple& s3
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Hard
    returnHard_impl() ;
    /**
     * user defined non-static method.
     */
    bool
    passinHard_impl (
      /* in */const ::s::Hard& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passoutHard_impl (
      /* out */::s::Hard& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutHard_impl (
      /* inout */::s::Hard& s
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Hard
    passeverywhereHard_impl (
      /* in */const ::s::Hard& s1,
      /* out */::s::Hard& s2,
      /* inout */::s::Hard& s3
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Combined
    returnCombined_impl() ;
    /**
     * user defined non-static method.
     */
    bool
    passinCombined_impl (
      /* in */const ::s::Combined& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passoutCombined_impl (
      /* out */::s::Combined& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutCombined_impl (
      /* inout */::s::Combined& s
    )
    ;

    /**
     * user defined non-static method.
     */
    ::s::Combined
    passeverywhereCombined_impl (
      /* in */const ::s::Combined& s1,
      /* out */::s::Combined& s2,
      /* inout */::s::Combined& s3
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinHardRarray_impl (
      /* in */const ::s::HardRarray& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutHardRarray_impl (
      /* inout */::s::HardRarray& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passeverywhereHardRarray_impl (
      /* in */const ::s::HardRarray& s1,
      /* inout */::s::HardRarray& s2
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinCombRarray_impl (
      /* in */const ::s::CombRarray& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passinoutCombRarray_impl (
      /* inout */::s::CombRarray& s
    )
    ;

    /**
     * user defined non-static method.
     */
    bool
    passeverywhereCombRarray_impl (
      /* in */const ::s::CombRarray& s1,
      /* inout */::s::CombRarray& s2
    )
    ;

  };  // end class StructTest_impl

} // end namespace s

// DO-NOT-DELETE splicer.begin(s.StructTest._hmisc)
// insert code here (miscellaneous things)
// DO-NOT-DELETE splicer.end(s.StructTest._hmisc)

#endif
