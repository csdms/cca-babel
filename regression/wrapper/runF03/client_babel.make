client_IORHDRS = synch_IOR.h synch_RegOut_IOR.h synch_ResultType_IOR.h        \
  wrapper_User_IOR.h
client_STUBHDRS = synch_RegOut_array_bindcdecls.h synch_RegOut_fAbbrev.h      \
  synch_RegOut_fStub.h synch_RegOut_mod_bindcdecls.h                          \
  synch_ResultType_array_bindcdecls.h synch_ResultType_fAbbrev.h              \
  wrapper_User_array_bindcdecls.h wrapper_User_fAbbrev.h wrapper_User_fStub.h \
  wrapper_User_mod_bindcdecls.h
client_STUBMODULESRCS = synch_RegOut.F03 wrapper_User.F03
client_STUBSRCS = synch_RegOut_fStub.c wrapper_User_fStub.c
client_TYPEMODULESRCS = synch_RegOut_type.F03 synch_ResultType_type.F03       \
  wrapper_User_type.F03

