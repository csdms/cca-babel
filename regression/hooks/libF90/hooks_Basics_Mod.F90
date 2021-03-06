! 
! File:          hooks_Basics_Mod.F90
! Symbol:        hooks.Basics-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
! Description:   Server-side private data module for hooks.Basics
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "hooks_Basics_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! insert code here (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module hooks_Basics_impl

  ! DO-NOT-DELETE splicer.begin(hooks.Basics.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(hooks.Basics.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type hooks_Basics_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(hooks.Basics.private_data)
    ! insert code here (private data members)
    integer :: place_holder ! replace with your private data
    ! DO-NOT-DELETE splicer.end(hooks.Basics.private_data)
  end type hooks_Basics_priv

  type hooks_Basics_wrap
    sequence
    type(hooks_Basics_priv), pointer :: d_private_data
  end type hooks_Basics_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use hooks_Basics
    use sidl_BaseInterface
    implicit none
    ! out hooks_Basics retval
    type(hooks_Basics_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in hooks_Basics_wrap private_data
    type(hooks_Basics_wrap), intent(in) :: private_data
    external hooks_Basics_wrapObj_m
    call hooks_Basics_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module hooks_Basics_impl
