! 
! File:          sort_SimpleCounter_Mod.F90
! Symbol:        sort.SimpleCounter-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for sort.SimpleCounter
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_SimpleCounter_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_SimpleCounter_impl

  ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.use)
use sidl
  ! DO-NOT-DELETE splicer.end(sort.SimpleCounter.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_SimpleCounter_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.SimpleCounter.private_data)
   integer(kind=sidl_int) :: count
    ! DO-NOT-DELETE splicer.end(sort.SimpleCounter.private_data)
  end type sort_SimpleCounter_priv

  type sort_SimpleCounter_wrap
    sequence
    type(sort_SimpleCounter_priv), pointer :: d_private_data
  end type sort_SimpleCounter_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_SimpleCounter
    use sidl_BaseInterface
    implicit none
    ! out sort_SimpleCounter retval
    type(sort_SimpleCounter_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_SimpleCounter_wrap private_data
    type(sort_SimpleCounter_wrap), intent(in) :: private_data
    external sort_SimpleCounter_wrapObj_m
    call sort_SimpleCounter_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_SimpleCounter_impl
