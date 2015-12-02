/*
 * File:          MergeSort_Impl.java
 * Symbol:        sort.MergeSort-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6563M trunk)
 * Description:   Server-side implementation for sort.MergeSort
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

package sort;

import sidl.BaseClass;
import sidl.BaseInterface;
import sidl.ClassInfo;
import sidl.RuntimeException;
import sort.Comparator;
import sort.Container;
import sort.Counter;
import sort.SortingAlgorithm;

// DO-NOT-DELETE splicer.begin(sort.MergeSort._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(sort.MergeSort._imports)

/**
 * Symbol "sort.MergeSort" (version 0.1)
 * 
 * Merge sort
 */
public class MergeSort_Impl extends MergeSort
{

  // DO-NOT-DELETE splicer.begin(sort.MergeSort._data)
  static void
    mergeLists(sort.Container  elems,
               sort.Comparator comp,
               sort.Counter    cmp,
               sort.Counter    swp,
               int             start,
               int             mid,
               int             end)
{
  int j;
  while ((start < mid) && (mid < end)) {
    cmp.inc();
    if (elems.compare(start, mid, comp) > 0) {
      /* move first element of upper list into place */
      for(j = mid;j > start; --j) {
        swp.inc();
        elems.swap(j, j - 1);
      }
      ++mid;
    }
    ++start;
  }
}
  /**
 * end is one past the end
 */
  static void
    mergeSort(sort.Container  elems,
              sort.Comparator comp,
              sort.Counter    cmp,
              sort.Counter    swp,
              int             start,
              int             end)
{
  if ((end - start) > 1) {
    int mid = (start + end) >> 1;
    mergeSort(elems, comp, cmp, swp, start, mid);
    mergeSort(elems, comp, cmp, swp, mid, end);
    mergeLists(elems, comp, cmp, swp, start, mid, end);
  }
}

  // DO-NOT-DELETE splicer.end(sort.MergeSort._data)


  static { 
  // DO-NOT-DELETE splicer.begin(sort.MergeSort._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(sort.MergeSort._load)

  }

  /**
   * User defined constructor
   */
  public MergeSort_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(sort.MergeSort.MergeSort)
    // add construction details here
    // DO-NOT-DELETE splicer.end(sort.MergeSort.MergeSort)

  }

  /**
   * Back door constructor
   */
  public MergeSort_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(sort.MergeSort._wrap)
    // Insert-Code-Here {sort.MergeSort._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(sort.MergeSort._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.MergeSort._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(sort.MergeSort._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.MergeSort.finalize)
    // Insert-Code-Here {sort.MergeSort.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(sort.MergeSort.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods:
  /**
   * Sort elements using Merge Sort.
   */
  public void sort_Impl (
    /*in*/ sort.Container elems,
    /*in*/ sort.Comparator comp ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.MergeSort.sort)
    // insert implementation here
    int num = elems.getLength();
    sort.Counter cmp = getCompareCounter();
    sort.Counter swp = getSwapCounter();
    mergeSort(elems, comp, cmp, swp, 0, num);
    return ;
    // DO-NOT-DELETE splicer.end(sort.MergeSort.sort)

  }

  /**
   * Return merge sort.
   */
  public java.lang.String getName_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.MergeSort.getName)
    // insert implementation here
    return new java.lang.String("Merge sort");
    // DO-NOT-DELETE splicer.end(sort.MergeSort.getName)

  }


  // DO-NOT-DELETE splicer.begin(sort.MergeSort._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(sort.MergeSort._misc)

} // end class MergeSort

