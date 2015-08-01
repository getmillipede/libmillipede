AC_INIT([libmillipede], [0.1], [hello@millipede.io])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])
AM_PROG_AR
LT_INIT
AC_PROG_CC

PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

AC_TYPE_SIZE_T

AC_FUNC_MALLOC

AC_CHECK_FUNCS([strdup calloc sprintf free])

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile src/Makefile libmillipede.pc])

AC_OUTPUT
