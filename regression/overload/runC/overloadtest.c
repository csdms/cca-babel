/*
 * File:        overloadtest.c
 * Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
 * Revision:    @(#) $Revision: 6479 $
 * Date:        $Date: 2008-08-21 07:38:07 -0700 (Thu, 21 Aug 2008) $
 * Description: Overload Test C client
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Overload.h"
#include "synch.h"
#include "sidl_Exception.h"

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

static void declare_part( synch_RegOut tracker, int * part_no, 
			  sidl_BaseInterface *_ex )
{
  synch_RegOut_startPart(tracker, ++(*part_no), _ex); SIDL_REPORT(*_ex);
 EXIT:
  ;
}

static void end_part(synch_RegOut tracker, int part_no, 
                     enum synch_ResultType__enum result, 
		     sidl_BaseInterface* _ex)
{
  synch_RegOut_endPart(tracker, part_no, result, _ex); SIDL_REPORT(*_ex);
 EXIT:
  ;
}

#define CHECK(FUNC,COMMENT)                 \
  declare_part(tracker, &part_no, &exception); SIDL_REPORT(exception);          \
  synch_RegOut_writeComment(tracker, COMMENT, &exception); SIDL_REPORT(exception);\
  result = (FUNC) ? synch_ResultType_PASS : synch_ResultType_FAIL; SIDL_REPORT(exception); \
  end_part(tracker, part_no, result, &exception); SIDL_REPORT(exception);


int main(int argc, char**argv)
{ 
  sidl_BaseInterface exception = NULL;
  enum synch_ResultType__enum result       = synch_ResultType_PASS; 
  int part_no      = 0;
  double d1        = 1.0;
  float  f1        = 1.0F;
  int    i1        = 1;
  double did       = 2.0;
  double difd      = 3.0;
  const char*  ev  = "AnException";
  char *msg;
  char*        s1  = "test string";
  char*        sret;

  struct sidl_dcomplex dc = { 1.1, 1.1 };
  struct sidl_dcomplex dcret;
  struct sidl_fcomplex fc = { 1.1F, 1.1F };
  struct sidl_fcomplex fcret;

  synch_RegOut tracker = synch_RegOut__create(&exception); SIDL_REPORT(exception);
  {
    Overload_Test        t  = Overload_Test__create(&exception); SIDL_REPORT(exception);
    {
      Overload_AnException ae = Overload_AnException__create (&exception); SIDL_REPORT(exception);
      {
	Overload_AClass      ac = Overload_AClass__create(&exception); SIDL_REPORT(exception);
	{
	  Overload_BClass      bc = Overload_BClass__create(&exception); SIDL_REPORT(exception);

	  synch_RegOut_setExpectations(tracker, 19,&exception); SIDL_REPORT(exception);
	  CHECK(Overload_Test_getValue(t,&exception) == 1, 
		"checking empty argument to known value");

	  CHECK(Overload_Test_getValueBool(t, TRUE,&exception) == TRUE, "checking bool");
	  CHECK(Overload_Test_getValueDouble(t, d1,&exception) == d1, "checking double");
	  dcret = Overload_Test_getValueDcomplex(t, dc,&exception); SIDL_REPORT(exception);
	  CHECK(dcret.real == dc.real && dcret.imaginary == dc.imaginary, 
		"checking dcomplex");
	  CHECK(Overload_Test_getValueFloat(t, f1,&exception) == f1, "checking float");
	  fcret = Overload_Test_getValueFcomplex(t, fc,&exception); SIDL_REPORT(exception);
	  CHECK(fcret.real == fc.real && fcret.imaginary == fc.imaginary, 
		"checking fcomplex");
	  CHECK(Overload_Test_getValueInt(t, i1,&exception) == i1, "checking int");
	  sret = Overload_Test_getValueString(t, s1,&exception);
	  CHECK(sret && !strcmp(sret, s1), "checking string");
	  if (sret) free ((void*)sret);
	  
	  CHECK(Overload_Test_getValueDoubleInt(t, d1, i1,&exception) == did, 
		"checking double int");
	  CHECK(Overload_Test_getValueIntDouble(t, i1, d1,&exception) == did, 
		"checking int double");
	  
	  CHECK(Overload_Test_getValueDoubleIntFloat(t, d1, i1, f1,&exception) == difd, 
		"checking double int float");
	  CHECK(Overload_Test_getValueIntDoubleFloat(t, i1, d1, f1,&exception) == difd, 
		"checking int double float");
	  
	  CHECK(Overload_Test_getValueDoubleFloatInt(t, d1, f1, i1,&exception) == difd, 
		"checking double float int");
	  CHECK(Overload_Test_getValueIntFloatDouble(t, i1, f1, d1,&exception) == difd, 
		"checking int float double");
	  
	  CHECK(Overload_Test_getValueFloatDoubleInt(t, f1, d1, i1,&exception) == difd, 
		"checking float double int");
	  CHECK(Overload_Test_getValueFloatIntDouble(t, f1, i1, d1,&exception) == difd, 
		"checking float int double");
	  
	  msg = Overload_Test_getValueException(t, ae,&exception);SIDL_REPORT(exception);
	  CHECK(msg && !strcmp(msg, ev), 
		"checking exception to known value");
	  if (msg) free((void*)msg);
	  
	  CHECK(Overload_Test_getValueAClass(t, ac,&exception) == 2, 
		"checking AClass value to known value");
	  
	  CHECK(Overload_Test_getValueBClass(t, bc,&exception) == 2, 
		"checking BClass value to known value");
	  
	  
	  Overload_BClass_deleteRef (bc,&exception);   SIDL_REPORT(exception);
	  Overload_AClass_deleteRef (ac,&exception);SIDL_REPORT(exception);
	  Overload_AnException_deleteRef (ae,&exception);SIDL_REPORT(exception);
	  Overload_Test_deleteRef (t,&exception);SIDL_REPORT(exception);
	  synch_RegOut_close(tracker,&exception);SIDL_REPORT(exception);
	  synch_RegOut_deleteRef(tracker,&exception);SIDL_REPORT(exception);
	  return 0;
	}
      }
    }
  }
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
      synch_RegOut_deleteRef(tracker,&throwaway_exception);
    }
    sidl_BaseInterface_deleteRef(exception, &throwaway_exception);
    return -1;
  }
}
