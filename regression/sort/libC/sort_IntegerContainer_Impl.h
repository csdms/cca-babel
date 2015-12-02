/*
 * File:          sort_IntegerContainer_Impl.h
 * Symbol:        sort.IntegerContainer-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.IntegerContainer
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_sort_IntegerContainer_Impl_h
#define included_sort_IntegerContainer_Impl_h

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
#ifndef included_sort_IntegerContainer_h
#include "sort_IntegerContainer.h"
#endif
/* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._hincludes) */
#include "sort_Integer.h"
/* DO-NOT-DELETE splicer.end(sort.IntegerContainer._hincludes) */

/*
 * Private data for class sort.IntegerContainer
 */

struct sort_IntegerContainer__data {
  /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._data) */
  struct sort_Integer__array *d_elements;
  /* DO-NOT-DELETE splicer.end(sort.IntegerContainer._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct sort_IntegerContainer__data*
sort_IntegerContainer__get_data(
  sort_IntegerContainer);

extern void
sort_IntegerContainer__set_data(
  sort_IntegerContainer,
  struct sort_IntegerContainer__data*);

extern
void
impl_sort_IntegerContainer__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_IntegerContainer__ctor(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_IntegerContainer__ctor2(
  /* in */ sort_IntegerContainer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_IntegerContainer__dtor(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sort_Comparator__object* 
  impl_sort_IntegerContainer_fconnect_sort_Comparator(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sort_IntegerContainer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_sort_IntegerContainer_setLength(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t len,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sort_IntegerContainer_getLength(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_sort_IntegerContainer_compare(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t i,
  /* in */ int32_t j,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_IntegerContainer_swap(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t i,
  /* in */ int32_t j,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sort_IntegerContainer_output(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t s,
  /* in */ int32_t e,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sort_Comparator__object* 
  impl_sort_IntegerContainer_fconnect_sort_Comparator(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sort_IntegerContainer_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
