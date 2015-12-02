// excepttest.cc

#include <string>
using namespace std;
#include "ExceptionTest.hxx"
#include "synch.hxx"
#ifdef SIDL_USE_UCXX
using namespace ucxx::ExceptionTest;
using namespace ucxx;
#else
using namespace ExceptionTest;
#endif
#include <stddef.h>
#include <stdlib.h>


#define MYPASS( AAA ) \
  tracker.writeComment(AAA); \
  tracker.endPart(part_no, synch::ResultType_PASS);

#define MYFAIL( AAA ) \
  tracker.writeComment(AAA); \
  tracker.endPart(part_no, synch::ResultType_FAIL);

static void
leakCheckOne(synch::RegOut &tracker,
	     Fib           &fib,
	     int           &part_no)
{
  int32_t buffer1[4], buffer2[4], m=2, n=2;
  ::sidl::array<int> a1 = ::sidl::array<int>::create2dCol(3,3);
  ::sidl::array<int> a2 = ::sidl::array<int>::create2dCol(4,4);
  ::sidl::array<int> a3;
  ::sidl::array<int> c1 = ::sidl::array<int>::create1d(3);
  ::sidl::array<int> c2 = ::sidl::array<int>::create1d(4);
  ::sidl::array<int> c3, retval;
  ::sidl::BaseClass o1 = ::sidl::BaseClass::_create();
  ::sidl::BaseClass o2 = ::sidl::BaseClass::_create();
  ::sidl::BaseClass o3;
  ::std::string s1 = "foo";
  ::std::string s2 = "foo";
  ::std::string s3;
  tracker.writeComment("leakCheckOne");
  try {
    tracker.startPart(++part_no);
    fib.noLeak(a1, a2, a3, buffer1, buffer2, m, n,
	       c1, c2, c3, s1, s2, s3, o1, o2, o3);
    MYFAIL("expected exception not thrown");
  }
  catch(::sidl::SIDLException &se){
    MYPASS("expected exception thrown");
  }
  catch(...) {
    MYFAIL("unexpected exception thrown");
  }
}

static void
leakCheckTwo(synch::RegOut &tracker,
	     Fib           &fib,
	     bool           row,
	     int           &part_no)
{
  ::sidl::array<int> a1 = ::sidl::array<int>::create2dCol(3,3);
  ::sidl::array<int> a2 = ::sidl::array<int>::create2dCol(4,4);
  ::sidl::array<int> a3;
  ::sidl::array<int> r1 = 
      (row ? ::sidl::array<int>::create2dRow(3,3)
       : ::sidl::array<int>::create2dCol(3,3));
  ::sidl::array<int> r2 = 
      (row ? ::sidl::array<int>::create2dRow(3,3)
       : ::sidl::array<int>::create2dCol(3,3));
  ::sidl::array<int> c1 = ::sidl::array<int>::create1d(3);
  ::sidl::array<int> c2 = ::sidl::array<int>::create1d(4);
  ::sidl::array<int> c3, retval;
  ::sidl::BaseClass o1 = ::sidl::BaseClass::_create();
  ::sidl::BaseClass o2 = ::sidl::BaseClass::_create();
  ::sidl::BaseClass o3;
  ::std::string s1 = "foo";
  ::std::string s2 = "foo";
  ::std::string s3;
  tracker.writeComment(::std::string("leakCheckTwo: row is ") +
		       ::std::string(row ? "TRUE" : "FALSE"));
  try {
    tracker.startPart(++part_no);
    fib.noLeak(a1, a2, a3, r1, r2,
	       c1, c2, c3, s1, s2, s3, o1, o2, o3);
    MYFAIL("expected exception not thrown");
  }
  catch(::sidl::SIDLException &se){
    MYPASS("expected exception thrown");
  }
  catch(...) {
    MYFAIL("unexpected exception thrown");
  }
}

int main() { 
  int part_no = 0;
  synch::RegOut tracker = synch::RegOut::_create();
  Fib fib = Fib::_create();

  tracker.setExpectations(7);
  tracker.startPart(++part_no);
  try { 
    fib.getFib(10,25,200,0);

    MYPASS( "no exception thrown (none expected)" );
  } catch (...) { 
    MYFAIL("unexpected exception thrown");
  }

  tracker.startPart(++part_no);
  try { 
    fib.getFib(-1,10,10,0);    
    MYFAIL( "no exception thrown (NegativeValueException expected)" );
  } catch ( NegativeValueException ex ) { 
    MYPASS( "NegativeValueException thrown (as expected)" );
  } catch ( ... ) { 
    MYFAIL( "unexpected exception thrown" );
  }
 
  tracker.startPart(++part_no);
  try { 
    fib.getFib(10,1,1000,0);
    MYFAIL( "no exception thrown (TooDeepException expected)" );    
  } catch ( TooDeepException ex ) { 
    MYFAIL( "TooDeepException thrown (and unexpectedly caught!)");
  } catch ( FibException ex ) { // catch declared types
    TooDeepException ex2 = sidl::babel_cast<TooDeepException>(ex);  // downcast
    if ( !ex2 ) { 
      MYFAIL( "FibException caught, but cannot cast to TooDeepException" );
    } else { 
      MYPASS( "FibException caught, and correctly cast to TooDeepException" );
    }
  } catch( ... ) { 
    MYFAIL( "unexpected exception thrown" );
  }

  tracker.startPart(++part_no);
  try { 
    fib.getFib(10,1000,1,0);
    MYFAIL( "no exception thrown (TooBigException expected)" );    
  } catch ( TooBigException ex ) { 
    MYFAIL( "TooBigException thrown (and unexpectedly caught!)");
  } catch ( FibException ex ) { // catch declared types
    TooBigException ex2 = sidl::babel_cast<TooBigException>(ex);  // downcast
    if ( !ex2 ) { 
      MYFAIL( "FibException caught, but cannot cast to TooBigException" );
    } else { 
      MYPASS( "FibException caught, and correctly cast to TooBigException" );
    }  
  } catch( ... ) { 
    MYFAIL( "unexpected exception thrown" );
  }
  leakCheckOne(tracker, fib, part_no);
  leakCheckTwo(tracker, fib, true, part_no);
  leakCheckTwo(tracker, fib, false, part_no);
  tracker.close();
  return 0;
}
