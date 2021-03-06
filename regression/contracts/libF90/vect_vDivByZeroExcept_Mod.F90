! 
! File:          vect_vDivByZeroExcept_Mod.F90
! Symbol:        vect.vDivByZeroExcept-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
! Description:   Server-side private data module for vect.vDivByZeroExcept
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "vect_vDivByZeroExcept_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module vect_vDivByZeroExcept_impl

  ! DO-NOT-DELETE splicer.begin(vect.vDivByZeroExcept.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(vect.vDivByZeroExcept.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type vect_vDivByZeroExcept_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(vect.vDivByZeroExcept.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(vect.vDivByZeroExcept.private_data)
  end type vect_vDivByZeroExcept_priv

  type vect_vDivByZeroExcept_wrap
    sequence
    type(vect_vDivByZeroExcept_priv), pointer :: d_private_data
  end type vect_vDivByZeroExcept_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use vect_vDivByZeroExcept
    use sidl_BaseInterface
    implicit none
    ! out vect_vDivByZeroExcept retval
    type(vect_vDivByZeroExcept_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in vect_vDivByZeroExcept_wrap private_data
    type(vect_vDivByZeroExcept_wrap), intent(in) :: private_data
    external vect_vDivByZeroExcept_wrapObj_m
    call vect_vDivByZeroExcept_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module vect_vDivByZeroExcept_impl
