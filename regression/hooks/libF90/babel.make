IMPLMODULESRCS = hooks_Basics_Mod.F90
IMPLSRCS = hooks_Basics_Impl.F90
IORHDRS = hooks_Basics_IOR.h hooks_IOR.h
IORSRCS = hooks_Basics_IOR.c
SKELSRCS = hooks_Basics_fSkel.c
STUBHDRS = hooks_Basics_array_bindcdecls.h hooks_Basics_fAbbrev.h             \
  hooks_Basics_fStub.h hooks_Basics_mod_bindcdecls.h
STUBMODULESRCS = hooks_Basics.F90
STUBSRCS = hooks_Basics_fStub.c
TYPEMODULESRCS = hooks_Basics_type.F90

_deps_hooks_Basics_Impl =  hooks_Basics
hooks_Basics_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_hooks_Basics_Impl))

