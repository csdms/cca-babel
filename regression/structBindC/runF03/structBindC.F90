!
! File:       structBindC.F90
! Copyright:  (c) 2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 6171 $
! Date:       $Date: 2007-10-08 17:39:28 -0600 (Mon, 08 Oct 2007) $
! Description:Exercise the FORTRAN interface
!
!
#include "s_StructTest_fAbbrev.h"
#include "s_Simple_fAbbrev.h"
#include "s_Hard_fAbbrev.h"
#include "s_Empty_fAbbrev.h"
#include "s_Combined_fAbbrev.h"
#include "s_Color_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
#include "synch_ResultType_fAbbrev.h"


subroutine starttest(number)
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  integer (kind=sidl_int) :: number
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  call getInstance(tracker, throwaway_exception)
  call startPart(tracker, number, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end subroutine starttest

subroutine reporttest(test, number)
  use sidl
  use synch_RegOut
  use synch_ResultType
  use sidl_BaseInterface
  integer (kind=sidl_int) :: number
  logical                             :: test
!    implicit none
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  call getInstance(tracker, throwaway_exception)
  if (test) then
    call endPart(tracker, number, PASS, throwaway_exception)
  else
    call endPart(tracker, number, FAIL, throwaway_exception)
  endif
  call deleteRef(tracker, throwaway_exception)
  number = number + 1
end subroutine reporttest

logical function my_isprime(num)
  use sidl
  integer (kind=sidl_long) :: num
!    implicit none
  integer (kind=sidl_long) :: i
  i = 3_sidl_long
  do while (i*i .le. num)
     if (mod(num,i) .eq. 0_sidl_long) then
        my_isprime = .false.
        return
     endif
     i = i + 1_sidl_long
  enddo
  my_isprime = .true.
  return
end function my_isprime

integer (kind=selected_int_kind(18)) function my_nextprime(prev)
  use sidl
  integer (kind=sidl_long) :: prev
!    implicit none
  logical :: my_isprime
  if (prev .le. 1_sidl_long) then
     my_nextprime = 2_sidl_long
     return
  endif
  if (prev .eq. 2_sidl_long) then
     my_nextprime = 3_sidl_long
     return
  endif
  prev = prev + 2_sidl_long
  do while (.not. my_isprime(prev))
     prev = prev + 2_sidl_long
  enddo
  my_nextprime = prev
  return
end function my_nextprime

subroutine my_force_float(f)
  use sidl
  real(kind=sidl_float) :: f
  return
end subroutine my_force_float

subroutine my_force_fcomplex(f)
  use sidl
  complex(kind=sidl_fcomplex) :: f
  return
end subroutine my_force_fcomplex

subroutine initSimpleClient(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
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
  
end subroutine initSimpleClient


logical function checkSimpleClient(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
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
    checkSimpleClient=.true.
  else
    checkSimpleClient=.false.
  endif

  return

end

logical function checkSimpleInv(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_Color

  type(s_Simple_t),intent(in) :: s
  real, parameter :: eps = 1E-6

  if ((s%d_bool .eq. 0) .and. &
       (s%d_char .eq. '3') .and. &
       (abs(real(s%d_dcomplex) - 3.14_sidl_double) .lt. eps) .and. &
       (abs(aimag(s%d_dcomplex) + 3.14_sidl_double) .lt. eps) .and. &
       (abs(s%d_double + 3.14_sidl_double) .lt. eps) .and. &
       (abs(s%d_float + 3.1_sidl_float) .lt. eps) .and. &
       (abs(real(s%d_fcomplex) - 3.1_sidl_float) .lt. eps) .and. &
       (abs(aimag(s%d_fcomplex) + 3.1_sidl_float) .lt. eps) .and. &
       (s%d_int .eq. - 3) .and. &
       (s%d_long .eq. - 3) .and. &
       (.not. c_associated(s%d_opaque)) .and. &
       (s%d_enum .eq. red)) then
    checkSimpleInv=.true.
  else
    checkSimpleInv=.false.
  endif

  return

end

logical function checkHardClient(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_Color

  integer :: count = 0
  type(s_Hard_t),intent(in) :: s
  type(sidl_double_1d) :: dArray
  real(kind=sidl_double) :: temp0,temp1,temp2

  checkHardClient=.false.

  call cast(s%d_array,dArray)

  call get(dArray,0,temp0)
  call get(dArray,1,temp1)
  call get(dArray,2,temp2)

  if ((dimen(dArray) .eq. 1) .and. &
      ((length(dArray,0)) .eq. 3 ) .and. &
      (temp0 .eq. 1 )  .and. &
      (temp1 .eq. 2 )  .and. &
      (temp2 .eq. 3 )) then 
    checkHardClient=.true.
  endif 

  return

end

logical function checkHardInv(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Hard
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_Color

  integer :: count = 0
  type(s_Hard_t),intent(in) :: s
  type(sidl_double_1d) :: dArray
  real(kind=sidl_double) :: temp0,temp1,temp2

  checkHardInv=.false.

  call cast(s%d_array,dArray)

  call get(dArray,0,temp0)
  call get(dArray,1,temp1)
  call get(dArray,2,temp2)

  if ((dimen(dArray) .eq. 1) .and. &
      ((length(dArray,0)) .eq. 3 ) .and. &
      (temp0 .eq. 3 )  .and. &
      (temp1 .eq. 2 )  .and. &
      (temp2 .eq. 1 )) then 
    checkHardInv=.true.
  endif 

  return

end

logical function checkCombinedClient(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_Color

  type(s_Combined_t),intent(in) :: s
  type(sidl_double_1d) :: dArray

  logical checkSimpleClient
  logical checkHardClient

  checkCombinedClient=.false.

  if (checkSimpleClient(s%d_simple) .and. checkHardClient(s%d_hard)) then
    checkCombinedClient=.true.
  endif

  return

end

logical function checkCombinedInv(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_Combined
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest
  use s_Color

  type(s_Combined_t),intent(in) :: s
  type(sidl_double_1d) :: dArray

  logical checkSimpleInv
  logical checkHardInv

  checkCombinedInv=.false.

  if (checkSimpleInv(s%d_simple) .and. checkHardInv(s%d_hard)) then
    checkCombinedInv=.true.
  endif

  return

end

subroutine initHardRarray(r,arr)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_HardRarray_t),intent(inout) :: r
  integer,parameter :: N=3
  integer i 
  real(c_double), intent(inout),target :: arr(N)

  r%d_int=N

  do i=1,N
    arr(i)=i
  enddo

  r%d_rarrayFix(1)=5 
  r%d_rarrayFix(2)=10 
  r%d_rarrayFix(3)=15 

  r%d_rarrayRaw=c_loc(arr)

end subroutine initHardRarray

logical function checkHardRarrayClient(r)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

!  logical c_associated
  type(s_HardRarray_t),intent(in) :: r

  real(c_double),dimension(:),pointer :: r_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=r%d_rarrayRaw, & 
                   FPTR=r_d_rarrayRaw_fptr, & 
                   SHAPE=(/DIM/))

  checkHardRarrayClient=.false.

  if (c_associated(r%d_rarrayRaw) .and. &
    (r%d_int .eq. 3) .and. &
    (r_d_rarrayRaw_fptr(1) .eq. 1.0) .and. &
    (r_d_rarrayRaw_fptr(2) .eq. 2.0) .and. &
    (r_d_rarrayRaw_fptr(3) .eq. 3.0) .and. &
    (r%d_rarrayFix(1) .eq. 5.0) .and. &
    (r%d_rarrayFix(2) .eq. 10.0) .and. &
    (r%d_rarrayFix(3) .eq. 15.0)) then
    checkHardRarrayClient=.true.
  endif

  return

end

logical function checkHardRarrayInv(r)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_HardRarray_t),intent(in) :: r

  real(c_double),dimension(:),pointer :: r_d_rarrayRaw_fptr

  call C_F_POINTER(CPTR=r%d_rarrayRaw, & 
                   FPTR=r_d_rarrayRaw_fptr, & 
                   SHAPE=(/r%d_int/))

  checkHardRarrayInv=.false.

  if (c_associated(r%d_rarrayRaw) .and. &
    (r%d_int .eq. 3) .and. &
    (r_d_rarrayRaw_fptr(1) .eq. 3.0) .and. &
    (r_d_rarrayRaw_fptr(2) .eq. 2.0) .and. &
    (r_d_rarrayRaw_fptr(3) .eq. 1.0) .and. &
    (r%d_rarrayFix(1) .eq. 15.0) .and. &
    (r%d_rarrayFix(2) .eq. 10.0) .and. &
    (r%d_rarrayFix(3) .eq. 5.0)) then
    checkHardRarrayInv=.true.
  endif

  return

end

subroutine deleteHardRarray(r)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_HardRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_HardRarray_t),intent(inout) :: r
  integer,parameter :: N=3
  integer i 

  !
  ! Not really deleting anything since the deallocates happens in main, this
  ! just resets stuff.
  !

  r%d_int=-99

  r%d_rarrayFix(1)=-99
  r%d_rarrayFix(2)=-99 
  r%d_rarrayFix(3)=-99 

  r%d_rarrayRaw=c_null_ptr

end subroutine deleteHardRarray

subroutine initCombRarray(r,arr)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_CombRarray_t),intent(inout) :: r
  integer,parameter :: N=3
  real(c_double), intent(inout),target :: arr(N)

  call initSimpleClient(r%d_simple)
  call initHardRarray(r%d_hardRarray,arr)

end subroutine initCombRarray

logical function checkCombRarrayClient(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use s_Simple
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_CombRarray_t),intent(in) :: s

  logical checkSimpleClient
  logical checkHardRarrayClient

  checkCombRarrayClient=.false.

  if (checkSimpleClient(s%d_simple) .and. checkHardRarrayClient(s%d_hardRarray)) then
    checkCombRarrayClient=.true.
  endif

  return

end

logical function checkCombRarrayInv(s)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_CombRarray_t),intent(in) :: s

  logical checkSimpleInv
  logical checkHardRarrayInv

  checkCombRarrayInv=.false.

  if (checkSimpleInv(s%d_simple) .and. checkHardRarrayInv(s%d_hardRarray)) then
    checkCombRarrayInv=.true.
  endif

  return

end

subroutine deleteCombRarray(r,arr)
  use,intrinsic :: iso_c_binding
  use sidl
  use sidl_NotImplementedException
  use s_CombRarray
  use sidl_BaseInterface
  use sidl_RuntimeException
  use s_StructTest

  type(s_CombRarray_t),intent(inout) :: r
  integer,parameter :: N=3
  real(c_double), intent(inout),target :: arr(N)

  call deleteHardRarray(r%d_hardRarray,arr)

end subroutine deleteCombRarray

subroutine checkEmptyStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_Empty
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception
  
  type(s_Empty_t) :: e1,e2,e3,e4;
  
  call new(obj,throwaway_exception)

  call starttest(test)
  call writeComment(tracker, 'not_null(obj)', throwaway_exception)
  call reporttest(not_null(obj), test)

  call starttest(test)
  call writeComment(tracker, 'returnEmpty(obj,e1,throwaway_exception)', throwaway_exception)
  call returnEmpty(obj,e1,throwaway_exception) 
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, 'passinEmpty(obj,e1,retval,throwaway_exception)', throwaway_exception)
  call passinEmpty(obj,e1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutEmpty(obj,e2,retval,throwaway_exception)', throwaway_exception)
  call passoutEmpty(obj,e2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutEmpty(obj,e2,retval,throwaway_exception)', throwaway_exception)
  call passinoutEmpty(obj,e2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutEmpty(obj,e3,retval,throwaway_exception)', throwaway_exception)
  call passoutEmpty(obj,e3,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereEmpty(obj,e1,e2,e3,e4,throwaway_exception)', throwaway_exception)
  call passeverywhereEmpty(obj,e1,e2,e3,e4,throwaway_exception) 
  call reporttest(is_null(throwaway_exception), test)

end subroutine checkEmptyStructs

subroutine checkSimpleStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_Simple
  integer(kind=sidl_int), intent(inout) :: test
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  logical checkSimpleClient,checkSimpleInv
  
  type(s_Simple_t) :: s1,s2,s3,s4;
  
  call new(obj,throwaway_exception)

  call starttest(test)
  call writeComment(tracker, 'returnSimple(obj,s1,throwaway_exception)', throwaway_exception)
  call returnSimple(obj,s1,throwaway_exception) 
  retval=checkSimpleClient(s1)
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinSimple(obj,s1,retval,throwaway_exception)', throwaway_exception)
  call passinSimple(obj,s1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutSimple(obj,s2,retval,throwaway_exception)', throwaway_exception)
  call passoutSimple(obj,s2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutSimple(obj,s2,retval,throwaway_exception)', throwaway_exception)
  call passinoutSimple(obj,s2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'checkSimpleInv(s2)', throwaway_exception)
  retval = checkSimpleInv(s2) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutSimple(obj,s3,retval,throwaway_exception)', throwaway_exception)
  call passoutSimple(obj,s3,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereSimple(obj,s1,s2,s3,s4,throwaway_exception)', throwaway_exception)
  call passeverywhereSimple(obj,s1,s2,s3,s4,throwaway_exception) 
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, '(checkSimpleClient(s4) .and. checkSimpleClient(s2) .and. checkSimpleInv(s3))', throwaway_exception)
  retval=(checkSimpleClient(s4) .and. checkSimpleClient(s2) .and. checkSimpleInv(s3))
  call reporttest(retval, test)

end subroutine checkSimpleStructs

subroutine checkHardStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_Hard
  integer(kind=sidl_int), intent(inout) :: test
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  logical checkHardClient,checkHardInv
  
  type(s_Hard_t) :: h1,h2,h3,h4;
  
  call new(obj,throwaway_exception)

  call starttest(test)
  call writeComment(tracker, 'returnHard(obj,h1,throwaway_exception)', throwaway_exception)
  call returnHard(obj,h1,throwaway_exception) 
  retval=checkHardClient(h1)
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinHard(obj,h1,retval,throwaway_exception)', throwaway_exception)
  call passinHard(obj,h1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutHard(obj,h2,retval,throwaway_exception)', throwaway_exception)
  call passoutHard(obj,h2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutHard(obj,h2,retval,throwaway_exception)', throwaway_exception)
  call passinoutHard(obj,h2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'checkHardInv(h2)', throwaway_exception)
  retval = checkHardInv(h2) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutHard(obj,h3,retval,throwaway_exception)', throwaway_exception)
  call passoutHard(obj,h3,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereHard(obj,h1,h2,h3,h4,throwaway_exception)', throwaway_exception)
  call passeverywhereHard(obj,h1,h2,h3,h4,throwaway_exception) 
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, '(checkHardClient(h4) .and. checkHardClient(h2) .and. checkHardInv(h3))', throwaway_exception)
  retval=(checkHardClient(h4) .and. checkHardClient(h2) .and. checkHardInv(h3))
  call reporttest(retval, test)

end subroutine checkHardStructs

subroutine checkCombinedStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_Combined
  integer(kind=sidl_int), intent(inout) :: test
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  logical checkCombinedClient,checkCombinedInv
  
  type(s_Combined_t) :: c1,c2,c3,c4;
  
  call new(obj,throwaway_exception)

  call starttest(test)
  call writeComment(tracker, 'returnCombined(obj,c1,throwaway_exception)', throwaway_exception)
  call returnCombined(obj,c1,throwaway_exception) 
  retval=checkCombinedClient(c1)
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinCombined(obj,c1,retval,throwaway_exception)', throwaway_exception)
  call passinCombined(obj,c1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutCombined(obj,c2,retval,throwaway_exception)', throwaway_exception)
  call passoutCombined(obj,c2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutCombined(obj,c2,retval,throwaway_exception)', throwaway_exception)
  call passinoutCombined(obj,c2,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'checkCombinedInv(c2)', throwaway_exception)
  retval = checkCombinedInv(c2) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passoutCombined(obj,c3,retval,throwaway_exception)', throwaway_exception)
  call passoutCombined(obj,c3,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereCombined(obj,c1,c2,c3,c4,throwaway_exception)', throwaway_exception)
  call passeverywhereCombined(obj,c1,c2,c3,c4,throwaway_exception) 
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, '(checkCombinedClient(c4) .and. checkCombinedClient(c2) &
         .and. checkCombinedInv(c3))', throwaway_exception)
  retval=(checkCombinedClient(c4) .and. checkCombinedClient(c2) .and. checkCombinedInv(c3))
  call reporttest(retval, test)

end subroutine checkCombinedStructs


subroutine checkHardRarrayStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_HardRarray
  integer(kind=sidl_int), intent(inout) :: test
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception
  logical checkHardRarrayClient,checkHardRarrayInv
  type(s_HardRarray_t) :: r1,r2
  real(c_double),dimension(:),target,allocatable :: tempArr1,tempArr2
  integer,parameter :: N=3
  
  call new(obj,throwaway_exception)

  allocate(tempArr1(N))

  call initHardRarray(r1,tempArr1)

  call starttest(test)
  call writeComment(tracker, 'passinHardRarray(obj,r1,retval,throwaway_exception)', throwaway_exception)
  call passinHardRarray(obj,r1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutHardRarray(obj,r1,retval,throwaway_exception)', throwaway_exception)
  call passinoutHardRarray(obj,r1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'checkHardRarrayInv(r1)', throwaway_exception)
  retval = checkHardRarrayInv(r1) 
  call reporttest(retval, test)

  deallocate(tempArr1)
  call deleteHardRarray(r1,tempArr1)
  allocate(tempArr1(N))
  allocate(tempArr2(N))
  call initHardRarray(r1,tempArr1)
  call initHardRarray(r2,tempArr2)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereHardRarray(obj,r1,r2,retval,throwaway_exception)', throwaway_exception)
  call passeverywhereHardRarray(obj,r1,r2,retval,throwaway_exception)
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, '(checkHardRarrayClient(r1) .and. checkHardRarrayInv(r2))' &
         , throwaway_exception)
  retval=(checkHardRarrayClient(r1) .and. checkHardRarrayInv(r2))
  call reporttest(retval, test)

  deallocate(tempArr1)
  deallocate(tempArr2)

end subroutine checkHardRarrayStructs

subroutine checkCombRarrayStructs(test,tracker)
  use sidl
  use sidl_bool_array
  use sidl_BaseInterface
  use synch_RegOut
  use s_StructTest
  use s_CombRarray
  integer(kind=sidl_int), intent(inout) :: test
  type(synch_RegOut_t),intent(inout) :: tracker
  type(s_StructTest_t) :: obj
  logical ::  retval
  type(sidl_BaseInterface_t) :: throwaway_exception
  logical checkCombRarrayClient,checkCombRarrayInv
  type(s_CombRarray_t) :: r1,r2
  real(c_double),dimension(:),target,allocatable :: tempArr1,tempArr2
  integer,parameter :: N=3
  
  call new(obj,throwaway_exception)

  allocate(tempArr1(N))

  call initCombRarray(r1,tempArr1)

  call starttest(test)
  call writeComment(tracker, 'passinCombRarray(obj,r1,retval,throwaway_exception)', throwaway_exception)
  call passinCombRarray(obj,r1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'passinoutCombRarray(obj,r1,retval,throwaway_exception)', throwaway_exception)
  call passinoutCombRarray(obj,r1,retval,throwaway_exception) 
  call reporttest(retval, test)

  call starttest(test)
  call writeComment(tracker, 'checkCombRarrayInv(r1)', throwaway_exception)
  retval = checkCombRarrayInv(r1) 
  call reporttest(retval, test)

  deallocate(tempArr1)
  call deleteCombRarray(r1,tempArr1)
  allocate(tempArr1(N))
  allocate(tempArr2(N))
  call initCombRarray(r1,tempArr1)
  call initCombRarray(r2,tempArr2)

  call starttest(test)
  call writeComment(tracker, 'passeverywhereCombRarray(obj,r1,r2,retval,throwaway_exception)', throwaway_exception)
  call passeverywhereCombRarray(obj,r1,r2,retval,throwaway_exception)
  call reporttest(is_null(throwaway_exception), test)

  call starttest(test)
  call writeComment(tracker, '(checkCombRarrayClient(r1) .and. checkCombRarrayInv(r2))' &
         , throwaway_exception)
  retval=(checkCombRarrayClient(r1) .and. checkCombRarrayInv(r2))
  call reporttest(retval, test)

  deallocate(tempArr1)
  deallocate(tempArr2)

end subroutine checkCombRarrayStructs

program structBindC
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  use s_StructTest
  integer(kind=sidl_int) :: test
  type(sidl_BaseInterface_t) :: throwaway_exception
  type(synch_RegOut_t) :: tracker
  character (len=80)             :: language
  language = ' '
  if (IArgc() .ge. 1) then
     call GetArg(1, language)
	write (*,*) language
  endif

  call getInstance(tracker, throwaway_exception)
  test=1
  call setExpectations(tracker,41_sidl_int, throwaway_exception)
  call writeComment(tracker, 'Empty Struct Tests', throwaway_exception)
  call checkEmptyStructs(test,tracker)

  call writeComment(tracker, 'Simple Struct Tests', throwaway_exception)
  call checkSimpleStructs(test,tracker)

  call writeComment(tracker, 'Hard Struct Tests', throwaway_exception)
  call checkHardStructs(test,tracker)

  call writeComment(tracker, 'Combined Struct Tests', throwaway_exception)
  call checkCombinedStructs(test,tracker)

  call writeComment(tracker, 'HardRarray Struct Tests', throwaway_exception)
  call checkHardRarrayStructs(test,tracker)

  call writeComment(tracker, 'CombRarray Struct Tests', throwaway_exception)
  call checkCombRarrayStructs(test,tracker)

  call close(tracker, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end program structBindC
