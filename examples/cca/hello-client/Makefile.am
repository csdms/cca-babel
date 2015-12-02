##
## File:        Makefile.am
## Package:     Babel examples
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for cca hello client example
##

AUTOMAKE_OPTIONS = foreign no-dependencies no-installinfo no-installman \
                   no-texinfo.tex 1.7

check_LTLIBRARIES = libHelloClient.la

BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
PUREBABELGEN = $(STUBSRCS) $(STUBHDRS) $(IORSRCS) $(IORHDRS) $(SKELSRCS)
HANDTUNEDGEN = $(IMPLSRCS) $(IMPLHDRS)

nodist_libHelloClient_la_SOURCES      = $(PUREBABELGEN)
libHelloClient_la_SOURCES      = $(HANDTUNEDGEN)
libHelloClient_la_LIBADD       = $(LIBSIDL)
libHelloClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@ -module

EXTRA_DIST = hello-client.sidl babel.make
AM_CPPFLAGS = -I. -I$(INCLUDEDIR)
CLEANFILES = $(PUREBABELGEN) babel-temp babel-stamp stamp-installcheck \
	babel.make.package babel.make.depends

$(PUREBABELGEN) $(HANDTUNEDGEN) : babel-stamp
	@if test -f $@; then \
	  touch $@ ; \
	else \
	  rm -f babel-stamp; \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

babel-stamp: $(srcdir)/hello-client.sidl
	@rm -f babel-temp
	@touch babel-temp
	rm -f ../repository/HelloClient*.xml
	$(SHELL) $(BABELDIR)/$(BABEL) --text=xml -R../repository	\
	  -o../repository $(srcdir)/hello-client.sidl
	$(SHELL) $(BABELDIR)/$(BABEL) --vpath="$(srcdir)" --server=c \
	  --repository-path=../repository \
	  HelloClient strop.StringProducerPort gov.cca
	rm -f libHelloClient.scl
	echo "<?xml version=\"1.0\" ?>" > libHelloClient.scl
	echo "<scl>" >> libHelloClient.scl
	echo "  <library uri=\""`pwd`"/libHelloClient.la\" scope=\"local\" resolution=\"lazy\" >" >> libHelloClient.scl
	grep __set_epv $(IORSRCS) /dev/null | awk 'BEGIN {FS=":"} { print $$1}' | sort -u | sed -e 's/_IOR.c//g' -e 's/_/./g' | awk ' { printf "    <class name=\"%s\" desc=\"ior/impl\" />\n", $$1 }' >> libHelloClient.scl
	echo "  </library>" >> libHelloClient.scl
	echo "</scl>" >> libHelloClient.scl
	@mv babel-temp $@

clean-local:
	rm -f *.a *.so *.scl
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) $(IMPLHDRS) babel.make

include $(srcdir)/babel.make


# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
