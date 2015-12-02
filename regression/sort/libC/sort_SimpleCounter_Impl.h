/*
 * File:          sort_SimpleCounter_Impl.h
 * Symbol:        sort.SimpleCounter-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.SimpleCounter
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_SimpleCounter_Impl_h
#define included_sort_SimpleCounter_Impl_h

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
#ifndef included_sort_Counter_h
#include "sort_Counter.h"
#endif
#ifndef included_sort_SimpleCounter_h
#include "sort_SimpleCounter.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(sort.SimpleCounter._hincludes) */

/*
 * Private data for class sort.SimpleCounter
 */

struct sort_SimpleCounter__data {
  /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._data) */
  int32_t d_count;
  /* DO-NOT-DELETE splicer.end(sort.SimpleCounter._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_SimpleCounter__data*
sort_SimpleCounter__get_data(
  sort_SimpleCounter);

extern void
sort_SimpleCounter__set_data(
  sort_SimpleCounter,
  struct sort_SimpleCounter__data*);

extern
void
impl_sort_SimpleCounter__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SimpleCounter__ctor(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SimpleCounter__ctor2(
  /* in */ sort_SimpleCounter self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_SimpleCounter__dtor(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_SimpleCounter_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sort_SimpleCounter_reset(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sort_SimpleCounter_getCount(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sort_SimpleCounter_inc(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_sort_SimpleCounter_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
