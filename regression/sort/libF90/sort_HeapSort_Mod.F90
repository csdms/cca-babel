! 
! File:          sort_HeapSort_Mod.F90
! Symbol:        sort.HeapSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side private data module for sort.HeapSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_HeapSort_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_HeapSort_impl

  ! DO-NOT-DELETE splicer.begin(sort.HeapSort.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.HeapSort.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_HeapSort_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.private_data)
  integer :: place_holder
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.private_data)
  end type sort_HeapSort_priv

  type sort_HeapSort_wrap
    sequence
    type(sort_HeapSort_priv), pointer :: d_private_data
  end type sort_HeapSort_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_HeapSort
    use sidl_BaseInterface
    implicit none
    ! out sort_HeapSort retval
    type(sort_HeapSort_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_HeapSort_wrap private_data
    type(sort_HeapSort_wrap), intent(in) :: private_data
    external sort_HeapSort_wrapObj_m
    call sort_HeapSort_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_HeapSort_impl
