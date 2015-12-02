/*
 * File:        sorttest.c
 * Copyright:   (c) 2002 Lawrence Livermore National Security, LLC
 * Revision:    @(#) $Revision: 6171 $
 * Date:        $Date: 2007-10-08 16:39:28 -0700 (Mon, 08 Oct 2007) $
 * Description: Simple C driver for the sort regression test
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort_SortTest.h"
#include "sort_MergeSort.h"
#include "sort_QuickSort.h"
#include "sort_HeapSort.h"
#include "sort_SortingAlgorithm.h"
#include "synch.h"
#include "sidl_Exception.h"

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
  declare_part(tracker,  &part_no ); \
  magicNumber = clearstack(magicNumber); \
  synch_RegOut_writeComment(tracker, #AAA, &exception); SIDL_REPORT(exception);\
  { \
    int _result = AAA; SIDL_REPORT(exception); \
    if ( _result ) result = synch_ResultType_PASS; \
    else result = synch_ResultType_FAIL;  \
  } \
  end_part( tracker, part_no, result);

void declare_part(synch_RegOut tracker,  int * part_no ) {
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

int
main(int argc, char **argv)
{
  enum synch_ResultType__enum result = synch_ResultType_PASS;
  sidl_BaseInterface exception = NULL;
  int magicNumber = 1;
  int part_no = 0;
  synch_RegOut tracker;
  sort_MergeSort merge;
  sort_QuickSort quick;
  sort_HeapSort  heap;
  sort_SortingAlgorithm sa = NULL;
  struct sort_SortingAlgorithm__array* 
    algs = sort_SortingAlgorithm__array_create1d(3);
  tracker = synch_RegOut_getInstance(&exception); SIDL_REPORT(exception);
  merge = sort_MergeSort__create(&exception); SIDL_REPORT(exception);
  quick = sort_QuickSort__create(&exception); SIDL_REPORT(exception);
  heap = sort_HeapSort__create(&exception); SIDL_REPORT(exception);
  srandom(time(NULL));
  synch_RegOut_setExpectations(tracker, 4, &exception); SIDL_REPORT(exception);
  MYASSERT(merge != NULL);
  MYASSERT(quick != NULL);
  MYASSERT(heap != NULL);
  sa = sort_SortingAlgorithm__cast(merge, &exception); SIDL_REPORT(exception);
  sort_SortingAlgorithm__array_set1(algs, 0, sa);
  sort_SortingAlgorithm_deleteRef(sa, &exception); SIDL_REPORT(exception);
  sa = sort_SortingAlgorithm__cast(quick, &exception); 
  sort_SortingAlgorithm__array_set1(algs, 1, sa);
  sort_SortingAlgorithm_deleteRef(sa, &exception);SIDL_REPORT(exception);
  sa = sort_SortingAlgorithm__cast(heap, &exception); SIDL_REPORT(exception);
  sort_SortingAlgorithm__array_set1(algs, 2, sa);
  sort_SortingAlgorithm_deleteRef(sa, &exception);SIDL_REPORT(exception);
  /* remove extraneous references */
  sort_MergeSort_deleteRef(merge, &exception); merge = NULL; SIDL_REPORT(exception);
  sort_QuickSort_deleteRef(quick, &exception); quick = NULL; SIDL_REPORT(exception);
  sort_HeapSort_deleteRef(heap, &exception); heap = NULL; SIDL_REPORT(exception);
  /* call test */
  MYASSERT(sort_SortTest_stressTest(algs, &exception) == TRUE);
  sort_SortingAlgorithm__array_deleteRef(algs);
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
