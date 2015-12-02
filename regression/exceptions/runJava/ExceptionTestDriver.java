// 
// File:        ExceptionTestDriver.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6173 $
// Date:        $Date: 2007-10-10 20:53:56 -0700 (Wed, 10 Oct 2007) $
// Description: exception regression test case for Java calling other languages
// 

/**
 * The following class runs the exception regression test cases for Java.
 */
public class ExceptionTestDriver {

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

  private static void tests(synch.RegOut tracker)
  {
    /*
     * No exception thrown
     */
    ExceptionTest.Fib fib = new ExceptionTest.Fib();
    try {
      fib.getFib(10, 25, 200, 0);
      startTest(null);
      check(synch.ResultType.PASS, 
            true, 
            "no exception thrown (none expected)");
    } catch (java.lang.Exception ex) {
      startTest(null);
      check(synch.ResultType.PASS, 
            false, 
            "unexpected exception thrown");
    }

    /*
     * Throw a NegativeValueException
     */

    try {
      fib.getFib(-1, 10, 10, 0);
      startTest(null);
      check(synch.ResultType.PASS, 
            false, 
            "no exception (NegativeValueException expected)");
    } catch (java.lang.Exception ex) {
      
      if (((sidl.BaseException)ex).isType("ExceptionTest.NegativeValueException")) {
        startTest(null);
        check(synch.ResultType.PASS, 
              true, 
              "NegativeValueException thrown (as expected)");
      } else {
        startTest(null);
        check(synch.ResultType.PASS, 
              false, 
              "unexpected sidl exception thrown");
      }
    }

    /*
     * Throw a TooDeepException 
     */

    try {
      fib.getFib(10, 1, 1000, 0);
      startTest(null);
      check(synch.ResultType.PASS, 
            false, 
            "no exception (TooDeepException expected)");
    } catch (java.lang.Exception ex) {
      if (((sidl.SIDLException)ex).isType("ExceptionTest.TooDeepException")) {
        startTest(null);
        check(synch.ResultType.PASS, 
              true, 
              "TooDeepException thrown (as expected)");
      } else {
        startTest(null);
        check(synch.ResultType.PASS, 
              false, 
              "unexpected exception thrown");
      }
    }

    /*
     * Throw a TooBigException 
     */

    try {
      fib.getFib(10, 1000, 1, 0);
      startTest(null);
      check(synch.ResultType.PASS, 
            false, 
            "no exception (TooBigException expected)");
    } catch (java.lang.Exception ex) {
      if (((sidl.SIDLException)ex).isType("ExceptionTest.TooBigException")) {
        startTest(null);
        check(synch.ResultType.PASS, 
              true, 
              "TooBigException thrown (as expected)");
      } else {
        startTest(null);
        check(synch.ResultType.PASS, 
              false, 
              "unexpected exception thrown");
      }
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
      tracker.setExpectations(-1);
      s_part   = 0;
      s_result = synch.ResultType.PASS;

      tests(tracker);
      System.gc(); Thread.sleep(5); // try to force the garbage collector 
      
      /*
       * Output final test results
       */
      tracker.close();
      tracker = null;
      System.gc(); Thread.sleep(50); // try to force the garbage collector 
      System.gc(); Thread.sleep(50); // try to force the garbage collector 
      System.gc(); Thread.sleep(50); // try to force the garbage collector 
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
