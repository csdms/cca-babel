/*
 * File:          sort_CompInt_Impl.c
 * Symbol:        sort.CompInt-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.CompInt
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.CompInt" (version 0.1)
 * 
 * Compare two Integer's.  By default, this will sort in increasing order.
 */

#include "sort_CompInt_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.CompInt._includes) */
#include <stdlib.h>
#include "sort_Integer.h"
/* DO-NOT-DELETE splicer.end(sort.CompInt._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_CompInt__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.CompInt._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_CompInt__ctor(
  /* in */ sort_CompInt self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt._ctor) */
  struct sort_CompInt__data *dptr =
    malloc(sizeof(struct sort_CompInt__data));
  if (dptr) {
    dptr->d_increasing = TRUE;
  }
  sort_CompInt__set_data(self, dptr);
    /* DO-NOT-DELETE splicer.end(sort.CompInt._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_CompInt__ctor2(
  /* in */ sort_CompInt self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt._ctor2) */
  /* Insert-Code-Here {sort.CompInt._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.CompInt._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_CompInt__dtor(
  /* in */ sort_CompInt self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt._dtor) */
  struct sort_CompInt__data *dptr = 
    sort_CompInt__get_data(self);
  if (dptr) {
    free((void*)dptr);
    sort_CompInt__set_data(self, NULL);
  }
    /* DO-NOT-DELETE splicer.end(sort.CompInt._dtor) */
  }
}

/*
 * If increasing is true, this will cause the comparator to
 * report a normal definition of less than; otherwise, it will
 * reverse the normal ordering.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt_setSortIncreasing"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_CompInt_setSortIncreasing(
  /* in */ sort_CompInt self,
  /* in */ sidl_bool increasing,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt.setSortIncreasing) */
  struct sort_CompInt__data *dptr = 
    sort_CompInt__get_data(self);
  if (dptr) {
    dptr->d_increasing = increasing;
  }
    /* DO-NOT-DELETE splicer.end(sort.CompInt.setSortIncreasing) */
  }
}

/*
 * This method is used to define an ordering of objects.  This method
 * will return -1 if i1 < i2, 0 if i1 = i2; and 1 if i1 > i2.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_CompInt_compare"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_CompInt_compare(
  /* in */ sort_CompInt self,
  /* in */ sidl_BaseInterface i1,
  /* in */ sidl_BaseInterface i2,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.CompInt.compare) */
  int result = 0;
  struct sort_CompInt__data *dptr = 
    sort_CompInt__get_data(self);
  if (dptr) {
    sort_Integer int1 = sort_Integer__cast(i1, _ex);
    sort_Integer int2 = sort_Integer__cast(i2, _ex);
    if (int1 && int2) {
      const int32_t val1 = sort_Integer_getValue(int1, _ex);
      const int32_t val2 = sort_Integer_getValue(int2, _ex);
      if (val1 < val2) result = -1;
      if (val1 > val2) result = 1;
      if (!dptr->d_increasing) {
        result = -result;
      }
    }
    if (int1) sort_Integer_deleteRef(int1, _ex);
    if (int2) sort_Integer_deleteRef(int2, _ex);
  }
  return result;
    /* DO-NOT-DELETE splicer.end(sort.CompInt.compare) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

