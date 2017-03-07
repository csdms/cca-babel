/*
 * File:          SimpleCounter_Impl.java
 * Symbol:        sort.SimpleCounter-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7436M trunk)
 * Description:   Server-side implementation for sort.SimpleCounter
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package sort;

import sidl.BaseClass;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sort.Counter;

// DO-NOT-DELETE splicer.begin(sort.SimpleCounter._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(sort.SimpleCounter._imports)

/**
 * Symbol "sort.SimpleCounter" (version 0.1)
 * 
 * Simple counter
 */
public class SimpleCounter_Impl extends SimpleCounter
{

  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._data)
  private int d_count = 0;
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._data)


  static { 
  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._load)

  }

  /**
   * User defined constructor
   */
  public SimpleCounter_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.SimpleCounter)
    // add construction details here
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter.SimpleCounter)

  }

  /**
   * Back door constructor
   */
  public SimpleCounter_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._wrap)
    // Insert-Code-Here {sort.SimpleCounter._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.finalize)
    // Insert-Code-Here {sort.SimpleCounter.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods:
  /**
   * Set the count to zero.
   */
  public void reset_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.reset)
    d_count = 0;
    return ;
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter.reset)

  }

  /**
   * Return the current count.
   */
  public int getCount_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.getCount)
    // insert implementation here
    return d_count;
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter.getCount)

  }

  /**
   * Increment the count (i.e. add one).
   */
  public int inc_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SimpleCounter.inc)
    // insert implementation here
    return ++d_count;
    // DO-NOT-DELETE splicer.end(sort.SimpleCounter.inc)

  }


  // DO-NOT-DELETE splicer.begin(sort.SimpleCounter._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(sort.SimpleCounter._misc)

} // end class SimpleCounter

