

if SUPPORT_FORTRAN77

if WITH_SIDLX
ALLSRCS=$(BABELSRCS) $(SIDLXSRCS)
INSTALLHDRS=  $(STUBFORTRANINC) $(STUBHDRS) $(sidlx_STUBFORTRANINC) $(sidlx_STUBHDRS)
else
ALLSRCS=$(BABELSRCS)
INSTALLHDRS=  $(STUBFORTRANINC) $(STUBHDRS)
endif

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
EXTRA_DIST = babel.make sidlx_babel.make
AM_CPPFLAGS = -I$(INCLUDEDIR)

BABELDOCS=$(STUBDOCS)
BABELSRCS=$(IORHDRS) $(STUBHDRS) $(STUBSRCS) $(STUBFORTRANINC)
SIDLXDOCS=$(sidlx_STUBDOCS)
SIDLXSRCS=$(sidlx_IORHDRS) $(sidlx_STUBHDRS) $(sidlx_STUBSRCS) $(sidlx_STUBFORTRANINC)

lib_LTLIBRARIES = libsidlstub_f77.la

f77incldir = $(includedir)/f77
nodist_f77incl_HEADERS = $(INSTALLHDRS)

nodist_libsidlstub_f77_la_SOURCES      = $(ALLSRCS) 
libsidlstub_f77_la_LIBADD       = $(LIBSIDL)
libsidlstub_f77_la_LDFLAGS      = -no-undefined -release @VERSION@ $(FFLAGS)

CLEANFILES = $(BABELDOCS) $(BABELSRCS) \
	$(SIDLXDOCS) $(SIDLXSRCS) \
	babel-stamp stamp-installcheck babel-temp \
	sidlx-stamp sidlx-temp \
	babel.make.package babel.make.depends \
	sidlx_babel.make.package sidlx_babel.make.depends

endif


$(BABELDOCS) $(BABELSRCS) : babel-stamp
	@if test -f $@; then \
		touch $@; \
	 else \
		rm -f babel-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	 fi

babel-stamp: $(top_srcdir)/runtime/sidl/sidl.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=F77 --include-referenced sidl
	@mv -f babel-temp $@

$(SIDLXDOCS) $(SIDLXSRCS) : sidlx-stamp
	@if test -f $@; then \
		touch $@; \
	 else \
		rm -f sidlx-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) sidlx-stamp; \
	 fi

sidlx-stamp: $(top_srcdir)/runtime/sidl/sidl.sidl $(top_srcdir)/runtime/sidlx/sidlx.sidl
	@rm -f sidlx-temp
	@touch sidlx-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=F77 --make-prefix=sidlx_ sidlx
	@mv -f sidlx-temp $@

$(sidlx_STUBSRCS:.c=.lo):$(IORHDRS)

check-local:
	@if test -f stamp-installcheck; then		\
	  rm -f stamp-installcheck ; 			\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean ;	\
	  $(MAKE) $(AM_MAKEFLAGS) clean ;		\
	  echo $(MAKE) $(AM_MAKEFLAGS) check ;	\
	  $(MAKE) $(AM_MAKEFLAGS) check ;		\
	fi

installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	touch stamp-installcheck			
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  INCLUDEDIRX=$(includedir)			\
	  INCLUDEDIR2=$(exec_prefix)/include		\
	  LIBSIDL=$(libdir)/libsidl.la		\
	  LIBSIDLX=$(INSTALLEDSIDLX) $(lib_LTLIBRARIES)
clean-local:
	test "X$(srcdir)" = "X." || rm -f babel.make sidlx_babel.make

include $(srcdir)/babel.make
include $(srcdir)/sidlx_babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
