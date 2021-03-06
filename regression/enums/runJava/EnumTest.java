// 
// File:        EnumTest.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6393 $
// Date:        $Date: 2008-05-23 15:39:52 -0700 (Fri, 23 May 2008) $
// Description: enum regression test case for Java calling other languages
// 

/**
 * The following class runs the enum regression test cases for Java.
 */
public class EnumTest {
  private final static String[] s_results = {
    "FAIL",
    "XFAIL",
    "synch.ResultType.PASS",
    "Xsynch.ResultType.PASS",
    "UNSUPPORTED"
  };

  private static int s_part = 0;
  private static long s_result = synch.ResultType.PASS;

  private static synch.RegOut tracker; 
  /**
   * Check the results of the test case.
   */
  //Comments should really be passed in here.
  private static void startTest(String test) {
    tracker.startPart(++s_part);
    if(test != null)
      tracker.writeComment(test);
  }

  private static void check(long expected, boolean pass, String test ) {
    if (test != null)
      tracker.writeComment(test);

    if(expected == synch.ResultType.PASS)
      if(pass)
        tracker.endPart(s_part, synch.ResultType.PASS);
      else
        tracker.endPart(s_part, synch.ResultType.FAIL);
    else if (expected == synch.ResultType.XFAIL)
      if(pass)
        tracker.endPart(s_part, synch.ResultType.XPASS);
      else
        tracker.endPart(s_part, synch.ResultType.XFAIL);
    else
      tracker.endPart(s_part, synch.ResultType.FAIL);
  }

  private static sidl.Enum.Array1 createArray()
  {
    sidl.Enum.Array1 result = new sidl.Enum.Array1(0, 2, false);
    result.set(0, enums.car.ford);
    result.set(1, enums.car.mercedes);
    result.set(2, enums.car.porsche);
    return result;
  }

  private static boolean checkArray(sidl.Enum.Array1 src)
  {
    boolean result = (src != null) && (src.length() == 3);
    if (result) {
      final long [] vals = { 
        enums.car.ford, enums.car.mercedes, enums.car.porsche 
      };
      for(int i = 0; i < vals.length; ++i ) {
        result = result &&
          (src.get(i + src.lower(0)) == vals[i]);
      }
    }
    return result;
  }
    

  private static void tests(synch.RegOut tracker)
  {
    /*
     * Look at the pretty colors...
     */
    if (true) {
      sidl.Enum.Holder out   = new sidl.Enum.Holder(0);
      sidl.Enum.Holder inout = new sidl.Enum.Holder(enums.color.green);
      
      enums.colorwheel obj = new enums.colorwheel();
      
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.returnback() == enums.color.violet),
            "(obj.returnback() == enums.color.violet)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passin(enums.color.blue) == true),
            "(obj.passin(enums.color.blue) == true)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passout(out) == true && out.get() == enums.color.violet),
            "(obj.passout(out) == true && out.get() == enums.color.violet)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passinout(inout) == true
             && inout.get() == enums.color.red),
            "(obj.passinout(inout) == true "
            + " && inout.get() == enums.color.red)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passeverywhere(enums.color.blue, out, inout) ==
             enums.color.violet 
             && out.get() == enums.color.violet
             && inout.get() == enums.color.green),
            "(obj.passeverywhere(enums.color.blue, out, inout) =="
            +     " enums.color.violet"
            + " && out.get() == enums.color.violet"
            + " && inout.get() == enums.color.green)");
    }
    
    /*
     * I want a porsche - zoom, zoom...
     */
    if (true) {
      sidl.Enum.Holder out   = new sidl.Enum.Holder(0);
      sidl.Enum.Holder inout = new sidl.Enum.Holder(enums.car.ford);
      
      enums.cartest obj = new enums.cartest();
      
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.returnback() == enums.car.porsche),
            "(obj.returnback() == enums.car.porsche)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passin(enums.car.mercedes) == true),
            "(obj.passin(enums.car.mercedes) == true)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passout(out) == true && out.get() == enums.car.ford),
            "(obj.passout(out) == true && out.get() == enums.car.ford)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passinout(inout) == true
             && inout.get() == enums.car.porsche),
            "(obj.passinout(inout) == true "
            + " && inout.get() == enums.car.porsche)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passeverywhere(enums.car.mercedes, out, inout) ==
             enums.car.porsche
             && out.get() == enums.car.ford
             && inout.get() == enums.car.mercedes),
            "(obj.passeverywhere(enums.car.mercedes, out, inout) =="
            +     " enums.car.porsche"
            + " && out.get() == enums.car.ford"
            + " && inout.get() == enums.car.mercedes)");
      startTest(null);
      sidl.Enum.Array1 tin, tret;
      sidl.Enum.Array1.Holder tinout = new sidl.Enum.Array1.Holder(), 
        tout = new sidl.Enum.Array1.Holder();
      tin = createArray(); 
      tinout.set(createArray());
      tracker.writeComment("Calling enums.cartest.passarray");
      tret = obj.passarray(tin, tout, tinout);
      check(synch.ResultType.PASS,
            checkArray(tin) && checkArray(tret) &&
            checkArray(tinout.get()) && checkArray(tout.get()),
            "checkArray(tin) && checkArray(tret) && checkArray(tinout.get()) && checkArray(tout.get())");
    }
    
    /*
     * When I started programming, we only had zeros...
     */
    if (true) {
      sidl.Enum.Holder out   = new sidl.Enum.Holder(0);
      sidl.Enum.Holder inout = new sidl.Enum.Holder(enums.number.zero);
      
      enums.numbertest obj = new enums.numbertest();
      
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.returnback() == enums.number.notOne),
            "(obj.returnback() == enums.number.notOne)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passin(enums.number.notZero) == true),
            "(obj.passin(enums.number.notZero) == true)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passout(out) == true && out.get() == enums.number.negOne),
            "(obj.passout(out) == true && out.get() == enums.number.negOne)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passinout(inout) == true
             && inout.get() == enums.number.notZero),
            "(obj.passinout(inout) == true "
            + " && inout.get() == enums.number.notZero)");
      startTest(null);
      check(synch.ResultType.PASS,
            (obj.passeverywhere(enums.number.notZero, out, inout) ==
             enums.number.notOne
             && out.get() == enums.number.negOne
             && inout.get() == enums.number.zero),
            "(obj.passeverywhere(enums.number.notZero, out, inout) =="
            +     " enums.number.notOne"
            + " && out.get() == enums.number.negOne"
            + " && inout.get() == enums.number.zero)");
    }
    
    if (true) {
      int[] numElem = {2};
      int[] stride = {2};
      sidl.Enum.Array1 enumArray = new sidl.Enum.Array1(4, true);
      sidl.Enum.Array1 slicedArray = null;
      sidl.Enum.Array1 cpArray = null;
      startTest(null);
      check(synch.ResultType.PASS, enumArray != null, "enumArray != null"); 
      enumArray.set(0, enums.car.porsche);
      enumArray.set(1, enums.car.ford);
      enumArray.set(2, enums.car.mercedes);
      enumArray.set(3, enums.car.porsche);
      startTest(null);
      check(synch.ResultType.PASS, enumArray.get(0) == enums.car.porsche,
            "Element 0 is a porsche!"); 
      startTest(null);
      check(synch.ResultType.PASS, enumArray.get(1) == enums.car.ford,
            "Element 1 is a ford!");
      startTest(null);
      check(synch.ResultType.PASS, enumArray.get(2) == enums.car.mercedes,
            "Element 2 is a mercedes!");
      startTest(null);
      check(synch.ResultType.PASS, enumArray.get(3) == enums.car.porsche,
            "Element 3 is a porsche!");
      
      slicedArray = (sidl.Enum.Array1) enumArray._slice(1, numElem, (int[])null, stride, (int[])null)._dcast();
      startTest(null);
      check(synch.ResultType.PASS, slicedArray != null, "Sliced Array is not null");
      startTest(null);
      check(synch.ResultType.PASS, slicedArray.get(0) == enums.car.porsche,
            "Sliced Array Element 0 is a porche!"); 
      startTest(null);
      check(synch.ResultType.PASS, slicedArray.get(1) == enums.car.mercedes,
            "Sliced Array Element 1 is a mercedes!");
      cpArray = slicedArray.smartCopy();
      
      startTest(null);
      check(synch.ResultType.PASS, cpArray != null, "Copied Array is not null");
      startTest(null);
      check(synch.ResultType.PASS, cpArray._get(0) == enums.car.porsche,
            "Copied Array Element 0 is a porche!"); 
      startTest(null);
      check(synch.ResultType.PASS, cpArray._get(1) == enums.car.mercedes,
            "Copied Array Element 1 is a mercedes!");
      cpArray._deallocate();
      slicedArray._deallocate();
      enumArray._deallocate();
      
      
    }
    
  }


  /**
   * The main test driver takes no command-line arguments and runs the
   * regression tests.
   */
  public static void main(String args[]) {
    try {
      /*
       * Begin the test
       */
      tracker = new synch.RegOut();
      tracker.setExpectations(27);


      s_part   = 0;
      s_result = synch.ResultType.PASS;

      tests(tracker);
      System.gc(); Thread.sleep(50);

      /*
       * Output final test results
       */
      tracker.close();
      tracker = null;
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      //System.out.println("TEST_RESULT " + s_results[s_result]);

      Runtime.getRuntime().exit(0); /* workaround for Linux JVM 1.3.1 bug */
      /*
       * Catch any unexpected exceptions and return a test failure
       */
    } catch (Throwable ex) {
      tracker.close();
      //System.out.println("TEST_RESULT FAIL");
      System.out.println(ex.toString());
      System.exit(1);
    }
  }
}
