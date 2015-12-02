! 
! File:          wrapper_User_Mod.F90
! Symbol:        wrapper.User-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
! Description:   Server-side private data module for wrapper.User
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "wrapper_User_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module wrapper_User_impl

  ! DO-NOT-DELETE splicer.begin(wrapper.User.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(wrapper.User.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type wrapper_User_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(wrapper.User.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(wrapper.User.private_data)
  end type wrapper_User_priv

  type wrapper_User_wrap
    sequence
    type(wrapper_User_priv), pointer :: d_private_data
  end type wrapper_User_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use wrapper_User
    use sidl_BaseInterface
    implicit none
    ! out wrapper_User retval
    type(wrapper_User_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in wrapper_User_wrap private_data
    type(wrapper_User_wrap), intent(in) :: private_data
    external wrapper_User_wrapObj_m
    call wrapper_User_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module wrapper_User_impl
