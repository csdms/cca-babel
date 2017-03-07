/*
 * File:          sort_Integer_Impl.c
 * Symbol:        sort.Integer-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Server-side implementation for sort.Integer
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.Integer" (version 0.1)
 * 
 * An object to hold a simple integer.
 */

#include "sort_Integer_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.Integer._includes) */
#include <stdlib.h>
/* DO-NOT-DELETE splicer.end(sort.Integer._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_Integer__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.Integer._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_Integer__ctor(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer._ctor) */
  struct sort_Integer__data *dptr =
    malloc(sizeof(struct sort_Integer__data));
  if (dptr) {
    dptr->d_num = 0;
  }
  sort_Integer__set_data(self, dptr);
    /* DO-NOT-DELETE splicer.end(sort.Integer._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_Integer__ctor2(
  /* in */ sort_Integer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer._ctor2) */
  /* Insert-Code-Here {sort.Integer._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.Integer._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_Integer__dtor(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer._dtor) */
  struct sort_Integer__data *dptr =
    sort_Integer__get_data(self);
  if (dptr) {
    free((void *)dptr);
    sort_Integer__set_data(self, NULL);
  }
    /* DO-NOT-DELETE splicer.end(sort.Integer._dtor) */
  }
}

/*
 * Method:  getValue[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer_getValue"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_Integer_getValue(
  /* in */ sort_Integer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer.getValue) */
  struct sort_Integer__data *dptr =
    sort_Integer__get_data(self);
  return dptr ? dptr->d_num : 0;
    /* DO-NOT-DELETE splicer.end(sort.Integer.getValue) */
  }
}

/*
 * Method:  setValue[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_Integer_setValue"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_Integer_setValue(
  /* in */ sort_Integer self,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.Integer.setValue) */
  struct sort_Integer__data *dptr =
    sort_Integer__get_data(self);
  if (dptr) {
    dptr->d_num = value;
  }
    /* DO-NOT-DELETE splicer.end(sort.Integer.setValue) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

