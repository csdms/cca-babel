/*
 * File:        hookstest.c
 * Copyright:   (c) 2004 Lawrence Livermore National Security, LLC
 * Revision:    @(#) $Revision: 4533 $
 * Date:        $Date: 2005-04-13 16:38:20 -0700 (Wed, 13 Apr 2005) $
 * Description: Assertion Test C client
 *
 */
#include <stdio.h>
#include "hooks_Basics.h"
#include "sidl_Exception.h"
#include <stdlib.h>
#include <string.h>
#include "synch.h"
#include "sidl_Exception.h"

/* #define RMI 0 */

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif


/**
 * Fill the stack with random junk.
 */
int clearstack(int magicNumber) {
  int chunk[2048], i;
  for(i = 0; i < 2048; i++){
    chunk[i] = rand() + magicNumber;
  }
  for(i = 0; i < 16; i++){
    magicNumber += chunk[rand() & 2047];
  }
  return magicNumber;
}


/*************************** main ***************************/
int main(int argc, char**argv)
{ 
  hooks_Basics h;
  sidl_BaseInterface exception = NULL;
  int32_t test = 1;
  int32_t b, c, ret = 0;
  synch_RegOut tracker = synch_RegOut_getInstance(&exception);
  
  synch_RegOut_setExpectations(tracker, 2, &exception); SIDL_REPORT(exception);

  hooks_Basics__set_hooks_static(TRUE, &exception);SIDL_REPORT(exception);

  h = hooks_Basics__create(&exception);SIDL_REPORT(exception);
  hooks_Basics__set_hooks(h, TRUE, &exception);SIDL_REPORT(exception);

  b = c = 0;
  ret = hooks_Basics_aStaticMeth(test, &b, &c, &exception);SIDL_REPORT(exception);
  b = c = 0;
  ++test;
  ret = hooks_Basics_aNonStaticMeth(h, test, &b, &c, &exception);SIDL_REPORT(exception);


  hooks_Basics_deleteRef(h, &exception);SIDL_REPORT(exception);
  synch_RegOut_close(tracker, &exception);SIDL_REPORT(exception);
  synch_RegOut_deleteRef(tracker,&exception);SIDL_REPORT(exception);
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
  return -1;
}
