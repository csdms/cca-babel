#!/bin/sh
# File:        runPython.sh
# Copyright:   (c) 2001 Lawrence Livermore National Security, LLC
# Description: set environment variables and run python
# Revision:    $Revision$
# Date:        $Date$
#

case "`uname`" in
  CYGWIN*) cygwin=true;;
  *) cygwin=false;;
esac

PYTHONLIB=../../../runtime/sidl/.libs
PYTHONPATH=../../../runtime/python
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PYTHONLIB
SIDL_DLL_PATH="../libdecaf/libdecaf.scl;../hello-server/libHelloServer.scl;../hello-client/libHelloClient.scl"
export PYTHONPATH SIDL_DLL_PATH LD_LIBRARY_PATH

if $cygwin; then
  PATH=$PATH:$PYTHONLIB
  export PATH
fi

python HelloDriver.py 
