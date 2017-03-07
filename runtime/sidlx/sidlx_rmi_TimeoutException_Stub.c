/*
 * File:          sidlx_rmi_TimeoutException_Stub.c
 * Symbol:        sidlx.rmi.TimeoutException-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Client-side glue code for sidlx.rmi.TimeoutException
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#define SIDLX_RMI_TIMEOUTEXCEPTION_INLINE_DECL
#include "sidlx_rmi_TimeoutException.h"
#include "sidlx_rmi_TimeoutException_IOR.h"
#ifndef included_sidl_interface_IOR_h
#include "sidl_interface_IOR.h"
#endif
#ifndef included_sidl_rmi_InstanceHandle_h
#include "sidl_rmi_InstanceHandle.h"
#endif
#ifndef included_sidl_rmi_ConnectRegistry_h
#include "sidl_rmi_ConnectRegistry.h"
#endif
#include "sidl_Exception.h"
#ifndef included_sidl_interface_IOR_h
#include "sidl_interface_IOR.h"
#endif
#include <stddef.h>
#include <string.h>
#include "sidl_BaseInterface_IOR.h"
#include "babel_config.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

#define LANG_SPECIFIC_INIT()

/*
 * Hold pointer to IOR functions.
 */

static const struct sidlx_rmi_TimeoutException__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct sidlx_rmi_TimeoutException__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _externals = sidlx_rmi_TimeoutException__externals();
#else
  _externals = (struct 
    sidlx_rmi_TimeoutException__external*)sidl_dynamicLoadIOR(
    "sidlx.rmi.TimeoutException","sidlx_rmi_TimeoutException__externals") ;
  sidl_checkIORVersion("sidlx.rmi.TimeoutException", 
    _externals->d_ior_major_version, _externals->d_ior_minor_version, 2, 0);
#endif
  return _externals;
}

#define _getExternals() (_externals ? _externals : _loadIOR())

/*
 * Constructor function for the class.
 */

sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__create(sidl_BaseInterface* _ex)
{
  return (*(_getExternals()->createObject))(NULL,_ex);
}

/**
 * Wraps up the private data struct pointer (struct sidlx_rmi_TimeoutException__data) passed in rather than running the constructor.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__wrapObj(void* data, sidl_BaseInterface* _ex)
{
  return (*(_getExternals()->createObject))(data, _ex);
}

#ifdef WITH_RMI

static sidlx_rmi_TimeoutException sidlx_rmi_TimeoutException__remoteCreate(
  const char* url, sidl_BaseInterface *_ex);
/*
 * RMI constructor function for the class.
 */

sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__createRemote(const char* url, sidl_BaseInterface 
  *_ex)
{
  return sidlx_rmi_TimeoutException__remoteCreate(url, _ex);
}

static struct sidlx_rmi_TimeoutException__object* 
  sidlx_rmi_TimeoutException__remoteConnect(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
static struct sidlx_rmi_TimeoutException__object* 
  sidlx_rmi_TimeoutException__IHConnect(struct sidl_rmi_InstanceHandle__object* 
  instance, sidl_BaseInterface *_ex);
/*
 * RMI connector function for the class.
 */

sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__connect(const char* url, sidl_BaseInterface *_ex)
{
  return sidlx_rmi_TimeoutException__remoteConnect(url, TRUE, _ex);
}

#endif /*WITH_RMI*/

/*
 * Cast method for interface and class type conversions.
 */

sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__cast(
  void* obj,
  sidl_BaseInterface* _ex)
{
  sidlx_rmi_TimeoutException cast = NULL;

#ifdef WITH_RMI
  static int connect_loaded = 0;
  if (!connect_loaded) {
    connect_loaded = 1;
    sidl_rmi_ConnectRegistry_registerConnect("sidlx.rmi.TimeoutException", (
      void*)sidlx_rmi_TimeoutException__IHConnect,_ex);SIDL_CHECK(*_ex);
  }
#endif /*WITH_RMI*/
  if (obj != NULL) {
    sidl_BaseInterface base = (sidl_BaseInterface) obj;
    cast = (sidlx_rmi_TimeoutException) (*base->d_epv->f__cast)(
      base->d_object,
      "sidlx.rmi.TimeoutException", _ex); SIDL_CHECK(*_ex);
  }

  EXIT:
  return cast;
}

/*
 * String cast method for interface and class type conversions.
 */

void*
sidlx_rmi_TimeoutException__cast2(
  void* obj,
  const char* type,
  sidl_BaseInterface* _ex)
{
  void* cast = NULL;

  if (obj != NULL) {
    sidl_BaseInterface base = (sidl_BaseInterface) obj;
    cast = (*base->d_epv->f__cast)(base->d_object, type, _ex); SIDL_CHECK(*_ex);
  }

  EXIT:
  return cast;
}




/*
 * TRUE if this object is remote, false if local
 */

sidl_bool
sidlx_rmi_TimeoutException__isLocal(
  /* in */ sidlx_rmi_TimeoutException self,
  /* out */ sidl_BaseInterface *_ex)
{
  return !sidlx_rmi_TimeoutException__isRemote(self, _ex);
}

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in column-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[])
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_createCol(dimen, 
    lower, upper);
}

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in row-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[])
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_createRow(dimen, 
    lower, upper);
}

/**
 * Create a contiguous one-dimensional array with a lower index
 * of 0 and an upper index of len-1. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_create1d(int32_t len)
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_create1d(len);
}

/**
 * Create a dense one-dimensional vector with a lower
 * index of 0 and an upper index of len-1. The initial data for this
 * new array is copied from data. This will increment the reference
 * count of each non-NULL object/interface reference in data.
 * 
 * This array owns and manages its data.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_create1dInit(
  int32_t len, 
  sidlx_rmi_TimeoutException* data)
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_create1dInit(len, (
    struct sidl_BaseInterface__object **)data);
}

/**
 * Create a contiguous two-dimensional array in column-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_create2dCol(int32_t m, int32_t n)
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_create2dCol(m, n);
}

/**
 * Create a contiguous two-dimensional array in row-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_create2dRow(int32_t m, int32_t n)
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_create2dRow(m, n);
}

/**
 * Create an array that uses data (memory) from another
 * source. The initial contents are determined by the
 * data being borrowed.
 * Any time an element in the borrowed array is replaced
 * via a set call, deleteRef will be called on the
 * value being replaced if it is not NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_borrow(
  sidlx_rmi_TimeoutException* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[])
{
  return (struct 
    sidlx_rmi_TimeoutException__array*)sidl_interface__array_borrow(
    (struct sidl_BaseInterface__object **)
    firstElement, dimen, lower, upper, stride);
}

/**
 * If array is borrowed, allocate a new self-sufficient
 * array and copy the borrowed array into the new array;
 * otherwise, increment the reference count and return
 * the array passed in. Use this whenever you want to
 * make a copy of a method argument because arrays
 * passed into methods aren't guaranteed to exist after
 * the method call.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_smartCopy(
  struct sidlx_rmi_TimeoutException__array *array)
{
  return (struct sidlx_rmi_TimeoutException__array*)
    sidl_interface__array_smartCopy((struct sidl_interface__array *)array);
}

/**
 * Increment the array's internal reference count by one.
 */
void
sidlx_rmi_TimeoutException__array_addRef(
  struct sidlx_rmi_TimeoutException__array* array)
{
  sidl_interface__array_addRef((struct sidl_interface__array *)array);
}

/**
 * Decrement the array's internal reference count by one.
 * If the reference count goes to zero, destroy the array.
 * If the array isn't borrowed, this releases all the
 * object references held by the array.
 */
void
sidlx_rmi_TimeoutException__array_deleteRef(
  struct sidlx_rmi_TimeoutException__array* array)
{
  sidl_interface__array_deleteRef((struct sidl_interface__array *)array);
}

/**
 * Retrieve element i1 of a(n) 1-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get1(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get1((const struct sidl_interface__array *)array
    , i1);
}

/**
 * Retrieve element (i1,i2) of a(n) 2-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get2(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get2((const struct sidl_interface__array *)array
    , i1, i2);
}

/**
 * Retrieve element (i1,i2,i3) of a(n) 3-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get3(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get3((const struct sidl_interface__array *)array
    , i1, i2, i3);
}

/**
 * Retrieve element (i1,i2,i3,i4) of a(n) 4-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get4(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get4((const struct sidl_interface__array *)array
    , i1, i2, i3, i4);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get5(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get5((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get6(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get6((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5, i6);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get7(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7)
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get7((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5, i6, i7);
}

/**
 * Retrieve element indices of an n-dimensional array.
 * indices is assumed to have the right number of elements
 * for the dimension of array.
 */
sidlx_rmi_TimeoutException
sidlx_rmi_TimeoutException__array_get(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t indices[])
{
  return (sidlx_rmi_TimeoutException)
    sidl_interface__array_get((const struct sidl_interface__array *)array, 
      indices);
}

/**
 * Set element i1 of a(n) 1-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set1(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set1((struct sidl_interface__array *)array
  , i1, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2) of a(n) 2-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set2(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set2((struct sidl_interface__array *)array
  , i1, i2, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3) of a(n) 3-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set3(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set3((struct sidl_interface__array *)array
  , i1, i2, i3, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4) of a(n) 4-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set4(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set4((struct sidl_interface__array *)array
  , i1, i2, i3, i4, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set5(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set5((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set6(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set6((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, i6, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array to value.
 */
void
sidlx_rmi_TimeoutException__array_set7(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set7((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, i6, i7, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element indices of an n-dimensional array to value.indices is assumed to have the right number of elements
 * for the dimension of array.
 */
void
sidlx_rmi_TimeoutException__array_set(
  struct sidlx_rmi_TimeoutException__array* array,
  const int32_t indices[],
  sidlx_rmi_TimeoutException const value)
{
  sidl_interface__array_set((struct sidl_interface__array *)array, indices, (
    struct sidl_BaseInterface__object *)value);
}

/**
 * Return the dimension of array. If the array pointer is
 * NULL, zero is returned.
 */
int32_t
sidlx_rmi_TimeoutException__array_dimen(
  const struct sidlx_rmi_TimeoutException__array* array)
{
  return sidl_interface__array_dimen((struct sidl_interface__array *)array);
}

/**
 * Return the lower bound of dimension ind.
 * If ind is not a valid dimension, 0 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_TimeoutException__array_lower(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t ind)
{
  return sidl_interface__array_lower((struct sidl_interface__array *)array, 
    ind);
}

/**
 * Return the upper bound of dimension ind.
 * If ind is not a valid dimension, -1 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_TimeoutException__array_upper(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t ind)
{
  return sidl_interface__array_upper((struct sidl_interface__array *)array, 
    ind);
}

/**
 * Return the length of dimension ind.
 * If ind is not a valid dimension, -1 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_TimeoutException__array_length(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t ind)
{
  return sidl_interface__array_length((struct sidl_interface__array *)array, 
    ind);
}

/**
 * Return the stride of dimension ind.
 * If ind is not a valid dimension, 0 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidlx_rmi_TimeoutException__array_stride(
  const struct sidlx_rmi_TimeoutException__array* array,
  const int32_t ind)
{
  return sidl_interface__array_stride((struct sidl_interface__array *)array, 
    ind);
}

/**
 * Return a true value iff the array is a contiguous
 * column-major ordered array. A NULL array argument
 * causes 0 to be returned.
 */
int
sidlx_rmi_TimeoutException__array_isColumnOrder(
  const struct sidlx_rmi_TimeoutException__array* array)
{
  return sidl_interface__array_isColumnOrder((struct sidl_interface__array 
    *)array);
}

/**
 * Return a true value iff the array is a contiguous
 * row-major ordered array. A NULL array argument
 * causes 0 to be returned.
 */
int
sidlx_rmi_TimeoutException__array_isRowOrder(
  const struct sidlx_rmi_TimeoutException__array* array)
{
  return sidl_interface__array_isRowOrder((struct sidl_interface__array 
    *)array);
}

/**
 * Copy the contents of one array (src) to a second array
 * (dest). For the copy to take place, both arrays must
 * exist and be of the same dimension. This method will
 * not modify dest's size, index bounds, or stride; only
 * the array element values of dest may be changed by
 * this function. No part of src is ever changed by copy.
 * 
 * On exit, dest[i][j][k]... = src[i][j][k]... for all
 * indices i,j,k...  that are in both arrays. If dest and
 * src have no indices in common, nothing is copied. For
 * example, if src is a 1-d array with elements 0-5 and
 * dest is a 1-d array with elements 2-3, this function
 * will make the following assignments:
 *   dest[2] = src[2],
 *   dest[3] = src[3].
 * The function copied the elements that both arrays have
 * in common.  If dest had elements 4-10, this function
 * will make the following assignments:
 *   dest[4] = src[4],
 *   dest[5] = src[5].
 */
void
sidlx_rmi_TimeoutException__array_copy(
  const struct sidlx_rmi_TimeoutException__array* src,
  struct sidlx_rmi_TimeoutException__array* dest)
{
  sidl_interface__array_copy((const struct sidl_interface__array *)src,
                             (struct sidl_interface__array *)dest);
}

/**
 * Create a sub-array of another array. This resulting
 * array shares data with the original array. The new
 * array can be of the same dimension or potentially
 * less assuming the original array has dimension
 * greater than 1.  If you are removing dimension,
 * indicate the dimensions to remove by setting
 * numElem[i] to zero for any dimension i wthat should
 * go away in the new array.  The meaning of each
 * argument is covered below.
 * 
 * src       the array to be created will be a subset
 *           of this array. If this argument is NULL,
 *           NULL will be returned. The array returned
 *           borrows data from src, so modifying src or
 *           the returned array will modify both
 *           arrays.
 * 
 * dimen     this argument must be greater than zero
 *           and less than or equal to the dimension of
 *           src. An illegal value will cause a NULL
 *           return value.
 * 
 * numElem   this specifies how many elements from src
 *           should be taken in each dimension. A zero
 *           entry indicates that the dimension should
 *           not appear in the new array.  This
 *           argument should be an array with an entry
 *           for each dimension of src.  Passing NULL
 *           here will cause NULL to be returned.  If
 *           srcStart[i] + numElem[i]*srcStride[i] is
 *           greater than upper[i] for src or if
 *           srcStart[i] + numElem[i]*srcStride[i] is
 *           less than lower[i] for src, NULL will be
 *           returned.
 * 
 * srcStart  this array holds the coordinates of the
 *           first element of the new array. If this
 *           argument is NULL, the first element of src
 *           will be the first element of the new
 *           array. If non-NULL, this argument should
 *           be an array with an entry for each
 *           dimension of src.  If srcStart[i] is less
 *           than lower[i] for the array src, NULL will
 *           be returned.
 * 
 * srcStride this array lets you specify the stride
 *           between elements in each dimension of
 *           src. This stride is relative to the
 *           coordinate system of the src array. If
 *           this argument is NULL, the stride is taken
 *           to be one in each dimension.  If non-NULL,
 *           this argument should be an array with an
 *           entry for each dimension of src.
 * 
 * newLower  this argument is like lower in a create
 *           method. It sets the coordinates for the
 *           first element in the new array.  If this
 *           argument is NULL, the values indicated by
 *           srcStart will be used. If non-NULL, this
 *           should be an array with dimen elements.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_slice(
  struct sidlx_rmi_TimeoutException__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart)
{
  return (struct sidlx_rmi_TimeoutException__array*)
    sidl_interface__array_slice((struct sidl_interface__array *)src,
                                dimen, numElem, srcStart, srcStride, newStart);
}

/**
 * If necessary, convert a general matrix into a matrix
 * with the required properties. This checks the
 * dimension and ordering of the matrix.  If both these
 * match, it simply returns a new reference to the
 * existing matrix. If the dimension of the incoming
 * array doesn't match, it returns NULL. If the ordering
 * of the incoming array doesn't match the specification,
 * a new array is created with the desired ordering and
 * the content of the incoming array is copied to the new
 * array.
 * 
 * The ordering parameter should be one of the constants
 * defined in enum sidl_array_ordering
 * (e.g. sidl_general_order, sidl_column_major_order, or
 * sidl_row_major_order). If you specify
 * sidl_general_order, this routine will only check the
 * dimension because any matrix is sidl_general_order.
 * 
 * The caller assumes ownership of the returned reference
 * unless it's NULL.
 */
struct sidlx_rmi_TimeoutException__array*
sidlx_rmi_TimeoutException__array_ensure(
  struct sidlx_rmi_TimeoutException__array* src,
  int32_t dimen,
  int     ordering)
{
  return (struct sidlx_rmi_TimeoutException__array*)
    sidl_interface__array_ensure((struct sidl_interface__array *)src, dimen, 
      ordering);
}

#ifdef WITH_RMI

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_rmi_ProtocolFactory_h
#include "sidl_rmi_ProtocolFactory.h"
#endif
#ifndef included_sidl_rmi_InstanceRegistry_h
#include "sidl_rmi_InstanceRegistry.h"
#endif
#ifndef included_sidl_rmi_InstanceHandle_h
#include "sidl_rmi_InstanceHandle.h"
#endif
#ifndef included_sidl_rmi_Invocation_h
#include "sidl_rmi_Invocation.h"
#endif
#ifndef included_sidl_rmi_Response_h
#include "sidl_rmi_Response.h"
#endif
#ifndef included_sidl_rmi_ServerRegistry_h
#include "sidl_rmi_ServerRegistry.h"
#endif
#ifndef included_sidl_rmi_ConnectRegistry_h
#include "sidl_rmi_ConnectRegistry.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif
#ifndef included_sidl_NotImplementedException_h
#include "sidl_NotImplementedException.h"
#endif
#include "sidl_Exception.h"

#ifndef NULL
#define NULL 0
#endif

#include "sidl_thread.h"
#ifdef HAVE_PTHREAD
static struct sidl_recursive_mutex_t sidlx_rmi_TimeoutException__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &sidlx_rmi_TimeoutException__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &sidlx_rmi_TimeoutException__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &sidlx_rmi_TimeoutException__mutex )==EDEADLOCK) */
#else
#define LOCK_STATIC_GLOBALS
#define UNLOCK_STATIC_GLOBALS
/* #define HAVE_LOCKED_STATIC_GLOBALS (1) */
#endif

/* Static variables to hold version of IOR */
static const int32_t s_IOR_MAJOR_VERSION = 2;
static const int32_t s_IOR_MINOR_VERSION = 0;

/* Static variables for managing EPV initialization. */
static int s_remote_initialized = 0;

static struct sidlx_rmi_TimeoutException__epv 
  s_rem_epv__sidlx_rmi_timeoutexception;

static struct sidl_BaseClass__epv  s_rem_epv__sidl_baseclass;

static struct sidl_BaseException__epv  s_rem_epv__sidl_baseexception;

static struct sidl_BaseInterface__epv  s_rem_epv__sidl_baseinterface;

static struct sidl_RuntimeException__epv  s_rem_epv__sidl_runtimeexception;

static struct sidl_SIDLException__epv  s_rem_epv__sidl_sidlexception;

static struct sidl_io_IOException__epv  s_rem_epv__sidl_io_ioexception;

static struct sidl_io_Serializable__epv  s_rem_epv__sidl_io_serializable;

static struct sidl_rmi_NetworkException__epv  
  s_rem_epv__sidl_rmi_networkexception;

static struct sidl_rmi_ProtocolException__epv  
  s_rem_epv__sidl_rmi_protocolexception;

static struct sidlx_rmi_RecoverableException__epv  
  s_rem_epv__sidlx_rmi_recoverableexception;


/* REMOTE CAST: dynamic type casting for remote objects. */
static void* remote_sidlx_rmi_TimeoutException__cast(
  struct sidlx_rmi_TimeoutException__object* self,
  const char* name, sidl_BaseInterface* _ex)
{
  int cmp;
  void* cast = NULL;
  *_ex = NULL; /* default to no exception */
  cmp = strcmp(name, "sidl.io.IOException");
  if (!cmp) {
    (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
    cast = ((struct sidl_io_IOException__object*)self);
    return cast;
  }
  else if (cmp < 0) {
    cmp = strcmp(name, "sidl.BaseInterface");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = &((
        *self).d_sidlx_rmi_recoverableexception.d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_baseclass.d_sidl_baseinterface);
      return cast;
    }
    else if (cmp < 0) {
      cmp = strcmp(name, "sidl.BaseException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((
          *self).d_sidlx_rmi_recoverableexception.d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_baseexception);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.BaseClass");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = ((struct sidl_BaseClass__object*)self);
          return cast;
        }
      }
    }
    else if (cmp > 0) {
      cmp = strcmp(name, "sidl.SIDLException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidl_SIDLException__object*)self);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.RuntimeException");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((
            *self).d_sidlx_rmi_recoverableexception.d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_runtimeexception);
          return cast;
        }
      }
    }
  }
  else if (cmp > 0) {
    cmp = strcmp(name, "sidl.rmi.ProtocolException");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = ((struct sidl_rmi_ProtocolException__object*)self);
      return cast;
    }
    else if (cmp < 0) {
      cmp = strcmp(name, "sidl.rmi.NetworkException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidl_rmi_NetworkException__object*)self);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.io.Serializable");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((
            *self).d_sidlx_rmi_recoverableexception.d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_io_serializable);
          return cast;
        }
      }
    }
    else if (cmp > 0) {
      cmp = strcmp(name, "sidlx.rmi.TimeoutException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidlx_rmi_TimeoutException__object*)self);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidlx.rmi.RecoverableException");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = ((struct sidlx_rmi_RecoverableException__object*)self);
          return cast;
        }
      }
    }
  }
  if ((*self->d_epv->f_isType)(self,name, _ex)) {
    void* (*func)(struct sidl_rmi_InstanceHandle__object*, struct 
      sidl_BaseInterface__object**) = 
      (void* (*)(struct sidl_rmi_InstanceHandle__object*, struct 
        sidl_BaseInterface__object**)) 
      sidl_rmi_ConnectRegistry_getConnect(name, _ex);SIDL_CHECK(*_ex);
    cast =  (*func)(((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih, _ex);
  }

  return cast;
  EXIT:
  return NULL;
}

/* REMOTE DELETE: call the remote destructor for the object. */
static void remote_sidlx_rmi_TimeoutException__delete(
  struct sidlx_rmi_TimeoutException__object* self,
  struct sidl_BaseInterface__object* *_ex)
{
  *_ex = NULL;
  free((void*) self);
}

/* REMOTE GETURL: call the getURL function for the object. */
static char* remote_sidlx_rmi_TimeoutException__getURL(
  struct sidlx_rmi_TimeoutException__object* self, struct 
    sidl_BaseInterface__object* *_ex)
{
  struct sidl_rmi_InstanceHandle__object *conn = ((struct 
    sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
  *_ex = NULL;
  if(conn != NULL) {
    return sidl_rmi_InstanceHandle_getObjectURL(conn, _ex);
  }
  return NULL;
}

/* REMOTE ADDREF: For internal babel use only! Remote addRef. */
static void remote_sidlx_rmi_TimeoutException__raddRef(
  struct sidlx_rmi_TimeoutException__object* self,struct 
    sidl_BaseInterface__object* *_ex)
{
  struct sidl_BaseException__object* netex = NULL;
  /* initialize a new invocation */
  struct sidl_BaseInterface__object* _throwaway = NULL;
  struct sidl_rmi_InstanceHandle__object *_conn = ((struct 
    sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
  sidl_rmi_Response _rsvp = NULL;
  sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
    "addRef", _ex ); SIDL_CHECK(*_ex);
  /* send actual RMI request */
  _rsvp = sidl_rmi_Invocation_invokeMethod(_inv,_ex);SIDL_CHECK(*_ex);
  /* Check for exceptions */
  netex = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);
  if(netex != NULL) {
    *_ex = (struct sidl_BaseInterface__object*)netex;
    return;
  }

  /* cleanup and return */
  EXIT:
  if(_inv) { sidl_rmi_Invocation_deleteRef(_inv,&_throwaway); }
  if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp,&_throwaway); }
  return;
}

/* REMOTE ISREMOTE: returns true if this object is Remote (it is). */
static sidl_bool
remote_sidlx_rmi_TimeoutException__isRemote(
    struct sidlx_rmi_TimeoutException__object* self, 
    struct sidl_BaseInterface__object* *_ex) {
  *_ex = NULL;
  return TRUE;
}

/* REMOTE METHOD STUB:_set_hooks */
static void
remote_sidlx_rmi_TimeoutException__set_hooks(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ sidl_bool enable,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "_set_hooks", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packBool( _inv, "enable", enable, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException._set_hooks.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* Contract enforcement has not been implemented for remote use. */
/* REMOTE METHOD STUB:_set_contracts */
static void
remote_sidlx_rmi_TimeoutException__set_contracts(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ sidl_bool enable,
  /* in */ const char* enfFilename,
  /* in */ sidl_bool resetCounters,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "_set_contracts", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packBool( _inv, "enable", enable, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packString( _inv, "enfFilename", enfFilename, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "resetCounters", resetCounters, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException._set_contracts.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* Contract enforcement has not been implemented for remote use. */
/* REMOTE METHOD STUB:_dump_stats */
static void
remote_sidlx_rmi_TimeoutException__dump_stats(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ const char* filename,
  /* in */ const char* prefix,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "_dump_stats", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "filename", filename, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packString( _inv, "prefix", prefix, _ex);SIDL_CHECK(
      *_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException._dump_stats.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE EXEC: call the exec function for the object. */
static void remote_sidlx_rmi_TimeoutException__exec(
  struct sidlx_rmi_TimeoutException__object* self,const char* methodName,
  sidl_rmi_Call inArgs,
  sidl_rmi_Return outArgs,
  struct sidl_BaseInterface__object* *_ex)
{
  *_ex = NULL;
}

/* REMOTE METHOD STUB:getHopCount */
static int32_t
remote_sidlx_rmi_TimeoutException_getHopCount(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    int32_t _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getHopCount", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.getHopCount.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:setErrno */
static void
remote_sidlx_rmi_TimeoutException_setErrno(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ int32_t err,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "setErrno", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packInt( _inv, "err", err, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.setErrno.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE METHOD STUB:getErrno */
static int32_t
remote_sidlx_rmi_TimeoutException_getErrno(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    int32_t _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getErrno", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.getErrno.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:addRef */
static void
remote_sidlx_rmi_TimeoutException_addRef(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    struct sidlx_rmi_TimeoutException__remote* r_obj = (struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data;
    LOCK_STATIC_GLOBALS;
    r_obj->d_refcount++;
#ifdef SIDL_DEBUG_REFCOUNT
    fprintf(stderr, "babel: addRef %p new count %d (type %s)\n",
      r_obj, r_obj->d_refcount, 
      "sidlx.rmi.TimeoutException Remote Stub");
#endif /* SIDL_DEBUG_REFCOUNT */ 
    UNLOCK_STATIC_GLOBALS;
  }
}

/* REMOTE METHOD STUB:deleteRef */
static void
remote_sidlx_rmi_TimeoutException_deleteRef(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    struct sidlx_rmi_TimeoutException__remote* r_obj = (struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data;
    LOCK_STATIC_GLOBALS;
    r_obj->d_refcount--;
#ifdef SIDL_DEBUG_REFCOUNT
    fprintf(stderr, "babel: deleteRef %p new count %d (type %s)\n",r_obj, r_obj->d_refcount, "sidlx.rmi.TimeoutException Remote Stub");
#endif /* SIDL_DEBUG_REFCOUNT */ 
    if(r_obj->d_refcount == 0) {
      sidl_rmi_InstanceHandle_deleteRef(r_obj->d_ih, _ex);
      free(r_obj);
      free(self);
    }
    UNLOCK_STATIC_GLOBALS;
  }
}

/* REMOTE METHOD STUB:isSame */
static sidl_bool
remote_sidlx_rmi_TimeoutException_isSame(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ struct sidl_BaseInterface__object* iobj,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    sidl_bool _retval = FALSE;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "isSame", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    if(iobj){
      char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)iobj, 
        _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packString( _inv, "iobj", _url, _ex);SIDL_CHECK(*_ex);
      free((void*)_url);
    } else {
      sidl_rmi_Invocation_packString( _inv, "iobj", NULL, _ex);SIDL_CHECK(*_ex);
    }

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.isSame.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackBool( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:isType */
static sidl_bool
remote_sidlx_rmi_TimeoutException_isType(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ const char* name,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    sidl_bool _retval = FALSE;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "isType", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "name", name, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.isType.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackBool( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:getClassInfo */
static struct sidl_ClassInfo__object*
remote_sidlx_rmi_TimeoutException_getClassInfo(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    char*_retval_str = NULL;
    struct sidl_ClassInfo__object* _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getClassInfo", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.getClassInfo.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval_str, 
      _ex);SIDL_CHECK(*_ex);
    _retval = sidl_ClassInfo__connectI(_retval_str, FALSE, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:getNote */
static char*
remote_sidlx_rmi_TimeoutException_getNote(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    char* _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getNote", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.getNote.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:setNote */
static void
remote_sidlx_rmi_TimeoutException_setNote(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ const char* message,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "setNote", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "message", message, _ex);SIDL_CHECK(
      *_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.setNote.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE METHOD STUB:getTrace */
static char*
remote_sidlx_rmi_TimeoutException_getTrace(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    char* _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getTrace", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.getTrace.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:addLine */
static void
remote_sidlx_rmi_TimeoutException_addLine(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ const char* traceline,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "addLine", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "traceline", traceline, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.addLine.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE METHOD STUB:add */
static void
remote_sidlx_rmi_TimeoutException_add(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ const char* filename,
  /* in */ int32_t lineno,
  /* in */ const char* methodname,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "add", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "filename", filename, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "lineno", lineno, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packString( _inv, "methodname", methodname, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.add.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE METHOD STUB:packObj */
static void
remote_sidlx_rmi_TimeoutException_packObj(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ struct sidl_io_Serializer__object* ser,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packObj", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    if(ser){
      char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)ser, 
        _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packString( _inv, "ser", _url, _ex);SIDL_CHECK(*_ex);
      free((void*)_url);
    } else {
      sidl_rmi_Invocation_packString( _inv, "ser", NULL, _ex);SIDL_CHECK(*_ex);
    }

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.packObj.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE METHOD STUB:unpackObj */
static void
remote_sidlx_rmi_TimeoutException_unpackObj(
  /* in */ struct sidlx_rmi_TimeoutException__object*self ,
  /* in */ struct sidl_io_Deserializer__object* des,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    /* initialize a new invocation */
    struct sidl_BaseInterface__object* _throwaway = NULL;
    sidl_BaseException _be = NULL;
    sidl_rmi_Response _rsvp = NULL;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidlx_rmi_TimeoutException__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "unpackObj", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    if(des){
      char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)des, 
        _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packString( _inv, "des", _url, _ex);SIDL_CHECK(*_ex);
      free((void*)_url);
    } else {
      sidl_rmi_Invocation_packString( _inv, "des", NULL, _ex);SIDL_CHECK(*_ex);
    }

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidlx.rmi.TimeoutException.unpackObj.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return;
  }
}

/* REMOTE EPV: create remote entry point vectors (EPVs). */
static void sidlx_rmi_TimeoutException__init_remote_epv(void)
{
  /* assert( HAVE_LOCKED_STATIC_GLOBALS ); */
  struct sidlx_rmi_TimeoutException__epv*     epv = 
    &s_rem_epv__sidlx_rmi_timeoutexception;
  struct sidl_BaseClass__epv*                 e0  = &s_rem_epv__sidl_baseclass;
  struct sidl_BaseException__epv*             e1  = 
    &s_rem_epv__sidl_baseexception;
  struct sidl_BaseInterface__epv*             e2  = 
    &s_rem_epv__sidl_baseinterface;
  struct sidl_RuntimeException__epv*          e3  = 
    &s_rem_epv__sidl_runtimeexception;
  struct sidl_SIDLException__epv*             e4  = 
    &s_rem_epv__sidl_sidlexception;
  struct sidl_io_IOException__epv*            e5  = 
    &s_rem_epv__sidl_io_ioexception;
  struct sidl_io_Serializable__epv*           e6  = 
    &s_rem_epv__sidl_io_serializable;
  struct sidl_rmi_NetworkException__epv*      e7  = 
    &s_rem_epv__sidl_rmi_networkexception;
  struct sidl_rmi_ProtocolException__epv*     e8  = 
    &s_rem_epv__sidl_rmi_protocolexception;
  struct sidlx_rmi_RecoverableException__epv* e9  = 
    &s_rem_epv__sidlx_rmi_recoverableexception;

  epv->f__cast               = remote_sidlx_rmi_TimeoutException__cast;
  epv->f__delete             = remote_sidlx_rmi_TimeoutException__delete;
  epv->f__exec               = remote_sidlx_rmi_TimeoutException__exec;
  epv->f__getURL             = remote_sidlx_rmi_TimeoutException__getURL;
  epv->f__raddRef            = remote_sidlx_rmi_TimeoutException__raddRef;
  epv->f__isRemote           = remote_sidlx_rmi_TimeoutException__isRemote;
  epv->f__set_hooks          = remote_sidlx_rmi_TimeoutException__set_hooks;
  epv->f__set_contracts      = remote_sidlx_rmi_TimeoutException__set_contracts;
  epv->f__dump_stats         = remote_sidlx_rmi_TimeoutException__dump_stats;
  epv->f__ctor               = NULL;
  epv->f__ctor2              = NULL;
  epv->f__dtor               = NULL;
  epv->f_getHopCount         = remote_sidlx_rmi_TimeoutException_getHopCount;
  epv->f_setErrno            = remote_sidlx_rmi_TimeoutException_setErrno;
  epv->f_getErrno            = remote_sidlx_rmi_TimeoutException_getErrno;
  epv->f_addRef              = remote_sidlx_rmi_TimeoutException_addRef;
  epv->f_deleteRef           = remote_sidlx_rmi_TimeoutException_deleteRef;
  epv->f_isSame              = remote_sidlx_rmi_TimeoutException_isSame;
  epv->f_isType              = remote_sidlx_rmi_TimeoutException_isType;
  epv->f_getClassInfo        = remote_sidlx_rmi_TimeoutException_getClassInfo;
  epv->f_getNote             = remote_sidlx_rmi_TimeoutException_getNote;
  epv->f_setNote             = remote_sidlx_rmi_TimeoutException_setNote;
  epv->f_getTrace            = remote_sidlx_rmi_TimeoutException_getTrace;
  epv->f_addLine             = remote_sidlx_rmi_TimeoutException_addLine;
  epv->f_add                 = remote_sidlx_rmi_TimeoutException_add;
  epv->f_packObj             = remote_sidlx_rmi_TimeoutException_packObj;
  epv->f_unpackObj           = remote_sidlx_rmi_TimeoutException_unpackObj;

  e0->f__cast          = (void* (*)(struct sidl_BaseClass__object*, const char*,
    struct sidl_BaseInterface__object**)) epv->f__cast;
  e0->f__delete        = (void (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e0->f__getURL        = (char* (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e0->f__raddRef       = (void (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e0->f__isRemote      = (sidl_bool (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e0->f__set_hooks     = (void (*)(struct sidl_BaseClass__object*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_hooks;
  e0->f__set_contracts = (void (*)(struct sidl_BaseClass__object*, sidl_bool, 
    const char*, sidl_bool, struct sidl_BaseInterface__object**)) 
    epv->f__set_contracts;
  e0->f__dump_stats    = (void (*)(struct sidl_BaseClass__object*, const char*, 
    const char*, struct sidl_BaseInterface__object**)) epv->f__dump_stats;
  e0->f__exec          = (void (*)(struct sidl_BaseClass__object*,const char*,
    struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e0->f_addRef         = (void (*)(struct sidl_BaseClass__object*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e0->f_deleteRef      = (void (*)(struct sidl_BaseClass__object*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e0->f_isSame         = (sidl_bool (*)(struct sidl_BaseClass__object*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e0->f_isType         = (sidl_bool (*)(struct sidl_BaseClass__object*,const 
    char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e0->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_BaseClass__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;

  e1->f__cast          = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e1->f__delete        = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__delete;
  e1->f__getURL        = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e1->f__raddRef       = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__raddRef;
  e1->f__isRemote      = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e1->f__set_hooks     = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e1->f__set_contracts = (void (*)(void*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e1->f__dump_stats    = (void (*)(void*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e1->f__exec          = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e1->f_getNote        = (char* (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_getNote;
  e1->f_setNote        = (void (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_setNote;
  e1->f_getTrace       = (char* (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_getTrace;
  e1->f_addLine        = (void (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_addLine;
  e1->f_add            = (void (*)(void*,const char*,int32_t,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_add;
  e1->f_packObj        = (void (*)(void*,struct sidl_io_Serializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_packObj;
  e1->f_unpackObj      = (void (*)(void*,struct sidl_io_Deserializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e1->f_addRef         = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_addRef;
  e1->f_deleteRef      = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_deleteRef;
  e1->f_isSame         = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e1->f_isType         = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e1->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e2->f__cast          = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e2->f__delete        = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__delete;
  e2->f__getURL        = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e2->f__raddRef       = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__raddRef;
  e2->f__isRemote      = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e2->f__set_hooks     = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e2->f__set_contracts = (void (*)(void*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e2->f__dump_stats    = (void (*)(void*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e2->f__exec          = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e2->f_addRef         = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_addRef;
  e2->f_deleteRef      = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_deleteRef;
  e2->f_isSame         = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e2->f_isType         = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e2->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e3->f__cast          = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e3->f__delete        = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__delete;
  e3->f__getURL        = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e3->f__raddRef       = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__raddRef;
  e3->f__isRemote      = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e3->f__set_hooks     = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e3->f__set_contracts = (void (*)(void*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e3->f__dump_stats    = (void (*)(void*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e3->f__exec          = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e3->f_getNote        = (char* (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_getNote;
  e3->f_setNote        = (void (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_setNote;
  e3->f_getTrace       = (char* (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_getTrace;
  e3->f_addLine        = (void (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_addLine;
  e3->f_add            = (void (*)(void*,const char*,int32_t,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_add;
  e3->f_packObj        = (void (*)(void*,struct sidl_io_Serializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_packObj;
  e3->f_unpackObj      = (void (*)(void*,struct sidl_io_Deserializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e3->f_addRef         = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_addRef;
  e3->f_deleteRef      = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_deleteRef;
  e3->f_isSame         = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e3->f_isType         = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e3->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e4->f__cast          = (void* (*)(struct sidl_SIDLException__object*, const 
    char*, struct sidl_BaseInterface__object**)) epv->f__cast;
  e4->f__delete        = (void (*)(struct sidl_SIDLException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e4->f__getURL        = (char* (*)(struct sidl_SIDLException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e4->f__raddRef       = (void (*)(struct sidl_SIDLException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e4->f__isRemote      = (sidl_bool (*)(struct sidl_SIDLException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__isRemote;
  e4->f__set_hooks     = (void (*)(struct sidl_SIDLException__object*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_hooks;
  e4->f__set_contracts = (void (*)(struct sidl_SIDLException__object*, 
    sidl_bool, const char*, sidl_bool, struct sidl_BaseInterface__object**)) 
    epv->f__set_contracts;
  e4->f__dump_stats    = (void (*)(struct sidl_SIDLException__object*, const 
    char*, const char*, struct sidl_BaseInterface__object**)) 
    epv->f__dump_stats;
  e4->f__exec          = (void (*)(struct sidl_SIDLException__object*,const 
    char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e4->f_addRef         = (void (*)(struct sidl_SIDLException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e4->f_deleteRef      = (void (*)(struct sidl_SIDLException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e4->f_isSame         = (sidl_bool (*)(struct sidl_SIDLException__object*,
    struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e4->f_isType         = (sidl_bool (*)(struct sidl_SIDLException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e4->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;
  e4->f_getNote        = (char* (*)(struct sidl_SIDLException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_getNote;
  e4->f_setNote        = (void (*)(struct sidl_SIDLException__object*,const 
    char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e4->f_getTrace       = (char* (*)(struct sidl_SIDLException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_getTrace;
  e4->f_addLine        = (void (*)(struct sidl_SIDLException__object*,const 
    char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e4->f_add            = (void (*)(struct sidl_SIDLException__object*,const 
    char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e4->f_packObj        = (void (*)(struct sidl_SIDLException__object*,struct 
    sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packObj;
  e4->f_unpackObj      = (void (*)(struct sidl_SIDLException__object*,struct 
    sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_unpackObj;

  e5->f__cast          = (void* (*)(struct sidl_io_IOException__object*, const 
    char*, struct sidl_BaseInterface__object**)) epv->f__cast;
  e5->f__delete        = (void (*)(struct sidl_io_IOException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e5->f__getURL        = (char* (*)(struct sidl_io_IOException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e5->f__raddRef       = (void (*)(struct sidl_io_IOException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e5->f__isRemote      = (sidl_bool (*)(struct sidl_io_IOException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__isRemote;
  e5->f__set_hooks     = (void (*)(struct sidl_io_IOException__object*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_hooks;
  e5->f__set_contracts = (void (*)(struct sidl_io_IOException__object*, 
    sidl_bool, const char*, sidl_bool, struct sidl_BaseInterface__object**)) 
    epv->f__set_contracts;
  e5->f__dump_stats    = (void (*)(struct sidl_io_IOException__object*, const 
    char*, const char*, struct sidl_BaseInterface__object**)) 
    epv->f__dump_stats;
  e5->f__exec          = (void (*)(struct sidl_io_IOException__object*,const 
    char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e5->f_addRef         = (void (*)(struct sidl_io_IOException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e5->f_deleteRef      = (void (*)(struct sidl_io_IOException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e5->f_isSame         = (sidl_bool (*)(struct sidl_io_IOException__object*,
    struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e5->f_isType         = (sidl_bool (*)(struct sidl_io_IOException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e5->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;
  e5->f_getNote        = (char* (*)(struct sidl_io_IOException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_getNote;
  e5->f_setNote        = (void (*)(struct sidl_io_IOException__object*,const 
    char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e5->f_getTrace       = (char* (*)(struct sidl_io_IOException__object*,struct 
    sidl_BaseInterface__object **)) epv->f_getTrace;
  e5->f_addLine        = (void (*)(struct sidl_io_IOException__object*,const 
    char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e5->f_add            = (void (*)(struct sidl_io_IOException__object*,const 
    char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e5->f_packObj        = (void (*)(struct sidl_io_IOException__object*,struct 
    sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packObj;
  e5->f_unpackObj      = (void (*)(struct sidl_io_IOException__object*,struct 
    sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_unpackObj;

  e6->f__cast          = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e6->f__delete        = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__delete;
  e6->f__getURL        = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e6->f__raddRef       = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__raddRef;
  e6->f__isRemote      = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e6->f__set_hooks     = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e6->f__set_contracts = (void (*)(void*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e6->f__dump_stats    = (void (*)(void*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e6->f__exec          = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e6->f_packObj        = (void (*)(void*,struct sidl_io_Serializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_packObj;
  e6->f_unpackObj      = (void (*)(void*,struct sidl_io_Deserializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e6->f_addRef         = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_addRef;
  e6->f_deleteRef      = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_deleteRef;
  e6->f_isSame         = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e6->f_isType         = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e6->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e7->f__cast          = (void* (*)(struct sidl_rmi_NetworkException__object*, 
    const char*, struct sidl_BaseInterface__object**)) epv->f__cast;
  e7->f__delete        = (void (*)(struct sidl_rmi_NetworkException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__delete;
  e7->f__getURL        = (char* (*)(struct sidl_rmi_NetworkException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__getURL;
  e7->f__raddRef       = (void (*)(struct sidl_rmi_NetworkException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__raddRef;
  e7->f__isRemote      = (sidl_bool (*)(struct 
    sidl_rmi_NetworkException__object*, struct sidl_BaseInterface__object**)) 
    epv->f__isRemote;
  e7->f__set_hooks     = (void (*)(struct sidl_rmi_NetworkException__object*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_hooks;
  e7->f__set_contracts = (void (*)(struct sidl_rmi_NetworkException__object*, 
    sidl_bool, const char*, sidl_bool, struct sidl_BaseInterface__object**)) 
    epv->f__set_contracts;
  e7->f__dump_stats    = (void (*)(struct sidl_rmi_NetworkException__object*, 
    const char*, const char*, struct sidl_BaseInterface__object**)) 
    epv->f__dump_stats;
  e7->f__exec          = (void (*)(struct sidl_rmi_NetworkException__object*,
    const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,
    struct sidl_BaseInterface__object **)) epv->f__exec;
  e7->f_getHopCount    = (int32_t (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getHopCount;
  e7->f_setErrno       = (void (*)(struct sidl_rmi_NetworkException__object*,
    int32_t,struct sidl_BaseInterface__object **)) epv->f_setErrno;
  e7->f_getErrno       = (int32_t (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getErrno;
  e7->f_addRef         = (void (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_addRef;
  e7->f_deleteRef      = (void (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e7->f_isSame         = (sidl_bool (*)(struct 
    sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object*,
    struct sidl_BaseInterface__object **)) epv->f_isSame;
  e7->f_isType         = (sidl_bool (*)(struct 
    sidl_rmi_NetworkException__object*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e7->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;
  e7->f_getNote        = (char* (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getNote;
  e7->f_setNote        = (void (*)(struct sidl_rmi_NetworkException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e7->f_getTrace       = (char* (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e7->f_addLine        = (void (*)(struct sidl_rmi_NetworkException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e7->f_add            = (void (*)(struct sidl_rmi_NetworkException__object*,
    const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) 
    epv->f_add;
  e7->f_packObj        = (void (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packObj;
  e7->f_unpackObj      = (void (*)(struct sidl_rmi_NetworkException__object*,
    struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_unpackObj;

  e8->f__cast          = (void* (*)(struct sidl_rmi_ProtocolException__object*, 
    const char*, struct sidl_BaseInterface__object**)) epv->f__cast;
  e8->f__delete        = (void (*)(struct sidl_rmi_ProtocolException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__delete;
  e8->f__getURL        = (char* (*)(struct sidl_rmi_ProtocolException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__getURL;
  e8->f__raddRef       = (void (*)(struct sidl_rmi_ProtocolException__object*, 
    struct sidl_BaseInterface__object**)) epv->f__raddRef;
  e8->f__isRemote      = (sidl_bool (*)(struct 
    sidl_rmi_ProtocolException__object*, struct sidl_BaseInterface__object**)) 
    epv->f__isRemote;
  e8->f__set_hooks     = (void (*)(struct sidl_rmi_ProtocolException__object*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_hooks;
  e8->f__set_contracts = (void (*)(struct sidl_rmi_ProtocolException__object*, 
    sidl_bool, const char*, sidl_bool, struct sidl_BaseInterface__object**)) 
    epv->f__set_contracts;
  e8->f__dump_stats    = (void (*)(struct sidl_rmi_ProtocolException__object*, 
    const char*, const char*, struct sidl_BaseInterface__object**)) 
    epv->f__dump_stats;
  e8->f__exec          = (void (*)(struct sidl_rmi_ProtocolException__object*,
    const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,
    struct sidl_BaseInterface__object **)) epv->f__exec;
  e8->f_getHopCount    = (int32_t (*)(struct 
    sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getHopCount;
  e8->f_setErrno       = (void (*)(struct sidl_rmi_ProtocolException__object*,
    int32_t,struct sidl_BaseInterface__object **)) epv->f_setErrno;
  e8->f_getErrno       = (int32_t (*)(struct 
    sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getErrno;
  e8->f_addRef         = (void (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_BaseInterface__object **)) epv->f_addRef;
  e8->f_deleteRef      = (void (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e8->f_isSame         = (sidl_bool (*)(struct 
    sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object*,
    struct sidl_BaseInterface__object **)) epv->f_isSame;
  e8->f_isType         = (sidl_bool (*)(struct 
    sidl_rmi_ProtocolException__object*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e8->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;
  e8->f_getNote        = (char* (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getNote;
  e8->f_setNote        = (void (*)(struct sidl_rmi_ProtocolException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e8->f_getTrace       = (char* (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e8->f_addLine        = (void (*)(struct sidl_rmi_ProtocolException__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e8->f_add            = (void (*)(struct sidl_rmi_ProtocolException__object*,
    const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) 
    epv->f_add;
  e8->f_packObj        = (void (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packObj;
  e8->f_unpackObj      = (void (*)(struct sidl_rmi_ProtocolException__object*,
    struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_unpackObj;

  e9->f__cast          = (void* (*)(struct 
    sidlx_rmi_RecoverableException__object*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e9->f__delete        = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e9->f__getURL        = (char* (*)(struct 
    sidlx_rmi_RecoverableException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e9->f__raddRef       = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e9->f__isRemote      = (sidl_bool (*)(struct 
    sidlx_rmi_RecoverableException__object*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e9->f__set_hooks     = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e9->f__set_contracts = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e9->f__dump_stats    = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e9->f__exec          = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e9->f_getHopCount    = (int32_t (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_getHopCount;
  e9->f_setErrno       = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,int32_t,struct 
    sidl_BaseInterface__object **)) epv->f_setErrno;
  e9->f_getErrno       = (int32_t (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_getErrno;
  e9->f_addRef         = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e9->f_deleteRef      = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e9->f_isSame         = (sidl_bool (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object*,
    struct sidl_BaseInterface__object **)) epv->f_isSame;
  e9->f_isType         = (sidl_bool (*)(struct 
    sidlx_rmi_RecoverableException__object*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e9->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_getClassInfo;
  e9->f_getNote        = (char* (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_getNote;
  e9->f_setNote        = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_setNote;
  e9->f_getTrace       = (char* (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object 
    **)) epv->f_getTrace;
  e9->f_addLine        = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_addLine;
  e9->f_add            = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,const char*,int32_t,const char*,
    struct sidl_BaseInterface__object **)) epv->f_add;
  e9->f_packObj        = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct sidl_io_Serializer__object*,
    struct sidl_BaseInterface__object **)) epv->f_packObj;
  e9->f_unpackObj      = (void (*)(struct 
    sidlx_rmi_RecoverableException__object*,struct 
    sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) 
    epv->f_unpackObj;

  s_remote_initialized = 1;
}

/* Create an instance that connects to an existing remote object. */
static struct sidlx_rmi_TimeoutException__object*
sidlx_rmi_TimeoutException__remoteConnect(const char *url, sidl_bool ar, struct 
  sidl_BaseInterface__object* *_ex)
{
  struct sidlx_rmi_TimeoutException__object* self = NULL;

  struct sidlx_rmi_TimeoutException__object* s0;
  struct sidlx_rmi_RecoverableException__object* s1;
  struct sidl_rmi_ProtocolException__object* s2;
  struct sidl_rmi_NetworkException__object* s3;
  struct sidl_io_IOException__object* s4;
  struct sidl_SIDLException__object* s5;
  struct sidl_BaseClass__object* s6;

  struct sidlx_rmi_TimeoutException__remote* r_obj = NULL;
  sidl_rmi_InstanceHandle instance = NULL;
  char* objectID = NULL;
  objectID = NULL;
  *_ex = NULL;
  if(url == NULL) {return NULL;}
  objectID = sidl_rmi_ServerRegistry_isLocalObject(url, _ex);
  if(objectID) {
    struct sidlx_rmi_TimeoutException__object* retobj = NULL;
    struct sidl_BaseInterface__object *throwaway_exception;
    sidl_BaseInterface bi = (
      sidl_BaseInterface)sidl_rmi_InstanceRegistry_getInstanceByString(objectID,
      _ex); SIDL_CHECK(*_ex);
    (*bi->d_epv->f_deleteRef)(bi->d_object, &throwaway_exception);
    retobj = (struct sidlx_rmi_TimeoutException__object*) (*bi->d_epv->f__cast)(
      bi->d_object, "sidlx.rmi.TimeoutException", _ex);
    if(!ar) { 
      (*bi->d_epv->f_deleteRef)(bi->d_object, &throwaway_exception);
    }
    return retobj;
  }
  instance = sidl_rmi_ProtocolFactory_connectInstance(url, 
    "sidlx.rmi.TimeoutException", ar, _ex ); SIDL_CHECK(*_ex);
  if ( instance == NULL) { return NULL; }
  self =
    (struct sidlx_rmi_TimeoutException__object*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__object));

  r_obj =
    (struct sidlx_rmi_TimeoutException__remote*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__remote));

  if(!self || !r_obj) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(
      _ex);
    SIDL_CHECK(*_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex); SIDL_CHECK(*_ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, 
      "sidlx.rmi.TimeoutException.EPVgeneration", _ex);
    SIDL_CHECK(*_ex);
    *_ex = (struct sidl_BaseInterface__object*)ex;
    goto EXIT;
  }

  r_obj->d_refcount = 1;
  r_obj->d_ih = instance;
  s0 =                                          self;
  s1 =                                          
    &s0->d_sidlx_rmi_recoverableexception;
  s2 =                                          
    &s1->d_sidl_rmi_protocolexception;
  s3 =                                          
    &s2->d_sidl_rmi_networkexception;
  s4 =                                          &s3->d_sidl_io_ioexception;
  s5 =                                          &s4->d_sidl_sidlexception;
  s6 =                                          &s5->d_sidl_baseclass;

  LOCK_STATIC_GLOBALS;
  if (!s_remote_initialized) {
    sidlx_rmi_TimeoutException__init_remote_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  s6->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
  s6->d_sidl_baseinterface.d_object = (void*) self;

  s6->d_data = (void*) r_obj;
  s6->d_epv  = &s_rem_epv__sidl_baseclass;

  s5->d_sidl_baseexception.d_epv    = &s_rem_epv__sidl_baseexception;
  s5->d_sidl_baseexception.d_object = (void*) self;

  s5->d_sidl_io_serializable.d_epv    = &s_rem_epv__sidl_io_serializable;
  s5->d_sidl_io_serializable.d_object = (void*) self;

  s5->d_data = (void*) r_obj;
  s5->d_epv  = &s_rem_epv__sidl_sidlexception;

  s4->d_sidl_runtimeexception.d_epv    = &s_rem_epv__sidl_runtimeexception;
  s4->d_sidl_runtimeexception.d_object = (void*) self;

  s4->d_data = (void*) r_obj;
  s4->d_epv  = &s_rem_epv__sidl_io_ioexception;

  s3->d_data = (void*) r_obj;
  s3->d_epv  = &s_rem_epv__sidl_rmi_networkexception;

  s2->d_data = (void*) r_obj;
  s2->d_epv  = &s_rem_epv__sidl_rmi_protocolexception;

  s1->d_data = (void*) r_obj;
  s1->d_epv  = &s_rem_epv__sidlx_rmi_recoverableexception;

  s0->d_data = (void*) r_obj;
  s0->d_epv  = &s_rem_epv__sidlx_rmi_timeoutexception;

  self->d_data = (void*) r_obj;

  return self;
  EXIT:
  if(self) { free(self); }
  if(r_obj) { free(r_obj); }
  return NULL;
}
/* Create an instance that uses an already existing  */
/* InstanceHandle to connect to an existing remote object. */
static VAR_UNUSED struct sidlx_rmi_TimeoutException__object*
sidlx_rmi_TimeoutException__IHConnect(sidl_rmi_InstanceHandle instance, struct 
  sidl_BaseInterface__object* *_ex)
{
  struct sidlx_rmi_TimeoutException__object* self = NULL;

  struct sidlx_rmi_TimeoutException__object* s0;
  struct sidlx_rmi_RecoverableException__object* s1;
  struct sidl_rmi_ProtocolException__object* s2;
  struct sidl_rmi_NetworkException__object* s3;
  struct sidl_io_IOException__object* s4;
  struct sidl_SIDLException__object* s5;
  struct sidl_BaseClass__object* s6;

  struct sidlx_rmi_TimeoutException__remote* r_obj = NULL;
  self =
    (struct sidlx_rmi_TimeoutException__object*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__object));

  r_obj =
    (struct sidlx_rmi_TimeoutException__remote*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__remote));

  if(!self || !r_obj) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(
      _ex);
    SIDL_CHECK(*_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex); SIDL_CHECK(*_ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, 
      "sidlx.rmi.TimeoutException.EPVgeneration", _ex);
    SIDL_CHECK(*_ex);
    *_ex = (struct sidl_BaseInterface__object*)ex;
    goto EXIT;
  }

  r_obj->d_refcount = 1;
  r_obj->d_ih = instance;
  s0 =                                          self;
  s1 =                                          
    &s0->d_sidlx_rmi_recoverableexception;
  s2 =                                          
    &s1->d_sidl_rmi_protocolexception;
  s3 =                                          
    &s2->d_sidl_rmi_networkexception;
  s4 =                                          &s3->d_sidl_io_ioexception;
  s5 =                                          &s4->d_sidl_sidlexception;
  s6 =                                          &s5->d_sidl_baseclass;

  LOCK_STATIC_GLOBALS;
  if (!s_remote_initialized) {
    sidlx_rmi_TimeoutException__init_remote_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  s6->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
  s6->d_sidl_baseinterface.d_object = (void*) self;

  s6->d_data = (void*) r_obj;
  s6->d_epv  = &s_rem_epv__sidl_baseclass;

  s5->d_sidl_baseexception.d_epv    = &s_rem_epv__sidl_baseexception;
  s5->d_sidl_baseexception.d_object = (void*) self;

  s5->d_sidl_io_serializable.d_epv    = &s_rem_epv__sidl_io_serializable;
  s5->d_sidl_io_serializable.d_object = (void*) self;

  s5->d_data = (void*) r_obj;
  s5->d_epv  = &s_rem_epv__sidl_sidlexception;

  s4->d_sidl_runtimeexception.d_epv    = &s_rem_epv__sidl_runtimeexception;
  s4->d_sidl_runtimeexception.d_object = (void*) self;

  s4->d_data = (void*) r_obj;
  s4->d_epv  = &s_rem_epv__sidl_io_ioexception;

  s3->d_data = (void*) r_obj;
  s3->d_epv  = &s_rem_epv__sidl_rmi_networkexception;

  s2->d_data = (void*) r_obj;
  s2->d_epv  = &s_rem_epv__sidl_rmi_protocolexception;

  s1->d_data = (void*) r_obj;
  s1->d_epv  = &s_rem_epv__sidlx_rmi_recoverableexception;

  s0->d_data = (void*) r_obj;
  s0->d_epv  = &s_rem_epv__sidlx_rmi_timeoutexception;

  self->d_data = (void*) r_obj;

  sidl_rmi_InstanceHandle_addRef(instance,_ex);SIDL_CHECK(*_ex);
  return self;
  EXIT:
  if(self) { free(self); }
  if(r_obj) { free(r_obj); }
  return NULL;
}
/* REMOTE: generate remote instance given URL string. */
static struct sidlx_rmi_TimeoutException__object*
sidlx_rmi_TimeoutException__remoteCreate(const char *url, struct 
  sidl_BaseInterface__object **_ex)
{
  struct sidl_BaseInterface__object* _throwaway_exception = NULL;
  struct sidlx_rmi_TimeoutException__object* self = NULL;

  struct sidlx_rmi_TimeoutException__object* s0;
  struct sidlx_rmi_RecoverableException__object* s1;
  struct sidl_rmi_ProtocolException__object* s2;
  struct sidl_rmi_NetworkException__object* s3;
  struct sidl_io_IOException__object* s4;
  struct sidl_SIDLException__object* s5;
  struct sidl_BaseClass__object* s6;

  struct sidlx_rmi_TimeoutException__remote* r_obj = NULL;
  sidl_rmi_InstanceHandle instance = sidl_rmi_ProtocolFactory_createInstance(
    url, "sidlx.rmi.TimeoutException", _ex ); SIDL_CHECK(*_ex);
  if ( instance == NULL) { return NULL; }
  self =
    (struct sidlx_rmi_TimeoutException__object*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__object));

  r_obj =
    (struct sidlx_rmi_TimeoutException__remote*) malloc(
      sizeof(struct sidlx_rmi_TimeoutException__remote));

  if(!self || !r_obj) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(
      _ex);
    SIDL_CHECK(*_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex); SIDL_CHECK(*_ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, 
      "sidlx.rmi.TimeoutException.EPVgeneration", _ex);
    SIDL_CHECK(*_ex);
    *_ex = (struct sidl_BaseInterface__object*)ex;
    goto EXIT;
  }

  r_obj->d_refcount = 1;
  r_obj->d_ih = instance;
  s0 =                                          self;
  s1 =                                          
    &s0->d_sidlx_rmi_recoverableexception;
  s2 =                                          
    &s1->d_sidl_rmi_protocolexception;
  s3 =                                          
    &s2->d_sidl_rmi_networkexception;
  s4 =                                          &s3->d_sidl_io_ioexception;
  s5 =                                          &s4->d_sidl_sidlexception;
  s6 =                                          &s5->d_sidl_baseclass;

  LOCK_STATIC_GLOBALS;
  if (!s_remote_initialized) {
    sidlx_rmi_TimeoutException__init_remote_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  s6->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
  s6->d_sidl_baseinterface.d_object = (void*) self;

  s6->d_data = (void*) r_obj;
  s6->d_epv  = &s_rem_epv__sidl_baseclass;

  s5->d_sidl_baseexception.d_epv    = &s_rem_epv__sidl_baseexception;
  s5->d_sidl_baseexception.d_object = (void*) self;

  s5->d_sidl_io_serializable.d_epv    = &s_rem_epv__sidl_io_serializable;
  s5->d_sidl_io_serializable.d_object = (void*) self;

  s5->d_data = (void*) r_obj;
  s5->d_epv  = &s_rem_epv__sidl_sidlexception;

  s4->d_sidl_runtimeexception.d_epv    = &s_rem_epv__sidl_runtimeexception;
  s4->d_sidl_runtimeexception.d_object = (void*) self;

  s4->d_data = (void*) r_obj;
  s4->d_epv  = &s_rem_epv__sidl_io_ioexception;

  s3->d_data = (void*) r_obj;
  s3->d_epv  = &s_rem_epv__sidl_rmi_networkexception;

  s2->d_data = (void*) r_obj;
  s2->d_epv  = &s_rem_epv__sidl_rmi_protocolexception;

  s1->d_data = (void*) r_obj;
  s1->d_epv  = &s_rem_epv__sidlx_rmi_recoverableexception;

  s0->d_data = (void*) r_obj;
  s0->d_epv  = &s_rem_epv__sidlx_rmi_timeoutexception;

  self->d_data = (void*) r_obj;

  return self;
  EXIT:
  if(instance) { sidl_rmi_InstanceHandle_deleteRef(instance, 
    &_throwaway_exception); }
  if(self) { free(self); }
  if(r_obj) { free(r_obj); }
  return NULL;
}
/*
 * RMI connector function for the class.
 */

struct sidlx_rmi_TimeoutException__object*
sidlx_rmi_TimeoutException__connectI(const char* url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex)
{
  return sidlx_rmi_TimeoutException__remoteConnect(url, ar, _ex);
}


#endif /*WITH_RMI*/
