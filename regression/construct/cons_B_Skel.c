/*
 * File:          cons_B_Skel.c
 * Symbol:        cons.B-v1.0
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7372  trunk)
 * Description:   Server-side glue code for cons.B
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "cons_B_IOR.h"
#include "cons_B.h"
#include <stddef.h>
#include "cons_B_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void cons_B__superEPV(
struct cons_A__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct cons_B__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct cons_B__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _externals = cons_B__externals();
#else
  _externals = (struct cons_B__external*)sidl_dynamicLoadIOR("cons.B",
    "cons_B__externals") ;
  sidl_checkIORVersion("cons.B", _externals->d_ior_major_version, 
    _externals->d_ior_minor_version, 2, 0);
#endif
  return _externals;
}

#define _getExternals() (_externals ? _externals : _loadIOR())


#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern void cons_B__superEPV(
struct cons_A__epv*);

extern
void
impl_cons_B__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_B__ctor(
  /* in */ cons_B self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_B__ctor2(
  /* in */ cons_B self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_B__dtor(
  /* in */ cons_B self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_B_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_cons_B_init(
  /* in */ cons_B self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_B_destruct(
  /* in */ cons_B self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_B_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
cons_B__set_epv(struct cons_B__epv *epv,
  struct cons_B__pre_epv *pre_epv, 
  struct cons_B__post_epv *post_epv
)
{
  epv->f__ctor = impl_cons_B__ctor;
  epv->f__ctor2 = impl_cons_B__ctor2;
  epv->f__dtor = impl_cons_B__dtor;
  pre_epv->f_init_pre = NULL;
  epv->f_init = impl_cons_B_init;
  post_epv->f_init_post = NULL;
  pre_epv->f_destruct_pre = NULL;
  epv->f_destruct = impl_cons_B_destruct;
  post_epv->f_destruct_post = NULL;

  cons_B__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void cons_B__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_cons_B__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* skel_cons_B_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct cons_B__data*
cons_B__get_data(cons_B self)
{
  return (struct cons_B__data*)(self ? self->d_data : NULL);
}

void cons_B__set_data(
  cons_B self,
  struct cons_B__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
