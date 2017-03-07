/*
 * File:        sidl_interface_IOR.h
 * Copyright:   (c) 2001-2002 Lawrence Livermore National Security, LLC
 * Revision:    @(#) $Revision$
 * Date:        $Date$
 * Description: interface array declarations and definitions
 * AUTOMATICALLY GENERATED BY createarrays.py
 *
 */

#ifndef included_sidl_interface_IOR_h
#define included_sidl_interface_IOR_h

#ifndef included_sidlType_h
#include "sidlType.h"
#endif

#ifndef included_sidlArray_h
#include "sidlArray.h"
#endif


#ifndef included_sidl_BaseInterface_h        
#include "sidl_BaseInterface.h"
#endif

/**
 * The data structure for multi-dimensional arrays for sidl interface.
 * The client may access this with the functions below or using
 * the macros in the header file sidlArray.h.
 */
struct sidl_interface__array {
  struct sidl__array   d_metadata;
  sidl_BaseInterface *d_firstElement;
};

#ifdef __cplusplus
extern "C" { /*}*/
#endif

/**
 * Create a dense interface array of the given dimension with specified
 * index bounds in column-major order.  This array owns and manages its data.
 * This function initializes the contents of the array to NULL.
 */
struct sidl_interface__array *
sidl_interface__array_createCol(int32_t       dimen,
                                const int32_t lower[],
                                const int32_t upper[]);

/**
 * Create a dense interface array of the given dimension with specified
 * index bounds in row-major order.  This array owns and manages its data.
 * This function initializes the contents of the array to NULL.
 */
struct sidl_interface__array *
sidl_interface__array_createRow(int32_t       dimen,
                                const int32_t lower[],
                                const int32_t upper[]);

/**
 * Initialize the array meta-data for this sidl array from the passed
 * in pointers. This is a little wierd, but all these pointers must
 * be allocated, but only upper and c_array actually need to be
 * initialized.  (We use upper, dim, andc_array to figure out the
 * correct values for the rest of the data.)
 * This function initializes the contents of the array to NULL.
 */
void
sidl_interface__array_init(sidl_BaseInterface const* c_array,
struct sidl_interface__array* sidl_array, int32_t dim,
int32_t lower[], int32_t upper[], int32_t stride[]);

/**
 * Create a dense one-dimensional vector of interfaces with a lower
 * index of 0 and an upper index of len-1. This array owns and manages
 * its data.
 * This function initializes the contents of the array to NULL.
 */
struct sidl_interface__array *
sidl_interface__array_create1d(int32_t len);

/**
 * Create a dense one-dimensional vector of interfaces with a lower
 * index of 0 and an upper index of len-1. The initial data for this
 * new array is copied from data. For strings, this will make a newly
 * malloc'ed copy of each non-NULL string. For interfaces/objects, this
 * will increment the reference count of each non-NULL object/interface
 * reference.
 * 
 * This array owns and manages its data.
 */
struct sidl_interface__array *
sidl_interface__array_create1dInit(int32_t len,
                                   sidl_BaseInterface* data);

/**
 * Create a dense two-dimensional array of interfaces with a lower
 * indices of (0,0) and an upper indices of (m-1,n-1). The array is
 * stored in column-major order, and it owns and manages its data.
 * This function initializes the contents of the array to NULL.
 */
struct sidl_interface__array *
sidl_interface__array_create2dCol(int32_t m, int32_t n);

/**
 * Create a dense two-dimensional array of interfaces with a lower
 * indices of (0,0) and an upper indices of (m-1,n-1). The array is
 * stored in row-major order, and it owns and manages its data.
 * This function initializes the contents of the array to NULL.
 */
struct sidl_interface__array *
sidl_interface__array_create2dRow(int32_t m, int32_t n);

/**
 * Create a sub-array of another array. This resulting array shares
 * data with the original array. The new array can be of the same
 * dimension or potentially less assuming the original array has
 * dimension greater than 1.  If you are removing dimension, indicate the
 * dimensions to remove by setting numElem[i] to zero for any dimension i
 * that should go away in the new array.  The meaning of each argument
 * is covered below.
 * 
 * src       the array to be created will be a subset of this array. If
 *           this argument is NULL, NULL will be returned. The array
 *           returned borrows data from src, so modifying src or the
 *           returned array will modify both arrays.
 * 
 * dimen     this argument must be greater than zero and less than or
 *           equal to the dimension of src. An illegal value will cause
 *           a NULL return value.
 *           
 * numElem   this specifies how many elements from src should be taken in
 *           each dimension. A zero entry indicates that the dimension
 *           should not appear in the new array.  This argument should be
 *           an array with an entry for each dimension of src.  Passing
 *           NULL here will cause NULL to be returned.  If
 *           srcStart[i] + numElem[i]*srcStride[i] is greater than
 *           upper[i] for src or if srcStart[i] + numElem[i]*srcStride[i]
 *           is less than lower[i] for src, NULL will be returned.
 * 
 * srcStart  this array holds the coordinates of the first element of the
 *           new array. If this argument is NULL, the first element of
 *           src will be the first element of the new array. If non-NULL,
 *           this argument should be an array with an entry for each
 *           dimension of src.  If srcStart[i] is less than lower[i] for
 *           the array src, NULL will be returned.
 * 
 * srcStride this array lets you specify the stride between elements in
 *           each dimension of src. This stride is relative to the
 *           coordinate system of the src array. If this argument is
 *           NULL, the stride is taken to be one in each dimension.
 *           If non-NULL, this argument should be an array with an entry
 *           for each dimension of src.
 * 
 * newLower  this argument is like lower in a create method. It sets the
 *           coordinates for the first element in the new array.  If this
 *           argument is NULL, the values indicated by srcStart will be
 *           used. If non-NULL, this should be an array with dimen
 *           elements.
 */
struct sidl_interface__array *
sidl_interface__array_slice(struct sidl_interface__array *src,
                            int32_t       dimen,
                            const int32_t numElem[],
                            const int32_t *srcStart,
                            const int32_t *srcStride,
                            const int32_t *newStart);

/**
 * Create an array that uses data memory from another source. This initial
 * contents are determined by the data being borrowed.
 */
struct sidl_interface__array *
sidl_interface__array_borrow(sidl_BaseInterface* firstElement,
                             int32_t        dimen,
                             const int32_t  lower[],
                             const int32_t  upper[],
                             const int32_t  stride[]);

/**
 * If array is borrowed, allocate a new self-sufficient array and copy
 * the borrowed array into the new array; otherwise, increment the
 * reference count and return the array passed in. Use this whenever
 * you want to make a copy of a method argument because arrays passed
 * into methods aren't guaranteed to exist after the method call.
 */
struct sidl_interface__array *
sidl_interface__array_smartCopy(struct sidl_interface__array *array);

/**
 * Increment the arrays internal reference count by one. To make a
 * persistent copy (i.e. that lives longer than the current method
 * call) use smartCopy.
 */
void
sidl_interface__array_addRef(struct sidl_interface__array* array);

/**
 * Decrement the arrays internal reference count by one. If the reference
 * count goes to zero, destroy the array.
 * Return true iff the array is destroyed
 */
void
sidl_interface__array_deleteRef(struct sidl_interface__array* array);

/**
 * Attempt to cast a generic array reference to an interface
 * array. A non-NULL return value indicates that the cast was
 * successful, and the returned pointer is a valid interface
 * array. A NULL return value indicates that the cast failed.
 * This function never alters the reference count of array.
 * 
 */
struct sidl_interface__array*
sidl_interface__array_cast(struct sidl__array* array);

/**
 * Retrieve element i1 of a one-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get1(const struct sidl_interface__array* array,
                           const int32_t i1);

/**
 * Retrieve element (i1,i2) of a two-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get2(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2);

/**
 * Retrieve element (i1,i2,i3) of a three-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get3(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3);

/**
 * Retrieve element (i1,i2,i3,i4) of a four-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get4(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4);

/**
 * Retrieve element (i1,i2,i3,i4,i5) of a five-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get5(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5);

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6) of a six-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get6(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5,
                           const int32_t i6);

/**
 * Retrieve element (i1,i2,i3,i4,i5,i6,i7) of a seven-dimensional array.
 */
sidl_BaseInterface
sidl_interface__array_get7(const struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5,
                           const int32_t i6,
                           const int32_t i7);

/**
 * Retrieve element indices of an n-dimensional array. Indices is assumed
 * to have the right number of elements for the dimension of array.
 */
sidl_BaseInterface
sidl_interface__array_get(const struct sidl_interface__array* array,
                          const int32_t indices[]);

/**
 * Set element i1 of a one-dimensional array to value.
 */
void
sidl_interface__array_set1(struct sidl_interface__array* array,
                           const int32_t i1,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2) of a two-dimensional array to value.
 */
void
sidl_interface__array_set2(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2,i3) of a three-dimensional array to value.
 */
void
sidl_interface__array_set3(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2,i3,i4) of a four-dimensional array to value.
 */
void
sidl_interface__array_set4(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2,i3,i4,i5) of a five-dimensional array to value.
 */
void
sidl_interface__array_set5(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2,i3,i4,i5,i6) of a six-dimensional array to value.
 */
void
sidl_interface__array_set6(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5,
                           const int32_t i6,
                           sidl_BaseInterface const value);

/**
 * Set element (i1,i2,i3,i4,i5,i6,i7) of a seven-dimensional array to value.
 */
void
sidl_interface__array_set7(struct sidl_interface__array* array,
                           const int32_t i1,
                           const int32_t i2,
                           const int32_t i3,
                           const int32_t i4,
                           const int32_t i5,
                           const int32_t i6,
                           const int32_t i7,
                           sidl_BaseInterface const value);

/**
 * Set element indices of an n-dimensional array to value. indices is assumed
 * to have the right number of elements for the dimension of array.
 */
void
sidl_interface__array_set(struct sidl_interface__array* array,
                          const int32_t indices[],
                          sidl_BaseInterface const value);

/**
 * Return the dimension of array. If the array pointer is NULL,
 * zero is returned.
 */
int32_t
sidl_interface__array_dimen(const struct sidl_interface__array* array);

/**
 * Return the lower index bound on dimension ind. If ind is not a valid
 * dimension, zero is returned. The valid range for ind is 0 to dimen-1.
 */
int32_t
sidl_interface__array_lower(const struct sidl_interface__array* array,
                            const int32_t ind);

/**
 * Return the upper index bound on dimension ind. If ind is not a valid
 * dimension, negative one is returned. The valid range for ind is 0 to
 * dimen-1.
 */
int32_t
sidl_interface__array_upper(const struct sidl_interface__array* array,
                            const int32_t ind);

/**
 * Return the number of element in dimension ind. If ind is not a valid
 * dimension, negative one is returned. The valid range for ind is 0 to
 * dimen-1.
 */
int32_t
sidl_interface__array_length(const struct sidl_interface__array* array,
                             const int32_t ind);

/**
 * Return the stride of dimension ind. If ind is not a valid
 * dimension, zero is returned. The valid range for ind is 0 to
 * dimen-1.
 */
int32_t
sidl_interface__array_stride(const struct sidl_interface__array* array,
                             const int32_t ind);

/**
 * Return a true value iff the array is a contiguous column-major ordered
 * array.  A NULL array argument causes 0 to be returned.
 */
sidl_bool
sidl_interface__array_isColumnOrder(const struct sidl_interface__array* array);

/**
 * Return a true value iff the array is a contiguous row-major ordered
 * array.  A NULL array argument causes 0 to be returned.
 */
sidl_bool
sidl_interface__array_isRowOrder(const struct sidl_interface__array* array);

/**
 * Copy the contents of one array (src) to a second array (dest). For
 * the copy to take place, both arrays must exist and be of the same
 * dimension. This method will not modify dest's size, index bounds,
 * or stride; only the array element values of dest may be changed by
 * this function. No part of src is ever changed by copy.
 * 
 * On exit, dest[i][j][k]... = src[i][j][k]... for all indices i,j,k...
 * that are in both arrays. If dest and src have no indices in common,
 * nothing is copied. For example, if src is a 1-d array with elements
 * 0-5 and dest is a 1-d array with elements 2-3, this function will
 * make the following assignments:
 *   dest[2] = src[2],
 *   dest[3] = src[3].
 * The function copied the elements that both arrays have in common.
 * If dest had elements 4-10, this function will make the following
 * assignments:
 *   dest[4] = src[4],
 *   dest[5] = src[5].
 * 
 */
void
sidl_interface__array_copy(const struct sidl_interface__array* src,
                                 struct sidl_interface__array* dest);

/**
 * If necessary, convert a general matrix into a matrix with the required
 * properties. This checks the dimension and ordering of the matrix.
 * If both these match, it simply returns a new reference to the existing
 * matrix. If the dimension of the incoming array doesn't match, it
 * returns NULL. If the ordering of the incoming array doesn't match the
 * specification, a new array is created with the desired ordering and
 * the content of the incoming array is copied to the new array.
 * 
 * The ordering parameter should be one of the constants defined in
 * enum sidl_array_ordering (e.g. sidl_general_order,
 * sidl_column_major_order, or sidl_row_major_order). If you
 * specify sidl_general_order, this routine will only check the
 * dimension because any matrix is sidl_general_order.
 * 
 * The caller assumes ownership of the returned reference unless it's NULL.
 * 
 */
struct sidl_interface__array*
sidl_interface__array_ensure(struct sidl_interface__array* src,
                             int32_t                dimen,
                             int                    ordering);

#ifdef __cplusplus
}
#endif
#endif /* included_sidl_interface_IOR_h */
