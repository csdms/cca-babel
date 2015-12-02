/*
 * File:          sidl_rmi_ServerRegistry_Impl.c
 * Symbol:        sidl.rmi.ServerRegistry-v0.9.17
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side implementation for sidl.rmi.ServerRegistry
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
 * Symbol "sidl.rmi.ServerRegistry" (version 0.9.17)
 * 
 *  
 * This singleton class is simply a place to register a
 * ServerInfo interface for general access.  This ServerInfo
 * should give info about the ORB being used to export RMI objects
 * for the current Babel process.
 * 
 * This Registry provides two important functions, a way to get
 * the URL for local object we wish to expose over RMI, and a way
 * to tell if an object passed to this process via RMI is actually
 * a local object.  This abilities are protocol specific, the
 * ServerInfo interface must by implemented by the protocol
 * writer.
 * 
 * THIS CLASS IS NOT DESIGNED FOR CONCURRENT WRITE ACCESS.  (Only
 * one server is assumed per Babel process)
 */

#include "sidl_rmi_ServerRegistry_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry._includes) */
#include "sidl_String.h"
#include "sidl_Exception.h"
#include "sidl_rmi_NoServerException.h"
#include "sidl_rmi_NetworkException.h"
#include "sidlOps.h"

#ifdef HAVE_PTHREAD
/* #include <pthread.h> */
/* static pthread_mutex_t s_lock; */
#include "sidl_thread.h"
static struct sidl_recursive_mutex_t s_lock;
#endif
static sidl_rmi_ServerInfo s_si;

/**
 * Called by atexit().  Same as calling registerServer with a NULL argument.
 */
static void s_clearServer(void* ignore) {
  sidl_BaseInterface throwaway_exception;
  if(s_si) {
    sidl_rmi_ServerInfo_deleteRef(s_si, &throwaway_exception);
  }
  s_si = NULL;
}

/* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ServerRegistry__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry._load) */
  s_si = NULL;
#ifdef HAVE_PTHREAD
  sidl_recursive_mutex_init(&s_lock);
#endif 
  sidl_atexit(s_clearServer, NULL);
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ServerRegistry__ctor(
  /* in */ sidl_rmi_ServerRegistry self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry._ctor) */
  /* Insert-Code-Here {sidl.rmi.ServerRegistry._ctor} (constructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ServerRegistry__ctor2(
  /* in */ sidl_rmi_ServerRegistry self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry._ctor2) */
  /* Insert-Code-Here {sidl.rmi.ServerRegistry._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ServerRegistry__dtor(
  /* in */ sidl_rmi_ServerRegistry self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry._dtor) */
  /* Insert-Code-Here {sidl.rmi.ServerRegistry._dtor} (destructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry._dtor) */
  }
}

/*
 * Register the server with the ServerRegistry.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry_registerServer"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ServerRegistry_registerServer(
  /* in */ sidl_rmi_ServerInfo si,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry.registerServer) */
#ifdef HAVE_PTHREAD
  /* pthread_mutex_lock(&s_lock); */
  sidl_recursive_mutex_lock(&s_lock);
#endif
  if(si) {
    sidl_rmi_ServerInfo_addRef(si, _ex); SIDL_CHECK(*_ex);
  }
  if(s_si) {
    sidl_rmi_ServerInfo_deleteRef(s_si, _ex); SIDL_CHECK(*_ex);
  }
  s_si = si;
 EXIT:
#ifdef HAVE_PTHREAD
  /* pthread_mutex_unlock(&s_lock); */
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return;

    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry.registerServer) */
  }
}

/*
 * Get the registered server from the Server Registery.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry_getServer"

#ifdef __cplusplus
extern "C"
#endif
sidl_rmi_ServerInfo
impl_sidl_rmi_ServerRegistry_getServer(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry.getServer) */
    if(s_si) {
      sidl_rmi_ServerInfo_addRef(s_si, _ex); 
    }
    return s_si;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry.getServer) */
  }
}

/*
 * Perhaps this should take BaseClass and look the objectID up in 
 * the Instance Registry
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry_getServerURL"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sidl_rmi_ServerRegistry_getServerURL(
  /* in */ const char* objID,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry.getServerURL) */
  char* result = NULL;
#ifdef HAVE_PTHREAD
  /* pthread_mutex_lock(&s_lock); */
  sidl_recursive_mutex_lock(&s_lock);
#endif
  if(s_si) {
    result=sidl_rmi_ServerInfo_getServerURL(s_si, objID, _ex); SIDL_CHECK(*_ex); 
  } else { 
    SIDL_THROW(*_ex, sidl_rmi_NoServerException, 
	       "sidl.rmi.ServerRegistry.getServerURL: There is no server running\n");
  }
 EXIT:
#ifdef HAVE_PTHREAD
 /* pthread_mutex_unlock(&s_lock); */
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return result;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry.getServerURL) */
  }
}

/*
 * For internal Babel use ONLY. Needed by Babel to determine if a 
 * url points to a local or remote object.  Returns the objectID 
 * if is local, Null otherwise.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry_isLocalObject"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_sidl_rmi_ServerRegistry_isLocalObject(
  /* in */ const char* url,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry.isLocalObject) */
  char * result = NULL;
#ifdef HAVE_PTHREAD
  /* pthread_mutex_lock(&s_lock); */
  sidl_recursive_mutex_lock(&s_lock);
#endif
  if(s_si) {
    result = sidl_rmi_ServerInfo_isLocalObject(s_si, url, _ex);
  }
#ifdef HAVE_PTHREAD
 /* pthread_mutex_unlock(&s_lock); */
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return result;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry.isLocalObject) */
  }
}

/*
 *  
 * This gets an array of logged exceptions.  If an exception
 * can not be thrown back to the caller, we log it with the
 * Server.  This gets the array of all those exceptions.  THIS
 * IS SOMETHING OF A TEST! THIS MAY CHANGE!
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ServerRegistry_getExceptions"

#ifdef __cplusplus
extern "C"
#endif
struct sidl_io_Serializable__array*
impl_sidl_rmi_ServerRegistry_getExceptions(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ServerRegistry.getExceptions) */
   struct sidl_io_Serializable__array* result;
#ifdef HAVE_PTHREAD
  /* pthread_mutex_lock(&s_lock); */
  sidl_recursive_mutex_lock(&s_lock);
#endif
  result = sidl_rmi_ServerInfo_getExceptions(s_si, _ex);
#ifdef HAVE_PTHREAD
 /* pthread_mutex_unlock(&s_lock); */
  sidl_recursive_mutex_unlock(&s_lock);
#endif
  return result;
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ServerRegistry.getExceptions) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

