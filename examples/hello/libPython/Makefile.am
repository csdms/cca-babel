##
## File:        Makefile.am
## Package:     Babel Hello example
## Copyright:   (c) 2007 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for Python Hello World server
##

if SERVER_PYTHON
check_LTLIBRARIES = libImpl.la libImplPy.la
endif

BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
PYINCLUDEDIR = $(top_builddir)/runtime/python
LIBSIDL     = $(top_builddir)/runtime/sidl/libsidl.la

SIDLFILE = $(srcdir)/../Hello.sidl
CLEANFILES = $(PUREBABELGEN) babel-stamp babel-temp babel.make.package \
	babel.make.depends python-babel-stamp libImplPy.scl libImpl.scl

AM_CPPFLAGS=-I. -I$(PYINCLUDEDIR) $(PYTHONINC)
SIDLPYTHONLIB=$(top_builddir)/runtime/sidl/.libs
SIDLPARSIFALLIB=$(top_builddir)/runtime/libparsifal/src/.libs
SIDLCHASMLITELIB=$(top_builddir)/runtime/libchasmlite/.libs

EXTRA_DIST=babel.make Hello/babel.make

PUREBABELGEN=$(IORSRCS) $(IORHDRS) $(LAUNCHSRCS) $(PYMOD_HDRS) $(SKELSRCS) \
	setup.py

if SERVER_PYTHON
libImpl_la_LDFLAGS = -no-undefined -rpath `pwd`/.libs -release @VERSION@ -module
libImplPy_la_LDFLAGS = -no-undefined -rpath `pwd`/.libs -release @VERSION@ -module
nodist_libImpl_la_SOURCES=$(IORSRCS) $(IORHDRS) $(LAUNCHSRCS)
libImpl_la_LIBADD=$(LIBSIDL)

nodist_libImplPy_la_SOURCES=$(SKELSRCS)
libImplPy_la_LIBADD = -L@PYTHON_SHARED_LIBRARY_DIR@ \
		      -lpython@PYTHON_VERSION@ $(LIBSIDL)
endif

$(PUREBABELGEN) libImpl.scl libImplPy.scl : babel-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f babel-stamp ; \
	    $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(SIDLFILE)
	test -d Hello || mkdir -p Hello || exit 1
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/babel --vpath="$(srcdir)" --server=python \
	   $(SIDLFILE)
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)
	$(SHELL) $(top_srcdir)/bin/generate_pyscl libImplPy.scl \
	   `pwd`/libImplPy.la $(IORSRCS)
	@mv -f babel-temp babel-stamp

python-babel-stamp:setup.py $(PYMOD_HDRS)
	@mkdir -p `python -c 'import distutils.util;import sys;print "build/temp."+distutils.util.get_platform()+"-"+sys.version[0:3]'`
	$(PYTHON) setup.py build_ext	\
	  --include-dirs=`cd $(INCLUDEDIR) && pwd`		\
	  --include-dirs=`cd $(PYINCLUDEDIR) && pwd`		\
	  `echo $(PYTHONINC) | sed -e 's/-I/--include-dirs=/g'` \
	  --library-dirs=`cd $(SIDLPYTHONLIB) && pwd`		\
	  --rpath=`cd $(SIDLPYTHONLIB) && pwd`			\
	  --library-dirs=`cd $(SIDLPARSIFALLIB) && pwd`		\
	  --library-dirs=`cd $(SIDLCHASMLITELIB) && pwd`		\
	  --rpath=`cd $(SIDLPARSIFALLIB) && pwd`			\
	  --rpath=`cd $(SIDLCHASMLITELIB) && pwd`			\
	  $(LIBPARSIFAL_PYSETUP) $(CHASM_PYSETUP) \
	  $(PYTHON_SETUP_ARGS) 					\
	  --inplace
	@touch python-babel-stamp

if SERVER_PYTHON
check-local: python-babel-stamp
endif

clean-local:
	rm -rf build
	@if test -d Hello; then \
	  if test "X$(srcdir)" = "X." ; then \
	    for file in $(PYMOD_SRCS) $(PYTHONADMIN) ; do \
	      rm -f Hello/$$file; \
	    done; \
	  else \
	    rm -f babel.make ; \
	    for file in $(PYMOD_SRCS) $(PYTHONADMIN) $(PYTHON_SRC) ; do \
	      rm -f Hello/$$file; \
	    done; \
	  fi ;\
	  cd Hello && rm -f *.so *.o *~ *.pyc *.depends; \
	fi

distclean-local: clean-local
	test "X$(srcdir)" = "X." || rm -rf Hello

include babel.make
include Hello/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
