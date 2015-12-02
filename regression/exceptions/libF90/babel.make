IMPLMODULESRCS = ExceptionTest_FibException_Mod.F90 ExceptionTest_Fib_Mod.F90 \
  ExceptionTest_NegativeValueException_Mod.F90                                \
  ExceptionTest_TooBigException_Mod.F90 ExceptionTest_TooDeepException_Mod.F90
IMPLSRCS = ExceptionTest_FibException_Impl.F90 ExceptionTest_Fib_Impl.F90     \
  ExceptionTest_NegativeValueException_Impl.F90                               \
  ExceptionTest_TooBigException_Impl.F90                                      \
  ExceptionTest_TooDeepException_Impl.F90
IORHDRS = ExceptionTest_FibException_IOR.h ExceptionTest_Fib_IOR.h            \
  ExceptionTest_IOR.h ExceptionTest_NegativeValueException_IOR.h              \
  ExceptionTest_TooBigException_IOR.h ExceptionTest_TooDeepException_IOR.h
IORSRCS = ExceptionTest_FibException_IOR.c ExceptionTest_Fib_IOR.c            \
  ExceptionTest_NegativeValueException_IOR.c                                  \
  ExceptionTest_TooBigException_IOR.c ExceptionTest_TooDeepException_IOR.c
SKELSRCS = ExceptionTest_FibException_fSkel.c ExceptionTest_Fib_fSkel.c       \
  ExceptionTest_NegativeValueException_fSkel.c                                \
  ExceptionTest_TooBigException_fSkel.c ExceptionTest_TooDeepException_fSkel.c
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
