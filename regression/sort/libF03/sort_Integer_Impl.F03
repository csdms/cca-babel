! 
! File:          sort_Integer_Impl.F03
! Symbol:        sort.Integer-v0.1
! Symbol Type:   class
! Babel Version: 2.0.0 (Revision: 7372  trunk)
! Description:   Server-side implementation for sort.Integer
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "sort.Integer" (version 0.1)
! 
! An object to hold a simple integer.
! 


#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "sort_Integer_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(module.include)
! 
! Add additional include statements here
! 

! DO-NOT-DELETE splicer.end(module.include)

module sort_Integer_Impl
  use sidl
  use sidl_BaseInterface
  use sidl_RuntimeException
  use sort_Integer
  ! DO-NOT-DELETE splicer.begin(module.use)
  ! 
  ! Add use statements here
  ! 

  ! DO-NOT-DELETE splicer.end(module.use)


  type, extends(sort_Integer_t) :: sort_Integer_impl_t
    ! DO-NOT-DELETE splicer.begin(sort.Integer.private_data)
    ! insert code here (private data members)
    integer(kind=sidl_int) :: d_value
    ! DO-NOT-DELETE splicer.end(sort.Integer.private_data)
  end type sort_Integer_impl_t

contains

  subroutine wrap(obj, self, exception)
    type(sort_Integer_impl_t), target :: obj
    type(sort_Integer_t) :: self
    type(sidl_BaseInterface_t) :: exception
    external sort_Integer_wrap
    call sort_Integer_wrap(obj, self, exception)
  end subroutine wrap

  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



  ! 
  ! Method:  _ctor[]
  ! Class constructor called when the class is created.
  ! 

  subroutine ctor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.Integer._ctor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.Integer._ctor.use)
    implicit none
    !  in sort.Integer self
    type(sort_Integer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.Integer._ctor)
    self%d_value = 0
    ! DO-NOT-DELETE splicer.end(sort.Integer._ctor)
  end subroutine ctor_impl


  ! 
  ! Method:  _dtor[]
  ! Class destructor called when the class is deleted.
  ! 

  subroutine dtor_impl(self, exception)
    ! DO-NOT-DELETE splicer.begin(sort.Integer._dtor.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.Integer._dtor.use)
    implicit none
    !  in sort.Integer self
    type(sort_Integer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.Integer._dtor)
    ! DO-NOT-DELETE splicer.end(sort.Integer._dtor)
  end subroutine dtor_impl


  ! 
  ! Method:  _load[]
  ! Static class initializer called exactly once before any user-defined method is dispatched
  ! 

  subroutine load_impl(exception)
    ! DO-NOT-DELETE splicer.begin(sort.Integer._load.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.Integer._load.use)
    implicit none
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.Integer._load)
    ! Insert the implementation here...
    ! DO-NOT-DELETE splicer.end(sort.Integer._load)
  end subroutine load_impl


  ! 
  ! Method:  getValue[]
  ! 

  function getValue_impl(self, exception) result(retval)
    ! DO-NOT-DELETE splicer.begin(sort.Integer.getValue.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.Integer.getValue.use)
    implicit none
    !  in sort.Integer self
    type(sort_Integer_impl_t) :: self
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception
    !  function result
    integer (kind=sidl_int) :: retval

    ! DO-NOT-DELETE splicer.begin(sort.Integer.getValue)
    retval = self%d_value
    ! DO-NOT-DELETE splicer.end(sort.Integer.getValue)
  end function getValue_impl


  ! 
  ! Method:  setValue[]
  ! 

  subroutine setValue_impl(self, value, exception)
    ! DO-NOT-DELETE splicer.begin(sort.Integer.setValue.use)
    ! Insert use statements here...
    ! DO-NOT-DELETE splicer.end(sort.Integer.setValue.use)
    implicit none
    !  in sort.Integer self
    type(sort_Integer_impl_t) :: self
    !  in int value
    integer (kind=sidl_int), intent(in) :: value
    !  out sidl.BaseInterface exception
    type(sidl_BaseInterface_t), intent(out) :: exception

    ! DO-NOT-DELETE splicer.begin(sort.Integer.setValue)
    self%d_value = value
    ! DO-NOT-DELETE splicer.end(sort.Integer.setValue)
  end subroutine setValue_impl


  ! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
  ! Insert extra code here...
  ! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)

end module sort_Integer_Impl
