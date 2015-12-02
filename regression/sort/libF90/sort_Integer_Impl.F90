! 
! File:          sort_Integer_Impl.F90
! Symbol:        sort.Integer-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side implementation for sort.Integer
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.Integer" (version 0.1)
! 
! An object to hold a simple integer.
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sort_Integer_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine sort_Integer__ctor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.Integer._ctor.use)
  implicit none
  type(sort_Integer_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer._ctor)
  type(sort_Integer_wrap) :: dp
  allocate(dp%d_private_data)
  dp%d_private_data%d_value = 0
  call sort_Integer__set_data_m(self, dp)
! DO-NOT-DELETE splicer.end(sort.Integer._ctor)
end subroutine sort_Integer__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_Integer__ctor2_mi(self, private_data, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer._ctor2.use)
  ! Insert-Code-Here {sort.Integer._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.Integer._ctor2.use)
  implicit none
  type(sort_Integer_t) :: self
  ! in
  type(sort_Integer_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer._ctor2)
! Insert-Code-Here {sort.Integer._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.Integer._ctor2)
end subroutine sort_Integer__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_Integer__dtor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.Integer._dtor.use)
  implicit none
  type(sort_Integer_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer._dtor)
  type(sort_Integer_wrap) :: dp
  call sort_Integer__get_data_m(self, dp)
  deallocate(dp%d_private_data)
! DO-NOT-DELETE splicer.end(sort.Integer._dtor)
end subroutine sort_Integer__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_Integer__load_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.Integer._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.Integer._load)
end subroutine sort_Integer__load_mi


! 
! Method:  getValue[]
! 

recursive subroutine sort_Integer_getValue_mi(self, retval, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer.getValue.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.Integer.getValue.use)
  implicit none
  type(sort_Integer_t) :: self
  ! in
  integer (kind=sidl_int) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer.getValue)
  type(sort_Integer_wrap) :: dp
  call sort_Integer__get_data_m(self, dp)
  retval = dp%d_private_data%d_value
! DO-NOT-DELETE splicer.end(sort.Integer.getValue)
end subroutine sort_Integer_getValue_mi


! 
! Method:  setValue[]
! 

recursive subroutine sort_Integer_setValue_mi(self, value, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  use sort_Integer_impl
  ! DO-NOT-DELETE splicer.begin(sort.Integer.setValue.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.Integer.setValue.use)
  implicit none
  type(sort_Integer_t) :: self
  ! in
  integer (kind=sidl_int) :: value
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.Integer.setValue)
  type(sort_Integer_wrap) :: dp
  call sort_Integer__get_data_m(self, dp)
  dp%d_private_data%d_value = value
! DO-NOT-DELETE splicer.end(sort.Integer.setValue)
end subroutine sort_Integer_setValue_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
