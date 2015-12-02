C       
C       File:          ExceptionTest_TooBigException_Impl.f
C       Symbol:        ExceptionTest.TooBigException-v1.0
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
C       Description:   Server-side implementation for ExceptionTest.TooBigException
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "ExceptionTest.TooBigException" (version 1.0)
C       
C       This exception is thrown if the Fibonacci number is too large.
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine ExceptionTest_TooBigException__ctor_fi(self, 
     &     exception)
        implicit none
C        in ExceptionTest.TooBigException self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine ExceptionTest_TooBigException__ctor2_fi(self, 
     &     private_data, exception)
        implicit none
C        in ExceptionTest.TooBigException self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor2)
C       Insert-Code-Here {ExceptionTest.TooBigException._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine ExceptionTest_TooBigException__dtor_fi(self, 
     &     exception)
        implicit none
C        in ExceptionTest.TooBigException self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._dtor)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine ExceptionTest_TooBigException__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._load)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
