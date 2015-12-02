// 
// File:        InheritTest.java
// Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6325 $
// Date:        $Date: 2008-02-07 10:43:32 -0800 (Thu, 07 Feb 2008) $
// Description: inherit regression test case for Java calling other languages
// 

/**
 * The following class runs the inherit regression test cases for Java.
 */
public class InheritTest {

  private final static String[] s_results = {
    "FAIL",
    "XFAIL",
    "synch.ResultType.PASS",
    "Xsynch.ResultType.PASS",
    "UNSUPPORTED"
  };

  private static int s_part = 0;
  private static long s_result = synch.ResultType.PASS;

  private static boolean scomp(String a, String b) {
    if(a.compareTo(b) == 0)
      return true;
    else 
      return false;
  }

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
     * Test Class C
     */
    if (true) {
      Inherit.C c = new Inherit.C();
      startTest(null);
      check(synch.ResultType.PASS, scomp(c.c(),"C.c"), "C.c");
    }

    /*
     * Test Class D
     */
    if (true) {
      Inherit.D d = new Inherit.D();
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.a(),"D.a"), "D.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.d(),"D.d"), "D.d");
      Inherit.A a = d;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"D.a"), "D.a");
    }

    /*
     * Test Class E
     */
    if (true) {
      Inherit.E e = new Inherit.E();
      startTest(null);
      check(synch.ResultType.PASS,scomp(e.c(),"C.c"), "C.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(e.e(),"E.e"), "E.e");
      Inherit.C c = e;
      startTest(null);
      check(synch.ResultType.PASS,scomp(c.c(),"C.c"), "C.c");
    }
    
    /*
     * Test Class E2
     */
    if (true) {
      Inherit.E2 e2 = new Inherit.E2();
      startTest(null);
      check(synch.ResultType.PASS,scomp(e2.c(),"E2.c"), "E2.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(e2.e(),"E2.e"), "E2.e");
      Inherit.C c = e2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(c.c(),"E2.c"), "E2.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(Inherit.E2.m(), "E2.m"), "E2.m");
    }

    /*
     * Test Class F
     */
    if (true) {
      Inherit.F f = new Inherit.F();
      startTest(null);
      check(synch.ResultType.PASS,scomp(f.a(),"F.a"), "F.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f.b(),"F.b"), "F.b");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f.c(),"C.c"), "C.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f.f(),"F.f"), "F.f");
      Inherit.A a = f;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"F.a"), "F.a");
      Inherit.B b = f;
      startTest(null);
      check(synch.ResultType.PASS,scomp(b.b(),"F.b"), "F.b");
      Inherit.C c = f;
      startTest(null);
      check(synch.ResultType.PASS,scomp(c.c(),"C.c"), "C.c");
    }

    /*
     * Test Class F2
     */
    if (true) {
      Inherit.F2 f2 = new Inherit.F2();
      startTest(null);
      check(synch.ResultType.PASS,scomp(f2.a(),"F2.a"), "F2.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f2.b(),"F2.b"), "F2.b");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f2.c(),"F2.c"), "F2.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(f2.f(),"F2.f"), "F2.f");
      Inherit.A a = f2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"F2.a"), "F2.a");
      Inherit.B b = f2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(b.b(),"F2.b"), "F2.b");
      Inherit.C c = f2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(c.c(),"F2.c"), "F2.c");
    }

    /*
     * Test Class G
     */
    if (true) {
      Inherit.G g = new Inherit.G();
      startTest(null);
      check(synch.ResultType.PASS,scomp(g.a(),"D.a"), "D.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(g.d(),"D.d"), "D.d");
      startTest(null);
      check(synch.ResultType.PASS,scomp(g.g(),"G.g"), "G.g");
      Inherit.A a = g;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"D.a"), "D.a");
      Inherit.D d = g;
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.a(),"D.a"), "D.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.d(),"D.d"), "D.d");
    }

    /*
     * Test Class G
     */
    if (true) {
      Inherit.G2 g2 = new Inherit.G2();
      startTest(null);
      check(synch.ResultType.PASS,scomp(g2.a(),"G2.a"), "G2.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(g2.d(),"G2.d"), "G2.d");
      startTest(null);
      check(synch.ResultType.PASS,scomp(g2.g(),"G2.g"), "G2.g");
      Inherit.A a = g2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"G2.a"), "G2.a");
      Inherit.D d = g2;
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.a(),"G2.a"), "G2.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(d.d(),"G2.d"), "G2.d");
    }

    /*
     * Test Class I
     */
    if (true) {
      Inherit.I i = new Inherit.I();
      startTest(null);
      check(synch.ResultType.PASS,scomp(i.a(),"I.a"), "I.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(i.h(),"I.h"), "I.h");
      Inherit.A a = i;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"I.a"), "I.a");
      Inherit.H h = i;
      startTest(null);
      check(synch.ResultType.PASS,scomp(h.a(),"I.a"), "I.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(h.h(),"I.h"), "I.h");
    }
      
    /*
     * Test Class J
     */
    if (true) {
      Inherit.J j = new Inherit.J();
      startTest(null);
      check(synch.ResultType.PASS,scomp(j.a(),"J.a"), "J.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(j.b(),"J.b"), "J.b");
      startTest(null);
      check(synch.ResultType.PASS,scomp(j.j(),"J.j"), "J.j");
      startTest(null);
      check(synch.ResultType.PASS,scomp(j.c(),"J.E2.c"), "J.E2.c");
      startTest(null);
      check(synch.ResultType.PASS,scomp(j.e(),"J.E2.e"), "J.E2.e");
      startTest(null);
      check(synch.ResultType.PASS,scomp(Inherit.J.m(), "E2.m"), "J.m");
    } 

    /*
     * Test Class K
     */
    if (true) {
      Inherit.K k = new Inherit.K();
      startTest(null);
      check(synch.ResultType.PASS,scomp(k.a(),"K.a"), "K.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(k.a(0),"K.a2"), "K.a2");
      startTest(null);
      check(synch.ResultType.PASS,scomp(k.k(),"K.k"), "K.k");
      startTest(null);
      check(synch.ResultType.PASS,scomp(k.h(),"K.h"), "K.h");
      Inherit.A a = k;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"K.a"), "K.a");
      Inherit.A2 a2 = k;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a2.a(0),"K.a2"), "K.a2");
      
      Inherit.H h = k;
      startTest(null);
      check(synch.ResultType.PASS,scomp(h.a(),"K.a"), "K.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(h.h(),"K.h"), "K.h");
    }


    /*
     * Test Class L
     */
    if (true) {
      Inherit.L l = new Inherit.L();
      startTest(null);
      check(synch.ResultType.PASS,scomp(l.a(),"L.a"), "L.a");
      startTest(null);
      check(synch.ResultType.PASS,scomp(l.a(0),"L.a2"), "L.a2");
      startTest(null);
      check(synch.ResultType.PASS,scomp(l.l(),"L.l"), "L.l");
      
      Inherit.A a = l;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a.a(),"L.a"), "L.a");
      Inherit.A2 a2 = l;
      startTest(null);
      check(synch.ResultType.PASS,scomp(a2.a(0),"L.a2"), "L.a2");
      
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
      System.gc(); Thread.sleep(5); //try to force garbage collector to run
      /*
       * Output final test results
       */
      tracker.close();
      //System.out.println("TEST_RESULT " + s_results[s_result]);
      tracker = null;
      System.gc(); Thread.sleep(50); //try to force garbage collector to run
      System.gc(); Thread.sleep(50); //try to force garbage collector to run
      System.gc(); Thread.sleep(50); //try to force garbage collector to run

      Runtime.getRuntime().exit(0); /* workaround for Linux JVM 1.3.1 bug */
      /*
       * Catch any unexpected exceptions and return a test failure
       */
    } catch (Throwable ex) {
      if (tracker != null ) {
        tracker.forceFailure();
        tracker.close();
      }
      //System.out.println("TEST_RESULT FAIL");
      System.out.println(ex.toString());
      ex.printStackTrace();
      System.exit(1);
    }
  }
}
