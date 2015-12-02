/*
 * File:          sidlx_rmi_Simvocation_IOR.h
 * Symbol:        sidlx.rmi.Simvocation-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for sidlx.rmi.Simvocation
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_Simvocation_IOR_h
#define included_sidlx_rmi_Simvocation_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
#endif
#ifndef included_sidl_io_Serializer_IOR_h
#include "sidl_io_Serializer_IOR.h"
#endif
#ifndef included_sidl_rmi_Invocation_IOR_h
#include "sidl_rmi_Invocation_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidlx.rmi.Simvocation" (version 0.1)
 * 
 * implementation of Invocation using the Simhandle Protocol (written by Jim)
 */

struct sidlx_rmi_Simvocation__array;
struct sidlx_rmi_Simvocation__object;

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
struct sidl_rmi_Call__array;
struct sidl_rmi_Call__object;
struct sidl_rmi_Response__array;
struct sidl_rmi_Response__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;
struct sidl_rmi_Ticket__array;
struct sidl_rmi_Ticket__object;
struct sidlx_rmi_Socket__array;
struct sidlx_rmi_Socket__object;

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_Simvocation__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidl.io.Serializer-v0.9.17 */
  void (*f_packBool)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ sidl_bool value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packChar)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ char value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packInt)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ int32_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLong)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ int64_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaque)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ void* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloat)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ float value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDouble)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ double value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplex)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_fcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplex)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_dcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packString)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ const char* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializable)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_io_Serializable__object* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packBoolArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<bool> */ struct sidl_bool__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packCharArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<char> */ struct sidl_char__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packIntArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<int> */ struct sidl_int__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLongArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<long> */ struct sidl_long__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaqueArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<opaque> */ struct sidl_opaque__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloatArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<float> */ struct sidl_float__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDoubleArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<double> */ struct sidl_double__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplexArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplexArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packStringArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<string> */ struct sidl_string__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packGenericArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<> */ struct sidl__array* value,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializableArray)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* key,
    /* in array<sidl.io.Serializable> */ struct sidl_io_Serializable__array* 
      value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.rmi.Invocation-v0.9.17 */
  struct sidl_rmi_Response__object* (*f_invokeMethod)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_rmi_Ticket__object* (*f_invokeNonblocking)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_invokeOneWay)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidlx.rmi.Simvocation-v0.1 */
  void (*f_initCreate)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* className,
    /* in */ struct sidlx_rmi_Socket__object* sock,
    /* in rarray[cookieLen] */ struct sidl_char__array* cookie,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_initInvocation)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* methodName,
    /* in */ const char* objectid,
    /* in */ struct sidlx_rmi_Socket__object* sock,
    /* in rarray[cookieLen] */ struct sidl_char__array* cookie,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_initUnserialize)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* in */ const char* objectid,
    /* in */ struct sidlx_rmi_Socket__object* sock,
    /* in rarray[cookieLen] */ struct sidl_char__array* cookie,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getMethodName)(
    /* in */ struct sidlx_rmi_Simvocation__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_Simvocation__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_Simvocation__object {
  struct sidl_BaseClass__object      d_sidl_baseclass;
  struct sidl_io_Serializer__object  d_sidl_io_serializer;
  struct sidl_rmi_Invocation__object d_sidl_rmi_invocation;
  struct sidlx_rmi_Simvocation__epv* d_epv;
  void*                              d_data;
};

struct sidlx_rmi_Simvocation__external {
  struct sidlx_rmi_Simvocation__object*
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

const struct sidlx_rmi_Simvocation__external*
sidlx_rmi_Simvocation__externals(void);

extern struct sidlx_rmi_Simvocation__object*
sidlx_rmi_Simvocation__createObject(void* ddata,struct 
  sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_Simvocation__init(
  struct sidlx_rmi_Simvocation__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_Simvocation__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_io_Serializer__epv **s_arg_epv__sidl_io_serializer,
  struct sidl_rmi_Invocation__epv **s_arg_epv__sidl_rmi_invocation,
  struct sidlx_rmi_Simvocation__epv **s_arg_epv__sidlx_rmi_simvocation);

extern void sidlx_rmi_Simvocation__fini(
  struct sidlx_rmi_Simvocation__object* self, struct sidl_BaseInterface__object 
    ** _ex);

extern void sidlx_rmi_Simvocation__IOR_version(int32_t *major, int32_t *minor);

struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_Simvocation_fconnect_sidlx_rmi_Socket(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_io_Serializable__object* 
  skel_sidlx_rmi_Simvocation_fconnect_sidl_io_Serializable(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_Simvocation_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_Simvocation__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
