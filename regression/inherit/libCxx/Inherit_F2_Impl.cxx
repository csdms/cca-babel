// 
// File:          Inherit_F2_Impl.cxx
// Symbol:        Inherit.F2-v1.1
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
// Description:   Server-side implementation for Inherit.F2
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "Inherit_F2_Impl.hxx"

// 
// Includes for all method dependencies.
// 
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sidl_RuntimeException_hxx
#include "sidl_RuntimeException.hxx"
#endif
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
#ifndef included_sidl_LangSpecificException_hxx
#include "sidl_LangSpecificException.hxx"
#endif
#ifndef included_sidl_String_h
#include "sidl_String.h"
#endif
// DO-NOT-DELETE splicer.begin(Inherit.F2._includes)
#include <string>
using namespace std;
// DO-NOT-DELETE splicer.end(Inherit.F2._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
Inherit::F2_impl::F2_impl() : StubBase(reinterpret_cast< void*>(
  ::Inherit::F2::_wrapObj(reinterpret_cast< void*>(this))),false) , _wrapped(
  true){ 
  // DO-NOT-DELETE splicer.begin(Inherit.F2._ctor2)
  // Insert-Code-Here {Inherit.F2._ctor2} (ctor2)
  // DO-NOT-DELETE splicer.end(Inherit.F2._ctor2)
}

// user defined constructor
void Inherit::F2_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(Inherit.F2._ctor)
  // add construction details here
  // DO-NOT-DELETE splicer.end(Inherit.F2._ctor)
}

// user defined destructor
void Inherit::F2_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(Inherit.F2._dtor)
  // add destruction details here
  // DO-NOT-DELETE splicer.end(Inherit.F2._dtor)
}

// static class initializer
void Inherit::F2_impl::_load() {
  // DO-NOT-DELETE splicer.begin(Inherit.F2._load)
  // guaranteed to be called at most once before any other method in this class
  // DO-NOT-DELETE splicer.end(Inherit.F2._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Method:  c[]
 */
::std::string
Inherit::F2_impl::c_impl () 

{
  // DO-NOT-DELETE splicer.begin(Inherit.F2.c)
  return "F2.c";
  // DO-NOT-DELETE splicer.end(Inherit.F2.c)
}

/**
 * Method:  a[]
 */
::std::string
Inherit::F2_impl::a_impl () 

{
  // DO-NOT-DELETE splicer.begin(Inherit.F2.a)
  return "F2.a";
  // DO-NOT-DELETE splicer.end(Inherit.F2.a)
}

/**
 * Method:  b[]
 */
::std::string
Inherit::F2_impl::b_impl () 

{
  // DO-NOT-DELETE splicer.begin(Inherit.F2.b)
  return "F2.b";
  // DO-NOT-DELETE splicer.end(Inherit.F2.b)
}

/**
 * Method:  f[]
 */
::std::string
Inherit::F2_impl::f_impl () 

{
  // DO-NOT-DELETE splicer.begin(Inherit.F2.f)
  return "F2.f";
  // DO-NOT-DELETE splicer.end(Inherit.F2.f)
}


// DO-NOT-DELETE splicer.begin(Inherit.F2._misc)
// Put miscellaneous code here
// DO-NOT-DELETE splicer.end(Inherit.F2._misc)


//////////////////////////////////////////////////
// 
// Special methods for throwing exceptions
// 

void
Inherit::F2_impl::Super::throwException0(
  const char* methodName,
  struct sidl_BaseInterface__object *_exception
)
  // throws:
{
  void * _p = 0;
  struct sidl_BaseInterface__object *throwaway_exception;

  if ( (_p=(*(_exception->d_epv->f__cast))(_exception->d_object, 
    "sidl.RuntimeException", &throwaway_exception)) != 0 ) {
    struct sidl_RuntimeException__object * _realtype = reinterpret_cast< struct 
      sidl_RuntimeException__object*>(_p);
    (*_exception->d_epv->f_deleteRef)(_exception->d_object, 
      &throwaway_exception);
    // Note: alternate constructor does not increment refcount.
    ::sidl::RuntimeException _resolved_exception = ::sidl::RuntimeException( 
      _realtype, false );
    (_resolved_exception._get_ior()->d_epv->f_add) (
      _resolved_exception._get_ior()->d_object , __FILE__, __LINE__, methodName,
      &throwaway_exception);throw _resolved_exception;
  }
  // Any unresolved exception is treated as LangSpecificException
  ::sidl::LangSpecificException _unexpected = 
    ::sidl::LangSpecificException::_create();
  _unexpected.add(__FILE__,__LINE__, "Unknown method");
  _unexpected.setNote("Unexpected exception received by C++ stub.");
  throw _unexpected;
}
/**
 * super method
 */
::std::string
Inherit::F2_impl::Super::c(  )

{
  ::std::string _result;
  char * _local_result;
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _local_result = (*(superEPV->f_c))(reinterpret_cast< struct 
    Inherit_C__object*>(superSelf), &_exception );
  /*dispatch to ior*/
  if (_exception != NULL ) {

    throwException0("Super::c", _exception);
  }
  if (_local_result) {
    _result = _local_result;
    ::sidl_String_free( _local_result );
  }
  /*unpack results and cleanup*/
  return _result;
}


