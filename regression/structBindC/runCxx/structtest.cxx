/*
 * File:        structtest.cxx
 * Copyright:   (c) 2007 Lawrence Livermore National Security, LLC
 * Release:     $Name$
 * Revision:    @(#) $Revision: 6190 $
 * Date:        $Date$
 * Description: Struct test driver
 *
 */
#include "s_StructTest.hxx"
#include <sstream>
using namespace std;
#include "synch.hxx"

#define MYASSERT( AAA ) \
  tracker.startPart(++part_no);\
  tracker.writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_FAIL;  \
  tracker.endPart(part_no, result);



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
checkSimpleInv(const ::s::Simple &s)
{
  const double eps = 1.E-6; 

  return ((!s.d_bool &&
           (s.d_char == '3') &&
           (fabs(s.d_dcomplex.real - 3.14) < eps) &&
           (fabs(s.d_dcomplex.imaginary + 3.14) < eps) &&
           (fabs(s.d_double + 3.14) < eps) &&
           (fabs(s.d_fcomplex.real - 3.1F) < eps) &&
           (fabs(s.d_fcomplex.imaginary + 3.1F) < eps) &&
           (fabs(s.d_float + 3.1F) < eps) &&
           (s.d_int == -3) &&
           (s.d_long == -3) &&
           (s.d_opaque == NULL) &&
           (s.get_d_enum() == ::s::Color_red)));

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

static bool
checkHardInv(const ::s::Hard &h) {
  bool result = h.get_d_array()._not_nil();
  if (result) {
    ::sidl::array<double> da = h.get_d_array();
    result = result && (da.dimen() == 1);
    result = result && (da.length(0) == 3);
    result = result && (da[0] == 3.0);
    result = result && (da[1] == 2.0);
    result = result && (da[2] == 1.0);
  }
  return result;
}

static bool
checkCombined(const ::s::Combined &c)
{
  return checkSimple(c.get_d_simple()) && checkHard(c.get_d_hard());
}

static bool
checkCombinedInv(const ::s::Combined &c)
{
  return checkSimpleInv(c.get_d_simple()) && checkHardInv(c.get_d_hard());
}

void
initHardRarray(::s::HardRarray &r) {
  const int N=3;
  int i;

  r.d_rarrayRaw = new double[N];

  r.d_int=N;
  for (i=0; i<N;i++){
    r.d_rarrayRaw[i]=(double)(i+1);
    r.d_rarrayFix[i]=(double)((i+1)*5);
  }
}

static bool
checkHardRarray(const ::s::HardRarray &r) {
  bool result = (r.d_rarrayRaw != NULL);
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

static bool
checkHardRarrayInv(const ::s::HardRarray &r) {
  bool result = (r.d_rarrayRaw != NULL);
  if (result) {
    result = result && (r.d_rarrayRaw[0] == 3.0);
    result = result && (r.d_rarrayRaw[1] == 2.0);
    result = result && (r.d_rarrayRaw[2] == 1.0);
    result = result && (r.d_rarrayFix[0] == 15.0);
    result = result && (r.d_rarrayFix[1] == 10.0);
    result = result && (r.d_rarrayFix[2] == 5.0);
  }
  return result;
}

void
deleteHardRarray(struct ::s::HardRarray &r) {

  delete [] r.d_rarrayRaw;

}

void
initCombRarray(struct ::s::CombRarray &r) {
  initSimple(r.get_d_simple());
  initHardRarray(r.get_d_hardRarray());
}

static sidl_bool
checkCombRarray(const struct ::s::CombRarray &r) {
  return checkSimple(r.get_d_simple()) &&
     checkHardRarray(r.get_d_hardRarray());
}

static sidl_bool
checkCombRarrayInv(const struct ::s::CombRarray &r) {
  return checkSimpleInv(r.get_d_simple()) &&
     checkHardRarrayInv(r.get_d_hardRarray());
}

void
deleteCombRarray(struct ::s::CombRarray &r) {
  deleteHardRarray(r.get_d_hardRarray());
}

int
main(int argc, char **argv)
{
  synch::ResultType result = synch::ResultType_PASS;
  int part_no = 0;
  synch::RegOut tracker = synch::RegOut::_create();
  tracker.setExpectations(40);
  ::s::StructTest test = ::s::StructTest::_create();
  MYASSERT(test._not_nil());
  
  {
    ::s::Empty e1, e2, e3, e4;
    ostringstream buf;
    buf << "sizeof(::s::Empty) == " << sizeof(::s::Empty);
    tracker.writeComment(buf.str());
    e1 = test.returnEmpty();
    MYASSERT(test.passinEmpty(e1));
    MYASSERT(test.passoutEmpty(e1));
    MYASSERT(test.passoutEmpty(e2));
    MYASSERT(test.passinoutEmpty(e2));
    MYASSERT(test.passoutEmpty(e3));
    e4 = test.passeverywhereEmpty(e1, e2, e3);
  }

  {
    ::s::Simple s1, s2, s3, s4;
    ostringstream buf;
    buf << "sizeof(::s::Simple) == " << sizeof(::s::Simple);
    tracker.writeComment(buf.str());
    s1 = test.returnSimple();
    MYASSERT(checkSimple(s1));
    MYASSERT(test.passinSimple(s1));
    MYASSERT(test.passoutSimple(s1));
    MYASSERT(test.passoutSimple(s2));
    MYASSERT(test.passinoutSimple(s2));
    MYASSERT(checkSimpleInv(s2));
    MYASSERT(test.passoutSimple(s3));
    s4 = test.passeverywhereSimple(s1, s2, s3);
    MYASSERT(checkSimple(s4) && checkSimple(s2) && checkSimpleInv(s3));
  }

  {
    ::s::Hard h1, h2, h3, h4;
    ostringstream buf;
    buf << "sizeof(::s::Hard) == " << sizeof(::s::Hard);
    tracker.writeComment(buf.str());
    h1 = test.returnHard();
    MYASSERT(checkHard(h1));
    MYASSERT(test.passinHard(h1));
    MYASSERT(test.passoutHard(h1));
    MYASSERT(test.passoutHard(h2));
    MYASSERT(test.passinoutHard(h2));
    MYASSERT(checkHardInv(h2));
    MYASSERT(test.passoutHard(h3));
    h4 = test.passeverywhereHard(h1, h2, h3);
    MYASSERT(checkHard(h4) && checkHard(h2) && checkHardInv(h3));
  }

  {
    ::s::Combined c1, c2, c3, c4;
    ostringstream buf;
    buf << "sizeof(::s::Combined) == " << sizeof(::s::Combined)
	<< " sizeof(struct s_Combined__data) == " 
	<< sizeof(struct s_Combined__data);
    tracker.writeComment(buf.str());
    c1 = test.returnCombined();
    MYASSERT(checkCombined(c1));
    MYASSERT(test.passinCombined(c1));
    MYASSERT(test.passoutCombined(c1));
    MYASSERT(test.passoutCombined(c2));
    MYASSERT(test.passinoutCombined(c2));
    MYASSERT(checkCombinedInv(c2));
    MYASSERT(test.passoutCombined(c3));
    c4 = test.passeverywhereCombined(c1, c2, c3);
    MYASSERT(checkCombined(c4) && checkCombined(c2) && checkCombinedInv(c3));
  }

  {
    ::s::HardRarray r1, r2;
    ostringstream buf;
    buf << "sizeof(::s::HardRarray) == " << sizeof(::s::HardRarray)
	<< " sizeof(struct s_HardRarray__data) == " 
	<< sizeof(struct s_HardRarray__data);
    tracker.writeComment(buf.str());
    initHardRarray(r1); 
    MYASSERT(test.passinHardRarray(r1)); 
    MYASSERT(test.passinoutHardRarray(r1));
    MYASSERT(checkHardRarrayInv(r1));
    deleteHardRarray(r1);
    initHardRarray(r1); 
    initHardRarray(r2); 
    MYASSERT(test.passeverywhereHardRarray(r1, r2));
    MYASSERT(checkHardRarray(r1) && checkHardRarrayInv(r2));
    deleteHardRarray(r1);
    deleteHardRarray(r2);
  }

  {
    ::s::CombRarray hr1, hr2;
    ostringstream buf;
    buf << "sizeof(::s::CombRarray) == " << sizeof(::s::HardRarray)
	<< " sizeof(struct s_CombRarray__data) == " 
	<< sizeof(struct s_CombRarray__data);
    tracker.writeComment(buf.str());
    initCombRarray(hr1); 
    MYASSERT(test.passinCombRarray(hr1)); 
    MYASSERT(test.passinoutCombRarray(hr1));
    MYASSERT(checkCombRarrayInv(hr1));
    deleteCombRarray(hr1);
    initCombRarray(hr1); 
    initCombRarray(hr2); 
    MYASSERT(test.passeverywhereCombRarray(hr1, hr2));
    MYASSERT(checkCombRarray(hr1) && checkCombRarrayInv(hr2));
    deleteCombRarray(hr1);
    deleteCombRarray(hr2);
  }

  tracker.close();
  return 0;
}
