! 
! File:          ExceptionTest_TooDeepException_Impl.F90
! Symbol:        ExceptionTest.TooDeepException-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side implementation for ExceptionTest.TooDeepException
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "ExceptionTest.TooDeepException" (version 1.0)
! 
! This exception is thrown if the Fibonacci recursion is too deep.
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sidl_SIDLException_fAbbrev.h"
#include "ExceptionTest_TooDeepException_fAbbrev.h"
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

recursive subroutine TooDeepExcep__ctor1ake1o4cbo_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooDeepException
  use ExceptionTest_TooDeepException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._ctor.use)
  implicit none
  type(ExceptionTest_TooDeepException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._ctor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._ctor)
end subroutine TooDeepExcep__ctor1ake1o4cbo_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine TooDeepExce__ctor27sdxb0j1zh_mi(self, private_data,       &
  exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooDeepException
  use ExceptionTest_TooDeepException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._ctor2.use)
  ! Insert-Code-Here {ExceptionTest.TooDeepException._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._ctor2.use)
  implicit none
  type(ExceptionTest_TooDeepException_t) :: self
  ! in
  type(ExceptionTest_TooDeepException_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._ctor2)
! Insert-Code-Here {ExceptionTest.TooDeepException._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._ctor2)
end subroutine TooDeepExce__ctor27sdxb0j1zh_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine TooDeepExcep__dtor3oskxzdn6p_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooDeepException
  use ExceptionTest_TooDeepException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._dtor.use)
  implicit none
  type(ExceptionTest_TooDeepException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._dtor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._dtor)
end subroutine TooDeepExcep__dtor3oskxzdn6p_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine TooDeepExcep__load92bhnpbj8x_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooDeepException
  use ExceptionTest_TooDeepException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooDeepException._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooDeepException._load)
end subroutine TooDeepExcep__load92bhnpbj8x_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
