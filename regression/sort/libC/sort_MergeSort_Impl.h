/*
 * File:          sort_MergeSort_Impl.h
 * Symbol:        sort.MergeSort-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.MergeSort
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_MergeSort_Impl_h
#define included_sort_MergeSort_Impl_h

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
#ifndef included_sort_Comparator_h
#include "sort_Comparator.h"
#endif
#ifndef included_sort_Container_h
#include "sort_Container.h"
#endif
#ifndef included_sort_Counter_h
#include "sort_Counter.h"
#endif
#ifndef included_sort_MergeSort_h
#include "sort_MergeSort.h"
#endif
#ifndef included_sort_SortingAlgorithm_h
#include "sort_SortingAlgorithm.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.MergeSort._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(sort.MergeSort._hincludes) */

/*
 * Private data for class sort.MergeSort
 */

struct sort_MergeSort__data {
  /* DO-NOT-DELETE splicer.begin(sort.MergeSort._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(sort.MergeSort._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_MergeSort__data*
sort_MergeSort__get_data(
  sort_MergeSort);

extern void
sort_MergeSort__set_data(
  sort_MergeSort,
  struct sort_MergeSort__data*);

extern
void
impl_sort_MergeSort__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_MergeSort__ctor(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_MergeSort__ctor2(
  /* in */ sort_MergeSort self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_MergeSort__dtor(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sort_Comparator__object* 
  impl_sort_MergeSort_fconnect_sort_Comparator(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sort_MergeSort_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex);
extern struct sort_Container__object* 
  impl_sort_MergeSort_fconnect_sort_Container(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sort_MergeSort_sort(
  /* in */ sort_MergeSort self,
  /* in */ sort_Container elems,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex);

extern
char*
impl_sort_MergeSort_getName(
  /* in */ sort_MergeSort self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sort_Comparator__object* 
  impl_sort_MergeSort_fconnect_sort_Comparator(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sort_MergeSort_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex);
extern struct sort_Container__object* 
  impl_sort_MergeSort_fconnect_sort_Container(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
