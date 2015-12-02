C       
C       File:          sort_SortingAlgorithm_Impl.f
C       Symbol:        sort.SortingAlgorithm-v0.1
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
C       Description:   Server-side implementation for sort.SortingAlgorithm
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.SortingAlgorithm" (version 0.1)
C       
C       An abstract sorting algorithm.
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_SortingAlgorithm__ctor_fi(self, exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor)
        integer*8 data, count, scount, tae
        call sort_Counter__array_create1d_f(2, data)
        call sort_SimpleCounter__create_f(scount, tae)
        call sort_Counter__cast_f(scount, count, tae)
        call sort_Counter__array_set1_f(data, 0, count)
        call sort_Counter_deleteRef_f(count, tae)
        call sort_SimpleCounter_deleteRef_f(scount, tae)
        call sort_SimpleCounter__create_f(scount, tae)
        call sort_Counter__cast_f(scount, count, tae)
        call sort_Counter__array_set1_f(data, 1, count)
        call sort_Counter_deleteRef_f(count, tae)
        call sort_SimpleCounter_deleteRef_f(scount, tae)
        call sort_SortingAlgorithm__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_SortingAlgorithm__ctor2_fi(self, private_data, 
     &     exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._ctor2)
C       Insert-Code-Here {sort.SortingAlgorithm._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_SortingAlgorithm__dtor_fi(self, exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor)
        integer*8 data
        call sort_SortingAlgorithm__get_data_f(self, data)
        call sort_Counter__array_deleteRef_f(data)
        data = 0
        call sort_SortingAlgorithm__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_SortingAlgorithm__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load)
        end


C       
C       Method:  getCompareCounter[]
C       Return the comparison counter.
C       

        subroutine sort_SortingAlgorithm_getCompareCounter_fi(self, 
     &     retval, exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        out sort.Counter retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter)
        integer*8 data, counter
        call sort_SortingAlgorithm__get_data_f(self, data)
        retval = 0
        if (data .ne. 0) then
           call sort_Counter__array_get1_f(data, 0, retval)
        endif
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter)
        end


C       
C       Method:  getSwapCounter[]
C       Return the swap counter.
C       

        subroutine sort_SortingAlgorithm_getSwapCounter_fi(self, retval,
     &     exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        out sort.Counter retval
        integer*8 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter)
        integer*8 data, counter
        call sort_SortingAlgorithm__get_data_f(self, data)
        retval = 0
        if (data .ne. 0) then
           call sort_Counter__array_get1_f(data, 1, retval)
        endif
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter)
        end


C       
C       Method:  reset[]
C       Reset the comparison and swap counter.
C       

        subroutine sort_SortingAlgorithm_reset_fi(self, exception)
        implicit none
C        in sort.SortingAlgorithm self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset)
        integer*8 data, counter, tae
        integer*4 i
        call sort_SortingAlgorithm__get_data_f(self, data)
        if (data .ne. 0) then
           do i = 0, 1
              call sort_Counter__array_get1_f(data, i, counter)
              call sort_Counter_reset_f(counter, tae)
              call sort_Counter_deleteRef_f(counter, tae)
           enddo
        endif
C       DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
