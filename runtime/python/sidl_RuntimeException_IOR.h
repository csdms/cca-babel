/*
 * File:          sidl_RuntimeException_IOR.h
 * Symbol:        sidl.RuntimeException-v0.9.17
 * Symbol Type:   interface
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.RuntimeException
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

#ifndef included_sidl_RuntimeException_IOR_h
#define included_sidl_RuntimeException_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseException_IOR_h
#include "sidl_BaseException_IOR.h"
#endif
#ifndef included_sidl_BaseInterface_IOR_h
#include "sidl_BaseInterface_IOR.h"
#endif
#ifndef included_sidl_io_Serializable_IOR_h
#include "sidl_io_Serializable_IOR.h"
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
 * Symbol "sidl.RuntimeException" (version 0.9.17)
 * 
 * This exception type is the default exception for every method.
 */

struct sidl_RuntimeException__array;
struct sidl_RuntimeException__object;

/*
 * Forward references for external classes and interfaces.
 */

struct sidl_ClassInfo__array;
struct sidl_ClassInfo__object;
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

struct sidl_RuntimeException__epv {
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
  /* Methods introduced in sidl.io.Serializable-v0.9.17 */
  void (*f_packObj)(
    /* in */ void* self,
    /* in */ struct sidl_io_Serializer__object* ser,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackObj)(
    /* in */ void* self,
    /* in */ struct sidl_io_Deserializer__object* des,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseException-v0.9.17 */
  char* (*f_getNote)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setNote)(
    /* in */ void* self,
    /* in */ const char* message,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getTrace)(
    /* in */ void* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_addLine)(
    /* in */ void* self,
    /* in */ const char* traceline,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_add)(
    /* in */ void* self,
    /* in */ const char* filename,
    /* in */ int32_t lineno,
    /* in */ const char* methodname,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.RuntimeException-v0.9.17 */
};

/*
 * Define the interface object structure.
 */

struct sidl_RuntimeException__object {
  struct sidl_RuntimeException__epv* d_epv;
  void*                              d_object;
};

/**
 * 
 * 
 * Anonymous class definition
 * 
 * 
 */
/*
 * Symbol "sidl._RuntimeException" (version 1.0)
 */

struct sidl__RuntimeException__array;
struct sidl__RuntimeException__object;

/*
 * Declare the method entry point vector.
 */

struct sidl__RuntimeException__epv {
  /* Implicit builtin methods */
  void* (*f__cast)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__delete)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__exec)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f__getURL)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__raddRef)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f__isRemote)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_hooks)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_contracts)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dump_stats)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor2)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dtor)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.io.Serializable-v0.9.17 */
  void (*f_packObj)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ struct sidl_io_Serializer__object* ser,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_unpackObj)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ struct sidl_io_Deserializer__object* des,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseException-v0.9.17 */
  char* (*f_getNote)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_setNote)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* message,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f_getTrace)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_addLine)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* traceline,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_add)(
    /* in */ struct sidl__RuntimeException__object* self,
    /* in */ const char* filename,
    /* in */ int32_t lineno,
    /* in */ const char* methodname,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.RuntimeException-v0.9.17 */
  /* Methods introduced in sidl._RuntimeException-v1.0 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidl__RuntimeException__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidl__RuntimeException__object {
  struct sidl_BaseException__object    d_sidl_baseexception;
  struct sidl_BaseInterface__object    d_sidl_baseinterface;
  struct sidl_RuntimeException__object d_sidl_runtimeexception;
  struct sidl_io_Serializable__object  d_sidl_io_serializable;
  struct sidl__RuntimeException__epv*  d_epv;
  void*                                d_data;
};


struct sidl__RuntimeException__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
