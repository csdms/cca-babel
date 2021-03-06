AC_INIT(parsifal, 1.0.0)
AC_CONFIG_AUX_DIR(conf)
AC_CONFIG_SRCDIR(src/parsifal.c)

## to avoid default install dir /usr/local and
## LD_LIBRARY_PATH etc hassle:

RELEASE=$PACKAGE_VERSION
AM_INIT_AUTOMAKE(libparsifal, $RELEASE)
AC_SUBST([RELEASE])

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_LIBTOOL

AC_LANG_C
AM_SANITY_CHECK

AC_DEFUN([ACX_CHECK_CC_FLAGS],
[AC_REQUIRE([AC_PROG_CC])dnl
AC_CACHE_CHECK(whether ${CC-cc} accepts $1, acx_cv_$2,
[echo 'int i=0;' > conftest.$ac_ext
if test -z "`${CC-cc} $1 -c conftest.$ac_ext 2>&1`"; then
	acx_cv_$2=yes
else
	acx_cv_$2=no
fi
rm -f conftest.$ac_ext
])
if test "$acx_cv_$2" = yes; then
	:
	$3
else
	:
	$4
fi
])

if test $ac_cv_prog_gcc = yes; then
  CFLAGS="-Wall -O3 $CFLAGS"
  ACX_CHECK_CC_FLAGS(-Wno-pointer-sign, wnoptrsign, CFLAGS="$CFLAGS -Wno-pointer-sign") 
fi

AC_ARG_ENABLE(iconv, AC_HELP_STRING([--disable-iconv],[(default enabled).]),,$enable_iconv="yes")
if test "$enable_iconv" = "yes"; then
  enable_iconv="no"
  incl='#include <stdlib.h>
#include "iconv.h"'
  body='iconv_t cd=iconv_open("","");
iconv(cd,NULL,NULL,NULL,NULL);'

  AC_CHECK_HEADER(iconv.h,
    AC_TRY_LINK([$incl],[$body],[enable_iconv="yes"],
      AC_MSG_CHECKING(-liconv)       
      save_LIBS=$LIBS
      LIBS="$LIBS -liconv"
      AC_TRY_LINK([$incl],[$body],[enable_iconv="yes"],
        LIBS=$save_LIBS
      )
    )
  )
  if test "$enable_iconv" = "yes"; then
    CPPFLAGS="$CPPFLAGS -DICONV_SUPPORT"
  fi
fi

AC_OUTPUT( Makefile \
	conf/Makefile \
	src/Makefile \
	include/Makefile \
	include/libparsifal/Makefile \
)

echo
echo "==============================="
echo "libparsifal $RELEASE"
echo "install prefix: $prefix"
echo "iconv support: $enable_iconv"
echo "==============================="


