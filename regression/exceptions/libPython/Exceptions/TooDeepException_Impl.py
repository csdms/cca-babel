#
# File:          TooDeepException_Impl.py
# Symbol:        Exceptions.TooDeepException-v1.0
# Symbol Type:   class
# Babel Version: 2.0.0 (Revision: 7436M trunk)
# Description:   Implementation of sidl class Exceptions.TooDeepException in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""This exception is thrown if the Fibonacci recursion is too deep.
"""

# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import Exceptions.FibException
import Exceptions.TooDeepException
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


class PlaceHolder:
  """work around a limitation of the grammar of Python < 2.5"""
  pass

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class TooDeepException(
# DO-NOT-DELETE splicer.begin(_inherits)
#
# Name of type(s) to inherit from.
# If desired, please change `PlaceHolder' to your own base class.
#

PlaceHolder
# DO-NOT-DELETE splicer.end(_inherits)
  ):
  """\
This exception is thrown if the Fibonacci recursion is too deep.
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = Exceptions.TooDeepException.TooDeepException(impl =    \
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
