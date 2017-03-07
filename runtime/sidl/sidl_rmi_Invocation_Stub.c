/*
 * File:          sidl_rmi_Invocation_Stub.c
 * Symbol:        sidl.rmi.Invocation-v0.9.17
 * Symbol Type:   interface
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Client-side glue code for sidl.rmi.Invocation
 * 
 * Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#define SIDL_RMI_INVOCATION_INLINE_DECL
#include "sidl_rmi_Invocation.h"
#include "sidl_rmi_Invocation_IOR.h"
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

#define LANG_SPECIFIC_INIT()

#ifdef WITH_RMI

static struct sidl_rmi_Invocation__object* sidl_rmi_Invocation__remoteConnect(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
static struct sidl_rmi_Invocation__object* sidl_rmi_Invocation__IHConnect(
  struct sidl_rmi_InstanceHandle__object* instance, sidl_BaseInterface *_ex);
/*
 * RMI connector function for the class.
 */

sidl_rmi_Invocation
sidl_rmi_Invocation__connect(const char* url, sidl_BaseInterface *_ex)
{
  return sidl_rmi_Invocation__remoteConnect(url, TRUE, _ex);
}

#endif /*WITH_RMI*/

/*
 * Cast method for interface and class type conversions.
 */

sidl_rmi_Invocation
sidl_rmi_Invocation__cast(
  void* obj,
  sidl_BaseInterface* _ex)
{
  sidl_rmi_Invocation cast = NULL;

#ifdef WITH_RMI
  static int connect_loaded = 0;
  if (!connect_loaded) {
    connect_loaded = 1;
    sidl_rmi_ConnectRegistry_registerConnect("sidl.rmi.Invocation", (
      void*)sidl_rmi_Invocation__IHConnect,_ex);SIDL_CHECK(*_ex);
  }
#endif /*WITH_RMI*/
  if (obj != NULL) {
    sidl_BaseInterface base = (sidl_BaseInterface) obj;
    cast = (sidl_rmi_Invocation) (*base->d_epv->f__cast)(
      base->d_object,
      "sidl.rmi.Invocation", _ex); SIDL_CHECK(*_ex);
  }

  EXIT:
  return cast;
}

/*
 * String cast method for interface and class type conversions.
 */

void*
sidl_rmi_Invocation__cast2(
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
sidl_rmi_Invocation__isLocal(
  /* in */ sidl_rmi_Invocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  return !sidl_rmi_Invocation__isRemote(self, _ex);
}

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in column-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[])
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_createCol(
    dimen, lower, upper);
}

/**
 * Create a contiguous array of the given dimension with specified
 * index bounds in row-major order. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[])
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_createRow(
    dimen, lower, upper);
}

/**
 * Create a contiguous one-dimensional array with a lower index
 * of 0 and an upper index of len-1. This array
 * owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_create1d(int32_t len)
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_create1d(
    len);
}

/**
 * Create a dense one-dimensional vector with a lower
 * index of 0 and an upper index of len-1. The initial data for this
 * new array is copied from data. This will increment the reference
 * count of each non-NULL object/interface reference in data.
 * 
 * This array owns and manages its data.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_create1dInit(
  int32_t len, 
  sidl_rmi_Invocation* data)
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_create1dInit(
    len, (struct sidl_BaseInterface__object **)data);
}

/**
 * Create a contiguous two-dimensional array in column-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_create2dCol(int32_t m, int32_t n)
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_create2dCol(
    m, n);
}

/**
 * Create a contiguous two-dimensional array in row-major
 * order with a lower index of (0,0) and an upper index of
 * (m-1,n-1). This array owns and manages its data.
 * This function initializes the contents of the array to
 * NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_create2dRow(int32_t m, int32_t n)
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_create2dRow(
    m, n);
}

/**
 * Create an array that uses data (memory) from another
 * source. The initial contents are determined by the
 * data being borrowed.
 * Any time an element in the borrowed array is replaced
 * via a set call, deleteRef will be called on the
 * value being replaced if it is not NULL.
 */
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_borrow(
  sidl_rmi_Invocation* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[])
{
  return (struct sidl_rmi_Invocation__array*)sidl_interface__array_borrow(
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
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_smartCopy(
  struct sidl_rmi_Invocation__array *array)
{
  return (struct sidl_rmi_Invocation__array*)
    sidl_interface__array_smartCopy((struct sidl_interface__array *)array);
}

/**
 * Increment the array's internal reference count by one.
 */
void
sidl_rmi_Invocation__array_addRef(
  struct sidl_rmi_Invocation__array* array)
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
sidl_rmi_Invocation__array_deleteRef(
  struct sidl_rmi_Invocation__array* array)
{
  sidl_interface__array_deleteRef((struct sidl_interface__array *)array);
}

/**
 * Retrieve element i1 of a(n) 1-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get1(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get1((const struct sidl_interface__array *)array
    , i1);
}

/**
 * Retrieve element (i1,i2) of a(n) 2-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get2(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get2((const struct sidl_interface__array *)array
    , i1, i2);
}

/**
 * Retrieve element (i1,i2,i3) of a(n) 3-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get3(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get3((const struct sidl_interface__array *)array
    , i1, i2, i3);
}

/**
 * Retrieve element (i1,i2,i3,i4) of a(n) 4-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get4(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get4((const struct sidl_interface__array *)array
    , i1, i2, i3, i4);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get5(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get5((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get6(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get6((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5, i6);
}

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get7(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7)
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get7((const struct sidl_interface__array *)array
    , i1, i2, i3, i4, i5, i6, i7);
}

/**
 * Retrieve element indices of an n-dimensional array.
 * indices is assumed to have the right number of elements
 * for the dimension of array.
 */
sidl_rmi_Invocation
sidl_rmi_Invocation__array_get(
  const struct sidl_rmi_Invocation__array* array,
  const int32_t indices[])
{
  return (sidl_rmi_Invocation)
    sidl_interface__array_get((const struct sidl_interface__array *)array, 
      indices);
}

/**
 * Set element i1 of a(n) 1-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set1(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set1((struct sidl_interface__array *)array
  , i1, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2) of a(n) 2-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set2(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set2((struct sidl_interface__array *)array
  , i1, i2, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3) of a(n) 3-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set3(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set3((struct sidl_interface__array *)array
  , i1, i2, i3, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4) of a(n) 4-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set4(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set4((struct sidl_interface__array *)array
  , i1, i2, i3, i4, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5) of a(n) 5-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set5(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set5((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5,i6) of a(n) 6-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set6(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set6((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, i6, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element (i1,i2,i3,i4,i5,i6,i7) of a(n) 7-dimensional array to value.
 */
void
sidl_rmi_Invocation__array_set7(
  struct sidl_rmi_Invocation__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set7((struct sidl_interface__array *)array
  , i1, i2, i3, i4, i5, i6, i7, (struct sidl_BaseInterface__object *)value);
}

/**
 * Set element indices of an n-dimensional array to value.indices is assumed to have the right number of elements
 * for the dimension of array.
 */
void
sidl_rmi_Invocation__array_set(
  struct sidl_rmi_Invocation__array* array,
  const int32_t indices[],
  sidl_rmi_Invocation const value)
{
  sidl_interface__array_set((struct sidl_interface__array *)array, indices, (
    struct sidl_BaseInterface__object *)value);
}

/**
 * Return the dimension of array. If the array pointer is
 * NULL, zero is returned.
 */
int32_t
sidl_rmi_Invocation__array_dimen(
  const struct sidl_rmi_Invocation__array* array)
{
  return sidl_interface__array_dimen((struct sidl_interface__array *)array);
}

/**
 * Return the lower bound of dimension ind.
 * If ind is not a valid dimension, 0 is returned.
 * The valid range for ind is from 0 to dimen-1.
 */
int32_t
sidl_rmi_Invocation__array_lower(
  const struct sidl_rmi_Invocation__array* array,
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
sidl_rmi_Invocation__array_upper(
  const struct sidl_rmi_Invocation__array* array,
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
sidl_rmi_Invocation__array_length(
  const struct sidl_rmi_Invocation__array* array,
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
sidl_rmi_Invocation__array_stride(
  const struct sidl_rmi_Invocation__array* array,
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
sidl_rmi_Invocation__array_isColumnOrder(
  const struct sidl_rmi_Invocation__array* array)
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
sidl_rmi_Invocation__array_isRowOrder(
  const struct sidl_rmi_Invocation__array* array)
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
sidl_rmi_Invocation__array_copy(
  const struct sidl_rmi_Invocation__array* src,
  struct sidl_rmi_Invocation__array* dest)
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
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_slice(
  struct sidl_rmi_Invocation__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart)
{
  return (struct sidl_rmi_Invocation__array*)
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
struct sidl_rmi_Invocation__array*
sidl_rmi_Invocation__array_ensure(
  struct sidl_rmi_Invocation__array* src,
  int32_t dimen,
  int     ordering)
{
  return (struct sidl_rmi_Invocation__array*)
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
static struct sidl_recursive_mutex_t sidl_rmi__Invocation__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &sidl_rmi__Invocation__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &sidl_rmi__Invocation__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &sidl_rmi__Invocation__mutex )==EDEADLOCK) */
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

static struct sidl_rmi__Invocation__epv s_rem_epv__sidl_rmi__invocation;

static struct sidl_BaseInterface__epv s_rem_epv__sidl_baseinterface;

static struct sidl_io_Serializer__epv s_rem_epv__sidl_io_serializer;

static struct sidl_rmi_Invocation__epv s_rem_epv__sidl_rmi_invocation;


/* REMOTE CAST: dynamic type casting for remote objects. */
static void* remote_sidl_rmi__Invocation__cast(
  struct sidl_rmi__Invocation__object* self,
  const char* name, sidl_BaseInterface* _ex)
{
  int cmp;
  void* cast = NULL;
  *_ex = NULL; /* default to no exception */
  cmp = strcmp(name, "sidl.rmi.Invocation");
  if (!cmp) {
    (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
    cast = &((*self).d_sidl_rmi_invocation);
    return cast;
  }
  else if (cmp < 0) {
    cmp = strcmp(name, "sidl.io.Serializer");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = &((*self).d_sidl_io_serializer);
      return cast;
    }
    else if (cmp < 0) {
      cmp = strcmp(name, "sidl.BaseInterface");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_sidl_baseinterface);
        return cast;
      }
    }
  }
  else if (cmp > 0) {
    cmp = strcmp(name, "sidl.rmi._Invocation");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = ((struct sidl_rmi__Invocation__object*)self);
      return cast;
    }
  }
  if ((*self->d_epv->f_isType)(self,name, _ex)) {
    void* (*func)(struct sidl_rmi_InstanceHandle__object*, struct 
      sidl_BaseInterface__object**) = 
      (void* (*)(struct sidl_rmi_InstanceHandle__object*, struct 
        sidl_BaseInterface__object**)) 
      sidl_rmi_ConnectRegistry_getConnect(name, _ex);SIDL_CHECK(*_ex);
    cast =  (*func)(((struct sidl_rmi__Invocation__remote*)self->d_data)->d_ih, 
      _ex);
  }

  return cast;
  EXIT:
  return NULL;
}

/* REMOTE DELETE: call the remote destructor for the object. */
static void remote_sidl_rmi__Invocation__delete(
  struct sidl_rmi__Invocation__object* self,
  struct sidl_BaseInterface__object* *_ex)
{
  *_ex = NULL;
  free((void*) self);
}

/* REMOTE GETURL: call the getURL function for the object. */
static char* remote_sidl_rmi__Invocation__getURL(
  struct sidl_rmi__Invocation__object* self, struct sidl_BaseInterface__object* 
    *_ex)
{
  struct sidl_rmi_InstanceHandle__object *conn = ((struct 
    sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
  *_ex = NULL;
  if(conn != NULL) {
    return sidl_rmi_InstanceHandle_getObjectURL(conn, _ex);
  }
  return NULL;
}

/* REMOTE ADDREF: For internal babel use only! Remote addRef. */
static void remote_sidl_rmi__Invocation__raddRef(
  struct sidl_rmi__Invocation__object* self,struct sidl_BaseInterface__object* 
    *_ex)
{
  struct sidl_BaseException__object* netex = NULL;
  /* initialize a new invocation */
  struct sidl_BaseInterface__object* _throwaway = NULL;
  struct sidl_rmi_InstanceHandle__object *_conn = ((struct 
    sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
remote_sidl_rmi__Invocation__isRemote(
    struct sidl_rmi__Invocation__object* self, 
    struct sidl_BaseInterface__object* *_ex) {
  *_ex = NULL;
  return TRUE;
}

/* REMOTE METHOD STUB:_set_hooks */
static void
remote_sidl_rmi__Invocation__set_hooks(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
      "Exception unserialized from sidl.rmi._Invocation._set_hooks.",
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
remote_sidl_rmi__Invocation__set_contracts(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
      "Exception unserialized from sidl.rmi._Invocation._set_contracts.",
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
remote_sidl_rmi__Invocation__dump_stats(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
      "Exception unserialized from sidl.rmi._Invocation._dump_stats.",
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
static void remote_sidl_rmi__Invocation__exec(
  struct sidl_rmi__Invocation__object* self,const char* methodName,
  sidl_rmi_Call inArgs,
  sidl_rmi_Return outArgs,
  struct sidl_BaseInterface__object* *_ex)
{
  *_ex = NULL;
}

/* REMOTE METHOD STUB:invokeMethod */
static struct sidl_rmi_Response__object*
remote_sidl_rmi__Invocation_invokeMethod(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
    struct sidl_rmi_Response__object* _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "invokeMethod", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.invokeMethod.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval_str, 
      _ex);SIDL_CHECK(*_ex);
    _retval = sidl_rmi_Response__connectI(_retval_str, FALSE, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:invokeNonblocking */
static struct sidl_rmi_Ticket__object*
remote_sidl_rmi__Invocation_invokeNonblocking(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
    struct sidl_rmi_Ticket__object* _retval = 0;
    struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "invokeNonblocking", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.invokeNonblocking.",
        &throwaway_exception);
      *_ex = (struct sidl_BaseInterface__object*) sidl_BaseInterface__cast(_be,
        &throwaway_exception);
      goto EXIT;
    }

    /* extract return value */
    sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval_str, 
      _ex);SIDL_CHECK(*_ex);
    _retval = sidl_rmi_Ticket__connectI(_retval_str, FALSE, _ex);SIDL_CHECK(
      *_ex);

    /* unpack out and inout arguments */

    /* cleanup and return */
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
    return _retval;
  }
}

/* REMOTE METHOD STUB:invokeOneWay */
static void
remote_sidl_rmi__Invocation_invokeOneWay(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "invokeOneWay", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.invokeOneWay.",
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

/* REMOTE METHOD STUB:packBool */
static void
remote_sidl_rmi__Invocation_packBool(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ sidl_bool value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packBool", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packBool.",
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

/* REMOTE METHOD STUB:packChar */
static void
remote_sidl_rmi__Invocation_packChar(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ char value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packChar", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packChar( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packChar.",
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

/* REMOTE METHOD STUB:packInt */
static void
remote_sidl_rmi__Invocation_packInt(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ int32_t value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packInt", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packInt.",
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

/* REMOTE METHOD STUB:packLong */
static void
remote_sidl_rmi__Invocation_packLong(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ int64_t value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packLong", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packLong( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packLong.",
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

/* REMOTE METHOD STUB:packOpaque */
static void
remote_sidl_rmi__Invocation_packOpaque(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ void* value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packOpaque", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packOpaque( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packOpaque.",
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

/* REMOTE METHOD STUB:packFloat */
static void
remote_sidl_rmi__Invocation_packFloat(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ float value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packFloat", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packFloat( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packFloat.",
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

/* REMOTE METHOD STUB:packDouble */
static void
remote_sidl_rmi__Invocation_packDouble(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ double value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packDouble", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packDouble( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packDouble.",
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

/* REMOTE METHOD STUB:packFcomplex */
static void
remote_sidl_rmi__Invocation_packFcomplex(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ struct sidl_fcomplex value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packFcomplex", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packFcomplex( _inv, "value", value, _ex);SIDL_CHECK(
      *_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packFcomplex.",
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

/* REMOTE METHOD STUB:packDcomplex */
static void
remote_sidl_rmi__Invocation_packDcomplex(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ struct sidl_dcomplex value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packDcomplex", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packDcomplex( _inv, "value", value, _ex);SIDL_CHECK(
      *_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packDcomplex.",
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

/* REMOTE METHOD STUB:packString */
static void
remote_sidl_rmi__Invocation_packString(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ const char* value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packString", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packString( _inv, "value", value, _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packString.",
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

/* REMOTE METHOD STUB:packSerializable */
static void
remote_sidl_rmi__Invocation_packSerializable(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in */ struct sidl_io_Serializable__object* value,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packSerializable", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    if(value){
      char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)value, 
        _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packString( _inv, "value", _url, _ex);SIDL_CHECK(
        *_ex);
      free((void*)_url);
    } else {
      sidl_rmi_Invocation_packString( _inv, "value", NULL, _ex);SIDL_CHECK(
        *_ex);
    }

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packSerializable.",
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

/* REMOTE METHOD STUB:packBoolArray */
static void
remote_sidl_rmi__Invocation_packBoolArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<bool> */ struct sidl_bool__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packBoolArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBoolArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packBoolArray.",
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

/* REMOTE METHOD STUB:packCharArray */
static void
remote_sidl_rmi__Invocation_packCharArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<char> */ struct sidl_char__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packCharArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packCharArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packCharArray.",
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

/* REMOTE METHOD STUB:packIntArray */
static void
remote_sidl_rmi__Invocation_packIntArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<int> */ struct sidl_int__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packIntArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packIntArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packIntArray.",
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

/* REMOTE METHOD STUB:packLongArray */
static void
remote_sidl_rmi__Invocation_packLongArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<long> */ struct sidl_long__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packLongArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packLongArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packLongArray.",
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

/* REMOTE METHOD STUB:packOpaqueArray */
static void
remote_sidl_rmi__Invocation_packOpaqueArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<opaque> */ struct sidl_opaque__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packOpaqueArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packOpaqueArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packOpaqueArray.",
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

/* REMOTE METHOD STUB:packFloatArray */
static void
remote_sidl_rmi__Invocation_packFloatArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<float> */ struct sidl_float__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packFloatArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packFloatArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packFloatArray.",
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

/* REMOTE METHOD STUB:packDoubleArray */
static void
remote_sidl_rmi__Invocation_packDoubleArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<double> */ struct sidl_double__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packDoubleArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packDoubleArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packDoubleArray.",
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

/* REMOTE METHOD STUB:packFcomplexArray */
static void
remote_sidl_rmi__Invocation_packFcomplexArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packFcomplexArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packFcomplexArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packFcomplexArray.",
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

/* REMOTE METHOD STUB:packDcomplexArray */
static void
remote_sidl_rmi__Invocation_packDcomplexArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packDcomplexArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packDcomplexArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packDcomplexArray.",
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

/* REMOTE METHOD STUB:packStringArray */
static void
remote_sidl_rmi__Invocation_packStringArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<string> */ struct sidl_string__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packStringArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packStringArray( _inv, "value",value,0,0,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packStringArray.",
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

/* REMOTE METHOD STUB:packGenericArray */
static void
remote_sidl_rmi__Invocation_packGenericArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<> */ struct sidl__array* value,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packGenericArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packGenericArray( _inv, "value",value,0, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packGenericArray.",
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

/* REMOTE METHOD STUB:packSerializableArray */
static void
remote_sidl_rmi__Invocation_packSerializableArray(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* in */ const char* key,
  /* in array<sidl.io.Serializable> */ struct sidl_io_Serializable__array* 
    value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "packSerializableArray", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */
    sidl_rmi_Invocation_packString( _inv, "key", key, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packSerializableArray( _inv, "value",(struct 
      sidl_io_Serializable__array*)value,0,0,0, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packInt( _inv, "ordering", ordering, _ex);SIDL_CHECK(
      *_ex);
    sidl_rmi_Invocation_packInt( _inv, "dimen", dimen, _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Invocation_packBool( _inv, "reuse_array", reuse_array, 
      _ex);SIDL_CHECK(*_ex);

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.packSerializableArray.",
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

/* REMOTE METHOD STUB:addRef */
static void
remote_sidl_rmi__Invocation_addRef(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    struct sidl_rmi__Invocation__remote* r_obj = (struct 
      sidl_rmi__Invocation__remote*)self->d_data;
    LOCK_STATIC_GLOBALS;
    r_obj->d_refcount++;
#ifdef SIDL_DEBUG_REFCOUNT
    fprintf(stderr, "babel: addRef %p new count %d (type %s)\n",
      r_obj, r_obj->d_refcount, 
      "sidl.rmi._Invocation Remote Stub");
#endif /* SIDL_DEBUG_REFCOUNT */ 
    UNLOCK_STATIC_GLOBALS;
  }
}

/* REMOTE METHOD STUB:deleteRef */
static void
remote_sidl_rmi__Invocation_deleteRef(
  /* in */ struct sidl_rmi__Invocation__object*self ,
  /* out */ struct sidl_BaseInterface__object **_ex)
{
  LANG_SPECIFIC_INIT();
  *_ex = NULL;
  {
    struct sidl_rmi__Invocation__remote* r_obj = (struct 
      sidl_rmi__Invocation__remote*)self->d_data;
    LOCK_STATIC_GLOBALS;
    r_obj->d_refcount--;
#ifdef SIDL_DEBUG_REFCOUNT
    fprintf(stderr, "babel: deleteRef %p new count %d (type %s)\n",r_obj, r_obj->d_refcount, "sidl.rmi._Invocation Remote Stub");
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
remote_sidl_rmi__Invocation_isSame(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
      "Exception unserialized from sidl.rmi._Invocation.isSame.",
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
remote_sidl_rmi__Invocation_isType(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
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
      "Exception unserialized from sidl.rmi._Invocation.isType.",
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
remote_sidl_rmi__Invocation_getClassInfo(
  /* in */ struct sidl_rmi__Invocation__object*self ,
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
      sidl_rmi__Invocation__remote*)self->d_data)->d_ih;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "getClassInfo", _ex ); SIDL_CHECK(*_ex);

    /* pack in and inout arguments */

    /* send actual RMI request */
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

    _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
    if (_be != NULL) {
      struct sidl_BaseInterface__object* throwaway_exception = NULL;
      sidl_BaseException_addLine(_be, 
      "Exception unserialized from sidl.rmi._Invocation.getClassInfo.",
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

/* REMOTE EPV: create remote entry point vectors (EPVs). */
static void sidl_rmi__Invocation__init_remote_epv(void)
{
  /* assert( HAVE_LOCKED_STATIC_GLOBALS ); */
  struct sidl_rmi__Invocation__epv* epv = &s_rem_epv__sidl_rmi__invocation;
  struct sidl_BaseInterface__epv*   e0  = &s_rem_epv__sidl_baseinterface;
  struct sidl_io_Serializer__epv*   e1  = &s_rem_epv__sidl_io_serializer;
  struct sidl_rmi_Invocation__epv*  e2  = &s_rem_epv__sidl_rmi_invocation;

  epv->f__cast                      = remote_sidl_rmi__Invocation__cast;
  epv->f__delete                    = remote_sidl_rmi__Invocation__delete;
  epv->f__exec                      = remote_sidl_rmi__Invocation__exec;
  epv->f__getURL                    = remote_sidl_rmi__Invocation__getURL;
  epv->f__raddRef                   = remote_sidl_rmi__Invocation__raddRef;
  epv->f__isRemote                  = remote_sidl_rmi__Invocation__isRemote;
  epv->f__set_hooks                 = remote_sidl_rmi__Invocation__set_hooks;
  epv->f__set_contracts             = 
    remote_sidl_rmi__Invocation__set_contracts;
  epv->f__dump_stats                = remote_sidl_rmi__Invocation__dump_stats;
  epv->f__ctor                      = NULL;
  epv->f__ctor2                     = NULL;
  epv->f__dtor                      = NULL;
  epv->f_invokeMethod               = remote_sidl_rmi__Invocation_invokeMethod;
  epv->f_invokeNonblocking          = 
    remote_sidl_rmi__Invocation_invokeNonblocking;
  epv->f_invokeOneWay               = remote_sidl_rmi__Invocation_invokeOneWay;
  epv->f_packBool                   = remote_sidl_rmi__Invocation_packBool;
  epv->f_packChar                   = remote_sidl_rmi__Invocation_packChar;
  epv->f_packInt                    = remote_sidl_rmi__Invocation_packInt;
  epv->f_packLong                   = remote_sidl_rmi__Invocation_packLong;
  epv->f_packOpaque                 = remote_sidl_rmi__Invocation_packOpaque;
  epv->f_packFloat                  = remote_sidl_rmi__Invocation_packFloat;
  epv->f_packDouble                 = remote_sidl_rmi__Invocation_packDouble;
  epv->f_packFcomplex               = remote_sidl_rmi__Invocation_packFcomplex;
  epv->f_packDcomplex               = remote_sidl_rmi__Invocation_packDcomplex;
  epv->f_packString                 = remote_sidl_rmi__Invocation_packString;
  epv->f_packSerializable           = 
    remote_sidl_rmi__Invocation_packSerializable;
  epv->f_packBoolArray              = remote_sidl_rmi__Invocation_packBoolArray;
  epv->f_packCharArray              = remote_sidl_rmi__Invocation_packCharArray;
  epv->f_packIntArray               = remote_sidl_rmi__Invocation_packIntArray;
  epv->f_packLongArray              = remote_sidl_rmi__Invocation_packLongArray;
  epv->f_packOpaqueArray            = 
    remote_sidl_rmi__Invocation_packOpaqueArray;
  epv->f_packFloatArray             = 
    remote_sidl_rmi__Invocation_packFloatArray;
  epv->f_packDoubleArray            = 
    remote_sidl_rmi__Invocation_packDoubleArray;
  epv->f_packFcomplexArray          = 
    remote_sidl_rmi__Invocation_packFcomplexArray;
  epv->f_packDcomplexArray          = 
    remote_sidl_rmi__Invocation_packDcomplexArray;
  epv->f_packStringArray            = 
    remote_sidl_rmi__Invocation_packStringArray;
  epv->f_packGenericArray           = 
    remote_sidl_rmi__Invocation_packGenericArray;
  epv->f_packSerializableArray      = 
    remote_sidl_rmi__Invocation_packSerializableArray;
  epv->f_addRef                     = remote_sidl_rmi__Invocation_addRef;
  epv->f_deleteRef                  = remote_sidl_rmi__Invocation_deleteRef;
  epv->f_isSame                     = remote_sidl_rmi__Invocation_isSame;
  epv->f_isType                     = remote_sidl_rmi__Invocation_isType;
  epv->f_getClassInfo               = remote_sidl_rmi__Invocation_getClassInfo;

  e0->f__cast          = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e0->f__delete        = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__delete;
  e0->f__getURL        = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e0->f__raddRef       = (void (*)(void*, struct sidl_BaseInterface__object**)) 
    epv->f__raddRef;
  e0->f__isRemote      = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e0->f__set_hooks     = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e0->f__set_contracts = (void (*)(void*, sidl_bool, const char*, sidl_bool, 
    struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e0->f__dump_stats    = (void (*)(void*, const char*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__dump_stats;
  e0->f__exec          = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e0->f_addRef         = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_addRef;
  e0->f_deleteRef      = (void (*)(void*,struct sidl_BaseInterface__object **)) 
    epv->f_deleteRef;
  e0->f_isSame         = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e0->f_isType         = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e0->f_getClassInfo   = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e1->f__cast                 = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e1->f__delete               = (void (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e1->f__getURL               = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e1->f__raddRef              = (void (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e1->f__isRemote             = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e1->f__set_hooks            = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e1->f__set_contracts        = (void (*)(void*, sidl_bool, const char*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e1->f__dump_stats           = (void (*)(void*, const char*, const char*, 
    struct sidl_BaseInterface__object**)) epv->f__dump_stats;
  e1->f__exec                 = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e1->f_packBool              = (void (*)(void*,const char*,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packBool;
  e1->f_packChar              = (void (*)(void*,const char*,char,struct 
    sidl_BaseInterface__object **)) epv->f_packChar;
  e1->f_packInt               = (void (*)(void*,const char*,int32_t,struct 
    sidl_BaseInterface__object **)) epv->f_packInt;
  e1->f_packLong              = (void (*)(void*,const char*,int64_t,struct 
    sidl_BaseInterface__object **)) epv->f_packLong;
  e1->f_packOpaque            = (void (*)(void*,const char*,void*,struct 
    sidl_BaseInterface__object **)) epv->f_packOpaque;
  e1->f_packFloat             = (void (*)(void*,const char*,float,struct 
    sidl_BaseInterface__object **)) epv->f_packFloat;
  e1->f_packDouble            = (void (*)(void*,const char*,double,struct 
    sidl_BaseInterface__object **)) epv->f_packDouble;
  e1->f_packFcomplex          = (void (*)(void*,const char*,struct 
    sidl_fcomplex,struct sidl_BaseInterface__object **)) epv->f_packFcomplex;
  e1->f_packDcomplex          = (void (*)(void*,const char*,struct 
    sidl_dcomplex,struct sidl_BaseInterface__object **)) epv->f_packDcomplex;
  e1->f_packString            = (void (*)(void*,const char*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_packString;
  e1->f_packSerializable      = (void (*)(void*,const char*,struct 
    sidl_io_Serializable__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packSerializable;
  e1->f_packBoolArray         = (void (*)(void*,const char*,struct 
    sidl_bool__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packBoolArray;
  e1->f_packCharArray         = (void (*)(void*,const char*,struct 
    sidl_char__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packCharArray;
  e1->f_packIntArray          = (void (*)(void*,const char*,struct 
    sidl_int__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packIntArray;
  e1->f_packLongArray         = (void (*)(void*,const char*,struct 
    sidl_long__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packLongArray;
  e1->f_packOpaqueArray       = (void (*)(void*,const char*,struct 
    sidl_opaque__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packOpaqueArray;
  e1->f_packFloatArray        = (void (*)(void*,const char*,struct 
    sidl_float__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packFloatArray;
  e1->f_packDoubleArray       = (void (*)(void*,const char*,struct 
    sidl_double__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packDoubleArray;
  e1->f_packFcomplexArray     = (void (*)(void*,const char*,struct 
    sidl_fcomplex__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packFcomplexArray;
  e1->f_packDcomplexArray     = (void (*)(void*,const char*,struct 
    sidl_dcomplex__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packDcomplexArray;
  e1->f_packStringArray       = (void (*)(void*,const char*,struct 
    sidl_string__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packStringArray;
  e1->f_packGenericArray      = (void (*)(void*,const char*,struct sidl__array*,
    sidl_bool,struct sidl_BaseInterface__object **)) epv->f_packGenericArray;
  e1->f_packSerializableArray = (void (*)(void*,const char*,struct 
    sidl_io_Serializable__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packSerializableArray;
  e1->f_addRef                = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e1->f_deleteRef             = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e1->f_isSame                = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e1->f_isType                = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e1->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,
    struct sidl_BaseInterface__object **)) epv->f_getClassInfo;

  e2->f__cast                 = (void* (*)(void*, const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e2->f__delete               = (void (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__delete;
  e2->f__getURL               = (char* (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__getURL;
  e2->f__raddRef              = (void (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__raddRef;
  e2->f__isRemote             = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object**)) epv->f__isRemote;
  e2->f__set_hooks            = (void (*)(void*, sidl_bool, struct 
    sidl_BaseInterface__object**)) epv->f__set_hooks;
  e2->f__set_contracts        = (void (*)(void*, sidl_bool, const char*, 
    sidl_bool, struct sidl_BaseInterface__object**)) epv->f__set_contracts;
  e2->f__dump_stats           = (void (*)(void*, const char*, const char*, 
    struct sidl_BaseInterface__object**)) epv->f__dump_stats;
  e2->f__exec                 = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e2->f_invokeMethod          = (struct sidl_rmi_Response__object* (*)(void*,
    struct sidl_BaseInterface__object **)) epv->f_invokeMethod;
  e2->f_invokeNonblocking     = (struct sidl_rmi_Ticket__object* (*)(void*,
    struct sidl_BaseInterface__object **)) epv->f_invokeNonblocking;
  e2->f_invokeOneWay          = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_invokeOneWay;
  e2->f_packBool              = (void (*)(void*,const char*,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packBool;
  e2->f_packChar              = (void (*)(void*,const char*,char,struct 
    sidl_BaseInterface__object **)) epv->f_packChar;
  e2->f_packInt               = (void (*)(void*,const char*,int32_t,struct 
    sidl_BaseInterface__object **)) epv->f_packInt;
  e2->f_packLong              = (void (*)(void*,const char*,int64_t,struct 
    sidl_BaseInterface__object **)) epv->f_packLong;
  e2->f_packOpaque            = (void (*)(void*,const char*,void*,struct 
    sidl_BaseInterface__object **)) epv->f_packOpaque;
  e2->f_packFloat             = (void (*)(void*,const char*,float,struct 
    sidl_BaseInterface__object **)) epv->f_packFloat;
  e2->f_packDouble            = (void (*)(void*,const char*,double,struct 
    sidl_BaseInterface__object **)) epv->f_packDouble;
  e2->f_packFcomplex          = (void (*)(void*,const char*,struct 
    sidl_fcomplex,struct sidl_BaseInterface__object **)) epv->f_packFcomplex;
  e2->f_packDcomplex          = (void (*)(void*,const char*,struct 
    sidl_dcomplex,struct sidl_BaseInterface__object **)) epv->f_packDcomplex;
  e2->f_packString            = (void (*)(void*,const char*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_packString;
  e2->f_packSerializable      = (void (*)(void*,const char*,struct 
    sidl_io_Serializable__object*,struct sidl_BaseInterface__object **)) 
    epv->f_packSerializable;
  e2->f_packBoolArray         = (void (*)(void*,const char*,struct 
    sidl_bool__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packBoolArray;
  e2->f_packCharArray         = (void (*)(void*,const char*,struct 
    sidl_char__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packCharArray;
  e2->f_packIntArray          = (void (*)(void*,const char*,struct 
    sidl_int__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packIntArray;
  e2->f_packLongArray         = (void (*)(void*,const char*,struct 
    sidl_long__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packLongArray;
  e2->f_packOpaqueArray       = (void (*)(void*,const char*,struct 
    sidl_opaque__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packOpaqueArray;
  e2->f_packFloatArray        = (void (*)(void*,const char*,struct 
    sidl_float__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packFloatArray;
  e2->f_packDoubleArray       = (void (*)(void*,const char*,struct 
    sidl_double__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packDoubleArray;
  e2->f_packFcomplexArray     = (void (*)(void*,const char*,struct 
    sidl_fcomplex__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packFcomplexArray;
  e2->f_packDcomplexArray     = (void (*)(void*,const char*,struct 
    sidl_dcomplex__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packDcomplexArray;
  e2->f_packStringArray       = (void (*)(void*,const char*,struct 
    sidl_string__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packStringArray;
  e2->f_packGenericArray      = (void (*)(void*,const char*,struct sidl__array*,
    sidl_bool,struct sidl_BaseInterface__object **)) epv->f_packGenericArray;
  e2->f_packSerializableArray = (void (*)(void*,const char*,struct 
    sidl_io_Serializable__array*,int32_t,int32_t,sidl_bool,struct 
    sidl_BaseInterface__object **)) epv->f_packSerializableArray;
  e2->f_addRef                = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e2->f_deleteRef             = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e2->f_isSame                = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e2->f_isType                = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e2->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,
    struct sidl_BaseInterface__object **)) epv->f_getClassInfo;

  s_remote_initialized = 1;
}

/* Create an instance that connects to an existing remote object. */
static struct sidl_rmi_Invocation__object*
sidl_rmi_Invocation__remoteConnect(const char *url, sidl_bool ar, struct 
  sidl_BaseInterface__object* *_ex)
{
  struct sidl_rmi__Invocation__object* self = NULL;

  struct sidl_rmi__Invocation__object* s0;

  struct sidl_rmi__Invocation__remote* r_obj = NULL;
  sidl_rmi_InstanceHandle instance = NULL;
  struct sidl_rmi_Invocation__object* ret_self = NULL;
  char* objectID = NULL;
  objectID = sidl_rmi_ServerRegistry_isLocalObject(url, _ex);
  if(objectID) {
    sidl_BaseInterface bi = (sidl_BaseInterface) 
      sidl_rmi_InstanceRegistry_getInstanceByString(objectID, _ex);
    return (struct sidl_rmi_Invocation__object*)(*bi->d_epv->f__cast)(
      bi->d_object, "sidl.rmi.Invocation", _ex);
  }
  instance = sidl_rmi_ProtocolFactory_connectInstance(url, 
    "sidl.rmi.Invocation", ar, _ex );
  if ( instance == NULL) { return NULL; }
  self =
    (struct sidl_rmi__Invocation__object*) malloc(
      sizeof(struct sidl_rmi__Invocation__object));

  r_obj =
    (struct sidl_rmi__Invocation__remote*) malloc(
      sizeof(struct sidl_rmi__Invocation__remote));

  if(!self || !r_obj) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(
      _ex);
    SIDL_CHECK(*_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex); SIDL_CHECK(*_ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, 
      "sidl.rmi._Invocation.EPVgeneration", _ex);
    SIDL_CHECK(*_ex);
    *_ex = (struct sidl_BaseInterface__object*)ex;
    goto EXIT;
  }

  r_obj->d_refcount = 1;
  r_obj->d_ih = instance;
  s0 =                                self;

  LOCK_STATIC_GLOBALS;
  if (!s_remote_initialized) {
    sidl_rmi__Invocation__init_remote_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
  s0->d_sidl_baseinterface.d_object = (void*) self;

  s0->d_sidl_io_serializer.d_epv    = &s_rem_epv__sidl_io_serializer;
  s0->d_sidl_io_serializer.d_object = (void*) self;

  s0->d_sidl_rmi_invocation.d_epv    = &s_rem_epv__sidl_rmi_invocation;
  s0->d_sidl_rmi_invocation.d_object = (void*) self;

  s0->d_data = (void*) r_obj;
  s0->d_epv  = &s_rem_epv__sidl_rmi__invocation;

  self->d_data = (void*) r_obj;

  ret_self = (struct sidl_rmi_Invocation__object*) (*self->d_epv->f__cast)(self,
    "sidl.rmi.Invocation", _ex);
  if(*_ex || !ret_self) { goto EXIT; }
  return ret_self;
  EXIT:
  if(self) { free(self); }
  if(r_obj) { free(r_obj); }
  return NULL;
}
/* Create an instance that uses an already existing  */
/* InstanceHandle to connect to an existing remote object. */
static struct sidl_rmi_Invocation__object*
sidl_rmi_Invocation__IHConnect(sidl_rmi_InstanceHandle instance, struct 
  sidl_BaseInterface__object* *_ex)
{
  struct sidl_rmi__Invocation__object* self = NULL;

  struct sidl_rmi__Invocation__object* s0;

  struct sidl_rmi__Invocation__remote* r_obj = NULL;
  struct sidl_rmi_Invocation__object* ret_self = NULL;
  self =
    (struct sidl_rmi__Invocation__object*) malloc(
      sizeof(struct sidl_rmi__Invocation__object));

  r_obj =
    (struct sidl_rmi__Invocation__remote*) malloc(
      sizeof(struct sidl_rmi__Invocation__remote));

  if(!self || !r_obj) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(
      _ex);
    SIDL_CHECK(*_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex); SIDL_CHECK(*_ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, 
      "sidl.rmi._Invocation.EPVgeneration", _ex);
    SIDL_CHECK(*_ex);
    *_ex = (struct sidl_BaseInterface__object*)ex;
    goto EXIT;
  }

  r_obj->d_refcount = 1;
  r_obj->d_ih = instance;
  s0 =                                self;

  LOCK_STATIC_GLOBALS;
  if (!s_remote_initialized) {
    sidl_rmi__Invocation__init_remote_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
  s0->d_sidl_baseinterface.d_object = (void*) self;

  s0->d_sidl_io_serializer.d_epv    = &s_rem_epv__sidl_io_serializer;
  s0->d_sidl_io_serializer.d_object = (void*) self;

  s0->d_sidl_rmi_invocation.d_epv    = &s_rem_epv__sidl_rmi_invocation;
  s0->d_sidl_rmi_invocation.d_object = (void*) self;

  s0->d_data = (void*) r_obj;
  s0->d_epv  = &s_rem_epv__sidl_rmi__invocation;

  self->d_data = (void*) r_obj;

  sidl_rmi_InstanceHandle_addRef(instance, _ex);

  ret_self = (struct sidl_rmi_Invocation__object*) (*self->d_epv->f__cast)(self,
    "sidl.rmi.Invocation", _ex);
  if(*_ex || !ret_self) { goto EXIT; }
  return ret_self;
  EXIT:
  if(self) { free(self); }
  if(r_obj) { free(r_obj); }
  return NULL;
}
/*
 * RMI connector function for the class.
 */

struct sidl_rmi_Invocation__object*
sidl_rmi_Invocation__connectI(const char* url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex)
{
  return sidl_rmi_Invocation__remoteConnect(url, ar, _ex);
}


#endif /*WITH_RMI*/
