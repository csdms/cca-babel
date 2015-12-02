

BABELGEN=$(BASICMODULESRC) $(TYPEMODULESRCS) $(ARRAYMODULESRCS) $(STUBMODULESRCS) $(STUBSRCS) $(STUBHDRS) $(IORHDRS)
SIDLXGEN=$(sidlx_BASICMODULESRC) $(sidlx_TYPEMODULESRCS) $(sidlx_ARRAYMODULESRCS) $(sidlx_STUBMODULESRCS) $(sidlx_STUBSRCS) $(sidlx_STUBHDRS) $(sidlx_IORHDRS)
BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`

if SUPPORT_FORTRAN03

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
EXTRA_DIST = babel.make sidlx_babel.make
AM_CPPFLAGS = -I$(INCLUDEDIR)

if WITH_SIDLX
ALLSRCS=$(BABELGEN) $(SIDLXGEN)
INSTALLHDRS=$(STUBHDRS) $(sidlx_STUBHDRS)
else
ALLSRCS=$(BABELGEN)
INSTALLHDRS=$(STUBHDRS)
endif


lib_LTLIBRARIES = libsidlstub_f03.la

f03incldir = $(includedir)/f03
nodist_f03incl_HEADERS = $(INSTALLHDRS)

nodist_libsidlstub_f03_la_SOURCES      = $(ALLSRCS) 
libsidlstub_f03_la_LIBADD       = $(LIBSIDL) $(FCLIBS)
libsidlstub_f03_la_LDFLAGS      = -no-undefined -release @VERSION@ $(AM_FFLAGS) $(FCFLAGS)
libsidlstub_f03_la_LINK	        = $(LINK) $(libsidlstub_f03_la_LDFLAGS)

endif
CLEANFILES = $(BABELGEN) $(SIDLXGEN) \
	babel-stamp stamp-installcheck babel-temp \
	babel.make.package babel.make.depends \
	sidlx_babel.make.package sidlx_babel.make.depends \
	sidlx-stamp sidlx-temp

# Customize some F03 macros since automake (as of 1.9.3)
# still doesn't include the --tag specifier for libtool
LTPPFCCOMPILE = $(LIBTOOL) --mode=compile --tag=FC $(FC) $(DEFS) \
	$(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) \
	$(AM_FCFLAGS) $(FCFLAGS) $(FCFLAGS_f90)


$(TYPEMODULESRCS:.F90=.lo) : $(BASICMODULESRC:.F90=.lo)
$(ARRAYMODULESRCS:.F90=.lo) : $(TYPEMODULESRCS:.F90=.lo)
$(STUBMODULESRCS:.F90=.lo) : $(ARRAYMODULESRCS:.F90=.lo) $(TYPEMODULESRCS:.F90=.lo)
$(IMPLMODULESRCS:.F90=.lo) : $(STUBMODULESRCS:.F90=.lo)

$(sidlx_TYPEMODULESRCS:.F90=.lo) : $(BASICMODULESRC:.F90=.lo) $(sidlx_BASICMODULESRC:.F90=.lo)
$(sidlx_ARRAYMODULESRCS:.F90=.lo) : $(TYPEMODULESRCS:.F90=.lo) $(sidlx_TYPEMODULESRCS:.F90=.lo)
$(sidlx_STUBMODULESRCS:.F90=.lo) : $(ARRAYMODULESRCS:.F90=.lo) $(TYPEMODULESRCS:.F90=.lo) $(sidlx_ARRAYMODULESRCS:.F90=.lo) $(sidlx_TYPEMODULESRCS:.F90=.lo)
$(sidlx_IMPLMODULESRCS:.F90=.lo) : $(STUBMODULESRCS:.F90=.lo) $(sidlx_STUBMODULESRCS:.F90=.lo)

$(BABELGEN) : babel-stamp
	@if test -f $@; then \
		touch $@; \
	 else \
		rm -f babel-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	 fi

babel-stamp: $(top_srcdir)/runtime/sidl/sidl.sidl 
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=F03 --include-referenced sidl
	@mv -f babel-temp $@

$(SIDLXGEN) : sidlx-stamp
	@if test -f $@; then \
		touch $@; \
	 else \
		rm -f sidlx-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) sidlx-stamp; \
	 fi

sidlx-stamp: $(top_srcdir)/runtime/sidlx/sidlx.sidl $(top_srcdir)/runtime/sidl/sidl.sidl 
	@rm -f sidlx-temp
	@touch sidlx-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=F03 --make-prefix=sidlx_ sidlx
	@mv -f sidlx-temp $@

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

# * is used in the for loop instead of *.mod to avoid the situation
# where *.mod does not match any files. Using * with case works
# when --with-bindc=no is specified.
install-data-local:
	test -z "$(f03incldir)" || $(mkdir_p) "$(DESTDIR)$(f03incldir)"
	@for p in *; do \
	  case "$$p" in \
	    *.mod) \
		echo " $(INSTALL_HEADER) '$$p' '$(DESTDIR)$(f03incldir)'"; \
		$(INSTALL_HEADER) "$$p" "$(DESTDIR)$(f03incldir)";; \
	  esac \
	done

uninstall-local:
	$(RM) $(DESTDIR)$(f03incldir)/*.mod;

clean-local:
	test "X$(srcdir)" = "X." || rm -f babel.make sidlx_babel.make
	rm -f *.mod

# Override default F03 macros since automake (as of 1.9.3) doesn't
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

include $(srcdir)/babel.make
include $(srcdir)/sidlx_babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
