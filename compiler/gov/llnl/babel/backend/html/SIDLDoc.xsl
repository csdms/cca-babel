<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:param name="prev" select="'null'"/>
    <xsl:param name="next" select="'null'"/>
    <xsl:param name="package" select="true"/>
    
    <xsl:preserve-space elements="Comment"/>
    <xsl:variable name="newline">
    <xsl:text>  
    </xsl:text>
    </xsl:variable>
    
    <xsl:variable name="lang"></xsl:variable>
    <xsl:strip-space elements="*"/>
    
    
    
    <xsl:output method="html" doctype-public='-//W3C//DTD HTML 4.0 TRANSITIONAL//EN"' doctype-system="http://www.w3c.org/TR/REC-html40/loose.dtd"/>
    
    <xsl:variable name="newline">
    <xsl:text>  
    </xsl:text>
    </xsl:variable>
    <xsl:template match="/">
        <xsl:apply-templates select="SymbolStore"/>
    </xsl:template>
    
    
    
    <xsl:template match="SymbolStore">
         <html> 
        <xsl:value-of select="$newline"/>             
            <head>
                <xsl:call-template name="generateDateStamp">
                    <xsl:with-param name="printDate" select="@date"/>  
                </xsl:call-template>
                <Title><xsl:value-of select="@shortName"/></Title>
                <xsl:call-template name="generateOtherHeader">
                    <xsl:with-param name="docTitle" >Class page</xsl:with-param>
                </xsl:call-template>
                
            </head> 
            <xsl:value-of select="$newline"/>
            <body BGCOLOR="white" nload="asd ();">
                <xsl:call-template name="navBarCreate"/>
                <xsl:value-of select="$newline"/>
                <xsl:apply-templates select="Symbol"/>
            </body>
            <xsl:value-of select="$newline"/>
           
       </html>    
    </xsl:template>
    
    <xsl:template name="navBarCreate">
        
        <xsl:value-of select="$newline"/>
        <xsl:comment>========== START OF NAVBAR ==========</xsl:comment>
        <xsl:value-of select="$newline"/>
        <A NAME="navbar_top"><xsl:comment></xsl:comment></A>
        <xsl:value-of select="$newline"/>
        <TABLE BORDER="0" WIDTH="100%" CELLPADDING="1" CELLSPACING="0">
        <xsl:value-of select="$newline"/>
        <TR>
        <xsl:value-of select="$newline"/>
        <TD COLSPAN="3" BGCOLOR="#EEEEFF" CLASS="NavBarCell1">
        <xsl:value-of select="$newline"/>
        <A NAME="navbar_top_firstrow"><xsl:comment></xsl:comment><!-- --></A>
        
        <TABLE BORDER="0" CELLPADDING="0" CELLSPACING="3">
        <xsl:value-of select="$newline"/>
             <TR ALIGN="center" VALIGN="top">
             <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1"> 
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                    <xsl:choose>
                        <xsl:when test="$package">
                            <A href="package-summary.html">
                                <FONT CLASS="NavBarFont1">Package</FONT>
                            </A>
                        </xsl:when>
                        <xsl:otherwise>
                            <FONT CLASS="NavBarFont1">Package</FONT>
                        </xsl:otherwise>
                    </xsl:choose>
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD CLASS="NavBarCell1Rev" BGCOLOR="#FFFFFF" >
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                        <FONT CLASS="NavBarFont1Rev">Class</FONT>
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">  
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                    
                        <FONT CLASS="NavBarFont1">
                            <B>Tree</B>
                        </FONT>
                    
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">  
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>  
                    
                        <FONT CLASS="NavBarFont1">
                            <B>Deprecated</B>
                        </FONT>
                    
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1"> 
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                    
                        <FONT CLASS="NavBarFont1">
                            <B>Index</B>
                        </FONT>
                    
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">   
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text> 
                    
                        <FONT CLASS="NavBarFont1">
                            <B>Help</B>
                        </FONT>
                    
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
            </TR>
            <xsl:value-of select="$newline"/>
        </TABLE>
        <xsl:value-of select="$newline"/>
        </TD>
        <xsl:value-of select="$newline"/>
        <TD ALIGN="right" VALIGN="top" ROWSPAN="3">
        <EM></EM>
        </TD>
        <xsl:value-of select="$newline"/>
        </TR>
        <xsl:value-of select="$newline"/>

        <TR>
        <xsl:value-of select="$newline"/>
        <TD BGCOLOR="white" CLASS="NavBarCell2">
        <FONT SIZE="-2">
        
        <xsl:choose>
        <xsl:when test="$prev = 'null'">PREV CLASS </xsl:when>
        <xsl:otherwise><A href="{$prev}">PREV CLASS </A></xsl:otherwise>
        </xsl:choose>
        </FONT>
        <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
        <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
        <FONT SIZE="-2">
        <xsl:choose>
        <xsl:when test="$next = 'null'">NEXT CLASS </xsl:when>
        <xsl:otherwise><A href="{$next}">NEXT CLASS </A></xsl:otherwise>
        </xsl:choose>
        </FONT>
        </TD>
        <xsl:value-of select="$newline"/>
        <TD BGCOLOR="white" CLASS="NavBarCell2"><FONT SIZE="-2">
            <xsl:choose>
                <xsl:when test="$package">
                    <A HREF="index.html" TARGET="_top"><B>FRAMES</B></A> 
                </xsl:when>
                <xsl:otherwise>
                    <B>FRAMES</B>
                </xsl:otherwise>
            </xsl:choose>
            <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text> 
            <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text> 
            <!--<A HREF="index-all.html" TARGET="_top">--><B>NO FRAMES</B><!--</A>--> 
            <xsl:value-of select="$newline"/>
        <SCRIPT>
        <xsl:value-of select="$newline"/>
        <!--
        if(window==top) {
            document.writeln('<A HREF="allclasses-noframe.html" TARGET=""><B>All Classes</B></A>');
        }
        //-->
        </SCRIPT>
        <xsl:value-of select="$newline"/>
        <NOSCRIPT>
            <A HREF="allclasses-noframe.html" TARGET=""><B>All Classes</B></A>
        </NOSCRIPT>
        <xsl:value-of select="$newline"/>
        </FONT> </TD>
        <xsl:value-of select="$newline"/>
        </TR>
        <xsl:value-of select="$newline"/>
        </TABLE>
        <xsl:value-of select="$newline"/>
    </xsl:template>
    <xsl:template name="generateDateStamp">
        <xsl:param name="printDate"/>
        <xsl:value-of select="$newline"/>
        <xsl:comment>Generated by babeldoc on <xsl:value-of select="$printDate"/> </xsl:comment>
        <xsl:value-of select="$newline"/>
    </xsl:template> 
      
    <xsl:template name="generateOtherHeader">
        <xsl:param name="docTitle"/>  
        <xsl:value-of select="$newline"/>
        <LINK REL="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style"/>
        
        <SCRIPT>
        function asd()
        {
        parent.document.title="<xsl:value-of select="$docTitle"/>"
        }
        </SCRIPT> 
        <xsl:value-of select="$newline"/>
     </xsl:template>
  
  
  
  
  
  
  <!-- Implementation of the xsl templates for the didl xml files -->
  
  <xsl:template match="Symbol">
  
    <h2>
    <FONT>
    <xsl:if test="Class/@abstract='true'">
	abstract
    </xsl:if>
    
    <xsl:value-of select="SymbolName/@name"/>-v<xsl:value-of select="SymbolName/@version"/>
   
    </FONT>
    </h2>
    <xsl:value-of select="$newline"/>
    <xsl:apply-templates select="Metadata"/>
    <xsl:apply-templates select="Comment"/>
    <xsl:value-of select="SymbolName/@name"/>-v<xsl:value-of select="SymbolName/@version"/>
    <xsl:apply-templates select="Package"/>     
    <xsl:apply-templates select="Class"/>
    <xsl:apply-templates select="Interface"/>
    <xsl:apply-templates select="Enumeration"/>
    <xsl:value-of select="$newline"/>
  </xsl:template>

  <xsl:template match="SymbolName">
  
    <a href="{@name}-v{@version}.html">
      <xsl:value-of select="@name"/>
    </a>
    
  </xsl:template>
   
  <xsl:template match="Metadata">
  <xsl:value-of select="$newline"/>
    <ul>
    <xsl:value-of select="$newline"/>
      <xsl:for-each select="MetadataEntry">
      <xsl:value-of select="$newline"/>
        <li><xsl:value-of select="@key"/>:<xsl:value-of select="@value"/></li>
        <xsl:value-of select="$newline"/>
      </xsl:for-each>
      <xsl:value-of select="$newline"/>
    </ul>
    <xsl:value-of select="$newline"/>
  </xsl:template> 
  
  <xsl:template match="Comment">
    <table cellpadding="3" WIDTH="100%"><tr><td>
    <p>
    <xsl:apply-templates select="text()"/>
    </p>
    <br/>
    </td></tr></table>  
  </xsl:template>
  
  <xsl:template match="node()">
  <BLOCKQUOTE><PRE>
    <xsl:copy>
      <xsl:apply-templates/>
    </xsl:copy>
    </PRE></BLOCKQUOTE>
  </xsl:template>

  <xsl:template match="Package"> 
  <xsl:value-of select="$newline"/>
    <xsl:variable name="vers"><xsl:value-of select="../SymbolName/@version"/></xsl:variable>
    <xsl:variable name="nm"><xsl:value-of select="../SymbolName/@name"/></xsl:variable>
    <xsl:value-of select="$newline"/>
    <table border="1" cellpadding="3" WIDTH="100%">
    <xsl:value-of select="$newline"/>
      <tr BGCOLOR="#CCCCFF"><th>Interfaces</th></tr>
      <xsl:value-of select="$newline"/>
      <xsl:for-each select="PackageSymbol">
	  <xsl:sort select="@name"/>
        <xsl:if test="@type='interface'">
	    <tr><td>
                <a href="{$nm}.{@name}-v{$vers}.html"><xsl:value-of select="$nm"/>.<xsl:value-of select="@name"/></a>
	    </td></tr>
            <xsl:value-of select="$newline"/>
        </xsl:if>
      </xsl:for-each>
    </table>  
    <xsl:value-of select="$newline"/> 
    <br/>
    <xsl:value-of select="$newline"/>
    <xsl:value-of select="$newline"/>
    <table border="1" cellpadding="3" WIDTH="100%">
    <xsl:value-of select="$newline"/>
      <tr BGCOLOR="#CCCCFF"><th> Classes </th></tr>
      <xsl:value-of select="$newline"/>
	  <xsl:for-each select="PackageSymbol">
            <xsl:sort select="@name"/>
            <xsl:if test="@type='class'">
            <tr>
            <xsl:value-of select="$newline"/>
	      <td>
              <xsl:value-of select="$newline"/>
                <a href="{$nm}.{@name}-v{$vers}.html"><xsl:value-of select="$nm"/>.<xsl:value-of select="@name"/></a>
	      </td>
              <xsl:value-of select="$newline"/>
	    </tr>
            <xsl:value-of select="$newline"/>
            </xsl:if>
        </xsl:for-each>
    </table>
    <xsl:value-of select="$newline"/><xsl:value-of select="$newline"/>
  </xsl:template>
  
  <xsl:template name="extend">
    <xsl:param name="extSource"/>
    <br/>
    <xsl:text>   extends </xsl:text>
    <xsl:value-of select="$extSource"/>
   
  </xsl:template>


  <xsl:template match="Interface">
    <xsl:if test="ExtendsBlock/SymbolName/@name">
        <xsl:call-template name="extend">
            <xsl:with-param name="extSource">
            <xsl:value-of select="ExtendsBlock/SymbolName/@name"/>
            <xsl:text>-v</xsl:text>    
            <xsl:value-of select="ExtendsBlock/SymbolName/@version"/>
            </xsl:with-param>
            </xsl:call-template>
        <!--<a href="{ExtendsBlock/SymbolName/@name}-v{ExtendsBlock/SymbolName/@version}.html">-->
        
        <!--</a>-->
        <xsl:value-of select="$newline"/>
        
     </xsl:if>
     <xsl:apply-templates select="MethodsBlock"/>
  </xsl:template>




  <xsl:template match="Class">
    
      <xsl:if test="Extends/SymbolName/@name">
        <xsl:call-template name="extend">
            <xsl:with-param name="extSource">
            <xsl:value-of select="Extends/SymbolName/@name"/>-v
            <xsl:value-of select="Extends/SymbolName/@version"/>
            </xsl:with-param>
        </xsl:call-template>
            
      </xsl:if>
	<xsl:if test="ImplimentsBlock">
            <xsl:text> impliments </xsl:text>
         <xsl:for-each select="ImplementsBlock/SymbolName">
          <xsl:value-of select="ImplementsBlock/SymbolName/@name"/>-v
          <xsl:value-of select="ImplementsBlock/SymbolName/@version"/>
          <xsl:if test="last()!=position()">
            <xsl:text>, </xsl:text>
          </xsl:if>
        </xsl:for-each>
      </xsl:if>
    
    <xsl:apply-templates select="MethodsBlock"/>
  </xsl:template>



  <xsl:template match="Enumeration">
    <table border="1" cellpadding="3" width="100%">
    <xsl:value-of select="$newline"/>
    <tr><th>Name</th><th>Value</th><th>User defined</th></tr>
    <xsl:value-of select="$newline"/>
    <xsl:for-each select="Enumerator">
	<tr>
        <xsl:value-of select="$newline"/>
	  <td><xsl:value-of select="@name"/></td>
          <xsl:value-of select="$newline"/>
	  <td><xsl:value-of select="@value"/></td>
          <xsl:value-of select="$newline"/>
 	  <td><xsl:value-of select="@fromuser"/></td>
          <xsl:value-of select="$newline"/>
      </tr>
      <xsl:value-of select="$newline"/>
    </xsl:for-each>
    </table>      
    <xsl:value-of select="$newline"/>
  </xsl:template>

  <xsl:template name="methodSignature">
  
    <xsl:variable name="mName"><xsl:value-of select="@name"/></xsl:variable>
   
    <xsl:variable name="mParams">(<xsl:for-each select="ArgumentList/Argument">
            <xsl:if test="@copy='true'">
                copy<xsl:text> </xsl:text>
            </xsl:if>
            <xsl:value-of select="@mode"/>
            <xsl:text> </xsl:text>
            <xsl:choose>
		 <xsl:when test="Type/SymbolName">
                    <xsl:apply-templates select="Type"/>
	         </xsl:when>
		 <xsl:when test="Type/Array">
	            <xsl:apply-templates select="Type"/>
                 </xsl:when>
                 <xsl:otherwise>
        	    <xsl:value-of select="Type/@type"/>
      		 </xsl:otherwise>
            </xsl:choose>
            <xsl:text>   </xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:if test="not(position()=last())">, </xsl:if>
            <xsl:text>  </xsl:text>
		
         </xsl:for-each>
	)
    </xsl:variable>
   <a href="{Symbol/SymbolName/@name}-v{Symbol/SymbolName/@version}.html#{$mName}{$mParams}">
        <strong><xsl:value-of select="$mName"/></strong><xsl:value-of select="$mParams"/>
   </a>
  </xsl:template>
  
  
  
  
  <xsl:template name="methodName">
        <xsl:choose>
            <xsl:when test="@name">
                <xsl:value-of select="@name"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="@shortname"/>
                <xsl:if test="string-length(@extension) > 0">
                <xsl:text>[</xsl:text>
                <xsl:value-of select="@extension"/>
                <xsl:text>]</xsl:text>
                </xsl:if>
            </xsl:otherwise>
        </xsl:choose>
        
  </xsl:template>
  
  
  
  <xsl:template name="methodParams">(<xsl:for-each select="ArgumentList/Argument">
            <xsl:if test="@copy='true'">copy<xsl:text> </xsl:text>
            </xsl:if>
            <xsl:value-of select="@mode"/>
            <xsl:text> </xsl:text>
            <xsl:choose>
		 <xsl:when test="Type/SymbolName">
                    <xsl:apply-templates select="Type"/>
	         </xsl:when>
		 <xsl:when test="Type/Array">
	            <xsl:apply-templates select="Type"/>
                 </xsl:when>
                 <xsl:otherwise>
        	    <xsl:value-of select="Type/@type"/>
      		 </xsl:otherwise>
            </xsl:choose>
            <xsl:text>   </xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:if test="not(position()=last())">, </xsl:if>
            <xsl:text>  </xsl:text>
		
         </xsl:for-each>)</xsl:template>
  
  
  <xsl:template name="returnValue">
        
        <xsl:if test="@definition!='normal'">
            <xsl:value-of select="@definition"/>
            <xsl:text> </xsl:text>
	</xsl:if>
	<xsl:choose>
            <xsl:when test="Type/Array">
                <xsl:apply-templates select="Type"/>
            </xsl:when>	  
            <xsl:when test="Type/SymbolName">
                <xsl:apply-templates select="Type"/>
            </xsl:when>  
            <xsl:otherwise>
                <xsl:value-of select="Type/@type"/>
            </xsl:otherwise>
        </xsl:choose>
        
  </xsl:template>
  
  
  
  <xsl:template match="MethodsBlock">
     <table border="1" cellpadding="3" width="100%">
     
     <tr BGCOLOR="#CCCCFF"><td COLSPAN="3">
            <a name="method_summary">
            <font size="+2">Method Summary</font>
            </a>
        </td></tr>
      <xsl:for-each select="Method">
	<xsl:sort select="./@name"/>  
        <tr>
        <xsl:value-of select="$newline"/>
	    <td align="RIGHT" width="15%">
                <xsl:call-template name="returnValue"/>
	    </td>
            <xsl:value-of select="$newline"/>
	    <td BGCOLOR="white">
                <xsl:value-of select="$newline"/>
                <xsl:variable name="mName"><xsl:call-template name="methodName"/></xsl:variable>
                <xsl:variable name="mParams">
                    <xsl:call-template name="methodParams"/>
                </xsl:variable>
                <a href="{../../../SymbolName/@name}-v{../../../SymbolName/@version}.html#{$mName}{$mParams}">
                    <strong><xsl:value-of select="$mName"/></strong>
                </a><xsl:call-template name="methodParams"/>
	    </td>
            <xsl:value-of select="$newline"/>
	  </tr>
          <xsl:value-of select="$newline"/>
      </xsl:for-each>
    </table><br/><xsl:value-of select="$newline"/>
    
    <table border="1" cellpadding="3" width="100%">
        <tr BGCOLOR="#CCCCFF"><td>
            <a name="method_detail">
            <font size="+2">Method Detail</font>
            </a>
        </td></tr>
        <xsl:for-each select="Method">
        <!--need to change for new sidl.dtd needs to handle attributes shortname and extension instead of name  -->
            <xsl:sort select="@name"/> 
            
            <xsl:variable name="mName">
                <xsl:call-template name="methodName"/>
            </xsl:variable>
            <xsl:variable name="mParams">
                <xsl:call-template name="methodParams"/>
            </xsl:variable>
        
        <tr>
        <td>
            <xsl:call-template name="returnValue"/><xsl:text> </xsl:text>
            <a name="{$mName}{$mParams}">
                <xsl:value-of select="$mName"/><xsl:call-template name="methodParams"/>
            </a>
        
        
      
            <xsl:value-of select="$newline"/>
                <xsl:if test="Comment/node()">
                
                    <xsl:apply-templates select="Comment"/>
                
                <xsl:value-of select="$newline"/>
            </xsl:if>
        </td>
        </tr>
        <xsl:value-of select="$newline"/>
        
    </xsl:for-each>
    </table>
  </xsl:template>
  
  
  <xsl:template match="ArgumentList">
    <xsl:if test="Argument">
    <tr><th>Type</th><th>Name</th><th>mode</th><th>copy</th></tr>
    <xsl:value-of select="$newline"/>
      <xsl:for-each select="Argument">
    <tr>
    <xsl:value-of select="$newline"/>
      <xsl:choose>
      <xsl:when test="Type/Array">
	<td><xsl:apply-templates select="Type"/></td>
      </xsl:when>
      <xsl:when test="Type/Symbol">
	<td><xsl:apply-templates select="Type"/></td>
      </xsl:when>
      <xsl:otherwise>
        <td><xsl:value-of select="Type/@type"/></td>
      </xsl:otherwise>
      </xsl:choose>
      <xsl:value-of select="$newline"/>
      <td>
	<xsl:value-of select="@name"/>
      </td>
      <xsl:value-of select="$newline"/>
      <td><xsl:value-of select="@mode"/></td>
      <xsl:value-of select="$newline"/>
      <td><xsl:value-of select="@copy"/></td>
      <xsl:value-of select="$newline"/>
	</tr>
        <xsl:value-of select="$newline"/>
    </xsl:for-each>
    </xsl:if>
  </xsl:template>

  <xsl:template match="Type">
    <xsl:apply-templates select="SymbolName"/>
    <xsl:apply-templates select="Array"/>
  </xsl:template>

  <xsl:template match="Array">
    <xsl:choose>
    <xsl:when test="Type/Array">
     <xsl:apply-templates select="Type"/> 
    </xsl:when>
    <xsl:when test="Type/SymbolName">
     <xsl:apply-templates select="Type"/> 
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="Type/@type"/>
    </xsl:otherwise>
    </xsl:choose>
    []
  </xsl:template>

</xsl:stylesheet>

