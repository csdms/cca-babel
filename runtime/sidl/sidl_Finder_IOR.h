/*
 * File:          sidl_Finder_IOR.h
 * Symbol:        sidl.Finder-v0.9.17
 * Symbol Type:   interface
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.Finder
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

#ifndef included_sidl_Finder_IOR_h
#define included_sidl_Finder_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseInterface_IOR_h
#include "sidl_BaseInterface_IOR.h"
#endif
#ifndef included_sidl_Resolve_IOR_h
#include "sidl_Resolve_IOR.h"
#endif
#ifndef included_sidl_Scope_IOR_h
#include "sidl_Scope_IOR.h"
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
 * Symbol "sidl.Finder" (version 0.9.17)
 * 
 * Interface <code>Finder</code> is an interface for classes that resolve 
 * dynamic libraries.  
 * Class <code>Loader</code> takes one of these interfaces through the 
 * method <code>setFinder</code>.  If NULL is passed to setFinder, the 
 * class <code>DefaultFinder</code> is used.
 */

struct sidl_Finder__array;
struct sidl_Finder__object;

/*
 * Forward references for external classes and interfaces.
 */

struct sidl_BaseException__array;
struct sidl_BaseException__object;
struct sidl_ClassInfo__array;
struct sidl_ClassInfo__object;
struct sidl_DLL__array;
struct sidl_DLL__object;
struct sidl_RuntimeException__array;
struct sidl_RuntimeException__object;
struct sidl_rmi_Call__array;
struct sidl_rmi_Call__object;
struct sidl_rmi_Return__array;
struct sidl_rmi_Return__object;

/*
 * Declare the method entry point vector.
 */

struct sidl_Finder__epv {
  /* Implicit builtin methods */
  /* 0 */
  void* (*f__cast)(
    /* in */ void* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 1 */
  void (*f__delete)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 2 */
  void (*f__exec)(
    /* in */ void* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 3 */
  char* (*f__getURL)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 4 */
  void (*f__raddRef)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 5 */
  sidl_bool (*f__isRemote)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 6 */
  void (*f__set_hooks)(
    /* in */ void* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 7 */
  void (*f__set_contracts)(
    /* in */ void* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* 8 */
  void (*f__dump_stats)(
    /* in */ void* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ void* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ void* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.Finder-v0.9.17 */
  struct sidl_DLL__object* (*f_findLibrary)(
    /* in */ void* self,
    /* in */ const char* sidl_name,
    /* in */ const char* target,
    /* in */ int64_t lScope,
    /* in */ int64_t lResolve,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setSearchPath)(
    /* in */ void* self,
    /* in */ const char* path_name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getSearchPath)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_addSearchPath)(
    /* in */ void* self,
    /* in */ const char* path_fragment,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the interface object structure.
 */

struct sidl_Finder__object {
  struct sidl_Finder__epv* d_epv;
  void*                    d_object;
};

/**
 * 
 * 
 * Anonymous class definition
 * 
 * 
 */
/*
 * Symbol "sidl._Finder" (version 1.0)
 */

struct sidl__Finder__array;
struct sidl__Finder__object;

/*
 * Declare the method entry point vector.
 */

struct sidl__Finder__epv {
  /* Implicit builtin methods */
  void* (*f__cast)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__delete)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__exec)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f__getURL)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__raddRef)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f__isRemote)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_hooks)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_contracts)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dump_stats)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor2)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dtor)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.Finder-v0.9.17 */
  struct sidl_DLL__object* (*f_findLibrary)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* sidl_name,
    /* in */ const char* target,
    /* in */ int64_t lScope,
    /* in */ int64_t lResolve,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setSearchPath)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* path_name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getSearchPath)(
    /* in */ struct sidl__Finder__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_addSearchPath)(
    /* in */ struct sidl__Finder__object* self,
    /* in */ const char* path_fragment,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl._Finder-v1.0 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidl__Finder__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidl__Finder__object {
  struct sidl_BaseInterface__object d_sidl_baseinterface;
  struct sidl_Finder__object        d_sidl_finder;
  struct sidl__Finder__epv*         d_epv;
  void*                             d_data;
};


struct sidl__Finder__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
