! 
! File:          sort_SortingAlgorithm_Impl.F90
! Symbol:        sort.SortingAlgorithm-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side implementation for sort.SortingAlgorithm
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.SortingAlgorithm" (version 0.1)
! 
! An abstract sorting algorithm.
! 


#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sort_Comparator_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "sort_Counter_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_Container_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sort_SortingAlgorithm_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
#include "sort_SimpleCounter_fAbbrev.h"
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine sort_SortingAlgorithm__ctor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor.use)
  use sort_Counter
  use sort_SimpleCounter
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor)
  type(sort_Counter_t) :: count
  type(sort_SimpleCounter_t) :: scount
  type(sort_SortingAlgorithm_wrap) :: dp
  allocate(dp%d_private_data)
  call new(scount, exception)
  call cast(scount, dp%d_private_data%d_compare, exception)
  call deleteRef(scount, exception)
  call new(scount, exception)
  call cast(scount, dp%d_private_data%d_swap, exception)
  call deleteRef(scount, exception)
  call sort_SortingAlgorithm__set_data_m(self, dp)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor)
end subroutine sort_SortingAlgorithm__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_SortingAlgorithm__ctor2_mi(self, private_data,       &
  exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor2.use)
  ! Insert-Code-Here {sort.SortingAlgorithm._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor2.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sort_SortingAlgorithm_wrap) :: private_data
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor2)
! Insert-Code-Here {sort.SortingAlgorithm._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor2)
end subroutine sort_SortingAlgorithm__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_SortingAlgorithm__dtor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor.use)
  use sort_Counter
  use sidl_BaseInterface
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor)
  type(sort_SortingAlgorithm_wrap) :: dp
  type(sidl_BaseInterface_t) :: throwaway_exception
  call sort_SortingAlgorithm__get_data_m(self, dp)
  call deleteRef(dp%d_private_data%d_swap, throwaway_exception)
  call deleteRef(dp%d_private_data%d_compare, throwaway_exception)
  deallocate(dp%d_private_data)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor)
end subroutine sort_SortingAlgorithm__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_SortingAlgorithm__load_mi(exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load)
end subroutine sort_SortingAlgorithm__load_mi


! 
! Method:  getCompareCounter[]
! Return the comparison counter.
! 

recursive subroutine getCompareCounter7t4c3x443qk_mi(self, retval, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Counter
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sort_Counter_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter)
  type(sort_SortingAlgorithm_wrap) :: dp
  call sort_SortingAlgorithm__get_data_m(self, dp)
  retval = dp%d_private_data%d_compare
  call addRef(retval, exception)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter)
end subroutine getCompareCounter7t4c3x443qk_mi


! 
! Method:  getSwapCounter[]
! Return the swap counter.
! 

recursive subroutine Sor_getSwapCounters2a2klo7r2_mi(self, retval, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Counter
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sort_Counter_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter)
  type(sort_SortingAlgorithm_wrap) :: dp
  call sort_SortingAlgorithm__get_data_m(self, dp)
  retval = dp%d_private_data%d_swap
  call addRef(retval, exception)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter)
end subroutine Sor_getSwapCounters2a2klo7r2_mi


! 
! Method:  reset[]
! Reset the comparison and swap counter.
! 

recursive subroutine sort_SortingAlgorithm_reset_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_impl
  ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset.use)
  use sort_Counter
  ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset.use)
  implicit none
  type(sort_SortingAlgorithm_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset)
  type(sort_SortingAlgorithm_wrap) :: dp
  call sort_SortingAlgorithm__get_data_m(self, dp)
  call reset(dp%d_private_data%d_compare, exception)
  call reset(dp%d_private_data%d_swap, exception)
! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset)
end subroutine sort_SortingAlgorithm_reset_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
