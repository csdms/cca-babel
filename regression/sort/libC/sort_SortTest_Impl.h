/*
 * File:          sort_SortTest_Impl.h
 * Symbol:        sort.SortTest-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.SortTest
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_SortTest_Impl_h
#define included_sort_SortTest_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
#ifndef included_sort_SortTest_h
#include "sort_SortTest.h"
#endif
#ifndef included_sort_SortingAlgorithm_h
#include "sort_SortingAlgorithm.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.SortTest._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(sort.SortTest._hincludes) */

/*
 * Private data for class sort.SortTest
 */

struct sort_SortTest__data {
  /* DO-NOT-DELETE splicer.begin(sort.SortTest._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(sort.SortTest._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_SortTest__data*
sort_SortTest__get_data(
  sort_SortTest);

extern void
sort_SortTest__set_data(
  sort_SortTest,
  struct sort_SortTest__data*);

extern
void
impl_sort_SortTest__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SortTest__ctor(
  /* in */ sort_SortTest self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SortTest__ctor2(
  /* in */ sort_SortTest self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SortTest__dtor(
  /* in */ sort_SortTest self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

extern
sidl_bool
impl_sort_SortTest_stressTest(
  /* in array<sort.SortingAlgorithm> */ struct sort_SortingAlgorithm__array* 
    algs,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_SortTest_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_SortTest_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
