##
## File:        make.runF77
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

if SUPPORT_FORTRAN77



check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SCRIPTS     = runAll.sh
check_LTLIBRARIES = libClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = $(top_builddir)/lib/sidlstubs/F77
LIBSIDLSTUB = $(top_builddir)/lib/sidlstubs/F77/libsidlstub_f77.la
LIBSYNC     = ../../output/libC/libOutput.la
PUREBABELGEN = $(STUBSRCS) $(STUBFORTRANINC) $(STUBHDRS) $(IORHDRS)
SYNCHBABELGEN = $(synch_IORHDRS) $(synch_STUBSRCS) $(synch_STUBFORTRANINC) \
	$(synch_STUBHDRS)
DOCFILES = $(STUBDOCS)
SYNCHDOCFILES =  $(synch_STUBDOCS)
CLEANFILES = $(PUREBABELGEN) $(EXTRACLEAN) $(DOCFILES) \
	$(SYNCHBABELGEN) $(SYNCHDOCFILES) \
	synch-stamp synch-temp babel-stamp \
	babel-temp stamp-installcheck core \
	babel.make.package babel.make.depends \
	synch_babel.make.package synch_babel.make.depends

if SUPPORT_STATIC
if SUPPORT_FORTRAN90
  BABEL_STATIC_F90  = runF772F90
else
  BABEL_STATIC_F90  = 
endif
STATIC_PROGS       = runF772C runF772Cxx runF772F77 $(BABEL_STATIC_F90)

runF772C_SOURCES        = $(TESTFILE) $(SOURCE_EXTRAS)
runF772C_LDFLAGS        = -static-libtool-libs
runF772C_LDADD          = libClient.la ../libC/libImpl.la \
			  $(LIBSYNC) $(FLIBS)
runF772C_LINK		= $(LINK) $(FMAIN) $(runF772C_LDFLAGS)
# use C linker instead of F77 to avoid problem when compiling with Intel's
# icc with optimization (undefined _intel_fast_memcpy symbol)

runF772Cxx_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF772Cxx_LDFLAGS      = -static-libtool-libs
runF772Cxx_LDADD        = libClient.la ../libCxx/libImpl.la \
			  $(LIBSYNC) $(FLIBS)
runF772Cxx_LINK	 	= $(CXXLINK) $(FMAIN) $(runF772Cxx_LDFLAGS)

runF772F77_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF772F77_LDFLAGS      = -static-libtool-libs
runF772F77_LDADD        = libClient.la ../libF77/libImpl.la \
			  $(LIBSYNC) $(FLIBS)
runF772F77_LINK		= $(LINK) $(FMAIN) $(runF772F77_LDFLAGS)
# use C linker instead of F77 to avoid problem when compiling with Intel's
# icc with optimization (undefined _intel_fast_memcpy symbol)

if SUPPORT_FORTRAN90
runF772F90_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF772F90_LDFLAGS      = -static-libtool-libs
runF772F90_LDADD        = libClient.la ../libF90/libImpl.la \
			  $(LIBSYNC) $(FLIBS) $(FCLIBS)
runF772F90_LINK		= $(LINK) $(FMAIN) $(runF772F90_LDFLAGS)
# use C linker instead of F77 to avoid problem when compiling with Intel's
# icc with optimization (undefined _intel_fast_memcpy symbol)
endif
endif

if SUPPORT_SHARED
SHARED_PROGS            = runAll
runAll_SOURCES          = $(TESTFILE) $(SOURCE_EXTRAS)
runAll_LDFLAGS		= -dynamic
runAll_LDADD            = libClient.la $(LIBSYNC) $(FLIBS)
runAll_LINK		= $(LINK) $(FMAIN) $(runAll_LDFLAGS)
endif

nodist_libClient_la_SOURCES = $(PUREBABELGEN) $(SYNCHBABELGEN) $(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSYNC) $(LIBSIDLSTUB)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release @VERSION@

EXTRA_DIST = babel.make synch_babel.make
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2)
AM_FFLAGS=$(AM_CPPFLAGS)

$(TESTFILE:.f=.o) : $(STUBFORTRANINC) $(synch_STUBFORTRANINC)

$(PUREBABELGEN) $(DOCFILES) : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp ; \
	fi

$(SYNCHBABELGEN) $(SYNCHDOCFILES) : synch-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f synch-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) synch-stamp ; \
	fi


# This little snippet forces automake to define $CXXLINK
EXTRA_PROGRAMS  = automake_hack
automake_hack_SOURCES = 
nodist_EXTRA_automake_hack_SOURCES = automake_hack.cc
endif

babel-stamp: $(SIDLFILE)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=f77 \
		$(BABELEXTRA) $(SIDLFILE)
	@mv -f babel-temp $@

synch-stamp: $(OUTPUTSIDL)
	@rm -f synch-temp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=f77 --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f synch-temp $@

clean-local:
	test "X$(srcdir)" = "X." || rm -f babel.make synch_babel.make
	rm -f *.testresult

update-babel-make: babel-stamp synch-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi

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
	  INCLUDEDIR2=$(includedir)/f77			\
	  LIBSIDLSTUB=$(libdir)/libsidlstub_f77.la	\
	  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS)
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
