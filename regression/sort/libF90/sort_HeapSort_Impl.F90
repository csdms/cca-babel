! 
! File:          sort_HeapSort_Impl.F90
! Symbol:        sort.HeapSort-v0.1
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
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


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sort_HeapSort_fAbbrev.h"
#include "sort_SortingAlgorithm_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sort_Comparator_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sort_Counter_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sort_Container_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
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
        call inc(cmp, counter, throwaway_exception)
        call compare(elem, child, child+1_sidl_int, comp, &
           result, throwaway_exception)
        if (result .lt. 0_sidl_int) then
           child = child + 1_sidl_int
        endif
     endif
     call inc(cmp, counter, throwaway_exception)
     call compare(elem, f, child, comp, result, throwaway_exception)
     if (result .ge. 0_sidl_int) goto 100
     call inc(swp, counter, throwaway_exception)
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

recursive subroutine sort_HeapSort__ctor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor.use)
  implicit none
  type(sort_HeapSort_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor)
end subroutine sort_HeapSort__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_HeapSort__ctor2_mi(self, private_data, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor2.use)
  ! Insert-Code-Here {sort.HeapSort._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor2.use)
  implicit none
  type(sort_HeapSort_t) :: self
  ! in
  type(sort_HeapSort_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort._ctor2)
! Insert-Code-Here {sort.HeapSort._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.HeapSort._ctor2)
end subroutine sort_HeapSort__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_HeapSort__dtor_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.HeapSort._dtor.use)
  implicit none
  type(sort_HeapSort_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort._dtor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.HeapSort._dtor)
end subroutine sort_HeapSort__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_HeapSort__load_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.HeapSort._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.HeapSort._load)
end subroutine sort_HeapSort__load_mi


! 
! Method:  sort[]
! Sort elements using Heap Sort.
! 

recursive subroutine sort_HeapSort_sort_mi(self, elems, comp, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort.sort.use)
  use sort_Counter
  use sidl_BaseInterface
  ! DO-NOT-DELETE splicer.end(sort.HeapSort.sort.use)
  implicit none
  type(sort_HeapSort_t) :: self
  ! in
  type(sort_Container_t) :: elems
  ! in
  type(sort_Comparator_t) :: comp
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort.sort)
  integer(kind=sidl_int) i, num, counter
  type(sort_Counter_t) cmp, swp
  type(sidl_BaseInterface_t) :: throwaway_exception
  call getLength(elems, num, throwaway_exception)
  call getCompareCounter(self, cmp, throwaway_exception)
  call getSwapCounter(self, swp, throwaway_exception)
!     make the heap
  do i = ((num / 2_sidl_int) - 1_sidl_int), 0_sidl_int, -1_sidl_int
     call remakeHeap(elems, comp, cmp, swp, num, i)
  enddo
!     put top of heap at back and remake the heap
  i = num - 1_sidl_int
  do while (i .gt. 0_sidl_int)
     call inc(swp, counter, throwaway_exception)
     call swap(elems, 0_sidl_int, i, throwaway_exception)
     call remakeHeap(elems, comp, cmp, swp, i, 0_sidl_int)
     i = i - 1_sidl_int
  enddo
  call deleteRef(cmp, throwaway_exception)
  call deleteRef(swp, throwaway_exception)
! DO-NOT-DELETE splicer.end(sort.HeapSort.sort)
end subroutine sort_HeapSort_sort_mi


! 
! Method:  getName[]
! Return heap sort.
! 

recursive subroutine sort_HeapSort_getName_mi(self, retval, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_HeapSort
  use sort_HeapSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.HeapSort.getName.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.HeapSort.getName.use)
  implicit none
  type(sort_HeapSort_t) :: self
  ! in
  character (len=*) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(sort.HeapSort.getName)
  retval = 'Heap sort'
! DO-NOT-DELETE splicer.end(sort.HeapSort.getName)
end subroutine sort_HeapSort_getName_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
