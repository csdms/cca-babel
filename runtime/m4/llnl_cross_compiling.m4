dnl @synopsis LLNL_CROSS_COMPILING
dnl 
dnl configure for BGL-type machines that need hard wired settings
dnl because the compute nodes running different OSes that the head
dnl node.
dnl
dnl @version
dnl @author Tom Epperly, LLNL
AC_DEFUN([LLNL_CROSS_COMPILING],
[
  case "$target" in
  powerpc64-ibm-bgl*)
    cross_compiling=yes
    llnl_cross_compiling_okay=yes
    enable_pure_static_runtime=yes
    enable_shared=no
    enable_static=yes
    enable_java=no
    enable_python=no
    sidl_cv_f77_false=0
    sidl_cv_f77_true=1
    sidl_cv_f90_false=0
    sidl_cv_f90_true=1
    llnl_cv_F77_string_passing="far int32_t"
    llnl_cv_F90_string_passing="far int32_t"
    ac_cv_func_malloc_0_nonnull=yes
    ac_cv_func_realloc_0_nonnull=yes
    ac_cv_func_memcmp_working=yes
    with_sidlx=no
    ;;
  x86_64-cray-catamount*)
    cross_compiling=yes
    llnl_cross_compiling_okay=yes
    enable_pure_static_runtime=yes
    enable_shared=no
    enable_static=yes
    enable_java=no
    enable_python=no
    enable_pthreads=no
    sidl_cv_f77_false=0
    sidl_cv_f77_true=-1
    llnl_cv_F77_logical_size=4
    sidl_cv_f90_false=0
    sidl_cv_f90_true=-1
    llnl_cv_F90_logical_size=4
    chasm_max_descriptor_size=568
    llnl_cv_F77_string_passing="far int32_t"
    llnl_cv_F90_string_passing="far int32_t"
    ac_cv_f90_pointer_size=8
    ac_cv_header_netinet_in_h=no
    ac_cv_func_malloc_0_nonnull=yes
    ac_cv_func_realloc_0_nonnull=yes
    ac_cv_func_memcmp_working=yes
    with_sidlx=no
    ;;  
  x86_64-cray-cnl*)
    cross_compiling=yes
    llnl_cross_compiling_okay=yes
    enable_pure_static_runtime=yes
    enable_shared=no
    enable_static=yes
    enable_java=no
    enable_python=no
    llnl_cv_F77_logical_size=4
    llnl_cv_F90_logical_size=4
    llnl_cv_F77_string_passing="far int32_t"
    llnl_cv_F90_string_passing="far int32_t"
    ac_cv_func_malloc_0_nonnull=yes
    ac_cv_func_realloc_0_nonnull=yes
    ac_cv_func_memcmp_working=yes
    ac_cv_f90_pointer_size=8
    with_sidlx=no
    ;;  
  esac
])
