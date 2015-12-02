/*
 * File:          cons_A_Skel.c
 * Symbol:        cons.A-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
 * Description:   Server-side glue code for cons.A
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "cons_A_IOR.h"
#include "cons_A.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_cons_A__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_A__ctor(
  /* in */ cons_A self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_A__ctor2(
  /* in */ cons_A self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_A__dtor(
  /* in */ cons_A self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_A_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
extern
void
impl_cons_A_init(
  /* in */ cons_A self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_cons_A_destruct(
  /* in */ cons_A self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_BaseInterface__object* 
  impl_cons_A_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
cons_A__set_epv(struct cons_A__epv *epv,
  struct cons_A__pre_epv *pre_epv, 
  struct cons_A__post_epv *post_epv
)
{
  epv->f__ctor = impl_cons_A__ctor;
  epv->f__ctor2 = impl_cons_A__ctor2;
  epv->f__dtor = impl_cons_A__dtor;
  pre_epv->f_init_pre = NULL;
  epv->f_init = impl_cons_A_init;
  post_epv->f_init_post = NULL;
  pre_epv->f_destruct_pre = NULL;
  epv->f_destruct = impl_cons_A_destruct;
  post_epv->f_destruct_post = NULL;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void cons_A__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_cons_A__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_BaseInterface__object* skel_cons_A_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct cons_A__data*
cons_A__get_data(cons_A self)
{
  return (struct cons_A__data*)(self ? self->d_data : NULL);
}

void cons_A__set_data(
  cons_A self,
  struct cons_A__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
