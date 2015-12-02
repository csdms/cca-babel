<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="xml"/>
    
    
    <xsl:template match="/">
            <xsl:apply-templates select="Library"/>
    </xsl:template>
    
    <xsl:template match="Library">
        <xsl:variable name="date" select="@date"/>
        <Symbols>
        <xsl:for-each select="//Symbol">
            <xsl:sort select="SymbolName/@name"/>
            <SymbolStore date="{$date}">
            <xsl:copy-of select="."/>
            </SymbolStore>
        </xsl:for-each>
        </Symbols>       
    </xsl:template>
    
   
</xsl:stylesheet>