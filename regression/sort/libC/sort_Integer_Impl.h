/*
 * File:          sort_Integer_Impl.h
 * Symbol:        sort.Integer-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.Integer
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_Integer_Impl_h
#define included_sort_Integer_Impl_h

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
#ifndef included_sort_Integer_h
#include "sort_Integer.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.Integer._hincludes) */

/* DO-NOT-DELETE splicer.end(sort.Integer._hincludes) */

/*
 * Private data for class sort.Integer
 */

struct sort_Integer__data {
  /* DO-NOT-DELETE splicer.begin(sort.Integer._data) */
  int32_t d_num;
  /* DO-NOT-DELETE splicer.end(sort.Integer._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_Integer__data*
sort_Integer__get_data(
  sort_Integer);

extern void
sort_Integer__set_data(
  sort_Integer,
  struct sort_Integer__data*);

extern
void
impl_sort_Integer__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_Integer__ctor(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_Integer__ctor2(
  /* in */ sort_Integer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_Integer__dtor(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_Integer_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
int32_t
impl_sort_Integer_getValue(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_Integer_setValue(
  /* in */ sort_Integer self,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_Integer_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
