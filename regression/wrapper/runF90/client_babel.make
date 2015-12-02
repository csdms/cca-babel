client_IORHDRS = synch_IOR.h synch_RegOut_IOR.h synch_ResultType_IOR.h        \
  wrapper_User_IOR.h
client_STUBHDRS = synch_RegOut_fAbbrev.h synch_RegOut_fStub.h                 \
  synch_ResultType_fAbbrev.h wrapper_User_fAbbrev.h wrapper_User_fStub.h
client_STUBMODULESRCS = synch_RegOut.F90 synch_ResultType.F90 wrapper_User.F90
client_STUBSRCS = synch_RegOut_fStub.c synch_ResultType_fStub.c               \
  wrapper_User_fStub.c
client_TYPEMODULESRCS = synch_RegOut_type.F90 synch_ResultType_type.F90       \
  wrapper_User_type.F90
