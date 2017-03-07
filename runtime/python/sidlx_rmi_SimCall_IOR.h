/*
 * File:          sidlx_rmi_SimCall_IOR.h
 * Symbol:        sidlx.rmi.SimCall-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Intermediate Object Representation for sidlx.rmi.SimCall
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_SimCall_IOR_h
#define included_sidlx_rmi_SimCall_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
#endif
#ifndef included_sidl_io_Deserializer_IOR_h
#include "sidl_io_Deserializer_IOR.h"
#endif
#ifndef included_sidl_rmi_Call_IOR_h
#include "sidl_rmi_Call_IOR.h"
#endif
#ifndef included_sidlx_rmi_CallType_IOR_h
#include "sidlx_rmi_CallType_IOR.h"
#endif

#ifndef VAR_UNUSED
#ifdef __GNUC__
#define VAR_UNUSED __attribute__ ((__unused__))
#else
#define VAR_UNUSED
#endif /* __GNUC__ */
#endif /* VAR_UNUSED */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidlx.rmi.SimCall" (version 0.1)
 * 
 * This type is created on the server side to get inargs off the network and 
 * pass them into exec.	
 */

struct sidlx_rmi_SimCall__array;
struct sidlx_rmi_SimCall__object;

/*
 * Forward references for external classes and interfaces.
 */

struct sidl_BaseException__array;
struct sidl_BaseException__object;
struct sidl_BaseInterface__array;
struct sidl_BaseInterface__object;
struct sidl_ClassInfo__array;
struct sidl_ClassInfo__object;
struct sidl_RuntimeException__array;
struct sidl_RuntimeException__object;
struct sidl_io_Serializable__array;
struct sidl_io_Serializable__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;
struct sidlx_rmi_Socket__array;
struct sidlx_rmi_Socket__object;
struct sidlx_rmi_UnauthorizedCallException__array;
struct sidlx_rmi_UnauthorizedCallException__object;

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_SimCall__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidl.io.Deserializer-v0.9.17 */
  void (*f_unpackBool)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ sidl_bool* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackChar)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ char* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackInt)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ int32_t* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackLong)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ int64_t* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackOpaque)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ void** value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackFloat)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ float* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackDouble)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ double* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackFcomplex)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ struct sidl_fcomplex* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackDcomplex)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ struct sidl_dcomplex* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackString)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ char** value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackSerializable)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout */ struct sidl_io_Serializable__object** value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackBoolArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<bool> */ struct sidl_bool__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackCharArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<char> */ struct sidl_char__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackIntArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<int> */ struct sidl_int__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackLongArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<long> */ struct sidl_long__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackOpaqueArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<opaque> */ struct sidl_opaque__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackFloatArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<float> */ struct sidl_float__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackDoubleArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<double> */ struct sidl_double__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackFcomplexArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<fcomplex> */ struct sidl_fcomplex__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackDcomplexArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<dcomplex> */ struct sidl_dcomplex__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackStringArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<string> */ struct sidl_string__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackGenericArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<> */ struct sidl__array** value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackSerializableArray)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ const char* key,
    /* inout array<sidl.io.Serializable> */ struct 
      sidl_io_Serializable__array** value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool isRarray,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.rmi.Call-v0.9.17 */
  /* Methods introduced in sidlx.rmi.SimCall-v0.1 */
  void (*f_init)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* in */ struct sidlx_rmi_Socket__object* sock,
    /* in rarray[len] */ struct sidl_char__array* cookie,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getMethodName)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getObjectID)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int64_t (*f_getCallType)(
    /* in */ struct sidlx_rmi_SimCall__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_SimCall__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_SimCall__object {
  struct sidl_BaseClass__object       d_sidl_baseclass;
  struct sidl_io_Deserializer__object d_sidl_io_deserializer;
  struct sidl_rmi_Call__object        d_sidl_rmi_call;
  struct sidlx_rmi_SimCall__epv*      d_epv;
  void*                               d_data;
};

struct sidlx_rmi_SimCall__external {
  struct sidlx_rmi_SimCall__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct sidl_BaseClass__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct sidlx_rmi_SimCall__external*
sidlx_rmi_SimCall__externals(void);

extern struct sidlx_rmi_SimCall__object*
sidlx_rmi_SimCall__createObject(void* ddata,struct sidl_BaseInterface__object 
  ** _ex);

extern void sidlx_rmi_SimCall__init(
  struct sidlx_rmi_SimCall__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_SimCall__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_io_Deserializer__epv **s_arg_epv__sidl_io_deserializer,
  struct sidl_rmi_Call__epv **s_arg_epv__sidl_rmi_call,
  struct sidlx_rmi_SimCall__epv **s_arg_epv__sidlx_rmi_simcall);

extern void sidlx_rmi_SimCall__fini(
  struct sidlx_rmi_SimCall__object* self, struct sidl_BaseInterface__object ** 
    _ex);

extern void sidlx_rmi_SimCall__IOR_version(int32_t *major, int32_t *minor);

struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_SimCall_fconnect_sidlx_rmi_Socket(const char* url, sidl_bool 
  ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimCall_fconnect_sidl_BaseInterface(const char* url, sidl_bool 
  ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_io_Serializable__object* 
  skel_sidlx_rmi_SimCall_fconnect_sidl_io_Serializable(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_SimCall__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
