##
## File:        Makefile.am
## Package:     Babel CCA Hello examples
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for F77 CCA Hello World client
##

if SUPPORT_FORTRAN77
check_PROGRAMS    = HelloDriver
check_SCRIPTS =  runFortran.sh
check_LTLIBRARIES = libDriver.la
endif 

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDLSTUBS=$(top_builddir)/lib/sidlstubs/F77/libsidlstub_f77.la
PUREBABELGEN = $(STUBSRCS) $(STUBHDRS) $(IORHDRS)
BABELXTRA = $(STUBFORTRANINC) $(STUBDOCS)
CLEANFILES = $(PUREBABELGEN) $(BABELXTRA) babel-stamp babel-temp \
	babel.make.package babel.make.depends

nodist_libDriver_la_SOURCES      = $(PUREBABELGEN)
libDriver_la_LIBADD       = $(LIBSIDLSTUBS)
libDriver_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@
libDriver_la_LINK = $(F77LINK) $(libDriver_la_LDFLAGS)

if SUPPORT_STATIC
SHARED_PROGS             = HelloDriver
HelloDriver_SOURCES      = HelloDriver.f
HelloDriver_LDFLAGS	 = -dynamic
HelloDriver_LDADD        = libDriver.la $(FLIBS)
HelloDriver_LINK	 = $(LINK) $(FMAIN) $(HelloDriver_LDFLAGS)
endif

EXTRA_DIST = babel.make
AM_CPPFLAGS   = -I$(INCLUDEDIR) -I$(top_builddir)/lib/sidlstubs/F77

$(PUREBABELGEN) $(BABELXTRA) : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	 else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	 fi 

babel-stamp:
	@rm -f babel-temp
	@touch babel-temp	
	$(SHELL) $(BABELDIR)/babel --client=f77 \
	  --repository-path=../repository \
	  decaf.Framework gov.cca
	@mv -f babel-temp $@

clean-local:
	rm -f *.a *.so
	test "X$(srcdir)" = "X." || rm -f runFortran.sh babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
