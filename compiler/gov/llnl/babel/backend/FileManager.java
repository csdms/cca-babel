//
// File:        FileManager.java
// Package:     gov.llnl.babel.backend
// Revision:    @(#) $Id$
// Description: singleton file manager for backend code generators
//
// Copyright (c) 2000-2001, Lawrence Livermore National Security, LLC
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
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

package gov.llnl.babel.backend;

import gov.llnl.babel.BabelConfiguration;
import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.CodeSplicer;
import gov.llnl.babel.backend.writers.ChangeWriter;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.SymbolUtilities;
import gov.llnl.babel.symbols.Type;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * <code>FileManager</code> is a singleton class that manages the files
 * generated by the backend code generators.  This class tracks what files
 * were generated and their "file group" for use in makefile generation.
 */
public class FileManager {
  private boolean    d_package_dirs;
  private boolean    d_glue_dirs;
  private File       d_root_dir;
  private File       d_vpath_dir;
  private Collection d_listeners;
  private Context    d_context;
  
  /**
   * Create a new instance of the backend file manager object.  Normally
   * you get the instance from the Context.
   */
  public FileManager(Context context) {
    d_package_dirs = true;
    d_glue_dirs = false;
    d_listeners = new LinkedList();
    d_context = context;
  }
  
  /**
   * Add a listener to the file manager. This listener will receive calls
   * for each file created.
   * 
   * @param listener  a new listener to be added.
   */
  public void addListener(FileListener listener)
  {
    d_listeners.add(listener);
  }

  /**
   * Remove a listener from this file manager.
   *
   * @param listener  the listener to remove.
   */
  public void removeListener(FileListener listener)
  {
    d_listeners.remove(listener);
  }

  /**
   * Remove a collection of listeners from this file manager.
   *
   * @param listeners  the listener collection to remove.
   */
  public void removeListeners(Collection listeners)
  {
    d_listeners.removeAll(listeners);
  }

  /**
   * Notify all listeners that a file will be created.
   */
  private void notifyListeners(SymbolID id,
                               int      type,
                               String   role,
                               String   dir,
                               String   name)
  {
    for(Iterator i = d_listeners.iterator(); i.hasNext(); ) {
      FileListener l = (FileListener)i.next();
      l.newFile(id, type, role, dir, name);
    }
  }

  /**
   * Get the current style of file generation, either all in one directory
   * or Java-style package directories.
   */
  public boolean getJavaStylePackageGeneration() {
    return d_package_dirs;
  }

  /**
   * Set the style of file generation, either all in one directory or
   * Java-style package directories.  In the first case, all files are
   * stored in the same directory.  In the second, files are stored in
   * package subdirectories that correspond to the sidl package structure.
   * The default is to use Java-style file generation.
   */
  public void setJavaStylePackageGeneration(boolean java_style) {
    d_package_dirs = java_style;
  }

  /**
   * Set the style of file generation for impl and non-impl (ior, etc)
   * files, either all in one directory, or generating the "glue"
   * code (stubs, skels, ior) in a separate glue/ subdirectory.
   */
  public void setGlueSubdirGeneration(boolean glue_dir) {
    d_glue_dirs = glue_dir;
  }
 
  /**
   * Get the current style of "glue" code generation.
   */
  public boolean getGlueSubdirGeneration() {
    return d_glue_dirs;
  }

  /**
   * Set the VPATH directory where files can be found
   * (notably IMPLS for CodeSplicers).
   * 
   * @param directory String name of directory ( relative or absolute).
   *                  If it's null, "", or "." then VPATH is disabled.
   */

  public void setVPathDirectory( String directory ) throws CodeGenerationException
  {
    if ( directory == null || directory.equals("") || directory.equals(".") ) { 
	d_vpath_dir = null;
        return;
    }  

    File d = new File( directory );
    if ( d.isFile() ) { 
      throw new CodeGenerationException
        ("\'" + directory +"\' is a file, not a directory.");
    }
    if ( !d.isDirectory())  { 
      throw new CodeGenerationException
        ("\'" + directory +"\' not found.");
    }
    d_vpath_dir = d;
  }

  /**
   * Change the root directory where files will be generated
   * to something other than the current working directory
   * 
   * @param directory String name of directory (relative or absolute)
   *                  if it's null, empty, or "." then current directory
   *                  is assumed.
   * @exception CodeGenerationException
   */
  public void setFileGenerationRootDirectory(String directory) 
    throws CodeGenerationException 
  {
    if ( directory == null || 
         directory.equals("") || 
         directory.equals(".") ) { 
      d_root_dir = null;
      return;
    }      

    File d = new File( directory );
    if ( d.isFile() ) { 
      throw new CodeGenerationException
        ("\'" + directory +"\' is a file, not a directory.");
    }
    if ( (!d.isDirectory()) && (! d.mkdirs()) ) { 
      throw new CodeGenerationException
        ("\'" + directory +"\' can neither be found nor created as a directory.");
    }
    d_root_dir = d;
  }

  /**
    * Create a file given a symbol ID, type, file group, and file name.  The
    * return value is a <code>PrintWriter</code> stream that must be closed
    * by the caller when the file handle is no longer needed.  The symbol is
    * used to expand the file path; it may be null if no expansion is
    * desired.
    *
    * @param id        the file is associated with this symbol ID.
    * @param type      the symbol ID is of this type. This should be one
    *                  of the constants from 
    *                  {@link gov.llnl.babel.symbols.Type}.
    * @param groupname the category this file belongs in.
    * @param filename  the file name.
    */
  public PrintWriter createFile(SymbolID id,
                                int      type,
                                String   groupname,
                                String   filename)
    throws CodeGenerationException
  {
    return new PrintWriter( createWriter(id, type, groupname, filename ));
  }

  private File getDirectory(SymbolID id,
                           int type,
                           String groupname,
                           String filename)
    throws CodeGenerationException
  {
    File result;
    if ( id==null || groupname==null || filename==null || filename.equals("") ) { 
      throw new CodeGenerationException("Non-null, non-empty input parameters required.");
    }
    if ("MATLAB_STUB".equals(groupname) || "MATLAB_PRIVATE".equals(groupname)) {
      result = expandStubMatlabDirectory(id, type, groupname);
    }
    else {
      result = expandDirectory(id, type);
    }
    BabelConfiguration babel_config = d_context.getConfig();
    if (babel_config.makeLanguageSubdir()) {
      result = expandLanguageSubdir(id, result, babel_config.getTargetLanguage());
    }
    
    /* 
     * Create a subdirectory for the "glue" code (ior, skels, etc)
     */
    if (d_glue_dirs && (! groupname.startsWith("IMPL"))
        && (! groupname.startsWith("JAVA"))
        && (! groupname.equals("STUBJAVA"))
        && (! groupname.equals("PYMOD_SRCS")) 
    	&& (! groupname.startsWith("PYTHONSRC"))    
    	&& (! groupname.startsWith("PYTHONADMIN"))) {    
      // [BRN] TODO: better way to designate glue code?
      result = expandGlueSubdir( id, result ); 
    }


    return result;
  }

  public boolean fileExists(SymbolID id,
                            int type,
                            String groupname,
                            String filename)
    throws CodeGenerationException
  {
    File file = new File(getDirectory(id, type, groupname, filename), filename);
    return file.isFile();
  }

  public void fakeFileCreation(SymbolID id,
                               int type,
                               String groupname,
                               String filename)
    throws CodeGenerationException 
  {
    File dir = getDirectory(id, type, groupname, filename);
    if ((dir == null) || !((new File(dir, filename)).isFile())) {
      throw new CodeGenerationException("Spoofing create for non-existent file: " + dir.getName() + File.separator +
                                        filename + ".");
    }
    notifyListeners(id, type, groupname, dir.toString() + File.separator, filename);
  }


  /**
    * Create a file given a symbol, file group, and file name.  The return
    * value is a <code>Writer</code> that will typically be used to 
    * create a <code>PrintWriter</code> stream that must be closed by the
    * caller when the file handle is no longer needed.  The symbol is used
    * to expand the file path; it may be null if no expansion is desired.
    *
    * @param id        the file being created is related to this symbol id.
    * @param type      this constant from 
    *                  {@link gov.llnl.babel.symbols.Type} indicates
    *                  the type of id.
    * @param groupname the category this file belongs in
    * @param filename  the file name
    */
  public Writer createWriter(SymbolID id, 
                             int      type,
                             String   groupname, 
                             String   filename)
    throws CodeGenerationException 
  {
    File dir = getDirectory(id, type, groupname, filename);

    String dirname = "";
    if ( dir != null && !dir.toString().equals("") ) { 
      if ((!dir.isDirectory()) && (!dir.mkdirs())) {
        throw new CodeGenerationException("Attempt to create directory " +
                                          dir.getName() + " failed.");
      }
      dirname = dir.toString() + File.separator;
    }
    notifyListeners(id, type, groupname, dirname, filename);

    /*     
     * Open the file and return a print writer handle to the file.
     */
    Writer writer = null;
    try {
      if (d_context.getConfig().getProtectLastTimeModified()) {
        writer = ChangeWriter.createWriter(filename, dirname);
      }
      else {
        writer = new BufferedWriter
          (new FileWriter(new File(dirname + filename)));
      }
    } catch (IOException ex) {
      throw new CodeGenerationException(ex.getMessage());
    }
    
    return writer;
  }
  
  /**
   * Read the specified file and return a code splicer object representing
   * code splices from the file that should be preserved in the next file.
   * If the file does not exist, an CodeSplicer instance based on the business
   * rules defined by CodeSplicer is returned.
   * This will happen whenever code is generated for the first time.
   * If there is any other error reading the file data, an IOException
   * is thrown.  There should be no need to check for null returns.
   * @return valid (though possibly empty) CodeSplicer
   * @exception java.io.IOException 
   */
  public CodeSplicer getCodeSplicer(SymbolID id, int type, String file, 
                                    boolean isSource, boolean prependFullName) 
    throws IOException 
  {
    File vpath_dir = expandVPathDirectory(id, type); // the vpath source for the splicer (if it exists)
    File target_dir = expandDirectory(id, type);  // the target for where the IMPL gets generated
    BabelConfiguration babel_config = d_context.getConfig();
    if (babel_config.makeLanguageSubdir())  {
      target_dir = expandLanguageSubdir( id, target_dir, babel_config.getTargetLanguage() );
    }

    String path = "";
    String vpath = ".";
    CodeSplicer  splicer  = null;
    FileReader   reader   = null;

    if ( target_dir == null || target_dir.toString().equals("") ) { 
        ; 
    } else { 
	path += target_dir.toString() + File.separator;
    }
    path += file;

    File f0 = new File( path );
    path = f0.getCanonicalPath();

    if ( vpath_dir == null  || vpath_dir.toString().equals("") 
         || vpath_dir.toString().equals(".") ) { 
        vpath = path;
    }  else { 
      vpath = vpath_dir.toString() + File.separator + file;    
      File f = new File( vpath );
      if ( ! (f.exists() && f.isFile() && f.canRead() ) ) { // if there's no file to read...
	  vpath = path;
      } else vpath = f.getCanonicalPath();
    } 
    
    try {
      reader  = new FileReader(vpath);
      splicer = new CodeSplicer(id, new BufferedReader(reader), vpath, path,
                                isSource, prependFullName, d_context);
    } catch ( FileNotFoundException ex ) { 
      /*
       * Instantiate a CodeSplicer that is not populated from a file.
       */
      splicer = new CodeSplicer(id, isSource, prependFullName, d_context);
    } finally {
      if (reader != null) {
        reader.close();
      }
    }
    
    return splicer;
  }
  
  /**
   * Generate the relative file name from the symbol ID.
   * If the symbol is not null and Java style package directories are
   * enabled, then the sidl package name of the symbol is converted into
   * a path name.  Furthermore, if the root directory and/or the sub
   * directory is set, they are prepended to the path.
   * The resulting directory is not guaranteed to exist
   * in the filesystem.
   * 
   * @param id   The symbol  ID to generate files for
   * @param type The type of the symbol ID. This should be one of the
   *             constants from {@link gov.llnl.babel.symbols.Type}.
   * @return <code>java.io.File</code> representation for
   *         the directory to generate the code.  Can be null
   *         if 
   *         <enumerate>
   *           <li><code>setJavaStylePackageGeneration(false)</code>, and</li>
   *           <li><code>setFileGenerationRootDirectory(null)</code>, and</li>
   *         </enumerate>
   * @see FileManager#setJavaStylePackageGeneration
   * @see FileManager#setFileGenerationRootDirectory
   */
  public File expandDirectory(SymbolID id,
                              int type) 
  {
    StringBuffer path = new StringBuffer();
    
    // first start with the root directory, if specified
    if ( d_root_dir != null ) { 
        path.append(d_root_dir.getPath()).append(File.separator);
    }
      
    // then concatenate the package directories, if specified
    if ((id != null) && (d_package_dirs == true)) {
      String pkg = null;
      if (type == Type.PACKAGE) {
        pkg = id.getFullName();
      } else {
        pkg = SymbolUtilities.getParentPackage(id.getFullName());
      }

      path.append(pkg.replace('.', File.separatorChar)).append(File.separator);
    }

    // now build the directories if they don't exist
    if ( path.length() == 0 ) { 
      return null;
    } else { 
      return new File( path.toString() );
    }
  }

  /**
   * Generate the relative Matlab file name from the symbol ID.
   * If the symbol is not null and Java style package directories are
   * enabled, then the sidl package name of the symbol is converted into
   * a path name with prefix @. Furthermore, if the root directory and/or the sub
   * directory is set, they are prepended to the path.
   * The resulting directory is not guaranteed to exist
   * in the filesystem.
   * 
   * @param id   The symbol  ID to generate files for
   * @param type The type of the symbol ID. This should be one of the
   *             constants from {@link gov.llnl.babel.symbols.Type}.
   * @return <code>java.io.File</code> representation for
   *         the directory to generate the code.  Can be null
   *         if 
   *         <enumerate>
   *           <li><code>setJavaStylePackageGeneration(false)</code>, and</li>
   *           <li><code>setFileGenerationRootDirectory(null)</code>, and</li>
   *         </enumerate>
   * @see FileManager#setJavaStylePackageGeneration
   * @see FileManager#setFileGenerationRootDirectory
   */
  public File expandStubMatlabDirectory(SymbolID id,
                              int type, String groupname) 
  {
    StringBuffer path = new StringBuffer();
    path.append("@");
    
    // first start with the root directory, if specified
    if ( d_root_dir != null ) { 
        path.append(d_root_dir.getPath()).append(File.separator);
    }
      
    // then concatenate the package directories, if specified
    if ((id != null) && (d_package_dirs == true)) {
      String mobjDir = null;
      //if (type == Type.CLASS) {
        mobjDir = id.getFullName().replace('.', '_');
      //}
      path.append(mobjDir);
      if("MATLAB_PRIVATE".equals(groupname))path.append("/private");
    }

    // now build the directories if they don't exist
    if ( path.length() == 0 ) { 
      return null;
    } else { 
      return new File( path.toString() );
    }
	}
/*
  public File expandStubMatlabPrivateDir(SymbolID id, int type) 
  {
    StringBuffer path = new StringBuffer();
    path.append("@");
    
    // then concatenate the package directories, if specified
    if ((id != null) && (d_package_dirs == true)) {
      String privateDir = null;
      //if (type == Type.CLASS) {
        privateDir = id.getFullName().replace('.', '_');
      //}
      path.append(privateDir);
      path.append("/private");
    }

    // now build the directories if they don't exist
    if ( path.length() == 0 ) { 
      return null;
    } else { 
      return new File( path.toString() );
    }
	}
*/


  public File expandLanguageSubdir( SymbolID id, File file, String language)
  {
    StringBuffer path = new StringBuffer();
    if (file != null) {
      path.append(file.getPath());
    }
    //if ((id != null) && (d_glue_dirs == true)) {
    if ((id != null)) {        // Enable language subdir. for client code
      if (path.length() > 0) {
        path.append(File.separator);
      }
      path.append(language);
    }
    if (path.length() == 0 ) {
      return null;
    } else {
      return new File(path.toString());
    }
  }

  public File expandGlueSubdir( SymbolID id, File file )
  {
    StringBuffer path = new StringBuffer();
    if (file != null) {
      path.append(file.getPath());
    }
    if ((id != null) && (d_glue_dirs == true)) {
      if (path.length() > 0) {
        path.append(File.separator);
      }
      path.append("glue");
    }
    if (path.length() == 0 ) {
      return null;
    } else {
      return new File(path.toString());
    }
  }

  /**
   * Generate the VPATH for the symbol ID.
   * If the result is not null, then the resulting directory is guaranteed to exist.
   * The directory is constructed of the explicit VPATH with the package directories appended
   * only if Java style package directories are enabled.
   * 
   * @param id   The symbol ID to generate files for
   * @param type The type of the symbol ID being generated. This should
   *             be one of the constants from
   *             {@link gov.llnl.babel.symbols.Type}.
   * @return <code>java.io.File</code> representation for
   *         the directory to generate the code.  Can be null
   *         if 
   *         <enumerate>
   *           <li><code>setVPathDirectory(null)</code>, or
   *           <li>VPATH == Output Directory, or
   *           <li>final directory does not exist.
   *         </enumerate>
   * @see FileManager#setJavaStylePackageGeneration
   * @see FileManager#setFileGenerationRootDirectory
   */
  public File expandVPathDirectory(SymbolID id,
                                   int      type)
  {
    
    if (d_vpath_dir == null || d_vpath_dir.equals(d_root_dir) ) { return null; }
 
    String path = d_vpath_dir.getPath() + File.separator;  
      
    // then concatenate the package directories, if specified
    if ((id != null) && (d_package_dirs == true)) {
      String pkg = null;
      if (type == Type.PACKAGE) {
        pkg = id.getFullName();
      } else {
        pkg = SymbolUtilities.getParentPackage(id.getFullName());
      }
      path += pkg.replace('.', File.separatorChar) + File.separator;
    }

    // Now verify the vpath exists.
    File f = new File( path );
    if (f.isDirectory()) { 
      return f;
    } else { 
      return null;
    }
  }

}
