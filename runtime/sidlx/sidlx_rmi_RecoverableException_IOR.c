/*
 * File:          sidlx_rmi_RecoverableException_IOR.c
 * Symbol:        sidlx.rmi.RecoverableException-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Intermediate Object Representation for sidlx.rmi.RecoverableException
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

/*
 * Begin: RMI includes
 */

#include "sidl_rmi_InstanceHandle.h"
#include "sidl_rmi_InstanceRegistry.h"
#include "sidl_rmi_ServerRegistry.h"
#include "sidl_rmi_Call.h"
#include "sidl_rmi_Return.h"
#include "sidl_Exception.h"
#include "sidl_exec_err.h"
#include "sidl_PreViolation.h"
#include "sidl_NotImplementedException.h"
#include <stdio.h>
/*
 * End: RMI includes
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#ifndef included_sidlOps_h
#include "sidlOps.h"
#endif
#include "sidlx_rmi_RecoverableException_IOR.h"
#ifndef included_sidl_BaseClass_Impl_h
#include "sidl_BaseClass_Impl.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_ClassInfoI_h
#include "sidl_ClassInfoI.h"
#endif

#ifndef NULL
#define NULL 0
#endif

#include "sidl_thread.h"
#ifdef HAVE_PTHREAD
static struct sidl_recursive_mutex_t sidlx_rmi_RecoverableException__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &sidlx_rmi_RecoverableException__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &sidlx_rmi_RecoverableException__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &sidlx_rmi_RecoverableException__mutex )==EDEADLOCK) */
#else
#define LOCK_STATIC_GLOBALS
#define UNLOCK_STATIC_GLOBALS
/* #define HAVE_LOCKED_STATIC_GLOBALS (1) */
#endif

/*
 * Static variables to hold version of IOR
 */

static const int32_t s_IOR_MAJOR_VERSION = 2;
static const int32_t s_IOR_MINOR_VERSION = 0;

/*
 * Static variable to hold shared ClassInfo interface.
 */

static sidl_ClassInfo s_classInfo  = NULL;

/*
 * Static variable to make sure _load called no more than once.
 */

static int s_load_called = 0;

/*
 * Static variables for managing EPV initialization.
 */

static int s_method_initialized = 0;

static struct sidlx_rmi_RecoverableException__epv 
  s_my_epv__sidlx_rmi_recoverableexception;

static struct sidl_BaseClass__epv  s_my_epv__sidl_baseclass;
static struct sidl_BaseClass__epv* s_par_epv__sidl_baseclass;

static struct sidl_BaseException__epv  s_my_epv__sidl_baseexception;
static struct sidl_BaseException__epv* s_par_epv__sidl_baseexception;

static struct sidl_BaseInterface__epv  s_my_epv__sidl_baseinterface;
static struct sidl_BaseInterface__epv* s_par_epv__sidl_baseinterface;

static struct sidl_RuntimeException__epv  s_my_epv__sidl_runtimeexception;
static struct sidl_RuntimeException__epv* s_par_epv__sidl_runtimeexception;

static struct sidl_SIDLException__epv  s_my_epv__sidl_sidlexception;
static struct sidl_SIDLException__epv* s_par_epv__sidl_sidlexception;

static struct sidl_io_IOException__epv  s_my_epv__sidl_io_ioexception;
static struct sidl_io_IOException__epv* s_par_epv__sidl_io_ioexception;

static struct sidl_io_Serializable__epv  s_my_epv__sidl_io_serializable;
static struct sidl_io_Serializable__epv* s_par_epv__sidl_io_serializable;

static struct sidl_rmi_NetworkException__epv  
  s_my_epv__sidl_rmi_networkexception;
static struct sidl_rmi_NetworkException__epv* 
  s_par_epv__sidl_rmi_networkexception;

static struct sidl_rmi_ProtocolException__epv  
  s_my_epv__sidl_rmi_protocolexception;
static struct sidl_rmi_ProtocolException__epv* 
  s_par_epv__sidl_rmi_protocolexception;

/*
 * Declare EPV routines defined in the skeleton file.
 */

#ifdef __cplusplus
extern "C" {
#endif

extern void sidlx_rmi_RecoverableException__set_epv(
  struct sidlx_rmi_RecoverableException__epv* epv);

extern void sidlx_rmi_RecoverableException__call_load(void);
#ifdef __cplusplus
}
#endif

static void
sidlx_rmi_RecoverableException_getHopCount__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t _retval = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getHopCount)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_setErrno__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t err = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "err", &err, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  (self->d_epv->f_setErrno)(
    self,
    err,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_getErrno__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t _retval = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getErrno)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_addRef__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  (self->d_epv->f_addRef)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_deleteRef__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  (self->d_epv->f_deleteRef)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_isSame__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* iobj_str = NULL;
#ifndef WITH_RMI
  sidl_BaseClass iobj_bc = NULL;
#endif /* WITH_RMI */
  struct sidl_BaseInterface__object* iobj = NULL;
  sidl_bool _retval = FALSE;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "iobj", &iobj_str, _ex);SIDL_CHECK(*_ex);
#ifdef WITH_RMI

  iobj = skel_sidlx_rmi_RecoverableException_fconnect_sidl_BaseInterface(
    iobj_str, TRUE, _ex);SIDL_CHECK(*_ex);
#else
  iobj_bc = sidl_rmi_InstanceRegistry_getInstanceByString(iobj_str, 
    _ex);SIDL_CHECK(*_ex);
  if(iobj_bc != NULL) {
    iobj= (struct sidlx_rmi_RecoverableException__object*) (
      *iobj_bc->d_epv->f__cast)(iobj_bc, "sidlx.rmi.RecoverableException", _ex);
    if(iobj != NULL) {
      (((struct sidl_BaseInterface__object*)(iobj))->d_epv->f_deleteRef)(((
        struct sidl_BaseInterface__object*)iobj)->d_object, _ex); SIDL_CHECK(
        *_ex);
    } else {
      (*iobj_bc->d_epv->f_deleteRef)(iobj_bc, _ex);
    }
  }
#endif /* WITH_RMI */

  /* make the call */
  _retval = (self->d_epv->f_isSame)(
    self,
    iobj,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packBool( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(iobj_str) {free(iobj_str);}
  if(iobj) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)iobj, &_ex3); EXEC_CHECK(
      _ex3);
  }
  EXEC_ERR:
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_isType__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  sidl_bool _retval = FALSE;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_isType)(
    self,
    name,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packBool( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(name) {free(name);}
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_getClassInfo__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  struct sidl_ClassInfo__object* _retval = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getClassInfo)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  if(_retval){
    char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)_retval, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Return_packString( outArgs, "_retval", _url, _ex);SIDL_CHECK(*_ex);
    free((void*)_url);
  } else {
    sidl_rmi_Return_packString( outArgs, "_retval", NULL, _ex);SIDL_CHECK(*_ex);
  }
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(_retval && sidl_BaseInterface__isRemote((sidl_BaseInterface)_retval, 
    &_throwaway_exception)) {
    (*((sidl_BaseInterface)_retval)->d_epv->f__raddRef)(((
      sidl_BaseInterface)_retval)->d_object, &_ex3); EXEC_CHECK(_ex3);
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)_retval, &_ex3); 
      EXEC_CHECK(_ex3);
  }
  EXEC_ERR:
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_getNote__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* _retval = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getNote)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packString( outArgs, "_retval", _retval, _ex);SIDL_CHECK(
    *_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(_retval) {
    free(_retval);
  }
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_setNote__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* message= NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "message", &message, _ex);SIDL_CHECK(
    *_ex);

  /* make the call */
  (self->d_epv->f_setNote)(
    self,
    message,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(message) {free(message);}
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_getTrace__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* _retval = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getTrace)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packString( outArgs, "_retval", _retval, _ex);SIDL_CHECK(
    *_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(_retval) {
    free(_retval);
  }
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_addLine__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* traceline= NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "traceline", &traceline, _ex);SIDL_CHECK(
    *_ex);

  /* make the call */
  (self->d_epv->f_addLine)(
    self,
    traceline,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(traceline) {free(traceline);}
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_add__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* filename= NULL;
  int32_t lineno = 0;
  char* methodname= NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "filename", &filename, _ex);SIDL_CHECK(
    *_ex);
  sidl_rmi_Call_unpackInt( inArgs, "lineno", &lineno, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackString( inArgs, "methodname", &methodname, 
    _ex);SIDL_CHECK(*_ex);

  /* make the call */
  (self->d_epv->f_add)(
    self,
    filename,
    lineno,
    methodname,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(filename) {free(filename);}
  if(methodname) {free(methodname);}
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_packObj__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* ser_str = NULL;
#ifndef WITH_RMI
  sidl_BaseClass ser_bc = NULL;
#endif /* WITH_RMI */
  struct sidl_io_Serializer__object* ser = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "ser", &ser_str, _ex);SIDL_CHECK(*_ex);
#ifdef WITH_RMI

  ser = skel_sidlx_rmi_RecoverableException_fconnect_sidl_io_Serializer(ser_str,
    TRUE, _ex);SIDL_CHECK(*_ex);
#else
  ser_bc = sidl_rmi_InstanceRegistry_getInstanceByString(ser_str, 
    _ex);SIDL_CHECK(*_ex);
  if(ser_bc != NULL) {
    ser= (struct sidlx_rmi_RecoverableException__object*) (
      *ser_bc->d_epv->f__cast)(ser_bc, "sidlx.rmi.RecoverableException", _ex);
    if(ser != NULL) {
      (((struct sidl_BaseInterface__object*)(ser))->d_epv->f_deleteRef)(((
        struct sidl_BaseInterface__object*)ser)->d_object, _ex); SIDL_CHECK(
        *_ex);
    } else {
      (*ser_bc->d_epv->f_deleteRef)(ser_bc, _ex);
    }
  }
#endif /* WITH_RMI */

  /* make the call */
  (self->d_epv->f_packObj)(
    self,
    ser,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(ser_str) {free(ser_str);}
  if(ser) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)ser, &_ex3); EXEC_CHECK(
      _ex3);
  }
  EXEC_ERR:
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException_unpackObj__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* des_str = NULL;
#ifndef WITH_RMI
  sidl_BaseClass des_bc = NULL;
#endif /* WITH_RMI */
  struct sidl_io_Deserializer__object* des = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "des", &des_str, _ex);SIDL_CHECK(*_ex);
#ifdef WITH_RMI

  des = skel_sidlx_rmi_RecoverableException_fconnect_sidl_io_Deserializer(
    des_str, TRUE, _ex);SIDL_CHECK(*_ex);
#else
  des_bc = sidl_rmi_InstanceRegistry_getInstanceByString(des_str, 
    _ex);SIDL_CHECK(*_ex);
  if(des_bc != NULL) {
    des= (struct sidlx_rmi_RecoverableException__object*) (
      *des_bc->d_epv->f__cast)(des_bc, "sidlx.rmi.RecoverableException", _ex);
    if(des != NULL) {
      (((struct sidl_BaseInterface__object*)(des))->d_epv->f_deleteRef)(((
        struct sidl_BaseInterface__object*)des)->d_object, _ex); SIDL_CHECK(
        *_ex);
    } else {
      (*des_bc->d_epv->f_deleteRef)(des_bc, _ex);
    }
  }
#endif /* WITH_RMI */

  /* make the call */
  (self->d_epv->f_unpackObj)(
    self,
    des,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(des_str) {free(des_str);}
  if(des) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)des, &_ex3); EXEC_CHECK(
      _ex3);
  }
  EXEC_ERR:
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

static void
sidlx_rmi_RecoverableException__cast__exec(
        struct sidlx_rmi_RecoverableException__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  void* _retval = 0;
  sidl_BaseInterface _throwaway_exception = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f__cast)(
    self,
    name,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packOpaque( outArgs, "_retval", _retval, _ex);SIDL_CHECK(
    *_ex);
  /* pack out and inout argments */
  EXIT:
  /* clean-up dangling references */
  if(name) {free(name);}
  if(*_ex) { 
    _SIDLex = sidl_BaseException__cast(*_ex,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed, throw _ex up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(*_ex, &_throwaway_exception);
    *_ex = NULL;
    if(_ex3) { 
      sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
      _ex3 = NULL;
    }
  } else if(_ex3) {
    _SIDLex = sidl_BaseException__cast(_ex3,&_throwaway_exception);
    sidl_rmi_Return_throwException(outArgs, _SIDLex, &_throwaway_exception); 
    if(_throwaway_exception) {
      /* Throwing failed throw _ex3 up the stack then. */
      sidl_BaseInterface_deleteRef(_throwaway_exception, &_throwaway_exception);
      return;
    }
    sidl_BaseException_deleteRef(_SIDLex, &_throwaway_exception);
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway_exception);
    _ex3 = NULL;
  }
}

/*
 * CHECKS: Enable/disable contract enforcement.
 */

static void ior_sidlx_rmi_RecoverableException__set_contracts(
  struct sidlx_rmi_RecoverableException__object* self,
  sidl_bool   enable,
  const char* enfFilename,
  sidl_bool   resetCounters,
  struct sidl_BaseInterface__object **_ex)
{
  *_ex  = NULL;
  {
    /*
     * Nothing to do since contract enforcement not needed.
     */

  }
}

/*
 * DUMP: Dump interface contract enforcement statistics.
 */

static void ior_sidlx_rmi_RecoverableException__dump_stats(
  struct sidlx_rmi_RecoverableException__object* self,
  const char* filename,
  const char* prefix,
  struct sidl_BaseInterface__object **_ex)
{
  *_ex = NULL;
  {
    /*
     * Nothing to do since contract checks not generated.
     */

  }
}

static void ior_sidlx_rmi_RecoverableException__ensure_load_called(void) {
  /*
   * assert( HAVE_LOCKED_STATIC_GLOBALS );
   */

  if (! s_load_called ) {
    s_load_called=1;
    sidlx_rmi_RecoverableException__call_load();
  }
}

/* CAST: dynamic type casting support. */
static void* ior_sidlx_rmi_RecoverableException__cast(
  struct sidlx_rmi_RecoverableException__object* self,
  const char* name, sidl_BaseInterface* _ex)
{
  int cmp;
  void* cast = NULL;
  *_ex = NULL; /* default to no exception */
  cmp = strcmp(name, "sidl.io.IOException");
  if (!cmp) {
    (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
    cast = ((struct sidl_io_IOException__object*)self);
    return cast;
  }
  else if (cmp < 0) {
    cmp = strcmp(name, "sidl.BaseInterface");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = &((
        *self).d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_baseclass.d_sidl_baseinterface);
      return cast;
    }
    else if (cmp < 0) {
      cmp = strcmp(name, "sidl.BaseException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((
          *self).d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_baseexception);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.BaseClass");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = ((struct sidl_BaseClass__object*)self);
          return cast;
        }
      }
    }
    else if (cmp > 0) {
      cmp = strcmp(name, "sidl.SIDLException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidl_SIDLException__object*)self);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.RuntimeException");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((
            *self).d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_runtimeexception);
          return cast;
        }
      }
    }
  }
  else if (cmp > 0) {
    cmp = strcmp(name, "sidl.rmi.ProtocolException");
    if (!cmp) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = ((struct sidl_rmi_ProtocolException__object*)self);
      return cast;
    }
    else if (cmp < 0) {
      cmp = strcmp(name, "sidl.rmi.NetworkException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidl_rmi_NetworkException__object*)self);
        return cast;
      }
      else if (cmp < 0) {
        cmp = strcmp(name, "sidl.io.Serializable");
        if (!cmp) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((
            *self).d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_io_serializable);
          return cast;
        }
      }
    }
    else if (cmp > 0) {
      cmp = strcmp(name, "sidlx.rmi.RecoverableException");
      if (!cmp) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct sidlx_rmi_RecoverableException__object*)self);
        return cast;
      }
    }
  }
  return cast;
  EXIT:
  return NULL;
}

/*
 * HOOKS: Enable/disable hooks.
 */

static void ior_sidlx_rmi_RecoverableException__set_hooks(
  struct sidlx_rmi_RecoverableException__object* self,
  sidl_bool enable, struct sidl_BaseInterface__object **_ex )
{
  *_ex  = NULL;
  /*
   * Nothing else to do since hook methods not generated.
   */

}

/*
 * DELETE: call destructor and free object memory.
 */

static void ior_sidlx_rmi_RecoverableException__delete(
  struct sidlx_rmi_RecoverableException__object* self, struct 
    sidl_BaseInterface__object **_ex)
{
  *_ex  = NULL; /* default to no exception */
  sidlx_rmi_RecoverableException__fini(self, _ex);
  memset((void*)self, 0, sizeof(struct sidlx_rmi_RecoverableException__object));
  free((void*) self);
}

static char*
ior_sidlx_rmi_RecoverableException__getURL(
  struct sidlx_rmi_RecoverableException__object* self,
  struct sidl_BaseInterface__object **_ex)
{
  char* ret  = NULL;
  char* objid = sidl_rmi_InstanceRegistry_getInstanceByClass((sidl_BaseClass)self, _ex); SIDL_CHECK(*_ex);
  if (!objid) {
    objid = sidl_rmi_InstanceRegistry_registerInstance((sidl_BaseClass)self, _ex); SIDL_CHECK(*_ex);
  }
#ifdef WITH_RMI

  ret = sidl_rmi_ServerRegistry_getServerURL(objid, _ex); SIDL_CHECK(*_ex);

#else

  ret = objid;

#endif /*WITH_RMI*/
  return ret;
  EXIT:
  return NULL;
}
static void
ior_sidlx_rmi_RecoverableException__raddRef(
    struct sidlx_rmi_RecoverableException__object* self, sidl_BaseInterface* 
  _ex) {
  sidl_BaseInterface_addRef((sidl_BaseInterface)self, _ex);
}

static sidl_bool
ior_sidlx_rmi_RecoverableException__isRemote(
    struct sidlx_rmi_RecoverableException__object* self, sidl_BaseInterface* 
  _ex) {
  *_ex  = NULL; /* default to no exception */
  return FALSE;
}

struct sidlx_rmi_RecoverableException__method {
  const char *d_name;
  void (*d_func)(struct sidlx_rmi_RecoverableException__object*,
    struct sidl_rmi_Call__object *,
    struct sidl_rmi_Return__object *,
    struct sidl_BaseInterface__object **);
};

static void
ior_sidlx_rmi_RecoverableException__exec(
  struct sidlx_rmi_RecoverableException__object* self,
  const char* methodName,
  struct sidl_rmi_Call__object* inArgs,
  struct sidl_rmi_Return__object* outArgs,
  struct sidl_BaseInterface__object **_ex )
{
  static const struct sidlx_rmi_RecoverableException__method  s_methods[] = {
    { "_cast", sidlx_rmi_RecoverableException__cast__exec },
    { "add", sidlx_rmi_RecoverableException_add__exec },
    { "addLine", sidlx_rmi_RecoverableException_addLine__exec },
    { "addRef", sidlx_rmi_RecoverableException_addRef__exec },
    { "deleteRef", sidlx_rmi_RecoverableException_deleteRef__exec },
    { "getClassInfo", sidlx_rmi_RecoverableException_getClassInfo__exec },
    { "getErrno", sidlx_rmi_RecoverableException_getErrno__exec },
    { "getHopCount", sidlx_rmi_RecoverableException_getHopCount__exec },
    { "getNote", sidlx_rmi_RecoverableException_getNote__exec },
    { "getTrace", sidlx_rmi_RecoverableException_getTrace__exec },
    { "isSame", sidlx_rmi_RecoverableException_isSame__exec },
    { "isType", sidlx_rmi_RecoverableException_isType__exec },
    { "packObj", sidlx_rmi_RecoverableException_packObj__exec },
    { "setErrno", sidlx_rmi_RecoverableException_setErrno__exec },
    { "setNote", sidlx_rmi_RecoverableException_setNote__exec },
    { "unpackObj", sidlx_rmi_RecoverableException_unpackObj__exec }
  };
  int i, cmp, l = 0;
  int u = sizeof(s_methods)/sizeof(struct 
    sidlx_rmi_RecoverableException__method);
  *_ex  = NULL; /* default to no exception */

  if (methodName) {
    /* Use binary search to locate method */
    while (l < u) {
      i = (l + u) >> 1;
      if (!(cmp=strcmp(methodName, s_methods[i].d_name))) {
        (s_methods[i].d_func)(self, inArgs, outArgs, _ex); SIDL_CHECK(*_ex);
        return;
      }
      else if (cmp < 0) u = i;
      else l = i + 1;
    }
  }
  /* TODO: add code for method not found */
  SIDL_THROW(*_ex, sidl_PreViolation, "method name not found");
  EXIT:
  return;
}
/*
 * EPV: create method entry point vector (EPV) structure.
 */

static void sidlx_rmi_RecoverableException__init_epv(void)
{
/*
 * assert( HAVE_LOCKED_STATIC_GLOBALS );
 */

  struct sidlx_rmi_RecoverableException__epv*  epv  = &s_my_epv__sidlx_rmi_recoverableexception;
  struct sidl_BaseClass__epv*                  e0   = &s_my_epv__sidl_baseclass;
  struct sidl_BaseException__epv*              e1   = &s_my_epv__sidl_baseexception;
  struct sidl_BaseInterface__epv*              e2   = &s_my_epv__sidl_baseinterface;
  struct sidl_RuntimeException__epv*           e3   = &s_my_epv__sidl_runtimeexception;
  struct sidl_SIDLException__epv*              e4   = &s_my_epv__sidl_sidlexception;
  struct sidl_io_IOException__epv*             e5   = &s_my_epv__sidl_io_ioexception;
  struct sidl_io_Serializable__epv*            e6   = &s_my_epv__sidl_io_serializable;
  struct sidl_rmi_NetworkException__epv*       e7   = &s_my_epv__sidl_rmi_networkexception;
  struct sidl_rmi_ProtocolException__epv*      e8   = &s_my_epv__sidl_rmi_protocolexception;

  struct sidl_rmi_ProtocolException__epv*     s1 = NULL;
  struct sidl_rmi_NetworkException__epv*      s2 = NULL;
  struct sidl_io_IOException__epv*            s3 = NULL;
  struct sidl_SIDLException__epv*             s4 = NULL;
  struct sidl_BaseClass__epv*                 s5 = NULL;

  /*
   * Get my parent's EPVs so I can start with their functions.
   */

  sidl_rmi_ProtocolException__getEPVs(
    &s_par_epv__sidl_baseinterface,
    &s_par_epv__sidl_baseclass,
    &s_par_epv__sidl_baseexception,
    &s_par_epv__sidl_io_serializable,
    &s_par_epv__sidl_sidlexception,
    &s_par_epv__sidl_runtimeexception,
    &s_par_epv__sidl_io_ioexception,
    &s_par_epv__sidl_rmi_networkexception,
    &s_par_epv__sidl_rmi_protocolexception);


  /*
   * Alias the static epvs to some handy small names.
   */

  s5  =  s_par_epv__sidl_baseclass;
  s4  =  s_par_epv__sidl_sidlexception;
  s3  =  s_par_epv__sidl_io_ioexception;
  s2  =  s_par_epv__sidl_rmi_networkexception;
  s1  =  s_par_epv__sidl_rmi_protocolexception;

  epv->f__cast                 = ior_sidlx_rmi_RecoverableException__cast;
  epv->f__delete               = ior_sidlx_rmi_RecoverableException__delete;
  epv->f__exec                 = ior_sidlx_rmi_RecoverableException__exec;
  epv->f__getURL               = ior_sidlx_rmi_RecoverableException__getURL;
  epv->f__raddRef              = ior_sidlx_rmi_RecoverableException__raddRef;
  epv->f__isRemote             = ior_sidlx_rmi_RecoverableException__isRemote;
  epv->f__set_hooks            = ior_sidlx_rmi_RecoverableException__set_hooks;
  epv->f__set_contracts        = ior_sidlx_rmi_RecoverableException__set_contracts;
  epv->f__dump_stats           = ior_sidlx_rmi_RecoverableException__dump_stats;
  epv->f__ctor                 = NULL;
  epv->f__ctor2                = NULL;
  epv->f__dtor                 = NULL;
  epv->f_getHopCount           = (int32_t (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_getHopCount;
  epv->f_setErrno              = (void (*)(struct sidlx_rmi_RecoverableException__object*,int32_t,struct sidl_BaseInterface__object **)) s1->f_setErrno;
  epv->f_getErrno              = (int32_t (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_getErrno;
  epv->f_addRef                = (void (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_addRef;
  epv->f_deleteRef             = (void (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_deleteRef;
  epv->f_isSame                = (sidl_bool (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) s1->f_isSame;
  epv->f_isType                = (sidl_bool (*)(struct sidlx_rmi_RecoverableException__object*,const char*,struct sidl_BaseInterface__object **)) s1->f_isType;
  epv->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_getClassInfo;
  epv->f_getNote               = (char* (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_getNote;
  epv->f_setNote               = (void (*)(struct sidlx_rmi_RecoverableException__object*,const char*,struct sidl_BaseInterface__object **)) s1->f_setNote;
  epv->f_getTrace              = (char* (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_BaseInterface__object **)) s1->f_getTrace;
  epv->f_addLine               = (void (*)(struct sidlx_rmi_RecoverableException__object*,const char*,struct sidl_BaseInterface__object **)) s1->f_addLine;
  epv->f_add                   = (void (*)(struct sidlx_rmi_RecoverableException__object*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) s1->f_add;
  epv->f_packObj               = (void (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) s1->f_packObj;
  epv->f_unpackObj             = (void (*)(struct sidlx_rmi_RecoverableException__object*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) s1->f_unpackObj;

  sidlx_rmi_RecoverableException__set_epv(epv);

  /*
   * Override function pointers for sidl.BaseClass with mine, as needed.
   */

  e0->f__cast                 = (void* (*)(struct sidl_BaseClass__object*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e0->f__delete               = (void (*)(struct sidl_BaseClass__object*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e0->f__getURL               = (char* (*)(struct sidl_BaseClass__object*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e0->f__raddRef              = (void (*)(struct sidl_BaseClass__object*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e0->f__isRemote             = (sidl_bool (*)(struct sidl_BaseClass__object*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e0->f__exec                 = (void (*)(struct sidl_BaseClass__object*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e0->f_addRef                = (void (*)(struct sidl_BaseClass__object*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e0->f_deleteRef             = (void (*)(struct sidl_BaseClass__object*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e0->f_isSame                = (sidl_bool (*)(struct sidl_BaseClass__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e0->f_isType                = (sidl_bool (*)(struct sidl_BaseClass__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e0->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidl_BaseClass__object*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;


  /*
   * Override function pointers for sidl.BaseException with mine, as needed.
   */

  e1->f__cast                 = (void* (*)(void*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e1->f__delete               = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e1->f__getURL               = (char* (*)(void*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e1->f__raddRef              = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e1->f__isRemote             = (sidl_bool (*)(void*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e1->f__exec                 = (void (*)(void*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e1->f_getNote               = (char* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e1->f_setNote               = (void (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e1->f_getTrace              = (char* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e1->f_addLine               = (void (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e1->f_add                   = (void (*)(void*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e1->f_packObj               = (void (*)(void*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e1->f_unpackObj             = (void (*)(void*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e1->f_addRef                = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e1->f_deleteRef             = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e1->f_isSame                = (sidl_bool (*)(void*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e1->f_isType                = (sidl_bool (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e1->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;


  /*
   * Override function pointers for sidl.BaseInterface with mine, as needed.
   */

  e2->f__cast                 = (void* (*)(void*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e2->f__delete               = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e2->f__getURL               = (char* (*)(void*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e2->f__raddRef              = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e2->f__isRemote             = (sidl_bool (*)(void*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e2->f__exec                 = (void (*)(void*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e2->f_addRef                = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e2->f_deleteRef             = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e2->f_isSame                = (sidl_bool (*)(void*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e2->f_isType                = (sidl_bool (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e2->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;


  /*
   * Override function pointers for sidl.RuntimeException with mine, as needed.
   */

  e3->f__cast                 = (void* (*)(void*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e3->f__delete               = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e3->f__getURL               = (char* (*)(void*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e3->f__raddRef              = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e3->f__isRemote             = (sidl_bool (*)(void*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e3->f__exec                 = (void (*)(void*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e3->f_getNote               = (char* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e3->f_setNote               = (void (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e3->f_getTrace              = (char* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e3->f_addLine               = (void (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e3->f_add                   = (void (*)(void*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e3->f_packObj               = (void (*)(void*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e3->f_unpackObj             = (void (*)(void*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e3->f_addRef                = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e3->f_deleteRef             = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e3->f_isSame                = (sidl_bool (*)(void*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e3->f_isType                = (sidl_bool (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e3->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;


  /*
   * Override function pointers for sidl.SIDLException with mine, as needed.
   */

  e4->f__cast                 = (void* (*)(struct sidl_SIDLException__object*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e4->f__delete               = (void (*)(struct sidl_SIDLException__object*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e4->f__getURL               = (char* (*)(struct sidl_SIDLException__object*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e4->f__raddRef              = (void (*)(struct sidl_SIDLException__object*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e4->f__isRemote             = (sidl_bool (*)(struct sidl_SIDLException__object*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e4->f__exec                 = (void (*)(struct sidl_SIDLException__object*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e4->f_addRef                = (void (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e4->f_deleteRef             = (void (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e4->f_isSame                = (sidl_bool (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e4->f_isType                = (sidl_bool (*)(struct sidl_SIDLException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e4->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;
  e4->f_getNote               = (char* (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e4->f_setNote               = (void (*)(struct sidl_SIDLException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e4->f_getTrace              = (char* (*)(struct sidl_SIDLException__object*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e4->f_addLine               = (void (*)(struct sidl_SIDLException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e4->f_add                   = (void (*)(struct sidl_SIDLException__object*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e4->f_packObj               = (void (*)(struct sidl_SIDLException__object*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e4->f_unpackObj             = (void (*)(struct sidl_SIDLException__object*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;


  /*
   * Override function pointers for sidl.io.IOException with mine, as needed.
   */

  e5->f__cast                 = (void* (*)(struct sidl_io_IOException__object*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e5->f__delete               = (void (*)(struct sidl_io_IOException__object*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e5->f__getURL               = (char* (*)(struct sidl_io_IOException__object*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e5->f__raddRef              = (void (*)(struct sidl_io_IOException__object*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e5->f__isRemote             = (sidl_bool (*)(struct sidl_io_IOException__object*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e5->f__exec                 = (void (*)(struct sidl_io_IOException__object*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e5->f_addRef                = (void (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e5->f_deleteRef             = (void (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e5->f_isSame                = (sidl_bool (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e5->f_isType                = (sidl_bool (*)(struct sidl_io_IOException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e5->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;
  e5->f_getNote               = (char* (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e5->f_setNote               = (void (*)(struct sidl_io_IOException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e5->f_getTrace              = (char* (*)(struct sidl_io_IOException__object*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e5->f_addLine               = (void (*)(struct sidl_io_IOException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e5->f_add                   = (void (*)(struct sidl_io_IOException__object*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e5->f_packObj               = (void (*)(struct sidl_io_IOException__object*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e5->f_unpackObj             = (void (*)(struct sidl_io_IOException__object*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;


  /*
   * Override function pointers for sidl.io.Serializable with mine, as needed.
   */

  e6->f__cast                 = (void* (*)(void*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e6->f__delete               = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e6->f__getURL               = (char* (*)(void*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e6->f__raddRef              = (void (*)(void*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e6->f__isRemote             = (sidl_bool (*)(void*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e6->f__exec                 = (void (*)(void*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e6->f_packObj               = (void (*)(void*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e6->f_unpackObj             = (void (*)(void*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;
  e6->f_addRef                = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e6->f_deleteRef             = (void (*)(void*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e6->f_isSame                = (sidl_bool (*)(void*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e6->f_isType                = (sidl_bool (*)(void*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e6->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(void*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;


  /*
   * Override function pointers for sidl.rmi.NetworkException with mine, as needed.
   */

  e7->f__cast                 = (void* (*)(struct sidl_rmi_NetworkException__object*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e7->f__delete               = (void (*)(struct sidl_rmi_NetworkException__object*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e7->f__getURL               = (char* (*)(struct sidl_rmi_NetworkException__object*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e7->f__raddRef              = (void (*)(struct sidl_rmi_NetworkException__object*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e7->f__isRemote             = (sidl_bool (*)(struct sidl_rmi_NetworkException__object*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e7->f__exec                 = (void (*)(struct sidl_rmi_NetworkException__object*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e7->f_getHopCount           = (int32_t (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_getHopCount;
  e7->f_setErrno              = (void (*)(struct sidl_rmi_NetworkException__object*,int32_t,struct sidl_BaseInterface__object **)) epv->f_setErrno;
  e7->f_getErrno              = (int32_t (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_getErrno;
  e7->f_addRef                = (void (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e7->f_deleteRef             = (void (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e7->f_isSame                = (sidl_bool (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e7->f_isType                = (sidl_bool (*)(struct sidl_rmi_NetworkException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e7->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;
  e7->f_getNote               = (char* (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e7->f_setNote               = (void (*)(struct sidl_rmi_NetworkException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e7->f_getTrace              = (char* (*)(struct sidl_rmi_NetworkException__object*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e7->f_addLine               = (void (*)(struct sidl_rmi_NetworkException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e7->f_add                   = (void (*)(struct sidl_rmi_NetworkException__object*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e7->f_packObj               = (void (*)(struct sidl_rmi_NetworkException__object*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e7->f_unpackObj             = (void (*)(struct sidl_rmi_NetworkException__object*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;


  /*
   * Override function pointers for sidl.rmi.ProtocolException with mine, as needed.
   */

  e8->f__cast                 = (void* (*)(struct sidl_rmi_ProtocolException__object*,const char*, struct sidl_BaseInterface__object**))epv->f__cast;
  e8->f__delete               = (void (*)(struct sidl_rmi_ProtocolException__object*, struct sidl_BaseInterface__object **)) epv->f__delete;
  e8->f__getURL               = (char* (*)(struct sidl_rmi_ProtocolException__object*, struct sidl_BaseInterface__object **)) epv->f__getURL;
  e8->f__raddRef              = (void (*)(struct sidl_rmi_ProtocolException__object*, struct sidl_BaseInterface__object **)) epv->f__raddRef;
  e8->f__isRemote             = (sidl_bool (*)(struct sidl_rmi_ProtocolException__object*, struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e8->f__exec                 = (void (*)(struct sidl_rmi_ProtocolException__object*,const char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct sidl_BaseInterface__object **)) epv->f__exec;
  e8->f_getHopCount           = (int32_t (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_getHopCount;
  e8->f_setErrno              = (void (*)(struct sidl_rmi_ProtocolException__object*,int32_t,struct sidl_BaseInterface__object **)) epv->f_setErrno;
  e8->f_getErrno              = (int32_t (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_getErrno;
  e8->f_addRef                = (void (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_addRef;
  e8->f_deleteRef             = (void (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_deleteRef;
  e8->f_isSame                = (sidl_bool (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) epv->f_isSame;
  e8->f_isType                = (sidl_bool (*)(struct sidl_rmi_ProtocolException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e8->f_getClassInfo          = (struct sidl_ClassInfo__object* (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_getClassInfo;
  e8->f_getNote               = (char* (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_getNote;
  e8->f_setNote               = (void (*)(struct sidl_rmi_ProtocolException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_setNote;
  e8->f_getTrace              = (char* (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_BaseInterface__object **)) epv->f_getTrace;
  e8->f_addLine               = (void (*)(struct sidl_rmi_ProtocolException__object*,const char*,struct sidl_BaseInterface__object **)) epv->f_addLine;
  e8->f_add                   = (void (*)(struct sidl_rmi_ProtocolException__object*,const char*,int32_t,const char*,struct sidl_BaseInterface__object **)) epv->f_add;
  e8->f_packObj               = (void (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_io_Serializer__object*,struct sidl_BaseInterface__object **)) epv->f_packObj;
  e8->f_unpackObj             = (void (*)(struct sidl_rmi_ProtocolException__object*,struct sidl_io_Deserializer__object*,struct sidl_BaseInterface__object **)) epv->f_unpackObj;


  s_method_initialized = 1;
  ior_sidlx_rmi_RecoverableException__ensure_load_called();
}

/*
 * sidlx_rmi_RecoverableException__getEPVs: Get my version of all relevant EPVs.
 */

void sidlx_rmi_RecoverableException__getEPVs (
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,
  struct sidl_BaseException__epv **s_arg_epv__sidl_baseexception,
  struct sidl_io_Serializable__epv **s_arg_epv__sidl_io_serializable,
  struct sidl_SIDLException__epv **s_arg_epv__sidl_sidlexception,
  struct sidl_RuntimeException__epv **s_arg_epv__sidl_runtimeexception,
  struct sidl_io_IOException__epv **s_arg_epv__sidl_io_ioexception,
  struct sidl_rmi_NetworkException__epv **s_arg_epv__sidl_rmi_networkexception,
  struct sidl_rmi_ProtocolException__epv **s_arg_epv__sidl_rmi_protocolexception,
  struct sidlx_rmi_RecoverableException__epv **s_arg_epv__sidlx_rmi_recoverableexception)
{
  LOCK_STATIC_GLOBALS;
  if (!s_method_initialized) {
    sidlx_rmi_RecoverableException__init_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  *s_arg_epv__sidl_baseinterface = &s_my_epv__sidl_baseinterface;
  *s_arg_epv__sidl_baseclass = &s_my_epv__sidl_baseclass;
  *s_arg_epv__sidl_baseexception = &s_my_epv__sidl_baseexception;
  *s_arg_epv__sidl_io_serializable = &s_my_epv__sidl_io_serializable;
  *s_arg_epv__sidl_sidlexception = &s_my_epv__sidl_sidlexception;
  *s_arg_epv__sidl_runtimeexception = &s_my_epv__sidl_runtimeexception;
  *s_arg_epv__sidl_io_ioexception = &s_my_epv__sidl_io_ioexception;
  *s_arg_epv__sidl_rmi_networkexception = &s_my_epv__sidl_rmi_networkexception;
  *s_arg_epv__sidl_rmi_protocolexception = &s_my_epv__sidl_rmi_protocolexception;
  *s_arg_epv__sidlx_rmi_recoverableexception = &s_my_epv__sidlx_rmi_recoverableexception;
}
/*
 * __getSuperEPV: returns parent's non-overrided EPV
 */

static struct sidl_rmi_ProtocolException__epv* sidlx_rmi_RecoverableException__getSuperEPV(void) {
  return s_par_epv__sidl_rmi_protocolexception;
}

/*
 * initClassInfo: create a ClassInfo interface if necessary.
 */

static void
initClassInfo(sidl_ClassInfo *info, struct sidl_BaseInterface__object **_ex)
{
  LOCK_STATIC_GLOBALS;
  *_ex  = NULL; /* default to no exception */

  if (!s_classInfo) {
    sidl_ClassInfoI impl;
    impl = sidl_ClassInfoI__create(_ex);
    s_classInfo = sidl_ClassInfo__cast(impl,_ex);
    if (impl) {
      sidl_ClassInfoI_setName(impl, "sidlx.rmi.RecoverableException", _ex);
      sidl_ClassInfoI_setVersion(impl, "0.1", _ex);
      sidl_ClassInfoI_setIORVersion(impl, s_IOR_MAJOR_VERSION,
        s_IOR_MINOR_VERSION, _ex);
      sidl_ClassInfoI_deleteRef(impl,_ex);
      sidl_atexit(sidl_deleteRef_atexit, &s_classInfo);
    }
  }
  UNLOCK_STATIC_GLOBALS;
  if (s_classInfo) {
    if (*info) {
      sidl_ClassInfo_deleteRef(*info,_ex);
    }
    *info = s_classInfo;
    sidl_ClassInfo_addRef(*info,_ex);
  }
}

/*
 * initMetadata: store IOR version & class in sidl.BaseClass's data
 */

static void
initMetadata(struct sidlx_rmi_RecoverableException__object* self, sidl_BaseInterface* _ex)
{
  *_ex = 0; /* default no exception */
  if (self) {
    struct sidl_BaseClass__data *data = (struct sidl_BaseClass__data*)((*self).d_sidl_rmi_protocolexception.d_sidl_rmi_networkexception.d_sidl_io_ioexception.d_sidl_sidlexception.d_sidl_baseclass.d_data);
    if (data) {
      data->d_IOR_major_version = s_IOR_MAJOR_VERSION;
      data->d_IOR_minor_version = s_IOR_MINOR_VERSION;
      initClassInfo(&(data->d_classinfo),_ex); SIDL_CHECK(*_ex);
    }
  }
EXIT:
return;
}

/*
 * sidlx_rmi_RecoverableException__createObject: Allocate the object and initialize it.
 */

struct sidlx_rmi_RecoverableException__object*
sidlx_rmi_RecoverableException__createObject(void* ddata, struct sidl_BaseInterface__object ** _ex)
{
  struct sidlx_rmi_RecoverableException__object* self =
    (struct sidlx_rmi_RecoverableException__object*) sidl_malloc(
      sizeof(struct sidlx_rmi_RecoverableException__object),
      "Object allocation failed for struct sidlx_rmi_RecoverableException__object",
        __FILE__, __LINE__, "sidlx_rmi_RecoverableException__createObject", _ex);
  if (!self) goto EXIT;
  sidlx_rmi_RecoverableException__init(self, ddata, _ex); SIDL_CHECK(*_ex);
  initMetadata(self, _ex); SIDL_CHECK(*_ex);
  return self;

  EXIT:
  return NULL;
}

/*
 * INIT: initialize a new instance of the class object.
 */

void sidlx_rmi_RecoverableException__init(
  struct sidlx_rmi_RecoverableException__object* self,
   void* ddata,
  struct sidl_BaseInterface__object **_ex)
{
  struct sidlx_rmi_RecoverableException__object* s0 = self;
  struct sidl_rmi_ProtocolException__object*     s1 = &s0->d_sidl_rmi_protocolexception;
  struct sidl_rmi_NetworkException__object*      s2 = &s1->d_sidl_rmi_networkexception;
  struct sidl_io_IOException__object*            s3 = &s2->d_sidl_io_ioexception;
  struct sidl_SIDLException__object*             s4 = &s3->d_sidl_sidlexception;
  struct sidl_BaseClass__object*                 s5 = &s4->d_sidl_baseclass;

  *_ex = 0; /* default no exception */
  LOCK_STATIC_GLOBALS;
  if (!s_method_initialized) {
    sidlx_rmi_RecoverableException__init_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  sidl_rmi_ProtocolException__init(s1, NULL, _ex); SIDL_CHECK(*_ex);

  s5->d_sidl_baseinterface.d_epv = &s_my_epv__sidl_baseinterface;
  s5->d_epv                      = &s_my_epv__sidl_baseclass;

  s4->d_sidl_baseexception.d_epv   = &s_my_epv__sidl_baseexception;
  s4->d_sidl_io_serializable.d_epv = &s_my_epv__sidl_io_serializable;
  s4->d_epv                        = &s_my_epv__sidl_sidlexception;

  s3->d_sidl_runtimeexception.d_epv = &s_my_epv__sidl_runtimeexception;
  s3->d_epv                         = &s_my_epv__sidl_io_ioexception;

  s2->d_epv    = &s_my_epv__sidl_rmi_networkexception;

  s1->d_epv    = &s_my_epv__sidl_rmi_protocolexception;

  s0->d_epv    = &s_my_epv__sidlx_rmi_recoverableexception;

  s0->d_data = NULL;

  if (ddata) {
    self->d_data = ddata;
    (*(self->d_epv->f__ctor2))(self,ddata,_ex); SIDL_CHECK(*_ex);
  } else { 
    (*(self->d_epv->f__ctor))(self,_ex); SIDL_CHECK(*_ex);
  }
  EXIT:
  return;
}

/*
 * FINI: deallocate a class instance (destructor).
 */

void sidlx_rmi_RecoverableException__fini(
  struct sidlx_rmi_RecoverableException__object* self,
  struct sidl_BaseInterface__object **_ex)
{
  struct sidlx_rmi_RecoverableException__object* s0 = self;
  struct sidl_rmi_ProtocolException__object*     s1 = &s0->d_sidl_rmi_protocolexception;
  struct sidl_rmi_NetworkException__object*      s2 = &s1->d_sidl_rmi_networkexception;
  struct sidl_io_IOException__object*            s3 = &s2->d_sidl_io_ioexception;
  struct sidl_SIDLException__object*             s4 = &s3->d_sidl_sidlexception;
  struct sidl_BaseClass__object*                 s5 = &s4->d_sidl_baseclass;

  *_ex  = NULL; /* default to no exception */

  (*(s0->d_epv->f__dtor))(s0,_ex); SIDL_CHECK(*_ex);

  s5->d_sidl_baseinterface.d_epv = s_par_epv__sidl_baseinterface;
  s5->d_epv                      = s_par_epv__sidl_baseclass;

  s4->d_sidl_baseexception.d_epv   = s_par_epv__sidl_baseexception;
  s4->d_sidl_io_serializable.d_epv = s_par_epv__sidl_io_serializable;
  s4->d_epv                        = s_par_epv__sidl_sidlexception;

  s3->d_sidl_runtimeexception.d_epv = s_par_epv__sidl_runtimeexception;
  s3->d_epv                         = s_par_epv__sidl_io_ioexception;

  s2->d_epv    = s_par_epv__sidl_rmi_networkexception;

  s1->d_epv    = s_par_epv__sidl_rmi_protocolexception;

  sidl_rmi_ProtocolException__fini(s1, _ex); SIDL_CHECK(*_ex);

  EXIT:
  return;
}

/*
 * VERSION: Return the version of the IOR used to generate this IOR.
 */

void
sidlx_rmi_RecoverableException__IOR_version(int32_t *major, int32_t *minor)
{
  *major = s_IOR_MAJOR_VERSION;
  *minor = s_IOR_MINOR_VERSION;
}

static const struct sidlx_rmi_RecoverableException__external
s_externalEntryPoints = {
  sidlx_rmi_RecoverableException__createObject,
  sidlx_rmi_RecoverableException__getSuperEPV,
  2, 
  0
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct sidlx_rmi_RecoverableException__external*
sidlx_rmi_RecoverableException__externals(void)
{
  return &s_externalEntryPoints;
}

