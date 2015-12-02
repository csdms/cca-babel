ARRAYMODULESRCS = sidl_array_array.F90 sidl_bool_array.F90                    \
  sidl_char_array.F90 sidl_dcomplex_array.F90 sidl_double_array.F90           \
  sidl_fcomplex_array.F90 sidl_float_array.F90 sidl_int_array.F90             \
  sidl_long_array.F90 sidl_opaque_array.F90 sidl_string_array.F90
BASICMODULESRC = sidl.F90
STUBHDRS = sidl_BaseClass_fAbbrev.h sidl_BaseClass_fStub.h                    \
  sidl_BaseException_fAbbrev.h sidl_BaseException_fStub.h                     \
  sidl_BaseInterface_fAbbrev.h sidl_BaseInterface_fStub.h                     \
  sidl_CastException_fAbbrev.h sidl_CastException_fStub.h                     \
  sidl_ClassInfoI_fAbbrev.h sidl_ClassInfoI_fStub.h sidl_ClassInfo_fAbbrev.h  \
  sidl_ClassInfo_fStub.h sidl_ClauseType_fAbbrev.h                            \
  sidl_ContractClass_fAbbrev.h sidl_DFinder_fAbbrev.h sidl_DFinder_fStub.h    \
  sidl_DLL_fAbbrev.h sidl_DLL_fStub.h sidl_EnfPolicy_fAbbrev.h                \
  sidl_EnfPolicy_fStub.h sidl_EnfTraceLevel_fAbbrev.h                         \
  sidl_EnforceFreq_fAbbrev.h sidl_Finder_fAbbrev.h sidl_Finder_fStub.h        \
  sidl_InvViolation_fAbbrev.h sidl_InvViolation_fStub.h                       \
  sidl_LangSpecificException_fAbbrev.h sidl_LangSpecificException_fStub.h     \
  sidl_Loader_fAbbrev.h sidl_Loader_fStub.h sidl_MemAllocException_fAbbrev.h  \
  sidl_MemAllocException_fStub.h sidl_NotImplementedException_fAbbrev.h       \
  sidl_NotImplementedException_fStub.h sidl_PostViolation_fAbbrev.h           \
  sidl_PostViolation_fStub.h sidl_PreViolation_fAbbrev.h                      \
  sidl_PreViolation_fStub.h sidl_Resolve_fAbbrev.h                            \
  sidl_RuntimeException_fAbbrev.h sidl_RuntimeException_fStub.h               \
  sidl_SIDLException_fAbbrev.h sidl_SIDLException_fStub.h                     \
  sidl_Scope_fAbbrev.h sidl_array_fAbbrev.h sidl_bool_fAbbrev.h               \
  sidl_char_fAbbrev.h sidl_dcomplex_fAbbrev.h sidl_double_fAbbrev.h           \
  sidl_fcomplex_fAbbrev.h sidl_float_fAbbrev.h sidl_int_fAbbrev.h             \
  sidl_io_Deserializer_fAbbrev.h sidl_io_Deserializer_fStub.h                 \
  sidl_io_IOException_fAbbrev.h sidl_io_IOException_fStub.h                   \
  sidl_io_Serializable_fAbbrev.h sidl_io_Serializable_fStub.h                 \
  sidl_io_Serializer_fAbbrev.h sidl_io_Serializer_fStub.h sidl_long_fAbbrev.h \
  sidl_opaque_fAbbrev.h sidl_rmi_BindException_fAbbrev.h                      \
  sidl_rmi_BindException_fStub.h sidl_rmi_Call_fAbbrev.h                      \
  sidl_rmi_Call_fStub.h sidl_rmi_ConnectException_fAbbrev.h                   \
  sidl_rmi_ConnectException_fStub.h sidl_rmi_ConnectRegistry_fAbbrev.h        \
  sidl_rmi_ConnectRegistry_fStub.h sidl_rmi_InstanceHandle_fAbbrev.h          \
  sidl_rmi_InstanceHandle_fStub.h sidl_rmi_InstanceRegistry_fAbbrev.h         \
  sidl_rmi_InstanceRegistry_fStub.h sidl_rmi_Invocation_fAbbrev.h             \
  sidl_rmi_Invocation_fStub.h sidl_rmi_MalformedURLException_fAbbrev.h        \
  sidl_rmi_MalformedURLException_fStub.h sidl_rmi_NetworkException_fAbbrev.h  \
  sidl_rmi_NetworkException_fStub.h sidl_rmi_NoRouteToHostException_fAbbrev.h \
  sidl_rmi_NoRouteToHostException_fStub.h                                     \
  sidl_rmi_NoServerException_fAbbrev.h sidl_rmi_NoServerException_fStub.h     \
  sidl_rmi_ObjectDoesNotExistException_fAbbrev.h                              \
  sidl_rmi_ObjectDoesNotExistException_fStub.h                                \
  sidl_rmi_ProtocolException_fAbbrev.h sidl_rmi_ProtocolException_fStub.h     \
  sidl_rmi_ProtocolFactory_fAbbrev.h sidl_rmi_ProtocolFactory_fStub.h         \
  sidl_rmi_Response_fAbbrev.h sidl_rmi_Response_fStub.h                       \
  sidl_rmi_Return_fAbbrev.h sidl_rmi_Return_fStub.h                           \
  sidl_rmi_ServerInfo_fAbbrev.h sidl_rmi_ServerInfo_fStub.h                   \
  sidl_rmi_ServerRegistry_fAbbrev.h sidl_rmi_ServerRegistry_fStub.h           \
  sidl_rmi_TicketBook_fAbbrev.h sidl_rmi_TicketBook_fStub.h                   \
  sidl_rmi_Ticket_fAbbrev.h sidl_rmi_Ticket_fStub.h                           \
  sidl_rmi_TimeOutException_fAbbrev.h sidl_rmi_TimeOutException_fStub.h       \
  sidl_rmi_UnexpectedCloseException_fAbbrev.h                                 \
  sidl_rmi_UnexpectedCloseException_fStub.h                                   \
  sidl_rmi_UnknownHostException_fAbbrev.h                                     \
  sidl_rmi_UnknownHostException_fStub.h sidl_string_fAbbrev.h
STUBMODULESRCS = sidl_BaseClass.F90 sidl_BaseException.F90                    \
  sidl_BaseInterface.F90 sidl_CastException.F90 sidl_ClassInfo.F90            \
  sidl_ClassInfoI.F90 sidl_ClauseType.F90 sidl_ContractClass.F90              \
  sidl_DFinder.F90 sidl_DLL.F90 sidl_EnfPolicy.F90 sidl_EnfTraceLevel.F90     \
  sidl_EnforceFreq.F90 sidl_Finder.F90 sidl_InvViolation.F90                  \
  sidl_LangSpecificException.F90 sidl_Loader.F90 sidl_MemAllocException.F90   \
  sidl_NotImplementedException.F90 sidl_PostViolation.F90                     \
  sidl_PreViolation.F90 sidl_Resolve.F90 sidl_RuntimeException.F90            \
  sidl_SIDLException.F90 sidl_Scope.F90 sidl_io_Deserializer.F90              \
  sidl_io_IOException.F90 sidl_io_Serializable.F90 sidl_io_Serializer.F90     \
  sidl_rmi_BindException.F90 sidl_rmi_Call.F90 sidl_rmi_ConnectException.F90  \
  sidl_rmi_ConnectRegistry.F90 sidl_rmi_InstanceHandle.F90                    \
  sidl_rmi_InstanceRegistry.F90 sidl_rmi_Invocation.F90                       \
  sidl_rmi_MalformedURLException.F90 sidl_rmi_NetworkException.F90            \
  sidl_rmi_NoRouteToHostException.F90 sidl_rmi_NoServerException.F90          \
  sidl_rmi_ObjectDoesNotExistException.F90 sidl_rmi_ProtocolException.F90     \
  sidl_rmi_ProtocolFactory.F90 sidl_rmi_Response.F90 sidl_rmi_Return.F90      \
  sidl_rmi_ServerInfo.F90 sidl_rmi_ServerRegistry.F90 sidl_rmi_Ticket.F90     \
  sidl_rmi_TicketBook.F90 sidl_rmi_TimeOutException.F90                       \
  sidl_rmi_UnexpectedCloseException.F90 sidl_rmi_UnknownHostException.F90
STUBSRCS = sidl_BaseClass_fStub.c sidl_BaseException_fStub.c                  \
  sidl_BaseInterface_fStub.c sidl_CastException_fStub.c                       \
  sidl_ClassInfoI_fStub.c sidl_ClassInfo_fStub.c sidl_ClauseType_fStub.c      \
  sidl_ContractClass_fStub.c sidl_DFinder_fStub.c sidl_DLL_fStub.c            \
  sidl_EnfPolicy_fStub.c sidl_EnfTraceLevel_fStub.c sidl_EnforceFreq_fStub.c  \
  sidl_Finder_fStub.c sidl_InvViolation_fStub.c                               \
  sidl_LangSpecificException_fStub.c sidl_Loader_fStub.c                      \
  sidl_MemAllocException_fStub.c sidl_NotImplementedException_fStub.c         \
  sidl_PostViolation_fStub.c sidl_PreViolation_fStub.c sidl_Resolve_fStub.c   \
  sidl_RuntimeException_fStub.c sidl_SIDLException_fStub.c sidl_Scope_fStub.c \
  sidl_array_fStub.c sidl_bool_fStub.c sidl_char_fStub.c                      \
  sidl_dcomplex_fStub.c sidl_double_fStub.c sidl_fcomplex_fStub.c             \
  sidl_float_fStub.c sidl_int_fStub.c sidl_io_Deserializer_fStub.c            \
  sidl_io_IOException_fStub.c sidl_io_Serializable_fStub.c                    \
  sidl_io_Serializer_fStub.c sidl_long_fStub.c sidl_opaque_fStub.c            \
  sidl_rmi_BindException_fStub.c sidl_rmi_Call_fStub.c                        \
  sidl_rmi_ConnectException_fStub.c sidl_rmi_ConnectRegistry_fStub.c          \
  sidl_rmi_InstanceHandle_fStub.c sidl_rmi_InstanceRegistry_fStub.c           \
  sidl_rmi_Invocation_fStub.c sidl_rmi_MalformedURLException_fStub.c          \
  sidl_rmi_NetworkException_fStub.c sidl_rmi_NoRouteToHostException_fStub.c   \
  sidl_rmi_NoServerException_fStub.c                                          \
  sidl_rmi_ObjectDoesNotExistException_fStub.c                                \
  sidl_rmi_ProtocolException_fStub.c sidl_rmi_ProtocolFactory_fStub.c         \
  sidl_rmi_Response_fStub.c sidl_rmi_Return_fStub.c                           \
  sidl_rmi_ServerInfo_fStub.c sidl_rmi_ServerRegistry_fStub.c                 \
  sidl_rmi_TicketBook_fStub.c sidl_rmi_Ticket_fStub.c                         \
  sidl_rmi_TimeOutException_fStub.c sidl_rmi_UnexpectedCloseException_fStub.c \
  sidl_rmi_UnknownHostException_fStub.c sidl_string_fStub.c
TYPEMODULESRCS = sidl_BaseClass_type.F90 sidl_BaseException_type.F90          \
  sidl_BaseInterface_type.F90 sidl_CastException_type.F90                     \
  sidl_ClassInfoI_type.F90 sidl_ClassInfo_type.F90 sidl_ClauseType_type.F90   \
  sidl_ContractClass_type.F90 sidl_DFinder_type.F90 sidl_DLL_type.F90         \
  sidl_EnfPolicy_type.F90 sidl_EnfTraceLevel_type.F90                         \
  sidl_EnforceFreq_type.F90 sidl_Finder_type.F90 sidl_InvViolation_type.F90   \
  sidl_LangSpecificException_type.F90 sidl_Loader_type.F90                    \
  sidl_MemAllocException_type.F90 sidl_NotImplementedException_type.F90       \
  sidl_PostViolation_type.F90 sidl_PreViolation_type.F90                      \
  sidl_Resolve_type.F90 sidl_RuntimeException_type.F90                        \
  sidl_SIDLException_type.F90 sidl_Scope_type.F90 sidl_array_type.F90         \
  sidl_io_Deserializer_type.F90 sidl_io_IOException_type.F90                  \
  sidl_io_Serializable_type.F90 sidl_io_Serializer_type.F90                   \
  sidl_rmi_BindException_type.F90 sidl_rmi_Call_type.F90                      \
  sidl_rmi_ConnectException_type.F90 sidl_rmi_ConnectRegistry_type.F90        \
  sidl_rmi_InstanceHandle_type.F90 sidl_rmi_InstanceRegistry_type.F90         \
  sidl_rmi_Invocation_type.F90 sidl_rmi_MalformedURLException_type.F90        \
  sidl_rmi_NetworkException_type.F90 sidl_rmi_NoRouteToHostException_type.F90 \
  sidl_rmi_NoServerException_type.F90                                         \
  sidl_rmi_ObjectDoesNotExistException_type.F90                               \
  sidl_rmi_ProtocolException_type.F90 sidl_rmi_ProtocolFactory_type.F90       \
  sidl_rmi_Response_type.F90 sidl_rmi_Return_type.F90                         \
  sidl_rmi_ServerInfo_type.F90 sidl_rmi_ServerRegistry_type.F90               \
  sidl_rmi_TicketBook_type.F90 sidl_rmi_Ticket_type.F90                       \
  sidl_rmi_TimeOutException_type.F90                                          \
  sidl_rmi_UnexpectedCloseException_type.F90                                  \
  sidl_rmi_UnknownHostException_type.F90
