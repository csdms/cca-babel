#
# File:          BClass_Impl.py
# Symbol:        Overload.BClass-v1.0
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class Overload.BClass in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""This class is passed into the overloaded method as another example
of passing classes.
"""

# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import Overload.AClass
import Overload.BClass
import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class BClass:
  """\
This class is passed into the overloaded method as another example
of passing classes.
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = Overload.BClass.BClass(impl = self)
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
