// 
// File:          ExceptionTest_NegativeValueException_Impl.hxx
// Symbol:        ExceptionTest.NegativeValueException-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for ExceptionTest.NegativeValueException
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 

#ifndef included_ExceptionTest_NegativeValueException_Impl_hxx
#define included_ExceptionTest_NegativeValueException_Impl_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_ExceptionTest_NegativeValueException_IOR_h
#include "ExceptionTest_NegativeValueException_IOR.h"
#endif
#ifndef included_ExceptionTest_NegativeValueException_hxx
#include "ExceptionTest_NegativeValueException.hxx"
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


// DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._hincludes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._hincludes)

namespace ExceptionTest { 

  /**
   * Symbol "ExceptionTest.NegativeValueException" (version 1.0)
   * 
   * This exception is thrown if the value for which the Fibonacci number
   * is requested is negative.
   */
  class NegativeValueException_impl : public virtual 
    ::ExceptionTest::NegativeValueException 
  // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._inherits)
  // Put additional inheritance here...
  // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._inherits)

  {

  // All data marked protected will be accessable by 
  // descendant Impl classes
  protected:

    bool _wrapped;

    // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._implementation)
    // Put additional implementation details here...
    // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._implementation)

  public:
    // default constructor, used for data wrapping(required)
    NegativeValueException_impl();
    // sidl constructor (required)
    // Note: alternate Skel constructor doesn't call addref()
    // (fixes bug #275)
      NegativeValueException_impl( struct 
        ExceptionTest_NegativeValueException__object * ior ) : StubBase(ior,
        true), 
      ::sidl::io::Serializable((ior==NULL) ? NULL : &((
        *ior).d_sidl_sidlexception.d_sidl_io_serializable)),
    ::sidl::BaseException((ior==NULL) ? NULL : &((
      *ior).d_sidl_sidlexception.d_sidl_baseexception)) , _wrapped(false) 
      {_ctor();}


    // user defined construction
    void _ctor();

    // virtual destructor (required)
    virtual ~NegativeValueException_impl() { _dtor(); }

    // user defined destruction
    void _dtor();

    // true if this object was created by a user newing the impl
    inline bool _isWrapped() {return _wrapped;}

    // static class initializer
    static void _load();

  public:

  };  // end class NegativeValueException_impl

} // end namespace ExceptionTest

// DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._hmisc)
// Put miscellaneous things here...
// DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._hmisc)

#endif
