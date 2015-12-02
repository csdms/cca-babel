!
! File:       exceptionclient.F90
! Copyright:  (c) 2001-2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 6171 $
! Date:       $Date: 2007-10-08 16:39:28 -0700 (Mon, 08 Oct 2007) $
! Description:Simple F90 exception test client
!
!
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_SIDLException_fAbbrev.h"
#include "ExceptionTest_Fib_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"

subroutine starttest(number)
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  implicit none
  integer (kind=sidl_int) :: number
  type(sidl_BaseInterface_t) :: throwaway
  type(synch_RegOut_t) :: tracker
  call getInstance(tracker, throwaway)
  call startPart(tracker, number, throwaway)
  call deleteRef(tracker, throwaway)
end subroutine starttest

subroutine reporttest(test, number)
  use sidl
  use synch_RegOut
  use synch_ResultType
  use sidl_BaseInterface
  implicit none
  integer (kind=sidl_int) :: number
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway
  logical                        :: test
  call getInstance(tracker, throwaway)
  if (test) then
     call endPart(tracker, number, PASS, throwaway)
  else
     call endPart(tracker, number, FAIL, throwaway)
  endif
  number = number + 1_sidl_int
  call deleteRef(tracker, throwaway)
end subroutine reporttest

subroutine reportexc(sExcept)
  use sidl_SIDLException
  use sidl_BaseInterface
  implicit none
  type(sidl_BaseInterface_t) :: throwaway
  type(sidl_SIDLException_t)  :: sExcept
  character (len=100)         :: msg
  character (len=1024)        :: trace

  call getNote(sExcept, msg, throwaway)
  write (6, *) msg
  call getTrace(sExcept, trace, throwaway)
  write (6, *) trace
end subroutine reportexc

subroutine testnone(fib, test)
  use sidl
  use ExceptionTest_Fib
  use sidl_BaseInterface
  use sidl_SIDLException
  implicit none
  type(ExceptionTest_Fib_t)      :: fib
  type(sidl_BaseInterface_t)     :: iExcept
  type(sidl_SIDLException_t)     :: sExcept
  integer (kind=sidl_int) :: test
  integer (kind=sidl_int) :: retval
  type(sidl_BaseInterface_t) :: throwaway

  call starttest(test)
  call getFib(fib, 10_sidl_int, 25_sidl_int, 200_sidl_int, 0_sidl_int, &
        retval, iExcept)
  if (is_null(iExcept)) then
     call reporttest(.true., test)
     write (6, 100) retval
  else
     call reporttest(.false., test)
     call cast(iExcept, sExcept, throwaway)
     call reportexc(sExcept)
     call deleteRef(sExcept, throwaway)
     call deleteRef(iExcept, throwaway)
  endif
100 format ('fib= ', I4)
end subroutine testnone

subroutine testneg(fib, test)
  use sidl
  use sidl_BaseInterface
  use sidl_SIDLException
  use ExceptionTest_Fib
  implicit none
  type(ExceptionTest_Fib_t)      :: fib
  type(sidl_BaseInterface_t)     :: iExcept
  type(sidl_SIDLException_t)     :: sExcept
  integer (kind=sidl_int) :: test
  integer (kind=sidl_int) :: retval
  logical                        :: isone
  type(sidl_BaseInterface_t) :: throwaway

  call starttest(test)
  call getFib(fib, -1_sidl_int, 10_sidl_int, 10_sidl_int, 0_sidl_int, &
        retval, iExcept)
  if (is_null(iExcept)) then
     call reporttest(.false., test)
     write (6, 100) retval
  else
     call isType(iExcept, &
          'ExceptionTest.NegativeValueException', isone, throwaway)
     if (isone .eqv. .true.) then
        call reporttest(.true., test)
     else
        call reporttest(.false., test)
     endif
     call cast(iExcept, sExcept, throwaway)
     call reportexc(sExcept)
     call deleteRef(sExcept, throwaway)
     call deleteRef(iExcept, throwaway)
  endif
100 format ('fib= ', I4)
end subroutine testneg

subroutine testdeep(fib, test)
  use sidl
  use sidl_BaseInterface
  use sidl_SIDLException
  use ExceptionTest_Fib
  implicit none
  type(ExceptionTest_Fib_t)      :: fib
  type(sidl_BaseInterface_t)     :: iExcept
  type(sidl_SIDLException_t)     :: sExcept
  integer (kind=sidl_int) :: test
  integer (kind=sidl_int) :: retval
  logical                        :: isone
  type(sidl_BaseInterface_t) :: throwaway

  call starttest(test)
  call getFib (fib, 10_sidl_int, 1_sidl_int, 100_sidl_int, 0_sidl_int, &
         retval, iExcept)
  if (is_null(iExcept)) then
     call reporttest(.false., test)
     write (6, 100) retval
  else
     call isType(iExcept, 'ExceptionTest.TooDeepException', &
          isone, throwaway)
     if (isone .eqv. .true.) then
        call reporttest(.true., test)
     else
        call reporttest(.false., test)
     endif
     call cast(iExcept, sExcept, throwaway)
     call reportexc(sExcept)
     call deleteRef(sExcept, throwaway)
     call deleteRef(iExcept, throwaway)
  endif
100 format ('fib= ', I4)
end subroutine testdeep

subroutine testbig(fib, test)
  use sidl
  use sidl_BaseInterface
  use sidl_SIDLException
  use ExceptionTest_Fib
  implicit none
  type(ExceptionTest_Fib_t)      :: fib
  type(sidl_BaseInterface_t)     :: iExcept
  type(sidl_SIDLException_t)     :: sExcept
  integer (kind=sidl_int) :: test
  integer (kind=sidl_int) :: retval
  integer (kind=sidl_int), parameter :: n = 10, max_depth = 100, &
       depth = 0, maxvalue = 1
  logical                        :: isone
  type(sidl_BaseInterface_t) :: throwaway

  call starttest(test)
  call getFib(fib, n, max_depth, depth, maxvalue, retval, iExcept)
  if (is_null(iExcept)) then
     call reporttest(.false., test)
     write (6, 100) retval
  else
     call isType(iExcept, 'ExceptionTest.TooBigException', &
          isone, throwaway)
     if (isone .eqv. .true.) then
        call reporttest(.true., test)
     else
        call reporttest(.false., test)
     endif
     call cast(iExcept, sExcept, throwaway)
     call reportexc(sExcept)
     call deleteRef(sExcept, throwaway)
     call deleteRef(iExcept, throwaway)
  endif
100 format ('fib= ', I4)
end subroutine testbig

subroutine testleak(fib, test, userow)
  use sidl
  use ExceptionTest_Fib
  use synch_RegOut
  use sidl_BaseInterface
  use sidl_BaseClass
  use sidl_int_array
  type(ExceptionTest_Fib_t)  :: fib
  integer (kind=sidl_int) :: test
  logical :: userow
  logical :: righttype
  type(sidl_int_2d) :: a1, a2, a3, retval
  type(sidl_int_1d) :: c1, c2, c3
  type(sidl_BaseClass_t) :: o1, o2, o3
  integer (kind=sidl_int), dimension(2,2)  :: buffer1, buffer2
  character (len=128) :: s1, s2, s3
  type(sidl_BaseInterface_t) :: exception, throwaway
  s1 = 'foo'
  s2 = 'foo'
  m = 2 
  n = 2
  if (userow) then
     call create2dRow(3_sidl_int, 3_sidl_int, a1)
     call create2dRow(4_sidl_int, 4_sidl_int, a2)
  else
     call create2dCol(3_sidl_int, 3_sidl_int, a1)
     call create2dCol(4_sidl_int, 4_sidl_int, a2)
  endif
  call create1d(3_sidl_int, c1)
  call create1d(4_sidl_int, c2)
  call new(o1, throwaway)
  call new(o2, throwaway)
  call starttest(test)
  call noLeak(fib, a1, a2, a3, buffer1, buffer2, &
       c1, c2, c3, s1, s2, s3, o1, o2, o3, retval, exception)
  if (not_null(exception)) then
     call isType(exception, 'sidl.SIDLException', righttype, throwaway)
     call reporttest(righttype, test)
     if (not_null(o1)) then
        call deleteRef(o1, throwaway)
     endif
     if (not_null(c1)) then
        call deleteRef(c1)
     endif
     if (not_null(a1)) then
        call deleteRef(a1)
     endif
     call deleteRef(exception, throwaway)
  else
     call reporttest(.false., test)
  endif
end subroutine testleak

subroutine testleaktwo(fib, test, userow)
  use sidl
  use ExceptionTest_Fib
  use synch_RegOut
  use sidl_BaseInterface
  use sidl_BaseClass
  use sidl_int_array
  type(ExceptionTest_Fib_t)  :: fib
  integer (kind=sidl_int) :: test
  logical :: userow
  logical :: righttype
  type(sidl_int_2d) :: a1, a2, a3, retval, r1, r2
  type(sidl_int_1d) :: c1, c2, c3
  type(sidl_BaseClass_t) :: o1, o2, o3
  character (len=128) :: s1, s2, s3
  type(sidl_BaseInterface_t) :: exception, throwaway
  s1 = 'foo'
  s2 = 'foo'
  m = 2 
  n = 2
  if (userow) then
     call create2dRow(3_sidl_int, 3_sidl_int, a1)
     call create2dRow(4_sidl_int, 4_sidl_int, a2)
     call create2dRow(3_sidl_int, 3_sidl_int, r1)
     call create2dRow(3_sidl_int, 3_sidl_int, r2)
  else
     call create2dCol(3_sidl_int, 3_sidl_int, a1)
     call create2dCol(4_sidl_int, 4_sidl_int, a2)
     call create2dCol(3_sidl_int, 3_sidl_int, r1)
     call create2dCol(3_sidl_int, 3_sidl_int, r2)
  endif
  call create1d(3_sidl_int, c1)
  call create1d(4_sidl_int, c2)
  call new(o1, throwaway)
  call new(o2, throwaway)
  call starttest(test)
  call noLeak(fib, a1, a2, a3, r1, r2, &
       c1, c2, c3, s1, s2, s3, o1, o2, o3, retval, exception)
  if (not_null(exception)) then
     call isType(exception, 'sidl.SIDLException', righttype, throwaway)
     call reporttest(righttype, test)
     if (not_null(o1)) then
        call deleteRef(o1, throwaway)
     endif
     if (not_null(r1)) then
        call deleteRef(r1)
     endif
     if (not_null(c1)) then
        call deleteRef(c1)
     endif
     if (not_null(a1)) then
        call deleteRef(a1)
     endif
     call deleteRef(exception, throwaway)
  else
     call reporttest(.false., test)
  endif
end subroutine testleaktwo


program exceptionclient
  use sidl
  use ExceptionTest_Fib
  use synch_RegOut
  implicit none
  integer (kind=sidl_int)  :: test
  type(synch_RegOut_t)            :: tracker
  type(ExceptionTest_Fib_t)       :: fib
  type(sidl_BaseInterface_t) :: throwaway

  call getInstance(tracker, throwaway)
  call setExpectations(tracker, 8_sidl_int, throwaway)
  call new(fib, throwaway)

  test = 1_sidl_int

  call writeComment(tracker, 'No Exception test            ', throwaway)
  call testnone(fib, test)
  call writeComment(tracker, 'Negative Value Exception test', throwaway)
  call testneg(fib, test)
  call writeComment(tracker, 'Too Deep Exception test      ', throwaway)
  call testdeep(fib, test)
  call writeComment(tracker, 'Too Big Exception test       ', throwaway)
  call testbig(fib, test)

  call writeComment(tracker, &
       'Test for memory leaks and ignored return values', &
       throwaway)
  call testleak(fib, test, .true.)
  call testleak(fib, test, .false.)
  call testleaktwo(fib, test, .true.)
  call testleaktwo(fib, test, .false.)


  call deleteRef(fib, throwaway)
  call close(tracker, throwaway)
  call deleteRef(tracker, throwaway)
end program exceptionclient
