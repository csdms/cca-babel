/*
 * File:        sorttest.cc
 * Copyright:   (c) 2002 Lawrence Livermore National Security, LLC
 * Revision:    @(#) $Revision$
 * Date:        $Date$
 * Description: Simple C++ driver for the sort regression test
 *
 */

#include <stdlib.h>
#include <time.h>
#ifdef _AIX
/* work around for #define realloc rpl_realloc on AIX */
#include <cstdlib>
#endif

#include "sort_SortTest.hxx"
#include "sort_MergeSort.hxx"
#include "sort_QuickSort.hxx"
#include "sort_HeapSort.hxx"
#include "sort_SortingAlgorithm.hxx"
#include "synch.hxx"
#include <cstdio>

#ifdef SIDL_USE_UCXX
using namespace ucxx;
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


#define MYASSERT( AAA ) \
  magicNumber = clearstack(magicNumber); \
  synch::RegOut::getInstance().startPart( ++part_no ); \
  synch::RegOut::getInstance().writeComment(#AAA); \
  if ( AAA ) result = synch::ResultType_PASS; \
  else result = synch::ResultType_FAIL;  \
  synch::RegOut::getInstance().endPart(part_no, result);

int main(int argc, char **argv)
{
  synch::RegOut tracker = synch::RegOut::getInstance();
  int magicNumber = 1;
  synch::ResultType result = synch::ResultType_PASS;
  int part_no = 0;
  sort::MergeSort merge = sort::MergeSort::_create();
  sort::QuickSort quick = sort::QuickSort::_create();
  sort::HeapSort heap = sort::HeapSort::_create();
  sidl::array<sort::SortingAlgorithm> algs = sidl::array<sort::SortingAlgorithm>::create1d(3);
  srandom(time(NULL));
  tracker.setExpectations(4);
  MYASSERT(merge._not_nil());
  MYASSERT(quick._not_nil());
  MYASSERT(heap._not_nil());
  algs.set(0, merge);
  algs.set(1, quick);
  algs.set(2, heap);
  MYASSERT(sort::SortTest::stressTest(algs));  
  tracker.close();  // require when using singleton
  return 0;
}
