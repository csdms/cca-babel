/*
 * File:          Inherit_I_Impl.c
 * Symbol:        Inherit.I-v1.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for Inherit.I
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "Inherit.I" (version 1.1)
 */

#include "Inherit_I_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"
#ifndef included_sidl_MemAllocException_h
#include "sidl_MemAllocException.h"
#endif

/* DO-NOT-DELETE splicer.begin(Inherit.I._includes) */
#include <stdlib.h>
#include "sidl_String.h"
/* DO-NOT-DELETE splicer.end(Inherit.I._includes) */

#define SIDL_IOR_MAJOR_VERSION 2
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_Inherit_I__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I._load) */
  /* Insert the implementation of the static class initializer method here... */
    /* DO-NOT-DELETE splicer.end(Inherit.I._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_Inherit_I__ctor(
  /* in */ Inherit_I self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I._ctor) */
  /* Insert the implementation of the constructor method here... */
    /* DO-NOT-DELETE splicer.end(Inherit.I._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_Inherit_I__ctor2(
  /* in */ Inherit_I self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I._ctor2) */
  /* Insert-Code-Here {Inherit.I._ctor2} (special constructor method) */
    /* DO-NOT-DELETE splicer.end(Inherit.I._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_Inherit_I__dtor(
  /* in */ Inherit_I self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I._dtor) */
  /* Insert the implementation of the destructor method here... */
    /* DO-NOT-DELETE splicer.end(Inherit.I._dtor) */
  }
}

/*
 * Method:  a[]
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I_a"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_Inherit_I_a(
  /* in */ Inherit_I self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I.a) */
  return sidl_String_strdup("I.a");
    /* DO-NOT-DELETE splicer.end(Inherit.I.a) */
  }
}

/*
 * Method:  h[]
 */

#undef __FUNC__
#define __FUNC__ "impl_Inherit_I_h"

#ifdef __cplusplus
extern "C"
#endif
char*
impl_Inherit_I_h(
  /* in */ Inherit_I self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(Inherit.I.h) */
  return sidl_String_strdup("I.h");
    /* DO-NOT-DELETE splicer.end(Inherit.I.h) */
  }
}
/* Babel internal methods, Users should not edit below this line. */

/* DO-NOT-DELETE splicer.begin(_misc) */
/* Insert-Code-Here {_misc} (miscellaneous code) */
/* DO-NOT-DELETE splicer.end(_misc) */

