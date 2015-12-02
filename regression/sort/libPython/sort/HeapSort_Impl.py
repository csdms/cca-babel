#
# File:          HeapSort_Impl.py
# Symbol:        sort.HeapSort-v0.1
# Symbol Type:   class
# Babel Version: 1.4.0 (Revision: 6563M trunk)
# Description:   Implementation of sidl class sort.HeapSort in Python.
# 
# WARNING: Automatically generated; changes will be lost
# 
#


"""Heap sort
"""

# DO-NOT-DELETE splicer.begin(_initial)
# DO-NOT-DELETE splicer.end(_initial)

import sidl.BaseClass
import sidl.BaseInterface
import sidl.ClassInfo
import sidl.RuntimeException
import sort.Comparator
import sort.Container
import sort.Counter
import sort.HeapSort
import sort.SortingAlgorithm
import sidl.NotImplementedException

# DO-NOT-DELETE splicer.begin(_before_type)
def remakeHeap(elem, comp, cmp, swp, last, first):
  half = (last >> 1) - 1
  while (first <= half):
    child = first + first + 1
    if ((child + 1) < last):
      cmp.inc()
      if (elem.compare(child, child+1, comp) < 0): child = child +1
    cmp.inc()
    if (elem.compare(first, child, comp) >= 0): return
    swp.inc()
    elem.swap(first, child)
    first = child
# DO-NOT-DELETE splicer.end(_before_type)

class HeapSort:
  """\
Heap sort
"""

# All calls to sidl methods should use __IORself

# Normal Babel creation pases in an IORself. If IORself == None
# that means this Impl class is being constructed for native delegation
  def __init__(self, IORself = None):
    if (IORself == None):
      self.__IORself = sort.HeapSort.HeapSort(impl = self)
    else:
      self.__IORself = IORself
# DO-NOT-DELETE splicer.begin(__init__)
    # Put your code here...
# DO-NOT-DELETE splicer.end(__init__)

# Returns the IORself (client stub) of the Impl, mainly for use
# with native delegation
  def _getStub(self):
    return self.__IORself

  def sort(self, elems, comp):
    #
    # sidl EXPECTED INCOMING TYPES
    # ============================
    # sort.Container elems
    # sort.Comparator comp
    #

    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # None
    #

    """\
Sort elements using Heap Sort.
"""
# DO-NOT-DELETE splicer.begin(sort)
    size = elems.getLength()
    cmp = self.__IORself.getCompareCounter()
    swp = self.__IORself.getSwapCounter()
    for i in xrange((size >> 1) - 1, -1, -1):
      remakeHeap(elems, comp, cmp, swp, size, i)
    i = size - 1
    while (i > 0):
      swp.inc()
      elems.swap(0, i)
      remakeHeap(elems, comp, cmp, swp, i, 0)
      i = i - 1
# DO-NOT-DELETE splicer.end(sort)

  def getName(self):
    #
    # sidl EXPECTED RETURN VALUE(s)
    # =============================
    # string _return
    #

    """\
Return heap sort.
"""
# DO-NOT-DELETE splicer.begin(getName)
    return "Heap sort"
# DO-NOT-DELETE splicer.end(getName)

# DO-NOT-DELETE splicer.begin(_final)
# Put your code here...
# DO-NOT-DELETE splicer.end(_final)
