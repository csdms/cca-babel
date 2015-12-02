IMPLSRCS = ExceptionTest_FibException_Impl.f ExceptionTest_Fib_Impl.f         \
  ExceptionTest_NegativeValueException_Impl.f                                 \
  ExceptionTest_TooBigException_Impl.f ExceptionTest_TooDeepException_Impl.f
IORHDRS = ExceptionTest_FibException_IOR.h ExceptionTest_Fib_IOR.h            \
  ExceptionTest_IOR.h ExceptionTest_NegativeValueException_IOR.h              \
  ExceptionTest_TooBigException_IOR.h ExceptionTest_TooDeepException_IOR.h
IORSRCS = ExceptionTest_FibException_IOR.c ExceptionTest_Fib_IOR.c            \
  ExceptionTest_NegativeValueException_IOR.c                                  \
  ExceptionTest_TooBigException_IOR.c ExceptionTest_TooDeepException_IOR.c
SKELSRCS = ExceptionTest_FibException_fSkel.c ExceptionTest_Fib_fSkel.c       \
  ExceptionTest_NegativeValueException_fSkel.c                                \
  ExceptionTest_TooBigException_fSkel.c ExceptionTest_TooDeepException_fSkel.c
STUBDOCS = ExceptionTest_Fib.fif ExceptionTest_FibException.fif               \
  ExceptionTest_NegativeValueException.fif ExceptionTest_TooBigException.fif  \
  ExceptionTest_TooDeepException.fif
STUBHDRS = ExceptionTest_FibException_fStub.h ExceptionTest_Fib_fStub.h       \
  ExceptionTest_NegativeValueException_fStub.h                                \
  ExceptionTest_TooBigException_fStub.h ExceptionTest_TooDeepException_fStub.h
STUBSRCS = ExceptionTest_FibException_fStub.c ExceptionTest_Fib_fStub.c       \
  ExceptionTest_NegativeValueException_fStub.c                                \
  ExceptionTest_TooBigException_fStub.c ExceptionTest_TooDeepException_fStub.c
