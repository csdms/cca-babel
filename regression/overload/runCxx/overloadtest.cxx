// overloadtest.cc

#include <string>
using namespace std;
#include "Overload.hxx"
#include "synch.hxx"

#ifdef SIDL_USE_UCXX
using namespace ucxx;
#endif
using namespace Overload;

#define MYASSERT( AAA ) \
  tracker.startPart(++part_no); \
  tracker.writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_FAIL; \
  tracker.endPart(part_no, result);

int main() { 
  int part_no      = 0;
  synch::ResultType result       = synch::ResultType_PASS;
  synch::RegOut tracker = synch::RegOut::_create();

  bool   b1        = true;
  double d1        = 1.0;
  float  f1        = 1.0F;
  int    i1        = 1;
  double did       = 2.0;
  double difd      = 3.0;
  string s1        = "aString";

  complex<double> cd1 (1.1, 1.1);
  complex<double> cdret;
  complex<float>  cf1 (1.1F, 1.1F);
  complex<float>  cfret;

  Overload::Test        t  = Overload::Test::_create();
  Overload::AnException ae = Overload::AnException::_create();
  Overload::AClass      ac = Overload::AClass::_create();
  Overload::BClass      bc = Overload::BClass::_create();

  tracker.setExpectations(19);
  MYASSERT( t.getValue() == 1 );

  MYASSERT( t.getValue(b1) == b1 );
  MYASSERT( t.getValue(d1) == d1 );
  cdret = t.getValue(cd1);
  MYASSERT( cdret.real() == cd1.real() && cdret.imag() == cd1.imag() );
  MYASSERT( t.getValue(f1) == f1 );
  cfret = t.getValue(cf1);
  MYASSERT( cfret.real() == cf1.real() && cfret.imag() == cf1.imag() );
  MYASSERT( t.getValue(i1) == i1 );
  MYASSERT( t.getValue(s1) == s1 );

  MYASSERT( t.getValue(d1, i1) == did );
  MYASSERT( t.getValue(i1, d1) == did );

  MYASSERT( t.getValue(d1, i1, f1) == difd );
  MYASSERT( t.getValue(i1, d1, f1) == difd );

  MYASSERT( t.getValue(d1, f1, i1) == difd );
  MYASSERT( t.getValue(i1, f1, d1) == difd );

  MYASSERT( t.getValue(f1, d1, i1) == difd );
  MYASSERT( t.getValue(f1, i1, d1) == difd );

  MYASSERT( t.getValue(ae) == "AnException" );
  MYASSERT( t.getValue(ac) == 2 );
  MYASSERT( t.getValue(bc) == 2 );

  tracker.close();
  return 0;
}
