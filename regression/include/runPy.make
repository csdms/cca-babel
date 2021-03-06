##
## File:        make.runPy
## Package:     Generic Makefile.am support for running Python drivers
## Revision:    $Revision: 6530 $
## Modified:    $Date: 2008-09-25 11:15:43 -0700 (Thu, 25 Sep 2008) $
## Description: automake makefile for python driver regression tests
##
## Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
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


OUTPUTSIDL=$(srcdir)/../../output/output.sidl

VERSION=@VERSION@
BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR=$(top_builddir)/bin
INCLUDEDIR=$(top_builddir)/runtime/sidl
INCLUDEDIR2=.
PYTHONDIR=$(top_builddir)/runtime/python
PYINCLUDEDIR=$(PYTHONDIR)
PYINCLUDEDIR2=.
SIDLPYTHONLIB=$(top_builddir)/runtime/sidl/.libs
SIDLPARSIFALLIB=$(top_builddir)/runtime/libparsifal/src/.libs
SIDLCHASMLITELIB=$(top_builddir)/runtime/libchasmlite/.libs
if SUPPORT_FORTRAN90
CHASMLITEDIR=`cd $(SIDLCHASMLITELIB) && pwd`
else
CHASMLITEDIR=$(SIDLCHASMLITELIB)
endif
if WITH_SIDLX
SIDLXPYTHONLIB=$(top_builddir)/runtime/sidlx/.libs
else
# use a harmless value
SIDLXPYTHONLIB=$(top_builddir)/runtime/sidl/.libs
endif
SIDLSTUBSLIB=$(top_builddir)/lib/sidlstubs
PYTHONLIB = @PYTHONLIB@
PYTHONINC=@PYTHONINC@
BABELGEN=$(IORSRCS) $(IORHDRS) $(PYMOD_HDRS) setup.py
SYNCHBABELGEN=$(synch_IORSRCS) $(synch_IORHDRS) $(synch_PYMOD_HDRS) synch_setup.py
CLEANFILES=$(BABELGEN) $(SYNCHBABELGEN)  $(EXTRACLEAN) \
	babel-stamp python-babel-stamp babel-temp \
	synch-stamp python-synch-stamp synch-temp \
	runPy2C runPy2Cxx runPy2UCxx runPy2F77 runPy2F90 runPy2Java \
	babel-stamp stamp-installcheck core babel-temp babel.make.package \
	babel.make.depends synch_babel.make.package synch_babel.make.depends


if SUPPORT_FORTRAN77
PY2F77_DRIVER=runPy2F77
else
PY2F77_DRIVER=
endif
if SUPPORT_FORTRAN90
PY2F90_DRIVER=runPy2F90
else
PY2F90_DRIVER=
endif
check_SCRIPTS = $(DRIVERSCRIPTS)

if SERVER_PYTHON
SUBDIRS = Py2Py
endif

if SUPPORT_PYTHON
python-support: python-babel-stamp $(PYTHONISHFILES) python-synch-stamp $(DRIVERSCRIPTS)

$(BABELGEN) $(PYTHONISHFILES) : babel-stamp
	@if test -f $@; then \
	   touch $@; \
	else \
	   rm -f babel-stamp; \
	   $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(SIDLFILE)
	@rm -f babel-stamp
	@touch babel-temp
	@if test "X$(srcdir)" != "X."; then				\
	  for file in $(PYTHONISHFILES); do				\
	    d=`dirname $$file`;						\
	    test -f $$d							\
	    || mkdir -p $$d						\
	    || exit 1;							\
	    echo cp -p $(srcdir)/$$file $$file;				\
	    cp -p $(srcdir)/$$file $$file;				\
	    echo chmod +x $$file;					\
	    chmod +x $$file;						\
	  done;								\
	fi
	test -f $(PYTHONIMPL)						 \
	|| mkdir -p $(PYTHONIMPL)					 \
	|| exit 1
	$(SHELL) $(BABELDIR)/$(BABEL) --client=python $(BABELEXTRA) \
		$(SIDLFILE)
	@mv -f babel-temp babel-stamp

python-babel-stamp:setup.py $(PYMOD_HDRS)
	-mkdir -p `python -c 'import distutils.util;import sys;print "build/temp."+distutils.util.get_platform()+"-"+sys.version[0:3]'`
	$(PYTHON) setup.py build_ext	\
	  --include-dirs=`cd $(INCLUDEDIR) && pwd`		\
	  --include-dirs=`cd $(INCLUDEDIR2) && pwd`		\
	  --include-dirs=`cd $(PYINCLUDEDIR) && pwd`		\
	  --include-dirs=`cd $(PYINCLUDEDIR2) && pwd`		\
	  --library-dirs=`cd $(SIDLPYTHONLIB) && pwd`		\
	  `echo $(PYTHONINC) | sed -e 's/-I/--include-dirs=/g'` \
	  --library-dirs=`cd $(SIDLXPYTHONLIB) && pwd`		\
	  --rpath=`cd $(SIDLPYTHONLIB) && pwd`		\
	  --library-dirs=`cd $(SIDLPARSIFALLIB) && pwd`		\
	  --library-dirs=$(CHASMLITEDIR)		\
	  --rpath=`cd $(SIDLPARSIFALLIB) && pwd`		\
	  --rpath=$(CHASMLITEDIR)		\
	  $(LIBPARSIFAL_PYSETUP) $(CHASM_PYSETUP) \
	  $(PYTHON_SETUP_ARGS) 					\
	  --inplace
	@touch python-babel-stamp

$(SYNCHBABELGEN):synch-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f synch-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) synch-stamp; \
	fi

synch-stamp:$(OUTPUTSIDL)
	@rm -f synch-stamp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=python --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f synch-temp synch-stamp

python-synch-stamp:synch_setup.py $(synch_PYMOD_HDRS)
	-mkdir -p `python -c 'import distutils.util;import sys;print "build/temp."+distutils.util.get_platform()+"-"+sys.version[0:3]'`
	$(PYTHON) synch_setup.py build_ext	\
	  --include-dirs=`cd $(INCLUDEDIR) && pwd`		\
	  --include-dirs=`cd $(INCLUDEDIR2) && pwd`		\
	  --include-dirs=`cd $(PYINCLUDEDIR) && pwd`		\
	  --include-dirs=`cd $(PYINCLUDEDIR2) && pwd`		\
	  `echo $(PYTHONINC) | sed -e 's/-I/--include-dirs=/g'` \
	  --library-dirs=`cd $(SIDLPYTHONLIB) && pwd`		\
	  --rpath=`cd $(SIDLPYTHONLIB) && pwd`			\
	  --library-dirs=`cd $(SIDLPARSIFALLIB) && pwd`		\
	  --library-dirs=$(CHASMLITEDIR)		\
	  --rpath=`cd $(SIDLPARSIFALLIB) && pwd`		\
	  --rpath=$(CHASMLITEDIR)		\
	  $(LIBPARSIFAL_PYSETUP) $(CHASM_PYSETUP) \
	  $(PYTHON_SETUP_ARGS) 					\
	  --inplace
	touch python-synch-stamp

runPy2C: $(srcdir)/runPy2C.in
	rm -f runPy2C
	sed -e s%PYTHONDIR%$(PYTHONDIR)%g				\
	  -e s%PYTHONLIB%$(SIDLPYTHONLIB):$(SIDLXPYTHONLIB):$(SIDLPARSIFALLIB):$(SIDLCHASMLITELIB)%g \
	  -e s%SIDLSTUBSLIB%$(SIDLSTUBSLIB)%g \
	  -e s%SHARED_LIB_VAR%$(SHARED_LIB_VAR)%g			\
	  -e s%PYTHONEXEC%$(PYTHON)%g $(srcdir)/runPy2C.in > runPy2C
	chmod +x runPy2C

runPy2Cxx: $(srcdir)/runPy2Cxx.in
	rm -f runPy2Cxx
	sed -e s%PYTHONDIR%$(PYTHONDIR)%g				\
	  -e s%PYTHONLIB%$(SIDLPYTHONLIB):$(SIDLXPYTHONLIB):$(SIDLPARSIFALLIB):$(SIDLCHASMLITELIB)%g \
	  -e s%SIDLSTUBSLIB%$(SIDLSTUBSLIB)%g \
	  -e s%SHARED_LIB_VAR%$(SHARED_LIB_VAR)%g			\
	  -e s%PYTHONEXEC%$(PYTHON)%g $(srcdir)/runPy2Cxx.in > runPy2Cxx
	chmod +x runPy2Cxx

runPy2Java: $(srcdir)/runPy2Java.in
	rm -f runPy2Java
	sed -e s%PYTHONDIR%$(PYTHONDIR)%g				\
	  -e s%PYTHONLIB%$(SIDLPYTHONLIB):$(SIDLXPYTHONLIB):$(SIDLPARSIFALLIB):$(SIDLCHASMLITELIB)%g \
	  -e s%SIDLSTUBSLIB%$(SIDLSTUBSLIB)%g \
	  -e s%LIBJAVA_DIR%$(LIBJAVA_DIR)%g                             \
	  -e s%LIBJVM_DIR%$(LIBJVM_DIR)%g                               \
	  -e s%EXEC_PREFIX%$(exec_prefix)%g				\
	  -e s%VERSION%$(VERSION)%g					\
	  -e s%SHARED_LIB_VAR%$(SHARED_LIB_VAR)%g			\
	  -e s%PYTHONEXEC%$(PYTHON)%g $(srcdir)/runPy2Java.in > runPy2Java
	chmod +x runPy2Java


if SUPPORT_FORTRAN77
runPy2F77: $(srcdir)/runPy2F77.in
	rm -f runPy2F77
	sed -e s%PYTHONDIR%$(PYTHONDIR)%g				\
	  -e s%PYTHONLIB%$(SIDLPYTHONLIB)::$(SIDLXPYTHONLIB):$(SIDLPARSIFALLIB):$(SIDLCHASMLITELIB)%g \
	  -e s%SIDLSTUBSLIB%$(SIDLSTUBSLIB)%g \
	  -e s%SHARED_LIB_VAR%$(SHARED_LIB_VAR)%g			\
	  -e s%PYTHONEXEC%$(PYTHON)%g $(srcdir)/runPy2F77.in > runPy2F77
	chmod +x runPy2F77
endif

if SUPPORT_FORTRAN90
runPy2F90: $(srcdir)/runPy2F90.in
	rm -f runPy290F
	sed -e s%PYTHONDIR%$(PYTHONDIR)%g				\
	  -e s%PYTHONLIB%$(SIDLPYTHONLIB)::$(SIDLXPYTHONLIB):$(SIDLPARSIFALLIB):$(SIDLCHASMLITELIB)%g \
	  -e s%SIDLSTUBSLIB%$(SIDLSTUBSLIB)%g \
	  -e s%SHARED_LIB_VAR%$(SHARED_LIB_VAR)%g			\
	  -e s%PYTHONEXEC%$(PYTHON)%g $(srcdir)/runPy2F90.in > runPy2F90
	chmod +x runPy2F90
endif

clean-local: clean-generic
	rm -f *setup.py *.testresult
	rm -rf build synch
	test "X$(srcdir)" = "X." || rm -rf babel.make  synch_babel.make $(TESTPROG)
	@if test -d $(sidlSUBDIR); then					\
	  cd $(sidlSUBDIR);						\
	  echo rm -f sedscript Makefile Makefile.pre Setup config.c babel.make.depends;	\
	  rm -f sedscript Makefile Makefile.pre Setup config.c babel.make.depends;		\
	  echo rm -f Setup.in *.so *.o *~ *.c *.h __init__.*;		\
	  rm -f Setup.in *.so *.o *~ *.c *.h __init__.*;		\
	fi

distclean-local:clean-local
	test "X$(srcdir)" = "X." || rm -rf $(sidlSUBDIR) $(PYTHONISHFILES)

check-local:
	@if test -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean-local;	\
	  $(MAKE) $(AM_MAKEFLAGS) clean-local;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS) python-support


installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean-local;	\
	  $(MAKE) $(AM_MAKEFLAGS) clean-local;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  INCLUDEDIR2=$(exec_prefix)/include		\
	  PYINCLUDEDIR=$(prefix)/include/python$(PYTHON_VERSION)/llnl_babel \
	  PYINCLUDEDIR2=$(prefix)/include/python$(PYTHON_VERSION)/llnl_babel_sidl_sidlx \
	  PYTHONDIR=$(exec_prefix)/`$(PYTHON) -c "import sys; print sys.__dict__.get('lib','lib')"`/python$(PYTHON_VERSION)/site-packages \
	  SIDLPYTHONLIB=$(libdir) SIDLXPYTHONLIB=$(libdir) \
	  SIDLPARSIFALLIB=$(libdir) \
	  SIDLCHASMLITELIB=$(libdir) \
	  SIDLSTUBSLIB=$(libdir) python-support
	touch stamp-installcheck
else
clean-local:
check-local:
installcheck-local:
endif

dist-hook:
	@for file in $(PYTHONISHFILES); do				\
	  d=`dirname $(distdir)/$$file`; 				\
	  test -f $$d							\
	  || mkdir -p $$d						\
	  || exit 1;							\
	  echo cp -p $(srcdir)/$$file $(distdir)/$$file;		\
	  cp -p $(srcdir)/$$file $(distdir)/$$file;			\
	done
	touch -c $(distdir)/Makefile.in

update-babel-make: babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi
