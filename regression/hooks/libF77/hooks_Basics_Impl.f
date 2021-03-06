C       
C       File:          hooks_Basics_Impl.f
C       Symbol:        hooks.Basics-v1.0
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6585 release-1-4-0-branch)
C       Description:   Server-side implementation for hooks.Basics
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "hooks.Basics" (version 1.0)
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert-Code-Here {_miscellaneous_code_start} (extra code)
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine hooks_Basics__ctor_fi(self, exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics._ctor)
C       DO-NOT-DELETE splicer.end(hooks.Basics._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine hooks_Basics__ctor2_fi(self, private_data, exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics._ctor2)
C       DO-NOT-DELETE splicer.end(hooks.Basics._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine hooks_Basics__dtor_fi(self, exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics._dtor)
C       DO-NOT-DELETE splicer.end(hooks.Basics._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine hooks_Basics__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics._load)
C       DO-NOT-DELETE splicer.end(hooks.Basics._load)
        end


C       
C       Method:  aStaticMeth_pre[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aStaticMeth_pre_fi(i, io, exception)
        implicit none
C        in int i
        integer*4 i
C        in int io
        integer*4 io
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth_pre)
        integer*8 tracker, throwaway
        call synch_RegOut_getInstance_f(tracker, throwaway)
        call synch_RegOut_startPart_f(tracker, 1, throwaway)
        call synch_RegOut_deleteRef_f(tracker, throwaway)
C       DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth_pre)
        end


C       
C       Method:  aStaticMeth[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aStaticMeth_fi(i, o, io, retval, 
     &     exception)
        implicit none
C        in int i
        integer*4 i
C        out int o
        integer*4 o
C        inout int io
        integer*4 io
C        out int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth)
        retval = 1
        o = 0
C       DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth)
        end


C       
C       Method:  aStaticMeth_post[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aStaticMeth_post_fi(i, o, io, retval, 
     &     exception)
        implicit none
C        in int i
        integer*4 i
C        in int o
        integer*4 o
C        in int io
        integer*4 io
C        in int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth_post)
        integer*8 tracker, throwaway
        integer*4 probnum
        include 'synch_ResultType.inc'
        call synch_RegOut_getInstance_f(tracker, throwaway)
        probnum = 1
        call synch_RegOut_endPart_f(tracker, probnum, PASS,
     $       throwaway)
        call synch_RegOut_deleteRef_f(tracker, throwaway)
        return
C       DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth_post)
        end


C       
C       Method:  aNonStaticMeth_pre[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aNonStaticMeth_pre_fi(self, i, io, 
     &     exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        in int i
        integer*4 i
C        in int io
        integer*4 io
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth_pre)
        integer*8 tracker, throwaway        
        call synch_RegOut_getInstance_f(tracker, throwaway)
        call synch_RegOut_startPart_f(tracker, 2, throwaway)
        call synch_RegOut_deleteRef_f(tracker, throwaway)
C       DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth_pre)
        end


C       
C       Method:  aNonStaticMeth[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aNonStaticMeth_fi(self, i, o, io, 
     &     retval, exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        in int i
        integer*4 i
C        out int o
        integer*4 o
C        inout int io
        integer*4 io
C        out int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth)
        retval = 1
        o = 0
C       DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth)
        end


C       
C       Method:  aNonStaticMeth_post[]
C       Basic illustration of hooks for static methods.
C       

        subroutine hooks_Basics_aNonStaticMeth_post_fi(self, i, o, io, 
     &     retval, exception)
        implicit none
C        in hooks.Basics self
        integer*8 self
C        in int i
        integer*4 i
C        in int o
        integer*4 o
C        in int io
        integer*4 io
C        in int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth_post)
        integer*8 tracker, throwaway
        integer*4 probnum
        include 'synch_ResultType.inc'
        probnum = 2
        call synch_RegOut_getInstance_f(tracker, throwaway)
        call synch_RegOut_endPart_f(tracker, probnum, PASS,
     $       throwaway)
        call synch_RegOut_deleteRef_f(tracker, throwaway)
        return
C       DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth_post)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert-Code-Here {_miscellaneous_code_end} (extra code)
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
