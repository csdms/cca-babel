! 
! File:          s_StructTest_Impl.F90
! Symbol:        s.StructTest-v1.0
! Symbol Type:   class
! Babel Version: 1.2.1 (Revision: 6475M trunk)
! Description:   Server-side implementation for s.StructTest
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "s.StructTest" (version 1.0)
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "s_StructTest_fAbbrev.h"
#include "s_Simple_fAbbrev.h"
#include "s_Hard_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
#include "s_CombRarray_fAbbrev.h"
#include "s_Combined_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "s_HardRarray_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "s_Empty_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
! insert code here (extra code)

subroutine initSimple(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Simple_t),intent(inout) :: s

  s%d_bool = 1
  s%d_char = '3'
  s%d_dcomplex = cmplx(3.14_sidl_double,3.14_sidl_double)
  s%d_double = 3.14_sidl_double
  s%d_fcomplex =  cmplx(3.1_sidl_float,3.1_sidl_float)
  s%d_float = 3.1_sidl_float
  s%d_int = 3
  s%d_long = 3
  s%d_opaque = c_null_ptr
  s%d_enum = blue
  
end subroutine initSimple

logical function checkSimple(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Simple_t),intent(in) :: s
  real, parameter :: eps = 1E-6

  if ((s%d_bool .ge. 1) .and. &
      (s%d_char .eq. '3' ) .and. &
       (abs(real(s%d_dcomplex) - 3.14_sidl_double) .lt. eps) .and. &
       (abs(aimag(s%d_dcomplex) - 3.14_sidl_double) .lt. eps) .and. &
       (abs(s%d_double - 3.14_sidl_double) .lt. eps ) .and. &
       (abs(s%d_float - 3.1_sidl_float) .lt. eps ) .and. &
       (abs(real(s%d_fcomplex) - 3.1_sidl_float) .lt. eps) .and. &
       (abs(aimag(s%d_fcomplex) - 3.1_sidl_float) .lt. eps) .and. &
       (s%d_int .eq. 3 ) .and. &
       (s%d_long .eq. 3) .and. &
       (.not. c_associated(s%d_opaque)) .and. &
       (s%d_enum .eq. blue )) then
    checkSimple=.true.
  else
    checkSimple=.false.
  endif

  return

end

subroutine invertSimple(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Simple_t),intent(inout) :: s

  ! ignore inversion of d_char since 3 is neither upper or lower case.  Also 
  ! ignore inversion of NULL

  if (s%d_bool .eq. 0) then
    s%d_bool=1
  else
    s%d_bool=0
  endif
  s%d_dcomplex = cmplx(3.14_sidl_double,-3.14_sidl_double)
  s%d_double = -s%d_double    
  s%d_fcomplex = cmplx(3.1_sidl_float,-3.1_sidl_float)
  s%d_float = -s%d_float
  s%d_int = -s%d_int 
  s%d_long = -s%d_long 
  s%d_enum = red

end subroutine invertSimple

subroutine initHard(h,ex)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use sidl_array_array
  use sidl_double_array

  type(s_Hard_t),intent(inout) :: h
  type(sidl_BaseInterface_t),intent(out) :: ex
  type(sidl_double_1d) :: fArray
  real(kind=sidl_double) :: temp
  integer :: i
  integer (kind=sidl_int) :: lw(1),up(1)

  !
  ! Array check
  !

  lw(1)=0
  up(1)=2
  call createRow(lw,up,fArray) 
  temp=1.0
  do i =0,2
    call set(fArray, i, temp)
    temp = temp + 1.0
  enddo

  h%d_array=fArray%d_array
  call addRef(fArray)

  !pass out exception even though one not returned from these Array calls
  if ((dimen(fArray) .eq. 1) .and. &
      (length(fArray,0) .eq. 3 )) then
      call set_null(ex) 
  endif 


end subroutine initHard

logical function checkHard(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Hard_t),intent(in) :: s
  type(sidl_double_1d) :: dArray
  real(kind=sidl_double) :: temp0,temp1,temp2

  checkHard=.false.

  call cast(s%d_array,dArray)

  call get(dArray,0,temp0)
  call get(dArray,1,temp1)
  call get(dArray,2,temp2)

  if ((dimen(dArray) .eq. 1) .and. &
      ((length(dArray,0)) .eq. 3 ) .and. &
      (temp0 .eq. 1 )  .and. &
      (temp1 .eq. 2 )  .and. &
      (temp2 .eq. 3 )) then 
    checkHard=.true.
  endif 

  return

end

subroutine invertHard(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Hard_t),intent(inout) :: s
  type(sidl_double_1d) :: dArray
  real(kind=sidl_double) :: temp,temp2

  call cast(s%d_array,dArray)

  if ((dimen(dArray) .eq. 1) .and. &
      (length(dArray,0) .eq. 3 )) then
         call get(dArray,0,temp)
         call get(dArray,2,temp2)
         call set(dArray,0,temp2)
         call set(dArray,2,temp)
  endif 

end subroutine invertHard

subroutine initCombined(s,ex)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use s_Hard
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Combined_t),intent(inout) :: s
  type(sidl_BaseInterface_t),intent(out) :: ex
  real(kind=sidl_double) :: temp
  type(s_Hard_t),target :: tHard

  call initSimple(s%d_simple)
  call initHard(s%d_hard,ex)
  
end subroutine initCombined

logical function checkCombined(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Combined_t),intent(in) :: s
  type(sidl_double_1d) :: dArray

  logical checkSimple
  logical checkHard

  checkCombined=.false.

  if (checkSimple(s%d_simple) .and. checkHard(s%d_hard)) then
    checkCombined=.true.
  endif

  return

end

subroutine invertCombined(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_Combined_t),intent(inout) :: s

  call invertSimple(s%d_simple)
  call invertHard(s%d_hard)

end subroutine invertCombined

logical function checkHardRarray(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

!  logical c_associated
  type(s_HardRarray_t),intent(in) :: s

  real(c_double),dimension(:),pointer :: s_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=s%d_rarrayRaw, & 
                   FPTR=s_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))

  checkHardRarray=.false.


  if (c_associated(s%d_rarrayRaw) .and. &
    (s%d_int .eq. 3) .and. &
    (s_d_rarrayRaw_fptr(1) .eq. 1.0) .and. &
    (s_d_rarrayRaw_fptr(2) .eq. 2.0) .and. &
    (s_d_rarrayRaw_fptr(3) .eq. 3.0) .and. &
    (s%d_rarrayFix(1) .eq. 5.0) .and. &
    (s%d_rarrayFix(2) .eq. 10.0) .and. &
    (s%d_rarrayFix(3) .eq. 15.0)) then
    checkHardRarray=.true.
  endif

  return

end

subroutine invertHardRarray(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  use s_Color

  type(s_HardRarray_t),intent(inout) :: s
  real(kind=sidl_double) :: temp
!  logical c_associated

  real(c_double),dimension(:),pointer :: s_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=s%d_rarrayRaw, & 
                   FPTR=s_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))

  if (c_associated(s%d_rarrayRaw)) then
    temp = s_d_rarrayRaw_fptr(1)   
    s_d_rarrayRaw_fptr(1) = s_d_rarrayRaw_fptr(3)     
    s_d_rarrayRaw_fptr(3) = temp
  
    temp = s%d_rarrayFix(1)   
    s%d_rarrayFix(1) = s%d_rarrayFix(3)     
    s%d_rarrayFix(3) = temp
  endif


end subroutine invertHardRarray

logical function checkCombRarray(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl

  type(s_CombRarray_t),intent(in) :: s

  logical checkSimple
  logical checkHardRarray

  checkCombRarray=.false.

  if (checkSimple(s%d_simple) .and. checkHardRarray(s%d_hardRarray)) then
    checkCombRarray=.true.
  endif

  return

end

subroutine invertCombRarray(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl

  type(s_CombRarray_t),intent(in) :: s

  call invertSimple(s%d_simple)
  call invertHardRarray(s%d_hardRarray)

  end subroutine invertCombRarray
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine s_StructTest__ctor_mi(self, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest._ctor.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest._ctor.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest._ctor)
! insert code here (_ctor method)
! 
! This method has not been implemented
! 

! DO-NOT-DELETE splicer.end(s.StructTest._ctor)
end subroutine s_StructTest__ctor_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine s_StructTest__ctor2_mi(self, private_data, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest._ctor2.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest._ctor2.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_StructTest_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest._ctor2)
! insert code here (_ctor2 method)
! 
! This method has not been implemented
! 

! DO-NOT-DELETE splicer.end(s.StructTest._ctor2)
end subroutine s_StructTest__ctor2_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine s_StructTest__dtor_mi(self, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest._dtor.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest._dtor.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest._dtor)
! insert code here (_dtor method)
! 
! This method has not been implemented
! 

! DO-NOT-DELETE splicer.end(s.StructTest._dtor)
end subroutine s_StructTest__dtor_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine s_StructTest__load_mi(exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest._load.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest._load)
! insert code here (_load method)
! 
! This method has not been implemented
! 

! DO-NOT-DELETE splicer.end(s.StructTest._load)
end subroutine s_StructTest__load_mi


! 
! Method:  returnEmpty[]
! 

recursive subroutine s_StructTest_returnEmpty_mi(self, retval, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Empty
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.returnEmpty.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.returnEmpty.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Empty_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.returnEmpty)
! insert code here (returnEmpty method)
! 
! Do Nothing. all we have to do is return retval
! 

! DO-NOT-DELETE splicer.end(s.StructTest.returnEmpty)
end subroutine s_StructTest_returnEmpty_mi


! 
! Method:  passinEmpty[]
! 

function s_StructTest_passinEmpty_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Empty
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinEmpty.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinEmpty.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Empty_t) :: s
  ! in
  logical :: s_StructTest_passinEmpty_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinEmpty)
! insert code here (passinEmpty method)
! 
    s_StructTest_passinEmpty_mi=.true.

! DO-NOT-DELETE splicer.end(s.StructTest.passinEmpty)
end function s_StructTest_passinEmpty_mi


! 
! Method:  passoutEmpty[]
! 

function s_StructTest_passoutEmpty_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Empty
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passoutEmpty.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passoutEmpty.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Empty_t) :: s
  ! out
  logical :: s_StructTest_passoutEmpty_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passoutEmpty)
! insert code here (passoutEmpty method)
! 
    s_StructTest_passoutEmpty_mi=.true.

! DO-NOT-DELETE splicer.end(s.StructTest.passoutEmpty)
end function s_StructTest_passoutEmpty_mi


! 
! Method:  passinoutEmpty[]
! 

function s_StructTest_passinoutEmpty_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Empty
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutEmpty.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutEmpty.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Empty_t) :: s
  ! inout
  logical :: s_StructTest_passinoutEmpty_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutEmpty)
! insert code here (passinoutEmpty method)
! 
    s_StructTest_passinoutEmpty_mi=.true.

! DO-NOT-DELETE splicer.end(s.StructTest.passinoutEmpty)
end function s_StructTest_passinoutEmpty_mi


! 
! Method:  passeverywhereEmpty[]
! 

recursive subroutine passeverywhereEmpt05k3gk_f64_mi(self, s1, s2, s3, retval, &
  exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Empty
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereEmpty.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereEmpty.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Empty_t) :: s1
  ! in
  type(s_Empty_t) :: s2
  ! out
  type(s_Empty_t) :: s3
  ! inout
  type(s_Empty_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereEmpty)
! insert code here (passeverywhereEmpty method)
! 
! This method has not been implemented
! 

! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereEmpty)
end subroutine passeverywhereEmpt05k3gk_f64_mi


! 
! Method:  returnSimple[]
! 

recursive subroutine s_StructTest_returnSimple_mi(self, retval, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.returnSimple.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.returnSimple.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Simple_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.returnSimple)
! insert code here (returnSimple method)
! 
  
  call initSimple(retval)

! DO-NOT-DELETE splicer.end(s.StructTest.returnSimple)
end subroutine s_StructTest_returnSimple_mi


! 
! Method:  passinSimple[]
! 

function s_StructTest_passinSimple_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinSimple.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinSimple.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Simple_t) :: s
  ! in
  logical :: s_StructTest_passinSimple_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinSimple)
! insert code here (passinSimple method)
! 
  logical checkSimple

  s_StructTest_passinSimple_mi=checkSimple(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinSimple)
end function s_StructTest_passinSimple_mi


! 
! Method:  passoutSimple[]
! 

function s_StructTest_passoutSimple_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passoutSimple.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passoutSimple.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Simple_t) :: s
  ! out
  logical :: s_StructTest_passoutSimple_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passoutSimple)
! insert code here (passoutSimple method)
! 
  call initSimple(s)
  s_StructTest_passoutSimple_mi = .true.

! DO-NOT-DELETE splicer.end(s.StructTest.passoutSimple)
end function s_StructTest_passoutSimple_mi


! 
! Method:  passinoutSimple[]
! 

function s_StructTest_passinoutSimple_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutSimple.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutSimple.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Simple_t) :: s
  ! inout
  logical :: s_StructTest_passinoutSimple_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutSimple)
! insert code here (passinoutSimple method)
! 
  logical checkSimple
  s_StructTest_passinoutSimple_mi=checkSimple(s)
  call invertSimple(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinoutSimple)
end function s_StructTest_passinoutSimple_mi


! 
! Method:  passeverywhereSimple[]
! 

recursive subroutine passeverywhereSimp1t_32r81n0_mi(self, s1, s2, s3, retval, &
  exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereSimple.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereSimple.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Simple_t) :: s1
  ! in
  type(s_Simple_t) :: s2
  ! out
  type(s_Simple_t) :: s3
  ! inout
  type(s_Simple_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereSimple)
! insert code here (passeverywhereSimple method)
! 
  logical checkSimple

  call initSimple(s2)
  call initSimple(retval)
  if (checkSimple(s1) .and. checkSimple(s2)) then
    call invertSimple(s3)
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereSimple)
end subroutine passeverywhereSimp1t_32r81n0_mi


! 
! Method:  returnHard[]
! 

recursive subroutine s_StructTest_returnHard_mi(self, retval, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.returnHard.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.returnHard.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Hard_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.returnHard)
! insert code here (returnHard method)
! 

  call initHard(retval,exception)

! DO-NOT-DELETE splicer.end(s.StructTest.returnHard)
end subroutine s_StructTest_returnHard_mi


! 
! Method:  passinHard[]
! 

function s_StructTest_passinHard_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinHard.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinHard.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Hard_t) :: s
  ! in
  logical :: s_StructTest_passinHard_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinHard)
! insert code here (passinHard method)
! 
  logical checkHard
  s_StructTest_passinHard_mi = checkHard(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinHard)
end function s_StructTest_passinHard_mi


! 
! Method:  passoutHard[]
! 

function s_StructTest_passoutHard_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passoutHard.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passoutHard.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Hard_t) :: s
  ! out
  logical :: s_StructTest_passoutHard_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passoutHard)
! insert code here (passoutHard method)
! 
  s_StructTest_passoutHard_mi = .true.
  call initHard(s,exception)
  if (not_null(exception)) then
    s_StructTest_passoutHard_mi = .false.
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passoutHard)
end function s_StructTest_passoutHard_mi


! 
! Method:  passinoutHard[]
! 

function s_StructTest_passinoutHard_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHard.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutHard.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Hard_t) :: s
  ! inout
  logical :: s_StructTest_passinoutHard_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHard)
! insert code here (passinoutHard method)
  logical checkHard
  s_StructTest_passinoutHard_mi = checkHard(s)
  call invertHard(s)
! 

! DO-NOT-DELETE splicer.end(s.StructTest.passinoutHard)
end function s_StructTest_passinoutHard_mi


! 
! Method:  passeverywhereHard[]
! 

recursive subroutine passeverywhereHardatsuyth6kv_mi(self, s1, s2, s3, retval, &
  exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHard.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHard.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Hard_t) :: s1
  ! in
  type(s_Hard_t) :: s2
  ! out
  type(s_Hard_t) :: s3
  ! inout
  type(s_Hard_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHard)
! insert code here (passeverywhereHard method)
! 
  logical checkHard

  call initHard(retval,exception)
  call initHard(s2,exception)
  if (checkHard(s1).and.checkHard(s3)) then
    call invertHard(s3)
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHard)
end subroutine passeverywhereHardatsuyth6kv_mi


! 
! Method:  returnCombined[]
! 

recursive subroutine s_StructTest_returnCombined_mi(self, retval, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.returnCombined.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.returnCombined.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Combined_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.returnCombined)
! insert code here (returnCombined method)
! 
  call initCombined(retval,exception)

! DO-NOT-DELETE splicer.end(s.StructTest.returnCombined)
end subroutine s_StructTest_returnCombined_mi


! 
! Method:  passinCombined[]
! 

function s_StructTest_passinCombined_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinCombined.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinCombined.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Combined_t) :: s
  ! in
  logical :: s_StructTest_passinCombined_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinCombined)
! insert code here (passinCombined method)
! 
  logical checkCombined
  s_StructTest_passinCombined_mi=.false.
  s_StructTest_passinCombined_mi=checkCombined(s)
  
! DO-NOT-DELETE splicer.end(s.StructTest.passinCombined)
end function s_StructTest_passinCombined_mi


! 
! Method:  passoutCombined[]
! 

function s_StructTest_passoutCombined_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passoutCombined.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passoutCombined.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Combined_t) :: s
  ! out
  logical :: s_StructTest_passoutCombined_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passoutCombined)
! insert code here (passoutCombined method)
! 
  s_StructTest_passoutCombined_mi = .true.
  call initCombined(s,exception)
  if (not_null(exception)) then
    s_StructTest_passoutCombined_mi = .false.
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passoutCombined)
end function s_StructTest_passoutCombined_mi


! 
! Method:  passinoutCombined[]
! 

function passinoutCombined0ko6zp9lxck_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombined.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombined.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Combined_t) :: s
  ! inout
  logical :: passinoutCombined0ko6zp9lxck_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombined)
! insert code here (passinoutCombined method)
! 
  logical checkCombined
  passinoutCombined0ko6zp9lxck_mi = checkCombined(s)
  call invertCombined(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombined)
end function passinoutCombined0ko6zp9lxck_mi


! 
! Method:  passeverywhereCombined[]
! 

recursive subroutine passeverywhereComb7br08sdkjq_mi(self, s1, s2, s3, retval, &
  exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombined.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombined.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_Combined_t) :: s1
  ! in
  type(s_Combined_t) :: s2
  ! out
  type(s_Combined_t) :: s3
  ! inout
  type(s_Combined_t) :: retval
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombined)
! insert code here (passeverywhereCombined method)
! 
  logical checkCombined

  call initCombined(retval,exception)
  call initCombined(s2,exception)
  if (checkCombined(s1).and.checkCombined(s3)) then
    call invertCombined(s3)
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombined)
end subroutine passeverywhereComb7br08sdkjq_mi


! 
! Method:  passinHardRarray[]
! 

function S_passinHardRarrayqi1sp_qiuv_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinHardRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinHardRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_HardRarray_t) :: s
  ! in
  logical :: S_passinHardRarrayqi1sp_qiuv_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out


  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinHardRarray.local_declarations)
  logical checkHardRarray
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinHardRarray.local_declarations)

  real(c_double),dimension(:),pointer :: s_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=s%d_rarrayRaw, & 
                   FPTR=s_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))


! DO-NOT-DELETE splicer.begin(s.StructTest.passinHardRarray)
! 
  S_passinHardRarrayqi1sp_qiuv_mi = checkHardRarray(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinHardRarray)
end function S_passinHardRarrayqi1sp_qiuv_mi


! 
! Method:  passinoutHardRarray[]
! 

function passinoutHardRarracjz5b9isop_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHardRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutHardRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_HardRarray_t) :: s
  ! inout
  logical :: passinoutHardRarracjz5b9isop_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out


  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHardRarray.local_declarations)
  logical checkHardRarray
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutHardRarray.local_declarations)

  real(c_double),dimension(:),pointer :: s_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=s%d_rarrayRaw, & 
                   FPTR=s_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))


! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutHardRarray)
! insert code here (passinoutHardRarray method)
! 
  passinoutHardRarracjz5b9isop_mi = checkHardRarray(s)
  call invertHardRarray(s)

! DO-NOT-DELETE splicer.end(s.StructTest.passinoutHardRarray)
end function passinoutHardRarracjz5b9isop_mi


! 
! Method:  passeverywhereHardRarray[]
! 

function passeverywhereHardz8i7xggsvp_mi(self, s1, s2, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHardRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHardRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_HardRarray_t) :: s1
  ! in
  type(s_HardRarray_t) :: s2
  ! inout
  logical :: passeverywhereHardz8i7xggsvp_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out


  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHardRarray.local_declarations)
  logical checkHardRarray
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHardRarray.local_declarations)

  real(c_double),dimension(:),pointer :: s1_d_rarrayRaw_fptr

  real(c_double),dimension(:),pointer :: s2_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=s1%d_rarrayRaw, & 
                   FPTR=s1_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))

  call C_F_POINTER(CPTR=s2%d_rarrayRaw, & 
                   FPTR=s2_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))


! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereHardRarray)
! 

  if (checkHardRarray(s1).and.checkHardRarray(s2)) then
    call invertHardRarray(s2)
    passeverywhereHardz8i7xggsvp_mi=.true.
  endif

! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereHardRarray)
end function passeverywhereHardz8i7xggsvp_mi


! 
! Method:  passinCombRarray[]
! 

function S_passinCombRarraydr1ajn2st4_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinCombRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinCombRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_CombRarray_t) :: s
  ! in
  logical :: S_passinCombRarraydr1ajn2st4_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinCombRarray)
! insert code here (passinCombRarray method)
  logical checkCombRarray
  S_passinCombRarraydr1ajn2st4_mi=.false.
  S_passinCombRarraydr1ajn2st4_mi=checkCombRarray(s)
! DO-NOT-DELETE splicer.end(s.StructTest.passinCombRarray)
end function S_passinCombRarraydr1ajn2st4_mi


! 
! Method:  passinoutCombRarray[]
! 

function passinoutCombRarra5h9jc4m73f_mi(self, s, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_CombRarray_t) :: s
  ! inout
  logical :: passinoutCombRarra5h9jc4m73f_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passinoutCombRarray)
! insert code here (passinoutCombRarray method)
  logical checkCombRarray
  passinoutCombRarra5h9jc4m73f_mi = checkCombRarray(s)
  call invertCombRarray(s)
! DO-NOT-DELETE splicer.end(s.StructTest.passinoutCombRarray)
end function passinoutCombRarra5h9jc4m73f_mi


! 
! Method:  passeverywhereCombRarray[]
! 

function passeverywhereCombr1wm898lfo_mi(self, s1, s2, exception)
  use, intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_StructTest_impl
  ! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombRarray.use)
  ! insert code here (use statements)
  ! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombRarray.use)
  implicit none
  type(s_StructTest_t) :: self
  ! in
  type(s_CombRarray_t) :: s1
  ! in
  type(s_CombRarray_t) :: s2
  ! inout
  logical :: passeverywhereCombr1wm898lfo_mi
  ! out
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(s.StructTest.passeverywhereCombRarray)
! insert code here (passeverywhereCombRarray method)
  logical checkCombRarray

  if (checkCombRarray(s1).and.checkCombRarray(s2)) then
    call invertCombRarray(s2)
    passeverywhereCombr1wm898lfo_mi=.true.
  endif
! DO-NOT-DELETE splicer.end(s.StructTest.passeverywhereCombRarray)
end function passeverywhereCombr1wm898lfo_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! insert code here (extra code)
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
