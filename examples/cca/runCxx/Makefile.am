##
## File:        Makefile.am
## Package:     Babel CCA Hello examples
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for F77 CCA Hello World client
##

AUTOMAKE_OPTIONS = foreign no-dependencies no-installinfo	\
                   no-installman no-texinfo.tex 1.7

check_PROGRAMS    = HelloDriver HelloDriver2
check_SHARED      = runCxx.sh
check_LTLIBRARIES = libDriver.la

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/lib/sidlstubs/Cxx
LIBSIDLSTUBS = $(top_builddir)/lib/sidlstubs/Cxx/libsidlstub_cxx.la
CLEANFILES=babel.make.package babel-stamp babel-temp \
	 $(IORHDRS) $(STUBHDRS) $(STUBSRCS) HelloDriver HelloDriver2 \
	babel.make.depends

nodist_libDriver_la_SOURCES      = $(STUBSRCS) $(STUBHDRS) $(IORHDRS) 
libDriver_la_LIBADD       = $(LIBSIDLSTUBS)
libDriver_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@

HelloDriver_SOURCES      = HelloDriver.cc 
HelloDriver_LDFLAGS	 = -dynamic
HelloDriver_LDADD        = libDriver.la
HelloDriver2_SOURCES     = HelloDriver2.cc 
HelloDriver2_LDFLAGS	 = -dynamic
HelloDriver2_LDADD       = libDriver.la


EXTRA_DIST = babel.make runCxx.sh
AM_CPPFLAGS   = -I$(INCLUDEDIR)

HelloDriver.$(OBJEXT) HelloDriver2.$(OBJEXT) : $(STUBHDRS) $(IORHDRS)

$(STUBSRCS) $(STUBHDRS) $(IORHDRS) : babel-stamp
	@if test -f $@; then \
		touch $@; \
	else \
		rm -f babel-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) babel-stamp;\
	fi

babel-stamp: 
	@rm -f babel-temp
	@touch babel-temp
	test "X$(srcdir)" = "X." || cp $(srcdir)/runCxx.sh .
	$(SHELL) $(BABELDIR)/babel --client=cxx \
	  --repository-path=../repository \
	  decaf.Framework gov.cca
	@mv -f babel-temp $@


clean-local:
	rm -f *.a *.so
	rm -rf ti_files
	test "X$(srcdir)" = "X." || rm -f runCxx.sh babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
