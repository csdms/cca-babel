!
! File:       overloadtest.F90
! Copyright:  (c) 2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 6171 $
! Date:       $Date: 2007-10-08 16:39:28 -0700 (Mon, 08 Oct 2007) $
! Description:Simple F90 overload test client
!
!

#include "Overload_AClass_fAbbrev.h"
#include "Overload_AnException_fAbbrev.h"
#include "Overload_BClass_fAbbrev.h"
#include "Overload_ParentTest_fAbbrev.h"
#include "Overload_Test_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
#include "synch_ResultType_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"

subroutine starttest(number)
  use sidl
  use synch_RegOut
  implicit none
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
  implicit none
  integer (kind=sidl_int) :: number
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  logical                        :: test
  call getInstance(tracker, throwaway_exception)
  if (test) then
     call endPart(tracker, number, PASS, throwaway_exception)
  else
     call endPart(tracker, number, FAIL, throwaway_exception)
  endif
  call deleteRef(tracker, throwaway_exception)
  number = number + 1
end subroutine reporttest

subroutine testnone(t, test)
  use sidl
  use Overload_Test
  implicit none
  integer (kind=sidl_int)  :: test
  type(Overload_Test_t) :: t
  integer (kind=sidl_int)  :: retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  retval = 0

  call starttest(test)
  call getValue(t, retval, throwaway_exception)
  call reporttest(retval .eq. 1, test)
end subroutine testnone

subroutine testone(t, test)
  use sidl
  use Overload_Test
  use Overload_AnException
  use Overload_AClass
  use Overload_BClass
  implicit none
  character*80 s1, sretval
  integer (kind=sidl_int)       :: test
  type(Overload_Test_t)                :: t
  type(Overload_AnException_t)         :: ae
  type(Overload_AClass_t)              :: ac
  type(Overload_BClass_t)              :: bc
  integer (kind=sidl_int)       :: i1, iretval
  real (kind=sidl_double)    :: d1, dretval
  real (kind=sidl_float)      :: f1, fretval
  logical                              :: b1, bretval
  complex (kind=sidl_fcomplex)   :: fc, fcretval
  complex (kind=sidl_dcomplex) :: dc, dcretval
  type(sidl_BaseInterface_t) :: throwaway_exception

  b1 = .true.
  d1 = 1.0d0
  f1 = 1.0
  i1 = 1
  fc = (1.1, 1.1)
  dc = (2.2d0, 2.2d0)
  s1 = 'AnException'

  call starttest(test)
  call getValue(t, b1, bretval, throwaway_exception)
  call reporttest(bretval .eqv. b1, test)
  call starttest(test)
  call getValue(t, d1, dretval, throwaway_exception)
  call reporttest(dretval .eq. d1, test)
  call starttest(test)
  call getValue(t, dc, dcretval, throwaway_exception)
  call reporttest(dcretval .eq. dc, test)
  call starttest(test)
  call getValue(t, f1, fretval, throwaway_exception)
  call reporttest(fretval .eq. f1, test)
  call starttest(test)
  call getValue(t, fc, fcretval, throwaway_exception)
  call reporttest(fcretval .eq. fc, test)
  call starttest(test)
  call getValue(t, i1, iretval, throwaway_exception)
  call reporttest(iretval .eq. i1, test)
  call starttest(test)
  call getValue(t, s1, sretval, throwaway_exception)
  call reporttest(sretval .eq. s1, test)

  call new(ae, throwaway_exception)
  call starttest(test)
  call getValue(t, ae, sretval, throwaway_exception)
  call reporttest(sretval .eq. s1, test)
  call deleteRef(ae, throwaway_exception)
  call new(ac, throwaway_exception)
  call starttest(test)
  call getValue(t, ac, iretval, throwaway_exception)
  call reporttest(iretval .eq. 2, test)
  call deleteRef(ac, throwaway_exception)
  call new(bc, throwaway_exception)
  call starttest(test)
  call getValue(t, bc, iretval, throwaway_exception)
  call reporttest(iretval .eq. 2, test)
  call deleteRef(bc, throwaway_exception)
end subroutine testone

subroutine testtwo(t, test)
  use sidl
  use Overload_Test
  implicit none
  integer (kind=sidl_int)    :: test
  type(Overload_Test_t)             :: t
  integer (kind=sidl_int)    :: i1, iretval
  real (kind=sidl_double) :: d1, dretval, did
  real (kind=sidl_float)   :: f1
  type(sidl_BaseInterface_t) :: throwaway_exception

  d1 = 1.0d0
  i1 = 1
  did =2.0d0

  call starttest(test)
  call getValue(t, d1, i1, dretval, throwaway_exception)
  call reporttest(dretval .eq. did, test)
  call starttest(test)
  call getValue(t, i1, d1, dretval, throwaway_exception)
  call reporttest(dretval .eq. did, test)
end subroutine testtwo

subroutine testthree(t, test)
  use sidl
  use Overload_Test
  implicit none
  type(Overload_Test_t)             :: t
  integer (kind=sidl_int)    :: i1
  integer (kind=sidl_int)    :: test
  real (kind=sidl_double) :: d1, difd, dretval
  real (kind=sidl_float)   :: f1
  type(sidl_BaseInterface_t) :: throwaway_exception

  d1 = 1.0d0
  f1 = 1.0
  i1 = 1
  difd = 3.0d0

  call starttest(test)
  call getValue(t, d1, i1, f1, dretval, throwaway_exception)
  call reporttest(dretval .eq. difd, test)
  call starttest(test)
  call getValue(t, i1, d1, f1, dretval, throwaway_exception)
  call reporttest(dretval .eq. difd, test)
  call starttest(test)
  call getValue(t, d1, f1, i1, dretval, throwaway_exception)
  call reporttest(dretval .eq.  difd, test)
  call starttest(test)
  call getValue(t, i1, f1, d1, dretval, throwaway_exception)
  call reporttest(dretval .eq. difd, test)
  call starttest(test)
  call getValue(t, f1, d1, i1, dretval, throwaway_exception)
  call reporttest(dretval .eq. difd, test)
  call starttest(test)
  call getValue(t, f1, i1, d1, dretval, throwaway_exception)
  call reporttest(dretval .eq. difd, test)
end subroutine testthree


program overloadtest
  use sidl
  use Overload_Test
  use synch_RegOut
  implicit none
  integer (kind=sidl_int)  :: test
  type(Overload_Test_t) :: t
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception

  call getInstance(tracker, throwaway_exception)
  call setExpectations(tracker, 19_sidl_int, throwaway_exception)
  call new(t, throwaway_exception)

  test = 1

  call writeComment(tracker, 'No Argument test             ', throwaway_exception)
  call testnone(t, test)
  call writeComment(tracker, 'Single Argument tests        ', throwaway_exception)
  call testone(t, test)
  call writeComment(tracker, 'Double Argument tests        ', throwaway_exception)
  call testtwo(t, test)
  call writeComment(tracker, 'Triple Argument tests        ', throwaway_exception)
  call testthree(t, test)

  call deleteRef(t, throwaway_exception)

  call close(tracker, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end program overloadtest
