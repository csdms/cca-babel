!
! File:       stringstest.F90
! Copyright:  (c) 2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 6171 $
! Date:       $Date: 2007-10-08 16:39:28 -0700 (Mon, 08 Oct 2007) $
! Description:Exercise the FORTRAN interface
!

#include "Strings_Cstring_fAbbrev.h"
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

subroutine reporttest(test, number)
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
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

subroutine teststring(test)
  use sidl
  use Strings_Cstring
  use sidl_BaseInterface
  implicit none
  type(Strings_Cstring_t)         :: obj
  type(sidl_BaseInterface_t) :: throwaway_exception
  integer (kind=sidl_int)  :: test
  logical                         :: retval
  character (len=80)              :: in, inout, out, sreturn
  character (len=1)               :: ch1, ch2
  call new(obj, throwaway_exception)
  sreturn = 'Not three'
  call starttest(test)
  call returnback(obj, .true., sreturn, throwaway_exception)
  call reporttest(sreturn .eq. 'Three', test)
  retval = .false.
  call starttest(test)
  call passin(obj, 'Three', retval, throwaway_exception)
  call reporttest(retval, test)
  in = 'Three'
  call starttest(test)
  call passin(obj, in, retval, throwaway_exception)
  call reporttest(retval, test)
  call starttest(test)
  call passin(obj, 'Four', retval, throwaway_exception)
  call reporttest(.not. retval, test)
  out = 'Not three'
  call starttest(test)
  call passout(obj, .true., out, retval, throwaway_exception)
  call reporttest(retval .and. out .eq. 'Three', test)
  inout = 'Three'
  call starttest(test)
  call passinout(obj, inout, retval, throwaway_exception)
  call reporttest(retval .and. inout .eq. 'threes', test)
  call starttest(test)
  call passeverywhere(obj, 'Three', out, inout, sreturn, &
	throwaway_exception)
  call reporttest(sreturn .eq. 'Three' .and. out .eq. 'Three' .and. &
       inout .eq. 'Three', test)
  call starttest(test)
  call mixedarguments(obj, 'Test', 'z', 'Test', 'z', retval, &
	throwaway_exception)
  call reporttest(retval, test)
  call starttest(test)
  call mixedarguments(obj, 'Not', 'A', 'Equal', 'a', retval, &
	throwaway_exception)
  call reporttest(.not. retval, test)
  ch1 = 'z'
  ch2 = 'z'
  call starttest(test)
  call mixedarguments(obj, 'Test', ch1, 'Test', ch1, retval, &
       throwaway_exception)
  call reporttest(retval, test)
  call starttest(test)
  call mixedarguments(obj, 'Test', ch1, 'Test', ch2, retval, &
       throwaway_exception)
  call reporttest(retval, test)
  ch2 = 'A'
  call starttest(test)
  call mixedarguments(obj, 'Not', ch1, 'Equal', ch2, retval, &
       throwaway_exception)
  call reporttest(.not. retval, test)
  call deleteRef(obj, throwaway_exception)

end subroutine teststring

program stringstest
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  integer (kind=sidl_int) :: test
  type(sidl_BaseInterface_t) :: throwaway_exception
  type(synch_RegOut_t) :: tracker
  test = 1
  call getInstance(tracker, throwaway_exception)
  call setExpectations(tracker, 12_sidl_int, throwaway_exception)
  call writeComment(tracker, 'String tests', throwaway_exception)
  call teststring(test)
  call close(tracker, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end program stringstest
