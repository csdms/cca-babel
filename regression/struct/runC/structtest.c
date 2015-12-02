/*
 * File:        structtest.c
 * Copyright:   (c) 2007 Lawrence Livermore National Security, LLC
 * Release:     $Name$
 * Revision:    @(#) $Revision: 6190 $
 * Date:        $Date$
 * Description: Struct test driver
 *
 */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "synch.h"
#include "sidl_BaseClass.h"
#include "sidl_BaseInterface.h"
#include "s_StructTest.h"
#include "s_Color.h"
#include "sidl_Exception.h"

void declare_part( synch_RegOut tracker, int *part_no );
void end_part( synch_RegOut tracker, int part_no, 
               enum synch_ResultType__enum result);

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

#define MYASSERT( AAA ) \
  declare_part( tracker, &part_no ); \
  magicNumber = clearstack(magicNumber); \
  synch_RegOut_writeComment(tracker, #AAA, &exception); SIDL_REPORT(exception); \
  { \
     int _result = AAA; SIDL_REPORT(exception); \
     if ( _result ) result = synch_ResultType_PASS; \
     else result = synch_ResultType_FAIL;  \
  } \
  end_part( tracker, part_no, result);

static sidl_bool
checkSimple(const struct s_Simple__data *s)
{
  return ((s->d_bool &&
           (s->d_char == '3') &&
           (s->d_dcomplex.real == 3.14) &&
           (s->d_dcomplex.imaginary == 3.14) &&
           (s->d_double == 3.14) &&
           (s->d_fcomplex.real == 3.1F) &&
           (s->d_fcomplex.imaginary == 3.1F) &&
           (s->d_float == 3.1F) &&
           (s->d_int == 3) &&
           (s->d_long == 3) &&
           (s->d_opaque == NULL) &&
           (s->d_enum == s_Color_blue)) ? TRUE : FALSE);
}

static sidl_bool
checkSimpleInv(const struct s_Simple__data *s)
{
  return ((!s->d_bool &&
           (s->d_char == '3') &&
           (s->d_dcomplex.real == 3.14) &&
           (s->d_dcomplex.imaginary == -3.14) &&
           (s->d_double == -3.14) &&
           (s->d_fcomplex.real == 3.1F) &&
           (s->d_fcomplex.imaginary == -3.1F) &&
           (s->d_float == -3.1F) &&
           (s->d_int == -3) &&
           (s->d_long == -3) &&
           (s->d_opaque == NULL) &&
           (s->d_enum == s_Color_red)) ? TRUE : FALSE);
}

static sidl_bool
checkHard(const struct s_Hard__data *h) {
  sidl_BaseInterface be;
  sidl_bool result = (h->d_string && !strcmp("Three", h->d_string)) 
    ? TRUE : FALSE;
  result = result && (h->d_object != NULL);
  result = result && (h->d_interface != NULL);
  if (result) {
    sidl_bool test;
    sidl_BaseInterface ex;
    test = sidl_BaseClass_isSame(h->d_object, h->d_interface, &ex);
    if (ex) {
      sidl_BaseInterface throwaway;
      result = FALSE;
      sidl_BaseInterface_deleteRef(ex, &throwaway);
    }
    else {
      result = result && test;
    }
  }
  result = result && (h->d_array != NULL) && (h->d_objectArray != NULL);
  if (result) {
    result = result && (sidlArrayDim(h->d_array) == 1) && 
      (sidlLength(h->d_array, 0) == 3);
    result = result && (sidlArrayDim(h->d_objectArray) == 1) && 
      (sidlLength(h->d_objectArray, 0) == 3);
    if (result) {
      int32_t i;
      result = result && (sidlArrayElem1(h->d_array, 0) == 1.0);
      result = result && (sidlArrayElem1(h->d_array, 1) == 2.0);
      result = result && (sidlArrayElem1(h->d_array, 2) == 3.0);
      for(i = 0; i < 3; ++i) {
        sidl_BaseClass bc = sidl_BaseClass__array_get1(h->d_objectArray, i);
        result = result && (bc != NULL);
        if (result) {
          result = result && sidl_BaseClass_isType(bc, "sidl.BaseClass", &be);
          if (be) {
            sidl_BaseInterface throwaway;
            result = FALSE;
            sidl_BaseInterface_deleteRef(be, &throwaway);
          }
        }
        if (bc) {
          sidl_BaseClass_deleteRef(bc, &be);
          if (be) {
            sidl_BaseInterface throwaway;
            result = FALSE;
            sidl_BaseInterface_deleteRef(be, &throwaway);
          }
        }
      }
    }
  }
  return result;
}

static sidl_bool
checkHardInv(const struct s_Hard__data *h) {
  sidl_BaseInterface be;
  sidl_bool result = (h->d_string && !strcmp("three", h->d_string)) 
    ? TRUE : FALSE;
  result = result && (h->d_object != NULL);
  result = result && (h->d_interface != NULL);
  if (result) {
    sidl_bool test;
    sidl_BaseInterface ex;
    test = sidl_BaseClass_isSame(h->d_object, h->d_interface, &ex);
    if (ex) {
      sidl_BaseInterface throwaway;
      result = FALSE;
      sidl_BaseInterface_deleteRef(ex, &throwaway);
    }
    else {
      result = result && !test;
    }
  }
  result = result && (h->d_array != NULL) && (h->d_objectArray != NULL);
  if (result) {
    result = result && (sidlArrayDim(h->d_array) == 1) && 
      (sidlLength(h->d_array, 0) == 3);
    result = result && (sidlArrayDim(h->d_objectArray) == 1) && 
      (sidlLength(h->d_objectArray, 0) == 3);
    if (result) {
      int32_t i;
      result = result && (sidlArrayElem1(h->d_array, 0) == 3.0);
      result = result && (sidlArrayElem1(h->d_array, 1) == 2.0);
      result = result && (sidlArrayElem1(h->d_array, 2) == 1.0);
      for(i = 0; i < 3; ++i) {
        sidl_BaseClass bc = sidl_BaseClass__array_get1(h->d_objectArray, i);
        if (i == 1) {
          result = result && (bc == NULL);
          if (bc) {
            sidl_BaseClass_deleteRef(bc, &be);
            if (be) {
              sidl_BaseInterface throwaway;
              result = FALSE;
              sidl_BaseInterface_deleteRef(be, &throwaway);
            }
          }
        }
        else {
          result = result && (bc != NULL);
          if (result) {
            result = result && 
              sidl_BaseClass_isType(bc, "sidl.BaseClass", &be);
            if (be) {
              sidl_BaseInterface throwaway;
              result = FALSE;
              sidl_BaseInterface_deleteRef(be, &throwaway);
            }
          }
          sidl_BaseClass_deleteRef(bc, &be);
          if (be) {
            sidl_BaseInterface throwaway;
            result = FALSE;
            sidl_BaseInterface_deleteRef(be, &throwaway);
          }
        }
      }
    }
  }
  return result;
}

static sidl_bool
checkCombined(const struct s_Combined__data *c)
{
  return checkSimple(&(c->d_simple)) && checkHard(&(c->d_hard));
}

static sidl_bool
checkCombinedInv(const struct s_Combined__data *c)
{
  return checkSimpleInv(&(c->d_simple)) && checkHardInv(&(c->d_hard));
}

void
fillRandom(char *buf, size_t size)
{
  while (size-- > 0) {
    *buf = (char)random();
    ++buf;
  }
}

int 
main(int argc, char **argv)
{
  char buffer[256];
  s_StructTest test = NULL;
  int part_no = 0;
  int magicNumber = 1;
  struct s_Empty__data e1, e2, e3, e4;
  struct s_Simple__data s1, s2, s3, s4;
  struct s_Hard__data h1, h2, h3, h4;
  struct s_Combined__data c1, c2, c3, c4;
  sidl_BaseInterface exception = NULL;
  enum synch_ResultType__enum result = synch_ResultType_PASS;
  synch_RegOut tracker = synch_RegOut__create(&exception);
  SIDL_REPORT(exception);
  synch_RegOut_setExpectations(tracker, 26, &exception); SIDL_REPORT(exception);
  fillRandom((char *)&s1, sizeof(struct s_Simple__data));
  fillRandom((char *)&s2, sizeof(struct s_Simple__data));
  fillRandom((char *)&s3, sizeof(struct s_Simple__data));
  fillRandom((char *)&s4, sizeof(struct s_Simple__data));
  fillRandom((char *)&h1, sizeof(struct s_Hard__data));
  fillRandom((char *)&h2, sizeof(struct s_Hard__data));
  fillRandom((char *)&h3, sizeof(struct s_Hard__data));
  fillRandom((char *)&h4, sizeof(struct s_Hard__data));
  fillRandom((char *)&c1, sizeof(struct s_Combined__data));
  fillRandom((char *)&c2, sizeof(struct s_Combined__data));
  fillRandom((char *)&c3, sizeof(struct s_Combined__data));
  fillRandom((char *)&c4, sizeof(struct s_Combined__data));
  test = s_StructTest__create(&exception); SIDL_REPORT(exception);
  MYASSERT(test != NULL);
  
  sprintf(buffer, "sizeof(struct s_Empty__data) == %d",
          sizeof(struct s_Empty__data));
  synch_RegOut_writeComment(tracker, buffer, &exception); SIDL_REPORT(exception);
  e1 = s_StructTest_returnEmpty(test, &exception); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passinEmpty(test, &e1, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutEmpty(test, &e2, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passinoutEmpty(test, &e2, &exception)); SIDL_REPORT(exception);
  s_Empty__destroy(&e2, &exception); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutEmpty(test, &e3, &exception)); SIDL_REPORT(exception);
  e4 = s_StructTest_passeverywhereEmpty(test, &e1, &e2, &e3, &exception);
  SIDL_REPORT(exception);
  s_Empty__destroy(&e1, &exception); SIDL_REPORT(exception);
  s_Empty__destroy(&e2, &exception); SIDL_REPORT(exception);
  s_Empty__destroy(&e3, &exception); SIDL_REPORT(exception);
  s_Empty__destroy(&e4, &exception); SIDL_REPORT(exception);

  sprintf(buffer, "sizeof(struct s_Simple__data) == %d",
          sizeof(struct s_Simple__data));
  synch_RegOut_writeComment(tracker, buffer, &exception); SIDL_REPORT(exception);
  s1 = s_StructTest_returnSimple(test, &exception); SIDL_REPORT(exception);
  MYASSERT(checkSimple(&s1));
  MYASSERT(s_StructTest_passinSimple(test, &s1, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutSimple(test, &s2, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passinoutSimple(test, &s2, &exception)); SIDL_REPORT(exception);
  MYASSERT(checkSimpleInv(&s2));
  s_Simple__destroy(&s2, &exception); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutSimple(test, &s3, &exception)); SIDL_REPORT(exception);
  s4 = s_StructTest_passeverywhereSimple(test, &s1, &s2, &s3, &exception);
  SIDL_REPORT(exception);
  MYASSERT(checkSimple(&s4) && checkSimple(&s2) && checkSimpleInv(&s3));
  s_Simple__destroy(&s1, &exception); SIDL_REPORT(exception);
  s_Simple__destroy(&s2, &exception); SIDL_REPORT(exception);
  s_Simple__destroy(&s3, &exception); SIDL_REPORT(exception);
  s_Simple__destroy(&s4, &exception); SIDL_REPORT(exception);

  sprintf(buffer, "sizeof(struct s_Hard__data) == %d",
          sizeof(struct s_Hard__data));
  synch_RegOut_writeComment(tracker, buffer, &exception); SIDL_REPORT(exception);
  h1 = s_StructTest_returnHard(test, &exception); SIDL_REPORT(exception);
  MYASSERT(checkHard(&h1));
  MYASSERT(s_StructTest_passinHard(test, &h1, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutHard(test, &h2, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passinoutHard(test, &h2, &exception)); SIDL_REPORT(exception);
  MYASSERT(checkHardInv(&h2));
  s_Hard__destroy(&h2, &exception); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutHard(test, &h3, &exception)); SIDL_REPORT(exception);
  h4 = s_StructTest_passeverywhereHard(test, &h1, &h2, &h3, &exception);
  SIDL_REPORT(exception);
  MYASSERT(checkHard(&h4) && checkHard(&h2) && checkHardInv(&h3));
  s_Hard__destroy(&h1, &exception); SIDL_REPORT(exception);
  s_Hard__destroy(&h2, &exception); SIDL_REPORT(exception);
  s_Hard__destroy(&h3, &exception); SIDL_REPORT(exception);
  s_Hard__destroy(&h4, &exception); SIDL_REPORT(exception);

  sprintf(buffer, "sizeof(struct s_Combined__data) == %d",
          sizeof(struct s_Combined__data));
  synch_RegOut_writeComment(tracker, buffer, &exception); SIDL_REPORT(exception);
  c1 = s_StructTest_returnCombined(test, &exception); SIDL_REPORT(exception);
  MYASSERT(checkCombined(&c1));
  MYASSERT(s_StructTest_passinCombined(test, &c1, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutCombined(test, &c2, &exception)); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passinoutCombined(test, &c2, &exception)); SIDL_REPORT(exception);
  MYASSERT(checkCombinedInv(&c2));
  s_Combined__destroy(&c2, &exception); SIDL_REPORT(exception);
  MYASSERT(s_StructTest_passoutCombined(test, &c3, &exception)); SIDL_REPORT(exception);
  c4 = s_StructTest_passeverywhereCombined(test, &c1, &c2, &c3, &exception);
  SIDL_REPORT(exception);
  MYASSERT(checkCombined(&c4) && checkCombined(&c2) && checkCombinedInv(&c3));
  s_Combined__destroy(&c1, &exception); SIDL_REPORT(exception);
  s_Combined__destroy(&c2, &exception); SIDL_REPORT(exception);
  s_Combined__destroy(&c3, &exception); SIDL_REPORT(exception);
  s_Combined__destroy(&c4, &exception); SIDL_REPORT(exception);

  s_StructTest_deleteRef(test, &exception); SIDL_REPORT(exception);

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
void declare_part( synch_RegOut tracker, int * part_no ) {
  sidl_BaseInterface exception = NULL;
  synch_RegOut_startPart(tracker, ++(*part_no), &exception);
  if (exception) {
    sidl_BaseInterface throwaway_exception;
    sidl_BaseInterface exception2 = NULL;
    synch_RegOut_forceFailure(tracker, &exception2);
    if (exception2) {
      puts("TEST_RESULT FAIL\n");
      sidl_BaseInterface_deleteRef(exception2, &throwaway_exception);
    }
    sidl_BaseInterface_deleteRef(exception, &throwaway_exception);
  }
}

void end_part( synch_RegOut tracker, int part_no, 
               enum synch_ResultType__enum result) {
  sidl_BaseInterface exception = NULL;
  synch_RegOut_endPart(tracker, part_no, result, &exception);
  if (exception) {
    sidl_BaseInterface throwaway_exception;
    sidl_BaseInterface exception2 = NULL;
    synch_RegOut_forceFailure(tracker, &exception2);
    if (exception2) {
      puts("TEST_RESULT FAIL\n");
      sidl_BaseInterface_deleteRef(exception2, &throwaway_exception);
    }
    sidl_BaseInterface_deleteRef(exception, &throwaway_exception);
  }
}

