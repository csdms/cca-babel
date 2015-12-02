/*
 * File:          sort_IntegerContainer_Impl.c
 * Symbol:        sort.IntegerContainer-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sort.IntegerContainer
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sort.IntegerContainer" (version 0.1)
 * 
 * Integer container.
 */

#include "sort_IntegerContainer_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._includes) */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort_Integer.h"
#include "synch_RegOut.h"
#include "sidl_Exception.h"
/* DO-NOT-DELETE splicer.end(sort.IntegerContainer._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer__ctor(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor) */
  struct sort_IntegerContainer__data *dptr =
    malloc(sizeof(struct sort_IntegerContainer__data));
  if (dptr) {
    dptr->d_elements = NULL;
  }
  sort_IntegerContainer__set_data(self, dptr);
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer__ctor2(
  /* in */ sort_IntegerContainer self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor2) */
  /* Insert-Code-Here {sort.IntegerContainer._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer__dtor(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor) */
  struct sort_IntegerContainer__data *dptr =
    sort_IntegerContainer__get_data(self);
  if (dptr) {
    if (dptr->d_elements) {
      sort_Integer__array_deleteRef(dptr->d_elements);
      dptr->d_elements = NULL;
    }
    free((void *)dptr);
    sort_IntegerContainer__set_data(self, NULL);
  }
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor) */
  }
}

/*
 * This sets the container length and pseudo-randomly orders the
 * Integer elements contained.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer_setLength"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer_setLength(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t len,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength) */
  if (len >= 0) {
    struct sort_IntegerContainer__data *dptr =
      sort_IntegerContainer__get_data(self);
    if (dptr) {
      int32_t i, j;
      if (dptr->d_elements) {
        sort_Integer__array_deleteRef(dptr->d_elements);
      }
      dptr->d_elements = sort_Integer__array_create1d(len);
      for(i = 0; i < len ; ++i ) {
        sort_Integer iptr = sort_Integer__create(_ex); SIDL_REPORT(*_ex);
        sort_Integer_setValue(iptr, i+1, _ex); SIDL_REPORT(*_ex);
        sort_Integer__array_set1(dptr->d_elements, i, iptr);
        sort_Integer_deleteRef(iptr, _ex); SIDL_REPORT(*_ex);
      }
      /* shuffle the list */
      for(i = len - 1; i > 0; --i) {
        j = random() % (i + 1);
        if (j != i) {
          sort_IntegerContainer_swap(self, i, j, _ex); SIDL_REPORT(*_ex);
        }
      }
    }
  }
 EXIT:;
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength) */
  }
}

/*
 * Return the number of elements in the container.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer_getLength"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_IntegerContainer_getLength(
  /* in */ sort_IntegerContainer self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength) */
  struct sort_IntegerContainer__data *dptr =
    sort_IntegerContainer__get_data(self);
  return (dptr && dptr->d_elements) ? 
    (sort_Integer__array_upper(dptr->d_elements, 0) - 
     sort_Integer__array_lower(dptr->d_elements, 0) + 1)  : 0;
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength) */
  }
}

/*
 * Return -1 if element i is less than element j, 0 if element i
 * is equal to element j, or otherwise 1.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer_compare"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_sort_IntegerContainer_compare(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t i,
  /* in */ int32_t j,
  /* in */ sort_Comparator comp,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare) */
  struct sort_IntegerContainer__data *dptr =
    sort_IntegerContainer__get_data(self);
  int result = 0;
  if (dptr && dptr->d_elements) {
    sort_Integer i1 = sort_Integer__array_get1(dptr->d_elements, i);
    sort_Integer i2 = sort_Integer__array_get1(dptr->d_elements, j);
    result = sort_Comparator_compare(comp,
                                     (sidl_BaseInterface)i1,
                                     (sidl_BaseInterface)i2, _ex);
    SIDL_REPORT(*_ex);
    sort_Integer_deleteRef(i1, _ex); SIDL_REPORT(*_ex);
    sort_Integer_deleteRef(i2, _ex); SIDL_REPORT(*_ex);
  }
 EXIT:
  return result;
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare) */
  }
}

/*
 * Swap elements i and j.
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer_swap"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer_swap(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t i,
  /* in */ int32_t j,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap) */
  struct sort_IntegerContainer__data *dptr =
    sort_IntegerContainer__get_data(self);
  if (dptr && dptr->d_elements) {
    const int32_t len = sort_IntegerContainer_getLength(self, _ex);
    SIDL_REPORT(*_ex);
    if ((i >= 0) && (j >= 0) && (i < len) && (j < len)) {
      sort_Integer i1 = sort_Integer__array_get1(dptr->d_elements, i);
      sort_Integer i2 = sort_Integer__array_get1(dptr->d_elements, j);
      sort_Integer__array_set1(dptr->d_elements, i, i2);
      sort_Integer__array_set1(dptr->d_elements, j, i1);
      sort_Integer_deleteRef(i1, _ex); SIDL_REPORT(*_ex);
      sort_Integer_deleteRef(i2, _ex); SIDL_REPORT(*_ex);
    }
    else {
      synch_RegOut tracker = synch_RegOut_getInstance(_ex); SIDL_REPORT(*_ex);
      fprintf(stderr, "\
sort::IntegerContainer::swap index out of bounds swap(%d, %d) len (%d)\n",
              i, j, len);
      synch_RegOut_forceFailure(tracker, _ex); SIDL_REPORT(*_ex);
      synch_RegOut_deleteRef(tracker, _ex); SIDL_REPORT(*_ex);
    }
  }
 EXIT:;
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap) */
  }
}

/*
 * Print elements s through e-1
 */

#undef __FUNC__
#define __FUNC__ "impl_sort_IntegerContainer_output"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sort_IntegerContainer_output(
  /* in */ sort_IntegerContainer self,
  /* in */ int32_t s,
  /* in */ int32_t e,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output) */
  struct sort_IntegerContainer__data *dptr =
    sort_IntegerContainer__get_data(self);
  if (dptr && dptr->d_elements) {
    static const char text[] = "list";
    const size_t bufsize = 14*(e-s) + 6;
    size_t entry_len;
    char *buffer = malloc(bufsize), entry[15];
    int current = sizeof(text)-1;
    synch_RegOut tracker = synch_RegOut_getInstance(_ex); SIDL_REPORT(*_ex);
    strcpy(buffer, text);
    while (s < e && (current < bufsize)) {
      sort_Integer i = sort_Integer__array_get1(dptr->d_elements, s++);
      sprintf(entry, " %d", sort_Integer_getValue(i, _ex)); SIDL_REPORT(*_ex);
      entry_len = strlen(entry);
      if ((current + entry_len) < bufsize) {
        strcpy(buffer + current, entry);
        current += entry_len;
      }
      else {
        current = bufsize + 1;
      }
      sort_Integer_deleteRef(i, _ex); SIDL_REPORT(*_ex);
    }
  EXIT:
    {
      sidl_BaseInterface throwaway_exception;
      if (tracker && buffer) {
        synch_RegOut_writeComment(tracker, buffer, &throwaway_exception);
      }
      if (tracker) {
        synch_RegOut_deleteRef(tracker, &throwaway_exception);
      }
    }
    if (buffer) free(buffer);
  }
    /* DO-NOT-DELETE splicer.end(sort.IntegerContainer.output) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

