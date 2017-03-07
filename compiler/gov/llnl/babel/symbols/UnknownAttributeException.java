//
// File:        UnknownAttributeException.java
// Package:     gov.llnl.babel.symbols
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Thrown when client requests an unknown attribute
// 
package gov.llnl.babel.symbols;

public class UnknownAttributeException extends RuntimeException {
  public UnknownAttributeException(String msg) {
    super(msg);
  }
};
