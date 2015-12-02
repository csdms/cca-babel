// File:        BabelDoc.java
// Package:     gov.llnl.babel.backend.html
// Revision:    $Revision: 6482 $
// Modified:    $Date: 2008-08-21 15:50:53 -0700 (Thu, 21 Aug 2008) $
// Description: Code for creating documentation of the SIDL xml files
//
// Copyright (c) 2004, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory.
// Written by the Components Team <components@llnl.gov>
// UCRL-CODE-2002-054
// All rights reserved.
// 
// This file is part of Babel. For more information, see
// http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
// for Our Notice and the LICENSE file for the GNU Lesser General Public
// License.
// 
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License (as published by
// the Free Software Foundation) version 2.1 dated February 1999.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
// conditions of the GNU Lesser General Public License for more details.
// 
// You should have recieved a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA


/**
 *
 * @author  James Durrenberger
 */
package gov.llnl.babel.backend.html;

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.Context;
import gov.llnl.babel.ResourceLoader;
import gov.llnl.babel.backend.html.BabelDocException;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMResult;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import org.w3c.dom.DOMImplementation;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 * BabelDoc is used to create an html documentation of an XML definition of a SIDL
 * file and/or package similar to javadoc. The assumption is made that the XML file accurately
 * represent the sidl.dtd as we do non-validating parsing.
 */
public class BabelDoc {

  Context d_context;

  /** 
   * Static implemention of the <CODE>ResourceLoader</CODE> class
   * used to load the stylesheets from the jar file.
   */
  final private static ResourceLoader s_resLoader = new ResourceLoader ();

  /**
   * Package path for the stylesheets.
   */
  final private static String s_tranformHome = "gov/llnl/babel/backend/html/";

  /** 
   *  We do not allow the public creation of a BabelDoc object. 
   */
  public BabelDoc (Context context) {
    d_context = context;

  }

  /**
   * <CODE>docify</CODE> creates all the html files for the
   * xml reprresentation of the SIDL files. It does a slight
   * transformation to make some of the trnslations easier.
   * The dtd for the transformed document is as follows.
   *
   * <!ELEMENT Library (Package*|Symbol+)>
   * <!ATTLIST Library date CDATA #REQUIRED>
   *
   * <!ELEMENT Package (Comment, PackageSymbols, Classes, Interfaces,Enumerations)>
   * <!ATTLIST Package name CDATA #REQUIRED
   *                  version CDATA #REQUIRED>
   *
   * <!ELEMENT PackageSymbols (PackageSymbol)*>
   * <!ELEMENT Classes (Symbol)*>
   * <!ELEMENT Interface (Symbol)*>
   * <!ELEMENT Enumerations (Symbol)*>
   *
   * Where Symbol, PackageSymbol and Comment are defined in sidl.dtd
   *
   * This allows us to not have to open and read the seperate xml files
   * numerous times during the document creation.
   * @param fileNames Files which will be processed into html documentation
   * @throws TransformerException
   * @throws TransformerConfigurationException
   * @throws FileNotFoundException
   */

  public void docify (Object[]fileNames) throws BabelDocException
  {
    final String outputDir = getOutputDirectory();
    // short circuit if no filenames are found. this should be caught already, but just in case.
    if (fileNames.length == 0)  return;
    DocumentBuilder dBuilder = null;
    Document rootDoc = null;
    DOMImplementation dImpl = null;
    DOMResult result = null;
    boolean hasPackage = true;
    Element tempEl;
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance ();

    createCSSFile ();

    //This is to create an in memory document to connect to all the different files
    try {
      dbf.setNamespaceAware (true);
      dbf.setValidating (false);
      dBuilder = dbf.newDocumentBuilder ();

      dImpl = dBuilder.getDOMImplementation ();
      rootDoc = dImpl.createDocument ("", "Files", null);

      //set up the date for output into documentation files
      String date =
	java.text.DateFormat.getDateTimeInstance ().format (new java.util.
							    Date ());
      rootDoc.getDocumentElement ().setAttribute ("date", date);
      rootDoc.getDocumentElement ().setAttribute ("childCount",
						  java.lang.Integer.
						  toString (fileNames.
							    length));

      //Now we open the xmls files and append them to our root element
      for (int i = 0; i < fileNames.length; i++) {

	tempEl = rootDoc.createElement ("File");
	tempEl.setAttribute ("fullPathName", (String) fileNames[i]);
	int loc = ((String) fileNames[i]).lastIndexOf ('/');
	String subString = ((String) fileNames[i]).substring (loc + 1,
							      ((String)
							       fileNames[i]).
							      length () - 4);

	tempEl.setAttribute ("shortName", subString);
	tempEl.setAttribute ("date", date);
	rootDoc.getDocumentElement ().appendChild (tempEl);

      }


    } catch (ParserConfigurationException pce) {
      throw new
	BabelDocException ("Configuration error creating root document. \n" +
			   pce.getMessage ());
    }

    //create an alternate represation to match the dtd shown above
    result = xmlConversion (new DOMSource (rootDoc), "packageTransform.xsl");
    //Test to see if any packages were in the selected files
    Element test = ((Document) result.getNode ()).getDocumentElement ();
    org.w3c.dom.NodeList testList = test.getElementsByTagName ("Package");
    if (testList == null || testList.getLength () <= 0) {
      hasPackage = false;
    }

    DOMSource library = new DOMSource (result.getNode ());

    //reset result to null    
    result = null;

    //We run the original document through a filter to exclude the package elements
    result = xmlConversion (library, "classFilter.xsl");

    if (result != null) {

      Document classDocument = (Document) (result.getNode ());

      org.w3c.dom.NodeList nl =
	(classDocument.getElementsByTagName ("SymbolStore"));

      String[]params = {
      "prev", "next", "package"};	//parameter used to set up part of the navBar
      String[]values = new String[3];	// href values for the navBar


      //We have to do a loop to catch all the individual files.   
      for (int i = 0; i < nl.getLength (); i++) {

	org.w3c.dom.NodeList nl2 =
	  ((Element) nl.item (i)).getElementsByTagName ("SymbolName");
	Element e = (Element) nl2.item (0);


	if (i > 0) {
	  nl2 =
	    ((Element) nl.item (i - 1)).getElementsByTagName ("SymbolName");
	  values[0] =
	    ((Element) nl2.item (0)).getAttribute ("name") + "-v" +
	    ((Element) nl2.item (0)).getAttribute ("version") + ".html";
	}

	else {
	  values[0] = "null";
	}

	if (i < nl.getLength () - 1) {
	  nl2 =
	    ((Element) nl.item (i + 1)).getElementsByTagName ("SymbolName");
	  values[1] =
	    ((Element) nl2.item (0)).getAttribute ("name") + "-v" +
	    ((Element) nl2.item (0)).getAttribute ("version") + ".html";
	}
	else {
	  values[1] = "null";
	}

	if (!hasPackage) {
	  values[2] = "";
	}
	else {
	  values[2] = "true";
	}

	createDocument (new DOMSource (nl.item (i)),
			"SIDLDoc.xsl", outputDir +
			e.getAttribute ("name") + "-v" +
			e.getAttribute ("version") + ".html", params, values);
      }
    }
    else {
      throw new
	BabelDocException ("Was unable to create allclasses-frame.html");
    }

    //Create allclasses-frame by passing a class frame which will be the target for the href
    createDocument (library,
		    "allClasses.xsl", outputDir +
                    "allclasses-frame.html", new String[] {
		    "frame_name"}
		    , new String[] {
		    "classFrame"}
    );
    //Create allclasses-noFrame by passing nulls for the parameters
    createDocument (library,
		    "allClasses.xsl", outputDir +
                    "allclasses-noframe.html", null, null);



    //create the index.html file
    createDocument (library, "createIndex.xsl", outputDir +
                    "index.html", null, null);

    if (hasPackage) {

      //Create the package summary     
      createDocument (library,
		      "createPackageSummary.xsl", outputDir +
		      "package-summary.html", null, null);
    }
  }


  /**
   * @param sourceTree DOM tree representation which is the source of the transformation
   * @param converter
   * @throws TransformerException
   * @throws TransformerConfigurationException
   * @return DOMResult resulting from transformation.
   */
  private DOMResult xmlConversion (DOMSource sourceTree,
				   String converter) throws BabelDocException
  {

    DOMResult result = new DOMResult ();

    TransformerFactory tFactory = TransformerFactory.newInstance ();
    Transformer transformer;
      try {


      transformer =
	tFactory.
	newTransformer (new StreamSource (getInputStream (converter)));
    } catch (TransformerConfigurationException e) {
      e.printStackTrace ();
      throw new BabelDocException ("Configuration setup in xmlCoversion for "
				   + converter + " failed. \n" +
				   e.getMessage ());
    }
    try {
      transformer.transform (sourceTree, result);
    }
    catch (TransformerException e) {
      throw new BabelDocException ("Transformation of sourceTree by " +
				   converter + " failed. \n" +
				   e.getMessage ());
    }

    return result;
  }

  /** 
   * Creates html files and runs the conversion using xslt and Xalan
   * @param xmlDocument DOMSource which is source for tree
   * @param xslFileName String xsl file name to use
   * @param outputFile String name of html file to create.
   * @param params String[] parameter names to pass to xsl file if necesarry. null defines no parameters
   * @param values Sting[] values assigned to parameters
   * @throws ParserConfigurationException
   * @throws TransformerConfigurationException
   * @throws TransformerException
   * @throws SAXException
   * @throws IOException
   */
  private void createDocument (DOMSource xmlDocument, String xslFileName,
			       String outputFile, String[]params,
			       String[]values) throws BabelDocException {

    DocumentBuilder dBuilder;
    Document xslDoc;

    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance ();
      dbf.setNamespaceAware (true);
      dbf.setValidating (false);

    TransformerFactory tFactory = TransformerFactory.newInstance ();
    Transformer transformer;

      try {
      dBuilder = dbf.newDocumentBuilder ();
    } catch (ParserConfigurationException e) {
      throw new BabelDocException ("In createDocument: " + e.getMessage ());
    }
    try {
      xslDoc =
	dBuilder.parse (new org.xml.sax.
			InputSource (getInputStream (xslFileName)));
    } catch (java.io.IOException e) {
      throw new BabelDocException ("Error opening file " + xslFileName +
				   " \n" + e.getMessage ());
    } catch (org.xml.sax.SAXException e) {
      throw new BabelDocException ("Error parsing " + xslFileName + " \n" +
				   e.getMessage ());
    }

    DOMSource xslDomSource = new DOMSource (xslDoc);

    try {
      transformer = tFactory.newTransformer (xslDomSource);
    } catch (TransformerConfigurationException e) {
      e.printStackTrace ();
      throw new
	BabelDocException
	("Error: was unable to create Transformer from xslDomSource \n" +
	 e.getMessage ());
    }

    /* Check for any params to send to xslt document */
    if (params != null) {
      //We check against the length of both arrays to make sure the array length are the same
      if (params.length != values.length) {
	throw new
	  BabelDocException
	  ("Parameter/Value array lengths are not the same");
      }
      for (int index = 0; index < params.length; index++) {
	transformer.setParameter (params[index], values[index]);

      }
    }
    //DOMSource xmlDomSource = new DOMSource(xmlDocument);
    try {
      transformer.transform (xmlDocument, new StreamResult (outputFile));
    } catch (TransformerException e) {
      e.printStackTrace ();
      throw new BabelDocException ("Error: Unable to transform document to " +
				   outputFile + " \n" + e.getMessage ());
    }
  }

    /**
     * @param fileName Name of File to converted into an InputStream
     * @throws BabelDocException
     * @return InputStream Stream source for all processing.
     */
  private InputStream getInputStream (String fileName) throws
    BabelDocException {

    try {
      return s_resLoader.getResourceStream (s_tranformHome + fileName);
    }
    catch (java.io.IOException e) {
      throw new BabelDocException ("Unable to load resource: " +
				   s_tranformHome + fileName + "\n" +
				   e.getMessage ());
    }
    //return in;
  }

  private String getOutputDirectory()
  {
    BabelConfiguration config = d_context.getConfig();
    String outDir = config.getOutputDirectory();
    if (outDir != null) {
      if (outDir.endsWith(File.separator)) return outDir;
      return outDir + File.separator;
    }
    return "./";
  }

  /** method for copying the stylesheet.css from the jar file to the
   * current working directory.
   * @throws BabelDocException
   */
  private void createCSSFile () throws BabelDocException {
    try {


      java.io.InputStream is =
	s_resLoader.getResourceStream (s_tranformHome + "stylesheet.css");

      java.io.BufferedReader in =
	new java.io.BufferedReader (new java.io.
				    InputStreamReader (new java.io.
						       BufferedInputStream
						       (is)));

      String ln;

        java.io.PrintWriter out =
	new java.io.PrintWriter (new java.io.FileWriter (getOutputDirectory() +
                                                         "stylesheet.css"));
      while ((ln = in.readLine ()) != null) {
	out.println (ln);
      } out.close ();
      in.close ();
    }
    catch (java.io.IOException e) {
      throw new BabelDocException ("Error writing " + 
                                   getOutputDirectory() + "stylesheet.css\n" +
				   e.getMessage ());
    }
  }

}
