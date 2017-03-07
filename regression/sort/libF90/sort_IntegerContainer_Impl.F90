! 
! File:          sort_IntegerContainer_Impl.F90
! Symbol:        sort.IntegerContainer-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7435  trunk)
! Description:   Server-side implementation for sort.IntegerContainer
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.IntegerContainer" (version 0.1)
! 
! Integer container.
! 


#include "sidl_RuntimeException_fAbbrev.h"
#include "sort_Comparator_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "sort_IntegerContainer_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sort_Container_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
#include "sort_Integer_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine sort_IntegerContainer__ctor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor.use)
  use sort_Integer_array
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor)
  type(sort_IntegerContainer_wrap) :: pd
  allocate(pd%d_private_data)
  call set_null(pd%d_private_data%d_array)
  call sort_IntegerContainer__set_data_m(self, pd)
! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor)
end subroutine sort_IntegerContainer__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine sort_IntegerContainer__ctor2_mi(self, private_data,       &
  exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor2.use)
  ! Insert-Code-Here {sort.IntegerContainer._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor2.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  type(sort_IntegerContainer_wrap) :: private_data
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor2)
! Insert-Code-Here {sort.IntegerContainer._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor2)
end subroutine sort_IntegerContainer__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine sort_IntegerContainer__dtor_mi(self, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor.use)
  use sort_Integer_array
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor)
  type(sort_IntegerContainer_wrap) :: pd
  call sort_IntegerContainer__get_data_m(self, pd)
  if (not_null(pd%d_private_data%d_array)) then
     call deleteRef(pd%d_private_data%d_array)
     call set_null(pd%d_private_data%d_array)
  endif
  deallocate(pd%d_private_data)
! DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor)
end subroutine sort_IntegerContainer__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine sort_IntegerContainer__load_mi(exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.IntegerContainer._load)
end subroutine sort_IntegerContainer__load_mi


! 
! Method:  setLength[]
! This sets the container length and pseudo-randomly orders the
! Integer elements contained.
! 

recursive subroutine IntegerC_setLengthj8msmv4gje_mi(self, len, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength.use)
  use sort_Integer
  use sort_Integer_array
  use sidl_BaseInterface
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  integer (kind=sidl_int) :: len
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength)
  type(sort_Integer_t) :: intobj
  type(sort_IntegerContainer_wrap) :: dp
  type(sidl_BaseInterface_t) :: throwaway_exception
  integer(kind=sidl_int) :: i, tmp
  if (len .ge. 0_sidl_int) then
     call sort_IntegerContainer__get_data_m(self, dp)
     call deleteRef(dp%d_private_data%d_array)
     call create1d(len, dp%d_private_data%d_array)
     do i = 0_sidl_int, len - 1_sidl_int
        call new(intobj, throwaway_exception)
        call setValue(intobj, i+1_sidl_int, throwaway_exception)
        if (mod(i,2_sidl_int) .eq. 0_sidl_int) then
           tmp = i/2_sidl_int
        else
           tmp = len - 1_sidl_int - i/2_sidl_int
        endif
        call set(dp%d_private_data%d_array, tmp, intobj)
        call deleteRef(intobj, throwaway_exception)
     enddo
   !     don't shuffle the list because no standard random number generator
     call sort_IntegerContainer__set_data_m(self, dp)
  endif
! DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength)
end subroutine IntegerC_setLengthj8msmv4gje_mi


! 
! Method:  getLength[]
! Return the number of elements in the container.
! 

recursive subroutine IntegerC_getLength11uun9rvs6_mi(self, retval, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength.use)
  use sort_Integer_array
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  integer (kind=sidl_int) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength)
  type(sort_IntegerContainer_wrap) :: dp
  integer(kind=sidl_int) low, up
  integer(kind=sidl_int) zero
  data zero / 0 /
  call sort_IntegerContainer__get_data_m(self, dp)
  retval = 0_sidl_int
  if (not_null(dp%d_private_data%d_array)) then
     low = lower(dp%d_private_data%d_array, zero)
     up = upper(dp%d_private_data%d_array, zero)
     retval = 1_sidl_int + up - low
  endif
! DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength)
end subroutine IntegerC_getLength11uun9rvs6_mi


! 
! Method:  compare[]
! Return -1 if element i is less than element j, 0 if element i
! is equal to element j, or otherwise 1.
! 

recursive subroutine IntegerCon_comparehztz37m8dj_mi(self, i, j, comp, retval, &
  exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare.use)
  use sort_Integer
  use sidl_BaseInterface
  use sort_Integer_array
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  integer (kind=sidl_int) :: i
  ! in
  integer (kind=sidl_int) :: j
  ! in
  type(sort_Comparator_t) :: comp
  ! in
  integer (kind=sidl_int) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare)
  type(sort_IntegerContainer_wrap) :: dp
  type(sort_Integer_t) :: i1, i2
  type(sidl_BaseInterface_t) :: throwaway_exception
  type(sidl_BaseInterface_t) :: bi1, bi2
  call sort_IntegerContainer__get_data_m(self, dp)
  if (not_null(dp%d_private_data%d_array)) then
     call get(dp%d_private_data%d_array, i, i1)
     call get(dp%d_private_data%d_array, j, i2)
     call cast(i1, bi1, throwaway_exception)
     call cast(i2, bi2, throwaway_exception)
     call compare(comp, bi1, bi2, retval, throwaway_exception)
     call deleteRef(i1, throwaway_exception)
     call deleteRef(bi1, throwaway_exception)
     call deleteRef(i2, throwaway_exception)
     call deleteRef(bi2, throwaway_exception)
  endif
! DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare)
end subroutine IntegerCon_comparehztz37m8dj_mi


! 
! Method:  swap[]
! Swap elements i and j.
! 

recursive subroutine sort_IntegerContainer_swap_mi(self, i, j, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap.use)
  use sort_Integer
  use sort_Integer_array
  use synch_RegOut
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  integer (kind=sidl_int) :: i
  ! in
  integer (kind=sidl_int) :: j
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap)
  type(sort_Integer_t) :: i1, i2
  type(sort_IntegerContainer_wrap) :: dp
  type(synch_RegOut_t) :: tracker
  integer(kind=sidl_int) len
  call sort_IntegerContainer__get_data_m(self, dp)
  if (not_null(dp%d_private_data%d_array)) then
     call getLength(self, len, exception)
     if ((i .ge. 0_sidl_int) .and. (j .ge. 0_sidl_int) .and. &
          (i .lt. len) .and. (j .lt. len)) then
        call get(dp%d_private_data%d_array, i, i1)
        call get(dp%d_private_data%d_array, j, i2)
        call set(dp%d_private_data%d_array, i, i2)
        call set(dp%d_private_data%d_array, j, i1)
        call deleteRef(i1, exception)
        call deleteRef(i2, exception)
     else
        call getInstance(tracker, exception)
        call writeComment(tracker, &
           'sort::IntegerContainer::swap index out of bounds', &
	   exception)
        call forceFailure(tracker, exception)
        call deleteRef(tracker, exception)
     endif
  endif
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap)
end subroutine sort_IntegerContainer_swap_mi


! 
! Method:  output[]
! Print elements s through e-1
! 

recursive subroutine sort_IntegerContainer_output_mi(self, s, e, exception)
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_IntegerContainer
  use sort_IntegerContainer_impl
  ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output.use)
  use synch_RegOut
  ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.output.use)
  implicit none
  type(sort_IntegerContainer_t) :: self
  ! in
  integer (kind=sidl_int) :: s
  ! in
  integer (kind=sidl_int) :: e
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out

! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output)
  type(synch_RegOut_t) :: tracker
  call getInstance(tracker, exception)
  call writeComment(tracker, &
       'output list not implemented', &
       exception)
  call deleteRef(tracker, exception)
! DO-NOT-DELETE splicer.end(sort.IntegerContainer.output)
end subroutine sort_IntegerContainer_output_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
