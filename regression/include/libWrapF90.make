##
## File:        make.libF90
## Package:     Babel regression checks
## Revision:    $Revision: 5340 $
## Modified:    $Date: 2006-04-04 14:35:32 -0700 (Tue, 04 Apr 2006) $
## Description: automake makefile for f90 regression tests
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

if SUPPORT_FORTRAN90

check_LTLIBRARIES = libImpl.la
SCLFILE=libImpl.scl

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = $(top_builddir)/lib/sidlstubs/F90
LIBSIDLSTUB= $(top_builddir)/lib/sidlstubs/F90/libsidlstub_f90.la
LIBSYNC     = ../../output/libC/libOutput.la

PUREBABELGEN = $(IORSRCS) $(TYPEMODULESRCS) $(ARRAYMODULESRCS) $(IORHDRS) \
	$(SKELSRCS) $(STUBHDRS) $(STUBMODULESRCS) $(STUBSRCS) \
	$(client_TYPEMODULESRCS) $(client_ARRAYMODULESRCS) $(client_IORHDRS) \
	$(client_STUBHDRS) \
	$(client_STUBMODULESRCS) $(client_STUBSRCS) 
BABELGEN = $(IMPLMODULESRCS) $(IMPLSRCS)


nodist_libImpl_la_SOURCES = $(PUREBABELGEN) $(SOURCE_EXTRAS)
dist_libImpl_la_SOURCES = $(BABELGEN) $(SOURCE_EXTRAS)
libImpl_la_LIBADD = $(LIBSIDLSTUB) $(LIBSYNC) $(FCLIBS)
libImpl_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			  -release @VERSION@ -module
libImpl_la_LINK = $(LINK) $(libImpl_la_LDFLAGS)

$(TYPEMODULESRCS:.F90=.lo) $(client_TYPEMODULESRCS:.F90=.lo) : $(BASICMODULESRC:.F90=.lo)
$(ARRAYMODULESRCS:.F90=.lo)  : $(TYPEMODULESRCS:.F90=.lo)
$(STUBMODULESRCS:.F90=.lo) : $(ARRAYMODULESRCS:.F90=.lo) $(TYPEMODULESRCS:.F90=.lo) $(client_TYPEMODULESRCS:.F90=.lo)
$(client_ARRAYMODULESRCS:.F90=.lo) : $(client_TYPEMODULESRCS:.F90=.lo)
$(client_STUBMODULESRCS:.F90=.lo) : $(client_ARRAYMODULESRCS:.F90=.lo) \
	$(client_TYPEMODULESRCS:.F90=.lo)
$(IMPLMODULESRCS:.F90=.lo) : $(STUBMODULESRCS:.F90=.lo) \
	$(client_STUBMODULESRCS:.F90=.lo)
$(IMPLSRCS:.F90=.lo) : $(IMPLMODULESRCS:.F90=.lo) \
	$(STUBMODULESRCS:.F90=.lo) \
	$(client_STUBMODULESRCS:.F90=.lo)

CLEANFILES=$(PUREBABELGEN) $(EXTRACLEAN) babel-stamp babel-temp \
	stamp-installcheck core libImpl.scl \
	babel.make.depends client_babel.make.depends \
	babel.make.package client_babel.make.package

EXTRA_DIST = babel.make client_babel.make 
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2)
AM_FCFLAGS    = $(CHASM_FORTRAN_MFLAG)$(INCLUDEDIR2)

endif

# Customize some F90 macros since automake (as of 1.9.3)
# still doesn't include the --tag specifier for libtool
LTPPFCCOMPILE = $(LIBTOOL) --mode=compile --tag=FC $(FC) $(DEFS) \
	$(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) \
	$(AM_FCFLAGS) $(FCFLAGS) $(FCFLAGS_f90)
FCLINK = $(LIBTOOL) --mode=link --tag=FC $(FCLD) $(AM_FFLAGS) $(FCFLAGS) \
	$(AM_LDFLAGS) $(LDFLAGS) -o $@

$(BABELGEN) $(PUREBABELGEN) : babel-stamp
	@if test -f $@; then\
	  touch $@; \
	else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(SIDLFILE) $(OUTPUTSIDL)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --vpath="$(srcdir)" --server=F90 \
	  $(BABELEXTRA) $(SERVEREXTRA)
	$(SHELL) $(BABELDIR)/$(BABEL) --client=F90 --make-prefix=client_ \
	  $(BABELEXTRA) $(CLIENTEXTRA)
	@mv -f babel-temp $@

libImpl.scl : $(IORSRCS)
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)

update-babel-make: babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make client_babel.make $(srcdir); \
	fi

clean-local:
	rm -f *.a *.so *.mod *.f90
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) $(IMPLMODULESRCS) \
	   babel.make client_babel.make

# Override default F90 macros since automake (as of 1.9.3) doesn't
# really allow us to override preprocessing step.
.F90.o:
	$(CPP) -traditional $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES)  $(AM_CPPFLAGS) $(CPPFLAGS) \
		-P -o $(@:.o=.tmp) -x c `test -f '$<' || echo '$(srcdir)/'`$<
	sed -e 's/^#pragma.*$$//' < $(@:.o=.tmp) > $(@:.o=$(F90CPPSUFFIX))
	$(PPFCCOMPILE) -c -o $@ $(@:.o=$(F90CPPSUFFIX))
	rm -f $(@:.o=$(F90CPPSUFFIX)) $(@:.o=.tmp) 

.F90.obj:
	$(CPP) -traditional $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES)  $(AM_CPPFLAGS) $(CPPFLAGS) \
		-P -o $(@:.obj=.tmp) -x c `test -f '$<' || echo '$(srcdir)/'`$<
	sed -e 's/^#pragma.*$$//' < $(@:.obj=.tmp) > $(@:.obj=$(F90CPPSUFFIX))
	$(PPFCCOMPILE) -c -o $@ $(@:.obj=$(F90CPPSUFFIX))
	rm -f $(@:.obj=$(F90CPPSUFFIX)) $(@:.obj=.tmp)

.F90.lo:
	$(CPP) -traditional $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES)  $(AM_CPPFLAGS) $(CPPFLAGS) \
		 -P -o $(@:.lo=.tmp) -x c `test -f '$<' || echo '$(srcdir)/'`$<
	sed -e 's/^#pragma.*$$//' < $(@:.lo=.tmp) > $(@:.lo=$(F90CPPSUFFIX))
	$(LTPPFCCOMPILE) -c -o $@  $(@:.lo=$(F90CPPSUFFIX))
	rm -f $(@:.lo=$(F90CPPSUFFIX)) $(@:.lo=.tmp)

check-local:
	@if test -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(SCLFILE)

installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  INCLUDEDIR2=$(includedir)/f90			\
	  LIBSIDLSTUB=$(libdir)/libsidlstub_f90.la	\
	  $(check_LTLIBRARIES) $(SCLFILE)
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
