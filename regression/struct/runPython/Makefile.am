##
## File:        Makefile.am
## Package:     Babel args regression tests
## Revision:    $Revision: 6192 $
## Modified:    $Date: 2007-10-22 16:12:59 -0700 (Mon, 22 Oct 2007) $
## Description: automake makefile for python args regression tests
##
## Copyright (c) 2007, Lawrence Livermore National Security, LLC.
## Produced at the Lawrence Livermore National Laboratory.
## Written by the Components Team <components@llnl.gov>
## UCRL-CODE-2002-054
## All rights reserved.
## 
## This file is part of Babel. For more information, see
## http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
## for Our Notice and the LICENSE file for the GNU Lesser General Public
## License.
## 
## This program is free software; you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License (as published by
## the Free Software Foundation) version 2.1 dated February 1999.
## 
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
## conditions of the GNU Lesser General Public License for more details.
## 
## You should have recieved a copy of the GNU Lesser General Public License
## along with this program; if not, write to the Free Software Foundation,
## Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

TESTPROG=structtest
PYTHONISHFILES=$(TESTPROG)
SIDLFILE=$(srcdir)/../struct.sidl
sidlSUBDIR=s
PYTHONIMPL=$(sidlSUBDIR)
EXTRA_DIST=runPy2C.in runPy2Cxx.in babel.make synch_babel.make

if SUPPORT_PYTHON
DRIVERSCRIPTS=runPy2C runPy2Cxx
else
DRIVERSCRIPTS=
check-local:
	@echo "Python not supported"
endif

include $(srcdir)/../../include/runPy.make
include $(srcdir)/babel.make
include $(srcdir)/synch_babel.make

