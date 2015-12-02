#
# File:          K_Impl.py
# Symbol:        Inherit.K-v1.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class Inherit.K in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


# DO-NOT-DELETE splicer.begin(_initial)
# Insert-Code-Here {_initial} ()
# DO-NOT-DELETE splicer.end(_initial)

import Inherit.A
import Inherit.A2
import Inherit.H
import Inherit.K
import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
# Insert-Code-Here {_before_type} ()
# DO-NOT-DELETE splicer.end(_before_type)

class K:

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = Inherit.K.K(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    # Insert-Code-Here {__init__} ()
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def a2(self, i):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # int i
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(a2)
    # Insert-Code-Here {a2} ()
    return "K.a2"
# DO-NOT-DELETE splicer.end(a2)

  def a(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(a)
    # Insert-Code-Here {a} ()
    return "K.a"
# DO-NOT-DELETE splicer.end(a)

  def h(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(h)
    # Insert-Code-Here {h} ()
    return "K.h"
# DO-NOT-DELETE splicer.end(h)

  def k(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

# DO-NOT-DELETE splicer.begin(k)
    # Insert-Code-Here {k} ()
    return "K.k"
# DO-NOT-DELETE splicer.end(k)

# DO-NOT-DELETE splicer.begin(_final)
# Insert-Code-Here {_final} ()
# DO-NOT-DELETE splicer.end(_final)
