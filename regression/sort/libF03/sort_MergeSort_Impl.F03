! 
! File:          sort_MergeSort_Impl.F03
! Symbol:        sort.MergeSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
! Description:   Server-side implementation for sort.MergeSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.MergeSort" (version 0.1)
! 
! Merge sort
! 


#include "sort_MergeSort_fAbbrev.h"
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

! DO-NOT-DELETE splicer.end(module.include)

module sort_MergeSort_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_MergeSort
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 

  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_MergeSort_t) :: sort_MergeSort_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.private_data)
    ! insert code here (private data members)
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.private_data)
  end type sort_MergeSort_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_MergeSort_impl_t), target :: obj
    type(sort_MergeSort_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_MergeSort_wrap
    call sort_MergeSort_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  ! This file contains an interative (non-recursive) version of mergesort.
  
  subroutine mergeLists(elems, comp, cmp, swp, start, mid, last)
    use sidl
    use sort_Container
    use sort_Comparator
    use sort_Counter
    use sidl_BaseInterface
    type(sort_Container_t) :: elems
    type(sort_Comparator_t) :: comp
    type(sort_Counter_t) :: cmp, swp
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) start, mid, last, j
    integer(kind=sidl_int) compres, counter
    integer(kind=sidl_int) m, s
    m = mid
    s = start
    do while ((s .lt. m) .and. (m .lt. last))
       counter = inc(cmp, throwaway_exception)
       compres = compare(elems, s, m, comp, throwaway_exception)
       if (compres .gt. 0_sidl_int) then
          do j = m, s + 1_sidl_int, -1_sidl_int
             counter = inc(swp, throwaway_exception)
             call swap(elems, j, j - 1_sidl_int, throwaway_exception)
          enddo
          m = m + 1_sidl_int
       endif
       s = s + 1_sidl_int
    enddo
  end subroutine mergeLists
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor.use)
    implicit none
    !  in sort.MergeSort self
    type(sort_MergeSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor)
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._dtor.use)
    implicit none
    !  in sort.MergeSort self
    type(sort_MergeSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor)
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.MergeSort._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.MergeSort._load)
  end subroutine load_impl


  ! 
  ! Method:  sort[]
  ! Sort elements using Merge Sort.
  ! 

  subroutine sort_impl(self, elems, comp, exception)
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.sort.use)
    use sort_Counter
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.sort.use)
    implicit none
    !  in sort.MergeSort self
    type(sort_MergeSort_impl_t) :: self
    !  in sort.Container elems
    type(sort_Container_t), intent(in) :: elems
    !  in sort.Comparator comp
    type(sort_Comparator_t), intent(in) :: comp
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.sort)
    type(sort_Counter_t) :: cmp, swp
    integer(kind=sidl_int) stride, i, mid, last, len
    mid = 1_sidl_int
    stride = 2_sidl_int
    len = getLength(elems, exception)
    cmp = getCompareCounter(self, exception)
    swp = getSwapCounter(self, exception)
    do while (mid .lt. len)
       do i = 0_sidl_int, len - mid, stride
          last = i + stride
          if (last .gt. len) then
             last = len
          endif
          call mergeLists(elems, comp, cmp, swp, i, i + mid, last)
       enddo
       mid = stride
       stride = stride + stride
    enddo
    call deleteRef(cmp, exception)
    call deleteRef(swp, exception)
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.sort)
  end subroutine sort_impl


  ! 
  ! Method:  getName[]
  ! Return merge sort.
  ! 

  function getName_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.getName.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.getName.use)
    implicit none
    !  in sort.MergeSort self
    type(sort_MergeSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    character (len=sidl_f03_str_minsize) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.MergeSort.getName)
    retval = 'Merge sort (non-recursive)'
    ! DO-NOT-DELETE splicer.end(sort.MergeSort.getName)
  end function getName_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_MergeSort_Impl
