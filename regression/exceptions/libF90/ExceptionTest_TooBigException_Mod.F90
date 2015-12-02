! 
! File:          ExceptionTest_TooBigException_Mod.F90
! Symbol:        ExceptionTest.TooBigException-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for ExceptionTest.TooBigException
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "ExceptionTest_TooBigException_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module ExceptionTest_TooBigException_impl

  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type ExceptionTest_TooBigException_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException.private_data)
  end type ExceptionTest_TooBigException_priv

  type ExceptionTest_TooBigException_wrap
    sequence
    type(ExceptionTest_TooBigException_priv), pointer :: d_private_data
  end type ExceptionTest_TooBigException_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use ExceptionTest_TooBigException
    use sidl_BaseInterface
    implicit none
    ! out ExceptionTest_TooBigException retval
    type(ExceptionTest_TooBigException_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in ExceptionTest_TooBigException_wrap private_data
    type(ExceptionTest_TooBigException_wrap), intent(in) :: private_data
    external ExceptionTest_TooBigException_wrapObj_m
    call ExceptionTest_TooBigException_wrapObj_m(private_data, retval,         &
      exception)
   end subroutine wrapObj_s
end module ExceptionTest_TooBigException_impl
