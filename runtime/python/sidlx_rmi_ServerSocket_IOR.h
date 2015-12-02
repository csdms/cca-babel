/*
 * File:          sidlx_rmi_ServerSocket_IOR.h
 * Symbol:        sidlx.rmi.ServerSocket-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for sidlx.rmi.ServerSocket
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_ServerSocket_IOR_h
#define included_sidlx_rmi_ServerSocket_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "sidlx.rmi.ServerSocket" (version 0.1)
 * 
 * Automatically sets up a port for listening for new connections
 */

struct sidlx_rmi_ServerSocket__array;
struct sidlx_rmi_ServerSocket__object;

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
struct sidl_rmi_Call__array;
struct sidl_rmi_Call__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;
struct sidlx_rmi_Socket__array;
struct sidlx_rmi_Socket__object;

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_ServerSocket__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidlx.rmi.ServerSocket-v0.1 */
  int32_t (*f_init)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* in */ int32_t port,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidlx_rmi_Socket__object* (*f_accept)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int32_t (*f_close)(
    /* in */ struct sidlx_rmi_ServerSocket__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_ServerSocket__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_ServerSocket__object {
  struct sidl_BaseClass__object       d_sidl_baseclass;
  struct sidlx_rmi_ServerSocket__epv* d_epv;
  void*                               d_data;
};

struct sidlx_rmi_ServerSocket__external {
  struct sidlx_rmi_ServerSocket__object*
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

const struct sidlx_rmi_ServerSocket__external*
sidlx_rmi_ServerSocket__externals(void);

extern struct sidlx_rmi_ServerSocket__object*
sidlx_rmi_ServerSocket__createObject(void* ddata,struct 
  sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_ServerSocket__init(
  struct sidlx_rmi_ServerSocket__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_ServerSocket__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidlx_rmi_ServerSocket__epv **s_arg_epv__sidlx_rmi_serversocket);

extern void sidlx_rmi_ServerSocket__fini(
  struct sidlx_rmi_ServerSocket__object* self, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_ServerSocket__IOR_version(int32_t *major, int32_t *minor);

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_ServerSocket_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_ServerSocket__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
