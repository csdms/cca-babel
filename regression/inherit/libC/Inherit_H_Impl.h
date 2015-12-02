/*
 * File:          Inherit_H_Impl.h
 * Symbol:        Inherit.H-v1.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side implementation for Inherit.H
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_Inherit_H_Impl_h
#define included_Inherit_H_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_Inherit_A_h
#include "Inherit_A.h"
#endif
#ifndef included_Inherit_H_h
#include "Inherit_H.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif
/* DO-NOT-DELETE splicer.begin(Inherit.H._hincludes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(Inherit.H._hincludes) */

/*
 * Private data for class Inherit.H
 */

struct Inherit_H__data {
  /* DO-NOT-DELETE splicer.begin(Inherit.H._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(Inherit.H._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct Inherit_H__data*
Inherit_H__get_data(
  Inherit_H);

extern void
Inherit_H__set_data(
  Inherit_H,
  struct Inherit_H__data*);

extern
void
impl_Inherit_H__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_Inherit_H__ctor(
  /* in */ Inherit_H self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_Inherit_H__ctor2(
  /* in */ Inherit_H self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_Inherit_H__dtor(
  /* in */ Inherit_H self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_Inherit_H_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_Inherit_H_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/

/* DO-NOT-DELETE splicer.begin(_hmisc) */
/* Insert-Code-Here {_hmisc} (miscellaneous things) */
/* DO-NOT-DELETE splicer.end(_hmisc) */

#ifdef __cplusplus
}
#endif
#endif
