#
# File:          StructTest_Impl.py
# Symbol:        s.StructTest-v1.0
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class s.StructTest in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


# DO-NOT-DELETE splicer.begin(_initial)
# Insert-Code-Here {_initial} ()
# DO-NOT-DELETE splicer.end(_initial)

import s.Combined
import s.Empty
import s.Hard
import s.Simple
import s.StructTest
import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
import s.Color
s_pkg = s

import sidlPyArrays
if sidlPyArrays.type == "numpy":
  from numpy import zeros, float32
elif sidlPyArrays.type == "numeric":
  import Numeric
  zeros = Numeric.zeros
  float32 = Numeric.Float32

def toFloat(d):
  tmp = zeros((1,), float32)
  try:
    tmp[0] = d
  except AttributeError:
    # don't die!
    tmp[0] = d
  return float(tmp[0])

def initSimple():
  s = s_pkg.Simple.Simple()
  s.d_bool = 1
  s.d_char = '3'
  s.d_dcomplex = 3.14+3.14j
  s.d_fcomplex = toFloat(3.1)+ toFloat(3.1) * 1j
  s.d_double = 3.14
  s.d_float = toFloat(3.1)
  s.d_int = 3
  s.d_long = 3
  s.d_opaque = None
  s.d_enum = s_pkg.Color.blue
  return s

def checkSimple(s):
  return (s.d_bool and (s.d_char == '3') and (s.d_dcomplex == 3.14+3.14j) and
          (s.d_double == 3.14) and
          (s.d_fcomplex == (toFloat(3.1) + toFloat(3.1) * 1j)) and
          (s.d_float == toFloat(3.1)) and (3 == s.d_int) and
          (3 == s.d_long) and (s.d_opaque == None) and
          (s_pkg.Color.blue == s.d_enum))

def invertSimple(s):
  s.d_bool = not s.d_bool
  if (s.d_char.islower()):
    s.d_char = s.d_char.upper()
  else:
    s.d_char =  s.d_char.lower()
  s.d_dcomplex = s.d_dcomplex.conjugate()
  s.d_fcomplex = s.d_fcomplex.conjugate()
  s.d_double = -s.d_double
  s.d_float = -s.d_float
  s.d_int = -s.d_int
  s.d_long = -s.d_long
  s.d_enum = s_pkg.Color.red
  return s

def initHard():
  h = s_pkg.Hard.Hard()
  h.d_string = "Three"
  h.d_object = sidl.BaseClass.BaseClass()
  h.d_interface = h.d_object
  h.d_array = [ 1.0, 2.0, 3.0 ]
  h.d_objectArray = [ sidl.BaseClass.BaseClass(),
                      sidl.BaseClass.BaseClass(),
                      sidl.BaseClass.BaseClass() ]
  return h

def checkHard(h):
  return (("Three" == h.d_string) and (None != h.d_object) and
          (None != h.d_interface) and h.d_object.isSame(h.d_interface) and
          (len(h.d_array) == 3) and (h.d_array[0] == 1.0) and
          (h.d_array[1] == 2.0) and (h.d_array[2] == 3.0) and
          (len(h.d_objectArray) == 3) and
          h.d_objectArray[0].isType("sidl.BaseClass") and
          h.d_objectArray[1].isType("sidl.BaseClass") and
          h.d_objectArray[2].isType("sidl.BaseClass"))

def invertHard(h):
  if ((None != h.d_string) and (len(h.d_string) > 0)):
    if (h.d_string[0].islower()):
      h.d_string = h.d_string[0].upper() + h.d_string[1:]
    else:
      h.d_string = h.d_string[0].lower() + h.d_string[1:]
  if ((None != h.d_object) and (None != h.d_interface)):
    if (h.d_object.isSame(h.d_interface)):
      h.d_interface = sidl.BaseClass.BaseClass()
    else:
      h.d_interface = h.d_object
  if (len(h.d_array) == 3):
    (h.d_array[0], h.d_array[2]) = (h.d_array[2], h.d_array[0])
  oa = h.d_objectArray
  if ((len(oa) == 3)):
    if (oa[1] != None):
      oa[1] = None
    else:
      oa[1] = sidl.BaseClass.BaseClass()
  h.d_objectArray = oa
  return h

def initCombined():
  c = s_pkg.Combined.Combined()
  c.d_simple = initSimple()
  c.d_hard = initHard()
  return c

def checkCombined(c):
  return checkSimple(c.d_simple) and checkHard(c.d_hard)

def invertCombined(c):
  invertSimple(c.d_simple)
  invertHard(c.d_hard)
  return c
# DO-NOT-DELETE splicer.end(_before_type)

class StructTest:

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = s.StructTest.StructTest(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def returnEmpty(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # s.Empty _return
    #

# DO-NOT-DELETE splicer.begin(returnEmpty)
    return s_pkg.Empty.Empty()
# DO-NOT-DELETE splicer.end(returnEmpty)

  def passinEmpty(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Empty s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # bool _return
    #

# DO-NOT-DELETE splicer.begin(passinEmpty)
    return 1
# DO-NOT-DELETE splicer.end(passinEmpty)

  def passoutEmpty(self):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Empty s
    #

# DO-NOT-DELETE splicer.begin(passoutEmpty)
    return (1, s_pkg.Empty.Empty())
# DO-NOT-DELETE splicer.end(passoutEmpty)

  def passinoutEmpty(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Empty s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Empty s
    #

# DO-NOT-DELETE splicer.begin(passinoutEmpty)
    return (1, s_pkg.Empty.Empty())
# DO-NOT-DELETE splicer.end(passinoutEmpty)

  def passeverywhereEmpty(self, s1, s3):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Empty s1
    # s.Empty s3
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s2, s3)
    # s.Empty _return
    # s.Empty s2
    # s.Empty s3
    #

# DO-NOT-DELETE splicer.begin(passeverywhereEmpty)
    return (s.Empty.Empty(), s.Empty.Empty(), s.Empty.Empty())
# DO-NOT-DELETE splicer.end(passeverywhereEmpty)

  def returnSimple(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # s.Simple _return
    #

# DO-NOT-DELETE splicer.begin(returnSimple)
    return initSimple()
# DO-NOT-DELETE splicer.end(returnSimple)

  def passinSimple(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Simple s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # bool _return
    #

# DO-NOT-DELETE splicer.begin(passinSimple)
    return checkSimple(s)
# DO-NOT-DELETE splicer.end(passinSimple)

  def passoutSimple(self):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Simple s
    #

# DO-NOT-DELETE splicer.begin(passoutSimple)
    return (1, initSimple())
# DO-NOT-DELETE splicer.end(passoutSimple)

  def passinoutSimple(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Simple s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Simple s
    #

# DO-NOT-DELETE splicer.begin(passinoutSimple)
    return (checkSimple(s), invertSimple(s))
# DO-NOT-DELETE splicer.end(passinoutSimple)

  def passeverywhereSimple(self, s1, s3):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Simple s1
    # s.Simple s3
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s2, s3)
    # s.Simple _return
    # s.Simple s2
    # s.Simple s3
    #

# DO-NOT-DELETE splicer.begin(passeverywhereSimple)
    if (checkSimple(s1) and checkSimple(s3)):
      s3 = invertSimple(s3)
    return (initSimple(), initSimple(), s3)
# DO-NOT-DELETE splicer.end(passeverywhereSimple)

  def returnHard(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # s.Hard _return
    #

# DO-NOT-DELETE splicer.begin(returnHard)
    return initHard()
# DO-NOT-DELETE splicer.end(returnHard)

  def passinHard(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Hard s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # bool _return
    #

# DO-NOT-DELETE splicer.begin(passinHard)
    return checkHard(s)
# DO-NOT-DELETE splicer.end(passinHard)

  def passoutHard(self):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Hard s
    #

# DO-NOT-DELETE splicer.begin(passoutHard)
    return (1, initHard())
# DO-NOT-DELETE splicer.end(passoutHard)

  def passinoutHard(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Hard s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Hard s
    #

# DO-NOT-DELETE splicer.begin(passinoutHard)
    return (checkHard(s), invertHard(s))
# DO-NOT-DELETE splicer.end(passinoutHard)

  def passeverywhereHard(self, s1, s3):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Hard s1
    # s.Hard s3
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s2, s3)
    # s.Hard _return
    # s.Hard s2
    # s.Hard s3
    #

# DO-NOT-DELETE splicer.begin(passeverywhereHard)
    if (checkHard(s1) and checkHard(s3)):
      s3 = invertHard(s3)
    return (initHard(), initHard(), s3)
# DO-NOT-DELETE splicer.end(passeverywhereHard)

  def returnCombined(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # s.Combined _return
    #

# DO-NOT-DELETE splicer.begin(returnCombined)
    return initCombined()
# DO-NOT-DELETE splicer.end(returnCombined)

  def passinCombined(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Combined s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # bool _return
    #

# DO-NOT-DELETE splicer.begin(passinCombined)
    return checkCombined(s)
# DO-NOT-DELETE splicer.end(passinCombined)

  def passoutCombined(self):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Combined s
    #

# DO-NOT-DELETE splicer.begin(passoutCombined)
    return (1, initCombined())
# DO-NOT-DELETE splicer.end(passoutCombined)

  def passinoutCombined(self, s):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Combined s
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s)
    # bool _return
    # s.Combined s
    #

# DO-NOT-DELETE splicer.begin(passinoutCombined)
    return (checkCombined(s), invertCombined(s))
# DO-NOT-DELETE splicer.end(passinoutCombined)

  def passeverywhereCombined(self, s1, s3):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # s.Combined s1
    # s.Combined s3
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # (_return, s2, s3)
    # s.Combined _return
    # s.Combined s2
    # s.Combined s3
    #

# DO-NOT-DELETE splicer.begin(passeverywhereCombined)
    if (checkCombined(s1) and checkCombined(s3)):
      s3 = invertCombined(s3)
    return (initCombined(), initCombined(), s3)
# DO-NOT-DELETE splicer.end(passeverywhereCombined)

# DO-NOT-DELETE splicer.begin(_final)
# Insert-Code-Here {_final} ()
# DO-NOT-DELETE splicer.end(_final)
