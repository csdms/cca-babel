/*
 * File:          SortTest_Impl.java
 * Symbol:        sort.SortTest-v0.1
 * Symbol Type:   class
 * Babel Version: 2.0.0 (Revision: 7436M trunk)
 * Description:   Server-side implementation for sort.SortTest
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package sort;

import sidl.BaseClass;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sort.SortingAlgorithm;

// DO-NOT-DELETE splicer.begin(sort.SortTest._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(sort.SortTest._imports)

/**
 * Symbol "sort.SortTest" (version 0.1)
 * 
 * Run a bunch of sorts through a stress test.
 */
public class SortTest_Impl extends SortTest
{

  // DO-NOT-DELETE splicer.begin(sort.SortTest._data)
  static int[] s_testSizes = {  
  0,
  1,
  2,
  3,
  4,
  7,
  10,
  51,
  64,
  -1
};

  static boolean notSorted(sort.Container cont,
              sort.Comparator comp)
  {
    int length = cont.getLength();
    int i;
    for(i = 1 ; i < length ; ++i ){
      if (cont.compare(i-1, i, comp) > 0) return true;
    }
    return false;
  }

  static boolean sortAndReport(sort.SortingAlgorithm alg,
                     sort.Container cont,
                        sort.Comparator comp,
                        boolean result)
  {
   
    synch.RegOut tracker = synch.RegOut.getInstance();
    sort.Counter swpCnt = null;
    sort.Counter cmpCnt = null;
    alg.reset();
    alg.sort(cont, comp);
    swpCnt = alg.getSwapCounter();
    cmpCnt = alg.getCompareCounter();
    java.lang.String buffer = new 
      java.lang.String("compares ("+cmpCnt.getCount()+") swaps ("+swpCnt.getCount()+")");
    tracker.writeComment(buffer);
    if (notSorted(cont, comp)) {
      tracker.writeComment("sort failed!!");
      result = false;
    }
    return result;
  }

  // DO-NOT-DELETE splicer.end(sort.SortTest._data)


  static { 
  // DO-NOT-DELETE splicer.begin(sort.SortTest._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(sort.SortTest._load)

  }

  /**
   * User defined constructor
   */
  public SortTest_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(sort.SortTest.SortTest)
    // add construction details here
    // DO-NOT-DELETE splicer.end(sort.SortTest.SortTest)

  }

  /**
   * Back door constructor
   */
  public SortTest_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(sort.SortTest._wrap)
    // Insert-Code-Here {sort.SortTest._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(sort.SortTest._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SortTest._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(sort.SortTest._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.SortTest.finalize)
    // Insert-Code-Here {sort.SortTest.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(sort.SortTest.finalize)

  }

  // user defined static methods:
  /**
   * Perform the array stress test.
   * 
   * Return true if all the algorithms work okay.
   */
  public static boolean stressTest_Impl (
    /*in*/ sort.SortingAlgorithm.Array1 algs ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.SortTest.stressTest)
    // insert implementation here
    boolean result = false;
    if (algs != null) {
      int lower = algs._lower(0);
      int upper = algs._upper(0);
      int i,j;
      result = true;
      for(i = lower; i <= upper; ++i) {
        sort.SortingAlgorithm alg =
          algs.get(i);
        if (alg != null) {
          synch.RegOut tracker = synch.RegOut.getInstance();
          sort.IntegerContainer data = new sort.IntegerContainer();
          //sort.Container cont = (sort.Container) sort.Container.Wrapper._cast(data);
          sort.CompInt intcomp = new sort.CompInt();
          sort.Comparator comp = (sort.Comparator) sort.Comparator.Wrapper._cast(intcomp);
          java.lang.String name = alg.getName();
          java.lang.String buffer = null;
          j = 0;
          buffer = new java.lang.String("****ALGORITHM IS "+name+"****");
          tracker.writeComment(buffer);
          buffer = null;
          System.gc();
          while (s_testSizes[j] >= 0) {
            intcomp.setSortIncreasing(true);
            buffer = new java.lang.String("DATA SIZE " + s_testSizes[j]);
            tracker.writeComment(buffer);
            data.setLength(s_testSizes[j]);
            result = sortAndReport(alg, data, comp, result);
            tracker.writeComment("pre-sorted list");
            result = sortAndReport(alg, data, comp, result);
            tracker.writeComment("reverse sorted list");
            intcomp.setSortIncreasing(false);
            result = sortAndReport(alg, data, comp, result);
            ++j;
          }
          buffer = null;
        }
        else{
          result = false;
        }
      }
    }
    return result;
    
    // DO-NOT-DELETE splicer.end(sort.SortTest.stressTest)

  }


  // user defined non-static methods: (none)

  // DO-NOT-DELETE splicer.begin(sort.SortTest._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(sort.SortTest._misc)

} // end class SortTest

