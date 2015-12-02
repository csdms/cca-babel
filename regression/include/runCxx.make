##
## File:        make.runCxx
## Package:     Babel regression checks
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for run regression tests
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

check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SCRIPTS     = runAll.sh
check_LTLIBRARIES = libClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/lib/sidlstubs/Cxx
INCLUDEDIR2 = .
LIBSIDLSTUB = $(top_builddir)/lib/sidlstubs/Cxx/libsidlstub_cxx.la
LIBSYNC     = ../../output/libC/libOutput.la
PUREBABELGEN=$(STUBSRCS) $(STUBHDRS) $(IORHDRS) 
SYNCHBABELGEN=$(synch_STUBSRCS) $(synch_STUBHDRS) $(synch_IORHDRS)
CLEANFILES=$(PUREBABELGEN) $(SYNCHBABELGEN) \
	$(EXTRACLEAN) babel-temp babel-stamp synch-temp synch-stamp \
	stamp-installcheck core babel.make.package babel.make.depends \
	babel.make.depends synch_babel.make.depends \
	synch_babel.make.package

if SUPPORT_STATIC
if SUPPORT_FORTRAN77
  BABEL_STATIC_F77  = runCxx2F77 
else
  BABEL_STATIC_F77  = 
endif
if SUPPORT_FORTRAN90
  BABEL_STATIC_F90  = runCxx2F90
else
  BABEL_STATIC_F90  = 
endif
STATIC_PROGS       = runCxx2C runCxx2Cxx runCxx2Cxx $(BABEL_STATIC_F77) $(BABEL_STATIC_F90)

runCxx2C_SOURCES        = $(TESTFILE) $(SOURCE_EXTRAS)
runCxx2C_LDFLAGS        = -static-libtool-libs
runCxx2C_LDADD          = libClient.la ../libC/libImpl.la \
			  $(LIBSYNC)

runCxx2Cxx_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runCxx2Cxx_LDFLAGS      = -static-libtool-libs
runCxx2Cxx_LDADD        = libClient.la ../libCxx/libImpl.la \
			  $(LIBSYNC)

if SUPPORT_FORTRAN77
runCxx2F77_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runCxx2F77_LDFLAGS      = -static-libtool-libs
runCxx2F77_LDADD        = libClient.la ../libF77/libImpl.la \
			  $(LIBSYNC) $(FLIBS)
endif

if SUPPORT_FORTRAN90
runCxx2F90_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runCxx2F90_LDFLAGS      = -static-libtool-libs
runCxx2F90_LDADD        = libClient.la ../libF90/libImpl.la \
			  $(LIBSYNC) $(FCLIBS)
endif
endif
if SUPPORT_SHARED
SHARED_PROGS            = runAll
runAll_SOURCES          = $(TESTFILE) $(SOURCE_EXTRAS)
runAll_LDFLAGS		= -dynamic
runAll_LDADD            = libClient.la $(LIBSYNC)
endif

nodist_libClient_la_SOURCES      = $(PUREBABELGEN) $(SYNCHBABELGEN) \
	$(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSIDLSTUB)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release @VERSION@

$(TESTFILE:.cxx=.o) : $(STUBHDRS) $(IORHDRS) $(synch_STUBHDRS) \
	$(synch_IORHDRS)

EXTRA_DIST = babel.make synch_babel.make  
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2)

$(PUREBABELGEN) : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp ; \
	fi

babel-stamp: $(SIDLFILE)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=Cxx $(BABELEXTRA) \
		$(SIDLFILE) 
	@mv -f babel-temp $@

$(SYNCHBABELGEN) : synch-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f synch-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) synch-stamp ; \
	fi

synch-stamp : $(OUTPUTSIDL)
	@rm -f synch-temp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=Cxx --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f synch-temp $@

clean-local:
	rm -f *.a *.so *.testresult
	rm -rf ti_files
	test "X$(srcdir)" = "X." || rm -f babel.make synch_babel.make

update-babel-make: babel-stamp synch-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi

check-local:
	@if test -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) 

installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)/cxx			\
	  LIBSIDLSTUB=$(libdir)/libsidlstub_cxx.la	\
	$(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) 
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
