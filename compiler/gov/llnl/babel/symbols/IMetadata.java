//
// File:        IMetadata.java
// Package:     gov.llnl.babel.symbols
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Interface for things that have metadata
// 

package gov.llnl.babel.symbols;

public interface IMetadata {
  /**
   * Return the metadata associated with this object.
   */
  public Metadata getMetadata();

  /**
   * Add a (keyword, value) pair to the metadata for this object.
   */
  public void addMetadata(String keyword, String value);
}
