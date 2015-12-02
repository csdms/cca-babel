!
! File:       argstest.F90
! Copyright:  (c) 2002 Lawrence Livermore National Security, LLC
! Revision:   @(#) $Revision: 5121 $
! Date:       $Date: 2005-12-09 14:41:13 -0800 (Fri, 09 Dec 2005) $
! Description:Exercise the FORTRAN interface
!
!
#include "hooks_Basics_fAbbrev.h"
#include "synch_RegOut_fAbbrev.h"
#include "synch_ResultType_fAbbrev.h"


subroutine testhooks(test)
  use sidl
  use hooks_Basics
  implicit none
  type(hooks_Basics_t) :: obj
  integer (kind=sidl_int)  :: test, ret, b, c
  logical                  :: out, inout, retval
  type(sidl_BaseInterface_t) :: throwaway_exception

  inout = .true.
  call new(obj, throwaway_exception)
  !
  ! Until the overloading issue can be addressed, the following approach
  ! must be used to enable hooks execution.
  !
  call hooks_Basics__set_hooks_static_m(inout, throwaway_exception)
  inout = .true.
  call hooks_Basics__set_hooks_m(obj, inout, throwaway_exception)

  call aStaticMeth(test, b, c, ret, throwaway_exception);
  test = test + 1
  call aNonStaticMeth(obj, test, b, c, ret, throwaway_exception);

  call deleteRef(obj, throwaway_exception)
end subroutine testhooks

program hookstest
  use sidl
  use synch_RegOut
  use sidl_BaseInterface
  integer (kind=sidl_int) :: test
  character (len=80)             :: language
  type(synch_RegOut_t) :: tracker
  type(sidl_BaseInterface_t) :: throwaway_exception
  language = ' '
  if (IArgc() .eq. 1) then
     call GetArg(1, language)
  endif
  call getInstance(tracker, throwaway_exception)
  test = 1
  call setExpectations(tracker, 2_sidl_int, throwaway_exception)
  call writeComment(tracker, 'hooks tests', throwaway_exception)
  call testhooks(test)
  call close(tracker, throwaway_exception)
  call deleteRef(tracker, throwaway_exception)
end program hookstest
