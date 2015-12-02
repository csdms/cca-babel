// 
// File:        OverloadTestDriver.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6173 $
// Date:        $Date: 2007-10-10 20:53:56 -0700 (Wed, 10 Oct 2007) $
// Description: overload regression test case for Java calling other languages
// 

/**
 * The following class runs the exception regression test cases for Java.
 */
public class OverloadTestDriver {


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

  private static void tests(synch.RegOut tracker) 
  {
    boolean b1   = true;
    int     i1   = 1;
    double  d1   = 1.0;
    float   f1   = 1.0F;
    double  did  = 2.0;
    double  difd = 3.0;
    String  s1   = "AnException";

    sidl.DoubleComplex dcret = null;
    sidl.DoubleComplex dc1   = new sidl.DoubleComplex(1.1, 1.1);
    sidl.FloatComplex  fcret = null;
    sidl.FloatComplex  fc1   = new sidl.FloatComplex(2.2F, 2.2F);

    Overload.Test t = new Overload.Test();

    if (t != null) {
      /*
       * Zero argument test
       */
      startTest(null);
      check(synch.ResultType.PASS, t.getValue() == 1, "Zero arguments, expecting a 1");

      /*
       * One-argument tests
       */
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(b1) == b1, "boolean argument");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(d1) == d1, "double argument");
      dcret = t.getValue(dc1);
      startTest(null);
      check(synch.ResultType.PASS, dcret.real() == dc1.real() && dcret.imag() == dc1.imag(), 
            "dcomplex argument");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(f1) == f1, "float argument");
      fcret = t.getValue(fc1);
      startTest(null);
      check(synch.ResultType.PASS, fcret.real() == fc1.real() && fcret.imag() == fc1.imag(), 
            "fcomplex argument");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(i1) == i1, "integer argument");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(s1).equals(s1), "string argument");
      
      Overload.AnException ae = new Overload.AnException();
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(ae).equals(s1), "AnException argument");
      
      Overload.AClass ac = new Overload.AClass();
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(ac) == 2, "AClass argument");
      
      Overload.BClass bc = new Overload.BClass();
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(bc) == 2, "BClass argument");
      
      /*
       * Two-argument tests
       */
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(d1, i1) == did, "Double, Int arguments");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(i1, d1) == did, "Int, Double arguments");
      
      /*
       * Three-argument tests
       */
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(d1, i1, f1) == difd, 
            "Double, Int, Float args");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(i1, d1, f1) == difd, 
            "Int, Double, Float args");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(d1, f1, i1) == difd, 
            "Double, Float, Int args");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(i1, f1, d1) == difd, 
            "Int, Float, Double args");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(f1, d1, i1) == difd, 
            "Float, Double, Int args");
      startTest(null);
      check(synch.ResultType.PASS, t.getValue(f1, i1, d1) == difd, 
            "Float, Int, Double args");
    } else {
      tracker.forceFailure();
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
      System.gc(); Thread.sleep(5);

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

    } catch (Throwable ex) {
      /*
       * Catch any unexpected exceptions and return a test failure
       */
      tracker.close();
      //System.out.println("TEST_RESULT FAIL");
      System.out.println(ex.toString());
      System.exit(1);
    }
  }
}
