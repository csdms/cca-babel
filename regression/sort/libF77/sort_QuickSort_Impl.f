C       
C       File:          sort_QuickSort_Impl.f
C       Symbol:        sort.QuickSort-v0.1
C       Symbol Type:   class
C       Babel Version: 2.0.0 (Revision: 7435  trunk)
C       Description:   Server-side implementation for sort.QuickSort
C       
C       WARNING: Automatically generated; only changes within splicers preserved
C       
C       


C       
C       Symbol "sort.QuickSort" (version 0.1)
C       
C       Quick sort
C       


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
      logical function notEmpty(self)
      implicit none
      integer*8 self, stacks, depth
      integer*4 stackdepth
      call sort_QuickSort__get_data_f(self, stacks)
      call sidl_opaque__array_get1_f(stacks, 0, depth)
      call sidl_int__array_get1_f(depth, 0, stackdepth)
      notEmpty = (stackdepth .gt. 0)
      end

      subroutine push(self, lower, upper)
      implicit none
      integer*8 self
      integer*8 tracker, tae
      integer*8 stacks, low, up, depth
      integer*4 lower, upper, stackdepth
      call sort_QuickSort__get_data_f(self, stacks)
      call sidl_opaque__array_get1_f(stacks, 0, depth)
      call sidl_opaque__array_get1_f(stacks, 1, low)
      call sidl_opaque__array_get1_f(stacks, 2, up)
      call sidl_int__array_get1_f(depth, 0, stackdepth)
      if (stackdepth .lt. 32) then
         call sidl_int__array_set1_f(low, stackdepth, lower)
         call sidl_int__array_set1_f(up, stackdepth, upper)
         stackdepth = stackdepth + 1
         call sidl_int__array_set1_f(depth, 0, stackdepth)
      else
         call synch_RegOut_getInstance_f(tracker, tae)
         call synch_RegOut_writeComment_f(tracker,
     $        'stack overflow in QuickSort', tae)
         call synch_RegOut_forceFailure_f(tracker, tae)
         call synch_RegOut_deleteRef_f(tracker, tae)
         stop
      endif
      end

      subroutine pop(self, lower, upper)
      implicit none
      integer*8 self
      integer*8 stacks, low, up, depth, tracker, tae
      integer*4 lower, upper, stackdepth
      call sort_QuickSort__get_data_f(self, stacks)
      call sidl_opaque__array_get1_f(stacks, 0, depth)
      call sidl_opaque__array_get1_f(stacks, 1, low)
      call sidl_opaque__array_get1_f(stacks, 2, up)
      call sidl_int__array_get1_f(depth, 0, stackdepth)
      if (stackdepth .gt. 0) then
         stackdepth = stackdepth - 1
         call sidl_int__array_set1_f(depth, 0, stackdepth)
         call sidl_int__array_get1_f(low, stackdepth, lower)
         call sidl_int__array_get1_f(up, stackdepth, upper)
      else
         call synch_RegOut_getInstance_f(tracker, tae)
         call synch_RegOut_writeComment_f(tracker,
     $        'stack underflow in QuickSort', tae)
         call synch_RegOut_forceFailure_f(tracker, tae)
         call synch_RegOut_deleteRef_f(tracker, tae)
         stop
      endif
      end

C
C Choose the middle of the first, middle and last element of the
C list.  For small lists, return the middle without checking.
C
      integer*4 function choosePivot(elems, comp, cmp, start, end)
      implicit none
      integer*8 elems, comp, cmp, tae
      integer*4 start, end, pivot, mid, cmpres, counter
      pivot = (start + end) / 2
      if ((end - start) .gt. 4) then
         mid = pivot
         call sort_Counter_inc_f(cmp, counter, tae)
         call sort_Container_compare_f(elems, start, mid, comp,
     $        cmpres, tae)
         if (cmpres .le. 0) then
            call sort_Counter_inc_f(cmp, counter, tae)
            call sort_Container_compare_f(elems, mid, end -1,
     $           comp, cmpres, tae)
            if (cmpres .gt. 0) then
               call sort_Counter_inc_f(cmp, counter, tae)
               call sort_Container_compare_f(elems, start,
     $              end - 1, comp, cmpres, tae)
               if (cmpres .lt. 0) then
                  pivot = end - 1
               else
                  pivot = start
               endif
            endif
         else
            call sort_Counter_inc_f(cmp, counter, tae)
            call sort_Container_compare_f(elems, mid, end - 1,
     $           comp, cmpres, tae)
            if (cmpres .lt. 0) then
               call sort_Counter_inc_f(cmp, counter, tae)
               call sort_Container_compare_f(elems, start, end - 1,
     $              comp, cmpres, tae)
               if (cmpres .gt. 0) then
                  pivot = end - 1
               else
                  pivot = start
               endif
            endif
         endif
      endif
      choosePivot = pivot
      end

      subroutine quickSort(self, elems, comp, cmp, swp)
      implicit none
      integer*8 self, elems, comp, cmp, swp, tae
      integer*4 start, end, pivot, choosePivot
      integer*4 i, j, cmpres, counter
      logical notEmpty
      call sort_Container_getLength_f(elems, end, tae)
      start = 0
      call push(self, start, end)
      do while (notEmpty(self))
         call pop(self, start, end)
         if ((end - start) .gt. 1) then
            pivot = choosePivot(elems, comp, cmp, start, end)
            i = start
            j = end
            if (pivot .ne. start) then
               call sort_Counter_inc_f(swp, counter, tae)
               call sort_Container_swap_f(elems, start, pivot, tae)
            endif
 100        j = j - 1
            call sort_Counter_inc_f(cmp, counter, tae)
            call sort_Container_compare_f(elems, start, j, comp,
     $           cmpres, tae)
            if (cmpres .lt. 0) goto 100
            i = i + 1
            do while (i .lt. j)
               call sort_Counter_inc_f(cmp, counter, tae)
               call sort_Container_compare_f(elems, start,
     $              i, comp, cmpres, tae)
               if (cmpres .lt. 0) goto 200
               i = i + 1
            enddo
 200        if (i .ge. j) goto 300
            call sort_counter_inc_f(swp, counter, tae)
            call sort_Container_swap_f(elems, i, j, tae)
            goto 100
 300        if (j .ne. start) then
               call sort_Counter_inc_f(swp, counter, tae)
               call sort_Container_swap_f(elems, start, j, tae)
            endif
            call push(self, start, j)
            call push(self, j + 1, end)
         endif
      enddo
      end
      
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_start)



C       
C       Method:  _ctor[]
C       Class constructor called when the class is created.
C       

        subroutine sort_QuickSort__ctor_fi(self, exception)
        implicit none
C        in sort.QuickSort self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor)
        integer*8 stacks, lower, upper, depth
        integer*4 stackdepth
        stackdepth = 0
        call sidl_int__array_create1d_f(32, lower)
        call sidl_int__array_create1d_f(32, upper)
        call sidl_int__array_create1d_f(1, depth)
        call sidl_int__array_set1_f(depth, 0, stackdepth)
        call sidl_opaque__array_create1d_f(3, stacks)
        call sidl_opaque__array_set1_f(stacks, 0, depth)
        call sidl_opaque__array_set1_f(stacks, 1, lower)
        call sidl_opaque__array_set1_f(stacks, 2, upper)
        call sort_QuickSort__set_data_f(self, stacks)
C       DO-NOT-DELETE splicer.end(sort.QuickSort._ctor)
        end


C       
C       Method:  _ctor2[]
C       Special Class constructor called when the user wants to wrap his own private data.
C       

        subroutine sort_QuickSort__ctor2_fi(self, private_data, 
     &     exception)
        implicit none
C        in sort.QuickSort self
        integer*8 :: self
C        in opaque private_data
        integer*8 :: private_data
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort._ctor2)
C       Insert-Code-Here {sort.QuickSort._ctor2} (_ctor2 method)
C       DO-NOT-DELETE splicer.end(sort.QuickSort._ctor2)
        end


C       
C       Method:  _dtor[]
C       Class destructor called when the class is deleted.
C       

        subroutine sort_QuickSort__dtor_fi(self, exception)
        implicit none
C        in sort.QuickSort self
        integer*8 :: self
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor)
        integer*8 stacks, lower, upper, depth
        call sort_QuickSort__get_data_f(self, stacks)
        call sidl_opaque__array_get1_f(stacks, 0, depth)
        call sidl_opaque__array_get1_f(stacks, 1, lower)
        call sidl_opaque__array_get1_f(stacks, 2, upper)
        call sidl_int__array_deleteRef_f(depth)
        call sidl_int__array_deleteRef_f(lower)
        call sidl_int__array_deleteRef_f(upper)
        call sidl_opaque__array_deleteRef_f(stacks)
        stacks = 0
        call sort_QuickSort__set_data_f(self, stacks)
C       DO-NOT-DELETE splicer.end(sort.QuickSort._dtor)
        end


C       
C       Method:  _load[]
C       Static class initializer called exactly once before any user-defined method is dispatched
C       

        subroutine sort_QuickSort__load_fi(exception)
        implicit none
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort._load)
C       Insert the implementation here...
C       DO-NOT-DELETE splicer.end(sort.QuickSort._load)
        end


C       
C       Method:  sort[]
C       Sort elements using Quick Sort.
C       

        subroutine sort_QuickSort_sort_fi(self, elems, comp, exception)
        implicit none
C        in sort.QuickSort self
        integer*8 :: self
C        in sort.Container elems
        integer*8 :: elems
C        in sort.Comparator comp
        integer*8 :: comp
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort.sort)
        integer*8 swp, cmp, tae
        call sort_QuickSort_getCompareCounter_f(self, cmp, tae)
        call sort_QuickSort_getSwapCounter_f(self, swp, tae)
        call quickSort(self, elems, comp, cmp, swp)
        call sort_Counter_deleteRef_f(cmp, tae)
        call sort_Counter_deleteRef_f(swp, tae)
C       DO-NOT-DELETE splicer.end(sort.QuickSort.sort)
        end


C       
C       Method:  getName[]
C       Return quick sort.
C       

        subroutine sort_QuickSort_getName_fi(self, retval, exception)
        implicit none
C        in sort.QuickSort self
        integer*8 :: self
C        out string retval
        character*(*) :: retval
C        out sidl.BaseInterface exception
        integer*8 :: exception

C       DO-NOT-DELETE splicer.begin(sort.QuickSort.getName)
        retval = 'Quick sort'
C       DO-NOT-DELETE splicer.end(sort.QuickSort.getName)
        end


C       DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
C       Insert extra code here...
C       DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
