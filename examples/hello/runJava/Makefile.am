##
## File:        Makefile.am
## Package:     Babel Hello example
## Copyright:   (c) 2000-2001 Lawrence Livermore National Security, LLC
## Revision:    $Revision: 6527 $
## Modified:    $Date: 2008-09-22 16:16:22 -0700 (Mon, 22 Sep 2008) $
## Description: automake makefile for Java hello world client
##

AUTOMAKE_OPTIONS = foreign no-dependencies no-installinfo	\
                   no-installman no-texinfo.tex 1.7

if SUPPORT_JAVA
check_SCRIPTS     = runJava2C.sh runJava2Cxx.sh runJava2F77.sh runJava2Java.sh runJava2Py.sh
check_LTLIBRARIES = libClient.la
endif

nodist_libClient_la_SOURCES      = $(STUBSRCS) $(STUBHDRS) $(IORHDRS) 
libClient_la_LIBADD       = $(LIBSIDL) 
libClient_la_LDFLAGS      = -no-undefined -rpath `pwd`/.libs -release @VERSION@

BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl 
STUBINCLUDEDIR = $(top_builddir)/lib/sidlstubs/Java
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
VERSION=@VERSION@
sidlJAR=$(top_builddir)/lib/sidl-$(VERSION).jar
SIDLSTUBSJAR=$(top_builddir)/lib/sidlstubs/Java/sidlstub_$(VERSION).jar
CLEANFILES = $(STUBSRCS) $(STUBHDRS) $(IORHDRS) babel-temp babel-stamp \
	babel.make.package babel.make.depends


EXTRA_DIST = babel.make
AM_CPPFLAGS   = -I$(INCLUDEDIR) -I$(STUBINCLUDEDIR)  $(JNI_INCLUDES)

$(STUBSRCS): babel-stamp
	@if test -f $@; then \
	  touch $@; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	fi 

if SUPPORT_CYGWIN
  CLASSPATH = `cygpath --path --windows "$(sidlJAR)"`
else
  CLASSPATH = $(sidlJAR):$(SIDLSTUBSJAR)
endif
JAVAC_FLAGS = -g -d . -classpath "$(CLASSPATH)"

babel-stamp: $(srcdir)/../Hello.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/babel  \
		--client=java $(srcdir)/../Hello.sidl
	if test "X$(srcdir)" = "X."; then				    \
	  $(JAVAC) $(JAVAC_FLAGS) `find $(srcdir)			    \
	     -name .svn -prune -o					    \
	     -name CVS -prune -o -name SCCS -prune -o 			    \
             -name "*.java" -print`;					    \
	else								    \
	  $(JAVAC) $(JAVAC_FLAGS) `find $(srcdir) .			    \
	     -name .svn -prune -o					    \
	     -name CVS -prune -o -name SCCS -prune -o 			    \
             -name "*.java" -print`;					    \
	fi
	rm -f libClient.scl
	echo "<?xml version=\"1.0\" ?>" > libClient.scl
	echo "<scl>" >> libClient.scl
	echo "  <library uri=\""`pwd`"/libClient.la\" scope=\"local\" resolution=\"lazy\" >" >> libClient.scl
	grep  __register $(STUBSRCS) /dev/null | awk 'BEGIN {FS=":"} { print $$1}' | sort -u | sed -e 's/_jniStub.c//g' -e 's/_/./g' | awk ' { printf "    <class name=\"%s\" desc=\"java\" />\n", $$1 }' >> libClient.scl
	echo "  </library>" >> libClient.scl
	echo "</scl>" >> libClient.scl
	@mv -f babel-temp babel-stamp


clean-local:
	rm -f *.a *.so *.scl *.class i
	rm -rf Hello sidl
	test "X$(srcdir)" = "X." || rm -f babel.make $(noinst_SCRIPTS)

include $(srcdir)/babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
