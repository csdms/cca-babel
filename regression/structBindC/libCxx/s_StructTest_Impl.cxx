// 
// File:          s_StructTest_Impl.cxx
// Symbol:        s.StructTest-v1.0
// Symbol Type:   class
// Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
// Description:   Server-side implementation for s.StructTest
// 
// WARNING: Automatically generated; only changes within splicers preserved
// 
// 
#include "s_StructTest_Impl.hxx"

// 
// Includes for all method dependencies.
// 
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
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif
#ifndef included_sidl_NotImplementedException_hxx
#include "sidl_NotImplementedException.hxx"
#endif
// DO-NOT-DELETE splicer.begin(s.StructTest._includes)
#include <ctype.h>
static void
initSimple(::s::Simple &s)
{
  s.d_bool = true;
  s.d_char = '3';
  s.d_dcomplex.real = s.d_dcomplex.imaginary = 3.14;
  s.d_fcomplex.real = s.d_fcomplex.imaginary = 3.1F;
  s.d_double = 3.14;
  s.d_float = 3.1F;
  s.d_int = 3;
  s.d_long = 3;
  s.d_opaque = 0;
  s.set_d_enum(::s::Color_blue);
}

static bool
checkSimple(const ::s::Simple &s)
{

const double eps = 1.E-6;

 return((s.d_bool &&
           (s.d_char == '3') &&
           (fabs(s.d_dcomplex.real - 3.14) < eps) &&
           (fabs(s.d_dcomplex.imaginary - 3.14) < eps) &&
           (fabs(s.d_double - 3.14) < eps) &&
           (fabs(s.d_fcomplex.real - 3.1F) < eps) &&
           (fabs(s.d_fcomplex.imaginary - 3.1F) < eps) &&
           (fabs(s.d_float - 3.1F) < eps) &&
           (s.d_int == 3) &&
           (s.d_long == 3) &&
           (s.d_opaque == NULL) &&
           (s.get_d_enum() == ::s::Color_blue)));
}

void
invertSimple(::s::Simple &s) {
    s.d_bool = (s.d_bool ? FALSE : TRUE);
    s.d_char = (islower((int)s.d_char) ? toupper(s.d_char) :
                 tolower(s.d_char));
    s.d_dcomplex.imaginary = -s.d_dcomplex.imaginary;
    s.d_double = - s.d_double;
    s.d_fcomplex.imaginary = -s.d_fcomplex.imaginary;
    s.d_float = - s.d_float;
    s.d_int = - s.d_int;
    s.d_long = - s.d_long;
    s.set_d_enum(::s::Color_red);
}

static void 
initHard(::s::Hard &h) {
  ::sidl::array<double> da = ::sidl::array<double> ::create1d(3);
  da.set(0,1.0);
  da.set(1,2.0);
  da.set(2,3.0);
  h.set_d_array(da);
}

static bool
checkHard(const ::s::Hard &h) {
  bool result = h.get_d_array()._not_nil();
  if (result) {
    ::sidl::array<double> da = h.get_d_array();
    result = result && (da.dimen() == 1);
    result = result && (da.length(0) == 3);
    result = result && (da[0] == 1.0);
    result = result && (da[1] == 2.0);
    result = result && (da[2] == 3.0);
  }
  return result;
}

static void
invertHard(::s::Hard &h) {
  ::sidl::array<double> da = h.get_d_array();
  if (da._not_nil() && (da.dimen() == 1) && (da.length(0) == 3)) {
    double tmp = da[2];
    da.set(2, da[0]);
    da.set(0, tmp);
  }
}

static void
initCombined(::s::Combined &c)
{
  initSimple(c.get_d_simple());
  initHard(c.get_d_hard());
}

static bool
checkCombined(const ::s::Combined &c)
{
  return checkSimple(c.get_d_simple()) && checkHard(c.get_d_hard());
}

static void
invertCombined(::s::Combined &c)
{
  invertSimple(c.get_d_simple());
  invertHard(c.get_d_hard());
}

static bool
checkHardRarray(const ::s::HardRarray &r) {
  bool result = (r.d_rarrayRaw != NULL) ;
  if (result) {
    result = result && (r.d_rarrayRaw[0] == 1.0);
    result = result && (r.d_rarrayRaw[1] == 2.0);
    result = result && (r.d_rarrayRaw[2] == 3.0);
    result = result && (r.d_rarrayFix[0] == 5.0);
    result = result && (r.d_rarrayFix[1] == 10.0);
    result = result && (r.d_rarrayFix[2] == 15.0);
  }
  return result;
}

static void
invertHardRarray(struct ::s::HardRarray &r) {
      double temp;
      temp = r.d_rarrayRaw[0];
      r.d_rarrayRaw[0] = r.d_rarrayRaw[2] ;
      r.d_rarrayRaw[2] = temp ;

      temp = r.d_rarrayFix[0];
      r.d_rarrayFix[0] = r.d_rarrayFix[2] ;
      r.d_rarrayFix[2] = temp ;
}

static bool
checkCombRarray(const struct ::s::CombRarray &h) {

  return checkSimple(h.get_d_simple()) && checkHardRarray(h.get_d_hardRarray());

}

static void
invertCombRarray(::s::CombRarray &h)
{
  invertSimple(h.get_d_simple());
  invertHardRarray(h.get_d_hardRarray());
}
// DO-NOT-DELETE splicer.end(s.StructTest._includes)

// special constructor, used for data wrapping(required).  Do not put code here unless you really know what you're doing!
s::StructTest_impl::StructTest_impl() : StubBase(reinterpret_cast< void*>(
  ::s::StructTest::_wrapObj(reinterpret_cast< void*>(this))),false) , _wrapped(
  true){ 
  // DO-NOT-DELETE splicer.begin(s.StructTest._ctor2)
  // DO-NOT-DELETE splicer.end(s.StructTest._ctor2)
}

// user defined constructor
void s::StructTest_impl::_ctor() {
  // DO-NOT-DELETE splicer.begin(s.StructTest._ctor)
  // DO-NOT-DELETE splicer.end(s.StructTest._ctor)
}

// user defined destructor
void s::StructTest_impl::_dtor() {
  // DO-NOT-DELETE splicer.begin(s.StructTest._dtor)
  // DO-NOT-DELETE splicer.end(s.StructTest._dtor)
}

// static class initializer
void s::StructTest_impl::_load() {
  // DO-NOT-DELETE splicer.begin(s.StructTest._load)
  // DO-NOT-DELETE splicer.end(s.StructTest._load)
}

// user defined static methods: (none)

// user defined non-static methods:
/**
 * Method:  returnEmpty[]
 */
::s::Empty
s::StructTest_impl::returnEmpty_impl () 

{
  // DO-NOT-DELETE splicer.begin(s.StructTest.returnEmpty)
  return ::s::Empty();
  // DO-NOT-DELETE splicer.end(s.StructTest.returnEmpty)
}

/**
 * Method:  passinEmpty[]
 */
bool
s::StructTest_impl::passinEmpty_impl (
  /* in */const ::s::Empty& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinEmpty)
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinEmpty)
}

/**
 * Method:  passoutEmpty[]
 */
bool
s::StructTest_impl::passoutEmpty_impl (
  /* out */::s::Empty& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passoutEmpty)
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passoutEmpty)
}

/**
 * Method:  passinoutEmpty[]
 */
bool
s::StructTest_impl::passinoutEmpty_impl (
  /* inout */::s::Empty& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutEmpty)
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutEmpty)
}

/**
 * Method:  passeverywhereEmpty[]
 */
::s::Empty
s::StructTest_impl::passeverywhereEmpty_impl (
  /* in */const ::s::Empty& s1,
  /* out */::s::Empty& s2,
  /* inout */::s::Empty& s3 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereEmpty)
  return ::s::Empty();
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereEmpty)
}

/**
 * Method:  returnSimple[]
 */
::s::Simple
s::StructTest_impl::returnSimple_impl () 

{
  // DO-NOT-DELETE splicer.begin(s.StructTest.returnSimple)
  ::s::Simple result;
  initSimple(result);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.returnSimple)
}

/**
 * Method:  passinSimple[]
 */
bool
s::StructTest_impl::passinSimple_impl (
  /* in */const ::s::Simple& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinSimple)
  return checkSimple(s);
  // DO-NOT-DELETE splicer.end(s.StructTest.passinSimple)
}

/**
 * Method:  passoutSimple[]
 */
bool
s::StructTest_impl::passoutSimple_impl (
  /* out */::s::Simple& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passoutSimple)
  initSimple(s);
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passoutSimple)
}

/**
 * Method:  passinoutSimple[]
 */
bool
s::StructTest_impl::passinoutSimple_impl (
  /* inout */::s::Simple& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutSimple)
  bool result = checkSimple(s);
  invertSimple(s);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutSimple)
}

/**
 * Method:  passeverywhereSimple[]
 */
::s::Simple
s::StructTest_impl::passeverywhereSimple_impl (
  /* in */const ::s::Simple& s1,
  /* out */::s::Simple& s2,
  /* inout */::s::Simple& s3 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereSimple)
  ::s::Simple result;
  initSimple(s2);
  initSimple(result);
  if (checkSimple(s1) && checkSimple(s3)) {
    invertSimple(s3);
  }
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereSimple)
}

/**
 * Method:  returnHard[]
 */
::s::Hard
s::StructTest_impl::returnHard_impl () 

{
  // DO-NOT-DELETE splicer.begin(s.StructTest.returnHard)
  ::s::Hard h;
  initHard(h);
  return h;
  // DO-NOT-DELETE splicer.end(s.StructTest.returnHard)
}

/**
 * Method:  passinHard[]
 */
bool
s::StructTest_impl::passinHard_impl (
  /* in */const ::s::Hard& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinHard)
  return checkHard(s);
  // DO-NOT-DELETE splicer.end(s.StructTest.passinHard)
}

/**
 * Method:  passoutHard[]
 */
bool
s::StructTest_impl::passoutHard_impl (
  /* out */::s::Hard& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passoutHard)
  initHard(s);
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passoutHard)
}

/**
 * Method:  passinoutHard[]
 */
bool
s::StructTest_impl::passinoutHard_impl (
  /* inout */::s::Hard& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHard)
  bool result = checkHard(s);
  invertHard(s);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutHard)
}

/**
 * Method:  passeverywhereHard[]
 */
::s::Hard
s::StructTest_impl::passeverywhereHard_impl (
  /* in */const ::s::Hard& s1,
  /* out */::s::Hard& s2,
  /* inout */::s::Hard& s3 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHard)
  ::s::Hard result;
  initHard(result);
  initHard(s2);
  if (checkHard(s1) && checkHard(s3)) {
    invertHard(s3);
  }
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHard)
}

/**
 * Method:  returnCombined[]
 */
::s::Combined
s::StructTest_impl::returnCombined_impl () 

{
  // DO-NOT-DELETE splicer.begin(s.StructTest.returnCombined)
  ::s::Combined result;
  initCombined(result);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.returnCombined)
}

/**
 * Method:  passinCombined[]
 */
bool
s::StructTest_impl::passinCombined_impl (
  /* in */const ::s::Combined& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinCombined)
  return checkCombined(s);
  // DO-NOT-DELETE splicer.end(s.StructTest.passinCombined)
}

/**
 * Method:  passoutCombined[]
 */
bool
s::StructTest_impl::passoutCombined_impl (
  /* out */::s::Combined& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passoutCombined)
  initCombined(s);
  return true;
  // DO-NOT-DELETE splicer.end(s.StructTest.passoutCombined)
}

/**
 * Method:  passinoutCombined[]
 */
bool
s::StructTest_impl::passinoutCombined_impl (
  /* inout */::s::Combined& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombined)
  bool result = checkCombined(s);
  invertCombined(s);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombined)
}

/**
 * Method:  passeverywhereCombined[]
 */
::s::Combined
s::StructTest_impl::passeverywhereCombined_impl (
  /* in */const ::s::Combined& s1,
  /* out */::s::Combined& s2,
  /* inout */::s::Combined& s3 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombined)
  ::s::Combined result;
  initCombined(result);
  initCombined(s2);
  if (checkCombined(s1) && checkCombined(s3)) {
    invertCombined(s3);
  }
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombined)
}

/**
 * Method:  passinHardRarray[]
 */
bool
s::StructTest_impl::passinHardRarray_impl (
  /* in */const ::s::HardRarray& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinHardRarray)
  return checkHardRarray(s);
  // DO-NOT-DELETE splicer.end(s.StructTest.passinHardRarray)
}

/**
 * Method:  passinoutHardRarray[]
 */
bool
s::StructTest_impl::passinoutHardRarray_impl (
  /* inout */::s::HardRarray& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHardRarray)
  bool result = checkHardRarray(s);
  invertHardRarray(s);
  return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutHardRarray)
}

/**
 * Method:  passeverywhereHardRarray[]
 */
bool
s::StructTest_impl::passeverywhereHardRarray_impl (
  /* in */const ::s::HardRarray& s1,
  /* inout */::s::HardRarray& s2 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHardRarray)
   if (checkHardRarray(s1) && checkHardRarray(s2)) {
     invertHardRarray(s2);
     return true;
   }
   return false;
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHardRarray)
}

/**
 * Method:  passinCombRarray[]
 */
bool
s::StructTest_impl::passinCombRarray_impl (
  /* in */const ::s::CombRarray& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinCombRarray)
    return checkCombRarray(s);
  // DO-NOT-DELETE splicer.end(s.StructTest.passinCombRarray)
}

/**
 * Method:  passinoutCombRarray[]
 */
bool
s::StructTest_impl::passinoutCombRarray_impl (
  /* inout */::s::CombRarray& s ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombRarray)
    bool result = checkCombRarray(s);
    invertCombRarray(s);
    return result;
  // DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombRarray)
}

/**
 * Method:  passeverywhereCombRarray[]
 */
bool
s::StructTest_impl::passeverywhereCombRarray_impl (
  /* in */const ::s::CombRarray& s1,
  /* inout */::s::CombRarray& s2 ) 
{
  // DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombRarray)
    if (checkCombRarray(s1) && checkCombRarray(s2)) {
      invertCombRarray(s2);
      return true;
    }
    return false;
  // DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombRarray)
}


// DO-NOT-DELETE splicer.begin(s.StructTest._misc)
// DO-NOT-DELETE splicer.end(s.StructTest._misc)

