##
## File:        make.runF90
## Package:     Babel regression checks
## Revision:    $Revision: 5359 $
## Modified:    $Date: 2006-04-06 16:53:03 -0700 (Thu, 06 Apr 2006) $
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

if SUPPORT_FORTRAN90
SCLFILE=libClient.scl

check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SCRIPTS     = runAll.sh
check_LTLIBRARIES = libClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = $(top_builddir)/lib/sidlstubs/F90
LIBSIDLSTUB = $(top_builddir)/lib/sidlstubs/F90/libsidlstub_f90.la
LIBSYNC     = ../../output/libC/libOutput.la
BABELGEN = $(IMPLMODULESRCS) $(IMPLSRCS)
PUREBABELGEN = $(IORSRCS) $(TYPEMODULESRCS) $(ARRAYMODULESRCS) $(IORHDRS) \
	$(SKELSRCS) $(STUBHDRS) $(STUBMODULESRCS) $(STUBSRCS) \
	$(client_TYPEMODULESRCS) $(client_ARRAYMODULESRCS) $(client_IORHDRS) \
	$(client_STUBHDRS) \
	$(client_STUBMODULESRCS) $(client_STUBSRCS) 
CLEANFILES=$(PUREBABELGEN) $(EXTRACLEAN) babel-stamp \
	stamp-installcheck core \
	babel-temp libClient.scl \
	babel.make.package client_babel.make.package \
	babel.make.depends client_babel.make.depends

$(TYPEMODULESRCS:.F90=.lo) $(client_TYPEMODULESRCS:.F90=.lo) : $(BASICMODULESRC:.F90=.lo)
$(ARRAYMODULESRCS:.F90=.lo)  : $(TYPEMODULESRCS:.F90=.lo)
$(STUBMODULESRCS:.F90=.lo) : $(ARRAYMODULESRCS:.F90=.lo) $(TYPEMODULESRCS:.F90=.lo)
$(client_ARRAYMODULESRCS:.F90=.lo) : $(client_TYPEMODULESRCS:.F90=.lo)
$(client_STUBMODULESRCS:.F90=.lo) : $(client_ARRAYMODULESRCS:.F90=.lo) \
	$(client_TYPEMODULESRCS:.F90=.lo)
$(IMPLMODULESRCS:.F90=.lo) : $(STUBMODULESRCS:.F90=.lo) \
	$(client_STUBMODULESRCS:.F90=.lo)
$(IMPLSRCS:.F90=.lo) : $(IMPLMODULESRCS:.F90=.lo) \
	$(STUBMODULESRCS:.F90=.lo) \
	$(client_STUBMODULESRCS:.F90=.lo)

if SUPPORT_STATIC
if SUPPORT_FORTRAN77
  STATIC_TEMP_F77 = runF902F77
else
  STATIC_TEMP_F77 =
endif
STATIC_PROGS      = runF902C runF902Cxx $(STATIC_TEMP_F77) runF902F90

runF902C_SOURCES        = $(TESTFILE) $(SOURCE_EXTRAS)
runF902C_LDFLAGS        = -static-libtool-libs
runF902C_LDADD          = libClient.la ../libC/libImpl.la \
			  $(LIBSYNC) $(FCLIBS) 
runF902C_LINK		= $(LINK) $(FCMAIN) $(runF902C_LDFLAGS)

runF902Cxx_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF902Cxx_LDFLAGS      = -static-libtool-libs
runF902Cxx_LDADD        = libClient.la ../libCxx/libImpl.la \
			  $(LIBSYNC) $(FCLIBS) 
runF902Cxx_LINK        =  $(LIBTOOL) --tag=CXX --mode=link $(CXXLD) $(AM_CXXFLAGS) \
	$(CXXFLAGS) $(AM_LDFLAGS) $(runF902Cxx_LDFLAGS) -o $@ $(FCMAIN) 


if SUPPORT_FORTRAN77
runF902F77_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF902F77_LDFLAGS      = -static-libtool-libs
runF902F77_LDADD        = libClient.la ../libF77/libImpl.la \
			  $(LIBSYNC) $(FLIBS) $(FCLIBS) 
runF902F77_LINK		= $(LINK) $(FCMAIN) $(runF902F77_LDFLAGS)
endif

runF902F90_SOURCES      = $(TESTFILE) $(SOURCE_EXTRAS)
runF902F90_LDFLAGS      = -static-libtool-libs
runF902F90_LDADD        = libClient.la ../libF90/libImpl.la \
			  $(LIBSYNC) $(FCLIBS) 
runF902F90_LINK		= $(LINK) $(FCMAIN) $(runF902F90_LDFLAGS)
endif

if SUPPORT_SHARED
SHARED_PROGS            = runAll
runAll_SOURCES          = $(TESTFILE) $(SOURCE_EXTRAS)
runAll_LDFLAGS		= -dynamic
runAll_LDADD            = libClient.la $(LIBSYNC) \
			  $(FCLIBS) 
runAll_LINK      	= $(LINK) $(FCMAIN) $(runAll_LDFLAGS)

endif

nodist_libClient_la_SOURCES      = $(PUREBABELGEN)
libClient_la_SOURCES      = $(BABELGEN) $(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSIDLSTUB) $(LIBSYNC) $(FCLIBS)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release @VERSION@
libClient_la_LINK = $(LINK) $(libClient_la_LDFLAGS)

$(TESTFILE:.F90=.o) : libClient.la

EXTRA_DIST = babel.make client_babel.make
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2)
AM_FCFLAGS    = $(CHASM_FORTRAN_MFLAG)$(INCLUDEDIR2)

STUBOBJS = $(STUBSRCS:.c=.lo)
BASICMODULEOBJ = $(BASICMODULESRC:.F90=.lo)
STUBMODULEOBJS = $(STUBMODULESRCS:.F90=.lo)
ARRAYMODULEOBJS = $(ARRAYMODULESRCS:.F90=.lo)
TYPEMODULEOBJS = $(TYPEMODULESRCS:.F90=.lo)
libClient.la $(STUBOBJS) $(ARRAYMODULEOBJS) $(STUBMODULEOBJS) $(TYPEMODULEOBJS): babel-stamp

$(TYPEMODULEOBJS) : $(BASICMODULEOBJ)
$(ARRAYMODULEOBJS) :  $(TYPEMODULEOBJS)
$(STUBMODULEOBJS): $(TYPEMODULEOBJS) $(ARRAYMODULEOBJS)

# This little snippet forces automake to define $CXXLINK
EXTRA_PROGRAMS  = automake_hack
automake_hack_SOURCES = 
nodist_EXTRA_automake_hack_SOURCES = automake_hack.cc
endif

PPFCCOMPILE = $(FC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_FCFLAGS) $(FCFLAGS) $(FCFLAGS_f90)
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
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp ; \
	fi

babel-stamp: $(OUTPUTSIDL)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --vpath="$(srcdir)" --server=f90 \
		$(BABELEXTRA) $(SERVEREXTRA) 
	$(SHELL) $(BABELDIR)/$(BABEL) --client=f90 \
		--make-prefix=client_ $(CLIENTEXTRA) $(BABELEXTRA) \
		$(OUTPUTSIDL)
	@mv -f babel-temp $@

libClient.scl : $(IORSRCS)
	$(SHELL) $(top_srcdir)/bin/generate_scl libClient.scl `pwd`/libClient.la \
		$(IORSRCS)

update-babel-make:babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make client_babel.make $(srcdir); \
	fi

clean-local:
	rm -f *.a *.so *.mod *.testresult *$(F90CPPSUFFIX)
	test "X$(srcdir)" = "X." || rm -f babel.make client_babel.make $(BABELGEN)

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
	$(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) \
	   $(SCLFILE)

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
	  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) \
	  $(SCLFILE)
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
