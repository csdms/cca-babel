/*
 * File:          sidlx_rmi_Settings_IOR.h
 * Symbol:        sidlx.rmi.Settings-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for sidlx.rmi.Settings
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidlx_rmi_Settings_IOR_h
#define included_sidlx_rmi_Settings_IOR_h

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
 * Symbol "sidlx.rmi.Settings" (version 0.1)
 * 
 * Low level settings
 */

struct sidlx_rmi_Settings__array;
struct sidlx_rmi_Settings__object;
struct sidlx_rmi_Settings__sepv;

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

/*
 * Declare the static method entry point vector.
 */

struct sidlx_rmi_Settings__sepv {
  /* Implicit builtin methods */
  /* 0 */
  /* 1 */
  /* 2 */
  /* 3 */
  /* 4 */
  /* 5 */
  /* 6 */
  void (*f__set_hooks_static)(
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts_static)(
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats_static)(
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  /* 10 */
  /* 11 */
  /* 12 */
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidlx.rmi.Settings-v0.1 */
  int32_t (*f_getMaxAcceptRetries)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setMaxAcceptRetries)(
    /* in */ int32_t retries,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int64_t (*f_getAcceptRetryInitialSleep)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setAcceptRetryInitialSleep)(
    /* in */ int64_t usecs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int32_t (*f_getMaxConnectRetries)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setMaxConnectRetries)(
    /* in */ int32_t retries,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int64_t (*f_getConnectRetryInitialSleep)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setConnectRetryInitialSleep)(
    /* in */ int64_t usecs,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method entry point vector.
 */

struct sidlx_rmi_Settings__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidlx_rmi_Settings__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidlx.rmi.Settings-v0.1 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidlx_rmi_Settings__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidlx_rmi_Settings__object {
  struct sidl_BaseClass__object   d_sidl_baseclass;
  struct sidlx_rmi_Settings__epv* d_epv;
  void*                           d_data;
};

struct sidlx_rmi_Settings__external {
  struct sidlx_rmi_Settings__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct sidlx_rmi_Settings__sepv*
  (*getStaticEPV)(void);
  struct sidl_BaseClass__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct sidlx_rmi_Settings__external*
sidlx_rmi_Settings__externals(void);

extern struct sidlx_rmi_Settings__object*
sidlx_rmi_Settings__createObject(void* ddata,struct sidl_BaseInterface__object 
  ** _ex);

extern struct sidlx_rmi_Settings__sepv*
sidlx_rmi_Settings__getStaticEPV(void);

extern void sidlx_rmi_Settings__init(
  struct sidlx_rmi_Settings__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidlx_rmi_Settings__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidlx_rmi_Settings__epv **s_arg_epv__sidlx_rmi_settings);

extern void sidlx_rmi_Settings__fini(
  struct sidlx_rmi_Settings__object* self, struct sidl_BaseInterface__object ** 
    _ex);

extern void sidlx_rmi_Settings__IOR_version(int32_t *major, int32_t *minor);

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_Settings_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidlx_rmi_Settings__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
