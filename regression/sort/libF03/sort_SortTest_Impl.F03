! 
! File:          sort_SortTest_Impl.F03
! Symbol:        sort.SortTest-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
! Description:   Server-side implementation for sort.SortTest
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.SortTest" (version 0.1)
! 
! Run a bunch of sorts through a stress test.
! 


#include "sort_SortTest_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sort_SortingAlgorithm_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(module.include)
! 
! Add additional include statements here
! 
#include "synch_RegOut_fAbbrev.h"
#include "sort_Comparator_fAbbrev.h"
#include "sort_CompInt_fAbbrev.h"
#include "sort_Container_fAbbrev.h"
#include "sort_Counter_fAbbrev.h"
#include "sort_IntegerContainer_fAbbrev.h"

! DO-NOT-DELETE splicer.end(module.include)

module sort_SortTest_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_SortTest
  use sort_SortingAlgorithm
  use sort_SortingAlgorithm_array
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 

  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_SortTest_t) :: sort_SortTest_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.SortTest.private_data)
    ! insert code here (private data members)
    ! DO-NOT-DELETE splicer.end(sort.SortTest.private_data)
  end type sort_SortTest_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_SortTest_impl_t), target :: obj
    type(sort_SortTest_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_SortTest_wrap
    call sort_SortTest_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  recursive integer(kind=selected_int_kind(9)) function intToString(ivalue, str)
    use sidl
    integer(kind=sidl_int), intent(in) :: ivalue
    integer(kind=sidl_int) :: copy
    integer(kind=sidl_int), parameter :: ten = 10_sidl_int
    character(len=*), intent(inout) :: str
    character(len=80) :: buffer
    logical :: isneg
    integer :: i, j, k
    i = 1_sidl_int
    copy = ivalue
    j = 1_sidl_int
    str = ''
    if (copy .lt. 0_sidl_int) then
       str(j:j) = '-'
       j = j + 1_sidl_int
       copy = -copy
    end if
    do 
       buffer(i:i) = char(ichar('0') + mod(copy,ten))
       i = i + 1_sidl_int
       copy = copy / 10_sidl_int
       if (copy .eq. 0_sidl_int) exit
    end do
    ! the string is done but reversed
    do k = 1_sidl_int, i-1_sidl_int
       str(j:j) = buffer(i - k:i - k)
       j = j + 1_sidl_int
    enddo
    intToString = j - 1_sidl_int
  end function intToString


  subroutine sortAndReport(alg, cont, comp)
    use sidl
    use sort_SortingAlgorithm
    use sort_Counter
    use sort_Container
    use sort_Comparator
    use synch_RegOut
    use sidl_BaseInterface
    implicit none
    type(sort_SortingAlgorithm_t) :: alg
    type(sort_Container_t) :: cont
    type(sort_Comparator_t) :: comp
    type(sort_Counter_t) :: swpCnt, cmpCnt
    type(synch_RegOut_t) :: tracker
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) numswap, numcmp
    character(len=80) :: cmpbuf, swapbuf
    integer(kind=sidl_int) :: cmplen, swaplen
    call reset(alg, throwaway_exception)
    call sort(alg, cont, comp, throwaway_exception)
    swpCnt = getSwapCounter(alg, throwaway_exception)
    numswap = getCount(swpCnt, throwaway_exception)
    call deleteRef(swpCnt, throwaway_exception)
    cmpCnt = getCompareCounter(alg, throwaway_exception)
    numcmp = getCount(cmpCnt, throwaway_exception)
    call deleteRef(cmpCnt, throwaway_exception)
    cmplen = intToString(numcmp, cmpbuf)
    swaplen = intToString(numswap, swapbuf)
    tracker = getInstance(throwaway_exception)
    call writeComment(tracker, 'compares (' // cmpbuf(1:cmplen) // &
         ') swaps (' // &
         swapbuf(1:swaplen) // ')', throwaway_exception)
    call deleteRef(tracker, throwaway_exception)
  end subroutine sortAndReport

  logical function notSorted(cont, comp)
    use sidl
    use sort_Container
    use sort_Comparator
    use sidl_BaseInterface
    implicit none
    type(sort_Container_t) :: cont
    type(sort_Comparator_t) :: comp
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) csize, i, result
    csize = getLength(cont, throwaway_exception)
    do i = 1_sidl_int, csize - 1_sidl_int
       result = compare(cont, i-1_sidl_int, i, comp, throwaway_exception)
       if (result .gt. 0_sidl_int) then
          notSorted = .true.
          goto 100
       endif
    enddo
    notSorted = .false.
100 return
  end function notSorted

  subroutine testAlgorithm(alg, retval)
    use sidl
    use sort_SortingAlgorithm
    use sort_IntegerContainer
    use sort_Container
    use sort_Comparator
    use sort_CompInt
    use synch_RegOut
    use sidl_BaseInterface
    implicit none
    type(sort_SortingAlgorithm_t) :: alg
    type(sort_Container_t) :: cont
    type(sort_IntegerContainer_t) :: intcont
    type(sort_Comparator_t) :: comp
    type(sort_CompInt_t) ::intcomp
    type(synch_RegOut_t) :: tracker
    type(sidl_BaseInterface_t) :: throwaway_exception
    character(len=30) ::  name
    character(len=80) :: sizebuf
    integer(kind=sidl_int) :: sizelen
    logical retval
    integer(kind=sidl_int) j, testsizes(10)
    data testsizes / 0_sidl_int, 1_sidl_int, 2_sidl_int, 3_sidl_int, &
         4_sidl_int, 7_sidl_int, 10_sidl_int, 51_sidl_int, 64_sidl_int, &
         -1_sidl_int /

    tracker = getInstance(throwaway_exception)
    name = getName(alg, throwaway_exception)
    call writeComment(tracker, &
         '****ALGORITHM IS ' // name // '****' &
         , throwaway_exception)
    call new(intcont, throwaway_exception)
    call cast(intcont, cont, throwaway_exception)
    call new(intcomp, throwaway_exception)
    call cast(intcomp, comp, throwaway_exception)
    j = 1_sidl_int
    do while (testsizes(j) .ge. 0_sidl_int)
       call setSortIncreasing(intcomp, .true., throwaway_exception)
       sizelen = intToString(testsizes(j), sizebuf)
       call writeComment(tracker, &
            'DATA SIZE ' // sizebuf(1:sizelen), throwaway_exception)
       call setLength(intcont, testsizes(j), throwaway_exception)
       call sortAndReport(alg, cont, comp)
       if (notSorted(cont, comp)) then
          call writeComment(tracker, 'sort failed!!', throwaway_exception)
          retval = .false.
       endif
       call writeComment(tracker, 'pre-sorted list', throwaway_exception)
       call sortAndReport(alg, cont, comp)
       if (notSorted(cont, comp)) then
          call writeComment(tracker, 'sort failed!!', throwaway_exception)
          retval = .false.
       endif
       call writeComment(tracker, 'reverse sorted list', throwaway_exception)
       call setSortIncreasing(intcomp, .false., throwaway_exception)
       call sortAndReport(alg, cont, comp)
       if (notSorted(cont, comp)) then
          call writeComment(tracker, 'sort failed!!', throwaway_exception)
          retval = .false.
       endif
       j = j + 1_sidl_int
    enddo

    call deleteRef(intcont, throwaway_exception)
    call deleteRef(cont, throwaway_exception)
    call deleteRef(alg, throwaway_exception)
    call deleteRef(intcomp, throwaway_exception)
    call deleteRef(comp, throwaway_exception)
    call deleteRef(tracker, throwaway_exception)
  end subroutine testAlgorithm
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortTest._ctor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._ctor.use)
    implicit none
    !  in sort.SortTest self
    type(sort_SortTest_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortTest._ctor)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortTest._dtor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._dtor.use)
    implicit none
    !  in sort.SortTest self
    type(sort_SortTest_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortTest._dtor)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.SortTest._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.SortTest._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest._load)
  end subroutine load_impl


  ! 
  ! Method:  stressTest[]
  ! Perform the array stress test.
  ! 
  ! Return true if all the algorithms work okay.
  ! 

  function stressTest_impl(algs, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.SortTest.stressTest.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.SortTest.stressTest.use)
    implicit none
    !  in array<sort.SortingAlgorithm> algs
    type(sort_SortingAlgorithm_1d), intent(in) :: algs
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    logical :: retval

    ! DO-NOT-DELETE splicer.begin(sort.SortTest.stressTest)
    integer(kind=sidl_int) low, up, i
    type(sort_SortingAlgorithm_t) ::alg
    if (not_null(algs)) then
       low = lower(algs, 0_sidl_int)
       up = upper(algs, 0_sidl_int)
       retval = .true.
       do i = low, up
          call get(algs, i, alg)
          if (not_null(alg)) then
             call testAlgorithm(alg, retval)
          else
             retval = .false.
          endif
       enddo
    endif
    ! DO-NOT-DELETE splicer.end(sort.SortTest.stressTest)
  end function stressTest_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_SortTest_Impl
