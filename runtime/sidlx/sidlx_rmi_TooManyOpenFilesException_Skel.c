/*
 * File:          sidlx_rmi_TooManyOpenFilesException_Skel.c
 * Symbol:        sidlx.rmi.TooManyOpenFilesException-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
 * Description:   Server-side glue code for sidlx.rmi.TooManyOpenFilesException
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "sidlx_rmi_TooManyOpenFilesException_IOR.h"
#include "sidlx_rmi_TooManyOpenFilesException.h"
#include <stddef.h>

#ifdef WITH_RMI
#ifndef included_sidl_io_Deserializer_h
#include "sidl_io_Deserializer.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_io_Serializer_h
#include "sidl_io_Serializer.h"
#endif
#endif /* WITH_RMI */
extern
void
impl_sidlx_rmi_TooManyOpenFilesException__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_TooManyOpenFilesException__ctor(
  /* in */ sidlx_rmi_TooManyOpenFilesException self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_TooManyOpenFilesException__ctor2(
  /* in */ sidlx_rmi_TooManyOpenFilesException self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_sidlx_rmi_TooManyOpenFilesException__dtor(
  /* in */ sidlx_rmi_TooManyOpenFilesException self,
  /* out */ sidl_BaseInterface *_ex);

#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Deserializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_BaseInterface(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Serializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef WITH_RMI
extern struct sidl_io_Deserializer__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Deserializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_BaseInterface(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_io_Serializer__object* 
  impl_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Serializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex);
#endif /*WITH_RMI*/
#ifdef __cplusplus
extern "C" {
#endif

void
sidlx_rmi_TooManyOpenFilesException__set_epv(struct 
  sidlx_rmi_TooManyOpenFilesException__epv *epv)
{
  epv->f__ctor = impl_sidlx_rmi_TooManyOpenFilesException__ctor;
  epv->f__ctor2 = impl_sidlx_rmi_TooManyOpenFilesException__ctor2;
  epv->f__dtor = impl_sidlx_rmi_TooManyOpenFilesException__dtor;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sidlx_rmi_TooManyOpenFilesException__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_sidlx_rmi_TooManyOpenFilesException__load(&_throwaway_exception);
}
#ifdef WITH_RMI
struct sidl_io_Deserializer__object* 
  skel_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Deserializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Deserializer__connectI(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_BaseInterface(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_BaseInterface__connectI(url, ar, _ex);
}

struct sidl_io_Serializer__object* 
  skel_sidlx_rmi_TooManyOpenFilesException_fconnect_sidl_io_Serializer(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return sidl_io_Serializer__connectI(url, ar, _ex);
}

#endif /*WITH_RMI*/
struct sidlx_rmi_TooManyOpenFilesException__data*
sidlx_rmi_TooManyOpenFilesException__get_data(
  sidlx_rmi_TooManyOpenFilesException self)
{
  return (struct sidlx_rmi_TooManyOpenFilesException__data*)(self ? 
    self->d_data : NULL);
}

void sidlx_rmi_TooManyOpenFilesException__set_data(
  sidlx_rmi_TooManyOpenFilesException self,
  struct sidlx_rmi_TooManyOpenFilesException__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif