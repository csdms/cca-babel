c
c     File:       hookstest.f
c     Copyright:  (c) 2001 Lawrence Livermore National Security, LLC
c     Revision:   @(#) $Revision: 5006 $
c     Date:       $Date: 2005-11-01 15:20:38 -0800 (Tue, 01 Nov 2005) $
c     Description:Exercise the FORTRAN interface
c
c
      subroutine starttest(number)
      implicit none
      integer*4 number
      integer*8 tracker, throwaway
      call synch_RegOut_getInstance_f(tracker, throwaway)
      call synch_RegOut_startPart_f(tracker, number, throwaway)
      call synch_RegOut_deleteRef_f(tracker, throwaway)
      end

      subroutine reporttest(test, number,  python)
      implicit none
      integer*4 number
      integer*8 tracker, throwaway
      logical test, python
      include 'synch_ResultType.inc'
      call synch_RegOut_getInstance_f(tracker, throwaway)
      if (test) then
         call synch_RegOut_endPart_f(tracker, number, PASS,
     $        throwaway)
      else
         if (python) then
            call synch_RegOut_endPart_f(tracker, number, XFAIL,
     $           throwaway)
         else
            call synch_RegOut_endPart_f(tracker, number, FAIL,
     $           throwaway)
         endif
      endif
      call synch_RegOut_deleteRef_f(tracker, throwaway)
      number = number + 1
      end

      subroutine testhooks(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test, a, b, c, ret
      logical   boolval
      
      boolval = .true.
      call hooks_Basics__set_hooks_static_f(boolval,throwaway)

      call hooks_Basics__create_f(obj,throwaway)
      call hooks_Basics__set_hooks_f(obj,boolval,throwaway)
      test = 1
      b = 0
      c = 0 
      ret = 0

      call hooks_Basics_aStaticMeth_f(test,b,c,ret,throwaway)

      test = test + 1
      b = 0 
      c = 0
      ret = 0
      call hooks_Basics_aNonStaticMeth_f(obj, test,b,c,ret,throwaway)

      call hooks_Basics_deleteRef_f(obj,throwaway)
      end


      program hookstest
      integer*4 test
      integer*8 tracker, throwaway
      character*80 language
      language = ' '
      call synch_RegOut_getInstance_f(tracker, throwaway)
      call synch_RegOut_setExpectations_f(tracker, 2, throwaway)
      call synch_RegOut_writeComment_f(tracker,
     $     'Make sure hooks work', throwaway)
      call testhooks(test)
      call synch_RegOut_close_f(tracker, throwaway)
      call synch_RegOut_deleteRef_f(tracker,throwaway)
      end
