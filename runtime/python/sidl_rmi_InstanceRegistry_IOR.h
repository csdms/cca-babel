/*
 * File:          sidl_rmi_InstanceRegistry_IOR.h
 * Symbol:        sidl.rmi.InstanceRegistry-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.rmi.InstanceRegistry
 * 
 * Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidl_rmi_InstanceRegistry_IOR_h
#define included_sidl_rmi_InstanceRegistry_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseClass_IOR_h
#include "sidl_BaseClass_IOR.h"
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
 * Symbol "sidl.rmi.InstanceRegistry" (version 0.9.17)
 * 
 *  
 * This singleton class is implemented by Babel's runtime for RMI
 * libraries to invoke methods on server objects.  It maps
 * objectID strings to sidl_BaseClass objects and vice-versa.
 * 
 * The InstanceRegistry creates and returns a unique string when a
 * new object is added to the registry.  When an object's refcount
 * reaches 0 and it is collected, it is removed from the Instance
 * Registry.
 * 
 * Objects are added to the registry in 3 ways:
 * 1) Added to the server's registry when an object is
 * create[Remote]'d.
 * 2) Implicity added to the local registry when an object is
 * passed as an argument in a remote call.
 * 3) A user may manually add a reference to the local registry
 * for publishing purposes.  The user hsould keep a reference
 * to the object.  Currently, the user cannot provide their own
 * objectID, this capability should probably be added.
 */

struct sidl_rmi_InstanceRegistry__array;
struct sidl_rmi_InstanceRegistry__object;
struct sidl_rmi_InstanceRegistry__sepv;

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

struct sidl_rmi_InstanceRegistry__sepv {
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
  /* Methods introduced in sidl.rmi.InstanceRegistry-v0.9.17 */
  char* (*f_registerInstance)(
    /* in */ struct sidl_BaseClass__object* instance,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_registerInstanceByString)(
    /* in */ struct sidl_BaseClass__object* instance,
    /* in */ const char* instanceID,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_BaseClass__object* (*f_getInstanceByString)(
    /* in */ const char* instanceID,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getInstanceByClass)(
    /* in */ struct sidl_BaseClass__object* instance,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_BaseClass__object* (*f_removeInstanceByString)(
    /* in */ const char* instanceID,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_removeInstanceByClass)(
    /* in */ struct sidl_BaseClass__object* instance,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Declare the method entry point vector.
 */

struct sidl_rmi_InstanceRegistry__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 9 */
  void (*f__ctor)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 10 */
  void (*f__ctor2)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 11 */
  void (*f__dtor)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 12 */
  void (*f__load)(
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidl_rmi_InstanceRegistry__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseClass-v0.9.17 */
  /* Methods introduced in sidl.rmi.InstanceRegistry-v0.9.17 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidl_rmi_InstanceRegistry__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidl_rmi_InstanceRegistry__object {
  struct sidl_BaseClass__object          d_sidl_baseclass;
  struct sidl_rmi_InstanceRegistry__epv* d_epv;
  void*                                  d_data;
};

struct sidl_rmi_InstanceRegistry__external {
  struct sidl_rmi_InstanceRegistry__object*
  (*createObject)(void* ddata, struct sidl_BaseInterface__object **_ex);

  struct sidl_rmi_InstanceRegistry__sepv*
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

const struct sidl_rmi_InstanceRegistry__external*
sidl_rmi_InstanceRegistry__externals(void);

extern struct sidl_rmi_InstanceRegistry__object*
sidl_rmi_InstanceRegistry__createObject(void* ddata,struct 
  sidl_BaseInterface__object ** _ex);

extern struct sidl_rmi_InstanceRegistry__sepv*
sidl_rmi_InstanceRegistry__getStaticEPV(void);

extern void sidl_rmi_InstanceRegistry__init(
  struct sidl_rmi_InstanceRegistry__object* self, void* ddata, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidl_rmi_InstanceRegistry__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_rmi_InstanceRegistry__epv **s_arg_epv__sidl_rmi_instanceregistry);

extern void sidl_rmi_InstanceRegistry__fini(
  struct sidl_rmi_InstanceRegistry__object* self, struct 
    sidl_BaseInterface__object ** _ex);

extern void sidl_rmi_InstanceRegistry__IOR_version(int32_t *major, int32_t 
  *minor);

struct sidl_BaseClass__object* 
  skel_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseClass(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_BaseInterface__object* 
  skel_sidl_rmi_InstanceRegistry_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, struct sidl_BaseInterface__object * *_ex);
struct sidl_rmi_InstanceRegistry__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
