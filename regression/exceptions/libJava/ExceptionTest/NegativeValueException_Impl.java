/*
 * File:          NegativeValueException_Impl.java
 * Symbol:        ExceptionTest.NegativeValueException-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6563M trunk)
 * Description:   Server-side implementation for ExceptionTest.NegativeValueException
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package ExceptionTest;

import sidl.BaseClass;
import sidl.BaseException;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sidl.SIDLException;
import sidl.io.Deserializer;
import sidl.io.Serializable;
import sidl.io.Serializer;

// DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._imports)

/**
 * Symbol "ExceptionTest.NegativeValueException" (version 1.0)
 * 
 * This exception is thrown if the value for which the Fibonacci number
 * is requested is negative.
 */
public class NegativeValueException_Impl extends NegativeValueException
{

  // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._data)
  // Put additional private data here...
  // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._data)


  static { 
  // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._load)

  }

  /**
   * User defined constructor
   */
  public NegativeValueException_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException.NegativeValueException)
    // add construction details here
    // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException.NegativeValueException)

  }

  /**
   * Back door constructor
   */
  public NegativeValueException_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._wrap)
    // Insert-Code-Here {ExceptionTest.NegativeValueException._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException.finalize)
    // Insert-Code-Here {ExceptionTest.NegativeValueException.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods: (none)

  // DO-NOT-DELETE splicer.begin(ExceptionTest.NegativeValueException._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(ExceptionTest.NegativeValueException._misc)

} // end class NegativeValueException

