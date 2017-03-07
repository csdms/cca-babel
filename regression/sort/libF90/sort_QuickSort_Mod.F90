! 
! File:          sort_QuickSort_Mod.F90
! Symbol:        sort.QuickSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side private data module for sort.QuickSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_QuickSort_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_QuickSort_impl

  ! DO-NOT-DELETE splicer.begin(sort.QuickSort.use)
use sidl
use sidl_int_array
  ! DO-NOT-DELETE splicer.end(sort.QuickSort.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_QuickSort_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.private_data)
   type(sidl_int_1d) :: lower
   type(sidl_int_1d) :: upper
   integer(kind=sidl_int)  :: depth
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.private_data)
  end type sort_QuickSort_priv

  type sort_QuickSort_wrap
    sequence
    type(sort_QuickSort_priv), pointer :: d_private_data
  end type sort_QuickSort_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_QuickSort
    use sidl_BaseInterface
    implicit none
    ! out sort_QuickSort retval
    type(sort_QuickSort_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_QuickSort_wrap private_data
    type(sort_QuickSort_wrap), intent(in) :: private_data
    external sort_QuickSort_wrapObj_m
    call sort_QuickSort_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_QuickSort_impl
