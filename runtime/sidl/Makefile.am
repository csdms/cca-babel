##
## File:        Makefile.am 
## Package:     Babel makefiles
## Revision:    $Revision: 6487 $
## Modified:    $Date: 2008-08-29 10:49:33 -0700 (Fri, 29 Aug 2008) $
## Description: automake makefile to build the sidl runtime library
##
## Copyright (c) 2000-2002, The Regents of the University of Calfornia.
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

dist_data_DATA = sidl.sidl

execincldir = $(exec_prefix)/include
nodist_execincl_HEADERS =  babel_config.h
DISTCLEANFILES=babel_config.h

#(gkk) Seems all IOR.c's require sidl_BaseClass__get_data.
#(gkk) So we'll install this one Impl.h.... for now 
include_HEADERS = $(STUBHDRS) $(IORHDRS) $(CUSTOMHDRS) sidl_BaseClass_Impl.h \
	sidl_EnfPolicy_Impl.h 

lib_LTLIBRARIES = libsidl.la 
# Note do not use nodist_libsidl_la_SOURCES here unless you've
# thought through how babel-runtime.tar.gz is going to work.
libsidl_la_SOURCES = $(IMPLSRCS) $(IMPLHDRS) \
	$(CUSTOMSRCS) $(CUSTOMHDRS) \
	$(STUBSRCS) $(STUBHDRS) $(IORSRCS) $(IORHDRS) \
	$(SKELSRCS) $(SKELHDRS)
if WITH_SIDLX
libsidl_la_DEPENDENCIES = ../sidlx/babel-stamp
SIDLXINCLUDE=-I$(srcdir)/../sidlx
else
libsidl_la_DEPENDENCIES =
SIDLXINCLUDE=
endif
libsidl_la_LIBADD = $(LIBLTDL) $(LIBADD_DL) $(F90_LIBS) $(LIBXML2_LIB) \
	$(LIBPARSIFAL_LIB) -lm
libsidl_la_LDFLAGS = -no-undefined -release $(VERSION)
$(libsidl_la_OBJECTS) $(nodist_libsidl_la_OBJECTS) : babel_config.h $(STUBHDRS) $(IORHDRS) $(SKELHDRS) $(CUSTOMHDRS)


EXTRA_DIST = $(SRCS_EXCLUDED) ignore_me.h.in \
	libsidl.scl.in scl.dtd changeundef.awk


AM_CPPFLAGS=$(F90_CFLAGS) $(LIBXML2_CFLAGS) $(LIBPARSIFAL_CFLAGS) $(JNI_INCLUDES) $(SIDLXINCLUDE) $(PYTHONINC) $(LTDLINCL)

SRCS_EXCLUDED = $(FORTRAN_EXCLUDED) $(PYTHON_EXCLUDED) $(JAVA_EXCLUDED)
SRCS_INCLUDED = $(FORTRAN_SOURCES) $(PYTHON_SOURCES) $(JAVA_SOURCES)

if SUPPORT_FORTRAN90
FORTRAN_SOURCES = sidlfortran.c sidlf90array.c
F90_CFLAGS = $(CHASM_CFLAGS)
F90_LIBS = $(CHASM_LIBS)
else
F90_CFLAGS =
F90_LIBS = 
if SUPPORT_FORTRAN77 
FORTRAN_SOURCES = sidlfortran.c sidlf90array.c
else
FORTRAN_EXCLUDED = sidlfortran.c sidlf90array.c
endif
endif

if SUPPORT_PYTHON
PYTHON_SOURCES = sidl_Python.c
else
PYTHON_EXCLUDED = sidl_Python.c
endif

if SUPPORT_JAVA
JAVA_SOURCES = sidl_Java.c
else
JAVA_EXCLUDED = sidl_Java.c
endif

CUSTOMHDRS = \
	sidlArray.h \
	sidlAsserts.h \
	sidlCas.h \
	sidlMemory.h \
	sidl_Enforcer.h \
	sidl_Exception.h \
	sidlType.h \
	sidlOps.h \
	sidl_search_scl.h \
	sidlfortran.h \
	sidlf90array.h \
	sidl_Java.h \
	sidl_Python.h \
	sidl_String.h \
	sidl_bool_IOR.h \
	sidl_char_IOR.h \
	sidl_dcomplex_IOR.h \
	sidl_double_IOR.h \
	sidl_fcomplex_IOR.h \
	sidl_float_IOR.h \
	sidl_header.h \
	sidl_int_IOR.h \
	sidl_long_IOR.h \
	sidl_opaque_IOR.h \
	sidl_string_IOR.h \
	sidl_interface_IOR.h \
	sidl_cxx.hxx \
	sidl_thread.h \
	sidl_exec_err.h \
	sidl_hashtable.h \
	sidl_hashtable_private.h

CUSTOMSRCS = \
	$(FORTRAN_SOURCES) \
	$(JAVA_SOURCES) \
	$(PYTHON_SOURCES) \
	sidl_String.c \
	sidl_Enforcer.c \
	sidl_Exception.c \
	sidlArray.c \
	sidlMemory.c \
	sidlOps.c \
	sidl_bool_IOR.c \
	sidl_search_scl.c \
	sidl_char_IOR.c \
	sidl_int_IOR.c \
	sidl_long_IOR.c \
	sidl_float_IOR.c \
	sidl_double_IOR.c \
	sidl_fcomplex_IOR.c \
	sidl_dcomplex_IOR.c \
	sidl_opaque_IOR.c \
	sidl_string_IOR.c \
	sidl_interface_IOR.c \
	sidl_thread.c \
	sidl_hashtable.c

all-local: libsidl.scl

libsidl.scl: 
	sed -e 's,@@DIR@@,'`pwd`',g' < $(srcdir)/libsidl.scl.in > libsidl.scl

if WITH_SIDLX
../sidlx/babel-stamp: babel-stamp
	cd ../sidlx && $(MAKE) $(AM_MAKEFLAGS) babel-stamp
endif

if BABEL_RUNTIME_ONLY
babel-stamp:
	@rm -f babel-temp
	@touch babel-temp
	@if test "X$(srcdir)" != "X." ; then \
	    list='$(CUSTOMHDRS)'; \
	    for i in $$list; do \
		echo cp $(srcdir)/$$i . ; \
		cp $(srcdir)/$$i . ;\
	    done; \
	fi
	@mv -f babel-temp $@

CLEANFILES = babel-stamp babel-temp babel.make.depends babel.make.package

else
$(STUBSRCS) $(STUBHDRS) $(IORSRCS) $(IORHDRS) $(SKELSRCS) $(SKELHDRS) $(IMPLSRCS) $(IMPLHDRS) : babel-stamp
	@if test -f $@; then \
		touch $@; \
	 else \
		rm -f babel-stamp; \
		$(MAKE) $(AM_MAKEFLAGS) babel-stamp; \
	 fi 

$(CUSTOMHDRS) : extra-stamp
	@if test -f $@; then \
		touch $@; \
	else \
		rm -f extra-stamp ; \
		$(MAKE) $(AM_MAKEFLAGS) extra-stamp; \
	fi

babel-stamp: $(srcdir)/sidl.sidl
	@rm -f babel-temp
	@touch babel-temp
	$(SHELL) ../../bin/babel --include-referenced --no-default-repository\
	  --generate-sidl-stdlib --server=c --vpath=$(srcdir) \
	  $(srcdir)/sidl.sidl 
	@mv -f babel-temp $@

extra-stamp:
	@rm -f extra-temp
	@touch extra-temp
	@if test "X$(srcdir)" != "X." ; then \
	    list='$(CUSTOMHDRS)'; \
	    for i in $$list; do \
		echo cp $(srcdir)/$$i . ; \
		cp $(srcdir)/$$i . ;\
	    done; \
	fi
	@mv -f extra-temp $@

CLEANFILES = babel-stamp extra-stamp babel-temp extra-temp libsidl.scl \
		$(STUBSRCS) $(STUBHDRS) $(IORSRCS) \
		$(IORHDRS) $(SKELHDRS) $(SKELSRCS) libsidl.scl \
		babel.make.depends babel.make.package

clean-local:
	test "X$(srcdir)" = "X." || rm -f $(IMPLSRCS) $(IMPLHDRS) $(CUSTOMHDRS)

endif

# special link for Java on Mac OS X
check-local:
	-test -d .libs -a -h .libs/libsidl.dylib \
	     -a \! -h .libs/libsidl.jnilib && \
	(cd .libs ; ln -s libsidl.dylib libsidl.jnilib )

install-exec-hook:
	-test -d $(DESTDIR)$(libdir) -a -h $(DESTDIR)$(libdir)/libsidl.dylib \
	     -a \! -h $(DESTDIR)$(libdir)/libsidl.jnilib  && \
	( cd $(DESTDIR)$(libdir) ; ln -s libsidl.dylib libsidl.jnilib )

install-data-hook:
	sed -e 's,@@DIR@@,$(DESTDIR)$(libdir),g' < $(srcdir)/libsidl.scl.in \
		> libsidl_inst.scl
	$(INSTALL_DATA) libsidl_inst.scl $(DESTDIR)$(libdir)/libsidl.scl
	rm -f libsidl_inst.scl

uninstall-hook:
	rm -f $(DESTDIR)$(libdir)/libsidl.scl
	rm -f $(DESTDIR)$(libdir)/libsidl.jnilib

babel_config.h: babel_internal.h
	sed -e 's,babel_internal,babel_config,g' \
	    -e 's,PACKAGE,BABEL_PACKAGE,g' \
	   < $< > $@

AUTOHEADER = @AUTOHEADER@ \
	     && mv -f babel_internal.h.in babel_internal.h.in.bak \
	     && awk -f changeundef.awk babel_internal.h.in.bak \
	        > babel_internal.h.in \
             && rm -f babel_internal.h.in.bak

include babel.make

# Make sure Makefile.in is newer than babel.make
dist-hook:
	touch -c $(distdir)/Makefile.in
