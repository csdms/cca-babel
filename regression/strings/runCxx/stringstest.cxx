
#include <string>
using namespace std;
#include "Strings.hxx"
#include "synch.hxx"


#define MYASSERT( AAA ) \
  tracker.startPart(++part_no);\
  tracker.writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_FAIL;  \
  tracker.endPart(part_no, result);


int main() { 
  synch::ResultType result = synch::ResultType_PASS;
  int part_no = 0;
  Strings::Cstring obj = Strings::Cstring::_create();
  synch::RegOut tracker = synch::RegOut::_create();
  tracker.setExpectations(-1);
  
  { 
    string in = "Three";
    string out;
    string inout = "Three";
 
    MYASSERT( obj.returnback(true) == "Three" );
    MYASSERT( obj.returnback(false) == "" );
    MYASSERT( obj.passin( in ) == true );
    MYASSERT( obj.passout(true, out ) == true && out == "Three" );
    MYASSERT( obj.passout(false, out ) == false && out == "" );
    MYASSERT( obj.passinout( inout ) == true && inout == "threes" );
    MYASSERT( obj.passeverywhere( in, out, inout ) == "Three" &&
	      out == "Three" && inout == "Three" );
    MYASSERT( obj.mixedarguments( "Test", 'z', "Test", 'z') );
    MYASSERT( !obj.mixedarguments( "Not", 'A', "Equal", 'a') );
    
  }

  tracker.close();
  return 0;
}
