##
## File:        Makefile.am 
## Package:     gov.llnl.babel
## Revision:    $Revision: 6552 $
## Modified:    $Date: 2008-10-13 08:51:17 -0700 (Mon, 13 Oct 2008) $
## Description: automake makefile for the Babel compiler system
##
## Copyright (c) 2000-2001, The Regents of the University of Calfornia.
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




JAR     = @JAR@
PACKAGE = @PACKAGE@
VERSION = @VERSION@
JARFILE = ../lib/$(PACKAGE)-$(VERSION).jar
CLEANFILES=babel-stamp babel-check-stamp

#
# Java classpath path information for jar files needed for compilation
#

CP = ../lib/java-getopt-1.0.7.jar:../lib/xerces-2.9.1.jar:../lib/jcert-1.0.1.jar:../lib/jnet-1.0.1.jar:../lib/jsse-1.0.1.jar:../lib/xml-apis.jar:../lib/xalan.jar

if SUPPORT_CYGWIN
  CLASSPATH = `cygpath --path --windows "$(CP)"`
else
  CLASSPATH = $(CP)
endif

#
# Compile the Babel jar file.  Recompile only if the jar file does not
# exist or if any of the java sources are newer than the jar file.
#

all-local: jarfile babel-stamp
check-local: babel-check-stamp
$(JARFILE): jarfile

jarfile:
	@if $(top_srcdir)/svnrevision.sh --topdir=$(top_srcdir) \
	    --srcfile=$(srcdir)/gov/llnl/babel/revision.txt \
	    --outfile=$(builddir)/gov/llnl/babel/revision.txt \
	   || test ! -f $(JARFILE); then				\
	  $(MAKE) $(AM_MAKEFLAGS) force-jarfile;			\
	else								\
	  newfiles=`find $(srcdir)/gov -name SCCS -prune -o             \
	    -name CVS -prune -o						\
	    -name .svn -prune -o					\
	    -name "*Test.java" -o					\
	    \( -name "*.java" -o -name "*.dtd" -o -name "*.xsl" -o      \
	       -name "*.css" -o -name "*.[ch]" -o -name "*.make" \)     \
	    -newer $(JARFILE) -print`;			                \
	  if test "x$$newfiles" != "x"; then                         	\
	    $(MAKE) $(AM_MAKEFLAGS) force-jarfile;			\
	  fi								\
	fi

JAVAC_FLAGS = -g -source 1.4 -target 1.4 -d . -classpath "$(CLASSPATH)"

force-jarfile:
	@javafiles=`find $(srcdir)/gov -name SCCS -prune -o 		\
	   -name CVS -prune -o						\
	   -name .svn -prune -o						\
	    -name "*Test.java" -o					\
	   -name "*.java" -print`;					\
	if test "x$$javafiles" != "x"; then				\
	  echo '$(JAVAC) $(JAVACFLAGS) $(JAVAC_FLAGS)' $$javafiles;	\
	  $(JAVAC) $(JAVACFLAGS) $(JAVAC_FLAGS) $$javafiles; 		\
	  compilestat=$$?;						\
	else								\
	  compilestat=0;						\
	fi;								\
	if test $$compilestat == 0; then				\
	  if test "X$(srcdir)" != "X."; then				\
	    dtdfiles=`cd $(srcdir) ; 					\
		find gov -name .svn -prune -o -name '*.dtd' -print`;	\
	    xslfiles=`cd $(srcdir) ; \
		find gov -name .svn -prune -o \( -name '*.xsl' -o -name "*.css" \) -print`;	\
	    cfiles=`cd $(srcdir) ; find gov -name .svn -prune -o \( -name '*.[ch]' \) -print`;	\
	    makefiles=`cd $(srcdir) ; find gov -name .svn -prune -o \( -name '*.make' \) -print`;	\
	    for f in $$dtdfiles $$cfiles $$makefiles $$xslfiles; do			\
	      echo mkdir -p `dirname $$f`;				\
	      mkdir -p `dirname $$f`;					\
	      echo cp -f $(srcdir)/$$f $$f;				\
	      cp -f $(srcdir)/$$f $$f;					\
	    done;							\
	  fi;								\
	  files=`find gov -name .svn -prune -o \( -name '*.class' -o -name "*.dtd" -o -name "*.[ch]" -o -name "*.xsl" -o -name "*.css" -o -name "*.txt" -o -name "*.make" \) -print`; \
	  echo chmod -f +w $(JARFILE) ;					\
	  chmod -f +w $(JARFILE) ;					\
	  echo  $(JAR) cf $(JARFILE) $$files;				\
	  $(JAR) cf $(JARFILE) $$files;					\
	else								\
	  exit 1;							\
	fi

#
# Make the parser.  This can only be done in the source directory, since it
# will over-write the java files.
#

SIDLDIR=$(srcdir)/gov/llnl/babel/parsers/sidl
parser:
	@echo Compiling sidl.jj;			\
	cd $(SIDLDIR); 					\
	../../../../../../bin/javacc sidl.jj ;		\
	perl -p -i -e 's/Enumeration enum/Enumeration e/;' \
			-e 's/enum\./e\./g;' \
			-e 's/ASCII\_CharStream/SimpleCharStream/g;' Parser.java

#
# Make clean and copy distribution files to the distribution directory
#

clean-local:
	@if test -d gov; then				  \
	    find gov -name '*.class' -exec rm -f {} \; ;\
	    if test "X$(srcdir)" != "X."; then \
	      find gov \( -name '*.dtd' -o -name '*.txt' -o -name "*.[ch]" -o -name "*.xsl" -o -name "*.css" -o -name "*.make" \) -exec rm -f {} \; ;\
	    fi \
	fi

dist-hook: jarfile babel-stamp babel-check-stamp
	dirs=`cd $(srcdir); find gov -type d \( -name CVS -prune -o     \
              -name SCCS -prune -o -name .svn -prune -o -print \)`;	\
	for d in $$dirs; do						\
	  mkdir -p $(distdir)/$$d;					\
	done
	cp -f $(builddir)/gov/llnl/babel/revision.txt \
	   $(distdir)/gov/llnl/babel/revision.txt
	files=`cd $(srcdir); find gov \( -name CVS -prune \) -o 	\
	   \( -name SCCS -prune \) -o \( -name .svn -prune \) -o		\
	   \( -name "*.java" -o 					\
	    -name "*.dtd" -o -name "*.dtd.in" -o -name "sidl.jj" 	\
	    -o -name "*.xsl" -o -name "*.css" -o -name "*.make"		\
	    -o -name "*.c" -o   -name "*.h" \) -print`;			\
	for f in $$files; do						\
	  echo cp $(srcdir)/$$f $(distdir)/$$f;				\
	  cp $(srcdir)/$$f $(distdir)/$$f;				\
	done

if WITH_SIDLX
SIDLX_GEN=--vpath ${abs_top_srcdir}/runtime/sidlx \
	  -o ${top_builddir}/runtime/sidlx --touch babel-stamp \
	  ${top_srcdir}/runtime/sidl/sidl.sidl \
	  ${top_srcdir}/runtime/sidlx/sidlx.sidl --server=c
CLIENT_SYMS=sidl sidlx
else
SIDLX_GEN= ${top_srcdir}/runtime/sidl/sidl.sidl ${top_srcdir}/runtime/sidlx/sidlx.sidl
CLIENT_SYMS=sidl
endif


babel-stamp : $(JARFILE)
	if test -d ${top_builddir}/share/repository ; then \
	  $(RM) ${top_builddir}/share/repository/*.xml ; \
	else \
	  mkdir -p ${top_builddir}/share/repository ; \
	fi
	../bin/babel --multi \
	  --no-default-repository --include-referenced --generate-sidl-stdlib \
	  -o ${top_builddir}/runtime/sidl --touch babel-stamp \
	  --vpath ${abs_top_srcdir}/runtime/sidl \
	  ${top_srcdir}/runtime/sidl/sidl.sidl --server=c --reset \
	  --no-default-repository $(SIDLX_GEN) \
	  -o ${top_builddir}/runtime/python --touch babel-src-stamp \
	  --generate-sidl-stdlib --client=python \
	  -o ${top_builddir}/share --touch babel-stamp \
	  -o ${top_builddir}/share/repository --text=xml --reset \
	  --include-referenced sidl \
	  -o ${top_builddir}/lib/sidlstubs/Cxx --touch babel-stamp --client=cxx \
	  -o ${top_builddir}/lib/sidlstubs/F77 --touch babel-stamp --client=f77 \
	  -o ${top_builddir}/lib/sidlstubs/F90 --touch babel-stamp --client=f90 \
	  -o ${top_builddir}/lib/sidlstubs/F03 --touch babel-stamp --client=f03 \
	  -o ${top_builddir}/lib/sidlstubs/Java --touch babel-stamp --client=java  --reset \
	  sidlx --make-prefix=sidlx_ \
	  -o ${top_builddir}/lib/sidlstubs/Cxx --touch sidlx-stamp --client=cxx \
	  -o ${top_builddir}/lib/sidlstubs/F77 --touch sidlx-stamp --client=f77 \
	  -o ${top_builddir}/lib/sidlstubs/F90 --touch sidlx-stamp --client=f90 \
	  -o ${top_builddir}/lib/sidlstubs/F03 --touch sidlx-stamp --client=f03 \
	  -o ${top_builddir}/lib/sidlstubs/Java --touch sidlx-stamp --client=java
	touch babel-stamp

babel-check-stamp: $(JARFILE) babel-stamp
	../bin/babel --multi \
	  ${top_srcdir}/regression/output/output.sidl \
	  -o ${top_builddir}/regression/output/libC -T babel-stamp \
	  --vpath ${abs_top_srcdir}/regression/output/libC \
	   --server=c --make-prefix synch_  \
	  -o ${top_builddir}/regression/args/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/args/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/args/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/args/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/args/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/args/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/args/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/arrays/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/arrays/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/arrays/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/arrays/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/arrays/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/arrays/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/arrays/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/enums/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/enums/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/enums/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/enums/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/enums/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/enums/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/exceptions/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/exceptions/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/exceptions/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/exceptions/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/exceptions/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/exceptions/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/exceptions/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/hooks/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/hooks/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/hooks/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/hooks/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/hooks/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/hooks/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/inherit/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/inherit/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/inherit/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/inherit/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/inherit/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/inherit/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/inherit/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/objarg/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/objarg/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/objarg/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/objarg/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/objarg/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/objarg/runC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/ordering/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/ordering/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/ordering/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/ordering/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/ordering/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/ordering/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/ordering/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/overload/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/overload/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/overload/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/overload/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/overload/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/overload/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/overload/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/sort/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/sort/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/sort/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/sort/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/sort/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/sort/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/sort/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/strings/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/strings/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/strings/libF77 -T synch-stamp -c f77 \
	  -o ${top_builddir}/regression/strings/libF90 -T synch-stamp -c f90 \
	  -o ${top_builddir}/regression/strings/libPython -T synch-stamp -c python \
	  -o ${top_builddir}/regression/strings/libJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/strings/runJava -T synch-stamp -c java \
	  -o ${top_builddir}/regression/struct/libC -T synch-stamp -c c \
	  -o ${top_builddir}/regression/struct/libCxx -T synch-stamp -c cxx \
	  -o ${top_builddir}/regression/struct/libPython -T synch-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/args/args.sidl \
	  --vpath ${abs_top_srcdir}/regression/args/libC \
	  -o ${top_builddir}/regression/args/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/args/libCxx \
	  -o ${top_builddir}/regression/args/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/args/libF77 \
	  -o ${top_builddir}/regression/args/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/args/libF90 \
	  -o ${top_builddir}/regression/args/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/args/libJava \
	  -o ${top_builddir}/regression/args/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/args/libPython \
	  -o ${top_builddir}/regression/args/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/args/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/args/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/args/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/args/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/args/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/args/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/arrays/ArrayTest.sidl \
	  --vpath ${abs_top_srcdir}/regression/arrays/libC \
	  -o ${top_builddir}/regression/arrays/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/arrays/libCxx \
	  -o ${top_builddir}/regression/arrays/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/arrays/libF77 \
	  -o ${top_builddir}/regression/arrays/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/arrays/libF90 \
	  -o ${top_builddir}/regression/arrays/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/arrays/libJava \
	  -o ${top_builddir}/regression/arrays/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/arrays/libPython \
	  -o ${top_builddir}/regression/arrays/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/arrays/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/arrays/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/arrays/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/arrays/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/arrays/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/arrays/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/contracts/vector.sidl \
	  --vpath ${abs_top_srcdir}/regression/contracts/libC \
	  -o ${top_builddir}/regression/contracts/libC \
	  -T babel-stamp -s c \
	  -o ${top_builddir}/regression/contracts/runC -T babel-stamp -c c
	../bin/babel --multi \
	  ${top_srcdir}/regression/enums/enums.sidl \
	  --vpath ${abs_top_srcdir}/regression/enums/libC \
	  -o ${top_builddir}/regression/enums/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/enums/libCxx \
	  -o ${top_builddir}/regression/enums/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/enums/libF77 \
	  -o ${top_builddir}/regression/enums/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/enums/libF90 \
	  -o ${top_builddir}/regression/enums/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/enums/libJava \
	  -o ${top_builddir}/regression/enums/libJava \
	  -T babel-stamp -s java \
	  -o ${top_builddir}/regression/enums/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/enums/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/enums/runJava -T babel-stamp -c java
	../bin/babel --multi \
	  ${top_srcdir}/regression/exceptions/ExceptionTest.sidl \
	  --vpath ${abs_top_srcdir}/regression/exceptions/libC \
	  -o ${top_builddir}/regression/exceptions/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/exceptions/libCxx \
	  -o ${top_builddir}/regression/exceptions/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/exceptions/libF77 \
	  -o ${top_builddir}/regression/exceptions/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/exceptions/libF90 \
	  -o ${top_builddir}/regression/exceptions/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/exceptions/libJava \
	  -o ${top_builddir}/regression/exceptions/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/exceptions/libPython \
	  -o ${top_builddir}/regression/exceptions/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/exceptions/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/exceptions/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/exceptions/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/exceptions/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/exceptions/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/exceptions/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/inherit/inherit.sidl \
	  --vpath ${abs_top_srcdir}/regression/inherit/libC \
	  -o ${top_builddir}/regression/inherit/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/inherit/libCxx \
	  -o ${top_builddir}/regression/inherit/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/inherit/libF77 \
	  -o ${top_builddir}/regression/inherit/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/inherit/libF90 \
	  -o ${top_builddir}/regression/inherit/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/inherit/libJava \
	  -o ${top_builddir}/regression/inherit/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/inherit/libPython \
	  -o ${top_builddir}/regression/inherit/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/inherit/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/inherit/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/inherit/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/inherit/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/inherit/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/inherit/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/objarg/objarg.sidl \
	  --vpath ${abs_top_srcdir}/regression/objarg/libC \
	  -o ${top_builddir}/regression/objarg/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/objarg/libCxx \
	  -o ${top_builddir}/regression/objarg/libCxx \
	  -T babel-stamp -s cxx \
	 --vpath ${abs_top_srcdir}/regression/objarg/libF90 \
	  -o ${top_builddir}/regression/objarg/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/objarg/libJava \
	  -o ${top_builddir}/regression/objarg/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/objarg/libPython \
	  -o ${top_builddir}/regression/objarg/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/objarg/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/objarg/runPython -T babel-stamp -c python \
	  ${top_srcdir}/regression/output/output.sidl \
	  -o ${top_builddir}/regression/objarg/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/objarg/runJava -T babel-stamp -c java
	../bin/babel --multi \
	  ${top_srcdir}/regression/ordering/ordering.sidl \
	  --vpath ${abs_top_srcdir}/regression/ordering/libC \
	  -o ${top_builddir}/regression/ordering/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/ordering/libCxx \
	  -o ${top_builddir}/regression/ordering/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/ordering/libF77 \
	  -o ${top_builddir}/regression/ordering/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/ordering/libF90 \
	  -o ${top_builddir}/regression/ordering/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/ordering/libJava \
	  -o ${top_builddir}/regression/ordering/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/ordering/libPython \
	  -o ${top_builddir}/regression/ordering/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/ordering/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/ordering/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/ordering/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/ordering/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/overload/Overload.sidl \
	  --vpath ${abs_top_srcdir}/regression/overload/libC \
	  -o ${top_builddir}/regression/overload/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/overload/libCxx \
	  -o ${top_builddir}/regression/overload/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/overload/libF77 \
	  -o ${top_builddir}/regression/overload/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/overload/libF90 \
	  -o ${top_builddir}/regression/overload/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/overload/libJava \
	  -o ${top_builddir}/regression/overload/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/overload/libPython \
	  -o ${top_builddir}/regression/overload/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/overload/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/overload/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/overload/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/overload/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/overload/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/overload/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/sort/sort.sidl \
	  --vpath ${abs_top_srcdir}/regression/sort/libC \
	  -o ${top_builddir}/regression/sort/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/sort/libCxx \
	  -o ${top_builddir}/regression/sort/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/sort/libF77 \
	  -o ${top_builddir}/regression/sort/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/sort/libF90 \
	  -o ${top_builddir}/regression/sort/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/sort/libJava \
	  -o ${top_builddir}/regression/sort/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/sort/libPython \
	  -o ${top_builddir}/regression/sort/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/sort/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/sort/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/sort/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/sort/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/sort/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/sort/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/strings/strings.sidl \
	  --vpath ${abs_top_srcdir}/regression/strings/libC \
	  -o ${top_builddir}/regression/strings/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/strings/libCxx \
	  -o ${top_builddir}/regression/strings/libCxx \
	  -T babel-stamp -s cxx \
	  --vpath ${abs_top_srcdir}/regression/strings/libF77 \
	  -o ${top_builddir}/regression/strings/libF77 \
	  -T babel-stamp -s f77 \
	 --vpath ${abs_top_srcdir}/regression/strings/libF90 \
	  -o ${top_builddir}/regression/strings/libF90 \
	  -T babel-stamp -s f90 \
	 --vpath ${abs_top_srcdir}/regression/strings/libJava \
	  -o ${top_builddir}/regression/strings/libJava \
	  -T babel-stamp -s java \
	 --vpath ${abs_top_srcdir}/regression/strings/libPython \
	  -o ${top_builddir}/regression/strings/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/strings/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/strings/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/strings/runF77 -T babel-stamp -c f77 \
	  -o ${top_builddir}/regression/strings/runF90 -T babel-stamp -c f90 \
	  -o ${top_builddir}/regression/strings/runJava -T babel-stamp -c java \
	  -o ${top_builddir}/regression/strings/runPython -T babel-stamp -c python
	../bin/babel --multi \
	  ${top_srcdir}/regression/struct/struct.sidl \
	  --vpath ${abs_top_srcdir}/regression/struct/libC \
	  -o ${top_builddir}/regression/struct/libC \
	  -T babel-stamp -s c \
	  --vpath ${abs_top_srcdir}/regression/struct/libCxx \
	  -o ${top_builddir}/regression/struct/libCxx \
	  -T babel-stamp -s cxx \
	 --vpath ${abs_top_srcdir}/regression/struct/libPython \
	  -o ${top_builddir}/regression/struct/libPython \
	  -T babel-stamp -s python \
	  -o ${top_builddir}/regression/struct/runC -T babel-stamp -c c \
	  -o ${top_builddir}/regression/struct/runCxx -T babel-stamp -c cxx \
	  -o ${top_builddir}/regression/struct/runPython -T babel-stamp -c python
	touch babel-check-stamp
