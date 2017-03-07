#!/usr/local/bin/python
#
# File:        helloclient
# Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
# Revision:    @(#) $Revision$
# Date:        $Date$
# Description: Simple Hello World Python client 
#

#import sidl.BaseClass
import Hello.World

if __name__ == '__main__':
  h = Hello.World.World ()
  print h.getMsg ()
