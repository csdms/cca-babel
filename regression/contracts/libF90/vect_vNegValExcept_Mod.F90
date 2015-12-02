! 
! File:          vect_vNegValExcept_Mod.F90
! Symbol:        vect.vNegValExcept-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
! Description:   Server-side private data module for vect.vNegValExcept
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "vect_vNegValExcept_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module vect_vNegValExcept_impl

  ! DO-NOT-DELETE splicer.begin(vect.vNegValExcept.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(vect.vNegValExcept.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type vect_vNegValExcept_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(vect.vNegValExcept.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(vect.vNegValExcept.private_data)
  end type vect_vNegValExcept_priv

  type vect_vNegValExcept_wrap
    sequence
    type(vect_vNegValExcept_priv), pointer :: d_private_data
  end type vect_vNegValExcept_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use vect_vNegValExcept
    use sidl_BaseInterface
    implicit none
    ! out vect_vNegValExcept retval
    type(vect_vNegValExcept_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in vect_vNegValExcept_wrap private_data
    type(vect_vNegValExcept_wrap), intent(in) :: private_data
    external vect_vNegValExcept_wrapObj_m
    call vect_vNegValExcept_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module vect_vNegValExcept_impl
