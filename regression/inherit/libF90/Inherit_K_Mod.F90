! 
! File:          Inherit_K_Mod.F90
! Symbol:        Inherit.K-v1.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side private data module for Inherit.K
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "Inherit_K_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module Inherit_K_impl

  ! DO-NOT-DELETE splicer.begin(Inherit.K.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(Inherit.K.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type Inherit_K_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(Inherit.K.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(Inherit.K.private_data)
  end type Inherit_K_priv

  type Inherit_K_wrap
    sequence
    type(Inherit_K_priv), pointer :: d_private_data
  end type Inherit_K_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use Inherit_K
    use sidl_BaseInterface
    implicit none
    ! out Inherit_K retval
    type(Inherit_K_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in Inherit_K_wrap private_data
    type(Inherit_K_wrap), intent(in) :: private_data
    external Inherit_K_wrapObj_m
    call Inherit_K_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module Inherit_K_impl
