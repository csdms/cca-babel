#
# File:          G_Impl.py
# Symbol:        Inherit.G-v1.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class Inherit.G in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


# DO-NOT-DELETE splicer.begin(_initial)
print "Hello"
# DO-NOT-DELETE splicer.end(_initial)

import Inherit.A
import Inherit.D
import Inherit.G
import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Put your code here...
# DO-NOT-DELETE splicer.end(_before_type)

class G:

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = Inherit.G.G(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    # Put your code here...
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def g(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(g)
    return "G.g"
# DO-NOT-DELETE splicer.end(g)

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
