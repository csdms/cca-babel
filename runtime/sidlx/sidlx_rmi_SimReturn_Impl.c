/*
 * File:          sidlx_rmi_SimReturn_Impl.c
 * Symbol:        sidlx.rmi.SimReturn-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sidlx.rmi.SimReturn
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidlx.rmi.SimReturn" (version 0.1)
 * 
 * This type is used to pack return (out/inout) arguments on the server
 * side after a method has been exececuted.
 */

#include "sidlx_rmi_SimReturn_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn._includes) */

#include <stdlib.h>
#include "sidl_String.h"
#include "sidl_Exception.h"
#include "sidlx_common.h"
#include <string.h>
#include "sidlx_rmi_UnrecoverableException.h"
#include "sidl_io_Serializable.h"
#include "sidl_CastException.h"
#include "sidl_MemAllocException.h"
/* Serialize the response into a buffer and send!*/

/* Copies n elements from data into the vector we maintain as part of this 
   SimReturn object.  This function will realloc as nessecary */
static void serialize(sidlx_rmi_SimReturn self, const char* data, int n, int obj_size,
                      sidl_BaseInterface* _ex) {
  struct sidlx_rmi_SimReturn__data *dptr =
    sidlx_rmi_SimReturn__get_data(self);
  if(dptr) {

    int ii;
    int bytes = n * obj_size;
    int rem = dptr->d_capacity - dptr->d_len; /*space remaining*/
    /*Offset required to align to data type size*/
    int offset = (obj_size - ((dptr->d_len) % obj_size)) % obj_size; 
    char* s_ptr = NULL; 
    
    if(rem < bytes + offset) {
      dptr->d_capacity += n + offset;
      dptr->d_capacity *= 2;
      dptr->d_buf = (char*)realloc((void*)dptr->d_buf, dptr->d_capacity);
      if(dptr->d_buf == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "SimReturn.serialize", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;
      }
    }
    s_ptr = (dptr->d_buf)+(dptr->d_len);

    /*put in the offset characters to align to the data type size*/
    for(ii = 0; ii < offset; ++ii) {
      *s_ptr = '\0';
      ++s_ptr;
    }
    
    memcpy(s_ptr, data, bytes);
    (dptr->d_len) += bytes + offset;

    return;
  } 
  SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Return has not been init'ed!");
 EXIT:
  return;
}


/* Allocates a bunch of space on the buffer for an incoming array.  May or may not 
   actually need to do memory allocation.  Returns a pointer to the beginning of the
   space where the array should go.*/
static void* buffer_alloc(sidlx_rmi_SimReturn self, int64_t num_elems, int32_t obj_size, 
                          int32_t obj_per_elem, sidl_BaseInterface* _ex) {

  struct sidlx_rmi_SimReturn__data *dptr =
    sidlx_rmi_SimReturn__get_data(self);
  if(dptr) {
    int ii;
    int rem = dptr->d_capacity - dptr->d_len; /*space remaining*/
    /*Offset required to align to data type size*/
    int offset = (obj_size - ((dptr->d_len) % obj_size)) % obj_size; 
    char* s_ptr = NULL; 
    int total_len = (num_elems * obj_size * obj_per_elem) + offset;

    if(rem < total_len) {
      dptr->d_capacity += total_len;  /*Give us just enough space (arrays might be big)*/
      dptr->d_buf = (char*)realloc((void*)dptr->d_buf, dptr->d_capacity);
      if(dptr->d_buf == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "SimReturn.buffer_alloc", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;
      }
    }
    s_ptr = (dptr->d_buf)+(dptr->d_len); /* get pointer to beginning of space*/
    
    /*put in the offset characters to align to the data type size*/
    for(ii = 0; ii < offset; ++ii) {
      *s_ptr = '\0';
      ++s_ptr;
    }

    (dptr->d_len) += total_len; 
    return s_ptr;
  }
  SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Return has not been init'ed!");
 EXIT:
  return NULL;
}

/**
 * Resets the serialization buffer to the beginning.  Useful for exceptions
 */
static void buffer_reset(sidlx_rmi_SimReturn self, sidl_BaseInterface* _ex ) {
  struct sidlx_rmi_SimReturn__data *dptr =
    sidlx_rmi_SimReturn__get_data(self);
  if(dptr) {
    dptr->d_len = dptr->d_begin;
    return;
  }
  SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Return has not been init'ed!");
 EXIT:
  return;
  
}

static sidl_bool destIsRow(struct sidl__array* value, int32_t ordering, int32_t* dest_stride) {

  sidl_bool isRow;
  int32_t l_dimen = value->d_dimen;
  int ii;

  if(!ordering) { /*don't care about the ordering*/
    /* default is row ordering */
    if(sidl__array_isRowOrder(value) || !sidl__array_isColumnOrder(value)) {
      isRow = TRUE;
    } else { /*column iff !row && isColumn (1-dim is both)*/
      isRow = FALSE;
    }
  } else { /*(ordering is definded)*/
    isRow = (ordering == sidl_row_major_order);
  }
    
  if(isRow) {
    int32_t size=1;
    for(ii = l_dimen-1; ii >= 0; --ii) {
      dest_stride[ii] = size;
      size *= (1 + (value->d_upper)[ii] - (value->d_lower)[ii]);
    }
  } else {
    int32_t size=1;
    for(ii = 0; ii < l_dimen; ++ii) {
      dest_stride[ii] = size;
      size *= (1 + (value->d_upper)[ii] - (value->d_lower)[ii]);
    }
  }

  return isRow;
}

/** For now I've decided to remove all byte reordering.  We've already removed
 *  it for float, and we don't have any big endian machines anyway.
 *  I may put it back in later. 
 * 
 * I had never heard of "reader-makes-right" when I wrote this, so I put 
 *  everything in network byte order.  I had to write my own 64-bit
 *  ntohl... 
 static void flip64(int64_t* in) {
 int64_t x = *in;
 *in =  ((((x) & 0xff00000000000000ull) >> 56)				
 | (((x) & 0x00ff000000000000ull) >> 40)			
 | (((x) & 0x0000ff0000000000ull) >> 24)			
 | (((x) & 0x000000ff00000000ull) >> 8)			
 | (((x) & 0x00000000ff000000ull) << 8)			
 | (((x) & 0x0000000000ff0000ull) << 24)			
 | (((x) & 0x000000000000ff00ull) << 40)			
 | (((x) & 0x00000000000000ffull) << 56));
 }
 
 static void flip32(int32_t* in) {
 int32_t x = *in;
 *in = ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |	
 (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24));
 }
*/

static void* prep_array(sidlx_rmi_SimReturn self, struct sidl__array* value, 
			int32_t ordering, int32_t dimen, sidl_bool reuse,
			int32_t obj_size, int32_t obj_per_elem, int32_t* dest_stride,
			int32_t* lengths, int32_t* current, int64_t* total_elements, 
                        sidl_BaseInterface* _ex) {
  sidl_bool isRow = FALSE;
  char* srcFirst = NULL; 
  void* destFirst = NULL;
  int32_t l_dimen = 0; /*dimension (local copy)*/
  int32_t count = 0;
  int32_t *src_stride = NULL; 

  /* If the array is null, or a dimension is required but it different than
     the passed in array, pass a null array*/
  if(!value || ((dimen != 0) && value->d_dimen != dimen)) {
    /*serialize reuse bool*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
    return NULL;
  }


  isRow =  destIsRow(value, ordering, dest_stride);

  srcFirst = sidl_char__array_first((struct sidl_char__array*)value);
  l_dimen =  value->d_dimen;
  src_stride = value->d_stride;

  *total_elements = 1;
  for(count=0; count<l_dimen; ++count) {
    int32_t len = sidlLength(value, count);
    *total_elements *= len;
    lengths[count] = len;
    current[count] = 0;
  }

  /*serialize reuse bool*/
  impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse, _ex); SIDL_CHECK(*_ex);
  /*serilize isRow*/
  impl_sidlx_rmi_SimReturn_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
  /*serialize dimension*/
  impl_sidlx_rmi_SimReturn_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);
  /*serialize upper lower stride * dim */
  for(count = 0; count < l_dimen; ++count) {
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, (value->d_lower)[count], _ex); SIDL_CHECK(*_ex);
  }
  for(count = 0; count < l_dimen; ++count) {
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, (value->d_upper)[count], _ex); SIDL_CHECK(*_ex);
  }

  /*serialize data */
  /*Allocate enough buffer space for the array, and put the pointer in destFirst*/ 
  destFirst = buffer_alloc(self, *total_elements, obj_size, obj_per_elem, _ex); SIDL_CHECK(*_ex); 
  return destFirst;
 EXIT:
  return NULL;
}

/* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn._load) */
    /* insert implementation here: sidlx.rmi.SimReturn._load (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn__ctor(
  /* in */ sidlx_rmi_SimReturn self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn._ctor) */
    /* insert implementation here: sidlx.rmi.SimReturn._ctor (constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn__ctor2(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn._ctor2) */
    /* Insert-Code-Here {sidlx.rmi.SimReturn._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn__dtor(
  /* in */ sidlx_rmi_SimReturn self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn._dtor) */
    struct sidlx_rmi_SimReturn__data *dptr =
      sidlx_rmi_SimReturn__get_data(self);
    if(dptr) {
      sidlx_rmi_Socket sock = NULL;

      free((void*)dptr->d_buf);
      sidl_String_free(dptr->d_methodName);
      sock = dptr->d_sock;
      free((void*)dptr);
      sidlx_rmi_SimReturn__set_data(self, NULL);

      /* Clean up everything before there's a chance of exception. */
      sidlx_rmi_Socket_deleteRef(sock, _ex); /*SIDL_CLEAR(*_ex);*/
    }
  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn._dtor) */
  }
}

/*
 * Method:  init[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_init"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_init(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* methodName,
  /* in */ const char* objectid,
  /* in */ sidlx_rmi_Socket sock,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.init) */
    struct sidlx_rmi_SimReturn__data *dptr =
      sidlx_rmi_SimReturn__get_data(self);
  
    int m_len = sidl_String_strlen(methodName);
    /*  int c_len = sidl_String_strlen(className);*/
    int o_len = sidl_String_strlen(objectid);
    int h_len = 5+6+o_len+7+8+m_len+6;  /*header length (used to have c_len)*/
    int t_capacity = h_len+128;

    /* Make this inital space for the function call equal the length of
     * EXEC:objid:<objectid>:clsid:<className>:method:<methodName>:args:(args go here)
     * Make the space for args be equal to 128 bytes (just a guess)
     * Note: The first 'arg' is always a boolean that is true if an exception is thrown.
     */

    if (dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This inReturn has already been init'ed!");
    } else {
      dptr = malloc(sizeof(struct sidlx_rmi_SimReturn__data));
      if(dptr == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.SimReturn.init", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;	
      }
    }
    dptr->d_methodName = sidl_String_strdup(methodName);
    sidlx_rmi_Socket_addRef(sock,_ex); SIDL_CHECK(*_ex);
    dptr->d_sock = sock;
    dptr->d_len = 0;
    dptr->d_capacity = t_capacity;
    dptr->d_buf = (char*)malloc(t_capacity);
    if(dptr->d_buf == NULL) {
      sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
      sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
      sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.SimReturn.init", _ex);
      *_ex = (sidl_BaseInterface)ex;
      goto EXIT;	
    }
    
    sidlx_rmi_SimReturn__set_data(self, dptr);

    /* Initialize Header */
    serialize(self,"RESP:", 5, 1, _ex);
    serialize(self,"objid:", 6, 1, _ex);
    serialize(self,objectid, o_len, 1, _ex);
    /*  serialize(self,":clsid:", 7, _ex);
        serialize(self,className, c_len, _ex);*/
    serialize(self,":method:", 8, 1, _ex);
    serialize(self,methodName, m_len, 1, _ex);
    serialize(self,":args:", 6, 1, _ex);

    dptr->d_begin = dptr->d_len; /* Set where the args begin*/ 
    /* No exception thrown yet*/
    sidlx_rmi_SimReturn_packBool(self, "ex_thrown", 0, _ex); SIDL_CHECK(*_ex);
    return;
  EXIT:
    /*Not really anything to clean up...*/
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.init) */
  }
}

/*
 * Method:  getMethodName[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_getMethodName"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sidlx_rmi_SimReturn_getMethodName(
  /* in */ sidlx_rmi_SimReturn self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.getMethodName) */
    struct sidlx_rmi_SimReturn__data *dptr =
      sidlx_rmi_SimReturn__get_data(self);
    if(!dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Return has not been init'd!") 
        }
    return sidl_String_strdup(dptr->d_methodName);
  EXIT:
    return NULL;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.getMethodName) */
  }
}

/*
 *  this method is the last call on a return object.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_SendReturn"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_SendReturn(
  /* in */ sidlx_rmi_SimReturn self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.SendReturn) */
    struct sidlx_rmi_SimReturn__data *dptr =
      sidlx_rmi_SimReturn__get_data(self);
    if(dptr) {
      int lower = 0;
      int upper = (dptr->d_len)-1;
      int stride = 1;
      struct sidl_char__array *carray = 
        sidl_char__array_borrow(dptr->d_buf,1,&lower, &upper,&stride);
    
      sidlx_rmi_Socket_writestring(dptr->d_sock, dptr->d_len, carray, _ex); SIDL_CHECK(*_ex);
    
      sidl_char__array_deleteRef(carray);
      return;
    }
    SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Return has not been init'ed!");
  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.SendReturn) */
  }
}

/*
 *  
 * This method serialized exceptions thrown on the server side
 * that should be returned to the client.  Assumed to invalidate
 * in previously serialized arguments.  (Also assumed that no
 * more arguments will be serialized.)
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_throwException"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_throwException(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ sidl_BaseException ex_to_throw,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.throwException) */
    sidl_BaseInterface _throwaway_exception = NULL;
    sidl_io_Serializable ex_tmp = 
      sidl_io_Serializable__cast(ex_to_throw,_ex); SIDL_CHECK(*_ex);
    buffer_reset(self, _ex); SIDL_CHECK(*_ex);
    sidlx_rmi_SimReturn_packBool(self, "ex_thrown", 1, _ex); SIDL_CHECK(*_ex);
    sidlx_rmi_SimReturn_packSerializable(self, "_ex", ex_tmp, _ex); SIDL_CHECK(*_ex);
  EXIT:
    if (ex_tmp) sidl_io_Serializable_deleteRef(ex_tmp,&_throwaway_exception);
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.throwException) */
  }
}

/*
 * Method:  packBool[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packBool"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packBool(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ sidl_bool value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packBool) */
    if(value) {
      char x = 0xFF;
      serialize(self, &x, 1, 1, _ex); 
    }else{
      char x = 0;
      serialize(self, &x, 1, 1, _ex); 
    }
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packBool) */
  }
}

/*
 * Method:  packChar[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packChar"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packChar(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ char value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packChar) */
    serialize(self, &value, 1, 1, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packChar) */
  }
}

/*
 * Method:  packInt[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packInt"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packInt(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packInt) */
    serialize(self, (char*)&value, 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packInt) */
  }
}

/*
 * Method:  packLong[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packLong"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packLong(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ int64_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packLong) */
    serialize(self, (char*)&value, 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packLong) */
  }
}

/*
 * Method:  packOpaque[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packOpaque"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packOpaque(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ void* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packOpaque) */
    int64_t temp = (int64_t) (ptrdiff_t) value;
    serialize(self, (char*)&temp, 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packOpaque) */
  }
}

/*
 * Method:  packFloat[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packFloat"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packFloat(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ float value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packFloat) */
    serialize(self, (char*)&value, 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packFloat) */
  }
}

/*
 * Method:  packDouble[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packDouble"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packDouble(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packDouble) */
    serialize(self, (char*)&value, 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packDouble) */
  }
}

/*
 * Method:  packFcomplex[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packFcomplex"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packFcomplex(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ struct sidl_fcomplex value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packFcomplex) */
    serialize(self, (char*)&(value.real), 1, 4, _ex); 
    serialize(self, (char*)&(value.imaginary), 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packFcomplex) */
  }
}

/*
 * Method:  packDcomplex[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packDcomplex"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packDcomplex(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ struct sidl_dcomplex value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packDcomplex) */
    serialize(self, (char*)&(value.real), 1, 8, _ex); 
    serialize(self, (char*)&(value.imaginary), 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packDcomplex) */
  }
}

/*
 * Method:  packString[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packString"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packString(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ const char* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packString) */
    int32_t len = sidl_String_strlen(value);
    serialize(self, (char*)&len, 1, 4, _ex);
    serialize(self, value, len, 1, _ex);
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packString) */
  }
}

/*
 * Method:  packSerializable[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packSerializable"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packSerializable(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in */ sidl_io_Serializable value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packSerializable) */
    sidl_BaseInterface _throwaway_exception = NULL;
    sidl_io_Serializer serial = NULL;
    sidl_ClassInfo ci = NULL;
    char* class_name = NULL;
    char* obj_url = NULL;

    /* If the object is NULL, we call it remote and pack NULL as the URL*/

    int is_remote = FALSE;
    if(value) {
      is_remote = sidl_io_Serializable__isRemote(value, _ex); SIDL_CHECK(*_ex);
    } else {
      is_remote = TRUE;
      sidlx_rmi_SimReturn_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      sidlx_rmi_SimReturn_packString(self, NULL, NULL, _ex); SIDL_CHECK(*_ex);
      return;
    }

    if(is_remote) {

      sidlx_rmi_SimReturn_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      obj_url = sidl_io_Serializable__getURL(value, _ex);SIDL_CHECK(*_ex);
      sidlx_rmi_SimReturn_packString(self, NULL, obj_url, _ex); SIDL_CHECK(*_ex);
      
    } else {

      sidlx_rmi_SimReturn_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      ci = sidl_io_Serializable_getClassInfo(value,_ex); SIDL_CHECK(*_ex);
      class_name = sidl_ClassInfo_getName(ci,_ex); SIDL_CHECK(*_ex);
      sidlx_rmi_SimReturn_packString(self, NULL, class_name, _ex); SIDL_CHECK(*_ex);
      serial = sidl_io_Serializer__cast(self,_ex); SIDL_CHECK(*_ex);
      sidl_io_Serializable_packObj(value, serial, _ex); SIDL_CHECK(*_ex); 
    }

  EXIT:
    if(ci) {sidl_ClassInfo_deleteRef(ci,&_throwaway_exception);}
    if(serial) {sidl_io_Serializer_deleteRef(serial, &_throwaway_exception);}
    sidl_String_free(class_name);
    sidl_String_free(obj_url);
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packSerializable) */
  }
}

/*
 *  
 * pack arrays of values.  It is possible to ensure an array is
 * in a certain order by passing in ordering and dimension
 * requirements.  ordering should represent a value in the
 * sidl_array_ordering enumeration in sidlArray.h If either
 * argument is 0, it means there is no restriction on that
 * aspect.  The boolean reuse_array flag is set to true if the
 * remote unserializer should try to reuse the array that is
 * passed into it or not.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packBoolArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packBoolArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<bool> */ struct sidl_bool__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packBoolArray) */
  
    sidl_bool* srcFirst = NULL; 
    char* destFirst = NULL;
    int32_t l_dimen = 0; /*dimension (local copy)*/
    int32_t dest_stride[7];
    int32_t *src_stride = NULL; 
    int32_t lengths[7];
    int32_t current[7];
    int i;
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (char*)prep_array(self, (struct sidl__array*)value, ordering, 
                                  dimen, reuse_array, 1,1,dest_stride, 
                                  lengths, current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      src_stride = value->d_metadata.d_stride;
      srcFirst = sidl_bool__array_first(value);
      l_dimen = sidlArrayDim(value);

    
      if(total_elements > 0) {
        do {
          if(*srcFirst) {
            *destFirst = (char)0xFF;
          } else {
            *destFirst = (char)0;
          }
          /* the whole point of this for-loop is to move forward one element */
          for(i = l_dimen - 1; i >= 0; --i) {
            ++(current[i]);
            if (current[i] >= lengths[i]) {
              /* this dimension has been enumerated already reset to beginning */
              current[i] = 0;
              /* prepare to next iteration of for-loop for i-1 */
              destFirst -= ((lengths[i]-1) * dest_stride[i]);
              srcFirst -= ((lengths[i]-1) * src_stride[i]);
            }
            else {
              /* move forward one element in dimension i */
              destFirst += dest_stride[i];
              srcFirst += src_stride[i];
              break; /* exit for loop */
            }
          }
        } while (i >= 0);
      }
      /* Finished serializing data*/
    }
  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packBoolArray) */
  }
}

/*
 * Method:  packCharArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packCharArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packCharArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<char> */ struct sidl_char__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packCharArray) */
 
    char* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (char*)prep_array(self, (struct sidl__array*)value, ordering, 
                                  dimen, reuse_array, 1,1,dest_stride, lengths, 
                                  current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_char__array* destArray = 
        sidl_char__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_char__array_copy(value, destArray);
      sidl_char__array_deleteRef(destArray);
    }
    /* Finished serializing data*/
    
  EXIT:
    return;
    
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packCharArray) */
  }
}

/*
 * Method:  packIntArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packIntArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packIntArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<int> */ struct sidl_int__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packIntArray) */
    
    int32_t* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (int32_t*)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array, 4,1,dest_stride, lengths,
                                     current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_int__array* destArray = 
        sidl_int__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_int__array_copy(value, destArray);
      sidl_int__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;
  
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packIntArray) */
  }
}

/*
 * Method:  packLongArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packLongArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packLongArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<long> */ struct sidl_long__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packLongArray) */

    int64_t* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (int64_t *)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array,8,1,dest_stride, lengths, 
                                     current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_long__array* destArray = 
        sidl_long__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_long__array_copy(value, destArray);
      sidl_long__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packLongArray) */
  }
}

/*
 * Method:  packOpaqueArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packOpaqueArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packOpaqueArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<opaque> */ struct sidl_opaque__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packOpaqueArray) */

    void ** destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (void **)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array, 8,1,dest_stride, lengths, 
                                     current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_opaque__array* destArray = 
        sidl_opaque__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_opaque__array_copy(value, destArray);
      sidl_opaque__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packOpaqueArray) */
  }
}

/*
 * Method:  packFloatArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packFloatArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packFloatArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<float> */ struct sidl_float__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packFloatArray) */

    float* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (float*)prep_array(self, (struct sidl__array*)value, ordering, 
                                   dimen, reuse_array,4,1,dest_stride, lengths,
                                   current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_float__array* destArray = 
        sidl_float__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_float__array_copy(value, destArray);
      sidl_float__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;
  
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packFloatArray) */
  }
}

/*
 * Method:  packDoubleArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packDoubleArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packDoubleArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<double> */ struct sidl_double__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packDoubleArray) */

    double* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 

    destFirst = (double*)prep_array(self, (struct sidl__array*)value, ordering, 
                                    dimen, reuse_array,8,1,dest_stride, lengths, 
                                    current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_double__array* destArray = 
        sidl_double__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_double__array_copy(value, destArray);
      sidl_double__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packDoubleArray) */
  }
}

/*
 * Method:  packFcomplexArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packFcomplexArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packFcomplexArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packFcomplexArray) */

    struct sidl_fcomplex* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 

    destFirst = (struct sidl_fcomplex*)prep_array(self, (struct sidl__array*)value, ordering, 
                                                  dimen, reuse_array, 4,2,dest_stride, lengths,
                                                  current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_fcomplex__array* destArray = 
        sidl_fcomplex__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_fcomplex__array_copy(value, destArray);
      sidl_fcomplex__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packFcomplexArray) */
  }
}

/*
 * Method:  packDcomplexArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packDcomplexArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packDcomplexArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packDcomplexArray) */

    struct sidl_dcomplex* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (struct sidl_dcomplex*)prep_array(self, (struct sidl__array*)value, ordering, 
                                                  dimen, reuse_array, 8,2,dest_stride, lengths, 
                                                  current, &total_elements, _ex);
    SIDL_CHECK(*_ex);

    if(destFirst) {
      /* Use Babel array copy to copy the array into the buffer
       * Possible refinement: allocate the array metadata on the stack */
      struct sidl_dcomplex__array* destArray = 
        sidl_dcomplex__array_borrow(destFirst, value->d_metadata.d_dimen, 
                               value->d_metadata.d_lower, value->d_metadata.d_upper, dest_stride);

      sidl_dcomplex__array_copy(value, destArray);
      sidl_dcomplex__array_deleteRef(destArray);
    }
    /* Finished serializing data*/

  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packDcomplexArray) */
  }
}

/*
 * Method:  packStringArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packStringArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packStringArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<string> */ struct sidl_string__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packStringArray) */
    sidl_bool isRow = FALSE;
    char** srcFirst = NULL; 
    int32_t l_dimen = 0; /*dimension (local copy)*/
    int32_t count = 0;
    int32_t dest_stride[7];
    int32_t *src_stride = NULL; 
    int32_t lengths[7];
    int32_t current[7];
    int i;
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    /* If the array is null, or a dimension is required but it different than
       the passed in array, pass a null array*/
    if(!value || ((dimen != 0) && sidl_string__array_dimen(value) != dimen)) {
      /*serialize reuse bool*/
      impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
      /*serilize isRow*/
      impl_sidlx_rmi_SimReturn_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
      /*serialize dimension*/
      impl_sidlx_rmi_SimReturn_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }

    isRow = destIsRow((struct sidl__array *)value, ordering, dest_stride);

    l_dimen = sidlArrayDim(value);
    srcFirst = (char**)sidl_int__array_first((struct sidl_int__array*)value);
    src_stride = ((struct sidl__array*)value)->d_stride;

    /*Figure out lengths (useful for copy)*/
    for(count=0; count<l_dimen; ++count) {
      int32_t len = sidlLength(value, count);
      lengths[count] = len;
      total_elements *= len;
      current[count] = 0;
    }

    /*serialize reuse bool*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);

    /*serialize upper lower stride * dim */
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_SimReturn_packInt(self, NULL, sidl_string__array_lower(value, count), _ex); SIDL_CHECK(*_ex);
    }
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_SimReturn_packInt(self, NULL, sidl_string__array_upper(value, count), _ex); SIDL_CHECK(*_ex);
    }
    /* Serialization of stride is unessecary, it is known from above info*/

    /*serialize data */
    /*Allocate enough buffer space for the array, and put the pointer in destFirst*/ 
    if(total_elements > 0) {
      do {
        int32_t len = sidl_String_strlen(*srcFirst);
        serialize(self, (char*)&len, 1, 4, _ex);SIDL_CHECK(*_ex);
        serialize(self, *srcFirst, len, 1, _ex);SIDL_CHECK(*_ex);
        
        /* the whole point of this for-loop is to move forward one element */
        for(i = l_dimen - 1; i >= 0; --i) {
          ++(current[i]);
          if (current[i] >= lengths[i]) {
            /* this dimension has been enumerated already reset to beginning */
            current[i] = 0;
            /* prepare to next iteration of for-loop for i-1 */
            srcFirst -= ((lengths[i]-1) * src_stride[i]);
          }
          else {
            /* move forward one element in dimension i */
            srcFirst += src_stride[i];
            break; /* exit for loop */
          }
        }
      } while (i >= 0);
    }
    /* Finished serializing data*/

  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packStringArray) */
  }
}

/*
 * Method:  packGenericArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packGenericArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packGenericArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<> */ struct sidl__array* value,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packGenericArray) */
    int32_t type = 0;
    if(value){
      type = sidl__array_type(value);
    } else {
      /* If the array is null, pass a null array and bail */
      impl_sidlx_rmi_SimReturn_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }
  
    /*serialize type */
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, type, _ex); SIDL_CHECK(*_ex);
    switch(type) {
    case sidl_bool_array:
      sidlx_rmi_SimReturn_packBoolArray(self,key,(struct sidl_bool__array*) value, 
                                        0,0,reuse_array,_ex);
      break;
    case sidl_char_array:
      sidlx_rmi_SimReturn_packCharArray(self,key,(struct sidl_char__array*) value, 
                                        0,0,reuse_array,_ex);
      break;
    case sidl_dcomplex_array:
      sidlx_rmi_SimReturn_packDcomplexArray(self,key,(struct sidl_dcomplex__array*) value, 
                                            0,0,reuse_array,_ex);
      break;
    case sidl_double_array:
      sidlx_rmi_SimReturn_packDoubleArray(self,key,(struct sidl_double__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_fcomplex_array:
      sidlx_rmi_SimReturn_packFcomplexArray(self,key,(struct sidl_fcomplex__array*) value, 
                                            0,0,reuse_array,_ex);
      break;
    case sidl_float_array:
      sidlx_rmi_SimReturn_packFloatArray(self,key,(struct sidl_float__array*) value, 
                                         0,0,reuse_array,_ex);
      break;
    case sidl_int_array:
      sidlx_rmi_SimReturn_packIntArray(self,key,(struct sidl_int__array*) value, 
                                       0,0,reuse_array,_ex);
      break;
    case sidl_long_array:
      sidlx_rmi_SimReturn_packLongArray(self,key,(struct sidl_long__array*) value, 
                                        0,0,reuse_array,_ex);
      break;
    case sidl_opaque_array:
      sidlx_rmi_SimReturn_packOpaqueArray(self,key,(struct sidl_opaque__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_string_array:
      sidlx_rmi_SimReturn_packStringArray(self,key,(struct sidl_string__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_interface_array:
    
      sidlx_rmi_SimReturn_packSerializableArray(self,key,(struct sidl_io_Serializable__array*) value, 
                                                0,0,reuse_array,_ex);
    }
  EXIT:  return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packGenericArray) */
  }
}

/*
 * Method:  packSerializableArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_SimReturn_packSerializableArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_SimReturn_packSerializableArray(
  /* in */ sidlx_rmi_SimReturn self,
  /* in */ const char* key,
  /* in array<sidl.io.Serializable> */ struct sidl_io_Serializable__array* 
    value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.SimReturn.packSerializableArray) */
    sidl_bool isRow = FALSE;
    sidl_io_Serializable* srcFirst = NULL; 
    sidl_io_Serializable toSerialize = NULL;
    sidl_BaseInterface toCast = NULL;
    int32_t l_dimen = 0; /*dimension (local copy)*/
    int32_t count = 0;
    int32_t dest_stride[7];
    int32_t *src_stride = NULL; 
    int32_t lengths[7];
    int32_t current[7];
    int i;
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    /* If the array is null, or a dimension is required but it different than
       the passed in array, pass a null array*/
    if(!value || ((dimen != 0) && sidl_io_Serializable__array_dimen(value) != dimen)) {
      /*serialize reuse bool*/
      impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);     
      /*serilize isRow*/
      impl_sidlx_rmi_SimReturn_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
      /*serialize dimension*/
      impl_sidlx_rmi_SimReturn_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }

    isRow = destIsRow((struct sidl__array *)value, ordering, dest_stride);

    l_dimen =  sidl_io_Serializable__array_dimen(value);
    srcFirst = (sidl_io_Serializable*)sidl_char__array_first((struct sidl_char__array*)value);
    src_stride = ((struct sidl_char__array*)value)->d_metadata.d_stride;

    /*Figure out lengths (useful for copy)*/
    for(count=0; count<l_dimen; ++count) {
      int32_t len = sidlLength(value, count);
      lengths[count] = len;
      total_elements *= len;
      current[count] = 0;
    }

    /*serialize reuse bool*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_SimReturn_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_SimReturn_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);

    /*serialize upper lower stride * dim */
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_SimReturn_packInt(self, NULL,  sidl_io_Serializable__array_lower(value,count), _ex); SIDL_CHECK(*_ex);
    }
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_SimReturn_packInt(self, NULL,  sidl_io_Serializable__array_upper(value,count), _ex); SIDL_CHECK(*_ex);
    }
    /* Serialization of stride is unessecary, it is known from above info*/

    /*serialize data */
    /*Allocate enough buffer space for the array, and put the pointer in destFirst*/ 
 
    if(total_elements > 0) {
      do {
        toCast = (sidl_BaseInterface) *srcFirst;
        toSerialize = sidl_io_Serializable__cast(toCast,_ex); SIDL_CHECK(*_ex);
        sidlx_rmi_SimReturn_packSerializable(self, NULL, toSerialize, _ex); SIDL_CHECK(*_ex);
        sidl_io_Serializable_deleteRef(toSerialize, _ex); SIDL_CHECK(*_ex);
        /* the whole point of this for-loop is to move forward one element */
        for(i = l_dimen - 1; i >= 0; --i) {
          ++(current[i]);
          if (current[i] >= lengths[i]) {
            /* this dimension has been enumerated already reset to beginning */
            current[i] = 0;
            /* prepare to next iteration of for-loop for i-1 */
            srcFirst -= ((lengths[i]-1) * src_stride[i]);
          }
          else {
            /* move forward one element in dimension i */
            srcFirst += src_stride[i];
            break; /* exit for loop */
          }
        }
      } while (i >= 0);
    }
    /* Finished serializing data*/

  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.SimReturn.packSerializableArray) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

