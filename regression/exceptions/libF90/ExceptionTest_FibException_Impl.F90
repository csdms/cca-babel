! 
! File:          ExceptionTest_FibException_Impl.F90
! Symbol:        ExceptionTest.FibException-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side implementation for ExceptionTest.FibException
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "ExceptionTest.FibException" (version 1.0)
! 
! This exception is a base class for the Fibonacci exceptions that are
! thrown if the value is too large or the recursion depth is too deep.
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sidl_SIDLException_fAbbrev.h"
#include "ExceptionTest_FibException_fAbbrev.h"
#include "sidl_io_Deserializer_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "sidl_io_Serializable_fAbbrev.h"
#include "sidl_BaseInterface_fAbbrev.h"
#include "sidl_RuntimeException_fAbbrev.h"
#include "sidl_io_Serializer_fAbbrev.h"
#include "sidl_BaseException_fAbbrev.h"
#include "sidl_BaseClass_fAbbrev.h"
! DO-NOT-DELETE splicer.begin(_miscellaneous_code_start)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_start)




! 
! Method:  _ctor[]
! Class constructor called when the class is created.
! 

recursive subroutine FibException__ctorch6at6eegc_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_FibException
  use ExceptionTest_FibException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor.use)
  implicit none
  type(ExceptionTest_FibException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor)
end subroutine FibException__ctorch6at6eegc_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine FibExceptio__ctor2c267psw2jt_mi(self, private_data,       &
  exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_FibException
  use ExceptionTest_FibException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor2.use)
  ! Insert-Code-Here {ExceptionTest.FibException._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor2.use)
  implicit none
  type(ExceptionTest_FibException_t) :: self
  ! in
  type(ExceptionTest_FibException_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._ctor2)
! Insert-Code-Here {ExceptionTest.FibException._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._ctor2)
end subroutine FibExceptio__ctor2c267psw2jt_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine FibException__dtorg2dtuiwq9i_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_FibException
  use ExceptionTest_FibException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._dtor.use)
  implicit none
  type(ExceptionTest_FibException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._dtor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._dtor)
end subroutine FibException__dtorg2dtuiwq9i_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine FibException__load0sdw0ljyvx_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_FibException
  use ExceptionTest_FibException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.FibException._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.FibException._load)
end subroutine FibException__load0sdw0ljyvx_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
