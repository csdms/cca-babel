// 
// File:          ExceptionTest_FibException_Impl.hxx
// Symbol:        ExceptionTest.FibException-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for ExceptionTest.FibException
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_ExceptionTest_FibException_Impl_hxx
#define included_ExceptionTest_FibException_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_ExceptionTest_FibException_IOR_h
#include "ExceptionTest_FibException_IOR.h"
#endif
#ifndef included_ExceptionTest_FibException_hxx
#include "ExceptionTest_FibException.hxx"
#endif
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sidl_SIDLException_hxx
#include "sidl_SIDLException.hxx"
#endif
#ifndef included_sidl_io_Deserializer_hxx
#include "sidl_io_Deserializer.hxx"
#endif
#ifndef included_sidl_io_Serializer_hxx
#include "sidl_io_Serializer.hxx"
#endif


// DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._hincludes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(ExceptionTest.FibException._hincludes)

namespace ExceptionTest { 

  /**
   * Symbol "ExceptionTest.FibException" (version 1.0)
   * 
   * This exception is a base class for the Fibonacci exceptions that are
   * thrown if the value is too large or the recursion depth is too deep.
   */
  class FibException_impl : public virtual ::ExceptionTest::FibException 
  // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._implementation)
    // Put additional implementation details here...
    // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._implementation)

  public:
    // default constructor, used for data wrapping(required)
    FibException_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
      FibException_impl( struct ExceptionTest_FibException__object * ior ) : 
        StubBase(ior,true), 
      ::sidl::io::Serializable((ior==NULL) ? NULL : &((
        *ior).d_sidl_sidlexception.d_sidl_io_serializable)),
    ::sidl::BaseException((ior==NULL) ? NULL : &((
      *ior).d_sidl_sidlexception.d_sidl_baseexception)) , _wrapped(false) 
      {_ctor();}


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~FibException_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:

  };  // end class FibException_impl

} // end namespace ExceptionTest

// DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(ExceptionTest.FibException._hmisc)

#endif
