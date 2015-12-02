##
## File:        Makefile.am
## Package:     Babel Hello example
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for C Hello World server
##

check_LTLIBRARIES = libImpl.la

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
PUREBABELGEN = $(IORSRCS) $(SKELSRCS) $(STUBSRCS) $(STUBHDRS) $(IORHDRS) 
BABELGEN = $(IMPLSRCS) $(IMPLHDRS)
CLEANFILES = $(PUREBABELGEN) libImpl.scl babel-stamp babel-temp \
	babel.make.package babel.make.depends

nodist_libImpl_la_SOURCES = $(PUREBABELGEN)
dist_libImpl_la_SOURCES = $(BABELGEN)
libImpl_la_LIBADD         = $(LIBSIDL) 
libImpl_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@ -module

EXTRA_DIST = babel.make
AM_CPPFLAGS   = -I$(INCLUDEDIR)

$(PUREBABELGEN) $(BABELGEN) libImpl.scl : babel-stamp
	@if test -f $@; then \
	    touch $@; \
	else \
	    rm -f babel-stamp ; \
	    $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp : $(srcdir)/../Hello.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/babel --vpath="$(srcdir)" --server=C \
	  $(srcdir)/../Hello.sidl
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)
	@mv babel-temp $@

clean-local:
	test "X$(srcdir)" = "X." || rm -f $(IMPLHDRS) $(IMPLSRCS) babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
