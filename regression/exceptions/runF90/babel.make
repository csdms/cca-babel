IORHDRS = ExceptionTest_FibException_IOR.h ExceptionTest_Fib_IOR.h            \
  ExceptionTest_IOR.h ExceptionTest_NegativeValueException_IOR.h              \
  ExceptionTest_TooBigException_IOR.h ExceptionTest_TooDeepException_IOR.h
STUBHDRS = ExceptionTest_FibException_fAbbrev.h                               \
  ExceptionTest_FibException_fStub.h ExceptionTest_Fib_fAbbrev.h              \
  ExceptionTest_Fib_fStub.h ExceptionTest_NegativeValueException_fAbbrev.h    \
  ExceptionTest_NegativeValueException_fStub.h                                \
  ExceptionTest_TooBigException_fAbbrev.h                                     \
  ExceptionTest_TooBigException_fStub.h                                       \
  ExceptionTest_TooDeepException_fAbbrev.h                                    \
  ExceptionTest_TooDeepException_fStub.h
STUBMODULESRCS = ExceptionTest_Fib.F90 ExceptionTest_FibException.F90         \
  ExceptionTest_NegativeValueException.F90 ExceptionTest_TooBigException.F90  \
  ExceptionTest_TooDeepException.F90
STUBSRCS = ExceptionTest_FibException_fStub.c ExceptionTest_Fib_fStub.c       \
  ExceptionTest_NegativeValueException_fStub.c                                \
  ExceptionTest_TooBigException_fStub.c ExceptionTest_TooDeepException_fStub.c
TYPEMODULESRCS = ExceptionTest_FibException_type.F90                          \
  ExceptionTest_Fib_type.F90 ExceptionTest_NegativeValueException_type.F90    \
  ExceptionTest_TooBigException_type.F90                                      \
  ExceptionTest_TooDeepException_type.F90
