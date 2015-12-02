/*
 * File:          cons_C_IOR.h
 * Symbol:        cons.C-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for cons.C
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_cons_C_IOR_h
#define included_cons_C_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_cons_B_IOR_h
#include "cons_B_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbol "cons.C" (version 1.0)
 */

struct cons_C__array;
struct cons_C__object;

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
 * Declare the method entry point vector.
 */

struct cons_C__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct cons_C__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct cons_C__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct cons_C__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct cons_C__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct cons_C__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct cons_C__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct cons_C__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct cons_C__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in cons.A-v1.0 */
  void (*f_init)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_destruct)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in cons.B-v1.0 */
  /* Methods introduced in cons.C-v1.0 */
};

/*
 * Declare the method pre hooks entry point vector.
 */

struct cons_C__pre_epv {
  void (*f_init_pre)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_destruct_pre)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method post hooks entry point vector.
 */

struct cons_C__post_epv {
  void (*f_init_post)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_destruct_post)(
    /* in */ struct cons_C__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the controls and statistics structure.
 */


struct cons_C__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct cons_C__object {
  struct cons_B__object d_cons_b;
  struct cons_C__epv*   d_epv;
  struct cons_C__cstats d_cstats;
  void*                 d_data;
};

struct cons_C__external {
  struct cons_C__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct cons_B__epv*(*getSuperEPV)(void);
  int d_ior_major_version;
  int d_ior_minor_version;
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct cons_C__external*
cons_C__externals(void);

extern struct cons_C__object*
cons_C__createObject(void* ddata,struct sidl_BaseInterface__object ** _ex);

extern void cons_C__init(
  struct cons_C__object* self, void* ddata, struct sidl_BaseInterface__object 
    ** _ex);

extern void cons_C__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct cons_A__epv **s_arg_epv__cons_a,
  struct cons_A__epv **s_arg_epv_hooks__cons_a,
  struct cons_B__epv **s_arg_epv__cons_b,
  struct cons_B__epv **s_arg_epv_hooks__cons_b,
  struct cons_C__epv **s_arg_epv__cons_c,
  struct cons_C__epv **s_arg_epv_hooks__cons_c);

extern void cons_C__fini(
  struct cons_C__object* self, struct sidl_BaseInterface__object ** _ex);

extern void cons_C__IOR_version(int32_t *major, int32_t *minor);

struct sidl_BaseInterface__object* skel_cons_C_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct cons_C__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
