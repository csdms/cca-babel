<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    
    <xsl:output method="html" doctype-public='-//W3C//DTD HTML 4.0 TRANSITIONAL//EN"' doctype-system="http://www.w3c.org/TR/REC-html40/loose.dtd"/>
    
    <xsl:variable name="newline">
    <xsl:text>  
    </xsl:text>
    </xsl:variable>
    
    <xsl:template match="/">
        <xsl:apply-templates select="Library"/>
    </xsl:template>
    
    
    <xsl:template match="Library">
        <html>  
        <xsl:value-of select="$newline"/>             
            <head>
                <xsl:call-template name="generateDateStamp">
                    <xsl:with-param name="printDate" select="@date"/>  
                </xsl:call-template>
                <Title>Package Summary</Title>
                
                <LINK REL="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style"/>      
            </head> 
            <body>
            <xsl:call-template name="navBarCreate"/>
            <hr></hr>
            
            <xsl:apply-templates select="Package"/>
            </body>
         </html>
    </xsl:template>
    
    
    <xsl:template match="Package">
        <xsl:variable name="count" select="'first'"/>
        <xsl:variable name="packagename"><xsl:value-of select="@name"/></xsl:variable>
        <table border="0" cellpadding="3" width="100%">
            <tr>
                <td WIDTH="20%">
                    <h2><xsl:value-of select="@name"/>-v<xsl:value-of select="@version"/></h2>
                </td>
                <td>
                    <xsl:value-of select="Comment/text()"/>
                </td>
             </tr>
        </table>
        <xsl:if test="Interfaces/Symbol">  
            <table border="1" cellpadding="2" width="100%">
                <tr BGCOLOR="#CCCCFF">
                    <td COLSPAN="3">
                        <font SIZE="+2">
                            Interface Summary
                        </font>
                    </td>
                </tr>
            <xsl:for-each select="Interfaces/Symbol">
                <xsl:call-template name="do-symbol-row"/>
            </xsl:for-each>
            </table>
        </xsl:if>
        <br/>
        <xsl:if test="Classes/Symbol">  
            <table border="1" cellpadding="2" width="100%">
                <tr BGCOLOR="#CCCCFF">
                    <td COLSPAN="3">
                        <font SIZE="+2">
                            Class Summary
                        </font>
                    </td>
                </tr>
            <xsl:for-each select="Classes/Symbol">
                <xsl:call-template name="do-symbol-row"/>
            </xsl:for-each>
            </table>
        </xsl:if>
        <br/>
        <xsl:if test="Enumerations/Symbol">  
            <table border="1" cellpadding="2" width="100%">
                <tr BGCOLOR="#CCCCFF">
                    <td COLSPAN="3">
                        <font SIZE="+2">
                            Enumeration Summary
                        </font>
                    </td>
                </tr>
            <xsl:for-each select="Enumeratios/Symbol">
                <xsl:call-template name="do-symbol-row"/>
            </xsl:for-each>
            </table>
        </xsl:if>
               
       <br/>
        <br/><hr></hr><br/>
    </xsl:template>
    
    <xsl:template name="do-symbol-row">
        <xsl:variable name="comment"><xsl:value-of select="Comment/text()"/></xsl:variable>
        <tr>
            <td WIDTH="15%" border="1">
                <a href="{SymbolName/@name}-v{SymbolName/@version}.html">
                    <xsl:value-of select="SymbolName/@name"/>-v<xsl:value-of select="SymbolName/@version"/>
                </a>
            </td>
            <td border="1">
                <xsl:value-of select="$comment"/><xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
            </td>
        </tr>
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
                <TD BGCOLOR="#FFFFFF" CLASS="NavBarCell1Rev"> 
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>   
                        <FONT CLASS="NavBarFont1Rev">Package</FONT>
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD CLASS="NavBarCell1" BGCOLOR="#EEEEFF" >
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                        <!--<A HREF="allclasses-noframe.html">-->
                            <FONT CLASS="NavBarFont1">
                                <b>Class</b>
                            </FONT>
                        <!--</A>-->
                    <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">  
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                    <!--<A HREF="overview-tree.html">-->
                        <FONT CLASS="NavBarFont1">
                            <B>Tree</B>
                        </FONT>
                    <!--</A>-->
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">  
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>  
                    <!--<A HREF="deprecated-list.html">-->
                        <FONT CLASS="NavBarFont1">
                            <B>Deprecated</B>
                        </FONT>
                    <!--</A>-->
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1"> 
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                    <!--<A HREF="index-all.html">-->
                        <FONT CLASS="NavBarFont1">
                            <B>Index</B>
                        </FONT>
                    <!--</A>-->
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
                
                </TD>
                <xsl:value-of select="$newline"/>
                <TD BGCOLOR="#EEEEFF" CLASS="NavBarCell1">   
                <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text> 
                    <!--<A HREF="help-doc.html">-->
                        <FONT CLASS="NavBarFont1">
                            <B>Help</B>
                        </FONT>
                    <!--</A>-->
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
        <FONT SIZE="-2">PREV</FONT>
        <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
        <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
        <FONT SIZE="-2">NEXT</FONT>
        </TD>
        <xsl:value-of select="$newline"/>
        <TD BGCOLOR="white" CLASS="NavBarCell2"><FONT SIZE="-2">
        
            <A HREF="index.html" TARGET="_top"><B>FRAMES</B></A> 
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
        <xsl:comment>========== END OF NAVBAR ==========</xsl:comment>
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
     
</xsl:stylesheet>