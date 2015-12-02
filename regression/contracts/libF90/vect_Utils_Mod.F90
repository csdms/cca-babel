! 
! File:          vect_Utils_Mod.F90
! Symbol:        vect.Utils-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
! Description:   Server-side private data module for vect.Utils
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "vect_Utils_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module vect_Utils_impl

  ! DO-NOT-DELETE splicer.begin(vect.Utils.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(vect.Utils.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type vect_Utils_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(vect.Utils.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(vect.Utils.private_data)
  end type vect_Utils_priv

  type vect_Utils_wrap
    sequence
    type(vect_Utils_priv), pointer :: d_private_data
  end type vect_Utils_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use vect_Utils
    use sidl_BaseInterface
    implicit none
    ! out vect_Utils retval
    type(vect_Utils_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in vect_Utils_wrap private_data
    type(vect_Utils_wrap), intent(in) :: private_data
    external vect_Utils_wrapObj_m
    call vect_Utils_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module vect_Utils_impl
