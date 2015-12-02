//
// File:        SortTest.java
// Package:     
// Copyright:   (c) 2002 Lawrence Livermore National Security, LLC
// Revision:    @(#) $Revision: 6173 $
// Date:        $Date: 2007-10-10 20:53:56 -0700 (Wed, 10 Oct 2007) $
// Description: Regression test for sorting and abstract classes
// 

public class SortTest {

  private final static String[] s_results = {
    "synch.ResultType.PASS",
    "FAIL",
    "XFAIL",
    "Xsynch.ResultType.PASS",
  };

  private static int s_part = 0;
  private static long s_result = synch.ResultType.PASS;
  private static synch.RegOut tracker = new synch.RegOut();  
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
    sort.SortingAlgorithm.Array1 algs = 
      new sort.SortingAlgorithm.Array1(3,true); 
     
    sort.MergeSort merge = new sort.MergeSort();
    sort.HeapSort heap = new sort.HeapSort();
    sort.QuickSort quick = new sort.QuickSort();

    startTest(null);
    check(synch.ResultType.PASS, (merge != null), "(merge != null)");
    startTest(null);
    check(synch.ResultType.PASS, (heap != null), "(heap != null)");
    startTest(null);
    check(synch.ResultType.PASS, (quick != null), "(quick != null)");
    algs.set(0, (sort.SortingAlgorithm)merge);
    algs.set(1, (sort.SortingAlgorithm)heap);
    algs.set(2, (sort.SortingAlgorithm)quick);
    
    System.out.println(((sort.SortingAlgorithm)merge).getName());
      

    startTest(null);
    check(synch.ResultType.PASS, sort.SortTest.stressTest(algs), "Stress Test!");
  }


  public static void main(String args[]) {
    try {
      tracker = new synch.RegOut();
      tracker.setExpectations(-1);
      s_part = 0;
      s_result = synch.ResultType.PASS;
      tests(tracker);
      System.gc(); Thread.sleep(5);

      tracker.close();
      tracker = null;
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      System.gc(); Thread.sleep(50);
      Runtime.getRuntime().exit(0); /* workaround for Linux JVM 1.3.1 bug */
    }
    catch (Throwable ex) {
      tracker.close();
      //System.out.println("TEST_RESULT FAIL");
      //System.out.println(ex.toString());
      ex.printStackTrace(System.err);
      System.exit(1);
      
    }
  }
}
