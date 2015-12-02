#
# File:          Integer_Impl.py
# Symbol:        sort.Integer-v0.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class sort.Integer in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""An object to hold a simple integer.
"""

# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sort.Integer
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class Integer:
  """\
An object to hold a simple integer.
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = sort.Integer.Integer(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    self.d_value = 0
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def getValue(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # int _return
    #

# DO-NOT-DELETE splicer.begin(getValue)
    return self.d_value
# DO-NOT-DELETE splicer.end(getValue)

  def setValue(self, value):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # int value
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # None
    #

# DO-NOT-DELETE splicer.begin(setValue)
    self.d_value = value
# DO-NOT-DELETE splicer.end(setValue)

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
