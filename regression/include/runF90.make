##
## File:        make.runF90
## Package:     Babel regression checks
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for run regression tests
##
## Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC
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



check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SCRIPTS     = runAll.sh
check_LTLIBRARIES = libClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = $(top_builddir)/lib/sidlstubs/F90
LIBSIDLSTUB = $(top_builddir)/lib/sidlstubs/F90/libsidlstub_f90.la
LIBSYNC     = ../../output/libC/libOutput.la
PUREBABELGEN = $(IORSRCS) $(ARRAYMODULESRCS) $(IORHDRS) \
	$(SKELSRCS) $(STUBHDRS) $(STUBMODULESRCS) $(STUBSRCS) \
	$(TYPEMODULESRCS) $(BASICMODULESRC)
SYNCHBABELGEN = $(synch_TYPEMODULESRCS) $(synch_ARRAYMODULESRCS) \
	$(synch_IORHDRS) $(synch_STUBHDRS) \
	$(synch_STUBMODULESRCS) $(synch_STUBSRCS) 

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
CLEANFILES=$(PUREBABELGEN) $(SYNCHBABELGEN) $(EXTRACLEAN) \
	synch-stamp synch-temp babel-stamp babel-temp \
	stamp-installcheck core babel.make.package \
	babel.make.depends synch_babel.make.depends \
	synch_babel.make.package

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
runAll_LINK      	= $(LINK) $(FCMAIN)  $(runAll_LDFLAGS)

endif

nodist_libClient_la_SOURCES      = $(PUREBABELGEN) $(SYNCHBABELGEN) \
	$(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSIDLSTUB) $(LIBSYNC) $(FCLIBS)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release @VERSION@
libClient_la_LINK = $(LINK) $(libClient_la_LDFLAGS)

$(TESTFILE:.F90=.o) : libClient.la

EXTRA_DIST = babel.make 
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2)
AM_FCFLAGS    = $(CHASM_FORTRAN_MFLAG)$(INCLUDEDIR2)

STUBOBJS = $(STUBSRCS:.c=.lo)
BASICMODULEOBJ = $(BASICMODULESRC:.F90=.lo)
STUBMODULEOBJS = $(STUBMODULESRCS:.F90=.lo)
ARRAYMODULEOBJS = $(ARRAYMODULESRCS:.F90=.lo)
TYPEMODULEOBJS = $(TYPEMODULESRCS:.F90=.lo)
libClient.la $(STUBOBJS) $(ARRAYMODULEOBJS) $(STUBMODULEOBJS) $(TYPEMODULEOBJS): babel-stamp

$(TYPEMODULEOBJS) $(synch_TYPEMODULESRCS:.F90=.lo) : $(BASICMODULEOBJ)
$(ARRAYMODULEOBJS) : $(TYPEMODULEOBJS)
$(STUBMODULEOBJS) : $(ARRAYMODULEOBJS) $(TYPEMODULEOBJS)
$(synch_ARRAYMODULESRCS:.F90=.lo) : $(synch_TYPEMODULESRCS:.F90=.lo)
$(synch_STUBMODULESRCS:.F90=.lo) : $(synch_ARRAYMODULESRCS:.F90=.lo) $(synch_TYPEMODULESRCS:.F90=.lo)
$(IMPLMODULESRCS:.F90=.lo) : $(STUBMODULEOBJS) $(synch_STUBMODULESRCS:.F90=.lo)

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

$(PUREBABELGEN) : babel-stamp
	@if test -f $@; then\
	  touch $@; \
	else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp ; \
	fi

babel-stamp: $(SIDLFILE)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=f90 $(BABELEXTRA) \
		$(SIDLFILE) 
	@mv -f babel-temp $@

$(SYNCHBABELGEN) : synch-stamp
	@if test -f $@; then\
	  touch $@; \
	else \
	  rm -f synch-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) synch-stamp ; \
	fi

synch-stamp: $(OUTPUTSIDL)
	@rm -f synch-temp
	@touch synch-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=f90 --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f synch-temp $@

update-babel-make:babel-stamp synch-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	fi

clean-local:
	rm -f *.a *.so *.mod *.testresult *$(F90CPPSUFFIX)
	test "X$(srcdir)" = "X." || rm -f babel.make synch_babel.make

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
	$(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) 

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
	  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS)
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
