/*
 * BabelDocException.java
 *
 * Created on February 20, 2004, 9:45 AM
 */

/**
 *
 * @author  jdurren
 */
package gov.llnl.babel.backend.html;

public class BabelDocException extends java.lang.Exception {

    /**
	 * 
	 */
	private static final long serialVersionUID = -2960884882516858050L;

	/**
     * Creates a new instance of <code>BabelDocException</code> without detail message.
     */
  public BabelDocException () {
  }

  /**
   * Constructs an instance of <code>BabelDocException</code> with the specified detail message.
   * @param msg the detail message.
   */ 
  public BabelDocException (String msg) {
    super (msg);
  }
}
