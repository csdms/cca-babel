//
// File:        AttributedType.java
// Package:     gov.llnl.babel.ast
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Attributed type
// 

package gov.llnl.babel.ast;
import gov.llnl.babel.parsers.sidl2.ParseTreeNode;

public abstract class AttributedType extends NamedType implements IAttributable {

  protected AttributeList d_attribList;
  
  public AttributedType(ParseTreeNode src, ASTNode parent, Name name) {
    super(src, parent, name);
    d_attribList = new AttributeList(null, this);
  }

  public AttributeList getAttributeList() {
    return d_attribList;
  }

  public void setAttributeList(AttributeList attribs) {
    d_attribList = attribs;
  }
}
