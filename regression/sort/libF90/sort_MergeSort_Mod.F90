! 
! File:          sort_MergeSort_Mod.F90
! Symbol:        sort.MergeSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side private data module for sort.MergeSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_MergeSort_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_MergeSort_impl

  ! DO-NOT-DELETE splicer.begin(sort.MergeSort.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.MergeSort.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_MergeSort_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.private_data)
  end type sort_MergeSort_priv

  type sort_MergeSort_wrap
    sequence
    type(sort_MergeSort_priv), pointer :: d_private_data
  end type sort_MergeSort_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_MergeSort
    use sidl_BaseInterface
    implicit none
    ! out sort_MergeSort retval
    type(sort_MergeSort_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_MergeSort_wrap private_data
    type(sort_MergeSort_wrap), intent(in) :: private_data
    external sort_MergeSort_wrapObj_m
    call sort_MergeSort_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_MergeSort_impl
