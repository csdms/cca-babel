// 
// File:        StringTest.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6173 $
// Date:        $Date: 2007-10-10 20:53:56 -0700 (Wed, 10 Oct 2007) $
// Description: string regression test case for Java calling other languages
// 

/**
 * The following class runs the string regression test cases for Java.
 */
public class StringTest {

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
    /*
     * Run the string tests
     */

    String             in    = "Three";
    sidl.String.Holder out   = new sidl.String.Holder();
    sidl.String.Holder inout = new sidl.String.Holder("Three");
    String             rbr   = null;
    
    Strings.Cstring obj = new Strings.Cstring();

    startTest(null);
    check(synch.ResultType.PASS,
          (obj.returnback(true).equals("Three")),
          "(obj.returnback(true).equals(\"Three\"))");
    rbr = obj.returnback(false);
    startTest(null);
    check(synch.ResultType.PASS,
          ((rbr == null) || rbr.equals("")),
          "(obj.returnback(false) == null)");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.passin(in) == true),
          "(obj.passin(in) == true)");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.passin(null) == false),
          "(obj.passin(null) == false)");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.passout(true,out) == true && out.get().equals("Three")),
          "(obj.passout(true,out) == true && out.get().equals(\"Three\"))");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.passinout(inout) == true && inout.get().equals("threes")),
          "(obj.passinout(inout) == true && inout.get().equals(\"threes\"))");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.passeverywhere(in , out, inout).equals("Three")
           && out.get().equals("Three")
           && inout.get().equals("Three")),
          "(obj.passeverywhere(in, out, inout).equals(\"Three\")"
          + " && out.get().equals(\"Three\")"
          + " && inout.get().equals(\"Three\"))");
    startTest(null);
    check(synch.ResultType.PASS,
          (obj.mixedarguments("Test", 'z', "Test", 'z')),
          "(obj.mixedarguments(\"Test\", 'z', \"Test\", 'z'))");
    startTest(null);
    check(synch.ResultType.PASS,
          (!obj.mixedarguments("Not", 'A', "Equal", 'a')),
          "(!obj.mixedarguments(\"Not\", 'A', \"Equal\", 'a'))");
    
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
      System.gc(); Thread.sleep(50); // try to force GC to run
      /*
       * Output final test results
       */
      tracker.close();
      tracker = null;
      System.gc(); Thread.sleep(50); // try to force GC to run
      System.gc(); Thread.sleep(50); // try to force GC to run
      System.gc(); Thread.sleep(50); // try to force GC to run
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
