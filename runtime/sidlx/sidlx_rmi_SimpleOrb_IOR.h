/*
 * File:          sidlx_rmi_SimpleOrb_IOR.h
 * Symbol:        sidlx.rmi.SimpleOrb-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Description:   Intermediate Object Representation for sidlx.rmi.SimpleOrb
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_SimpleOrb_IOR_h
#define included_sidlx_rmi_SimpleOrb_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidlx_rmi_SimpleServer_IOR_h
#include "sidlx_rmi_SimpleServer_IOR.h"
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
 * Symbol "sidlx.rmi.SimpleOrb" (version 0.1)
 * 
 * A simple example orb, using the simhandle protocol (written by Jim)
 */

struct sidlx_rmi_SimpleOrb__array;
struct sidlx_rmi_SimpleOrb__object;

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
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;
struct sidlx_rmi_Socket__array;
struct sidlx_rmi_Socket__object;

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_SimpleOrb__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidl.rmi.ServerInfo-v0.9.17 */
  char* (*f_getServerURL)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* objID,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_isLocalObject)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ const char* url,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_io_Serializable__array* (*f_getExceptions)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidlx.rmi.SimpleServer-v0.1 */
  void (*f_setMaxThreadPool)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t max,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_requestPort)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t port,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_requestPortInRange)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t minport,
    /* in */ int32_t maxport,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_requestLocalPort)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t port,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_requestLocalPortInRange)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t minport,
    /* in */ int32_t maxport,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int32_t (*f_getPort)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getServerName)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int64_t (*f_run)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_shutdown)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_shutdownNoWait)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isRunning)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_serviceRequest)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ struct sidlx_rmi_Socket__object* sock,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidlx.rmi.SimpleOrb-v0.1 */
  void (*f_setCookie)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in rarray[len] */ struct sidl_char__array* cookie,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setNumSecurityRetries)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* in */ int32_t retries,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getProtocol)(
    /* in */ struct sidlx_rmi_SimpleOrb__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_SimpleOrb__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_SimpleOrb__object {
  struct sidlx_rmi_SimpleServer__object d_sidlx_rmi_simpleserver;
  struct sidlx_rmi_SimpleOrb__epv*      d_epv;
  void*                                 d_data;
};

struct sidlx_rmi_SimpleOrb__external {
  struct sidlx_rmi_SimpleOrb__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct sidlx_rmi_SimpleServer__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct sidlx_rmi_SimpleOrb__external*
sidlx_rmi_SimpleOrb__externals(void);

extern struct sidlx_rmi_SimpleOrb__object*
sidlx_rmi_SimpleOrb__createObject(void* ddata,struct sidl_BaseInterface__object 
  ** _ex);

extern void sidlx_rmi_SimpleOrb__init(
  struct sidlx_rmi_SimpleOrb__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_SimpleOrb__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_rmi_ServerInfo__epv **s_arg_epv__sidl_rmi_serverinfo,
  struct sidlx_rmi_SimpleServer__epv **s_arg_epv__sidlx_rmi_simpleserver,
  struct sidlx_rmi_SimpleOrb__epv **s_arg_epv__sidlx_rmi_simpleorb);

extern void sidlx_rmi_SimpleOrb__fini(
  struct sidlx_rmi_SimpleOrb__object* self, struct sidl_BaseInterface__object 
    ** _ex);

extern void sidlx_rmi_SimpleOrb__IOR_version(int32_t *major, int32_t *minor);

struct sidlx_rmi_Socket__object* 
  skel_sidlx_rmi_SimpleOrb_fconnect_sidlx_rmi_Socket(const char* url, sidl_bool 
  ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_SimpleOrb_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_SimpleOrb__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
