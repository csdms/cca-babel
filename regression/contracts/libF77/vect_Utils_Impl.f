C       
C       File:          vect_Utils_Impl.f
C       Symbol:        vect.Utils-v1.0
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
C       Description:   Server-side implementation for vect.Utils
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "vect.Utils" (version 1.0)
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
      subroutine getInfo(a, lowA, lenA)
      implicit none
      integer*8 a
      integer*4 dimA, lenA, lowA, upA

      if (a .ne. 0) then
         call sidl_double__array_dimen_f(a, dimA)
         if (dimA .eq. 1) then
            call sidl_double__array_lower_f(a, 0, lowA)
            call sidl_double__array_upper_f(a, 0, upA)
            lenA = (upA - lowA) + 1
         else
            lenA = -1
         endif
      else
         lenA = -1
      endif

      return
      end

      subroutine createArray(lenA, a)
      implicit none
      integer*4  lenA
      integer*8  a

      if (lenA .gt. 0) then
         call sidl_double__array_create1d_f(lenA, a)
      else 
         a = 0
      endif

      return
      end
 
      subroutine createMatrix(lenA, a)
      implicit none
      integer*4  lenA
      integer*8  a

      if (lenA .gt. 0) then
         call sidl_double__array_create2dCol_f(lenA, lenA, a)
      else 
         a = 0
      endif

      return
      end
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine vect_Utils__ctor_fi(self, exception)
        implicit none
C        in vect.Utils self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils._ctor)
C       Nothing needed here.
C       DO-NOT-DELETE splicer.end(vect.Utils._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine vect_Utils__ctor2_fi(self, private_data, exception)
        implicit none
C        in vect.Utils self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils._ctor2)
C       Nothing needed here.
C       DO-NOT-DELETE splicer.end(vect.Utils._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine vect_Utils__dtor_fi(self, exception)
        implicit none
C        in vect.Utils self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils._dtor)
C       Nothing needed here.
C       DO-NOT-DELETE splicer.end(vect.Utils._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine vect_Utils__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils._load)
C       Nothing needed here.
C       DO-NOT-DELETE splicer.end(vect.Utils._load)
        end


C       
C       Method:  vuIsZero[]
C       boolean result operations 
C       Return TRUE if the specified vector is the zero vector, within the
C       given tolerance level; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuIsZero_fi(u, tol, retval, exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuIsZero)
        integer*4        lowU, lenU, i
        double precision val

        call getInfo(u, lowU, lenU)
        if (lenU .gt. 0) then
           retval = .true.
           i = 0
           do while ( retval .and. (i .lt. lenU) )
              call sidl_double__array_get1_f(u, lowU+i, val)
              if (ABS(val) .gt. ABS(tol)) then
                 retval = .false.
              endif
              i = i + 1
           enddo
        else
           retval = .false.
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuIsZero)
        end


C       
C       Method:  vuIsUnit[]
C       Return TRUE if the specified vector is the unit vector, within the
C       given tolerance level; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuIsUnit_fi(u, tol, retval, exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuIsUnit)
        double precision val
        integer*8        throwaway_exception
        character*(*)    myfilename, myname
        parameter(myfilename='vect_Utils_Impl.f')
        parameter(myname='vect_Utils_vuIsUnit')

        if (u .ne. 0) then
           call vect_Utils_vuNorm_fi(u, tol, 0, val, exception)
           if (exception .eq. 0) then
              if (ABS(val - 1.0) .le. ABS(tol)) then
                 retval = .true.
              else
                 retval = .false.
              endif
           else
              retval = .false.
              call sidl_SIDLException_add_f(exception, myfilename,
     $                   223, myname, throwaway_exception)
              return
           endif
        else
           retval = .false.
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuIsUnit)
        end


C       
C       Method:  vuAreEqual[]
C       Return TRUE if the specified vectors are equal, within the given
C       tolerance level; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuAreEqual_fi(u, v, tol, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuAreEqual)
        integer*4        i, lenU, lenV, lowU, lowV
        double precision ui, vi

        if ( (u .ne. 0) .and. (v .ne. 0) ) then
           call getInfo(u, lowU, lenU)
           call getInfo(v, lowV, lenV)
           if ( (lenU .gt. 0) .and. (lenU .eq. lenV) ) then
              retval = .true.
              i = 0
              do while ( retval .and. (i .lt. lenU) ) 
                 call sidl_double__array_get1_f(u, lowU+i, ui)
                 call sidl_double__array_get1_f(v, lowV+i, vi)
                 if (ABS(ui - vi) .gt. ABS(tol)) then
                    retval = .false.
                 endif
                 i = i + 1
              enddo
           else
              retval = .false.
           endif
        else if ( (u .eq. 0) .and. (v .eq. 0) ) then
C          Is this even appropriate/valid?
           retval = .true.
        else 
           retval = .false.
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuAreEqual)
        end


C       
C       Method:  vuAreOrth[]
C       Return TRUE if the specified vectors are orthogonal, within the given
C       tolerance; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuAreOrth_fi(u, v, tol, retval, exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuAreOrth)
        double precision val
        integer*8        throwaway_exception
        character*(*)    myfilename, myname
        parameter(myfilename='vect_Utils_Impl.f')
        parameter(myname='vect_Utils_vuAreOrth')

        if ( (u .ne. 0) .and. (v .ne. 0) ) then
           call vect_Utils_vuDot_fi(u, v, tol, 0, val, exception)
           if (exception .eq. 0) then
              if (ABS(val) .le. ABS(tol)) then
                retval = .true.
              else
                retval = .false.
              endif
           else
              retval = .false.
              call sidl_SIDLException_add_f(exception, myfilename, 
     $                   329, myname, throwaway_exception)
              return
           endif
        else
           retval = .false.
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuAreOrth)
        end


C       
C       Method:  vuSchwarzHolds[]
C       Return TRUE if the Schwarz (or Cauchy-Schwarz) inequality holds, within
C       the given tolerance; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuSchwarzHolds_fi(u, v, tol, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuSchwarzHolds)
        double precision valDot, valNormU, valNormV, val
        integer*8        throwaway_exception
        character*(*)    myfilename, myname
        parameter(myfilename='vect_Utils_Impl.f')
        parameter(myname='vect_Utils_vuSchwarzHolds')

        if ( (u .ne. 0) .and. (v .ne. 0) ) then
           call vect_Utils_vuDot_fi(u, v, tol, 0, valDot, 
     $                                exception)
           if (exception .eq. 0) then
              call vect_Utils_vuNorm_fi(u, tol, 0, valNormU, 
     $                                    exception)
              if (exception .eq. 0) then
                 call vect_Utils_vuNorm_fi(v, tol, 0, valNormV, 
     $                                       exception)
                 if (exception .eq. 0) then
                    val = valNormU * valNormV
                    if (ABS(valDot) .le. ABS(val) + ABS(tol)) then
                      retval = .true.
                    else
                      retval = .false.
                    endif
                 else
                    retval = .false.
                    call sidl_SIDLException_add_f(exception, 
     $                         myfilename, 386, myname, 
     $                         throwaway_exception)
                    return
                 endif
              else
                 retval = .false.
                 call sidl_SIDLException_add_f(exception, myfilename, 
     $                      383, myname, throwaway_exception)
                 return
              endif
           else
              retval = .false.
              call sidl_SIDLException_add_f(exception, myfilename,
     $                   361, myname, throwaway_exception)
              return
           endif
        else
           retval = .false.
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuSchwarzHolds)
        end


C       
C       Method:  vuTriIneqHolds[]
C       Return TRUE if the Minkowski (or triangle) inequality holds, within the
C       given tolerance; otherwise, return FALSE.
C       

        subroutine vect_Utils_vuTriIneqHolds_fi(u, v, tol, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in double tol
        double precision tol
C        out bool retval
        logical retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuTriIneqHolds)
        double precision valSum, sumNorm, valNormU, valNormV, normTot
        integer*8        throwaway_exception, aSum
        character*(*)    myfilename, myname
        parameter(myfilename='vect_Utils_Impl.f')
        parameter(myname='vect_Utils_vuTriIneqHolds')

        aSum = 0
        if ( (u .ne. 0) .and. (v .ne. 0) ) then
           call vect_Utils_vuSum_fi(u, v, 0, aSum, exception)
           if (exception .eq. 0) then
              call vect_Utils_vuNorm_fi(aSum, tol, 0, sumNorm, 
     $                                    exception)
              if (exception .eq. 0) then
                 call vect_Utils_vuNorm_fi(u, tol, 0, valNormU, 
     $                                       exception)
                 if (exception .eq. 0) then
                    call vect_Utils_vuNorm_fi(v, tol, 0, valNormV, 
     $                                          exception)
                    if (exception .eq. 0) then
                       normTot = ABS(valNormU + valNormV) + ABS(tol)
                       if ( ABS(sumNorm) .le. ABS(normTot) ) then
                         retval = .true.
                       else
                         retval = .false.
                       endif
                    else
                       retval = .false.
                       call sidl_SIDLException_add_f(exception, 
     $                            myfilename, 458, myname, 
     $                            throwaway_exception)
                       return
                    endif
                 else
                    retval = .false.
                    call sidl_SIDLException_add_f(exception, myfilename,
     $                         455, myname, throwaway_exception)
                    return
                 endif
              else
                 retval = .false.
                 call sidl_SIDLException_add_f(exception, myfilename, 
     $                      452, myname, throwaway_exception)
                 return
              endif
           else
              retval = .false.
              call sidl_SIDLException_add_f(exception, myfilename,
     $                   450, myname, throwaway_exception)
              return
           endif
        else
           retval = .false.
        endif

        if (aSum .ne. 0) then 
           call sidl_double__array_deleteRef_f(aSum)
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuTriIneqHolds)
        end


C       
C       Method:  vuNorm[]
C       double result operations 
C       Return the norm (or length) of the specified vector.
C       
C       Note that the size exception is given here simply because the
C       implementation is leveraging the vuDot() method.  Also the tolerance
C       is included to enable the caller to specify the tolerance used in
C       contract checking.
C       
C       Also note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a negative result (regardless of input);
C       2 = Return a positive result not near zero (regardless of input), 
C       which means a violation will occur only if u is the zero
C       vector; and
C       3 = Return a zero result (regardless of input), which means a
C       violation will occur only if u is not the zero vector.
C       

        subroutine vect_Utils_vuNorm_fi(u, tol, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in double tol
        double precision tol
C        in int badLevel
        integer*4 badLevel
C        out double retval
        double precision retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuNorm)
        double precision valDot
        integer*8        throwaway_exception
        character*(*)    myfilename, myname, msg

        parameter(myfilename="vect_Utils_Impl.f")
        parameter(myname="vect_Utils_vuNorm")
        parameter(msg=
     $    "vuNorm: vNegValExcept: Cannot sqrt() a negative value.")

        if (badLevel .eq. 0) then
           if (u .ne. 0) then
              call vect_Utils_vuDot_fi(u, u, tol, 0, valDot, 
     $                                   exception)
              if (exception .eq. 0) then
                 if (valDot .gt. 0.0) then
                   retval = sqrt(valDot)
                 else if (valDot .eq. 0.0) then
                   retval = 0.0
                 else
C                  This should NEVER happen!
                   retval = -5.0
                   call vect_vNegValExcept__create_f(exception,
     $                           throwaway_exception)
                    if (exception .ne. 0) then
                      call vect_vNegValExcept_setNote_f(exception, 
     $                             msg, throwaway_exception)
                      call vect_vNegValExcept_add_f(exception, 
     $                             myfilename, 559, myname, 
     $                             throwaway_exception)
                      return
                    endif
                 endif
              else
                 retval = -5.0
                 call sidl_SIDLException_add_f(exception, myfilename,
     $                      550, myname, throwaway_exception)
                 return
              endif
           else 
              retval = 0.0
           endif 
        else if (badLevel .eq. 1) then
           retval = -5.0
        else if (badLevel .eq. 2) then
           retval = 5.0
        else if (badLevel .eq. 3) then
           retval = 0.0
        else 
           retval = -5.0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuNorm)
        end


C       
C       Method:  vuDot[]
C       Return the dot (, inner, or scalar) product of the specified vectors.
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a negative result (regardless of input); and
C       2 = Return a positive result not near zero (regardless of input), 
C       which means a violation will occur only if u and v are the zero
C       vector.
C       

        subroutine vect_Utils_vuDot_fi(u, v, tol, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in double tol
        double precision tol
C        in int badLevel
        integer*4 badLevel
C        out double retval
        double precision retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuDot)
        integer*4        i, lenU, lenV, lowU, lowV
        double precision ui, vi

        if (badLevel .eq. 0) then
           if ( (u .ne. 0) .and. (v .ne. 0) ) then
              call getInfo(u, lowU, lenU)
              call getInfo(v, lowV, lenV)
              if ( (lenU .gt. 0) .and. (lenU .eq. lenV) ) then
                 retval = 0.0
                 do i = 0, lenU - 1
                    call sidl_double__array_get1_f(u, lowU+i, ui)
                    call sidl_double__array_get1_f(v, lowV+i, vi)
                    retval = retval + (ui * vi)
                 enddo
              else
                 retval = 0.0
              endif
           else
              retval = 0.0
           endif
        else if (badLevel .eq. 1) then
           retval = -5.0
        else if (badLevel .eq. 2) then
           retval = 5.0
        else
           retval = -1.0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuDot)
        end


C       
C       Method:  vuProduct[]
C       vector result operations 
C       Return the (scalar) product of the specified vector.
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a null result (regardless of input);
C       2 = Return a 2D array result (regardless of input); and
C       3 = Return an array of a different size (regardless of input).
C       

        subroutine vect_Utils_vuProduct_fi(a, u, badLevel, retval, 
     &     exception)
        implicit none
C        in double a
        double precision a
C        in array<double> u
        integer*8 u
C        in int badLevel
        integer*4 badLevel
C        out array<double> retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuProduct)
        integer*4        i, lenU, lowU
        double precision val

        call getInfo(u, lowU, lenU)
        if (badLevel .eq. 0) then
           if (lenU .gt. 0) then
              call createArray(lenU, retval)
              if (retval .ne. 0) then
                 do i = 0, lenU - 1
                    call sidl_double__array_get1_f(u, lowU+i, val)
                    call sidl_double__array_set1_f(retval, i, a * val)
                 enddo
              else
                 retval = 0
              endif
           else
              retval = 0
           endif
        else if (badLevel .eq. 1) then
           retval = 0
        else if (badLevel .eq. 2) then
           call createMatrix(lenU, retval)
        else if (badLevel .eq. 3) then
           call createArray(lenU+5, retval)
        else 
           retval = 0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuProduct)
        end


C       
C       Method:  vuNegate[]
C       Return the negation of the specified vector.
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a null result (regardless of input);
C       2 = Return a 2D array result (regardless of input); and
C       3 = Return an array of a different size (regardless of input).
C       

        subroutine vect_Utils_vuNegate_fi(u, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in int badLevel
        integer*4 badLevel
C        out array<double> retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuNegate)
        integer*4        i, lenU, lowU
        integer*8        throwaway_exception
        double precision a
        character*(*)    myfilename, myname
        parameter(myfilename='vect_Utils_Impl.f')
        parameter(myname='vect_Utils_vuNegate')

        a = -1.0
        call getInfo(u, lowU, lenU)
        if (badLevel .eq. 0) then
           if (lenU .gt. 0) then
              call vect_Utils_vuProduct_fi(a, u, 0, retval,
     $                                       exception)
              if (exception .ne. 0) then
                 retval = 0
                 call sidl_SIDLException_add_f(exception, myfilename,
     $                      759, myname, throwaway_exception)
                 return
              endif
           else
              retval = 0
           endif
        else if (badLevel .eq. 1) then
           retval = 0
        else if (badLevel .eq. 2) then
           call createMatrix(lenU, retval)
        else if (badLevel .eq. 3) then
           call createArray(lenU+5, retval)
        else 
           retval = 0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuNegate)
        end


C       
C       Method:  vuNormalize[]
C       Return the normalizaton of the specified vector.
C       
C       Note the tolerance is included because the implementation invokes 
C       vuDot().
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a null result (regardless of input);
C       2 = Return a 2D array result (regardless of input); and
C       3 = Return an array of a different size (regardless of input).
C       

        subroutine vect_Utils_vuNormalize_fi(u, tol, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in double tol
        double precision tol
C        in int badLevel
        integer*4 badLevel
C        out array<double> retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuNormalize)
        integer*4        i, lenU, lowU
        integer*8        throwaway_exception
        double precision valNorm
        character*(*)    myfilename, myname, msg

        parameter(myfilename="vect_Utils_Impl.f")
        parameter(myname="vect_Utils_vuNormalize")
        parameter(msg=
     $      "vuNormalize: vDivByZeroExcept: Cannot divide by zero.")

        call getInfo(u, lowU, lenU)
        if (badLevel .eq. 0) then
           if (lenU .gt. 0) then
              call vect_Utils_vuNorm_fi(u, tol, 0, valNorm,
     $                                    exception)
              if (exception .eq. 0) then
                 if (valNorm .ne. 0.0) then
                    call vect_Utils_vuProduct_fi(1.0/valNorm, u, 0,
     $                                             retval, exception)
                    if (exception .ne. 0) then
                       retval = 0
                       call sidl_SIDLException_add_f(exception,
     $                            myfilename, 832, myname,
     $                            throwaway_exception)
                       return
                    endif
                 else
                    retval = 0
                    call vect_vDivByZeroExcept__create_f(exception, 
     $                                        throwaway_exception)
                    if (exception .ne. 0) then
                       call vect_vDivByZeroExcept_setNote_f(
     $                              exception, msg, throwaway_exception)
                       call vect_vDivByZeroExcept_add_f(
     $                              exception, myfilename, 843, myname,
     $                              throwaway_exception)
                       return
                    endif
                 endif
              else
                 retval = 0
                 call sidl_SIDLException_add_f(exception, myfilename,
     $                      828, myname, throwaway_exception)
                 return
              endif
           else
              retval = 0
           endif
        else if (badLevel .eq. 1) then
           retval = 0
        else if (badLevel .eq. 2) then
           call createMatrix(lenU, retval)
        else if (badLevel .eq. 3) then
           call createArray(lenU+5, retval)
        else 
           retval = 0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuNormalize)
        end


C       
C       Method:  vuSum[]
C       Return the sum of the specified vectors.
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a null result (regardless of input);
C       2 = Return a 2D array result (regardless of input); and
C       3 = Return an array of a different size (regardless of input).
C       

        subroutine vect_Utils_vuSum_fi(u, v, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in int badLevel
        integer*4 badLevel
C        out array<double> retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuSum)
        integer*4        i, lenU, lenV, lowU, lowV
        double precision ui, vi

        call getInfo(u, lowU, lenU)
        if (badLevel .eq. 0) then
           call getInfo(v, lowV, lenV)
           if ( (lenU .gt. 0) .and. (lenU .eq. lenV) ) then
              call createArray(lenU, retVal)
              if (retval .ne. 0) then
                 do i = 0, lenU - 1
                    call sidl_double__array_get1_f(u, lowU+i, ui)
                    call sidl_double__array_get1_f(v, lowV+i, vi)
                    call sidl_double__array_set1_f(retval, i, ui + vi)
                 enddo
              endif
           else
              retval = 0
           endif
        else if (badLevel .eq. 1) then
           retval = 0
        else if (badLevel .eq. 2) then
           call createMatrix(lenU, retval)
        else if (badLevel .eq. 3) then
           call createArray(lenU+5, retval)
        else 
           retval = 0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuSum)
        end


C       
C       Method:  vuDiff[]
C       Return the difference of the specified vectors.
C       
C       Note that badLevel has been added only to facilitate regression
C       testing of postconditions.  The levels are:
C       0 = NONE  (i.e., no deliberate postcondition violation);
C       1 = Return a null result (regardless of input);
C       2 = Return a 2D array result (regardless of input); and
C       3 = Return an array of a different size (regardless of input).
C       

        subroutine vect_Utils_vuDiff_fi(u, v, badLevel, retval, 
     &     exception)
        implicit none
C        in array<double> u
        integer*8 u
C        in array<double> v
        integer*8 v
C        in int badLevel
        integer*4 badLevel
C        out array<double> retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(vect.Utils.vuDiff)
        integer*4        i, lenU, lenV, lowU, lowV
        double precision ui, vi

        call getInfo(u, lowU, lenU)
        if (badLevel .eq. 0) then
           call getInfo(v, lowV, lenV)
           if ( (lenU .gt. 0) .and. (lenU .eq. lenV) ) then
              call createArray(lenU, retval)
              if (retval .ne. 0) then
                 do i = 0, lenU - 1
                    call sidl_double__array_get1_f(u, lowU+i, ui)
                    call sidl_double__array_get1_f(v, lowV+i, vi)
                    call sidl_double__array_set1_f(retval, i, ui - vi)
                 enddo
              endif
           else
              retval = 0
           endif
        else if (badLevel .eq. 1) then
           retval = 0
        else if (badLevel .eq. 2) then
           call createMatrix(lenU, retval)
        else if (badLevel .eq. 3) then
           call createArray(lenU+5, retval)
        else 
           retval = 0
        endif

        return
C       DO-NOT-DELETE splicer.end(vect.Utils.vuDiff)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       insert code here (extra code)
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
