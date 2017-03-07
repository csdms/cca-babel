! 
! File:          sort_IntegerContainer_Impl.F03
! Symbol:        sort.IntegerContainer-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
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
! DO-NOT-DELETE splicer.begin(module.include)
! 
! Add additional include statements here
! 
#include "sort_Integer_fAbbrev.h"
! DO-NOT-DELETE splicer.end(module.include)

module sort_IntegerContainer_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Comparator
  use sort_IntegerContainer
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 
  use sort_Integer_array
  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_IntegerContainer_t) :: sort_IntegerContainer_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.private_data)
    ! insert code here (private data members)
     type(sort_Integer_1d) :: d_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.private_data)
  end type sort_IntegerContainer_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_IntegerContainer_impl_t), target :: obj
    type(sort_IntegerContainer_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_IntegerContainer_wrap
    call sort_IntegerContainer_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
#include "sort_Integer_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor.use)
    use sort_Integer_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor)
    call set_null(self%d_array)
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor.use)
    use sort_Integer_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor)
    if (not_null(self%d_array)) then
       call deleteRef(self%d_array)
       call set_null(self%d_array)
    endif
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer._load)
  end subroutine load_impl


  ! 
  ! Method:  setLength[]
  ! This sets the container length and pseudo-randomly orders the
  ! Integer elements contained.
  ! 

  subroutine setLength_impl(self, len, exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength.use)
    use sort_Integer
    use sort_Integer_array
    use sidl_BaseInterface
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  in int len
    integer (kind=sidl_int), intent(in) :: len
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength)
    type(sort_Integer_t) :: intobj
    type(sidl_BaseInterface_t) :: throwaway_exception
    integer(kind=sidl_int) :: i, tmp
    if (len .ge. 0_sidl_int) then
       call deleteRef(self%d_array)
       call create1d(len, self%d_array)
       do i = 0_sidl_int, len - 1_sidl_int
          call new(intobj, throwaway_exception)
          call setValue(intobj, i+1_sidl_int, throwaway_exception)
          if (mod(i,2_sidl_int) .eq. 0_sidl_int) then
             tmp = i/2_sidl_int
          else
             tmp = len - 1_sidl_int - i/2_sidl_int
          endif
          call set(self%d_array, tmp, intobj)
          call deleteRef(intobj, throwaway_exception)
       enddo
    endif
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength)
  end subroutine setLength_impl


  ! 
  ! Method:  getLength[]
  ! Return the number of elements in the container.
  ! 

  function getLength_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength.use)
    use sort_Integer_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    integer (kind=sidl_int) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength)
    integer(kind=sidl_int) low, up
    integer(kind=sidl_int) zero
    data zero / 0 /
    retval = 0_sidl_int
    if (not_null(self%d_array)) then
       low = lower(self%d_array, zero)
       up = upper(self%d_array, zero)
       retval = 1_sidl_int + up - low
    endif
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength)
  end function getLength_impl


  ! 
  ! Method:  compare[]
  ! Return -1 if element i is less than element j, 0 if element i
  ! is equal to element j, or otherwise 1.
  ! 

  function compare_impl(self, i, j, comp, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare.use)
    use sort_Integer
    use sidl_BaseInterface
    use sort_Integer_array
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  in int i
    integer (kind=sidl_int), intent(in) :: i
    !  in int j
    integer (kind=sidl_int), intent(in) :: j
    !  in sort.Comparator comp
    type(sort_Comparator_t), intent(in) :: comp
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    integer (kind=sidl_int) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare)
    type(sort_Integer_t) :: i1, i2
    type(sidl_BaseInterface_t) :: throwaway_exception
    type(sidl_BaseInterface_t) :: bi1, bi2
    if (not_null(self%d_array)) then
       call get(self%d_array, i, i1)
       call get(self%d_array, j, i2)
       call cast(i1, bi1, throwaway_exception)
       call cast(i2, bi2, throwaway_exception)
       retval = compare(comp, bi1, bi2, throwaway_exception)
       call deleteRef(i1, throwaway_exception)
       call deleteRef(bi1, throwaway_exception)
       call deleteRef(i2, throwaway_exception)
       call deleteRef(bi2, throwaway_exception)
    endif
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare)
  end function compare_impl


  ! 
  ! Method:  swap[]
  ! Swap elements i and j.
  ! 

  subroutine swap_impl(self, i, j, exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap.use)
    use sort_Integer
    use sort_Integer_array
    use synch_RegOut
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  in int i
    integer (kind=sidl_int), intent(in) :: i
    !  in int j
    integer (kind=sidl_int), intent(in) :: j
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap)
    type(sort_Integer_t) :: i1, i2
    type(synch_RegOut_t) :: tracker
    integer(kind=sidl_int) len
    if (not_null(self%d_array)) then
       len = getLength(self, exception)
       if ((i .ge. 0_sidl_int) .and. (j .ge. 0_sidl_int) .and. &
            (i .lt. len) .and. (j .lt. len)) then
          call get(self%d_array, i, i1)
          call get(self%d_array, j, i2)
          call set(self%d_array, i, i2)
          call set(self%d_array, j, i1)
          call deleteRef(i1, exception)
          call deleteRef(i2, exception)
       else
          tracker = getInstance(exception)
          call writeComment(tracker, &
               'sort::IntegerContainer::swap index out of bounds', &
               exception)
          call forceFailure(tracker, exception)
          call deleteRef(tracker, exception)
       endif
    endif
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap)
  end subroutine swap_impl


  ! 
  ! Method:  output[]
  ! Print elements s through e-1
  ! 

  subroutine output_impl(self, s, e, exception)
    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output.use)
    use synch_RegOut
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.output.use)
    implicit none
    !  in sort.IntegerContainer self
    type(sort_IntegerContainer_impl_t) :: self
    !  in int s
    integer (kind=sidl_int), intent(in) :: s
    !  in int e
    integer (kind=sidl_int), intent(in) :: e
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output)
    type(synch_RegOut_t) :: tracker
    tracker = getInstance(exception)
    call writeComment(tracker, &
         'output list not implemented', &
         exception)
    call deleteRef(tracker, exception)
    ! DO-NOT-DELETE splicer.end(sort.IntegerContainer.output)
  end subroutine output_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_IntegerContainer_Impl
