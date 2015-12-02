IORHDRS = ExceptionTest_FibException_IOR.h ExceptionTest_Fib_IOR.h            \
  ExceptionTest_IOR.h ExceptionTest_NegativeValueException_IOR.h              \
  ExceptionTest_TooBigException_IOR.h ExceptionTest_TooDeepException_IOR.h
IORSRCS = ExceptionTest_FibException_IOR.c ExceptionTest_Fib_IOR.c            \
  ExceptionTest_NegativeValueException_IOR.c                                  \
  ExceptionTest_TooBigException_IOR.c ExceptionTest_TooDeepException_IOR.c
SKELSRCS = ExceptionTest_FibException_jniSkel.c ExceptionTest_Fib_jniSkel.c   \
  ExceptionTest_NegativeValueException_jniSkel.c                              \
  ExceptionTest_TooBigException_jniSkel.c                                     \
  ExceptionTest_TooDeepException_jniSkel.c
STUBHDRS = ExceptionTest_FibException_jniStub.h ExceptionTest_Fib_jniStub.h   \
  ExceptionTest_NegativeValueException_jniStub.h                              \
  ExceptionTest_TooBigException_jniStub.h                                     \
  ExceptionTest_TooDeepException_jniStub.h
STUBSRCS = ExceptionTest_FibException_jniStub.c ExceptionTest_Fib_jniStub.c   \
  ExceptionTest_NegativeValueException_jniStub.c                              \
  ExceptionTest_TooBigException_jniStub.c                                     \
  ExceptionTest_TooDeepException_jniStub.c
