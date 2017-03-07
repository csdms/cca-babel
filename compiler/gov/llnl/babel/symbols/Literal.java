//
// File:        Literal.java
// Package:     gov.llnl.babel.symbols
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: A intermediate class for literals
// 

package gov.llnl.babel.symbols;

import gov.llnl.babel.Context;

public abstract class Literal extends AssertionExpression {

  Literal(boolean valid, Context context) {
    super(valid, context);
  }

}
