/*
 * File:          synch_RegOut_IOR.h
 * Symbol:        synch.RegOut-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for synch.RegOut
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_synch_RegOut_IOR_h
#define included_synch_RegOut_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
#endif
#ifndef included_synch_ResultType_IOR_h
#include "synch_ResultType_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "synch.RegOut" (version 0.1)
 * 
 * Regression test output class. 
 */

struct synch_RegOut__array;
struct synch_RegOut__object;
struct synch_RegOut__sepv;

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

struct synch_RegOut__sepv {
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
  /* Methods introduced in synch.RegOut-v0.1 */
  struct synch_RegOut__object* (*f_getInstance)(
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method entry point vector.
 */

struct synch_RegOut__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in synch.RegOut-v0.1 */
  void (*f_setExpectations)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t numparts,
    /* out */ struct sidl_BaseInterface__object **_ex);
  int32_t (*f_getCurrentPart)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_startPart)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_endPart)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* in */ int64_t res,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_writeComment)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* comment,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_forceFailure)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_close)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method pre hooks entry point vector.
 */

struct synch_RegOut__pre_epv {
  void (*f_setExpectations_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t numparts,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_getCurrentPart_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_startPart_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_endPart_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* in */ int64_t res,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_writeComment_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* comment,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_forceFailure_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_close_pre)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method post hooks entry point vector.
 */

struct synch_RegOut__post_epv {
  void (*f_setExpectations_post)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t numparts,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_getCurrentPart_post)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t _retval,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_startPart_post)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_endPart_post)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ int32_t part,
    /* in */ int64_t res,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_writeComment_post)(
    /* in */ struct synch_RegOut__object* self,
    /* in */ const char* comment,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_forceFailure_post)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_close_post)(
    /* in */ struct synch_RegOut__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the static method pre hooks entry point vector.
 */

struct synch_RegOut__pre_sepv {
  void (*f_getInstance_pre)(
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the static method post hooks entry point vector.
 */

struct synch_RegOut__post_sepv {
  void (*f_getInstance_post)(
    /* in */ struct synch_RegOut__object* _retval,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct synch_RegOut__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct synch_RegOut__object {
  struct sidl_BaseClass__object d_sidl_baseclass;
  struct synch_RegOut__epv*     d_epv;
  struct synch_RegOut__cstats   d_cstats;
  void*                         d_data;
};

struct synch_RegOut__external {
  struct synch_RegOut__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct synch_RegOut__sepv*
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

const struct synch_RegOut__external*
synch_RegOut__externals(void);

extern struct synch_RegOut__object*
synch_RegOut__createObject(void* ddata,struct sidl_BaseInterface__object ** 
  _ex);

extern struct synch_RegOut__sepv*
synch_RegOut__getStaticEPV(void);


extern struct synch_RegOut__sepv*
synch_RegOut__getTypeStaticEPV(int type);

extern void synch_RegOut__init(
  struct synch_RegOut__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void synch_RegOut__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct synch_RegOut__epv **s_arg_epv__synch_regout,
  struct synch_RegOut__epv **s_arg_epv_hooks__synch_regout);

extern void synch_RegOut__fini(
  struct synch_RegOut__object* self, struct sidl_BaseInterface__object ** _ex);

extern void synch_RegOut__IOR_version(int32_t *major, int32_t *minor);

/*
 * Define static structure options.
 */

static const int s_SEPV_SYNCH_REGOUT_BASE = 0;
static const int s_SEPV_SYNCH_REGOUT_CONTRACTS = 1;
static const int s_SEPV_SYNCH_REGOUT_HOOKS = 2;

struct sidl_BaseInterface__object* 
  skel_synch_RegOut_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  struct sidl_BaseInterface__object * *_ex);
struct synch_RegOut__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
