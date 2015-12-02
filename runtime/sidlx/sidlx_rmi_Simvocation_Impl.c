/*
 * File:          sidlx_rmi_Simvocation_Impl.c
 * Symbol:        sidlx.rmi.Simvocation-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for sidlx.rmi.Simvocation
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidlx.rmi.Simvocation" (version 0.1)
 * 
 * implementation of Invocation using the Simhandle Protocol (written by Jim)
 */

#include "sidlx_rmi_Simvocation_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation._includes) */

#include <stdlib.h>
#include "sidl_String.h"
#include "sidl_Exception.h"
#include "sidlx_rmi_Simsponse.h"
#include "sidl_rmi_NetworkException.h"
#include "sidlx_rmi_UnrecoverableException.h"
#include "sidl_MemAllocException.h"
#include "sidl_CastException.h"
#include "sidlx_common.h"
#include "sidl_io_Serializable.h"
#include "sidlx_rmi_SimpleTicket.h"
#include <string.h>
/* Copies n elements from data into the vector we maintain as part of this 
   Simvocation object.  This function will grow the buffer as nessecary */
static void serialize(sidlx_rmi_Simvocation self, const char* data, int n, int obj_size, 
                      sidl_BaseInterface* _ex) {
  struct sidlx_rmi_Simvocation__data *dptr =
    sidlx_rmi_Simvocation__get_data(self);
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
	sidl_MemAllocException_setNote(ex, "Realloc failed.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "Simvocation.serialize", _ex);
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
  SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This Invocation has not been init'ed!");
 EXIT:
  return;
}


/* Allocates a bunch of space on the buffer for an incoming array.  May or may not 
   actually need to do memory allocation.  Returns a pointer to the beginning of the
   space where the array should go.*/
static void* buffer_alloc(sidlx_rmi_Simvocation self, int64_t num_elems, int32_t obj_size, 
                          int32_t obj_per_elem, sidl_BaseInterface* _ex) {

  struct sidlx_rmi_Simvocation__data *dptr =
    sidlx_rmi_Simvocation__get_data(self);
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
	sidl_MemAllocException_setNote(ex, "Realloc failed.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "Simvocation.buffer.alloc", _ex);
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


static void* prep_array(sidlx_rmi_Simvocation self, struct sidl__array* value, 
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
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
    return NULL;
  }

  isRow = destIsRow(value, ordering, dest_stride);

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
  impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse, _ex); SIDL_CHECK(*_ex);
  /*serilize isRow*/
  impl_sidlx_rmi_Simvocation_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
  /*serialize dimension*/
  impl_sidlx_rmi_Simvocation_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);
  /*serialize upper lower stride * dim */
  for(count = 0; count < l_dimen; ++count) {
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, (value->d_lower)[count], _ex); SIDL_CHECK(*_ex);
  }
  for(count = 0; count < l_dimen; ++count) {
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, (value->d_upper)[count], _ex); SIDL_CHECK(*_ex);
  }

  /*serialize data */
  /*Allocate enough buffer space for the array, and put the pointer in destFirst*/ 
  destFirst = buffer_alloc(self, *total_elements, obj_size, obj_per_elem, _ex); SIDL_CHECK(*_ex); 
  return destFirst;
 EXIT:
  return NULL;
}

static sidlx_rmi_Simsponse 
low_level_invoke( /* in */ sidlx_rmi_Simvocation self, 
		  /* out */ sidl_BaseInterface *_ex ) { 

  struct sidlx_rmi_Simvocation__data *dptr =
    sidlx_rmi_Simvocation__get_data(self);
  struct sidl_char__array* carray = NULL;
  if(dptr) {
    sidlx_rmi_Simsponse sponse = NULL;
    int lower = 0;
    int upper = (dptr->d_len)-1;
    int stride = 1;

    carray = sidl_char__array_borrow(dptr->d_buf,1,&lower, &upper,&stride);    
    sidlx_rmi_Socket_writestring(dptr->d_sock, dptr->d_len, carray, _ex); SIDL_CHECK(*_ex);
    sponse = sidlx_rmi_Simsponse__create(_ex); SIDL_CHECK(*_ex);
    sidlx_rmi_Simsponse_init(sponse, dptr->d_methodName, /*dptr->d_className,*/ dptr->d_objectID,
			     dptr->d_sock, _ex); SIDL_CHECK(*_ex);
    sidl_char__array_deleteRef(carray);
    return sponse;
  }
  SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "Simvocation has not been initialized");
 EXIT:
  if ( carray != NULL ) { 
    sidl_char__array_deleteRef(carray);
  }
  return NULL;
}

/* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation._load) */
    /* insert implementation here: sidlx.rmi.Simvocation._load (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation__ctor(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation._ctor) */
    /* insert implementation here: sidlx.rmi.Simvocation._ctor (constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation__ctor2(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation._ctor2) */
    /* Insert-Code-Here {sidlx.rmi.Simvocation._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation__dtor(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation._dtor) */
    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);
    if(dptr) {
      sidlx_rmi_Socket_deleteRef(dptr->d_sock,_ex); SIDL_CHECK(*_ex);
      sidl_String_free((void*)dptr->d_buf);
      sidl_String_free((void*)dptr->d_methodName);
      /*sidl_String_free((void*)dptr->d_className);*/
      sidl_String_free((void*)dptr->d_objectID);
      free((void*)dptr);
      sidlx_rmi_Simvocation__set_data(self, NULL);
    EXIT:
      return;
    }
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation._dtor) */
  }
}

/*
 * Method:  initCreate[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_initCreate"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_initCreate(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* className,
  /* in */ sidlx_rmi_Socket sock,
  /* in rarray[cookieLen] */ char* cookie,
  /* in */ int32_t cookieLen,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.initCreate) */
    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);
    
    int c_len = sidl_String_strlen(className);
    int h_len = 7+c_len;  /*CREATE:+ */
    int t_capacity = h_len + 128 + cookieLen; /* h_len+128 + cookieLen; */
    
    if (dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException,
                 "This invocation has already been init'ed!");
    } else {
      dptr = malloc(sizeof(struct sidlx_rmi_Simvocation__data));
      if(dptr == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "malloc failed.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initCreate", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;
      }
    }
        
    /* Make this inital space for the function call equal the length of
     * EXEC:objid:<objectid>:method:<methodName>:args:(args go here)
     * Make the space for args be equal to 128 bytes (just a guess) expands 
     to size
    */
    
    dptr->d_methodName = sidl_String_strdup("CREATE");
    dptr->d_sock = sock;
    sidlx_rmi_Socket_addRef(sock,_ex); SIDL_CHECK(*_ex);
    dptr->d_len = 0;
    dptr->d_capacity = t_capacity;
    dptr->d_buf = (char*)malloc(t_capacity);
    if(dptr->d_buf == NULL) {
      sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
      sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
      sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initCreate", _ex);
      *_ex = (sidl_BaseInterface)ex;
      goto EXIT;
    }
    dptr->d_objectID = NULL;
    sidlx_rmi_Simvocation__set_data(self, dptr);
    
    /* Write Cookie (if it exists) */
    if(cookieLen) {
      serialize(self,cookie, cookieLen, 1, _ex);
    }

    /* Initialize Header */
    serialize(self,"CREATE:", 7, 1, _ex);
    serialize(self, (char*)&c_len, 1, 4, _ex);
    serialize(self,className, c_len, 1, _ex);
    
    return;
  EXIT:
    /*Not really anything to clean up...*/
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.initCreate) */
  }
}

/*
 * Method:  initInvocation[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_initInvocation"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_initInvocation(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* methodName,
  /* in */ const char* objectid,
  /* in */ sidlx_rmi_Socket sock,
  /* in rarray[cookieLen] */ char* cookie,
  /* in */ int32_t cookieLen,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.initInvocation) */
    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);

    int m_len = sidl_String_strlen(methodName);
    int o_len = sidl_String_strlen(objectid);
    int t_capacity = 256 + cookieLen; /* h_len+128 (rounded up) + cookieLen */
    
    sidlx_rmi_Socket_addRef(sock,_ex); SIDL_CHECK(*_ex);
    
    if (dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException,
                 "This invocation has already been init'ed!");
    } else {
      dptr = malloc(sizeof(struct sidlx_rmi_Simvocation__data));
      if(dptr == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initInvocation", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;
      }
    }
        
    /* Make this inital space for the function call equal the length of
     * EXEC:objid:<objectid>:method:<methodName>:args:(args go here)
     * Make the space for args be equal to 128 bytes (just a guess) expands 
     to size
    */
    
    dptr->d_methodName = sidl_String_strdup(methodName);
    dptr->d_sock = sock;
    dptr->d_len = 0;
    dptr->d_capacity = t_capacity;
    dptr->d_buf = (char*)malloc(t_capacity);
    if(dptr->d_buf == NULL) {
      sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
      sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
      sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initInvocation", _ex);
      *_ex = (sidl_BaseInterface)ex;
      goto EXIT;
    }
    dptr->d_objectID = sidl_String_strdup(objectid);
    sidlx_rmi_Simvocation__set_data(self, dptr);
    
    /* Write Cookie (if it exists) */
    if(cookieLen) {
      serialize(self,cookie, cookieLen, 1, _ex);
    }

    /* Initialize Header */
    serialize(self,"EXEC:", 5, 1, _ex);
    serialize(self,"objid:", 6, 1, _ex);
    serialize(self,objectid, o_len, 1, _ex);
    serialize(self,":method:", 8, 1, _ex);
    serialize(self,methodName, m_len, 1, _ex);
    serialize(self,":args:", 6, 1, _ex);
    
    return;
  EXIT:
    /*Not really anything to clean up...*/
    return;


    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.initInvocation) */
  }
}

/*
 * Method:  initUnserialize[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_initUnserialize"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_initUnserialize(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* objectid,
  /* in */ sidlx_rmi_Socket sock,
  /* in rarray[cookieLen] */ char* cookie,
  /* in */ int32_t cookieLen,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.initUnserialize) */
    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);
    
    int o_len = sidl_String_strlen(objectid);
    int h_len = 7+o_len;  /*CREATE:+ */
    int t_capacity = h_len + 128 + cookieLen; /* h_len+128; */
    
    if (dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException,
                 "This invocation has already been init'ed!");
    } else {
      dptr = malloc(sizeof(struct sidlx_rmi_Simvocation__data));
      if(dptr == NULL) {
	sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
	sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
	sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initUnserialize", _ex);
	*_ex = (sidl_BaseInterface)ex;
	goto EXIT;
      }
    }
        
    /* Make this inital space for the function call equal the length of
     * EXEC:objid:<objectid>:method:<methodName>:args:(args go here)
     * Make the space for args be equal to 128 bytes (just a guess) expands 
     to size
    */
    
    dptr->d_methodName = sidl_String_strdup("SERIAL");
    dptr->d_sock = sock;
    sidlx_rmi_Socket_addRef(sock,_ex); SIDL_CHECK(*_ex);
    dptr->d_len = 0;
    dptr->d_capacity = t_capacity;
    dptr->d_buf = (char*)malloc(t_capacity);
    if(dptr->d_buf == NULL) {
      sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
      sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
      sidl_MemAllocException_add(ex, __FILE__, __LINE__, "sidlx.rmi.Simvocation.initUnserialize", _ex);
      *_ex = (sidl_BaseInterface)ex;
      goto EXIT;
    }
    dptr->d_objectID = NULL;
    sidlx_rmi_Simvocation__set_data(self, dptr);
    
    /* Write Cookie (if it exists) */
    if(cookieLen) {
      serialize(self,cookie, cookieLen, 1, _ex);
    }

    /* Initialize Header */
    serialize(self,"SERIAL:", 7, 1, _ex);
    serialize(self, (char*)&o_len, 1, 4, _ex);
    serialize(self, objectid, o_len, 1, _ex);

    return;
  EXIT:
    /*Not really anything to clean up...*/
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.initUnserialize) */
  }
}

/*
 * Method:  getMethodName[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_getMethodName"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sidlx_rmi_Simvocation_getMethodName(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.getMethodName) */
    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);
    if(!dptr) {
      SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "This invocation has not been initialized!") 
        }
    return sidl_String_strdup(dptr->d_methodName);
  EXIT:
    return NULL;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.getMethodName) */
  }
}

/*
 *  
 * this method is one of a triad.  Only one of which 
 * may be called, and it must the the last method called
 * in the object's lifetime.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_invokeMethod"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_Response
impl_sidlx_rmi_Simvocation_invokeMethod(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.invokeMethod) */

    struct sidlx_rmi_Simvocation__data *dptr =
      sidlx_rmi_Simvocation__get_data(self);
    struct sidl_char__array* carray = NULL;
    if(dptr) {
      sidlx_rmi_Simsponse sponse = NULL;
      sidl_rmi_Response ret = NULL;

      sponse = low_level_invoke( self, _ex); SIDL_CHECK(*_ex);
      sidlx_rmi_Simsponse_pullData(sponse, _ex); SIDL_CHECK(*_ex);
      ret = sidl_rmi_Response__cast(sponse, _ex); SIDL_CHECK(*_ex);
      sidlx_rmi_Simsponse_deleteRef(sponse, _ex); SIDL_CHECK(*_ex);
      return ret;
    }
    SIDL_THROW(*_ex, sidlx_rmi_UnrecoverableException, "Simvocation has not been initialized");
  EXIT:
    if ( carray != NULL ) { 
      sidl_char__array_deleteRef(carray);
    }
    return NULL;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.invokeMethod) */
  }
}

/*
 * This method is second of the triad.  It returns
 * a Ticket, from which a Response is later extracted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_invokeNonblocking"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_Ticket
impl_sidlx_rmi_Simvocation_invokeNonblocking(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.invokeNonblocking) */
    sidl_BaseInterface _throwaway_exception = NULL;
    sidlx_rmi_SimpleTicket t = NULL;
    sidlx_rmi_Simsponse sponse = NULL;
    sidl_rmi_Response r = NULL;
    sidl_rmi_Ticket T = NULL;

    sponse = low_level_invoke( self, _ex); SIDL_CHECK(*_ex);

    r = sidl_rmi_Response__cast(sponse, _ex); SIDL_CHECK(*_ex);
    sidlx_rmi_Simsponse_deleteRef(sponse, _ex); SIDL_CHECK(*_ex);
    t = sidlx_rmi_SimpleTicket__create(_ex); SIDL_CHECK(*_ex);
    sidlx_rmi_SimpleTicket_setResponse(t, r, _ex); SIDL_CHECK(*_ex);
    sidl_rmi_Response_deleteRef(r, _ex); SIDL_CHECK(*_ex);
    T = sidl_rmi_Ticket__cast(t, _ex); SIDL_CHECK(*_ex);
  EXIT:
    if (t) sidlx_rmi_SimpleTicket_deleteRef(t,&_throwaway_exception);
    return T;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.invokeNonblocking) */
  }
}

/*
 * This method is third of the triad.  It returns
 * and exception iff the invocation cannot be delivered
 * reliably.  It does not wait for the invocation to 
 * be acted upon and returns no values from the invocation.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_invokeOneWay"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_invokeOneWay(
  /* in */ sidlx_rmi_Simvocation self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.invokeOneWay) */
    /* this is an inherently blocking protocol, so we only emulate
     * nonblocking APIs, not actually doing nonblocking calls.*/
    sidl_rmi_Response r = NULL;
    r = sidlx_rmi_Simvocation_invokeMethod(self, _ex); SIDL_CHECK(*_ex);
    sidl_rmi_Response_deleteRef(r,_ex); SIDL_CHECK(*_ex);
  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.invokeOneWay) */
  }
}

/*
 * Method:  packBool[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packBool"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packBool(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ sidl_bool value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packBool) */
    if(value) {
      char x = 0xFF;
      serialize(self, &x, 1, 1, _ex); 
    }else{ 
      char x = 0;
      serialize(self, &x, 1, 1, _ex); 
    }
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packBool) */
  }
}

/*
 * Method:  packChar[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packChar"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packChar(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ char value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packChar) */
    serialize(self, &value, 1, 1, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packChar) */
  }
}

/*
 * Method:  packInt[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packInt"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packInt(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packInt) */
    /*int32_t x = htonl(value);*/
    serialize(self, (char*)&value, 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packInt) */
  }
}

/*
 * Method:  packLong[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packLong"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packLong(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ int64_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packLong) */
    serialize(self, (char*)&value, 1, 8, _ex); 
    /*short host = 1;
      short net = htons(host);

      if(host == net) {  This computer uses network byte ordering
      } else {           This computer does not use network byte ordering
      flip64(&value);
      serialize(self, (char*)&value, 8, _ex); 
      }
    */
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packLong) */
  }
}

/*
 * Method:  packOpaque[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packOpaque"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packOpaque(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ void* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packOpaque) */
    int64_t temp = (int64_t) (ptrdiff_t) value;
    serialize(self, (char*)&temp, 1, 8, _ex); 
    /*  short host = 1;
        short net = htons(host);
        int64_t temp = (int64_t) (ptrdiff_t) value;
        if(host == net) {  This computer uses network byte ordering
        } else {           This computer does not use network byte ordering
        flip64(&temp);
        serialize(self, (char*)&temp, 8, _ex); 
        }*/
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packOpaque) */
  }
}

/*
 * Method:  packFloat[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packFloat"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packFloat(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ float value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packFloat) */
    serialize(self, (char*)&value, 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packFloat) */
  }
}

/*
 * Method:  packDouble[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packDouble"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packDouble(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packDouble) */
    serialize(self, (char*)&value, 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packDouble) */
  }
}

/*
 * Method:  packFcomplex[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packFcomplex"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packFcomplex(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ struct sidl_fcomplex value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packFcomplex) */
    serialize(self, (char*)&(value.real), 1, 4, _ex); 
    serialize(self, (char*)&(value.imaginary), 1, 4, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packFcomplex) */
  }
}

/*
 * Method:  packDcomplex[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packDcomplex"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packDcomplex(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ struct sidl_dcomplex value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packDcomplex) */
    serialize(self, (char*)&(value.real), 1, 8, _ex); 
    serialize(self, (char*)&(value.imaginary), 1, 8, _ex); 
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packDcomplex) */
  }
}

/*
 * Method:  packString[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packString"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packString(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ const char* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packString) */
    int32_t len = sidl_String_strlen(value);
    /*int32_t f_len = htonl(len);*/
    serialize(self, (char*)&len, 1, 4, _ex);SIDL_CHECK(*_ex);
    serialize(self, value, len, 1, _ex);SIDL_CHECK(*_ex);
  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packString) */
  }
}

/*
 * Method:  packSerializable[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packSerializable"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packSerializable(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in */ sidl_io_Serializable value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packSerializable) */
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
      sidlx_rmi_Simvocation_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      sidlx_rmi_Simvocation_packString(self, NULL, NULL, _ex); SIDL_CHECK(*_ex);
      return;
    }

    if(is_remote) {
      sidlx_rmi_Simvocation_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      obj_url = sidl_io_Serializable__getURL(value, _ex);SIDL_CHECK(*_ex);
      sidlx_rmi_Simvocation_packString(self, NULL, obj_url, _ex); SIDL_CHECK(*_ex);
       
    } else {
      sidlx_rmi_Simvocation_packBool(self, NULL, is_remote, _ex); SIDL_CHECK(*_ex);
      ci = sidl_io_Serializable_getClassInfo(value,_ex); SIDL_CHECK(*_ex);
      class_name = sidl_ClassInfo_getName(ci,_ex); SIDL_CHECK(*_ex);
      sidlx_rmi_Simvocation_packString(self, NULL, class_name, _ex); SIDL_CHECK(*_ex);
      serial = sidl_io_Serializer__cast(self,_ex); SIDL_CHECK(*_ex);
      sidl_io_Serializable_packObj(value, serial, _ex); SIDL_CHECK(*_ex); 
    }

  EXIT:
    sidl_String_free(class_name);
    sidl_String_free(obj_url);
    if(ci) {sidl_ClassInfo_deleteRef(ci,&_throwaway_exception);}
    if(serial) {sidl_io_Serializer_deleteRef(serial, &_throwaway_exception);}
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packSerializable) */
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
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packBoolArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packBoolArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<bool> */ struct sidl_bool__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packBoolArray) */
    /*struct sidl__array* metadata = (struct sidl__array*) alue;*/
  
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

      /* Special case, cannot use memcpy here, and alignment is unnecessary*/
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
        /* Finished serializing data*/
      }
    }
  EXIT:
    return;
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packBoolArray) */
  }
}

/*
 * Method:  packCharArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packCharArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packCharArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<char> */ struct sidl_char__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packCharArray) */
    /*struct sidl__array* metadata = (struct sidl__array*) value;*/
  
    char* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 

    destFirst = (char*)prep_array(self, (struct sidl__array*)value, ordering, 
                                  dimen, reuse_array, 1,1,dest_stride, 
                                  lengths, current, &total_elements, _ex);
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
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packCharArray) */
  }
}

/*
 * Method:  packIntArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packIntArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packIntArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<int> */ struct sidl_int__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packIntArray) */
    /*struct sidl__array* metadata = (struct sidl__array*) value;*/
  
    int32_t* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (int32_t*)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array, 
                                     4,1,dest_stride, lengths, current, &total_elements, 
                                     _ex);
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
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packIntArray) */
  }
}

/*
 * Method:  packLongArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packLongArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packLongArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<long> */ struct sidl_long__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packLongArray) */
    
    int64_t* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (int64_t*)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array, 
                                     8,1,dest_stride, lengths, current, &total_elements, 
                                     _ex);
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

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packLongArray) */
  }
}

/*
 * Method:  packOpaqueArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packOpaqueArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packOpaqueArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<opaque> */ struct sidl_opaque__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packOpaqueArray) */

    void ** destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (void **)prep_array(self, (struct sidl__array*)value, ordering, 
                                     dimen, reuse_array, 
                                     8,1,dest_stride, lengths, current, &total_elements
                                     , _ex);
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

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packOpaqueArray) */
  }
}

/*
 * Method:  packFloatArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packFloatArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packFloatArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<float> */ struct sidl_float__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packFloatArray) */
  
    float* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 

    destFirst = (float*)prep_array(self, (struct sidl__array*)value, ordering, 
                                   dimen, reuse_array, 
                                   4,1,dest_stride, lengths, current, &total_elements,
                                   _ex);
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
  
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packFloatArray) */
  }
}

/*
 * Method:  packDoubleArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packDoubleArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packDoubleArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<double> */ struct sidl_double__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packDoubleArray) */
    
    double* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (double*)prep_array(self, (struct sidl__array*)value, ordering, 
                                    dimen, reuse_array, 
                                    8,1,dest_stride, lengths, current, &total_elements
                                    , _ex);
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
    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packDoubleArray) */
  }
}

/*
 * Method:  packFcomplexArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packFcomplexArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packFcomplexArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packFcomplexArray) */
    struct sidl_fcomplex* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (struct sidl_fcomplex*)prep_array(self, (struct sidl__array*)value, ordering, 
                                                  dimen, reuse_array, 
                                                  4,2,dest_stride, lengths, current, 
                                                  &total_elements, _ex);
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

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packFcomplexArray) */
  }
}

/*
 * Method:  packDcomplexArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packDcomplexArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packDcomplexArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packDcomplexArray) */

    struct sidl_dcomplex* destFirst = NULL;
    int32_t dest_stride[7];
    int32_t lengths[7];
    int32_t current[7];
    int64_t total_elements = 1; /*Total length (of the array, in elements)*/ 
    destFirst = (struct sidl_dcomplex*)prep_array(self, (struct sidl__array*)value, ordering, 
                                                  dimen, reuse_array, 8, 2, dest_stride, 
                                                  lengths, current, &total_elements, _ex);
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


    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packDcomplexArray) */
  }
}

/*
 * Method:  packStringArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packStringArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packStringArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<string> */ struct sidl_string__array* value,
  /* in */ int32_t ordering,
  /* in */ int32_t dimen,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packStringArray) */
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
      impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);     
      /*serilize isRow*/
      impl_sidlx_rmi_Simvocation_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
      /*serialize dimension*/
      impl_sidlx_rmi_Simvocation_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }

    isRow = destIsRow((struct sidl__array*)value, ordering, dest_stride);

    l_dimen = sidlArrayDim(value);
    srcFirst = (char**)sidl_char__array_first((struct sidl_char__array*)value);
    src_stride = ((struct sidl__array*)value)->d_stride;

    /*Figure out lengths (useful for copy)*/
    for(count=0; count<l_dimen; ++count) {
      int32_t len = sidlLength(value, count);
      lengths[count] = len;
      total_elements *= len;
      current[count] = 0;
    }

    /*serialize reuse bool*/
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);

    /*serialize lower upper*/
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_Simvocation_packInt(self, NULL,  sidl_string__array_lower(value,count), _ex); SIDL_CHECK(*_ex);
    }
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_Simvocation_packInt(self, NULL,  sidl_string__array_upper(value,count), _ex); SIDL_CHECK(*_ex);
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

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packStringArray) */
  }
}

/*
 * Method:  packGenericArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packGenericArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packGenericArray(
  /* in */ sidlx_rmi_Simvocation self,
  /* in */ const char* key,
  /* in array<> */ struct sidl__array* value,
  /* in */ sidl_bool reuse_array,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packGenericArray) */
    int32_t type = 0;
    if(value){
      type = sidl__array_type(value);
    } else {
      /* If the array is null, pass a null array and bail */
      impl_sidlx_rmi_Simvocation_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }
    /*serialize type */
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, type, _ex); SIDL_CHECK(*_ex);
    switch(type) {
    case sidl_bool_array:
      sidlx_rmi_Simvocation_packBoolArray(self,key,(struct sidl_bool__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_char_array:
      sidlx_rmi_Simvocation_packCharArray(self,key,(struct sidl_char__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_dcomplex_array:
      sidlx_rmi_Simvocation_packDcomplexArray(self,key,(struct sidl_dcomplex__array*) value, 
                                              0,0,reuse_array,_ex);
      break;
    case sidl_double_array:
      sidlx_rmi_Simvocation_packDoubleArray(self,key,(struct sidl_double__array*) value, 
                                            0,0,reuse_array,_ex);
      break;
    case sidl_fcomplex_array:
      sidlx_rmi_Simvocation_packFcomplexArray(self,key,(struct sidl_fcomplex__array*) value, 
                                              0,0,reuse_array,_ex);
      break;
    case sidl_float_array:
      sidlx_rmi_Simvocation_packFloatArray(self,key,(struct sidl_float__array*) value, 
                                           0,0,reuse_array,_ex);
      break;
    case sidl_int_array:
      sidlx_rmi_Simvocation_packIntArray(self,key,(struct sidl_int__array*) value, 
                                         0,0,reuse_array,_ex);
      break;
    case sidl_long_array:
      sidlx_rmi_Simvocation_packLongArray(self,key,(struct sidl_long__array*) value, 
                                          0,0,reuse_array,_ex);
      break;
    case sidl_opaque_array:
      sidlx_rmi_Simvocation_packOpaqueArray(self,key,(struct sidl_opaque__array*) value, 
                                            0,0,reuse_array,_ex);
      break;
    case sidl_string_array:
      sidlx_rmi_Simvocation_packStringArray(self,key,(struct sidl_string__array*) value, 
                                            0,0,reuse_array,_ex);
      break;
    case sidl_interface_array:
      sidlx_rmi_Simvocation_packSerializableArray(self,key,(struct sidl_io_Serializable__array*) value, 
                                                  0,0,reuse_array,_ex);
    }
  EXIT:
    return;

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packGenericArray) */
  }
}

/*
 * Method:  packSerializableArray[]
 */

#undef __FUNC__
#define __FUNC__ "impl_sidlx_rmi_Simvocation_packSerializableArray"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidlx_rmi_Simvocation_packSerializableArray(
  /* in */ sidlx_rmi_Simvocation self,
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
    /* DO-NOT-DELETE splicer.begin(sidlx.rmi.Simvocation.packSerializableArray) */
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
      impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
      /*serilize isRow*/
      impl_sidlx_rmi_Simvocation_packBool(self, NULL, FALSE, _ex); SIDL_CHECK(*_ex);
      /*serialize dimension*/
      impl_sidlx_rmi_Simvocation_packInt(self, NULL, 0, _ex); SIDL_CHECK(*_ex);
      return;
    }

    isRow = destIsRow((struct sidl__array*)value, ordering, dest_stride);
   
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
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, reuse_array, _ex); SIDL_CHECK(*_ex);
    /*serilize isRow*/
    impl_sidlx_rmi_Simvocation_packBool(self, NULL, isRow, _ex); SIDL_CHECK(*_ex);
    /*serialize dimension*/
    impl_sidlx_rmi_Simvocation_packInt(self, NULL, l_dimen, _ex); SIDL_CHECK(*_ex);

    /*serialize upper lower stride * dim */
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_Simvocation_packInt(self, NULL,  sidl_io_Serializable__array_lower(value,count), _ex); SIDL_CHECK(*_ex);
    }
    for(count = 0; count < l_dimen; ++count) {
      impl_sidlx_rmi_Simvocation_packInt(self, NULL,  sidl_io_Serializable__array_upper(value,count), _ex); SIDL_CHECK(*_ex);
    }
    /* Serialization of stride is unessecary, it is known from above info*/

    /*serialize data */
    /*Allocate enough buffer space for the array, and put the pointer in destFirst*/ 
  
    if(total_elements > 0) {
      do {
        toCast = (sidl_BaseInterface) *srcFirst;
        toSerialize = sidl_io_Serializable__cast(toCast,_ex); SIDL_CHECK(*_ex);
        sidlx_rmi_Simvocation_packSerializable(self, NULL, toSerialize, _ex); SIDL_CHECK(*_ex);
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

    /* DO-NOT-DELETE splicer.end(sidlx.rmi.Simvocation.packSerializableArray) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

