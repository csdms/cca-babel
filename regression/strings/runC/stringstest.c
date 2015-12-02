
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"
#include "synch.h"
#include "sidl_Exception.h"

#define MYASSERT( AAA ) {\
  int _result; \
  synch_RegOut_startPart(tracker, ++part_no, &exception); SIDL_REPORT(exception);\
  synch_RegOut_writeComment(tracker, #AAA, &exception); SIDL_REPORT(exception);\
  _result = (int) (AAA); SIDL_REPORT(exception);\
  if ( _result ) result = synch_ResultType_PASS; \
  else result = synch_ResultType_FAIL;  \
  synch_RegOut_endPart(tracker, part_no, result, &exception); \
  SIDL_REPORT(exception);\
}

int main(int argc, char **argv) { 
  sidl_BaseInterface exception = 0;
  enum synch_ResultType__enum result = synch_ResultType_PASS; 
  int part_no = 0;
  Strings_Cstring obj;
  synch_RegOut tracker = synch_RegOut__create(&exception);
  SIDL_REPORT(exception);
  synch_RegOut_setExpectations(tracker, -1, &exception);
  SIDL_REPORT(exception);
  
  { 
    char* out;
    char* temp;
    char* inout = (char*)(malloc(sizeof(char)*6));
    strcpy(inout,"Three");
    MYASSERT(obj = Strings_Cstring__create(&exception));
 
    MYASSERT((temp =  Strings_Cstring_returnback( obj, TRUE, &exception )) &&
             !strcmp(temp, "Three"));
    free(temp);
    MYASSERT( (!(temp = Strings_Cstring_returnback(obj, FALSE, &exception))) || 
               !strcmp(temp, ""));
    if (temp) free(temp);
    MYASSERT( Strings_Cstring_passin( obj, "Three", &exception ) == TRUE );
    MYASSERT( Strings_Cstring_passin( obj, NULL, &exception ) == FALSE );
    MYASSERT( Strings_Cstring_passout( obj, TRUE, &out, &exception ) == TRUE && !(strcmp(out, "Three")));
    free(out);
    out = NULL;
    MYASSERT( Strings_Cstring_passout( obj, FALSE, &out, &exception ) == FALSE && 
              !(out && strcmp(out, "")));
    if (out) free(out);
    MYASSERT( Strings_Cstring_passinout( obj, &inout, &exception ) == TRUE && !(strcmp(inout,"threes")));
    MYASSERT( (temp=Strings_Cstring_passeverywhere( obj, "Three", &out,
                                                   &inout, &exception )) &&
              !(strcmp(temp, "Three"))  &&
	      !(strcmp(out, "Three")) && !(strcmp(inout, "Three")) );
    MYASSERT( Strings_Cstring_mixedarguments( obj, "Test", 'z', "Test", 'z', &exception)
              );
    MYASSERT( !Strings_Cstring_mixedarguments( obj, "Not", 'A', "Equal", 'a', &exception)
             );

    free(out);
    free(temp);
    free(inout);
    inout = NULL;
    MYASSERT( (Strings_Cstring_passinout( obj, &inout, &exception) == FALSE));
    if (inout) free(inout);
    
    Strings_Cstring_deleteRef( obj, &exception ); SIDL_REPORT(exception);
  }

  synch_RegOut_close(tracker, &exception); SIDL_REPORT(exception);
  synch_RegOut_deleteRef(tracker, &exception); SIDL_REPORT(exception);
  return 0;
 EXIT:
  {
    sidl_BaseInterface throwaway_exception = NULL;
    if (tracker) {
      sidl_BaseInterface exception2 = NULL;
      synch_RegOut_forceFailure(tracker, &exception2);
      if (exception2) {
        puts("TEST_RESULT FAIL\n");
        sidl_BaseInterface_deleteRef(exception2, &throwaway_exception);
      }
      synch_RegOut_deleteRef(tracker, &throwaway_exception);
    }
    sidl_BaseInterface_deleteRef(exception, &throwaway_exception);
    return -1;
  }
}
