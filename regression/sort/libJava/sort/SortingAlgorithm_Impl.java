/*
 * File:          SortingAlgorithm_Impl.java
 * Symbol:        sort.SortingAlgorithm-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7436M trunk)
 * Description:   Server-side implementation for sort.SortingAlgorithm
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package sort;

import sidl.BaseClass;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sort.Comparator;
import sort.Container;
import sort.Counter;

// DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._imports)

/**
 * Symbol "sort.SortingAlgorithm" (version 0.1)
 * 
 * An abstract sorting algorithm.
 */
public class SortingAlgorithm_Impl extends SortingAlgorithm
{

  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._data)
  sort.Counter d_cmp;
  sort.Counter d_swp;
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._data)


  static { 
  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._load)

  }

  /**
   * User defined constructor
   */
  public SortingAlgorithm_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.SortingAlgorithm)
    // add construction details here
    d_cmp = (sort.Counter) sort.Counter.Wrapper._cast(new sort.SimpleCounter());
    d_swp = (sort.Counter) sort.Counter.Wrapper._cast(new sort.SimpleCounter());
    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.SortingAlgorithm)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.finalize)
    // Insert-Code-Here {sort.SortingAlgorithm.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods:
  /**
   * Return the comparison counter.
   */
  public sort.Counter getCompareCounter_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getCompareCounter)
    // insert implementation here
    sort.Counter result = null;
    result = d_cmp;
    return result;

    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getCompareCounter)

  }

  /**
   * Return the swap counter.
   */
  public sort.Counter getSwapCounter_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.getSwapCounter)
    // insert implementation here
    sort.Counter result = null;
    result = d_swp;
    return result;

    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.getSwapCounter)

  }

  /**
   * Reset the comparison and swap counter.
   */
  public void reset_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm.reset)
    // insert implementation here
    d_swp.reset();
    d_cmp.reset();
    return ;
    // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm.reset)

  }


  // DO-NOT-DELETE splicer.begin(sort.SortingAlgorithm._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(sort.SortingAlgorithm._misc)

} // end class SortingAlgorithm

