// 
// File:          ExceptionTest_TooDeepException_Impl.hxx
// Symbol:        ExceptionTest.TooDeepException-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for ExceptionTest.TooDeepException
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_ExceptionTest_TooDeepException_Impl_hxx
#define included_ExceptionTest_TooDeepException_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_ExceptionTest_TooDeepException_IOR_h
#include "ExceptionTest_TooDeepException_IOR.h"
#endif
#ifndef included_ExceptionTest_FibException_hxx
#include "ExceptionTest_FibException.hxx"
#endif
#ifndef included_ExceptionTest_TooDeepException_hxx
#include "ExceptionTest_TooDeepException.hxx"
#endif
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sidl_io_Deserializer_hxx
#include "sidl_io_Deserializer.hxx"
#endif
#ifndef included_sidl_io_Serializer_hxx
#include "sidl_io_Serializer.hxx"
#endif


// DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._hincludes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._hincludes)

namespace ExceptionTest { 

  /**
   * Symbol "ExceptionTest.TooDeepException" (version 1.0)
   * 
   * This exception is thrown if the Fibonacci recursion is too deep.
   */
  class TooDeepException_impl : public virtual 
    ::ExceptionTest::TooDeepException 
  // DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._implementation)
    // Put additional implementation details here...
    // DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._implementation)

  public:
    // default constructor, used for data wrapping(required)
    TooDeepException_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
      TooDeepException_impl( struct ExceptionTest_TooDeepException__object * 
        ior ) : StubBase(ior,true), 
      ::sidl::io::Serializable((ior==NULL) ? NULL : &((
        *ior).d_exceptiontest_fibexception.d_sidl_sidlexception.d_sidl_io_serializable))
        ,
    ::sidl::BaseException((ior==NULL) ? NULL : &((
      *ior).d_exceptiontest_fibexception.d_sidl_sidlexception.d_sidl_baseexception))
      , _wrapped(false) {_ctor();}


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~TooDeepException_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:

  };  // end class TooDeepException_impl

} // end namespace ExceptionTest

// DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._hmisc)

#endif
