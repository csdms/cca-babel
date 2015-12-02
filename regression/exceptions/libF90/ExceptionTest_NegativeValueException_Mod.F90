! 
! File:          ExceptionTest_NegativeValueException_Mod.F90
! Symbol:        ExceptionTest.NegativeValueException-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for ExceptionTest.NegativeValueException
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "ExceptionTest_NegativeValueException_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module ExceptionTest_NegativeValueException_impl

  ! DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type ExceptionTest_NegativeValueException_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException.private_data)
  end type ExceptionTest_NegativeValueException_priv

  type ExceptionTest_NegativeValueException_wrap
    sequence
    type(ExceptionTest_NegativeValueException_priv), pointer :: d_private_data
  end type ExceptionTest_NegativeValueException_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use ExceptionTest_NegativeValueException
    use sidl_BaseInterface
    implicit none
    ! out ExceptionTest_NegativeValueException retval
    type(ExceptionTest_NegativeValueException_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in ExceptionTest_NegativeValueException_wrap private_data
    type(ExceptionTest_NegativeValueException_wrap), intent(in) ::             &
      private_data
    external ExceptionTest_NegativeValueException_wrapObj_m
    call ExceptionTest_NegativeValueException_wrapObj_m(private_data, retval,  &
      exception)
   end subroutine wrapObj_s
end module ExceptionTest_NegativeValueException_impl
