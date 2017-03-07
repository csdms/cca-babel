/*
 * File:          sidlx_rmi_RecoverableException_IOR.h
 * Symbol:        sidlx.rmi.RecoverableException-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Intermediate Object Representation for sidlx.rmi.RecoverableException
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_RecoverableException_IOR_h
#define included_sidlx_rmi_RecoverableException_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_rmi_ProtocolException_IOR_h
#include "sidl_rmi_ProtocolException_IOR.h"
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
 * Symbol "sidlx.rmi.RecoverableException" (version 0.1)
 * 
 *  EXCEPTION DEFINITIONS FOR SIMHANDLE BELOW THIS LINE------------------------------
 */

struct sidlx_rmi_RecoverableException__array;
struct sidlx_rmi_RecoverableException__object;

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
struct sidl_io_Deserializer__array;
struct sidl_io_Deserializer__object;
struct sidl_io_Serializer__array;
struct sidl_io_Serializer__object;
struct sidl_rmi_Call__array;
struct sidl_rmi_Call__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_RecoverableException__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidl.io.Serializable-v0.9.17 */
  void (*f_packObj)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ struct sidl_io_Serializer__object* ser,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackObj)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ struct sidl_io_Deserializer__object* des,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseException-v0.9.17 */
  char* (*f_getNote)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setNote)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* message,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getTrace)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_addLine)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* traceline,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_add)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ const char* filename,
    /* in */ int32_t lineno,
    /* in */ const char* methodname,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.SIDLException-v0.9.17 */
  /* Methods introduced in sidl.RuntimeException-v0.9.17 */
  /* Methods introduced in sidl.io.IOException-v0.9.17 */
  /* Methods introduced in sidl.rmi.NetworkException-v0.9.17 */
  int32_t (*f_getHopCount)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setErrno)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* in */ int32_t err,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int32_t (*f_getErrno)(
    /* in */ struct sidlx_rmi_RecoverableException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.rmi.ProtocolException-v0.9.17 */
  /* Methods introduced in sidlx.rmi.RecoverableException-v0.1 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_RecoverableException__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_RecoverableException__object {
  struct sidl_rmi_ProtocolException__object   d_sidl_rmi_protocolexception;
  struct sidlx_rmi_RecoverableException__epv* d_epv;
  void*                                       d_data;
};

struct sidlx_rmi_RecoverableException__external {
  struct sidlx_rmi_RecoverableException__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct sidl_rmi_ProtocolException__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct sidlx_rmi_RecoverableException__external*
sidlx_rmi_RecoverableException__externals(void);

extern struct sidlx_rmi_RecoverableException__object*
sidlx_rmi_RecoverableException__createObject(void* ddata,struct 
  sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_RecoverableException__init(
  struct sidlx_rmi_RecoverableException__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_RecoverableException__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_BaseException__epv **s_arg_epv__sidl_baseexception,
  struct sidl_io_Serializable__epv **s_arg_epv__sidl_io_serializable,
  struct sidl_SIDLException__epv **s_arg_epv__sidl_sidlexception,
  struct sidl_RuntimeException__epv **s_arg_epv__sidl_runtimeexception,
  struct sidl_io_IOException__epv **s_arg_epv__sidl_io_ioexception,
  struct sidl_rmi_NetworkException__epv **s_arg_epv__sidl_rmi_networkexception,
  struct sidl_rmi_ProtocolException__epv 
    **s_arg_epv__sidl_rmi_protocolexception,
  struct sidlx_rmi_RecoverableException__epv 
    **s_arg_epv__sidlx_rmi_recoverableexception);

extern void sidlx_rmi_RecoverableException__fini(
  struct sidlx_rmi_RecoverableException__object* self, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_RecoverableException__IOR_version(int32_t *major, int32_t 
  *minor);

struct sidl_io_Deserializer__object* 
  skel_sidlx_rmi_RecoverableException_fconnect_sidl_io_Deserializer(const char* 
  url, sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_io_Serializer__object* 
  skel_sidlx_rmi_RecoverableException_fconnect_sidl_io_Serializer(const char* 
  url, sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_RecoverableException_fconnect_sidl_BaseInterface(const char* 
  url, sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_RecoverableException__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
