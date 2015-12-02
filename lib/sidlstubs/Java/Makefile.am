JAR=@JAR@
VERSION=@VERSION@
BABEL=`if test "$(BABELDIR)" != "$(top_builddir)/bin" ; then echo babel | sed '$(transform)' ; else echo babel; fi`
BABELDIR   = $(top_builddir)/bin
INCLUDEDIR = $(top_builddir)/runtime/sidl
LIBSIDL    = $(top_builddir)/runtime/sidl/libsidl.la
CLASSPATH  = $(top_builddir)/lib/sidl-$(VERSION).jar
EXTRA_DIST = babel.make sidlx_babel.make
AM_CPPFLAGS = -I$(INCLUDEDIR) $(JNI_INCLUDES)
JAVAC_FLAGS = -g -source 1.4 -target 1.4 -d . -classpath "$(CLASSPATH)"
jardir=$(prefix)/lib
jar_DATA=sidlstub_$(VERSION).jar
BABELGEN=$(STUBSRCS) $(STUBHDRS) $(IORHDRS)
SIDLXGEN=$(sidlx_STUBSRCS) $(sidlx_STUBHDRS) $(sidlx_IORHDRS)
if WITH_SIDLX
ALLSRCS=$(BABELGEN) $(SIDLXGEN)
ALLSTUBS=$(STUBSRCS) $(sidlx_STUBSRCS)
SIDLX=sidlx
else
ALLSRCS=$(BABELGEN)
ALLSTUBS=$(STUBSRCS)
SIDLX=
endif

if SUPPORT_JAVA
lib_LTLIBRARIES = libsidlstub_java.la
all-local: libsidlstub_java.scl
else
all-local:
endif

javaincldir = $(includedir)/java
nodist_javaincl_HEADERS = $(STUBHDRS)

nodist_libsidlstub_java_la_SOURCES      = $(ALLSRCS)
libsidlstub_java_la_LIBADD       = $(LIBSIDL)
libsidlstub_java_la_LDFLAGS      = -no-undefined -release @VERSION@

CLEANFILES = $(BABELGEN) $(SIDLXGEN) \
	stamp-installcheck babel-stamp babel-temp sidlx-stamp sidlx-temp \
	babel.make.package babel.make.depends \
	sidlx_babel.make.package sidlx_babel.make.depends \
	libsidlstub_java.scl sidlstub_$(VERSION).jar

sidlstub_$(VERSION).jar : $(ALLSRCS)
	$(JAVAC) $(JAVAC_FLAGS) `find sidl $(SIDLX) -name "*.java" -print`
	$(JAR) cf $@ `find sidl $(SIDLX) -name "*.class" -print`

$(BABELGEN) : babel-stamp
	@if test -f $@ ; then \
		touch $@ ; \
	 else \
		rm -f babel-stamp ; \
		$(MAKE) $(AM_MAKEFLAGS) babel-stamp ; \
	 fi

babel-stamp: $(top_srcdir)/runtime/sidl/sidl.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --client=Java --include-referenced sidl
	@mv -f babel-temp $@

$(SIDLXGEN) : sidlx-stamp
	@if test -f $@ ; then \
		touch $@ ; \
	 else \
		rm -f sidlx-stamp ; \
		$(MAKE) $(AM_MAKEFLAGS) sidlx-stamp ; \
	 fi

sidlx-stamp: $(top_srcdir)/runtime/sidl/sidl.sidl $(top_srcdir)/runtime/sidlx/sidlx.sidl
	@rm -f sidlx-temp
	@touch sidlx-temp
	$(SHELL) $(BABELDIR)/$(BABEL) --make-prefix=sidlx_ --client=Java sidlx
	@mv -f sidlx-temp $@

$(sidlx_STUBSRCS:.c=.lo) : $(STUBHDRS) $(sidlx_STUBHDRS) $(IORHDRS) $(sidlx_IORHDRS)

libsidlstub_java.scl:$(ALLSTUBS)
	rm -f libsidlstub_java.scl
	echo "<?xml version=\"1.0\" ?>" > libsidlstub_java.scl
	echo "<scl>" >> libsidlstub_java.scl
	if test `uname` = "Darwin"; then \
	  scope="global"; \
	else \
	  scope="local"; \
	fi ; \
	echo "  <library uri=\""`pwd`"/libsidlstub_java.la\" scope=\"$$scope\" resolution=\"lazy\" >" >> libsidlstub_java.scl
	grep __register $(ALLSTUBS) /dev/null | awk 'BEGIN {FS=":"} { print $$1}' | sort -u | sed -e 's/_jniStub.c//g' -e 's/_/./g' | awk ' { printf "    <class name=\"%s\" desc=\"java\" />\n", $$1 }' >> libsidlstub_java.scl
	echo "  </library>" >> libsidlstub_java.scl
	echo "</scl>" >> libsidlstub_java.scl

check-local:
	@if test -f stamp-installcheck; then		\
	  rm -f stamp-installcheck				\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean ;	\
	  $(MAKE) $(AM_MAKEFLAGS) clean ;	\
	  echo $(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(jar_DATA) ; \
	  $(MAKE) $(AM_MAKEFLAGS) $(check_LTLIBRARIES) $(jar_DATA) ; \
	fi

clean-local:
	test "X$(srcdir)" = "X." || rm -f babel.make sidlx_babel.make
	rm -rf sidl sidlx

install-lib-local:
	cd $(DESTDIR)$(libdir) && rm -f sidlstub.jar && ln -s sidlstub_$(VERSION).jar sidlstub.jar

install-data-local: $(ALLSTUBS)
	rm -f $(libdir)/libsidlstub_java.scl
	echo "<?xml version=\"1.0\" ?>" > $(DESTDIR)$(libdir)/libsidlstub_java.scl
	echo "<scl>" >> $(DESTDIR)$(libdir)/libsidlstub_java.scl
	if test `uname` = "Darwin"; then \
	  scope="global"; \
	else \
	  scope="local"; \
	fi ; \
	echo "  <library uri=\"$(DESTDIR)$(libdir)/libsidlstub_java.la\" scope=\"$$scope\" resolution=\"lazy\" >" >> $(DESTDIR)$(libdir)/libsidlstub_java.scl
	grep __register $(ALLSTUBS) /dev/null | awk 'BEGIN {FS=":"} { print $$1}' | sort -u | sed -e 's/_jniStub.c//g' -e 's/_/./g' | awk ' { printf "    <class name=\"%s\" desc=\"java\" />\n", $$1 }' >> $(DESTDIR)$(libdir)/libsidlstub_java.scl
	echo "  </library>" >> $(DESTDIR)$(libdir)/libsidlstub_java.scl
	echo "</scl>" >> $(DESTDIR)$(libdir)/libsidlstub_java.scl
	chmod 644  $(DESTDIR)$(libdir)/libsidlstub_java.scl


uninstall-local:
	rm -f $(libdir)/libsidlstub_java.scl
	cd $(DESTDIR)$(libdir) && rm -f sidlstub.jar

installcheck-local:
	@if test ! -f stamp-installcheck; then		\
	  echo $(MAKE) $(AM_MAKEFLAGS) clean;		\
	  $(MAKE) $(AM_MAKEFLAGS) clean;		\
	fi
	touch stamp-installcheck
	$(MAKE) $(AM_MAKEFLAGS)				\
	  BABELDIR=$(bindir)				\
	  INCLUDEDIR=$(includedir)			\
	  LIBSIDL=$(libdir)/libsidl.la		\
	  $(lib_LTLIBRARIES) $(jar_DATA)

include $(srcdir)/babel.make
include $(srcdir)/sidlx_babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
