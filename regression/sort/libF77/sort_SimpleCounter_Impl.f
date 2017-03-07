C       
C       File:          sort_SimpleCounter_Impl.f
C       Symbol:        sort.SimpleCounter-v0.1
C       Symbol Type:   class
C       Babel Version: 2.0.0 (Revision: 7435  trunk)
C       Description:   Server-side implementation for sort.SimpleCounter
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.SimpleCounter" (version 0.1)
C       
C       Simple counter
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_SimpleCounter__ctor_fi(self, exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor)
        integer*8 data
        integer*4 count
        call sidl_int__array_create1d_f(1, data)
        count = 0
        call sidl_int__array_set1_f(data, 0, count)
        call sort_SimpleCounter__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_SimpleCounter__ctor2_fi(self, private_data, 
     &     exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        in opaque private_data
        integer*8 :: private_data
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter._ctor2)
C       Insert-Code-Here {sort.SimpleCounter._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_SimpleCounter__dtor_fi(self, exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor)
        integer*8 data
        call sort_SimpleCounter__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_deleteRef_f(data)
           data = 0
           call sort_SimpleCounter__set_data_f(self, data)
        endif
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_SimpleCounter__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter._load)
        end


C       
C       Method:  reset[]
C       Set the count to zero.
C       

        subroutine sort_SimpleCounter_reset_fi(self, exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset)
        integer*8 data
        Integer*4 zero
        call sort_SimpleCounter__get_data_f(self, data)
        if (data .ne. 0) then
           zero = 0
           call sidl_int__array_set1_f(data, 0, zero)
        endif
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset)
        end


C       
C       Method:  getCount[]
C       Return the current count.
C       

        subroutine sort_SimpleCounter_getCount_fi(self, retval, 
     &     exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        out int retval
        integer*4 :: retval
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount)
        integer*8 data
        retval = 0
        call sort_SimpleCounter__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_get1_f(data, 0, retval)
        endif
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount)
        end


C       
C       Method:  inc[]
C       Increment the count (i.e. add one).
C       

        subroutine sort_SimpleCounter_inc_fi(self, retval, exception)
        implicit none
C        in sort.SimpleCounter self
        integer*8 :: self
C        out int retval
        integer*4 :: retval
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc)
        integer*8 data
        retval = 0
        call sort_SimpleCounter__get_data_f(self, data)
        if (data .ne. 0) then
           call sidl_int__array_get1_f(data, 0, retval)
           retval = retval + 1
           call sidl_int__array_set1_f(data, 0, retval)
        endif
C       DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
