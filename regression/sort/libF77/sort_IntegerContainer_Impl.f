C       
C       File:          sort_IntegerContainer_Impl.f
C       Symbol:        sort.IntegerContainer-v0.1
C       Symbol Type:   class
C       Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
C       Description:   Server-side implementation for sort.IntegerContainer
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.IntegerContainer" (version 0.1)
C       
C       Integer container.
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_IntegerContainer__ctor_fi(self, exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor)
        integer*8 data
        data = 0
        call sort_IntegerContainer__set_data_f(self, data)
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_IntegerContainer__ctor2_fi(self, private_data, 
     &     exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        in opaque private_data
        integer*8 private_data
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer._ctor2)
C       Insert-Code-Here {sort.IntegerContainer._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_IntegerContainer__dtor_fi(self, exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer._dtor)
        integer*8 data
        call sort_IntegerContainer__get_data_f(self, data)
        if (data .ne. 0) then
           call sort_Integer__array_deleteRef_f(data)
           data = 0
           call sort_IntegerContainer__set_data_f(self, data)
        endif
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_IntegerContainer__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer._load)
        end


C       
C       Method:  setLength[]
C       This sets the container length and pseudo-randomly orders the
C       Integer elements contained.
C       

        subroutine sort_IntegerContainer_setLength_fi(self, len, 
     &     exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        in int len
        integer*4 len
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer.setLength)
        integer*8 data, intobj, tae
        integer*4 i
        if (len .ge. 0) then
           call sort_IntegerContainer__get_data_f(self, data)
           call sort_Integer__array_deleteRef_f(data)
           call sort_Integer__array_create1d_f(len, data)
           do i = 0, len - 1
              call sort_Integer__create_f(intobj, tae)
              call sort_Integer_setValue_f(intobj, i + 1, tae)
              if (mod(i,2) .eq. 0) then
                 call sort_Integer__array_set1_f(data, i/2, intobj)
              else
                 call sort_Integer__array_set1_f(data,
     $                len - 1 - i/2, intobj)
              endif
              call sort_Integer_deleteRef_f(intobj, tae)
           enddo
C     don't shuffle the list because no standard random number generator
           call sort_IntegerContainer__set_data_f(self, data)
        endif
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer.setLength)
        end


C       
C       Method:  getLength[]
C       Return the number of elements in the container.
C       

        subroutine sort_IntegerContainer_getLength_fi(self, retval, 
     &     exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        out int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer.getLength)
        integer*8 data
        integer*4 lower, upper
        integer*4 zero
        data zero / 0 /
        call sort_IntegerContainer__get_data_f(self, data)
        retval = 0
        if (data .ne. 0) then
           call sort_Integer__array_lower_f(data, zero, lower)
           call sort_Integer__array_upper_f(data, zero, upper)
           retval = 1 + upper - lower
        endif
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer.getLength)
        end


C       
C       Method:  compare[]
C       Return -1 if element i is less than element j, 0 if element i
C       is equal to element j, or otherwise 1.
C       

        subroutine sort_IntegerContainer_compare_fi(self, i, j, comp, 
     &     retval, exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        in int i
        integer*4 i
C        in int j
        integer*4 j
C        in sort.Comparator comp
        integer*8 comp
C        out int retval
        integer*4 retval
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer.compare)
        integer*8 i1, i2, data, tae
        call sort_IntegerContainer__get_data_f(self, data)
        if (data .ne. 0) then
           call sort_Integer__array_get1_f(data, i, i1)
           call sort_Integer__array_get1_f(data, j, i2)
           call sort_Comparator_compare_f(comp, i1, i2, retval, tae)
           call sort_Integer_deleteRef_f(i1, tae)
           call sort_Integer_deleteRef_f(i2, tae)
        endif
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer.compare)
        end


C       
C       Method:  swap[]
C       Swap elements i and j.
C       

        subroutine sort_IntegerContainer_swap_fi(self, i, j, exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        in int i
        integer*4 i
C        in int j
        integer*4 j
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer.swap)
        integer*8 data, i1, i2, tae
        integer*8 tracker
        integer*4 len
        call sort_IntegerContainer__get_data_f(self, data)
        if (data .ne. 0) then
           call sort_IntegerContainer_getLength_f(self, len, tae)
           if ((i .ge. 0) .and. (j .ge. 0) .and.
     $          (i .lt. len) .and. (j .lt. len)) then
              call sort_Integer__array_get1_f(data, i, i1)
              call sort_Integer__array_get1_f(data, j, i2)
              call sort_Integer__array_set1_f(data, i, i2)
              call sort_Integer__array_set1_f(data, j, i1)
              call sort_Integer_deleteRef_f(i1, tae)
              call sort_Integer_deleteRef_f(i2, tae)
           else
              call synch_RegOut_getInstance_f(tracker, tae)
              call synch_RegOut_writeComment_f(tracker,
     $             'sort::IntegerContainer::swap index out of bounds'
     $             , tae)
              call synch_RegOut_forceFailure_f(tracker, tae)
              call synch_RegOut_deleteRef_f(tracker, tae)
           endif
        endif
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer.swap)
        end


C       
C       Method:  output[]
C       Print elements s through e-1
C       

        subroutine sort_IntegerContainer_output_fi(self, s, e, 
     &     exception)
        implicit none
C        in sort.IntegerContainer self
        integer*8 self
C        in int s
        integer*4 s
C        in int e
        integer*4 e
C        out sidl.BaseInterface exception
        integer*8 exception



C       DO-NOT-DELETE splicer.begin(sort.IntegerContainer.output)
        integer*8 tracker, tae
        call synch_RegOut_getInstance_f(tracker, tae)
        call synch_RegOut_writeComment_f(tracker,
     $       'output list not implemented', tae)
        call synch_RegOut_deleteRef_f(tracker, tae)
C       DO-NOT-DELETE splicer.end(sort.IntegerContainer.output)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
