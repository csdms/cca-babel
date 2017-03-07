C       
C       File:          sort_Integer_Impl.f
C       Symbol:        sort.Integer-v0.1
C       Symbol Type:   class
C       Babel Version: 2.0.0 (Revision: 7435  trunk)
C       Description:   Server-side implementation for sort.Integer
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.Integer" (version 0.1)
C       
C       An object to hold a simple integer.
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_Integer__ctor_fi(self, exception)
        implicit none
C        in sort.Integer self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer._ctor)
        integer*8 data
        integer*4 zero
        zero = 0
        call sidl_int__array_create1d_f(1, data)
        call sidl_int__array_set1_f(data, zero, zero)
        call sort_Integer__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.Integer._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_Integer__ctor2_fi(self, private_data, exception)
        implicit none
C        in sort.Integer self
        integer*8 :: self
C        in opaque private_data
        integer*8 :: private_data
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer._ctor2)
C       Insert-Code-Here {sort.Integer._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.Integer._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_Integer__dtor_fi(self, exception)
        implicit none
C        in sort.Integer self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer._dtor)
        integer*8 data
        call sort_Integer__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_deleteRef_f(data)
           data = 0
           call sort_Integer__set_data_f(self, data)
        endif
C       DO-NOT-DELETE splicer.end(sort.Integer._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_Integer__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.Integer._load)
        end


C       
C       Method:  getValue[]
C       

        subroutine sort_Integer_getValue_fi(self, retval, exception)
        implicit none
C        in sort.Integer self
        integer*8 :: self
C        out int retval
        integer*4 :: retval
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer.getValue)
        integer*8 data
        call sort_Integer__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_get1_f(data, 0, retval)
        endif
C       DO-NOT-DELETE splicer.end(sort.Integer.getValue)
        end


C       
C       Method:  setValue[]
C       

        subroutine sort_Integer_setValue_fi(self, value, exception)
        implicit none
C        in sort.Integer self
        integer*8 :: self
C        in int value
        integer*4 :: value
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.Integer.setValue)
        integer*8 data
        call sort_Integer__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_set1_f(data, 0, value)
        endif
C       DO-NOT-DELETE splicer.end(sort.Integer.setValue)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
