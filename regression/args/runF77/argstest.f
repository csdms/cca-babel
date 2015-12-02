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

      subroutine testbool(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical out, inout, retval
      
      inout = .true.
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackbool_f(obj, retval,throwaway)
      call reporttest(retval, test, .false.)
      call starttest(test)
      call Args_Basic_passinbool_f(obj, .true., retval,throwaway)
      call reporttest(retval, test, .false.)
      call starttest(test)
      call Args_Basic_passoutbool_f(obj, out, retval,throwaway)
      call reporttest(retval .and. out, test,
     $     .false.)
      call starttest(test)
      call Args_Basic_passinoutbool_f(obj, inout, retval,throwaway)
      call reporttest(retval .and. .not. inout, test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywherebool_f(obj, .true.,
     $     out, inout, retval,throwaway)
      call reporttest(retval .and. out .and. inout, test,
     $      .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testint(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval
      integer*4 iretval, out, inout
      
      inout = 3
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackint_f(obj, iretval,throwaway)
      call reporttest(iretval .eq. 3, test,
     $     .false.)
      call starttest(test)
      call Args_Basic_passinint_f(obj, 3, bretval,throwaway)
      call reporttest(bretval, test,
     $    .false.)
      call starttest(test)
      call Args_Basic_passoutint_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. 3), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutint_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. -3), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywhereint_f(obj, 3,
     $     out, inout, iretval,throwaway)
      call reporttest((iretval .eq. 3) .and.
     $     (out .eq. 3) .and.
     $     (inout .eq. 3), test, .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testchar(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval
      character cretval, out, inout
      
      inout = 'A'
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackchar_f(obj, cretval,throwaway)
      call reporttest(cretval .eq. '3', test, 
     $      .false.)
      call starttest(test)
      call Args_Basic_passinchar_f(obj, '3', bretval,throwaway)
      call reporttest(bretval, test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passoutchar_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. '3'), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutchar_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. 'a'), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywherechar_f(obj, '3',
     $     out, inout, cretval,throwaway)
      call reporttest((cretval .eq. '3') .and.
     $     (out .eq. '3') .and.
     $     (inout .eq. 'A'), test, .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testlong(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval
      integer*8 out, inout, iretval, inval
      
      inout = 3
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbacklong_f(obj, iretval,throwaway)
      call reporttest(iretval .eq. 3, test,
     $      .false.)
      call starttest(test)
      inval = 3
      call Args_Basic_passinlong_f(obj, inval, bretval,throwaway)
      call reporttest(bretval, test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passoutlong_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. 3), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutlong_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. -3), test,
     $      .false.)
      call starttest(test)
      inval = 3
      call Args_Basic_passeverywherelong_f(obj, inval,
     $     out, inout, iretval,throwaway)
      call reporttest((iretval .eq. 3) .and.
     $     (out .eq. 3) .and.
     $     (inout .eq. 3), test,  .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testfloat(test, python)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval, python
      real out, inout, fretval
      
      inout = 3.1
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackfloat_f(obj, fretval,throwaway)
      call reporttest(fretval .eq. 3.1, test, .false.)
      call starttest(test)
      call Args_Basic_passinfloat_f(obj, 3.1, bretval,throwaway)
      call reporttest(bretval, test, python)
      call starttest(test)
      call Args_Basic_passoutfloat_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. 3.1), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutfloat_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. -3.1), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywherefloat_f(obj, 3.1,
     $     out, inout, fretval,throwaway)
      call reporttest((fretval .eq. 3.1) .and.
     $     (out .eq. 3.1) .and.
     $     (inout .eq. 3.1), test,
     $      python)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testdouble(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval
      double precision out, inout, dretval
      
      inout = 3.14d0
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackdouble_f(obj, dretval,throwaway)
      call reporttest(dretval .eq. 3.14d0, test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passindouble_f(obj, 3.14d0, bretval,throwaway)
      call reporttest(bretval, test,
     $     .false.)
      call starttest(test)
      call Args_Basic_passoutdouble_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. 3.14d0), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutdouble_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. -3.14d0), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywheredouble_f(obj, 3.14d0,
     $     out, inout, dretval,throwaway)
      call reporttest((dretval .eq. 3.14d0) .and.
     $     (out .eq. 3.14d0) .and.
     $     (inout .eq. 3.14d0), test,
     $     .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testfcomplex(test, python)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval, python
      complex in, out, inout, cretval
      
      in = (3.1,3.1)
      inout = (3.1, 3.1)
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackfcomplex_f(obj, cretval,throwaway)
      call reporttest(cretval .eq. (3.1,3.1), test,
     $     .false.)
      call starttest(test)
      call Args_Basic_passinfcomplex_f(obj, in, bretval,throwaway)
      call reporttest(bretval, test,  python)
      call starttest(test)
      call Args_Basic_passoutfcomplex_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. (3.1,3.1)), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passinoutfcomplex_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. (3.1,-3.1)), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passeverywherefcomplex_f(obj, in,
     $     out, inout, cretval,throwaway)
      call reporttest((cretval .eq. (3.1,3.1)) .and.
     $     (out .eq. (3.1,3.1)) .and.
     $     (inout .eq. (3.1,3.1)), test,
     $    python)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end

      subroutine testdcomplex(test)
      implicit none
      integer*8 obj
      integer*8 throwaway
      integer*4 test
      logical bretval
      double complex in, out, inout, cretval
      
      in = (3.14d0,3.14d0)
      inout = (3.14d0, 3.14d0)
      call Args_Basic__create_f(obj,throwaway)
      call starttest(test)
      call Args_Basic_returnbackdcomplex_f(obj, cretval,throwaway)
      call reporttest(cretval .eq. (3.14d0,3.14d0), test,
     $      .false.)
      call starttest(test)
      call Args_Basic_passindcomplex_f(obj, in, bretval,throwaway)
      call reporttest(bretval, test,
     $    .false.)
      call starttest(test)
      call Args_Basic_passoutdcomplex_f(obj, out, bretval,throwaway)
      call reporttest(bretval .and. (out .eq. (3.14d0,3.14d0)),
     $     test,  .false.)
      call starttest(test)
      call Args_Basic_passinoutdcomplex_f(obj, inout, bretval,throwaway)
      call reporttest(bretval .and. (inout .eq. (3.14d0,-3.14d0)),
     $     test,  .false.)
      call starttest(test)
      call Args_Basic_passeverywheredcomplex_f(obj, in,
     $     out, inout, cretval,throwaway)
      call reporttest((cretval .eq. (3.14d0,3.14d0)) .and.
     $     (out .eq. (3.14d0,3.14d0)) .and.
     $     (inout .eq. (3.14d0,3.14d0)), test,
     $   .false.)
      call Args_Basic_deleteRef_f(obj,throwaway)
      end


      program argstest
      integer*4 test
      integer*8 tracker, throwaway
      character*80 language
      language = ' '
      if (IArgc() .eq. 1) then
         callGetArg(1, language)
      endif
      test = 1
      call synch_RegOut_getInstance_f(tracker, throwaway)
      call synch_RegOut_setExpectations_f(tracker, 40, throwaway)
      call synch_RegOut_writeComment_f(tracker,
     $     'Boolean tests', throwaway)
      call testbool(test)
      call synch_RegOut_writeComment_f(tracker, 'Character tests',
     $     throwaway)
      call testchar(test)
      call synch_RegOut_writeComment_f(tracker, 'Integer tests',
     $     throwaway)
      call testint(test)
      call synch_RegOut_writeComment_f(tracker, 'Long tests',
     $     throwaway)
      call testlong(test)
      call synch_RegOut_writeComment_f(tracker, 'Float tests',
     $     throwaway)
      call testfloat(test, 
     $     language .eq. 'Python')
      call synch_RegOut_writeComment_f(tracker, 'Double tests',
     $     throwaway)
      call testdouble(test)
      call synch_RegOut_writeComment_f(tracker, 'Fcomplex tests',
     $     throwaway)
      call testfcomplex(test, 
     $     language .eq. 'Python')
      call synch_RegOut_writeComment_f(tracker, 'Dcomplex tests',
     $     throwaway)
      call testDcomplex(test)
      call synch_RegOut_close_f(tracker, throwaway)
      call synch_RegOut_deleteRef_f(tracker,throwaway)
      end
