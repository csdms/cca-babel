##
## File:        make.libC
## Package:     Babel regression checks
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for C regression tests
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

check_LTLIBRARIES = libImpl.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
if WITH_SIDLX
INCLUDEDIRX  = $(top_builddir)/runtime/sidlx
LIBSIDL      =
LIBSIDLX     = $(top_builddir)/runtime/sidlx/libsidlx.la
INSTALLEDSIDLX = $(libdir)/libsidlx.la
INSTALLEDSIDL=
else
INCLUDEDIRX  = $(INCLUDEDIR)
LIBSIDLX     = 
LIBSIDL      =$(top_builddir)/runtime/sidl/libsidl.la
INSTALLEDSIDLX = 
INSTALLEDSIDL=$(libdir)/libsidl.la
endif
INCLUDEDIR2 = .
LIBSYNC     = ../../output/libC/libOutput.la

PUREBABELGEN = $(STUBSRCS) $(RSTUBSRCS) $(SKELSRCS) $(IORSRCS) \
	$(IORHDRS) $(STUBHDRS) 
SYNCHBABELGEN = $(synch_STUBSRCS) $(synch_STUBHDRS) \
	$(synch_RSTUBSRCS) $(synch_IORHDRS)
BABELGEN = $(IMPLSRCS) $(IMPLHDRS)
CLEANFILES=$(PUREBABELGEN) $(SYNCHBABELGEN) $(EXTRACLEAN) \
	libImpl.scl babel-stamp babel-temp synch-stamp synch-temp \
	stamp-installcheck core \
	babel.make.package  synch_babel.make.package \
	babel.make.depends synch_babel.make.depends

nodist_libImpl_la_SOURCES = $(PUREBABELGEN) $(SYNCHBABELGEN)
libImpl_la_SOURCES = $(BABELGEN) $(SOURCE_EXTRAS)
libImpl_la_LIBADD         = $(LIBSIDLX) $(LIBSIDL) $(LIB_EXTRAS)
libImpl_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			  -release @VERSION@ -module

EXTRA_DIST = babel.make synch_babel.make 
AM_CPPFLAGS = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIRX) -I$(INCLUDEDIR2)


$(BABELGEN) $(PUREBABELGEN) : babel-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f babel-stamp; \
	    $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp : $(SIDLFILE)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --vpath="$(srcdir)" --server=C \
	  $(BABELEXTRA) $(SIDLFILE)
	@mv babel-temp $@

libImpl.scl : $(IORSRCS)
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)

$(IMPLSRCS:.c=.lo) : $(STUBHDRS) $(IORHDRS) $(synch_STUBHDRS) $(synch_IORHDRS)

$(SYNCHBABELGEN) : synch-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f synch-stamp; \
	    $(MAKE) $(AM_MAKEFLAGS) synch-stamp; \
	fi

synch-stamp : $(OUTPUTSIDL)
	@rm -f synch-temp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=C --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv synch-temp $@	

update-babel-make: babel-stamp synch-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi

clean-local:
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) $(IMPLHDRS) babel.make \
	       synch_babel.make

check-local:
	@if test -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) libImpl.scl

installcheck-local: 
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  INCLUDEDIRX=$(includedir)			\
	  INCLUDEDIR2=$(exec_prefix)/include		\
	  LIBSIDL=$(INSTALLEDSIDL)			\
	  LIBSIDLX=$(INSTALLEDSIDLX) $(check_LTLIBRARIES) libImpl.scl
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
