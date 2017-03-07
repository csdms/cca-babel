/*
 * File:          sidl_rmi_ConnectException_Impl.c
 * Symbol:        sidl.rmi.ConnectException-v0.9.17
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7435  trunk)
 * Release:       $Name:  $
 * Revision:      @(#) $Id: $
 * Description:   Server-side implementation for sidl.rmi.ConnectException
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
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "sidl.rmi.ConnectException" (version 0.9.17)
 * 
 * This exception is thrown by the RMI library when an 
 * attempt to connect to a remote host fails.
 */

#include "sidl_rmi_ConnectException_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(sidl.rmi.ConnectException._includes) */
/* Insert-Code-Here {sidl.rmi.ConnectException._includes} (includes and arbitrary code) */
/* DO-NOT-DELETE splicer.end(sidl.rmi.ConnectException._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ConnectException__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ConnectException__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ConnectException._load) */
  /* Insert-Code-Here {sidl.rmi.ConnectException._load} (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ConnectException._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ConnectException__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ConnectException__ctor(
  /* in */ sidl_rmi_ConnectException self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ConnectException._ctor) */
  /* Insert-Code-Here {sidl.rmi.ConnectException._ctor} (constructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ConnectException._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ConnectException__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ConnectException__ctor2(
  /* in */ sidl_rmi_ConnectException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ConnectException._ctor2) */
  /* Insert-Code-Here {sidl.rmi.ConnectException._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ConnectException._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_sidl_rmi_ConnectException__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_sidl_rmi_ConnectException__dtor(
  /* in */ sidl_rmi_ConnectException self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(sidl.rmi.ConnectException._dtor) */
  /* Insert-Code-Here {sidl.rmi.ConnectException._dtor} (destructor method) */
    /* DO-NOT-DELETE splicer.end(sidl.rmi.ConnectException._dtor) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

