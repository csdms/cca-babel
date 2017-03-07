/*
 * File:          TooBigException_Impl.java
 * Symbol:        Exceptions.TooBigException-v1.0
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7436M trunk)
 * Description:   Server-side implementation for Exceptions.TooBigException
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package Exceptions;

import Exceptions.FibException;
import sidl.BaseClass;
import sidl.BaseException;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sidl.SIDLException;
import sidl.io.Deserializer;
import sidl.io.Serializable;
import sidl.io.Serializer;

// DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(Exceptions.TooBigException._imports)

/**
 * Symbol "Exceptions.TooBigException" (version 1.0)
 * 
 * This exception is thrown if the Fibonacci number is too large.
 */
public class TooBigException_Impl extends TooBigException
{

  // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._data)
  // Put additional private data here...
  // DO-NOT-DELETE splicer.end(Exceptions.TooBigException._data)


  static { 
  // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(Exceptions.TooBigException._load)

  }

  /**
   * User defined constructor
   */
  public TooBigException_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException.TooBigException)
    // add construction details here
    // DO-NOT-DELETE splicer.end(Exceptions.TooBigException.TooBigException)

  }

  /**
   * Back door constructor
   */
  public TooBigException_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._wrap)
    // Insert-Code-Here {Exceptions.TooBigException._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(Exceptions.TooBigException._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(Exceptions.TooBigException._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException.finalize)
    // Insert-Code-Here {Exceptions.TooBigException.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(Exceptions.TooBigException.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods: (none)

  // DO-NOT-DELETE splicer.begin(Exceptions.TooBigException._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(Exceptions.TooBigException._misc)

} // end class TooBigException

