/*
 * File:          sidl_rmi_UnexpectedCloseException_Module.h
 * Symbol:        sidl.rmi.UnexpectedCloseException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   expose a constructor for the Python wrapper
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
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * THIS CODE IS AUTOMATICALLY GENERATED BY THE BABEL
 * COMPILER. DO NOT EDIT THIS!
 * 
 * External clients need an entry point to wrap a pointer
 * to an instance of sidl.rmi.UnexpectedCloseException.
 * This header files defines two methods that such clients
 * will need.
 *     sidl_rmi_UnexpectedCloseException__import
 *         This should be called in the client's init
 *         module method.
 *     sidl_rmi_UnexpectedCloseException__wrap
 *         This will wrap an IOR in a Python object.
 * This object can be used as an exception. It exports
 * a Python exception type that may be needed as well.
 *     sidl_rmi_UnexpectedCloseException__type
 *         A Python exception type corresponding to
 *         this object type.
 * Here is the pattern for throwing an exception:
 *   PyObject *obj = sidl_rmi_UnexpectedCloseException__wrap(ex);
 *   PyErr_SetObject(sidl_rmi_UnexpectedCloseException__type, obj);
 *   Py_XDECREF(obj);
 */

#ifndef included_sidl_rmi_UnexpectedCloseException_MODULE
#define included_sidl_rmi_UnexpectedCloseException_MODULE

#include <Python.h>
#include "sidlType.h"
#ifdef HAVE_PTHREAD
#include <pthread.h>
#endif /* HAVE_PTHREAD */

#ifdef __cplusplus
extern "C" {
#endif

struct sidl__array;

/* Forward declaration of IOR structure */
struct sidl_rmi_UnexpectedCloseException__object;
struct sidl_rmi_UnexpectedCloseException__array;
struct sidl_BaseInterface__object;

#define sidl_rmi_UnexpectedCloseException__wrap_NUM 0
#define sidl_rmi_UnexpectedCloseException__wrap_RETURN PyObject *
#define sidl_rmi_UnexpectedCloseException__wrap_PROTO (const struct sidl_rmi_UnexpectedCloseException__object *sidlobj)

#define sidl_rmi_UnexpectedCloseException__convert_NUM 1
#define sidl_rmi_UnexpectedCloseException__convert_RETURN int
#define sidl_rmi_UnexpectedCloseException__convert_PROTO (PyObject *obj, struct sidl_rmi_UnexpectedCloseException__object **sidlobj)

#define sidl_rmi_UnexpectedCloseException__convert_python_array_NUM 2
#define sidl_rmi_UnexpectedCloseException__convert_python_array_RETURN int
#define sidl_rmi_UnexpectedCloseException__convert_python_array_PROTO (PyObject *obj, struct sidl_rmi_UnexpectedCloseException__array **sidlarray)

#define sidl_rmi_UnexpectedCloseException__convert_sidl_array_NUM 3
#define sidl_rmi_UnexpectedCloseException__convert_sidl_array_RETURN PyObject *
#define sidl_rmi_UnexpectedCloseException__convert_sidl_array_PROTO (struct sidl__array *sidlarray)

#define sidl_rmi_UnexpectedCloseException__weakRef_NUM 4
#define sidl_rmi_UnexpectedCloseException__weakRef_RETURN PyObject *
#define sidl_rmi_UnexpectedCloseException__weakRef_PROTO (struct sidl_rmi_UnexpectedCloseException__object *sidlobj)

#define sidl_rmi_UnexpectedCloseException_deref_NUM 5
#define sidl_rmi_UnexpectedCloseException_deref_RETURN void
#define sidl_rmi_UnexpectedCloseException_deref_PROTO (struct sidl_rmi_UnexpectedCloseException__object *sidlobj)

#define sidl_rmi_UnexpectedCloseException__newRef_NUM 6
#define sidl_rmi_UnexpectedCloseException__newRef_RETURN PyObject *
#define sidl_rmi_UnexpectedCloseException__newRef_PROTO (struct sidl_rmi_UnexpectedCloseException__object *sidlobj)

#define sidl_rmi_UnexpectedCloseException__addRef_NUM 7
#define sidl_rmi_UnexpectedCloseException__addRef_RETURN void
#define sidl_rmi_UnexpectedCloseException__addRef_PROTO (struct sidl_rmi_UnexpectedCloseException__object *sidlobj)

#define sidl_rmi_UnexpectedCloseException_PyType_NUM 8
#define sidl_rmi_UnexpectedCloseException_PyType_RETURN PyTypeObject *
#define sidl_rmi_UnexpectedCloseException_PyType_PROTO (void)

#define sidl_rmi_UnexpectedCloseException__connectI_NUM 9
#define sidl_rmi_UnexpectedCloseException__connectI_RETURN struct sidl_rmi_UnexpectedCloseException__object* 
#define sidl_rmi_UnexpectedCloseException__connectI_PROTO (const char* url, sidl_bool ar, struct sidl_BaseInterface__object ** _ex)

#define sidl_rmi_UnexpectedCloseException__type_NUM 10

#define sidl_rmi_UnexpectedCloseException__API_NUM 11

#ifdef sidl_rmi_UnexpectedCloseException_INTERNAL

#define sidl_rmi_UnexpectedCloseException__import() ;


/*
 * This declaration is not for clients.
 */

static sidl_rmi_UnexpectedCloseException__wrap_RETURN
sidl_rmi_UnexpectedCloseException__wrap
sidl_rmi_UnexpectedCloseException__wrap_PROTO;

static sidl_rmi_UnexpectedCloseException__convert_RETURN
sidl_rmi_UnexpectedCloseException__convert
sidl_rmi_UnexpectedCloseException__convert_PROTO;

static sidl_rmi_UnexpectedCloseException__convert_python_array_RETURN
sidl_rmi_UnexpectedCloseException__convert_python_array
sidl_rmi_UnexpectedCloseException__convert_python_array_PROTO;

static sidl_rmi_UnexpectedCloseException__convert_sidl_array_RETURN
sidl_rmi_UnexpectedCloseException__convert_sidl_array
sidl_rmi_UnexpectedCloseException__convert_sidl_array_PROTO;

static sidl_rmi_UnexpectedCloseException__weakRef_RETURN
sidl_rmi_UnexpectedCloseException__weakRef
sidl_rmi_UnexpectedCloseException__weakRef_PROTO;

static sidl_rmi_UnexpectedCloseException_deref_RETURN
sidl_rmi_UnexpectedCloseException_deref
sidl_rmi_UnexpectedCloseException_deref_PROTO;

static sidl_rmi_UnexpectedCloseException__newRef_RETURN
sidl_rmi_UnexpectedCloseException__newRef
sidl_rmi_UnexpectedCloseException__newRef_PROTO;

static sidl_rmi_UnexpectedCloseException__addRef_RETURN
sidl_rmi_UnexpectedCloseException__addRef
sidl_rmi_UnexpectedCloseException__addRef_PROTO;

static sidl_rmi_UnexpectedCloseException_PyType_RETURN
sidl_rmi_UnexpectedCloseException_PyType
sidl_rmi_UnexpectedCloseException_PyType_PROTO;

static PyObject *
sidl_rmi_UnexpectedCloseException__type;

#else

static void **sidl_rmi_UnexpectedCloseException__API = NULL;

#define sidl_rmi_UnexpectedCloseException__wrap \
  (*((sidl_rmi_UnexpectedCloseException__wrap_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__wrap_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__wrap_NUM])))

#define sidl_rmi_UnexpectedCloseException__convert \
  (*((sidl_rmi_UnexpectedCloseException__convert_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__convert_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__convert_NUM])))

#define sidl_rmi_UnexpectedCloseException__convert_python_array \
  (*((sidl_rmi_UnexpectedCloseException__convert_python_array_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__convert_python_array_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__convert_python_array_NUM])))

#define sidl_rmi_UnexpectedCloseException__convert_sidl_array \
  (*((sidl_rmi_UnexpectedCloseException__convert_sidl_array_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__convert_sidl_array_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__convert_sidl_array_NUM])))

#define sidl_rmi_UnexpectedCloseException__weakRef \
  (*((sidl_rmi_UnexpectedCloseException__weakRef_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__weakRef_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__weakRef_NUM])))

#define sidl_rmi_UnexpectedCloseException_deref \
  (*((sidl_rmi_UnexpectedCloseException_deref_RETURN (*) \
  sidl_rmi_UnexpectedCloseException_deref_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException_deref_NUM])))

#define sidl_rmi_UnexpectedCloseException__newRef \
  (*((sidl_rmi_UnexpectedCloseException__newRef_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__newRef_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__newRef_NUM])))

#define sidl_rmi_UnexpectedCloseException__addRef \
  (*((sidl_rmi_UnexpectedCloseException__addRef_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__addRef_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__addRef_NUM])))

#define sidl_rmi_UnexpectedCloseException_PyType \
  (*((sidl_rmi_UnexpectedCloseException_PyType_RETURN (*) \
  sidl_rmi_UnexpectedCloseException_PyType_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException_PyType_NUM])))

#define sidl_rmi_UnexpectedCloseException__connectI \
  (*((sidl_rmi_UnexpectedCloseException__connectI_RETURN (*) \
  sidl_rmi_UnexpectedCloseException__connectI_PROTO) \
  (sidl_rmi_UnexpectedCloseException__API \
  [sidl_rmi_UnexpectedCloseException__connectI_NUM])))

#define sidl_rmi_UnexpectedCloseException__type \
  ((PyObject *)(sidl_rmi_UnexpectedCloseException__API[sidl_rmi_UnexpectedCloseException__type_NUM]))

#ifdef HAVE_PTHREAD
#define sidl_rmi_UnexpectedCloseException__import() \
{ \
  pthread_mutex_t __sidl_pyapi_mutex = PTHREAD_MUTEX_INITIALIZER; \
  pthread_mutex_lock(&__sidl_pyapi_mutex); \
  if (!sidl_rmi_UnexpectedCloseException__API) { \
    PyObject *_imp_module = PyImport_ImportModule("sidl.rmi.UnexpectedCloseException"); \
    if (_imp_module != NULL) { \
      PyObject *_imp_module_dict = PyModule_GetDict(_imp_module); \
      PyObject *_imp_c_api_object = \
        PyDict_GetItemString(_imp_module_dict, "_C_API"); \
      if (_imp_c_api_object && PyCObject_Check(_imp_c_api_object)) { \
        sidl_rmi_UnexpectedCloseException__API = \
          (void **)PyCObject_AsVoidPtr(_imp_c_api_object); \
      } \
      else { fprintf(stderr, "babel: sidl_rmi_UnexpectedCloseException__import failed to lookup _C_API (%p %p %s).\n", _imp_c_api_object, _imp_c_api_object ? _imp_c_api_object->ob_type : NULL, _imp_c_api_object ? _imp_c_api_object->ob_type->tp_name : ""); }\
      Py_DECREF(_imp_module); \
    } else { fprintf(stderr, "babel: sidl_rmi_UnexpectedCloseException__import failed to import its module.\n"); \
      if (PyErr_Occurred()) { PyErr_Print(); PyErr_Clear();}\
    }\
  }\
  pthread_mutex_unlock(&__sidl_pyapi_mutex); \
  pthread_mutex_destroy(&__sidl_pyapi_mutex); \
}
#else /* !HAVE_PTHREAD */
#define sidl_rmi_UnexpectedCloseException__import() \
if (!sidl_rmi_UnexpectedCloseException__API) { \
  PyObject *_imp_module = PyImport_ImportModule("sidl.rmi.UnexpectedCloseException"); \
  if (_imp_module != NULL) { \
    PyObject *_imp_module_dict = PyModule_GetDict(_imp_module); \
    PyObject *_imp_c_api_object = \
      PyDict_GetItemString(_imp_module_dict, "_C_API"); \
    if (_imp_c_api_object && PyCObject_Check(_imp_c_api_object)) { \
      sidl_rmi_UnexpectedCloseException__API = \
        (void **)PyCObject_AsVoidPtr(_imp_c_api_object); \
    } \
    else { fprintf(stderr, "babel: sidl_rmi_UnexpectedCloseException__import failed to lookup _C_API (%p %p %s).\n", _imp_c_api_object, _imp_c_api_object ? _imp_c_api_object->ob_type : NULL, _imp_c_api_object ? _imp_c_api_object->ob_type->tp_name : ""); }\
    Py_DECREF(_imp_module); \
  } else { fprintf(stderr, "babel: sidl_rmi_UnexpectedCloseException__import failed to import its module.\n"); \
    if (PyErr_Occurred()) { PyErr_Print(); PyErr_Clear();}\
  }\
}
#endif /* HAVE_PTHREAD */

#endif

#ifdef __cplusplus
}
#endif

#endif
