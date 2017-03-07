! 
! File:          sort_HeapSort_Impl.F03
! Symbol:        sort.HeapSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
! Description:   Server-side implementation for sort.HeapSort
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.HeapSort" (version 0.1)
! 
! Heap sort
! 


#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sort_Comparator_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "sort_Counter_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_Container_fAbbrev.h"
#include "sort_HeapSort_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sort_SortingAlgorithm_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(module.include)
! 
! Add additional include statements here
! 

! DO-NOT-DELETE splicer.end(module.include)

module sort_HeapSort_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_HeapSort
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 

  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_HeapSort_t) :: sort_HeapSort_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.private_data)
    ! insert code here (private data members)
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.private_data)
  end type sort_HeapSort_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_HeapSort_impl_t), target :: obj
    type(sort_HeapSort_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_HeapSort_wrap
    call sort_HeapSort_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  subroutine remakeHeap(elem, comp, cmp, swp, last, first)
    use sidl
    use sort_Counter
    use sort_Comparator
    use sort_Container
    use sidl_BaseInterface
    implicit none
    type(sort_Counter_t) cmp, swp
    type(sort_Comparator_t) comp
    type(sort_Container_t) elem
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) last, first, half, child, result, counter, f
    f = first
    half = (last/2_sidl_int) - 1_sidl_int
    do while (f .le. half) 
       child = f + f + 1_sidl_int
       if ((child + 1_sidl_int) .lt. last) then
          counter = inc(cmp, throwaway_exception)
          result = compare(elem, child, child+1_sidl_int, comp, &
               throwaway_exception)
          if (result .lt. 0_sidl_int) then
             child = child + 1_sidl_int
          endif
       endif
       counter = inc(cmp, throwaway_exception)
       result = compare(elem, f, child, comp, throwaway_exception)
       if (result .ge. 0_sidl_int) goto 100
       counter = inc(swp, throwaway_exception)
       call swap(elem, f, child, throwaway_exception)
       f = child
    enddo
100 return
  end subroutine remakeHeap
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor.use)
    implicit none
    !  in sort.HeapSort self
    type(sort_HeapSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._dtor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._dtor.use)
    implicit none
    !  in sort.HeapSort self
    type(sort_HeapSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._dtor)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.HeapSort._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort._load)
  end subroutine load_impl


  ! 
  ! Method:  sort[]
  ! Sort elements using Heap Sort.
  ! 

  subroutine sort_impl(self, elems, comp, exception)
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.sort.use)
    use sort_Counter
    use sidl_BaseInterface
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.sort.use)
    implicit none
    !  in sort.HeapSort self
    type(sort_HeapSort_impl_t) :: self
    !  in sort.Container elems
    type(sort_Container_t), intent(in) :: elems
    !  in sort.Comparator comp
    type(sort_Comparator_t), intent(in) :: comp
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.sort)
    integer(kind=sidl_int) i, num, counter
    type(sort_Counter_t) cmp, swp
    type(sidl_BaseInterface_t) :: throwaway_exception
    num = getLength(elems, throwaway_exception)
    cmp = getCompareCounter(self, throwaway_exception)
    swp = getSwapCounter(self, throwaway_exception)
    !     make the heap
    do i = ((num / 2_sidl_int) - 1_sidl_int), 0_sidl_int, -1_sidl_int
       call remakeHeap(elems, comp, cmp, swp, num, i)
    enddo
    !     put top of heap at back and remake the heap
    i = num - 1_sidl_int
    do while (i .gt. 0_sidl_int)
       counter = inc(swp, throwaway_exception)
       call swap(elems, 0_sidl_int, i, throwaway_exception)
       call remakeHeap(elems, comp, cmp, swp, i, 0_sidl_int)
       i = i - 1_sidl_int
    enddo
    call deleteRef(cmp, throwaway_exception)
    call deleteRef(swp, throwaway_exception)
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.sort)
  end subroutine sort_impl


  ! 
  ! Method:  getName[]
  ! Return heap sort.
  ! 

  function getName_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.getName.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.getName.use)
    implicit none
    !  in sort.HeapSort self
    type(sort_HeapSort_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    character (len=sidl_f03_str_minsize) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.HeapSort.getName)
    retval = 'Heap sort'
    ! DO-NOT-DELETE splicer.end(sort.HeapSort.getName)
  end function getName_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_HeapSort_Impl
