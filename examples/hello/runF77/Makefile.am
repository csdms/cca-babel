##
## File:        Makefile.am
## Package:     Babel Hello examples
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for F77 Hello World client
##

LIBSIDLSTUBS = $(top_builddir)/lib/sidlstubs/F77/libsidlstub_f77.la

if SUPPORT_FORTRAN77
check_PROGRAMS    = $(STATIC_PROGS) $(SHARED_PROGS)
check_SHARED      = runAll.sh
check_LTLIBRARIES = libClient.la
endif


# This little snippet forces automake to define $CXXLINK
EXTRA_PROGRAMS  = automake_hack
automake_hack_SOURCES = 
nodist_EXTRA_automake_hack_SOURCES = automake_hack.cc

nodist_libClient_la_SOURCES      = $(PUREBABELGEN)
libClient_la_LIBADD       = $(LIBSIDLSTUBS)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@
libClient_la_LINK = $(F77LINK) $(libClient_la_LDFLAGS)

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl 
PUREBABELGEN = $(STUBSRCS) $(STUBHDRS) $(IORHDRS)
BABELXTRA = $(STUBDOCS) $(STUBFORTRANINC)
CLEANFILES = $(PUREBABELGEN) $(BABELXTRA) babel-stamp babel-temp \
	babel.make.package babel.make.depends

if SUPPORT_STATIC
STATIC_PROGS       = runF772C runF772Cxx runF772F77

runF772C_SOURCES        = helloclient.f
runF772C_LDFLAGS        = -static-libtool-libs
runF772C_LDADD          = libClient.la ../libC/libImpl.la $(LIBSIDLSTUBS) $(FLIBS)
runF772C_LINK		= $(LINK)  $(FMAIN) $(runF772C_LDFLAGS)
# use C linker instead of F77 to avoid problem when compiling with Intel's
# icc with optimization (undefined _intel_fast_memcpy symbol)

runF772Cxx_SOURCES      = helloclient.f
runF772Cxx_LDFLAGS      = -static-libtool-libs
runF772Cxx_LDADD        = libClient.la ../libCxx/libImpl.la $(LIBSIDLSTUBS) $(FLIBS)
runF772Cxx_LINK         = $(CXXLINK) $(FMAIN) $(runF772Cxx_LDFLAGS)

runF772F77_SOURCES      = helloclient.f
runF772F77_LDFLAGS      = -static-libtool-libs
runF772F77_LDADD        =  libClient.la ../libF77/libImpl.la $(LIBSIDLSTUBS) $(FLIBS)
runF772F77_LINK		= $(LINK)  $(FMAIN) $(runF772F77_LDFLAGS)

endif
if SUPPORT_SHARED
SHARED_PROGS            = runAll
runAll_SOURCES          = helloclient.f
runAll_LDFLAGS		= -dynamic
runAll_LDADD            = libClient.la $(LIBSIDLSTUBS) $(FLIBS)
runAll_LINK		= $(LINK) $(FMAIN) $(runAll_LDFLAGS)
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


babel-stamp: $(srcdir)/../Hello.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/babel \
	   --client=f77 $(srcdir)/../Hello.sidl
	@mv -f babel-temp $@

update-babel-make:babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make $(srcdir); \
	fi

clean-local:
	rm -f *.a *.so
	rm -rf ti_files
	test "X$(srcdir)" = "X." || rm -f babel.make

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
