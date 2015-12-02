#
# File:          J_Impl.py
# Symbol:        Inherit.J-v1.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class Inherit.J in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


# DO-NOT-DELETE splicer.begin(_initial)
# Put your code here...
# DO-NOT-DELETE splicer.end(_initial)

import Inherit.A
import Inherit.B
import Inherit.C
import Inherit.E2
import Inherit.J
import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class J:

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = Inherit.J.J(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    # Put your code here...
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def j(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(j)
    # Put your code here...
    return "J.j"
# DO-NOT-DELETE splicer.end(j)

  def e(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(e)
    # Put your code here...
    return "J.E2.e"
# DO-NOT-DELETE splicer.end(e)

  def c(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(c)
    # Put your code here...
    return "J.E2.c"
# DO-NOT-DELETE splicer.end(c)

  def a(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(a)
    # Put your code here...
    return "J.a"
# DO-NOT-DELETE splicer.end(a)

  def b(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(b)
    # Put your code here...
    return "J.b"
# DO-NOT-DELETE splicer.end(b)

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
