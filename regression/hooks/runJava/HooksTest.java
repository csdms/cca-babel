// 
// File:        ArgsTest.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 4618 $
// Date:        $Date: 2005-05-09 15:54:29 -0700 (Mon, 09 May 2005) $
// Description: argument regression test case for Java calling other languages
// 

/**
 * The following class runs the argument regression test cases for Java.
 */
public class HooksTest {
  private final static int FAIL        = 0;
  private final static int XFAIL       = 1;
  private final static int PASS        = 2;
  private final static int XPASS       = 3;
  private final static int UNSUPPORTED = 4;

  private final static String[] s_results = {
    "FAIL",
    "XFAIL",
    "PASS",
    "XPASS",
    "UNSUPPORTED"
  };

  private static int s_part = 0;
  private static long s_result =  synch.ResultType.PASS;
  private static synch.RegOut tracker = null; 
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
    throws sidl.RuntimeException.Wrapper
  {
    hooks.Basics._set_hooks_static(true);
    /*
     * Boolean arguments
     */
    hooks.Basics obj = new hooks.Basics();
    obj._set_hooks(true);
      
    int test = 1;
    sidl.Integer.Holder b = new sidl.Integer.Holder(0);
    sidl.Integer.Holder c = new sidl.Integer.Holder(0);
    int ret = 0;

    ret = hooks.Basics.aStaticMeth(test, b, c);
    ++test; 
    b.set(0);
    c.set(0);
    ret = obj.aNonStaticMeth(test,b,c);
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
      tracker = synch.RegOut.getInstance();
      tracker.setExpectations(2);
      s_part   = 0;
      s_result = synch.ResultType.PASS;
      tests(tracker);
      System.gc(); Thread.sleep(5);
      tracker.close();
      tracker = null;
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      Runtime.getRuntime().exit(0); /* workaround for Linux JVM 1.3.1 bug */
      
      /*
       * Catch any unexpected exceptions and return a test failure
       */
    } catch (Throwable ex) {
      if (tracker != null) {
        tracker.forceFailure();
        tracker.close();
      }
      else {
        System.out.println("TEST_RESULT FAIL");
      }
      ex.printStackTrace();
      //System.out.println(ex.toString());
      //System.exit(1);
    }
  }
}
  
