/*
 * File:          sidl_rmi_ProtocolFactory_Impl.c
 * Symbol:        sidl.rmi.ProtocolFactory-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side implementation for sidl.rmi.ProtocolFactory
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
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidl.rmi.ProtocolFactory" (version 0.9.17)
 * 
 *  
 * This singleton class keeps a table of string prefixes
 * (e.g. "babel" or "proteus") to protocol implementations.  The
 * intent is to parse a URL (e.g. "babel://server:port/class") and
 * create classes that implement
 * <code>sidl.rmi.InstanceHandle</code>.
 */

#include "sidl_rmi_ProtocolFactory_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory._includes) */
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "sidl_String.h"
#include "sidl_DLL.h"
#include "sidl_Loader.h"
#include "sidl_BaseClass.h"
#include "sidl_rmi_InstanceHandle.h"
#include "sidl_Exception.h"
#include "sidl_rmi_NetworkException.h"
#ifdef HAVE_PTHREAD
#include "sidl_thread.h"
static struct sidl_recursive_mutex_t s_lock;
#endif
static char ** s_reg; /* s_reg[2*i] is associated w/ s_reg[2*i+1] */
static size_t s_len; /* really 2*s_len entries */
static size_t s_maxlen; /* 1/2 size of buffer malloc'd */


/* This function parses a url into the pointers provided (they are all out parameters)
   url, protocol, and server are required, and the method will throw an if they are
   null.  port, className, and objectID are optional, and may be passed in as NULL
*/ 
static char* get_prefix(const char* url, sidl_BaseInterface *_ex) {
  size_t i = 0;
  size_t length = 0;
  char* retval = NULL;
  if(url == NULL) {
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, "url is NULL\n");
  }

  length = strlen(url); /* includes terminating '\0' character */

  /* extract the protocol name */
  while ((i<length) && isalnum(url[i])) { 
    ++i;
  }
  
  if ( (i<=0) || (i>=length) ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, "url has no separable prefix\n");
  }

  if ((retval = malloc(i+1)) == NULL ) { 
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, "get_prefix", _ex);
    *_ex = (sidl_BaseInterface)ex;
    goto EXIT;
  }
  
  strncpy(retval, url, i);
  retval[i] = '\0';

  return retval;
 EXIT:
  if (retval) free(retval);
  return NULL;
}


/* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ProtocolFactory__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory._load) */
  s_maxlen=1024;
  s_reg = (char**) malloc ( sizeof(char*)*s_maxlen*2 );
  s_len = 0;
  if(!s_reg) {
    sidl_MemAllocException ex = sidl_MemAllocException_getSingletonException(_ex);
    sidl_MemAllocException_setNote(ex, "Out of memory.", _ex);
    sidl_MemAllocException_add(ex, __FILE__, __LINE__, "ProtocolFactory__load", _ex);
    *_ex = (sidl_BaseInterface)ex;
    goto EXIT;
  }
#ifdef HAVE_PTHREAD
    sidl_recursive_mutex_init(&s_lock);
#endif
  EXIT:;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ProtocolFactory__ctor(
  /* in */ sidl_rmi_ProtocolFactory self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ProtocolFactory__ctor2(
  /* in */ sidl_rmi_ProtocolFactory self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory._ctor2) */
  /* Insert-Code-Here {sidl.rmi.ProtocolFactory._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ProtocolFactory__dtor(
  /* in */ sidl_rmi_ProtocolFactory self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory._dtor) */
  }
}

/*
 *  
 * Associate a particular prefix in the URL to a typeName
 * <code>sidl.Loader</code> can find.  The actual type is
 * expected to implement <code>sidl.rmi.InstanceHandle</code>
 * Return true iff the addition is successful.  (no collisions
 * allowed)
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_addProtocol"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_sidl_rmi_ProtocolFactory_addProtocol(
  /* in */ const char* prefix,
  /* in */ const char* typeName,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.addProtocol) */
  size_t i;
  sidl_bool add_prefix=TRUE;

  /* push new protocol to back of list */
  if ( s_len >= s_maxlen ) { 
    ;/*TODO implement realloc */
  } 
  /* return false is prefix already exists */
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_lock(&s_lock);
#endif
  for (i=0;i<2*s_len;i+=2) { 
    if ( !strcmp( s_reg[i], prefix )) { 
      add_prefix = FALSE;
      break;
    }
  }

  /* now add prefix into list */
  if ( add_prefix == TRUE ) { 
    s_reg[2*s_len] = (char*)sidl_String_strdup(prefix);
    s_reg[2*s_len+1] = (char*) sidl_String_strdup(typeName);
    ++s_len;
  }
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return add_prefix;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.addProtocol) */
  }
}

/*
 * Return the typeName associated with a particular prefix.
 * Return empty string if the prefix
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_getProtocol"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sidl_rmi_ProtocolFactory_getProtocol(
  /* in */ const char* prefix,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.getProtocol) */
  int i;
  char* result = NULL;
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_lock(&s_lock);
#endif
  for (i=0;i<2*s_len;i+=2) { 
    if ( !strcmp( s_reg[i], prefix )) { 
      result = (char*) sidl_String_strdup( s_reg[i+1] );
      break;
    }
  }
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return result;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.getProtocol) */
  }
}

/*
 * Remove a protocol from the active list.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_deleteProtocol"

#ifdef __cplusplus
extern "C"
#endif
sidl_bool
impl_sidl_rmi_ProtocolFactory_deleteProtocol(
  /* in */ const char* prefix,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.deleteProtocol) */
  int i;
  sidl_bool success = FALSE;
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_lock(&s_lock);
#endif
  for (i=0;i<2*s_len;i+=2) { 
    if ( !strcmp( s_reg[i], prefix )) { 
      --s_len;
      if (i<2*s_len) { 
	/* swap i entry to back of list */
	char *tmp;
	tmp=s_reg[i];
	s_reg[i]=s_reg[2*s_len];
	s_reg[2*s_len]= tmp;
	tmp=s_reg[i+1];
	s_reg[i+1] = s_reg[2*s_len+1];
	s_reg[2*s_len+1] = tmp;
      }
      sidl_String_free(s_reg[2*s_len]);
      s_reg[2*s_len]=NULL;
      sidl_String_free(s_reg[2*s_len+1]);
      s_reg[2*s_len+1]=NULL;
      success = TRUE;
      break;
    }
  }
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return success;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.deleteProtocol) */
  }
}

/*
 * Create a new remote object and return an instance handle for that
 * object. 
 * The server and port number are in the url.  Return nil 
 * if protocol unknown or InstanceHandle.init() failed.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_createInstance"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_InstanceHandle
impl_sidl_rmi_ProtocolFactory_createInstance(
  /* in */ const char* url,
  /* in */ const char* typeName,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.createInstance) */
  char * prefix = NULL;
  char * protocol = NULL;
  sidl_BaseClass bc;
  sidl_rmi_InstanceHandle ih = NULL;
  sidl_DLL dll = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  if(!url) { return NULL;}
  prefix = get_prefix(url, _ex ); SIDL_CHECK(*_ex);

  /* now find the protocol associated with the prefix */
  
  protocol = sidl_rmi_ProtocolFactory_getProtocol( prefix, _ex ); SIDL_CHECK(*_ex);
  if ( protocol == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: prefix not found in ProtocolFactory\n"); 
  }
  dll = sidl_Loader_findLibrary( protocol, "ior/impl", 
				 sidl_Scope_SCLSCOPE, 
				 sidl_Resolve_SCLRESOLVE,_ex );SIDL_CHECK(*_ex);
  if ( dll == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be loaded\n"); 
  }
  bc = sidl_DLL_createClass( dll, protocol,_ex ); SIDL_CHECK(*_ex);
  if ( bc == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be created\n");
  }    
  ih = sidl_rmi_InstanceHandle__cast( bc, _ex ); SIDL_CHECK(*_ex);
  sidl_BaseClass_deleteRef(bc, _ex); SIDL_CHECK(*_ex);
  if ( ih == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol doesn't implement InstanceHandle\n");
  }
  sidl_rmi_InstanceHandle_initCreate( ih, url, typeName, _ex );
 EXIT:
  sidl_String_free(protocol);
  sidl_String_free(prefix);
  if(dll) {
    sidl_DLL_deleteRef(dll,&_throwaway_exception );
  }
  return ih;  /* On error, ih will be NULL*/
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.createInstance) */
  }
}

/*
 *  
 * Create an new connection linked to an already existing
 * object on a remote server.  The server and port number are in
 * the url, the objectID is the unique ID of the remote object
 * in the remote instance registry.  Return null if protocol
 * unknown or InstanceHandle.init() failed.  The boolean addRef
 * should be true if connect should remotely addRef
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_connectInstance"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_InstanceHandle
impl_sidl_rmi_ProtocolFactory_connectInstance(
  /* in */ const char* url,
  /* in */ const char* typeName,
  /* in */ sidl_bool ar,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.connectInstance) */
  char * prefix = NULL;
  char * protocol = NULL;
  sidl_BaseClass bc = NULL;
  sidl_rmi_InstanceHandle ih = NULL;
  sidl_DLL dll = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  int32_t success = 0;

  if(!url) { return NULL;}
  prefix = get_prefix(url, _ex ); SIDL_CHECK(*_ex);

  /* now find the protocol associated with the prefix */
  
  protocol = sidl_rmi_ProtocolFactory_getProtocol( prefix, _ex );SIDL_CHECK(*_ex);
  if ( protocol == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: prefix not found in ProtocolFactory\n"); 
  }

  dll = sidl_Loader_findLibrary( protocol, "ior/impl", 
				 sidl_Scope_SCLSCOPE, 
				 sidl_Resolve_SCLRESOLVE, _ex );SIDL_CHECK(*_ex);
  if ( dll == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be loaded\n"); 
  }
  bc = sidl_DLL_createClass( dll, protocol, _ex );SIDL_CHECK(*_ex);
  if ( bc == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be created\n");
  }    
  ih = sidl_rmi_InstanceHandle__cast( bc, _ex); SIDL_CHECK(*_ex);
  sidl_BaseClass_deleteRef(bc, _ex); SIDL_CHECK(*_ex);
  if ( ih == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol doesn't implement InstanceHandle\n");
  }
  success = sidl_rmi_InstanceHandle_initConnect( ih, url, typeName, ar, _ex ); SIDL_CHECK(*_ex);
  if(success == 0) { goto EXIT; } 

  return ih;

 EXIT:
  sidl_String_free(protocol);
  sidl_String_free(prefix);
  if(dll) {
    sidl_DLL_deleteRef(dll,&_throwaway_exception);
  }
  if(ih) { sidl_rmi_InstanceHandle_deleteRef(ih, &_throwaway_exception); ih = NULL; }
  return ih; /* Will be NULL if there is a problem*/
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.connectInstance) */
  }
}

/*
 *  
 * Request that a remote object be serialized to you.  The server 
 * and port number are in the url, the objectID is the unique ID 
 * of the remote object in the remote instance registry.  Return 
 * null if protocol unknown or InstanceHandle.init() failed.  
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ProtocolFactory_unserializeInstance"

#ifdef __cplusplus
extern "C"
#endif
sidl_io_Serializable
impl_sidl_rmi_ProtocolFactory_unserializeInstance(
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ProtocolFactory.unserializeInstance) */
  char * prefix = NULL;
  char * protocol = NULL;
  sidl_BaseClass bc = NULL;
  sidl_rmi_InstanceHandle ih = NULL;
  sidl_DLL dll = NULL;
  sidl_io_Serializable dser = NULL;
  sidl_BaseInterface _throwaway_exception = NULL;
  if(!url) { return NULL;}
  prefix = get_prefix(url, _ex ); SIDL_CHECK(*_ex);

  /* now find the protocol associated with the prefix */
  
  protocol = sidl_rmi_ProtocolFactory_getProtocol( prefix, _ex ); SIDL_CHECK(*_ex);
  if ( protocol == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: prefix not found in ProtocolFactory\n"); 
  }
  
  dll = sidl_Loader_findLibrary( protocol, "ior/impl", 
				 sidl_Scope_SCLSCOPE, 
				 sidl_Resolve_SCLRESOLVE,_ex );SIDL_CHECK(*_ex);
  if ( dll == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be loaded\n"); 
  }
  bc = sidl_DLL_createClass( dll, protocol,_ex ); SIDL_CHECK(*_ex);
  if ( bc == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol cannot be created\n");
  }    
  ih = sidl_rmi_InstanceHandle__cast( bc, _ex ); SIDL_CHECK(*_ex);
  sidl_BaseClass_deleteRef(bc, _ex); SIDL_CHECK(*_ex);
  if ( ih == NULL ) { 
    SIDL_THROW(*_ex, sidl_rmi_NetworkException, 
	       "sidl.rmi.ProtocolFactory: Protocol doesn't implement InstanceHandle\n");
  }
  dser = sidl_rmi_InstanceHandle_initUnserialize( ih, url, _ex );
 EXIT:
  sidl_String_free(protocol);
  sidl_String_free(prefix);
  if(dll) { sidl_DLL_deleteRef(dll, &_throwaway_exception);  }
  if(ih) {sidl_rmi_InstanceHandle_deleteRef(ih, &_throwaway_exception);}
  return dser;  /* On error, dser will be NULL*/

    /* DO-NOT-DELETE splicer.end(sidl.rmi.ProtocolFactory.unserializeInstance) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

