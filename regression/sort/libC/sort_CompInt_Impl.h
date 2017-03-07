/*
 * File:          sort_CompInt_Impl.h
 * Symbol:        sort.CompInt-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.CompInt
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_CompInt_Impl_h
#define included_sort_CompInt_Impl_h

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
#ifndef included_sort_CompInt_h
#include "sort_CompInt.h"
#endif
#ifndef included_sort_Comparator_h
#include "sort_Comparator.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.CompInt._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(sort.CompInt._hincludes) */

/*
 * Private data for class sort.CompInt
 */

struct sort_CompInt__data {
  /* DO-NOT-DELETE splicer.begin(sort.CompInt._data) */
  sidl_bool d_increasing;
  /* DO-NOT-DELETE splicer.end(sort.CompInt._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_CompInt__data*
sort_CompInt__get_data(
  sort_CompInt);

extern void
sort_CompInt__set_data(
  sort_CompInt,
  struct sort_CompInt__data*);

extern
void
impl_sort_CompInt__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_CompInt__ctor(
  /* in */ sort_CompInt self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_CompInt__ctor2(
  /* in */ sort_CompInt self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_CompInt__dtor(
  /* in */ sort_CompInt self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_CompInt_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sort_CompInt_setSortIncreasing(
  /* in */ sort_CompInt self,
  /* in */ sidl_bool increasing,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sort_CompInt_compare(
  /* in */ sort_CompInt self,
  /* in */ sidl_BaseInterface i1,
  /* in */ sidl_BaseInterface i2,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_CompInt_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
