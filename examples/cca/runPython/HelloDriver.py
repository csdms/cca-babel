#!/usr/local/bin/python
#
# File:        HelloDriver.py
# Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
# Revision:    @(#) $Revision$
# Date:        $Date$
# Description: Simple CCA Hello World Python client 
#

import decaf.Framework
import gov.cca.ports.GoPort

if __name__ == '__main__':
  dec = decaf.Framework.Framework()
  
  server = dec.createInstance( "HelloServerInstance","HelloServer.Component", None )
  client = dec.createInstance( "HelloClientInstance","HelloClient.Component", None )
  dec.connect(client, "HelloServer", server, "HelloServer")

  port = dec.lookupPort(client, "GoPort")
  go = gov.cca.ports.GoPort.GoPort(port)
  go.go()

  dec.destroyInstance(server,0.0)
  dec.destroyInstance(client,0.0)
