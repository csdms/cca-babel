C       
C       File:          Inherit_H_Impl.f
C       Symbol:        Inherit.H-v1.1
C       Symbol Type:   class
C       Babel Version: 2.0.0 (Revision: 7435  trunk)
C       Description:   Server-side implementation for Inherit.H
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "Inherit.H" (version 1.1)
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine Inherit_H__ctor_fi(self, exception)
        implicit none
C        in Inherit.H self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(Inherit.H._ctor)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(Inherit.H._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine Inherit_H__ctor2_fi(self, private_data, exception)
        implicit none
C        in Inherit.H self
        integer*8 :: self
C        in opaque private_data
        integer*8 :: private_data
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(Inherit.H._ctor2)
C       Insert-Code-Here {Inherit.H._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(Inherit.H._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine Inherit_H__dtor_fi(self, exception)
        implicit none
C        in Inherit.H self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(Inherit.H._dtor)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(Inherit.H._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine Inherit_H__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(Inherit.H._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(Inherit.H._load)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
