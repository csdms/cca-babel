! 
! File:          sort_CompInt_Mod.F90
! Symbol:        sort.CompInt-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side private data module for sort.CompInt
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_CompInt_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_CompInt_impl

  ! DO-NOT-DELETE splicer.begin(sort.CompInt.use)
! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.CompInt.use)

  private :: wrapObj_s

  interface wrapObj
  module procedure wrapObj_s
  end interface

  type sort_CompInt_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.CompInt.private_data)
   logical :: d_increasing
    ! DO-NOT-DELETE splicer.end(sort.CompInt.private_data)
  end type sort_CompInt_priv

  type sort_CompInt_wrap
    sequence
    type(sort_CompInt_priv), pointer :: d_private_data
  end type sort_CompInt_wrap

  contains

  recursive subroutine wrapObj_s(private_data, retval, exception)
    use sort_CompInt
    use sidl_BaseInterface
    implicit none
    ! out sort_CompInt retval
    type(sort_CompInt_t) , intent(out) :: retval
    ! out sidl_BaseInterface exception
    type(sidl_BaseInterface_t) , intent(out) :: exception
    ! in sort_CompInt_wrap private_data
    type(sort_CompInt_wrap), intent(in) :: private_data
    external sort_CompInt_wrapObj_m
    call sort_CompInt_wrapObj_m(private_data, retval, exception)
   end subroutine wrapObj_s
end module sort_CompInt_impl
