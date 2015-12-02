IMPLHDRS = ExceptionTest_FibException_Impl.hxx ExceptionTest_Fib_Impl.hxx     \
  ExceptionTest_NegativeValueException_Impl.hxx                               \
  ExceptionTest_TooBigException_Impl.hxx                                      \
  ExceptionTest_TooDeepException_Impl.hxx
IMPLSRCS = ExceptionTest_FibException_Impl.cxx ExceptionTest_Fib_Impl.cxx     \
  ExceptionTest_NegativeValueException_Impl.cxx                               \
  ExceptionTest_TooBigException_Impl.cxx                                      \
  ExceptionTest_TooDeepException_Impl.cxx
IORHDRS = ExceptionTest_FibException_IOR.h ExceptionTest_Fib_IOR.h            \
  ExceptionTest_IOR.h ExceptionTest_NegativeValueException_IOR.h              \
  ExceptionTest_TooBigException_IOR.h ExceptionTest_TooDeepException_IOR.h
IORSRCS = ExceptionTest_FibException_IOR.c ExceptionTest_Fib_IOR.c            \
  ExceptionTest_NegativeValueException_IOR.c                                  \
  ExceptionTest_TooBigException_IOR.c ExceptionTest_TooDeepException_IOR.c
SKELSRCS = ExceptionTest_FibException_Skel.cxx ExceptionTest_Fib_Skel.cxx     \
  ExceptionTest_NegativeValueException_Skel.cxx                               \
  ExceptionTest_TooBigException_Skel.cxx                                      \
  ExceptionTest_TooDeepException_Skel.cxx
STUBHDRS = ExceptionTest.hxx ExceptionTest_Fib.hxx                            \
  ExceptionTest_FibException.hxx ExceptionTest_NegativeValueException.hxx     \
  ExceptionTest_TooBigException.hxx ExceptionTest_TooDeepException.hxx
STUBSRCS = ExceptionTest_Fib.cxx ExceptionTest_FibException.cxx               \
  ExceptionTest_NegativeValueException.cxx ExceptionTest_TooBigException.cxx  \
  ExceptionTest_TooDeepException.cxx
