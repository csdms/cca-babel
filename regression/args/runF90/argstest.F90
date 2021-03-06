!
! File:       argstest.F90
! Copyright:  (c) 2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 6171 $
! Date:       $Date: 2007-10-08 16:39:28 -0700 (Mon, 08 Oct 2007) $
! Description:Exercise the FORTRAN interface
!
!
#include "Args_Basic_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
#include "synch_ResultType_fAbbrev.h"

subroutine starttest(number)
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  implicit none
  integer (kind=sidl_int) :: number
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  call getInstance(tracker, throwaway_exception)
  call startPart(tracker, number, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end subroutine starttest

subroutine reporttest(test, number, python)
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  use synch_ResultType
  implicit none
  integer (kind=sidl_int) :: number
  logical                             :: test, python
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  call getInstance(tracker, throwaway_exception)
  if (test) then
     call endPart(tracker, number, PASS, throwaway_exception)
  else
     if (python) then
        call endPart(tracker, number, XFAIL, throwaway_exception)
     else
        call endPart(tracker, number, FAIL, throwaway_exception)
     endif
  endif
  call deleteRef(tracker, throwaway_exception)
  number = number + 1
end subroutine reporttest

subroutine testbool(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)  :: test
  logical                         :: out, inout, retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = .true.
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackbool(obj, retval, throwaway_exception)
  call reporttest(retval, test,  .false.)
  call starttest(test)
  call passinbool(obj, .true., retval, throwaway_exception)
  call reporttest(retval, test,  .false.)
  call starttest(test)
  call passoutbool(obj, out, retval, throwaway_exception)
  call reporttest(retval .and. out, test,  .false.)
  call starttest(test)
  call passinoutbool(obj, inout, retval, throwaway_exception)
  call reporttest(retval .and. .not. inout, test,  .false.)
  call starttest(test)
  call passeverywherebool(obj, .true., out, inout, retval, throwaway_exception)
  call reporttest(retval .and. out .and. inout, test,  &
                  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testbool

subroutine testint(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)  :: test 
  logical                         :: bretval
  integer (kind=sidl_int)  :: iretval, out, inout
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = 3_sidl_int
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackint(obj, iretval, throwaway_exception)
  call reporttest(iretval .eq. 3_sidl_int, test,  .false.)
  call starttest(test)
  call passinint(obj, 3_sidl_int, bretval, throwaway_exception)
  call reporttest(bretval, test,  .false.)
  call starttest(test)
  call passoutint(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. 3_sidl_int), test,  .false.)
  call starttest(test)
  call passinoutint(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. -3_sidl_int), test,  &
                  .false.)
  call starttest(test)
  call passeverywhereint(obj, 3_sidl_int, out, inout, iretval, &
    throwaway_exception)
  call reporttest((iretval .eq. 3_sidl_int) .and.  &
                  (out .eq. 3_sidl_int) .and. &
                  (inout .eq. 3_sidl_int), test,  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testint

subroutine testchar(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type (Args_Basic_t) :: obj
  integer (kind=sidl_int)  :: test
  logical                         :: bretval
  character (len=1)               :: cretval, out, inout
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = 'A'
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackchar(obj, cretval, throwaway_exception)
  call reporttest(cretval .eq. '3', test,  .false.)
  call starttest(test)
  call passinchar(obj, '3', bretval, throwaway_exception)
  call reporttest(bretval, test,  .false.)
  call starttest(test)
  call passoutchar(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. '3'), test,  &
                  .false.)
  call starttest(test)
  call passinoutchar(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. 'a'), test,  &
                  .false.)
  call starttest(test)
  call passeverywherechar(obj, '3', out, inout, cretval, throwaway_exception)
  call reporttest((cretval .eq. '3') .and.  (out .eq. '3') .and. &
                  (inout .eq. 'A'), test,  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testchar

subroutine testlong(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)  :: test
  logical                         :: bretval
  integer (kind=sidl_long) :: out, inout, iretval, inval
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = 3_sidl_long
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbacklong(obj, iretval, throwaway_exception)
  call reporttest(iretval .eq. 3_sidl_long, test,  .false.)
  call starttest(test)
  inval = 3_sidl_long
  call passinlong(obj, inval, bretval, throwaway_exception)
  call reporttest(bretval, test,  .false.)
  call starttest(test)
  call passoutlong(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. 3_sidl_long), test,  .false.)
  call starttest(test)
  call passinoutlong(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. -3_sidl_long), test,  &
                  .false.)
  call starttest(test)
  inval = 3_sidl_long
  call passeverywherelong(obj, inval, out, inout, iretval, throwaway_exception)
  call reporttest((iretval .eq. 3_sidl_long) .and.  &
                  (out .eq. 3_sidl_long) .and. &
                  (inout .eq. 3_sidl_long), test,  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testlong

subroutine testfloat(test,  python)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)  :: test
  logical                         :: bretval, python
  real (kind=sidl_float) :: out, inout, fretval
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = 3.1_sidl_float
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackfloat(obj, fretval, throwaway_exception)
  call reporttest(fretval .eq. 3.1_sidl_float, test,  .false.)
  call starttest(test)
  call passinfloat(obj, 3.1_sidl_float, bretval, &
     throwaway_exception)
  call reporttest(bretval, test,  python)
  call starttest(test)
  call passoutfloat(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. 3.1_sidl_float), test,  &
                  .false.)
  call starttest(test)
  call passinoutfloat(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. -3.1_sidl_float), test,  &
                  .false.)
  call starttest(test)
  call passeverywherefloat(obj, 3.1_sidl_float, out, inout, fretval, &
      throwaway_exception)
  call reporttest((fretval .eq. 3.1_sidl_float) .and.  &
                  (out .eq. 3.1_sidl_float) .and. &
                  (inout .eq. 3.1_sidl_float), test,  python)
  call deleteRef(obj, throwaway_exception)
end subroutine testfloat

subroutine testdouble(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)    :: test
  logical                           :: bretval
  real (kind=sidl_double) :: out, inout, dretval
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = 3.14_sidl_double
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackdouble(obj, dretval, throwaway_exception)
  call reporttest(dretval .eq. 3.14_sidl_double, test,  .false.)
  call starttest(test)
  call passindouble(obj, 3.14_sidl_double, bretval, throwaway_exception)
  call reporttest(bretval, test,  .false.)
  call starttest(test)
  call passoutdouble(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. 3.14_sidl_double), test,  &
                  .false.)
  call starttest(test)
  call passinoutdouble(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. -3.14_sidl_double), test,  &
                  .false.)
  call starttest(test)
  call passeverywheredouble(obj, 3.14_sidl_double, out, inout, dretval, &
      throwaway_exception)
  call reporttest((dretval .eq. 3.14_sidl_double) .and.  &
                  (out .eq. 3.14_sidl_double) .and. &
                  (inout .eq. 3.14_sidl_double), test,  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testdouble

subroutine testfcomplex(test,  python)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)     :: test
  logical                            :: bretval, python
  complex (kind=sidl_fcomplex) :: in, out, inout, cretval
  type(sidl_BaseInterface_t) :: throwaway_exception

  in = (3.1_sidl_float,3.1_sidl_float)
  inout = (3.1_sidl_float, 3.1_sidl_float)
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackfcomplex(obj, cretval, throwaway_exception)
  call reporttest(cretval .eq. (3.1_sidl_float,3.1_sidl_float), test, &
        .false.)
  call starttest(test)
  call passinfcomplex(obj, in, bretval, throwaway_exception)
  call reporttest(bretval, test,  python)
  call starttest(test)
  call passoutfcomplex(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. (out .eq. (3.1_sidl_float,3.1_sidl_float)), &
      test,  .false.)
  call starttest(test)
  call passinoutfcomplex(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. (inout .eq. (3.1_sidl_float,-3.1_sidl_float)),&
      test, .false.)
  call starttest(test)
  call passeverywherefcomplex(obj, in, out, inout, cretval, &
       throwaway_exception)
  call reporttest((cretval .eq. (3.1_sidl_float,3.1_sidl_float)) .and.  (out .eq. (3.1_sidl_float,3.1_sidl_float)) .and. &
                  (inout .eq. (3.1_sidl_float,3.1_sidl_float)), test,  python)
  call deleteRef(obj, throwaway_exception)
end subroutine testfcomplex

subroutine testdcomplex(test)
  use sidl
  use Args_Basic
  use sidl_BaseInterface
  implicit none
  type(Args_Basic_t) :: obj
  integer (kind=sidl_int)       :: test
  logical                              :: bretval
  complex (kind=sidl_dcomplex) :: in, out, inout, cretval
  type(sidl_BaseInterface_t) :: throwaway_exception

  in = (3.14_sidl_double,3.14_sidl_double)
  inout = (3.14_sidl_double, 3.14_sidl_double)
  call new(obj, throwaway_exception)
  call starttest(test)
  call returnbackdcomplex(obj, cretval, throwaway_exception)
  call reporttest(cretval .eq. (3.14_sidl_double,3.14_sidl_double), test,  &
                  .false.)
  call starttest(test)
  call passindcomplex(obj, in, bretval, throwaway_exception)
  call reporttest(bretval, test,  .false.)
  call starttest(test)
  call passoutdcomplex(obj, out, bretval, throwaway_exception)
  call reporttest(bretval .and. &
           (out .eq. (3.14_sidl_double,3.14_sidl_double)), test, .false.)
  call starttest(test)
  call passinoutdcomplex(obj, inout, bretval, throwaway_exception)
  call reporttest(bretval .and. &
           (inout .eq. (3.14_sidl_double,-3.14_sidl_double)), test, .false.)
  call starttest(test)
  call passeverywheredcomplex(obj, in, out, inout, cretval, &
           throwaway_exception)
  call reporttest((cretval .eq. (3.14_sidl_double,3.14_sidl_double)) .and.  &
                  (out .eq. (3.14_sidl_double,3.14_sidl_double)) .and. &
                  (inout .eq. (3.14_sidl_double,3.14_sidl_double)), test,   &
                  .false.)
  call deleteRef(obj, throwaway_exception)
end subroutine testdcomplex


program argstest
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  integer (kind=sidl_int) :: test
  integer (kind=sidl_int), parameter :: numparts = 40_sidl_int
  character (len=80)             :: language
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  language = ' '
  if (IArgc() .eq. 1) then
     call GetArg(1, language)
  endif
  call getInstance(tracker, throwaway_exception)
  test = 1
  call setExpectations(tracker, 40_sidl_int, throwaway_exception)
  call writeComment(tracker, 'Boolean tests', throwaway_exception)
  call testbool(test)
  call writeComment(tracker, 'Character tests', throwaway_exception)
  call testchar(test)
  call writeComment(tracker, 'Integer tests', throwaway_exception)
  call testint(test)
  call writeComment(tracker, 'Long tests', throwaway_exception)
  call testlong(test)
  call writeComment(tracker, 'Float tests', throwaway_exception)
  call testfloat(test,  language .eq. 'Python')
  call writeComment(tracker, 'Double tests', throwaway_exception)
  call testdouble(test)
  call writeComment(tracker, 'Fcomplex tests', throwaway_exception)
  call testfcomplex(test,  language .eq. 'Python')
  call writeComment(tracker, 'Dcomplex tests', throwaway_exception)
  call testDcomplex(test)
  call close(tracker, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end program argstest
