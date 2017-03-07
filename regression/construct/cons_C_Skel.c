/*
 * File:          cons_C_Skel.c
 * Symbol:        cons.C-v1.0
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7372  trunk)
 * Description:   Server-side glue code for cons.C
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "cons_C_IOR.h"
#include "cons_C.h"
#include <stddef.h>
#include "cons_C_IOR.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.h"
#endif

extern void cons_C__superEPV(
struct cons_B__epv*);
/*
 * Hold pointer to IOR functions.
 */

static const struct cons_C__external *_externals = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct cons_C__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _externals = cons_C__externals();
#else
  _externals = (struct cons_C__external*)sidl_dynamicLoadIOR("cons.C",
    "cons_C__externals") ;
  sidl_checkIORVersion("cons.C", _externals->d_ior_major_version, 
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
extern void cons_C__superEPV(
struct cons_B__epv*);

extern
void
impl_cons_C__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_C__ctor(
  /* in */ cons_C self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_C__ctor2(
  /* in */ cons_C self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_C__dtor(
  /* in */ cons_C self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_C_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_cons_C_init(
  /* in */ cons_C self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_C_destruct(
  /* in */ cons_C self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_C_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
cons_C__set_epv(struct cons_C__epv *epv,
  struct cons_C__pre_epv *pre_epv, 
  struct cons_C__post_epv *post_epv
)
{
  epv->f__ctor = impl_cons_C__ctor;
  epv->f__ctor2 = impl_cons_C__ctor2;
  epv->f__dtor = impl_cons_C__dtor;
  pre_epv->f_init_pre = NULL;
  epv->f_init = impl_cons_C_init;
  post_epv->f_init_post = NULL;
  pre_epv->f_destruct_pre = NULL;
  epv->f_destruct = impl_cons_C_destruct;
  post_epv->f_destruct_post = NULL;

  cons_C__superEPV(_getExternals()->getSuperEPV());
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void cons_C__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_cons_C__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* skel_cons_C_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct cons_C__data*
cons_C__get_data(cons_C self)
{
  return (struct cons_C__data*)(self ? self->d_data : NULL);
}

void cons_C__set_data(
  cons_C self,
  struct cons_C__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
