! 
! File:          sort_Integer_Mod.F90
! Symbol:        sort.Integer-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for sort.Integer
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_Integer_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_Integer_impl

  ! DO-NOT-DELETE splicer.begin(sort.Integer.use)
use sidl
  ! DO-NOT-DELETE splicer.end(sort.Integer.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_Integer_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.Integer.private_data)
   integer(kind=sidl_int) :: d_value
    ! DO-NOT-DELETE splicer.end(sort.Integer.private_data)
  end type sort_Integer_priv

  type sort_Integer_wrap
    sequence
    type(sort_Integer_priv), pointer :: d_private_data
  end type sort_Integer_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_Integer
    use sidl_BaseInterface
    implicit none
    ! out sort_Integer retval
    type(sort_Integer_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_Integer_wrap private_data
    type(sort_Integer_wrap), intent(in) :: private_data
    external sort_Integer_wrapObj_m
    call sort_Integer_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_Integer_impl
