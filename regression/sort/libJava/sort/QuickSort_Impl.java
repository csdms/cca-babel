/*
 * File:          QuickSort_Impl.java
 * Symbol:        sort.QuickSort-v0.1
 * Symbol Type:   class
 * Babel Version: 1.4.0 (Revision: 6563M trunk)
 * Description:   Server-side implementation for sort.QuickSort
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

// DO-NOT-DELETE splicer.begin(sort.QuickSort._imports)
// Put additional imports here...
// DO-NOT-DELETE splicer.end(sort.QuickSort._imports)

/**
 * Symbol "sort.QuickSort" (version 0.1)
 * 
 * Quick sort
 */
public class QuickSort_Impl extends QuickSort
{

  // DO-NOT-DELETE splicer.begin(sort.QuickSort._data)
  int choosePivot(sort.Container  elems,
                sort.Comparator comp,
                sort.Counter    cmp,
                int         start,
                int         end)
  {
    int pivot = (start + end) >> 1;
    if ((end - start) > 4) {
      int mid = pivot;
      cmp.inc();
      if (elems.compare(start, mid, comp) <= 0) {
        cmp.inc();
        if (elems.compare(mid, end - 1, comp) > 0) {
          cmp.inc();
          if (elems.compare(start, end - 1, comp) < 0) {
            pivot = end - 1;
          }
          else {
            pivot = start;
          }
        }
      }
      else {
        cmp.inc();
        if (elems.compare(mid, end - 1, comp) < 0) {
          cmp.inc();
          if (elems.compare(start, end - 1, comp) > 0) {
            pivot = end - 1;
          }
          else {
            pivot = start;
          }
        }
      }
    }
    return pivot;
  }
  
  void quickSort(sort.Container  elems,
              sort.Comparator comp,
              sort.Counter    cmp,
              sort.Counter    swp,
              int         start,
              int         end)
  {
    if ((end - start) > 1) {
      int pivot = choosePivot(elems, comp, cmp, start, end);
      int i = start;
      int j = end;
      if (pivot != start) {
        swp.inc();
        elems.swap(start, pivot);
      }
      for(;;) {
        do {
          --j;
          cmp.inc();
        } while (elems.compare(start, j, comp) < 0);
        while (++i < j) {
          cmp.inc();
          if (elems.compare(start, i, comp) < 0) break;
        }
        if (i >= j) break;
        swp.inc();
        elems.swap(i, j);
      }
      if (j != start) {
        swp.inc();
        elems.swap(start, j);
      }
      quickSort(elems, comp, cmp, swp, start, j);
      quickSort(elems, comp, cmp, swp, j + 1, end);
    }
  }

  // Put additional private data here...
  // DO-NOT-DELETE splicer.end(sort.QuickSort._data)


  static { 
  // DO-NOT-DELETE splicer.begin(sort.QuickSort._load)
  // Put load function implementation here...
  // DO-NOT-DELETE splicer.end(sort.QuickSort._load)

  }

  /**
   * User defined constructor
   */
  public QuickSort_Impl(long IORpointer){
    super(IORpointer);
    // DO-NOT-DELETE splicer.begin(sort.QuickSort.QuickSort)
    // add construction details here
    // DO-NOT-DELETE splicer.end(sort.QuickSort.QuickSort)

  }

  /**
   * Back door constructor
   */
  public QuickSort_Impl(){
    d_ior = _wrap(this);
    // DO-NOT-DELETE splicer.begin(sort.QuickSort._wrap)
    // Insert-Code-Here {sort.QuickSort._wrap} (_wrap)
    // DO-NOT-DELETE splicer.end(sort.QuickSort._wrap)

  }

  /**
   * User defined destructing method
   */
  public void dtor() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.QuickSort._dtor)
    // add destruction details here
    // DO-NOT-DELETE splicer.end(sort.QuickSort._dtor)

  }

  /**
   * finalize method (Only use this if you're sure you need it!)
   */
  public void finalize() throws Throwable{
    // DO-NOT-DELETE splicer.begin(sort.QuickSort.finalize)
    // Insert-Code-Here {sort.QuickSort.finalize} (finalize)
    // DO-NOT-DELETE splicer.end(sort.QuickSort.finalize)

  }

  // user defined static methods: (none)

  // user defined non-static methods:
  /**
   * Sort elements using Quick Sort.
   */
  public void sort_Impl (
    /*in*/ sort.Container elems,
    /*in*/ sort.Comparator comp ) 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.QuickSort.sort)
    // insert implementation here
    int num = elems.getLength();
    sort.Counter cmp = getCompareCounter();
    sort.Counter swp = getSwapCounter();
    quickSort(elems, comp, cmp, swp, 0, num);
    return ;
    // DO-NOT-DELETE splicer.end(sort.QuickSort.sort)

  }

  /**
   * Return quick sort.
   */
  public java.lang.String getName_Impl () 
    throws sidl.RuntimeException.Wrapper
  {
    // DO-NOT-DELETE splicer.begin(sort.QuickSort.getName)
    // insert implementation here
    return new java.lang.String("Quick sort");
    // DO-NOT-DELETE splicer.end(sort.QuickSort.getName)

  }


  // DO-NOT-DELETE splicer.begin(sort.QuickSort._misc)
  // Put miscellaneous code here
  // DO-NOT-DELETE splicer.end(sort.QuickSort._misc)

} // end class QuickSort

