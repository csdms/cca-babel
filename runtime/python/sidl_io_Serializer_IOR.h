/*
 * File:          sidl_io_Serializer_IOR.h
 * Symbol:        sidl.io.Serializer-v0.9.17
 * Symbol Type:   interface
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Intermediate Object Representation for sidl.io.Serializer
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

#ifndef included_sidl_io_Serializer_IOR_h
#define included_sidl_io_Serializer_IOR_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
struct sidl_rmi_InstanceHandle__object;
#ifndef included_sidl_BaseInterface_IOR_h
#include "sidl_BaseInterface_IOR.h"
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
 * Symbol "sidl.io.Serializer" (version 0.9.17)
 * 
 * Standard interface for packing Babel types
 */

struct sidl_io_Serializer__array;
struct sidl_io_Serializer__object;

/*
 * Forward references for external classes and interfaces.
 */

struct sidl_BaseException__array;
struct sidl_BaseException__object;
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

/*
 * Declare the method entry point vector.
 */

struct sidl_io_Serializer__epv {
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
  /* Methods introduced in sidl.io.Serializer-v0.9.17 */
  void (*f_packBool)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ sidl_bool value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packChar)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ char value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packInt)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ int32_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLong)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ int64_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaque)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ void* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloat)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ float value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDouble)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ double value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplex)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ struct sidl_fcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplex)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ struct sidl_dcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packString)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ const char* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializable)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in */ struct sidl_io_Serializable__object* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packBoolArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<bool> */ struct sidl_bool__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packCharArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<char> */ struct sidl_char__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packIntArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<int> */ struct sidl_int__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLongArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<long> */ struct sidl_long__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaqueArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<opaque> */ struct sidl_opaque__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloatArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<float> */ struct sidl_float__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDoubleArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<double> */ struct sidl_double__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplexArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplexArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packStringArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<string> */ struct sidl_string__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packGenericArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<> */ struct sidl__array* value,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializableArray)(
    /* in */ void* self,
    /* in */ const char* key,
    /* in array<sidl.io.Serializable> */ struct sidl_io_Serializable__array* 
      value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
};

/*
 * Define the interface object structure.
 */

struct sidl_io_Serializer__object {
  struct sidl_io_Serializer__epv* d_epv;
  void*                           d_object;
};

/**
 * 
 * 
 * Anonymous class definition
 * 
 * 
 */
/*
 * Symbol "sidl.io._Serializer" (version 1.0)
 */

struct sidl_io__Serializer__array;
struct sidl_io__Serializer__object;

/*
 * Declare the method entry point vector.
 */

struct sidl_io__Serializer__epv {
  /* Implicit builtin methods */
  void* (*f__cast)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__delete)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__exec)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* methodName,
    /* in */ struct sidl_rmi_Call__object* inArgs,
    /* in */ struct sidl_rmi_Return__object* outArgs,
    /* out */ struct sidl_BaseInterface__object **_ex);
  char* (*f__getURL)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__raddRef)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f__isRemote)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_hooks)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ sidl_bool enable,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__set_contracts)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ sidl_bool enable,
    /* in */ const char* enfFilename,
    /* in */ sidl_bool resetCounters,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dump_stats)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* filename,
    /* in */ const char* prefix,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__ctor2)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ void* private_data,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f__dtor)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.BaseInterface-v0.9.17 */
  void (*f_addRef)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_deleteRef)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isSame)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object **_ex);
  sidl_bool (*f_isType)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object **_ex);
  struct sidl_ClassInfo__object* (*f_getClassInfo)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.io.Serializer-v0.9.17 */
  void (*f_packBool)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ sidl_bool value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packChar)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ char value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packInt)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ int32_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLong)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ int64_t value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaque)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ void* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloat)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ float value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDouble)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ double value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplex)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_fcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplex)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_dcomplex value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packString)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ const char* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializable)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in */ struct sidl_io_Serializable__object* value,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packBoolArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<bool> */ struct sidl_bool__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packCharArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<char> */ struct sidl_char__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packIntArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<int> */ struct sidl_int__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packLongArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<long> */ struct sidl_long__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packOpaqueArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<opaque> */ struct sidl_opaque__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFloatArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<float> */ struct sidl_float__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDoubleArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<double> */ struct sidl_double__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packFcomplexArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<fcomplex> */ struct sidl_fcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packDcomplexArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<dcomplex> */ struct sidl_dcomplex__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packStringArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<string> */ struct sidl_string__array* value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packGenericArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<> */ struct sidl__array* value,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  void (*f_packSerializableArray)(
    /* in */ struct sidl_io__Serializer__object* self,
    /* in */ const char* key,
    /* in array<sidl.io.Serializable> */ struct sidl_io_Serializable__array* 
      value,
    /* in */ int32_t ordering,
    /* in */ int32_t dimen,
    /* in */ sidl_bool reuse_array,
    /* out */ struct sidl_BaseInterface__object **_ex);
  /* Methods introduced in sidl.io._Serializer-v1.0 */
};

/*
 * Define the controls and statistics structure.
 */


struct sidl_io__Serializer__cstats {
  sidl_bool use_hooks;
};

/*
 * Define the class object structure.
 */

struct sidl_io__Serializer__object {
  struct sidl_BaseInterface__object d_sidl_baseinterface;
  struct sidl_io_Serializer__object d_sidl_io_serializer;
  struct sidl_io__Serializer__epv*  d_epv;
  void*                             d_data;
};


struct sidl_io__Serializer__remote{
  int d_refcount;
  struct sidl_rmi_InstanceHandle__object *d_ih;
};

#ifdef __cplusplus
}
#endif
#endif
