! 
! File:          sort_SimpleCounter_Impl.F90
! Symbol:        sort.SimpleCounter-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side implementation for sort.SimpleCounter
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.SimpleCounter" (version 0.1)
! 
! Simple counter
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sort_SimpleCounter_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sort_Counter_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine sort_SimpleCounter__ctor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor)
  type(sort_SimpleCounter_wrap) :: dp
  allocate(dp%d_private_data)
  dp%d_private_data%count = 0
  call sort_SimpleCounter__set_data_m(self, dp)
! DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor)
end subroutine sort_SimpleCounter__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_SimpleCounter__ctor2_mi(self, private_data,          &
  exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor2.use)
  ! Insert-Code-Here {sort.SimpleCounter._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor2.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  type(sort_SimpleCounter_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor2)
! Insert-Code-Here {sort.SimpleCounter._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor2)
end subroutine sort_SimpleCounter__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_SimpleCounter__dtor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor)
  type(sort_SimpleCounter_wrap) :: dp
  call sort_SimpleCounter__get_data_m(self, dp)
  deallocate(dp%d_private_data)
! DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor)
end subroutine sort_SimpleCounter__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_SimpleCounter__load_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.SimpleCounter._load)
end subroutine sort_SimpleCounter__load_mi


! 
! Method:  reset[]
! Set the count to zero.
! 

recursive subroutine sort_SimpleCounter_reset_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset)
  type(sort_SimpleCounter_wrap) :: dp
  call sort_SimpleCounter__get_data_m(self, dp)
  dp%d_private_data%count = 0
! DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset)
end subroutine sort_SimpleCounter_reset_mi


! 
! Method:  getCount[]
! Return the current count.
! 

recursive subroutine sort_SimpleCounter_getCount_mi(self, retval, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  integer (kind=sidl_int) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount)
  type(sort_SimpleCounter_wrap) :: dp
  call sort_SimpleCounter__get_data_m(self, dp)
  retval = dp%d_private_data%count
! DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount)
end subroutine sort_SimpleCounter_getCount_mi


! 
! Method:  inc[]
! Increment the count (i.e. add one).
! 

recursive subroutine sort_SimpleCounter_inc_mi(self, retval, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SimpleCounter
  use sort_SimpleCounter_impl
  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc.use)
  implicit none
  type(sort_SimpleCounter_t) :: self
  ! in
  integer (kind=sidl_int) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc)
  type(sort_SimpleCounter_wrap) :: dp
  call sort_SimpleCounter__get_data_m(self, dp)
  dp%d_private_data%count = dp%d_private_data%count + 1
  retval = dp%d_private_data%count
! DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc)
end subroutine sort_SimpleCounter_inc_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
