#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include "hooks.hxx"
#include "synch.hxx"
#include "sidl_RuntimeException.hxx"

#ifdef SIDL_USE_UCXX
using namespace ucxx;
#endif /* UCXX */


#define MYASSERT( AAA ) \
  tracker.startPart(++part_no); \
  tracker.writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_PASS;  \
  tracker.endPart(part_no, result);

int main(int argc, char **argv) { 
  synch::ResultType result = synch::ResultType_PASS; 
  synch::RegOut tracker = synch::RegOut::getInstance();
  int part_no = 0;
  string language = "";
  tracker.setExpectations(2);
  if (argc == 2) {
    language = argv[1];
  }
  
  { 
    int32_t b, c, ret = 0;
    int32_t test = 1;
    try {
      hooks::Basics::_set_hooks_static(TRUE);

      hooks::Basics obj = hooks::Basics::_create();
      obj._set_hooks(TRUE);
      
      ret = hooks::Basics::aStaticMeth(test, b, c);
      ++test;
      b =  c = ret = 0;
      ret = obj.aNonStaticMeth(test, b, c);
    } catch (::sidl::RuntimeException e) {
      cout << e.getNote() << endl;
    }
 
  }

  tracker.close();
  return 0;
}

