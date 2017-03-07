! 
! File:          sort_QuickSort_Impl.F03
! Symbol:        sort.QuickSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
! Description:   Server-side implementation for sort.QuickSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.QuickSort" (version 0.1)
! 
! Quick sort
! 


#include "sidl_RuntimeException_fAbbrev.h"
#include "sort_QuickSort_fAbbrev.h"
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
#include "sort_QuickSort_fAbbrev.h"
#include "sort_MergeSort_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
#include "sidl_int_fAbbrev.h"

! DO-NOT-DELETE splicer.end(module.include)

module sort_QuickSort_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_QuickSort
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 
use sidl_int_array
  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_QuickSort_t) :: sort_QuickSort_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.private_data)
    ! insert code here (private data members)
    type(sidl_int_1d) :: lower
    type(sidl_int_1d) :: upper
    integer(kind=sidl_int)  :: depth
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.private_data)
  end type sort_QuickSort_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_QuickSort_impl_t), target :: obj
    type(sort_QuickSort_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_QuickSort_wrap
    call sort_QuickSort_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  logical function notEmpty(self)
    use sidl
    use sort_QuickSort
    implicit none
    type(sort_QuickSort_impl_t) :: self
    notEmpty = (self%depth .gt. 0_sidl_int)
  end function notEmpty

  subroutine push(self, low, up)
    use sidl
    use sort_QuickSort
    use synch_RegOut
    use sidl_BaseInterface
    implicit none
    type(sort_QuickSort_impl_t) :: self
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) low, up
    type(synch_RegOut_t) :: tracker
    if (self%depth .lt. 32_sidl_int) then
       call set(self%lower, self%depth, low)
       call set(self%upper, self%depth, up)
       self%depth = self%depth + 1_sidl_int
    else
       tracker = getInstance(throwaway_exception)
       call writeComment(tracker, &
            'stack overflow in QuickSort', throwaway_exception)
       call forceFailure(tracker, throwaway_exception)
       stop
    endif
  end subroutine push

  subroutine pop(self, low, up)
    use sidl
    use sort_QuickSort
    use synch_RegOut
    use sidl_BaseInterface
    implicit none
    type(sort_QuickSort_impl_t) :: self
    integer(kind=sidl_int) low, up, stackdepth
    type(synch_RegOut_t) :: tracker
    type(sidl_BaseInterface_t) :: throwaway_exception
    if (self%depth .gt. 0_sidl_int) then
       self%depth = self%depth - 1_sidl_int
       stackdepth = self%depth
       call get(self%lower, stackdepth, low)
       call get(self%upper, stackdepth, up)
    else
       tracker = getInstance(throwaway_exception)
       call writeComment(tracker, &
            'stack underflow in QuickSort', throwaway_exception)
       call forceFailure(tracker, throwaway_exception)
       stop
    endif
  end subroutine pop

  !
  ! Choose the middle of the first, middle and last element of the
  ! list.  For small lists, return the middle without checking.
  !
  integer(kind=selected_int_kind(9)) function choosePivot(elems, comp, cmp, start, end)
    use sidl
    use sort_Container
    use sort_Comparator
    use sort_Counter
    use sidl_BaseInterface
    implicit none
    type(sort_Container_t) :: elems
    type(sort_Comparator_t) :: comp
    type(sort_Counter_t) cmp
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) start, end, pivot, mid, cmpres, counter
    pivot = (start + end) / 2_sidl_int
    if ((end - start) .gt. 4_sidl_int) then
       mid = pivot
       counter = inc(cmp, throwaway_exception)
       cmpres = compare(elems, start, mid, comp, throwaway_exception)
       if (cmpres .le. 0_sidl_int) then
          counter = inc(cmp, throwaway_exception)
          cmpres = compare(elems, mid, end -1_sidl_int, comp,  &
               throwaway_exception)
          if (cmpres .gt. 0_sidl_int) then
             counter = inc(cmp, throwaway_exception)
             cmpres = compare(elems, start, end - 1_sidl_int, comp, &
                  throwaway_exception)
             if (cmpres .lt. 0_sidl_int) then
                pivot = end - 1_sidl_int
             else
                pivot = start
             endif
          endif
       else
          counter = inc(cmp, throwaway_exception)
          cmpres = compare(elems, mid, end - 1_sidl_int, comp, &
               throwaway_exception)
          if (cmpres .lt. 0_sidl_int) then
             counter = inc(cmp, throwaway_exception)
             cmpres = compare(elems, start, end - 1_sidl_int, comp, &
                  throwaway_exception)
             if (cmpres .gt. 0_sidl_int) then
                pivot = end - 1_sidl_int
             else
                pivot = start
             endif
          endif
       endif
    endif
    choosePivot = pivot
  end function choosePivot

  subroutine quickSort(self, elems, comp, cmp, swp)
    use sidl
    use sort_QuickSort
    use sort_Container
    use sort_Comparator
    use sort_Counter
    use sidl_BaseInterface
    implicit none
    type(sort_QuickSort_impl_t) :: self
    type(sort_Container_t) :: elems
    type(sort_Comparator_t) :: comp
    type(sort_Counter_t) :: cmp, swp
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) start, end, pivot
    integer(kind=sidl_int) i, j, cmpres, counter
    end = getLength(elems, throwaway_exception)
    start = 0_sidl_int
    call push(self, start, end)
    do while (notEmpty(self))
       call pop(self, start, end)
       if ((end - start) .gt. 1_sidl_int) then
          pivot = choosePivot(elems, comp, cmp, start, end)
          i = start
          j = end
          if (pivot .ne. start) then
             counter = inc(swp, throwaway_exception)
             call swap(elems, start, pivot, throwaway_exception)
          endif
100       j = j - 1_sidl_int
          counter = inc(cmp, throwaway_exception)
          cmpres = compare(elems, start, j, comp, throwaway_exception)
          if (cmpres .lt. 0_sidl_int) goto 100
          i = i + 1_sidl_int
          do while (i .lt. j)
             counter = inc(cmp, throwaway_exception)
             cmpres = compare(elems, start, i, comp, throwaway_exception)
             if (cmpres .lt. 0_sidl_int) goto 200
             i = i + 1_sidl_int
          enddo
200       if (i .ge. j) goto 300
          counter = inc(swp, throwaway_exception)
          call swap(elems, i, j, throwaway_exception)
          goto 100
300       if (j .ne. start) then
             counter = inc(swp, throwaway_exception)
             call swap(elems, start, j, throwaway_exception)
          endif
          call push(self, start, j)
          call push(self, j + 1_sidl_int, end)
       endif
    enddo
  end subroutine quickSort

  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._ctor.use)
    implicit none
    !  in sort.QuickSort self
    type(sort_QuickSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor)
    call create1d(32_sidl_int, self%lower)
    call create1d(32_sidl_int, self%upper)
    self%depth = 0_sidl_int
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._dtor.use)
    implicit none
    !  in sort.QuickSort self
    type(sort_QuickSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor)
    call deleteRef(self%lower)
    call deleteRef(self%upper)
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.QuickSort._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.QuickSort._load)
  end subroutine load_impl


  ! 
  ! Method:  sort[]
  ! Sort elements using Quick Sort.
  ! 

  subroutine sort_impl(self, elems, comp, exception)
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.sort.use)
    use sort_Counter
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.sort.use)
    implicit none
    !  in sort.QuickSort self
    type(sort_QuickSort_impl_t) :: self
    !  in sort.Container elems
    type(sort_Container_t), intent(in) :: elems
    !  in sort.Comparator comp
    type(sort_Comparator_t), intent(in) :: comp
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.sort)
    type (sort_Counter_t) :: swp, cmp
    cmp = getCompareCounter(self, exception)
    swp = getSwapCounter(self, exception)
    call quickSort(self, elems, comp, cmp, swp)
    call deleteRef(cmp, exception)
    call deleteRef(swp, exception)
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.sort)
  end subroutine sort_impl


  ! 
  ! Method:  getName[]
  ! Return quick sort.
  ! 

  function getName_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.getName.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.getName.use)
    implicit none
    !  in sort.QuickSort self
    type(sort_QuickSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    character (len=sidl_f03_str_minsize) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.QuickSort.getName)
    retval = 'Quick sort'
    ! DO-NOT-DELETE splicer.end(sort.QuickSort.getName)
  end function getName_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_QuickSort_Impl
