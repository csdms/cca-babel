// 
// File:          ExceptionTest_FibException_Impl.cxx
// Symbol:        ExceptionTest.FibException-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for ExceptionTest.FibException
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "ExceptionTest_FibException_Impl.hxx"

// 
// Includes for all method dependencies.
// 
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
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
// DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._includes)
// Put additional includes or other arbitrary code here...
// DO-NOT-DELETE splicer.end(ExceptionTest.FibException._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
ExceptionTest::FibException_impl::FibException_impl() : StubBase(
  reinterpret_cast< void*>(::ExceptionTest::FibException::_wrapObj(
  reinterpret_cast< void*>(this))),false) , _wrapped(true){ 
  // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor2)
  // Insert-Code-Here {ExceptionTest.FibException._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor2)
}

// user defined constructor
void ExceptionTest::FibException_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor)
  // add construction details here
  // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor)
}

// user defined destructor
void ExceptionTest::FibException_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._dtor)
}

// static class initializer
void ExceptionTest::FibException_impl::_load() {
  // DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(ExceptionTest.FibException._load)
}

// user defined static methods: (none)

// user defined non-static methods: (none)

// DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(ExceptionTest.FibException._misc)

