! 
! File:          ExceptionTest_Fib_Mod.F90
! Symbol:        ExceptionTest.Fib-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for ExceptionTest.Fib
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "ExceptionTest_Fib_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module ExceptionTest_Fib_impl

  ! DO-NOT-DELETE splicer.begin(ExceptionTest.Fib.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.Fib.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type ExceptionTest_Fib_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(ExceptionTest.Fib.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(ExceptionTest.Fib.private_data)
  end type ExceptionTest_Fib_priv

  type ExceptionTest_Fib_wrap
    sequence
    type(ExceptionTest_Fib_priv), pointer :: d_private_data
  end type ExceptionTest_Fib_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use ExceptionTest_Fib
    use sidl_BaseInterface
    implicit none
    ! out ExceptionTest_Fib retval
    type(ExceptionTest_Fib_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in ExceptionTest_Fib_wrap private_data
    type(ExceptionTest_Fib_wrap), intent(in) :: private_data
    external ExceptionTest_Fib_wrapObj_m
    call ExceptionTest_Fib_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module ExceptionTest_Fib_impl
