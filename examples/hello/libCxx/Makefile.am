##
## File:        Makefile.am
## Package:     Babel Hello example
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for C++ Hello World server
##

AUTOMAKE_OPTIONS = foreign no-dependencies no-installinfo	\
                   no-installman no-texinfo.tex 1.7

if SUPPORT_CXX
check_LTLIBRARIES = libImpl.la
endif

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDLSTUBS = $(top_builddir)/lib/sidlstubs/Cxx/libsidlstub_cxx.la
BABELGEN=$(IMPLSRCS) $(IMPLHDRS)
PUREBABELGEN=$(STUBSRCS) $(STUBHDRS) $(IORSRCS) $(IORHDRS) $(SKELSRCS)
CLEANFILES=$(PUREBABELGEN) babel-stamp babel-temp libImpl.scl \
	babel.make.package babel.make.depends

dist_libImpl_la_SOURCES = $(BABELGEN)
nodist_libImpl_la_SOURCES = $(PUREBABELGEN)
libImpl_la_LIBADD       = $(LIBSIDLSTUBS)
libImpl_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@

EXTRA_DIST = babel.make
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I $(top_builddir)/lib/sidlstubs/Cxx

$(BABELGEN) $(PUREBABELGEN) libImpl.scl : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f babel-stamp ; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(srcdir)/../Hello.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/babel --vpath="$(srcdir)" --server=C++ \
	  $(srcdir)/../Hello.sidl
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)
	@mv -f babel-temp $@

update-babel-make: babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make $(srcdir); \
	fi

clean-local:
	rm -f *.a *.so
	rm -rf ti_files
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) $(IMPLHDRS) babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
