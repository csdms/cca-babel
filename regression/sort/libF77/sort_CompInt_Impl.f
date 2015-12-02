C       
C       File:          sort_CompInt_Impl.f
C       Symbol:        sort.CompInt-v0.1
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
C       Description:   Server-side implementation for sort.CompInt
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.CompInt" (version 0.1)
C       
C       Compare two Integer's.  By default, this will sort in increasing order.
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_CompInt__ctor_fi(self, exception)
        implicit none
C        in sort.CompInt self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt._ctor)
C       a data pointer equal to self means true
C       a data pointer equal to 0 means false
        call sort_CompInt__set_data_f(self, self)
C       DO-NOT-DELETE splicer.end(sort.CompInt._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_CompInt__ctor2_fi(self, private_data, exception)
        implicit none
C        in sort.CompInt self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt._ctor2)
C       Insert-Code-Here {sort.CompInt._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.CompInt._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_CompInt__dtor_fi(self, exception)
        implicit none
C        in sort.CompInt self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt._dtor)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.CompInt._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_CompInt__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.CompInt._load)
        end


C       
C       Method:  setSortIncreasing[]
C       If increasing is true, this will cause the comparator to
C       report a normal definition of less than; otherwise, it will
C       reverse the normal ordering.
C       

        subroutine sort_CompInt_setSortIncreasing_fi(self, increasing, 
     &     exception)
        implicit none
C        in sort.CompInt self
        integer*8 self
C        in bool increasing
        logical increasing
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt.setSortIncreasing)
        integer*8 data
        if (increasing) then
           data = self
        else
           data = 0
        endif
        call sort_CompInt__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.CompInt.setSortIncreasing)
        end


C       
C       Method:  compare[]
C       This method is used to define an ordering of objects.  This method
C       will return -1 if i1 < i2, 0 if i1 = i2; and 1 if i1 > i2.
C       

        subroutine sort_CompInt_compare_fi(self, i1, i2, retval, 
     &     exception)
        implicit none
C        in sort.CompInt self
        integer*8 self
C        in sidl.BaseInterface i1
        integer*8 i1
C        in sidl.BaseInterface i2
        integer*8 i2
C        out int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.CompInt.compare)
        integer*8 int1, int2, data, tae
        integer*4 val1, val2
        logical increasing
        retval = 0
        call sort_CompInt__get_data_f(self, data)
        increasing = (data .eq. self)
        call sort_Integer__cast_f(i1, int1, tae)
        call sort_Integer__cast_f(i2, int2, tae)
        if ((int1 .ne. 0) .and. (int2 .ne. 0)) then
           call sort_Integer_getValue_f(int1, val1, tae)
           call sort_Integer_getValue_f(int2, val2, tae)
           if (val1 .lt. val2)  then
              retval = -1
           endif
           if (val1 .gt. val2) then
              retval = 1
           endif
           if (.not. increasing) then
              retval = -retval
           endif
        endif
        if (int1 .ne. 0) then
           call sort_Integer_deleteRef_f(int1, tae)
        endif
        if (int2 .ne. 0) then
           call sort_Integer_deleteRef_f(int2, tae)
        endif
C       DO-NOT-DELETE splicer.end(sort.CompInt.compare)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
