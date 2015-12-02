! 
! File:          sort_SortTest_Mod.F90
! Symbol:        sort.SortTest-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for sort.SortTest
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_SortTest_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_SortTest_impl

  ! DO-NOT-DELETE splicer.begin(sort.SortTest.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SortTest.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_SortTest_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.SortTest.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(sort.SortTest.private_data)
  end type sort_SortTest_priv

  type sort_SortTest_wrap
    sequence
    type(sort_SortTest_priv), pointer :: d_private_data
  end type sort_SortTest_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_SortTest
    use sidl_BaseInterface
    implicit none
    ! out sort_SortTest retval
    type(sort_SortTest_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_SortTest_wrap private_data
    type(sort_SortTest_wrap), intent(in) :: private_data
    external sort_SortTest_wrapObj_m
    call sort_SortTest_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_SortTest_impl
