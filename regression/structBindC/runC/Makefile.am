##
## File:        Makefile.am
## Package:     Babel regression checks
## Revision:    $Revision: 6361 $
## Modified:    $Date: 2006-05-30 11:17:48 -0700 (Tue, 30 May 2006) $
## Description: automake makefile for C regression tests
##
## Copyright (c) 2000-2002, The Regents of the University of Calfornia.
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

SIDLFILE = $(srcdir)/../structBindC.sidl
TESTFILE = structtest.c
include $(srcdir)/babel.make
include $(srcdir)/synch_babel.make

OUTPUTSIDL=$(srcdir)/../../output/output.sidl

check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SCRIPTS     = runAll.sh
check_LTLIBRARIES = libClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = .
if WITH_SIDLX
INCLUDEDIRX  = $(top_builddir)/runtime/sidlx
LIBSIDLX     = $(top_builddir)/runtime/sidlx/libsidlx.la
INSTALLEDSIDLX = $(libdir)/libsidlx.la
else
INCLUDEDIRX  = $(INCLUDEDIR)
LIBSIDLX     = 
INSTALLEDSIDLX = 
endif
LIBSIDL     = $(top_builddir)/runtime/sidl/libsidl.la
LIBSYNC     = ../../output/libC/libOutput.la
PUREBABELGEN = $(STUBSRCS) $(STUBHDRS) $(IORHDRS) 
SYNCHBABELGEN = $(synch_STUBSRCS) $(synch_STUBHDRS) $(synch_IORHDRS)
CLEANFILES = $(PUREBABELGEN) $(SYNCHBABELGEN) \
	$(EXTRACLEAN) core babel-stamp babel-temp \
	stamp-installcheck synch-stamp synch-temp \
	babel.make.package babel.make.depends \
	synch_babel.make.package synch_babel.make.depends


# This little snippet forces automake to define $CXXLINK
EXTRA_PROGRAMS  = automake_hack
automake_hack_SOURCES = 
nodist_EXTRA_automake_hack_SOURCES = automake_hack.cc

if SUPPORT_STATIC
if SUPPORT_FORTRAN03
BABEL_STATIC_F03=runC2F03
else
BABEL_STATIC_F03=
endif
STATIC_PROGS = runC2C runC2Cxx $(BABEL_STATIC_F03)
endif

runC2F03_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runC2F03_LDFLAGS      = -static-libtool-libs
runC2F03_LDADD        = libClient.la ../libF03/libImpl.la \
			$(LIBSYNC) $(LIBSIDL) $(LIBSIDLX)

runC2C_SOURCES        = $(TESTFILE) $(SOURCE_EXTRAS)
runC2C_LDFLAGS        = -static-libtool-libs
runC2C_LDADD          = libClient.la ../libC/libImpl.la \
			$(LIBSYNC) $(LIBSIDL) $(LIBSIDLX)

runC2Cxx_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runC2Cxx_LDFLAGS      = -static-libtool-libs
runC2Cxx_LDADD        = libClient.la ../libCxx/libImpl.la \
			$(LIBSYNC) $(LIBSIDL) $(LIBSIDLX)
runC2Cxx_LINK	      = $(CXXLINK) $(runC2Cxx_LDFLAGS)


if SUPPORT_SHARED
SHARED_PROGS          = runAll
runAll_SOURCES        = $(TESTFILE) $(SOURCE_EXTRAS)
runAll_LDFLAGS	      = -dynamic
runAll_LDADD          = libClient.la $(LIBSYNC) $(LIBSIDL) $(LIBSIDLX)
endif

nodist_libClient_la_SOURCES      = $(PUREBABELGEN) $(SYNCHBABELGEN) $(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSYNC) $(LIBSIDL) $(LIBSIDLX)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release @VERSION@

$(TESTFILE:.c=.o) : $(STUBHDRS) $(IORHDRS) $(synch_STUBHDRS) \
	$(synch_IORHDRS)

EXTRA_DIST = babel.make synch_babel.make 
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(INCLUDEDIRX)

$(PUREBABELGEN) : babel-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f babel-stamp ; \
	    $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(SIDLFILE) $(OUTPUTSIDL)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=C \
		$(BABELEXTRA) $(SIDLFILE) 
	@mv -f babel-temp $@

$(SYNCHBABELGEN) : synch-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f synch-stamp ; \
	    $(MAKE) $(AM_MAKEFLAGS) synch-stamp; \
	fi

synch-stamp: $(OUTPUTSIDL)
	@rm -f synch-temp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=C --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f synch-temp $@


clean-local:
	test "X$(srcdir)" = "X." || rm -f babel.make synch_babel.make
	rm -f *.testresult

check-local:
	@if test -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS)

installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  INCLUDEDIR2=$(exec_prefix)/include		\
	  INCLUDEDIRX=$(includedir)			\
	  LIBSIDL=$(libdir)/libsidl.la			\
	  LIBSIDLX=$(INSTALLED_SIDLX)                   \
	  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) 
	touch stamp-installcheck

update-babel-make: babel-stamp synch-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi
# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in

