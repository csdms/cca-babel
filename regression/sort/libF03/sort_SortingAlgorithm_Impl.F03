! 
! File:          sort_SortingAlgorithm_Impl.F03
! Symbol:        sort.SortingAlgorithm-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
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
! DO-NOT-DELETE splicer.begin(module.include)
! 
! Add additional include statements here
! 
#include "sort_SimpleCounter_fAbbrev.h"

! DO-NOT-DELETE splicer.end(module.include)

module sort_SortingAlgorithm_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_Counter
  use sort_SortingAlgorithm
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 

  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_SortingAlgorithm_t) :: sort_SortingAlgorithm_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.private_data)
    ! insert code here (private data members)
    type(sort_Counter_t) :: d_compare
    type(sort_Counter_t) :: d_swap
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.private_data)
  end type sort_SortingAlgorithm_impl_t

contains

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor.use)
    use sort_Counter
    use sort_SimpleCounter
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor.use)
    implicit none
    !  in sort.SortingAlgorithm self
    type(sort_SortingAlgorithm_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor)
    type(sort_Counter_t) :: count
    type(sort_SimpleCounter_t) :: scount
    call new(scount, exception)
    call cast(scount, self%d_compare, exception)
    call deleteRef(scount, exception)
    call new(scount, exception)
    call cast(scount, self%d_swap, exception)
    call deleteRef(scount, exception)
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor.use)
    use sort_Counter
    use sidl_BaseInterface
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor.use)
    implicit none
    !  in sort.SortingAlgorithm self
    type(sort_SortingAlgorithm_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor)
    type(sidl_BaseInterface_t) :: throwaway_exception
    call deleteRef(self%d_swap, throwaway_exception)
    call deleteRef(self%d_compare, throwaway_exception)
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load)
  end subroutine load_impl


  ! 
  ! Method:  getCompareCounter[]
  ! Return the comparison counter.
  ! 

  function getCompareCounter_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter.use)
    implicit none
    !  in sort.SortingAlgorithm self
    type(sort_SortingAlgorithm_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    type(sort_Counter_t) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter)
    retval = self%d_compare
    call addRef(retval, exception)
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter)
  end function getCompareCounter_impl


  ! 
  ! Method:  getSwapCounter[]
  ! Return the swap counter.
  ! 

  function getSwapCounter_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter.use)
    implicit none
    !  in sort.SortingAlgorithm self
    type(sort_SortingAlgorithm_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    type(sort_Counter_t) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter)
    retval = self%d_swap
    call addRef(retval, exception)
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter)
  end function getSwapCounter_impl


  ! 
  ! Method:  reset[]
  ! Reset the comparison and swap counter.
  ! 

  subroutine reset_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset.use)
    use sort_Counter
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset.use)
    implicit none
    !  in sort.SortingAlgorithm self
    type(sort_SortingAlgorithm_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset)
    call reset(self%d_compare, exception)
    call reset(self%d_swap, exception)
    ! DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset)
  end subroutine reset_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_SortingAlgorithm_Impl
