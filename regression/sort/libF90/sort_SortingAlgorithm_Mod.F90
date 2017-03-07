! 
! File:          sort_SortingAlgorithm_Mod.F90
! Symbol:        sort.SortingAlgorithm-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side private data module for sort.SortingAlgorithm
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 

#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_SortingAlgorithm_fAbbrev.h"

! DO-NOT-DELETE splicer.begin(_hincludes)
! Insert-Code-Here {_hincludes} (include files)
! DO-NOT-DELETE splicer.end(_hincludes)

module sort_SortingAlgorithm_impl

  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.use)
  use sort_Counter_type
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.use)

  type sort_SortingAlgorithm_priv
    sequence
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.private_data)
   type(sort_Counter_t) :: d_compare
   type(sort_Counter_t) :: d_swap
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.private_data)
  end type sort_SortingAlgorithm_priv

  type sort_SortingAlgorithm_wrap
    sequence
    type(sort_SortingAlgorithm_priv), pointer :: d_private_data
  end type sort_SortingAlgorithm_wrap

end module sort_SortingAlgorithm_impl
