##
## File:        make.runJava
## Package:     Babel regression checks
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for run regression tests
##
## Copyright (c) 2000-2002, Lawrence Livermore National Security, LLC.
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

if SUPPORT_JAVA
check_SCRIPTS = runJava2C.sh runJava2Cxx.sh \
	runJava2F77.sh runJava2F90.sh runJava2Java.sh

check_LTLIBRARIES = libClient.la
SCLFILE=libClient.scl
endif

VERSION=@VERSION@
BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR    = $(top_builddir)/bin
INCLUDEDIR  = $(top_builddir)/runtime/sidl
INCLUDEDIR2 = .
STUBINCLUDEDIR = $(top_builddir)/lib/sidlstubs/Java
LIBSYNC     = ../../output/libC/libOutput.la
PUREBABELGEN = $(STUBSRCS) $(STUBHDRS) $(IORHDRS) \
	$(synch_STUBSRCS) $(synch_STUBHDRS) $(synch_IORHDRS) 
CLEANFILES = $(PUREBABELGEN) $(EXTRACLEAN) babel-temp babel-stamp \
	stamp-installcheck babel.make.package java-temp java-stamp \
	babel.make.depends synch_babel.make.package \
	synch_babel.make.depends libClient.scl synch-stamp


nodist_libClient_la_SOURCES = $(PUREBABELGEN)
libClient_la_SOURCES = $(SOURCE_EXTRAS)
libClient_la_LIBADD       = $(LIBSYNC)
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs \
			    -release $(VERSION)

EXTRA_DIST = $(TESTFILE) synch_babel.make babel.make $(JAVAPKG)/babel.make \
	synch/synch_babel.make
AM_CPPFLAGS   = -I. -I$(INCLUDEDIR) -I$(INCLUDEDIR2) -I$(STUBINCLUDEDIR) $(JNI_INCLUDES)

$(PUREBABELGEN) : babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi

CP = $(top_builddir)/lib/sidl-$(VERSION).jar:$(top_builddir)/lib/sidlstubs/Java/sidlstub_$(VERSION).jar
if SUPPORT_CYGWIN
  CLASSPATH = `cygpath --path --windows "$(CP):."`
else
  CLASSPATH = $(CP):.
endif
JAVAC_FLAGS = -g -d . -classpath "$(CLASSPATH)"

babel-stamp: $(SIDLFILE) $(TESTFILE) $(OUTPUTSIDL) $(SOURCE_EXTRAS)
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=java \
		$(BABELEXTRA) $(SIDLFILE)
	$(SHELL) $(BABELDIR)/$(BABEL) --client=java --make-prefix=synch_  \
	  $(OUTPUTSIDL)
	@mv -f babel-temp babel-stamp

libClient.scl : $(STUBSRCS) $(synch_STUBSRCS)
	rm -f libClient.scl
	echo "<?xml version=\"1.0\" ?>" > libClient.scl
	echo "<scl>" >> libClient.scl
	if test `uname` = "Darwin"; then \
	  scope="global"; \
	else \
	  scope="local"; \
	fi ; \
	echo "  <library uri=\""`pwd`"/libClient.la\" scope=\"$$scope\" resolution=\"lazy\" >" >> libClient.scl
	grep __register $(STUBSRCS) $(synch_STUBSRCS) /dev/null | awk 'BEGIN {FS=":"} { print $$1}' | sort -u | sed -e 's/_jniStub.c//g' -e 's/_/./g' | awk ' { printf "    <class name=\"%s\" desc=\"java\" />\n", $$1 }' >> libClient.scl
	echo "  </library>" >> libClient.scl
	echo "</scl>" >> libClient.scl

if SUPPORT_JAVA
java-stamp: babel-stamp
	@rm -f java-temp
	@touch java-temp
	if test "X$(srcdir)" = "X."; then				    \
	  $(JAVAC) $(JAVAC_FLAGS) `find . \( -name "*.java" -print \) -o \( -name .svn -prune \)`;	    \
	else								    \
	  $(JAVAC) $(JAVAC_FLAGS) `find $(srcdir) . \( -name "*.java" -print \) -o \( -name .svn -prune \)`; \
	fi
	@mv -f java-temp java-stamp
else
java-stamp:
	touch java-stamp
endif

update-babel-make:babel-stamp
	if test "X$(srcdir)" != "X."; then \
	   cp babel.make synch_babel.make $(srcdir); \
	   cp $(JAVAPKG)/babel.make $(srcdir)/$(JAVAPKG); \
	   cp synch/synch_babel.make $(srcdir)/synch/synch_babel.make; \
	fi

clean-local:
	rm -f *.a *.so *.scl *.class *.testresult
	rm -rf `find . \( \( -name .svn -o -name .libs -o -name CVS -o -name "*.o" -o -name "*.lo" \) -prune \) -o \( -type d ! -name "." -print \)`
	test "X$(srcdir)" = "X." || rm -f babel.make synch_babel.make\
		$(check_SCRIPTS)

check-local:
	@if test -f stamp-installcheck; then            \
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;           \
	  $(MAKE) $(AM_MAKEFLAGS) clean;                \
	fi
	$(MAKE) $(AM_MAKEFLAGS)				\
	  $(check_LTLIBRARIES) $(check_PROGRAMS) $(check_SCRIPTS) \
	  java-stamp $(SCLFILE)

installcheck-local:
	@if test ! -f stamp-installcheck; then          \
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;           \
	  $(MAKE) $(AM_MAKEFLAGS) clean;                \
	fi
	$(MAKE) $(AM_MAKEFLAGS)                         \
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)	                 \
	  INCLUDEDIR2=$(exec_prefix)/include            \
	  CP=$(libdir)/sidl-$(VERSION).jar:$(libdir)/sidlstub_$(VERSION).jar \
	  $(check_PROGRAMS) $(check_SCRIPTS) $(check_LTLIBRARIES) java-stamp \
	  $(SCLFILE)
	touch stamp-installcheck

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
