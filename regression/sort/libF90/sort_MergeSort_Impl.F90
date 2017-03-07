! 
! File:          sort_MergeSort_Impl.F90
! Symbol:        sort.MergeSort-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
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
     call inc(cmp, counter, throwaway_exception)
     call compare(elems, s, m, comp, compres, throwaway_exception)
     if (compres .gt. 0_sidl_int) then
        do j = m, s + 1_sidl_int, -1_sidl_int
           call inc(swp, counter, throwaway_exception)
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

recursive subroutine sort_MergeSort__ctor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor.use)
  implicit none
  type(sort_MergeSort_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor)
! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor)
end subroutine sort_MergeSort__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_MergeSort__ctor2_mi(self, private_data, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor2.use)
  ! Insert-Code-Here {sort.MergeSort._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor2.use)
  implicit none
  type(sort_MergeSort_t) :: self
  ! in
  type(sort_MergeSort_wrap) :: private_data
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort._ctor2)
! Insert-Code-Here {sort.MergeSort._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.MergeSort._ctor2)
end subroutine sort_MergeSort__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_MergeSort__dtor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.MergeSort._dtor.use)
  implicit none
  type(sort_MergeSort_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor)
! DO-NOT-DELETE splicer.end(sort.MergeSort._dtor)
end subroutine sort_MergeSort__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_MergeSort__load_mi(exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.MergeSort._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.MergeSort._load)
end subroutine sort_MergeSort__load_mi


! 
! Method:  sort[]
! Sort elements using Merge Sort.
! 

recursive subroutine sort_MergeSort_sort_mi(self, elems, comp, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_Container
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort.sort.use)
  use sort_Counter
  ! DO-NOT-DELETE splicer.end(sort.MergeSort.sort.use)
  implicit none
  type(sort_MergeSort_t) :: self
  ! in
  type(sort_Container_t) :: elems
  ! in
  type(sort_Comparator_t) :: comp
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort.sort)
  type(sort_Counter_t) :: cmp, swp
  integer(kind=sidl_int) stride, i, mid, last, len
  mid = 1_sidl_int
  stride = 2_sidl_int
  call getLength(elems, len, exception)
  call getCompareCounter(self, cmp, exception)
  call getSwapCounter(self, swp, exception)
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
end subroutine sort_MergeSort_sort_mi


! 
! Method:  getName[]
! Return merge sort.
! 

recursive subroutine sort_MergeSort_getName_mi(self, retval, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_MergeSort
  use sort_MergeSort_impl
  ! DO-NOT-DELETE splicer.begin(sort.MergeSort.getName.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.MergeSort.getName.use)
  implicit none
  type(sort_MergeSort_t) :: self
  ! in
  character (len=*) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.MergeSort.getName)
  retval = 'Merge sort (non-recursive)'
! DO-NOT-DELETE splicer.end(sort.MergeSort.getName)
end subroutine sort_MergeSort_getName_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
