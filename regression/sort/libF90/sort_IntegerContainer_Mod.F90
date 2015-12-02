! 
! File:          sort_IntegerContainer_Mod.F90
! Symbol:        sort.IntegerContainer-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for sort.IntegerContainer
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_IntegerContainer_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_IntegerContainer_impl

  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.use)
  use sort_Integer_type
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_IntegerContainer_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.private_data)
  type(sort_Integer_1d) :: d_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.private_data)
  end type sort_IntegerContainer_priv

  type sort_IntegerContainer_wrap
    sequence
    type(sort_IntegerContainer_priv), pointer :: d_private_data
  end type sort_IntegerContainer_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_IntegerContainer
    use sidl_BaseInterface
    implicit none
    ! out sort_IntegerContainer retval
    type(sort_IntegerContainer_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_IntegerContainer_wrap private_data
    type(sort_IntegerContainer_wrap), intent(in) :: private_data
    external sort_IntegerContainer_wrapObj_m
    call sort_IntegerContainer_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_IntegerContainer_impl
