##
## File:        Makefile.am
## Package:     Babel regression checks
## Revision:    $Revision: 4618 $
## Modified:    $Date: 2005-05-09 15:54:29 -0700 (Mon, 09 May 2005) $
## Description: automake makefile for Python regression tests
##
## Copyright (c) 2000-2001, The Regents of the University of Calfornia.
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

SERVEREXTRA = wrapper.Data
CLIENTEXTRA = wrapper.User
BABELEXTRA = -R../runSIDL/xml

TESTPROG = wraptest
PYTHONISHFILES = $(TESTPROG)
PYTHON=@PYTHON@
PYTHONIMPL = wrapper
sidlSUBDIR = wrapper
TMP_EXTRA_DIST = runPy2C.in runPy2Cxx.in runPy2F77.in runPy2F90.in runPy2Java.in

if SUPPORT_PYTHON
DRIVERSCRIPTS=runPy2C runPy2Cxx runPy2Java \
	$(PY2F90_DRIVER) $(PY2F77_DRIVER)
else
DRIVERSCRIPTS=
check-local:
	@echo "Python not supported"
endif

include $(srcdir)/../../include/runWrapPy.make
include $(srcdir)/$(PYTHONIMPL)/babel.make
include $(srcdir)/$(PYTHONIMPL)/client_babel.make 
include $(srcdir)/client_babel.make
include $(srcdir)/babel.make


