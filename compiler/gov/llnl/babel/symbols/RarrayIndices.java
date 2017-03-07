//
// File:        RarrayIndices.java
// Package:     gov.llnl.babel.symbols
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Visitor to create a set of rarray indices
// 

package gov.llnl.babel.symbols;

import gov.llnl.babel.symbols.ExprVisitor;
import java.util.Set;

public class RarrayIndices extends ExprVisitor
{
  public Object visitIdentifierLiteral(IdentifierLiteral il, Object data)
  {
    Set s = (Set)data;
    s.add(il.getIdentifier());
    return s;
  }
}
