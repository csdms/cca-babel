#
# File:          SimpleCounter_Impl.py
# Symbol:        sort.SimpleCounter-v0.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class sort.SimpleCounter in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""Simple counter
"""

# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sort.Counter
import sort.SimpleCounter
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class SimpleCounter:
  """\
Simple counter
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = sort.SimpleCounter.SimpleCounter(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    self.d_count = 0
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def reset(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # None
    #

    """\
Set the count to zero.
"""
# DO-NOT-DELETE splicer.begin(reset)
    self.d_count = 0
# DO-NOT-DELETE splicer.end(reset)

  def getCount(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # int _return
    #

    """\
Return the current count.
"""
# DO-NOT-DELETE splicer.begin(getCount)
    return self.d_count
# DO-NOT-DELETE splicer.end(getCount)

  def inc(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # int _return
    #

    """\
Increment the count (i.e. add one).
"""
# DO-NOT-DELETE splicer.begin(inc)
    self.d_count = self.d_count + 1
    return self.d_count
# DO-NOT-DELETE splicer.end(inc)

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
