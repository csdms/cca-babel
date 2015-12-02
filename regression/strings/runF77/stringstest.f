c
c     File:       argstest.f
c     Copyright:  (c) 2001 Lawrence Livermore National Security, LLC
c     Revision:   @(#) $Revision: 6183 $
c     Date:       $Date: 2007-10-15 14:41:51 -0700 (Mon, 15 Oct 2007) $
c     Description:Exercise the FORTRAN interface
c
c
      subroutine starttest(number)
      implicit none
      integer*4 number
      integer*8 tracker, tae
      call synch_RegOut_getInstance_f(tracker, tae)
      call synch_RegOut_startPart_f(tracker, number, tae)
      call synch_RegOut_deleteRef_f(tracker, tae)
      end

      subroutine reporttest(test, number)
      implicit none
      integer*4 number
      integer*8 tracker, tae
      logical test
      include 'synch_ResultType.inc'
      call synch_RegOut_getInstance_f(tracker, tae)
      if (test) then
         call synch_RegOut_endPart_f(tracker, number, PASS,
     $        tae)
      else
         call synch_RegOut_endPart_f(tracker, number, FAIL,
     $        tae)
      endif
      call synch_RegOut_deleteRef_f(tracker, tae)
      number = number + 1
      end

      subroutine teststring(test)
      implicit none
      integer*8 obj, tae
      integer*4 test
      logical retval
      character*80 in, inout, out, sreturn
      character ch1, ch2
      call Strings_Cstring__create_f(obj, tae)
      sreturn = 'Not three'
      call starttest(test)
      call Strings_Cstring_returnback_f(obj, .true., sreturn, tae)
      call reporttest(sreturn .eq. 'Three', test)
      retval = .false.
      call starttest(test)
      call Strings_Cstring_passin_f(obj, 'Three', retval, tae)
      call reporttest(retval, test)
      in = 'Three'
      call starttest(test)
      call Strings_Cstring_passin_f(obj, in, retval, tae)
      call reporttest(retval, test)
      call starttest(test)
      call Strings_Cstring_passin_f(obj, 'Four', retval, tae)
      call reporttest(.not. retval, test)
      out = 'Not three'
      call starttest(test)
      call Strings_Cstring_passout_f(obj, .true., out, retval, tae)
      call reporttest(retval .and. out .eq. 'Three', test)
      inout = 'Three'
      call starttest(test)
      call Strings_Cstring_passinout_f(obj, inout, retval, tae)
      call reporttest(retval .and. inout .eq. 'threes', test)
      call starttest(test)
      call Strings_Cstring_passeverywhere_f(obj,
     $     'Three', out, inout, sreturn, tae)
      call reporttest(sreturn .eq. 'Three' .and.
     $     out .eq. 'Three' .and. inout .eq. 'Three',
     $     test)
      call starttest(test)
      call Strings_Cstring_mixedarguments_f(obj, 'Test', 'z',
     $     'Test', 'z', retval, tae)
      call reporttest(retval, test)
      call starttest(test)
      call Strings_Cstring_mixedarguments_f(obj, 'Not', 'A',
     $     'Equal', 'a', retval, tae)
      call reporttest(.not. retval, test)
      ch1 = 'z'
      ch2 = 'z'
      call starttest(test)
      call Strings_Cstring_mixedarguments_f(obj, 'Test', ch1,
     $     'Test', ch1, retval, tae)
      call reporttest(retval, test)
      call starttest(test)
      call Strings_Cstring_mixedarguments_f(obj, 'Test', ch1,
     $     'Test', ch2, retval, tae)
      call reporttest(retval, test)
      ch2 = 'A'
      call starttest(test)
      call Strings_Cstring_mixedarguments_f(obj, 'Not', ch1,
     $     'Equal', ch2, retval, tae)
      call reporttest(.not. retval, test)
      call Strings_Cstring_deleteRef_f(obj, tae)

      end

      program stringstest
      integer*4 test
      integer*8 tracker, tae
      test = 1
      call synch_RegOut_getInstance_f(tracker, tae)
      call synch_RegOut_setExpectations_f(tracker, 12, tae)
      call synch_RegOut_writeComment_f(tracker,
     $     'String tests', tae)
      call teststring(test)
      call synch_RegOut_close_f(tracker, tae)
      call synch_RegOut_deleteRef_f(tracker, tae)
      end
