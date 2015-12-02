#
# File:          NegativeValueException_Impl.py
# Symbol:        ExceptionTest.NegativeValueException-v1.0
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class ExceptionTest.NegativeValueException in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""This exception is thrown if the value for which the Fibonacci number
is requested is negative.
"""

# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import ExceptionTest.NegativeValueException
import sidl.BaseClass
import sidl.BaseException
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.SIDLException
import sidl.io.Deserializer
import sidl.io.Serializable
import sidl.io.Serializer
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class NegativeValueException:
  """\
This exception is thrown if the value for which the Fibonacci number
is requested is negative.
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself =                                                        \
        ExceptionTest.NegativeValueException.NegativeValueException(impl =    \
        self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    # Put your code here...
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
