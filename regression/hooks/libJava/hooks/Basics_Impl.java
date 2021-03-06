/*
 * File:          Basics_Impl.java
 * Symbol:        hooks.Basics-v1.0
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6561M trunk)
 * Description:   Server-side implementation for hooks.Basics
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package hooks;

import sidl.BaseClass;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;

// DO-NOT-DELETE splicer.begin(hooks.Basics._imports)
// Insert-Code-Here {hooks.Basics._imports} (additional imports)
// DO-NOT-DELETE splicer.end(hooks.Basics._imports)

/**
 * Symbol "hooks.Basics" (version 1.0)
 */
public class Basics_Impl extends Basics
{

  // DO-NOT-DELETE splicer.begin(hooks.Basics._data)
  // Insert-Code-Here {hooks.Basics._data} (private data)
  // DO-NOT-DELETE splicer.end(hooks.Basics._data)


  static { 
  // DO-NOT-DELETE splicer.begin(hooks.Basics._load)
  // Insert-Code-Here {hooks.Basics._load} (class initialization)
  // DO-NOT-DELETE splicer.end(hooks.Basics._load)

  }

  /**
   * User defined constructor
   */
  public Basics_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(hooks.Basics.Basics)
    // Insert-Code-Here {hooks.Basics.Basics} (constructor)
    // DO-NOT-DELETE splicer.end(hooks.Basics.Basics)

  }

  /**
   * Back door constructor
   */
  public Basics_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(hooks.Basics._wrap)
    // Insert-Code-Here {hooks.Basics._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(hooks.Basics._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(hooks.Basics._dtor)
    // Insert-Code-Here {hooks.Basics._dtor} (destructor)
    // DO-NOT-DELETE splicer.end(hooks.Basics._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(hooks.Basics.finalize)
    // Insert-Code-Here {hooks.Basics.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(hooks.Basics.finalize)

  }

  // user defined static methods:
  /**
   * Basic illustration of hooks for static methods.
   */
  public static void aStaticMeth_pre_Impl (
    /*in*/ int i,
    /*in*/ int io ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth_pre)
    // Insert-Code-Here {hooks.Basics.aStaticMeth_pre} (aStaticMeth_pre)
    /*
     * This method has not been implemented
     */
    synch.RegOut tracker = synch.RegOut.getInstance();
    tracker.startPart(1);
    // DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth_pre)

  }

  /**
   * Basic illustration of hooks for static methods.
   */
  public static int aStaticMeth_Impl (
    /*in*/ int i,
    /*out*/ sidl.Integer.Holder o,
    /*inout*/ sidl.Integer.Holder io ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth)
    // Insert-Code-Here {hooks.Basics.aStaticMeth} (aStaticMeth)
    /*
     * This method has not been implemented
     */
    return 1;
    // DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth)

  }

  /**
   * Basic illustration of hooks for static methods.
   */
  public static void aStaticMeth_post_Impl (
    /*in*/ int i,
    /*in*/ int o,
    /*in*/ int io,
    /*in*/ int _retval ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aStaticMeth_post)
    // Insert-Code-Here {hooks.Basics.aStaticMeth_post} (aStaticMeth_post)
    /*
     * This method has not been implemented
     */
    synch.RegOut tracker = synch.RegOut.getInstance();
    tracker.endPart(1, synch.ResultType.PASS);

    // DO-NOT-DELETE splicer.end(hooks.Basics.aStaticMeth_post)

  }


  // user defined non-static methods:
  /**
   * Basic illustration of hooks for static methods.
   */
  public void aNonStaticMeth_pre_Impl (
    /*in*/ int i,
    /*in*/ int io ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth_pre)
    // Insert-Code-Here {hooks.Basics.aNonStaticMeth_pre} (aNonStaticMeth_pre)
    /*
     * This method has not been implemented
     */
    synch.RegOut tracker = synch.RegOut.getInstance();
    tracker.startPart(2);
    // DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth_pre)

  }

  /**
   * Basic illustration of hooks for static methods.
   */
  public int aNonStaticMeth_Impl (
    /*in*/ int i,
    /*out*/ sidl.Integer.Holder o,
    /*inout*/ sidl.Integer.Holder io ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth)
    // Insert-Code-Here {hooks.Basics.aNonStaticMeth} (aNonStaticMeth)
    /*
     * This method has not been implemented
     */
    return 1;

    // DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth)

  }

  /**
   * Basic illustration of hooks for static methods.
   */
  public void aNonStaticMeth_post_Impl (
    /*in*/ int i,
    /*in*/ int o,
    /*in*/ int io,
    /*in*/ int _retval ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(hooks.Basics.aNonStaticMeth_post)
    // Insert-Code-Here {hooks.Basics.aNonStaticMeth_post} (aNonStaticMeth_post)
    /*
     * This method has not been implemented
     */
    synch.RegOut tracker = synch.RegOut.getInstance();
    tracker.endPart(2, synch.ResultType.PASS);
    // DO-NOT-DELETE splicer.end(hooks.Basics.aNonStaticMeth_post)

  }


  // DO-NOT-DELETE splicer.begin(hooks.Basics._misc)
  // Insert-Code-Here {hooks.Basics._misc} (miscellaneous)
  // DO-NOT-DELETE splicer.end(hooks.Basics._misc)

} // end class Basics

