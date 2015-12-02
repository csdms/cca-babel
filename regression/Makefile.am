##
## File:        Makefile.am
## Package:     Babel regression checks
## Revision:    $Revision: 6494 $
## Modified:    $Date: 2008-09-04 16:24:45 -0700 (Thu, 04 Sep 2008) $
## Description: automake makefile for all regression tests
##
## Copyright (c) 2000-2007, The Regents of the University of Calfornia.
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




#
# Override the standard automake behavior when recursing into subdirectories.
# We only want to build the regression tests if we've specified the check
# target.  For installcheck, we will check against the installed version of
# the library and not the local version.
#

SUBDIRS = output args arrays contracts enums exceptions hooks inherit  \
             objarg ordering overload sort strings struct wrapper \
	     construct structBindC

MAKE_MODULES = include/libC.make   include/libCxx.make			\
	       include/libF77.make include/libF90.make                  \
               include/runC.make   include/runCxx.make 			\
               include/runF77.make include/runF90.make			\
	       include/runPy.make  include/runJava.make			\
	       include/libPython.make include/runPy2Py.make             \
	       include/libWrapC.make   include/libWrapCxx.make		\
	       include/libWrapF77.make include/libWrapF90.make          \
               include/runWrapC.make   include/runWrapCxx.make 		\
               include/runWrapF77.make include/runWrapF90.make		\
	       include/runWrapPy.make  include/runWrapJava.make		\
	       include/libWrapPython.make include/runWrapPy2Py.make     \
               include/runSIDL.make

GANTLET_MODULES = \
	gantlet/classic_display.py     gantlet/__init__.py \
	gantlet/commandline.py         gantlet/ProgressMeter.py \
	gantlet/debug_display.py       gantlet/result_base.py \
	gantlet/email_display.py       gantlet/scoreboard.py \
	gantlet/events.py              gantlet/session_archiver.py \
	gantlet/exit_status_result.py  gantlet/session_email_parser.py \
	gantlet/filesys.py             gantlet/session_pop_client.py \
	gantlet/gts_result.py          gantlet/test_invocation.py \
	gantlet/gts_tparser_exec.py    gantlet/tparser_base.py \
	gantlet/gts_tparser.py         gantlet/tparser_factory.py \
	gantlet/gts_tparser_read.py    gantlet/unknown_tparser.py \
	gantlet/gts_tparser_script.py  gantlet/xml_display.py \
	gantlet/gui_display.py         gantlet/xml_result.py \
	gantlet/html_viewer.py         gantlet/xml_tparser.py \
	gantlet/gantlet.cfg

EXTRA_DIST = $(MAKE_MODULES) $(GANTLET_MODULES) check_valgrind.py \
	check_leaks.py

check-local: 
	export CHECK_COMMAND='check'; \
	$(MAKE) $(AM_MAKEFLAGS)	run-gantlet

installcheck-local: 
	export CHECK_COMMAND='installcheck'; \
	$(MAKE) $(AM_MAKEFLAGS)	run-gantlet

distclean-local:
	rm -f check.brief.log check.full.log check.summary.log gantlet_archive.xml

#
# Python setup for gantlet
#

PYTHON = @PYTHON@
host = @host@

RUNPYTEST = PYTHONPATH=$$PYTHONPATH:$(srcdir) $(PYTHON) $(srcdir)/gantlet/commandline.py \
		-d -k$(PACKAGE) -c$(host)


#
# Run the test scripts and report errors
#
if SUPPORT_JAVA
SHAREDF77JAVA=args/runJava/runJava2F77.sh \
	      arrays/runJava/runJava2F77.sh \
	      enums/runJava/runJava2F77.sh \
	      exceptions/runJava/runJava2F77.sh \
	      hooks/runJava/runJava2F77.sh \
	      inherit/runJava/runJava2F77.sh \
	      ordering/runJava/runJava2F77.sh \
	      overload/runJava/runJava2F77.sh \
	      strings/runJava/runJava2F77.sh \
	      sort/runJava/runJava2F77.sh \
	      wrapper/runJava/runJava2F77.sh 
SHAREDF90JAVA=args/runJava/runJava2F90.sh \
	      arrays/runJava/runJava2F90.sh \
	      enums/runJava/runJava2F90.sh \
	      exceptions/runJava/runJava2F90.sh \
	      hooks/runJava/runJava2F90.sh \
	      inherit/runJava/runJava2F90.sh \
	      ordering/runJava/runJava2F90.sh \
	      overload/runJava/runJava2F90.sh \
	      strings/runJava/runJava2F90.sh \
	      objarg/runJava/runJava2F90.sh \
	      sort/runJava/runJava2F90.sh \
	      wrapper/runJava/runJava2F90.sh
SHAREDCJAVA=args/runJava/runJava2C.sh \
	      arrays/runJava/runJava2C.sh \
	      enums/runJava/runJava2C.sh \
	      exceptions/runJava/runJava2C.sh \
	      hooks/runJava/runJava2C.sh \
	      inherit/runJava/runJava2C.sh \
	      objarg/runJava/runJava2C.sh\
	      ordering/runJava/runJava2C.sh \
	      overload/runJava/runJava2C.sh \
	      sort/runJava/runJava2C.sh \
	      strings/runJava/runJava2C.sh \
	      wrapper/runJava/runJava2C.sh

SHAREDCXXJAVA=args/runJava/runJava2Cxx.sh \
	      arrays/runJava/runJava2Cxx.sh \
	      enums/runJava/runJava2Cxx.sh \
	      exceptions/runJava/runJava2Cxx.sh \
	      hooks/runJava/runJava2Cxx.sh \
	      inherit/runJava/runJava2Cxx.sh \
	      objarg/runJava/runJava2Cxx.sh\
	      ordering/runJava/runJava2Cxx.sh \
	      overload/runJava/runJava2Cxx.sh \
	      sort/runJava/runJava2Cxx.sh \
	      strings/runJava/runJava2Cxx.sh \
	      wrapper/runJava/runJava2Cxx.sh 

if SERVER_PYTHON
PYSERVERTOJAVA=wrapper/runPython/runPy2Java
else
PYSERVERTOJAVA=
endif

SHAREDPYTHONJAVA=args/runPython/runPy2Java \
              arrays/runPython/runPy2Java \
	      exceptions/runPython/runPy2Java \
	      hooks/runPython/runPy2Java \
	      inherit/runPython/runPy2Java \
              objarg/runPython/runPy2Java \
	      ordering/runPython/runPy2Java \
	      overload/runPython/runPy2Java \
	      sort/runPython/runPy2Java \
	      strings/runPython/runPy2Java \
	      $(PYSERVERTOJAVA)

SHAREDJAVAJAVA= arrays/runJava/runJava2Java.sh \
	      enums/runJava/runJava2Java.sh \
	      exceptions/runJava/runJava2Java.sh \
	      hooks/runJava/runJava2Java.sh \
	      inherit/runJava/runJava2Java.sh \
	      objarg/runJava/runJava2Java.sh\
	      ordering/runJava/runJava2Java.sh \
	      overload/runJava/runJava2Java.sh \
	      sort/runJava/runJava2Java.sh \
	      strings/runJava/runJava2Java.sh \
	      wrapper/runJava/runJava2Java.sh
else
SHAREDF77JAVA=
SHAREDF90JAVA=
SHAREDCJAVA=
SHAREDCXXJAVA=
SHAREDPYTHONJAVA=
SHAREDJAVAJAVA=
endif

if SUPPORT_FORTRAN77
STATIC_FORTRAN77 = \
	      args/runC/runC2F77@EXEEXT@ \
	      args/runCxx/runCxx2F77@EXEEXT@ \
	      args/runF77/runF772C@EXEEXT@ \
	      args/runF77/runF772Cxx@EXEEXT@ \
	      args/runF77/runF772F77@EXEEXT@ \
	      arrays/runC/runC2F77@EXEEXT@ \
	      arrays/runCxx/runCxx2F77@EXEEXT@ \
	      arrays/runF77/runF772C@EXEEXT@ \
	      arrays/runF77/runF772Cxx@EXEEXT@ \
	      arrays/runF77/runF772F77@EXEEXT@ \
	      contracts/runC/runC2F77@EXEEXT@ \
	      contracts/runCxx/runCxx2F77@EXEEXT@ \
	      enums/runC/runC2F77@EXEEXT@ \
	      enums/runCxx/runCxx2F77@EXEEXT@ \
	      exceptions/runC/runC2F77@EXEEXT@ \
	      exceptions/runCxx/runCxx2F77@EXEEXT@ \
	      exceptions/runF77/runF772C@EXEEXT@ \
	      exceptions/runF77/runF772Cxx@EXEEXT@ \
	      exceptions/runF77/runF772F77@EXEEXT@ \
	      hooks/runC/runC2F77@EXEEXT@ \
	      hooks/runCxx/runCxx2F77@EXEEXT@ \
	      hooks/runF77/runF772C@EXEEXT@ \
	      hooks/runF77/runF772Cxx@EXEEXT@ \
	      hooks/runF77/runF772F77@EXEEXT@ \
	      inherit/runC/runC2F77@EXEEXT@ \
	      inherit/runCxx/runCxx2F77@EXEEXT@ \
	      inherit/runF77/runF772C@EXEEXT@ \
	      inherit/runF77/runF772Cxx@EXEEXT@ \
	      inherit/runF77/runF772F77@EXEEXT@ \
	      ordering/runC/runC2F77@EXEEXT@ \
	      ordering/runCxx/runCxx2F77@EXEEXT@ \
	      overload/runC/runC2F77@EXEEXT@ \
	      overload/runCxx/runCxx2F77@EXEEXT@ \
	      overload/runF77/runF772C@EXEEXT@ \
	      overload/runF77/runF772Cxx@EXEEXT@ \
	      overload/runF77/runF772F77@EXEEXT@ \
	      sort/runC/runC2F77@EXEEXT@ \
	      sort/runCxx/runCxx2F77@EXEEXT@ \
	      sort/runF77/runF772C@EXEEXT@ \
	      sort/runF77/runF772Cxx@EXEEXT@ \
	      sort/runF77/runF772F77@EXEEXT@ \
	      strings/runC/runC2F77@EXEEXT@ \
	      strings/runCxx/runCxx2F77@EXEEXT@ \
	      strings/runF77/runF772C@EXEEXT@ \
	      strings/runF77/runF772Cxx@EXEEXT@ \
	      strings/runF77/runF772F77@EXEEXT@ \
	      wrapper/runC/runC2F77@EXEEXT@ \
	      wrapper/runCxx/runCxx2F77@EXEEXT@ \
	      wrapper/runF77/runF772C@EXEEXT@ \
	      wrapper/runF77/runF772Cxx@EXEEXT@ \
	      wrapper/runF77/runF772F77@EXEEXT@ 

SHARED_FORTRAN77 = \
	      args/runF77/runAll.sh \
	      arrays/runF77/runAll.sh \
	      exceptions/runF77/runAll.sh \
	      hooks/runF77/runAll.sh \
	      inherit/runF77/runAll.sh \
	      overload/runF77/runAll.sh \
	      sort/runF77/runAll.sh \
	      strings/runF77/runAll.sh \
	      wrapper/runF77/runAll.sh \
	      $(SHAREDF77JAVA)

if SERVER_PYTHON
PYSERVERTOF77=wrapper/runPython/runPy2F77
else
PYSERVERTOF77=
endif

PYTHON_FORTRAN77 = \
	      args/runPython/runPy2F77		\
	      arrays/runPython/runPy2F77	\
	      exceptions/runPython/runPy2F77	\
	      hooks/runPython/runPy2F77	\
	      inherit/runPython/runPy2F77	\
	      ordering/runPython/runPy2F77	\
	      overload/runPython/runPy2F77	\
	      sort/runPython/runPy2F77		\
	      strings/runPython/runPy2F77	\
	      $(PYSERVERTOF77)

endif
if SUPPORT_FORTRAN90
if SUPPORT_FORTRAN03
STATIC_BINDC=    \
	        structBindC/runC/runC2F03@EXEEXT@ \
	        structBindC/runCxx/runCxx2F03@EXEEXT@ \
	        structBindC/runF03/runF032C@EXEEXT@ \
	        structBindC/runF03/runF032Cxx@EXEEXT@ \
	        structBindC/runF03/runF032F03@EXEEXT@ 
endif
STATIC_FORTRAN90 = \
	      args/runC/runC2F90@EXEEXT@ \
	      args/runCxx/runCxx2F90@EXEEXT@ \
	      args/runF90/runF902C@EXEEXT@ \
	      args/runF90/runF902Cxx@EXEEXT@ \
	      args/runF90/runF902F90@EXEEXT@ \
	      arrays/runC/runC2F90@EXEEXT@ \
	      arrays/runCxx/runCxx2F90@EXEEXT@ \
	      arrays/runF90/runF902C@EXEEXT@ \
	      arrays/runF90/runF902Cxx@EXEEXT@ \
	      contracts/runC/runC2F90@EXEEXT@ \
	      contracts/runCxx/runCxx2F90@EXEEXT@ \
	      enums/runC/runC2F90@EXEEXT@ \
	      enums/runCxx/runCxx2F90@EXEEXT@ \
	      exceptions/runC/runC2F90@EXEEXT@ \
	      exceptions/runCxx/runCxx2F90@EXEEXT@ \
	      exceptions/runF90/runF902C@EXEEXT@ \
	      exceptions/runF90/runF902Cxx@EXEEXT@ \
	      exceptions/runF90/runF902F90@EXEEXT@ \
	      hooks/runC/runC2F90@EXEEXT@ \
	      hooks/runCxx/runCxx2F90@EXEEXT@ \
	      hooks/runF90/runF902C@EXEEXT@ \
	      hooks/runF90/runF902Cxx@EXEEXT@ \
	      hooks/runF90/runF902F90@EXEEXT@ \
	      inherit/runC/runC2F90@EXEEXT@ \
	      inherit/runCxx/runCxx2F90@EXEEXT@ \
	      inherit/runF90/runF902C@EXEEXT@ \
	      inherit/runF90/runF902Cxx@EXEEXT@ \
	      inherit/runF90/runF902F90@EXEEXT@ \
	      objarg/runC/runC2F90@EXEEXT@ \
	      objarg/runCxx/runCxx2F90@EXEEXT@ \
	      ordering/runC/runC2F90@EXEEXT@ \
	      ordering/runCxx/runCxx2F90@EXEEXT@ \
	      overload/runC/runC2F90@EXEEXT@ \
	      overload/runCxx/runCxx2F90@EXEEXT@ \
	      overload/runF90/runF902C@EXEEXT@ \
	      overload/runF90/runF902Cxx@EXEEXT@ \
	      overload/runF90/runF902F90@EXEEXT@ \
	      sort/runC/runC2F90@EXEEXT@ \
	      sort/runCxx/runCxx2F90@EXEEXT@ \
	      sort/runF90/runF902C@EXEEXT@ \
	      sort/runF90/runF902Cxx@EXEEXT@ \
	      sort/runF90/runF902F90@EXEEXT@ \
	      strings/runC/runC2F90@EXEEXT@ \
	      strings/runCxx/runCxx2F90@EXEEXT@ \
	      strings/runF90/runF902C@EXEEXT@ \
	      strings/runF90/runF902Cxx@EXEEXT@ \
	      strings/runF90/runF902F90@EXEEXT@ \
	      wrapper/runC/runC2F90@EXEEXT@ \
	      wrapper/runCxx/runCxx2F90@EXEEXT@ \
	      wrapper/runF90/runF902C@EXEEXT@ \
	      wrapper/runF90/runF902Cxx@EXEEXT@ \
	      wrapper/runF90/runF902F90@EXEEXT@ 

SHARED_FORTRAN90 = \
	      args/runF90/runAll.sh \
	      arrays/runF90/runAll.sh \
	      exceptions/runF90/runAll.sh \
	      hooks/runF90/runAll.sh \
	      inherit/runF90/runAll.sh \
	      overload/runF90/runAll.sh \
	      sort/runF90/runAll.sh \
	      strings/runF90/runAll.sh \
	      wrapper/runF90/runAll.sh \
	      $(SHAREDF90JAVA)
if SERVER_PYTHON
PYSERVERTOF90=wrapper/runPython/runPy2F90
else
PYSERVERTOF90=
endif


PYTHON_FORTRAN90 = \
	      args/runPython/runPy2F90		\
	      arrays/runPython/runPy2F90	\
	      exceptions/runPython/runPy2F90	\
	      hooks/runPython/runPy2F90	\
	      inherit/runPython/runPy2F90	\
	      objarg/runPython/runPy2F90 	\
	      ordering/runPython/runPy2F90	\
	      overload/runPython/runPy2F90	\
	      sort/runPython/runPy2F90		\
	      strings/runPython/runPy2F90	\
	      $(PYSERVERTOF90)
endif
if SUPPORT_FORTRAN77
if SUPPORT_FORTRAN90
STATIC_F77_F90 = \
	      args/runF77/runF772F90		\
	      args/runF90/runF902F77		\
	      arrays/runF90/runF902F77		\
	      exceptions/runF77/runF772F90	\
	      exceptions/runF90/runF902F77	\
	      hooks/runF77/runF772F90	\
	      hooks/runF90/runF902F77	\
	      inherit/runF77/runF772F90		\
	      inherit/runF90/runF902F77		\
	      overload/runF77/runF772F90	\
	      overload/runF90/runF902F77	\
	      sort/runF77/runF772F90		\
	      sort/runF90/runF902F77		\
	      strings/runF77/runF772F90		\
	      strings/runF90/runF902F77		\
	      wrapper/runF77/runF772F90		\
	      wrapper/runF90/runF902F77	
endif
endif
if SUPPORT_STATIC
STATICTESTS = \
	      construct/checkCtorDtor@EXEEXT@ \
	      args/runC/runC2C@EXEEXT@ \
	      args/runC/runC2Cxx@EXEEXT@ \
	      args/runCxx/runCxx2C@EXEEXT@ \
	      args/runCxx/runCxx2Cxx@EXEEXT@ \
	      arrays/runC/runC2C@EXEEXT@ \
	      arrays/runC/runC2Cxx@EXEEXT@ \
	      arrays/runCxx/runCxx2C@EXEEXT@ \
	      arrays/runCxx/runCxx2Cxx@EXEEXT@ \
	      contracts/runC/runC2C@EXEEXT@ \
	      contracts/runC/runC2Cxx@EXEEXT@ \
	      contracts/runCxx/runCxx2C@EXEEXT@ \
	      contracts/runCxx/runCxx2Cxx@EXEEXT@ \
	      enums/runC/runC2C@EXEEXT@ \
	      enums/runC/runC2Cxx@EXEEXT@ \
	      enums/runCxx/runCxx2C@EXEEXT@ \
	      enums/runCxx/runCxx2Cxx@EXEEXT@ \
	      exceptions/runC/runC2C@EXEEXT@ \
	      exceptions/runC/runC2Cxx@EXEEXT@ \
	      exceptions/runCxx/runCxx2C@EXEEXT@ \
	      exceptions/runCxx/runCxx2Cxx@EXEEXT@ \
	      hooks/runC/runC2C@EXEEXT@ \
	      hooks/runC/runC2Cxx@EXEEXT@ \
	      hooks/runCxx/runCxx2C@EXEEXT@ \
	      hooks/runCxx/runCxx2Cxx@EXEEXT@ \
	      inherit/runC/runC2C@EXEEXT@ \
	      inherit/runC/runC2Cxx@EXEEXT@ \
	      inherit/runCxx/runCxx2C@EXEEXT@ \
	      inherit/runCxx/runCxx2Cxx@EXEEXT@ \
	      objarg/runC/runC2C@EXEEXT@ \
	      objarg/runC/runC2Cxx@EXEEXT@ \
	      objarg/runCxx/runCxx2C@EXEEXT@ \
	      objarg/runCxx/runCxx2Cxx@EXEEXT@ \
	      ordering/runC/runC2C@EXEEXT@ \
	      ordering/runC/runC2Cxx@EXEEXT@ \
	      ordering/runCxx/runCxx2C@EXEEXT@ \
	      ordering/runCxx/runCxx2Cxx@EXEEXT@ \
	      overload/runC/runC2C@EXEEXT@ \
	      overload/runC/runC2Cxx@EXEEXT@ \
	      overload/runCxx/runCxx2C@EXEEXT@ \
	      overload/runCxx/runCxx2Cxx@EXEEXT@ \
	      sort/runC/runC2C@EXEEXT@ \
	      sort/runC/runC2Cxx@EXEEXT@ \
	      sort/runCxx/runCxx2C@EXEEXT@ \
	      sort/runCxx/runCxx2Cxx@EXEEXT@ \
	      strings/runC/runC2C@EXEEXT@ \
	      strings/runC/runC2Cxx@EXEEXT@ \
	      strings/runCxx/runCxx2C@EXEEXT@ \
	      strings/runCxx/runCxx2Cxx@EXEEXT@ \
	      struct/runC/runC2C@EXEEXT@ \
	      struct/runC/runC2Cxx@EXEEXT@ \
	      struct/runCxx/runCxx2C@EXEEXT@ \
	      struct/runCxx/runCxx2Cxx@EXEEXT@ \
	      structBindC/runC/runC2C@EXEEXT@ \
	      structBindC/runC/runC2Cxx@EXEEXT@ \
	      structBindC/runCxx/runCxx2C@EXEEXT@ \
	      structBindC/runCxx/runCxx2Cxx@EXEEXT@ \
	      wrapper/runC/runC2C@EXEEXT@ \
	      wrapper/runC/runC2Cxx@EXEEXT@ \
	      wrapper/runCxx/runCxx2C@EXEEXT@ \
	      wrapper/runCxx/runCxx2Cxx@EXEEXT@ \
	      $(STATIC_FORTRAN77) \
	      $(STATIC_FORTRAN90) \
	      $(STATIC_F77_F90) \
	      $(STATIC_BINDC)
endif

if SUPPORT_SHARED
SHAREDTESTS = \
	      $(SHAREDCJAVA) \
	      $(SHAREDCXXJAVA) \
	      $(SHAREDJAVAJAVA) \
	      args/runC/runAll.sh \
	      args/runCxx/runAll.sh \
	      arrays/runC/runAll.sh \
	      arrays/runCxx/runAll.sh \
	      contracts/runC/runAll.sh \
	      contracts/runCxx/runAll.sh \
	      enums/runC/runAll.sh \
	      enums/runCxx/runAll.sh \
	      exceptions/runC/runAll.sh \
	      exceptions/runCxx/runAll.sh \
	      hooks/runC/runAll.sh \
	      hooks/runCxx/runAll.sh \
	      inherit/runC/runAll.sh \
	      inherit/runCxx/runAll.sh \
	      objarg/runC/runAll.sh \
	      objarg/runCxx/runAll.sh \
	      ordering/runC/runAll.sh \
	      ordering/runCxx/runAll.sh \
	      overload/runC/runAll.sh \
	      overload/runCxx/runAll.sh \
	      sort/runC/runAll.sh \
	      sort/runCxx/runAll.sh \
	      strings/runC/runAll.sh \
	      strings/runCxx/runAll.sh \
	      struct/runC/runAll.sh \
	      struct/runCxx/runAll.sh \
	      wrapper/runC/runAll.sh \
	      wrapper/runCxx/runAll.sh \
	      $(SHARED_FORTRAN77) \
	      $(SHARED_FORTRAN90)
endif
if SUPPORT_PYTHON
PYTHONTESTS = \
	      args/runPython/runPy2C \
	      args/runPython/runPy2Cxx \
	      arrays/runPython/runPy2C \
	      arrays/runPython/runPy2Cxx \
	      exceptions/runPython/runPy2C \
	      exceptions/runPython/runPy2Cxx \
	      hooks/runPython/runPy2C \
	      hooks/runPython/runPy2Cxx \
	      inherit/runPython/runPy2C \
	      inherit/runPython/runPy2Cxx \
	      objarg/runPython/runPy2C \
	      objarg/runPython/runPy2Cxx \
	      ordering/runPython/runPy2C \
	      ordering/runPython/runPy2Cxx \
	      overload/runPython/runPy2C \
	      overload/runPython/runPy2Cxx \
	      sort/runPython/runPy2C \
	      sort/runPython/runPy2Cxx \
	      strings/runPython/runPy2C \
	      strings/runPython/runPy2Cxx \
	      struct/runPython/runPy2C \
	      struct/runPython/runPy2Cxx \
	      $(SHAREDPYTHONJAVA) \
	      $(PYTHON_FORTRAN77) \
              $(PYTHON_FORTRAN90)


endif

if SERVER_PYTHON
if SUPPORT_JAVA
JAVAPYTESTS = \
		args/runJava/runJava2Py.sh \
		arrays/runJava/runJava2Py.sh \
		exceptions/runJava/runJava2Py.sh \
		hooks/runJava/runJava2Py.sh \
		inherit/runJava/runJava2Py.sh \
		ordering/runJava/runJava2Py.sh \
		overload/runJava/runJava2Py.sh \
		strings/runJava/runJava2Py.sh \
		objarg/runJava/runJava2Py.sh \
		sort/runJava/runJava2Py.sh \
		wrapper/runJava/runJava2Py.sh
endif

PYSERVERTESTS = $(JAVAPYTESTS) \
		args/runPython/Py2Py/runPy2Py.sh \
		exceptions/runPython/Py2Py/runPy2Py.sh \
		hooks/runPython/Py2Py/runPy2Py.sh \
		inherit/runPython/Py2Py/runPy2Py.sh \
		objarg/runPython/Py2Py/runPy2Py.sh \
		overload/runPython/Py2Py/runPy2Py.sh \
		struct/runPython/Py2Py/runPy2Py.sh \
		sort/runPython/Py2Py/runPy2Py.sh \
		strings/runPython/Py2Py/runPy2Py.sh \
		wrapper/runPython/Py2Py/runPy2Py.sh \
		wrapper/runPython/runPy2C \
		wrapper/runPython/runPy2Cxx

endif

sidlTESTS =	args/runSIDL/runSIDL.sh 	\
		arrays/runSIDL/runSIDL.sh	\
		contracts/runSIDL/runSIDL.sh	\
		enums/runSIDL/runSIDL.sh	\
		exceptions/runSIDL/runSIDL.sh	\
		hooks/runSIDL/runSIDL.sh	\
		inherit/runSIDL/runSIDL.sh	\
		objarg/runSIDL/runSIDL.sh	\
		ordering/runSIDL/runSIDL.sh	\
		overload/runSIDL/runSIDL.sh	\
		sort/runSIDL/runSIDL.sh		\
		strings/runSIDL/runSIDL.sh	\
		wrapper/runSIDL/runSIDL.sh \
		structBindC/runSIDL/runSIDL.sh \
		struct/runSIDL/runSIDL.sh

ALLTESTS = $(STATICTESTS) $(SHAREDTESTS) $(PYTHONTESTS) $(PYSERVERTESTS) \
           $(sidlTESTS)

run-gantlet:
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run tests without python 2.1 or greater" ;\
	else :; \
	  if test "X$$PROFILE_NAME" = X; then \
	    PROFILE_NAME="$(host)"; \
          fi; \
	  if test "X$(SESSION)" != X; then \
	    session_name="$(SESSION)"; \
          else  \
            session_name="default_$$CHECK_COMMAND"; \
          fi; \
	  echo "" $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" \$$\(ALLTESTS\) ;\
	  $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" $(ALLTESTS) ;\
	fi 

run-gantlet-quick:
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run tests without python 2.1 or greater" ;\
	else :; \
	  if test "X$$PROFILE_NAME" = X; then \
	    PROFILE_NAME="$(host)"; \
          fi; \
	  if test "X$(SESSION)" != X; then \
	    session_name="$(SESSION)"; \
          else \
            session_name="default_$$CHECK_COMMAND"; \
          fi; \
	  echo "" $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" ;\
	  $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" ;\
	fi 

run-icgantlet: 
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run tests without python 2.1 or greater" ;\
	else :; \
	  if test "X$$PROFILE_NAME" = X; then \
	    PROFILE_NAME="$(host)"; \
          fi; \
	  if test "X$(SESSION)" != X; then \
	    session_name="$(SESSION)"; \
          else \
            session_name="default_$$CHECK_COMMAND"; \
          fi; \
	  echo "PYTHONPATH=$(prefix)/python:$${PYTHONPATH}" $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" \$$\(ALLTESTS\) ;\
	  PYTHONPATH=$(prefix)/python:$${PYTHONPATH} $(RUNPYTEST) -p "$$PROFILE_NAME" $(PYFLAGS) "$$session_name" $(ALLTESTS) ;\
	fi 

run-valgrind:
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run valgrind tests without python" ; \
	else \
	  $(PYTHON) $(srcdir)/check_valgrind.py --suppressions=$(srcdir)/babel_valgrind.supp $(STATICTESTS) ; \
	fi

run-leakcheck:
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run leak tests without python" ; \
	else \
	  if test "X$(SESSION)" = X; then \
	    sessionarg=" "; \
	  else \
	    sessionarg='--session="$(SESSION)" '; \
          fi ; \
	  if test "X$(SUMMARY_LOG)" = X; then \
	    summarylog=" "; \
	  else \
	    summarylog='--summary-file="$(SUMMARY_LOG)" '; \
          fi ; \
	  $(PYTHON) $$sessionarg $$summarylog $(srcdir)/check_leaks.py  $(STATICTESTS) $(SHAREDTESTS) $(PYTHONTESTS) $(PYSERVERTESTS) ; \
	fi

run-leakcheck-quiet:
	@if test "X$(PYTHON)" = X; then \
	  echo "WARNING: Cannot run leak tests without python" ; \
	else \
	  if test "X$(SESSION)" = X; then \
	    sessionarg=" "; \
	  else \
	    sessionarg='--session=$(SESSION) '; \
          fi ; \
	  if test "X$(SUMMARY_LOG)" = X; then \
	    summarylog=" "; \
	  else \
	    summarylog='--summary-file=$(SUMMARY_LOG) '; \
          fi ; \
	  $(PYTHON) $(srcdir)/check_leaks.py --summary-only $$sessionarg $$summarylog $(STATICTESTS) $(SHAREDTESTS) $(PYTHONTESTS) $(PYSERVERTESTS) ; \
	fi
