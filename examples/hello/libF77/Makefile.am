##
## File:        Makefile.am
## Package:     Babel examples
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for f77 Hello World server
##

AUTOMAKE_OPTIONS = foreign no-dependencies no-installinfo	\
                   no-installman no-texinfo.tex 1.7

if SUPPORT_FORTRAN77
check_LTLIBRARIES = libImpl.la
endif
BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl 
LIBSIDLSTUBS = $(top_builddir)/lib/sidlstubs/F77/libsidlstub_f77.la

BABELGEN=$(IMPLSRCS)
PUREBABELGEN=$(IORSRCS) $(STUBSRCS) $(SKELSRCS) $(IORHDRS) $(STUBFORTRANINC) \
	$(STUBHDRS)
DOCFILES=$(STUBDOCS) 
CLEANFILES=$(PUREBABELGEN) babel-stamp babel-temp libImpl.scl \
	$(DOCFILES) stamp-installcheck core babel.make.package \
	babel.make.depends

libImpl_la_SOURCES      = $(BABELGEN)
nodist_libImpl_la_SOURCES = $(PUREBABELGEN)
libImpl_la_LIBADD       = $(LIBSIDLSTUBS)
libImpl_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@ -module

EXTRA_DIST = babel.make
AM_CPPFLAGS   = -I$(INCLUDEDIR) -I$(top_builddir)/lib/sidlstubs/F77

$(BABELGEN) $(PUREBABELGEN) $(DOCFILES) : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  rm -f babel-stamp ; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(srcdir)/../Hello.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --vpath="$(srcdir)" --server=f77 \
	  $(srcdir)/../Hello.sidl
	$(SHELL) $(top_srcdir)/bin/generate_scl libImpl.scl `pwd`/libImpl.la \
	   $(IORSRCS)
	@mv -f babel-temp $@

clean-local:
	rm -f *.a *.so *.scl
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
