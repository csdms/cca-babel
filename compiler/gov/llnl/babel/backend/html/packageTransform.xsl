<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
     
    <xsl:output method="xml"/>
    
    <xsl:template match="/">
        <Library date="{Files/@date}">
            <xsl:for-each select="Files/File">
                
                <xsl:call-template name="File"/>
            </xsl:for-each>
        </Library>
    </xsl:template>
   
    
    
    <xsl:template name="File">
        
        <xsl:if test="document(@fullPathName)/Symbol/Package">
        
                <xsl:variable name="name" select="document(@fullPathName)/Symbol/SymbolName/@name"/>
                <xsl:variable name="version" select="document(@fullPathName)/Symbol/SymbolName/@version"/>
                <xsl:variable name="comment" select="document(@fullPathName)/Symbol/Comment"/>
            
                <Package name="{$name}" version="{$version}"><xsl:text>
                            </xsl:text>
                    <Comment>
                        <xsl:value-of select="$comment"/>
                    </Comment>
                    <PackageSymbols><xsl:text>
                            </xsl:text>
                        <xsl:for-each select="document(@fullPathName)/Symbol/Package/PackageSymbol">
                            <xsl:sort select="@name"/>
                            <xsl:copy-of select="."/><xsl:text>
                            </xsl:text>
                        </xsl:for-each>
                    </PackageSymbols><xsl:text>
                            </xsl:text>
                    <xsl:value-of select="name()"/><xsl:text>
                            </xsl:text>
                    <Classes>
                        <xsl:value-of select="name()"/>
                        <xsl:for-each select="document(../File/@fullPathName)/Symbol/Class">
                            <xsl:sort select="../SymbolName/@name"/>
                            <xsl:value-of select="name()"/>
                            <xsl:if test="starts-with(../SymbolName/@name,$name)">
                                <xsl:copy-of select=".."/>
                            </xsl:if>
                        </xsl:for-each>
                    </Classes><xsl:text>
                            </xsl:text>
                    <Interfaces><xsl:text>
                            </xsl:text>
                        <xsl:for-each select="document(../File/@fullPathName)/Symbol/InterFace">
                            <xsl:sort select="../SymbolName/@name"/>
                            <xsl:if test="starts-with(../SymbolName/@name,$name)">
                                <xsl:copy-of select=".."/>
                            </xsl:if>
                        </xsl:for-each>
                    </Interfaces><xsl:text>
                            </xsl:text>
                    <Enumerations>
                        <xsl:for-each select="document(../File/@fullPathName)/Symbol/Enumeration">
                            <xsl:sort select="../SymbolName/@name"/>
                            <xsl:if test="starts-with(../SymbolName/@name,$name)">
                                <xsl:copy-of select=".."/>
                            </xsl:if>
                        </xsl:for-each>
                    </Enumerations>  <xsl:text>
                            </xsl:text>  
                </Package><xsl:text>
                    </xsl:text>  
        </xsl:if>
        <xsl:choose>
            <xsl:when test="document(@fullPathName)/Symbol/Package">
                
            </xsl:when>
            <xsl:otherwise>
                <xsl:copy-of select="document(@fullPathName)/Symbol"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
</xsl:stylesheet>