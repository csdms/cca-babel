! 
! File:          ExceptionTest_TooBigException_Impl.F90
! Symbol:        ExceptionTest.TooBigException-v1.0
! Symbol Type:   class
! Babel Version: 1.4.0 (Revision: 6607 release-1-4-0-branch)
! Description:   Server-side implementation for ExceptionTest.TooBigException
! 
! WARNING: Automatically generated; only changes within splicers preserved
! 
! 


! 
! Symbol "ExceptionTest.TooBigException" (version 1.0)
! 
! This exception is thrown if the Fibonacci number is too large.
! 


#include "sidl_NotImplementedException_fAbbrev.h"
#include "sidl_SIDLException_fAbbrev.h"
#include "ExceptionTest_FibException_fAbbrev.h"
#include "sidl_io_Deserializer_fAbbrev.h"
#include "sidl_ClassInfo_fAbbrev.h"
#include "ExceptionTest_TooBigException_fAbbrev.h"
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

recursive subroutine TooBigExcept__ctor3jwdutdu8v_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooBigException
  use ExceptionTest_TooBigException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor.use)
  implicit none
  type(ExceptionTest_TooBigException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor)
end subroutine TooBigExcept__ctor3jwdutdu8v_mi


! 
! Method:  _ctor2[]
! Special Class constructor called when the user wants to wrap his own private data.
! 

recursive subroutine TooBigExcep__ctor2k8reh2ipr4_mi(self, private_data,       &
  exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooBigException
  use ExceptionTest_TooBigException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor2.use)
  ! Insert-Code-Here {ExceptionTest.TooBigException._ctor2.use} (use statements)
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor2.use)
  implicit none
  type(ExceptionTest_TooBigException_t) :: self
  ! in
  type(ExceptionTest_TooBigException_wrap) :: private_data
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._ctor2)
! Insert-Code-Here {ExceptionTest.TooBigException._ctor2} (_ctor2 method)
! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._ctor2)
end subroutine TooBigExcep__ctor2k8reh2ipr4_mi


! 
! Method:  _dtor[]
! Class destructor called when the class is deleted.
! 

recursive subroutine TooBigExcept__dtorhifmzlpoff_mi(self, exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooBigException
  use ExceptionTest_TooBigException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._dtor.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._dtor.use)
  implicit none
  type(ExceptionTest_TooBigException_t) :: self
  ! in
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._dtor)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._dtor)
end subroutine TooBigExcept__dtorhifmzlpoff_mi


! 
! Method:  _load[]
! Static class initializer called exactly once before any user-defined method is dispatched
! 

recursive subroutine TooBigExcept__load4w4p9f7cz4_mi(exception)
  use sidl
  use sidl_NotImplementedException
  use sidl_BaseInterface
  use sidl_RuntimeException
  use ExceptionTest_TooBigException
  use ExceptionTest_TooBigException_impl
  ! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._load.use)
  ! Insert use statements here...
  ! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._load.use)
  implicit none
  type(sidl_BaseInterface_t) :: exception
  ! out



! DO-NOT-DELETE splicer.begin(ExceptionTest.TooBigException._load)
! Insert the implementation here...
! DO-NOT-DELETE splicer.end(ExceptionTest.TooBigException._load)
end subroutine TooBigExcept__load4w4p9f7cz4_mi


! DO-NOT-DELETE splicer.begin(_miscellaneous_code_end)
! Insert extra code here...
! DO-NOT-DELETE splicer.end(_miscellaneous_code_end)
