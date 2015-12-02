/*
 * File:          sort_SimpleCounter_Impl.c
 * Symbol:        sort.SimpleCounter-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.SimpleCounter
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.SimpleCounter" (version 0.1)
 * 
 * Simple counter
 */

#include "sort_SimpleCounter_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._includes) */
#include <stdlib.h>
/* DO-NOT-DELETE splicer.end(sort.SimpleCounter._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SimpleCounter__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SimpleCounter__ctor(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor) */
  struct sort_SimpleCounter__data *dptr =
    malloc(sizeof(struct sort_SimpleCounter__data));
  if (dptr) {
    dptr->d_count = 0;
  }
  sort_SimpleCounter__set_data(self, dptr);
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SimpleCounter__ctor2(
  /* in */ sort_SimpleCounter self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor2) */
  /* Insert-Code-Here {sort.SimpleCounter._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SimpleCounter__dtor(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor) */
  struct sort_SimpleCounter__data *dptr =
    sort_SimpleCounter__get_data(self);
  if (dptr) {
    free((void *)dptr);
  }
  sort_SimpleCounter__set_data(self, NULL);
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor) */
  }
}

/*
 * Set the count to zero.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter_reset"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_SimpleCounter_reset(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset) */
  struct sort_SimpleCounter__data *dptr =
    sort_SimpleCounter__get_data(self);
  if (dptr) {
    dptr->d_count = 0;
  }
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset) */
  }
}

/*
 * Return the current count.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter_getCount"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_SimpleCounter_getCount(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount) */
  struct sort_SimpleCounter__data *dptr =
    sort_SimpleCounter__get_data(self);
  return dptr ? dptr->d_count : 0;
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount) */
  }
}

/*
 * Increment the count (i.e. add one).
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_SimpleCounter_inc"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_SimpleCounter_inc(
  /* in */ sort_SimpleCounter self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc) */
  struct sort_SimpleCounter__data *dptr =
    sort_SimpleCounter__get_data(self);
  return dptr ? (++(dptr->d_count)) : 0;
    /* DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

