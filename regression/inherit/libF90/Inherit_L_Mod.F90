! 
! File:          Inherit_L_Mod.F90
! Symbol:        Inherit.L-v1.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for Inherit.L
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "Inherit_L_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module Inherit_L_impl

  ! DO-NOT-DELETE splicer.begin(Inherit.L.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(Inherit.L.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type Inherit_L_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(Inherit.L.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(Inherit.L.private_data)
  end type Inherit_L_priv

  type Inherit_L_wrap
    sequence
    type(Inherit_L_priv), pointer :: d_private_data
  end type Inherit_L_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use Inherit_L
    use sidl_BaseInterface
    implicit none
    ! out Inherit_L retval
    type(Inherit_L_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in Inherit_L_wrap private_data
    type(Inherit_L_wrap), intent(in) :: private_data
    external Inherit_L_wrapObj_m
    call Inherit_L_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module Inherit_L_impl
