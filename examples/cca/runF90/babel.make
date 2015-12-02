IORHDRS = decaf_Framework_IOR.h gov_cca_AbstractFramework_IOR.h               \
  gov_cca_CCAExceptionType_IOR.h gov_cca_CCAException_IOR.h                   \
  gov_cca_ComponentClassDescription_IOR.h gov_cca_ComponentID_IOR.h           \
  gov_cca_ComponentRelease_IOR.h gov_cca_Component_IOR.h                      \
  gov_cca_ConnectionID_IOR.h gov_cca_IOR.h gov_cca_Port_IOR.h                 \
  gov_cca_Services_IOR.h gov_cca_TypeMap_IOR.h                                \
  gov_cca_TypeMismatchException_IOR.h gov_cca_Type_IOR.h                      \
  gov_cca_ports_BasicParameterPort_IOR.h gov_cca_ports_BuilderService_IOR.h   \
  gov_cca_ports_ComponentRepository_IOR.h                                     \
  gov_cca_ports_ConnectionEventListener_IOR.h                                 \
  gov_cca_ports_ConnectionEventService_IOR.h                                  \
  gov_cca_ports_ConnectionEvent_IOR.h gov_cca_ports_EventType_IOR.h           \
  gov_cca_ports_GoPort_IOR.h gov_cca_ports_IOR.h                              \
  gov_cca_ports_ParameterGetListener_IOR.h                                    \
  gov_cca_ports_ParameterPortFactory_IOR.h gov_cca_ports_ParameterPort_IOR.h  \
  gov_cca_ports_ParameterSetListener_IOR.h                                    \
  gov_cca_ports_ServiceProvider_IOR.h gov_cca_ports_ServiceRegistry_IOR.h
STUBHDRS = decaf_Framework_fAbbrev.h decaf_Framework_fStub.h                  \
  gov_cca_AbstractFramework_fAbbrev.h gov_cca_AbstractFramework_fStub.h       \
  gov_cca_CCAExceptionType_fAbbrev.h gov_cca_CCAException_fAbbrev.h           \
  gov_cca_CCAException_fStub.h gov_cca_ComponentClassDescription_fAbbrev.h    \
  gov_cca_ComponentClassDescription_fStub.h gov_cca_ComponentID_fAbbrev.h     \
  gov_cca_ComponentID_fStub.h gov_cca_ComponentRelease_fAbbrev.h              \
  gov_cca_ComponentRelease_fStub.h gov_cca_Component_fAbbrev.h                \
  gov_cca_Component_fStub.h gov_cca_ConnectionID_fAbbrev.h                    \
  gov_cca_ConnectionID_fStub.h gov_cca_Port_fAbbrev.h gov_cca_Port_fStub.h    \
  gov_cca_Services_fAbbrev.h gov_cca_Services_fStub.h                         \
  gov_cca_TypeMap_fAbbrev.h gov_cca_TypeMap_fStub.h                           \
  gov_cca_TypeMismatchException_fAbbrev.h                                     \
  gov_cca_TypeMismatchException_fStub.h gov_cca_Type_fAbbrev.h                \
  gov_cca_ports_BasicParameterPort_fAbbrev.h                                  \
  gov_cca_ports_BasicParameterPort_fStub.h                                    \
  gov_cca_ports_BuilderService_fAbbrev.h gov_cca_ports_BuilderService_fStub.h \
  gov_cca_ports_ComponentRepository_fAbbrev.h                                 \
  gov_cca_ports_ComponentRepository_fStub.h                                   \
  gov_cca_ports_ConnectionEventListener_fAbbrev.h                             \
  gov_cca_ports_ConnectionEventListener_fStub.h                               \
  gov_cca_ports_ConnectionEventService_fAbbrev.h                              \
  gov_cca_ports_ConnectionEventService_fStub.h                                \
  gov_cca_ports_ConnectionEvent_fAbbrev.h                                     \
  gov_cca_ports_ConnectionEvent_fStub.h gov_cca_ports_EventType_fAbbrev.h     \
  gov_cca_ports_GoPort_fAbbrev.h gov_cca_ports_GoPort_fStub.h                 \
  gov_cca_ports_ParameterGetListener_fAbbrev.h                                \
  gov_cca_ports_ParameterGetListener_fStub.h                                  \
  gov_cca_ports_ParameterPortFactory_fAbbrev.h                                \
  gov_cca_ports_ParameterPortFactory_fStub.h                                  \
  gov_cca_ports_ParameterPort_fAbbrev.h gov_cca_ports_ParameterPort_fStub.h   \
  gov_cca_ports_ParameterSetListener_fAbbrev.h                                \
  gov_cca_ports_ParameterSetListener_fStub.h                                  \
  gov_cca_ports_ServiceProvider_fAbbrev.h                                     \
  gov_cca_ports_ServiceProvider_fStub.h                                       \
  gov_cca_ports_ServiceRegistry_fAbbrev.h                                     \
  gov_cca_ports_ServiceRegistry_fStub.h
STUBMODULESRCS = decaf_Framework.F90 gov_cca_AbstractFramework.F90            \
  gov_cca_CCAException.F90 gov_cca_CCAExceptionType.F90 gov_cca_Component.F90 \
  gov_cca_ComponentClassDescription.F90 gov_cca_ComponentID.F90               \
  gov_cca_ComponentRelease.F90 gov_cca_ConnectionID.F90 gov_cca_Port.F90      \
  gov_cca_Services.F90 gov_cca_Type.F90 gov_cca_TypeMap.F90                   \
  gov_cca_TypeMismatchException.F90 gov_cca_ports_BasicParameterPort.F90      \
  gov_cca_ports_BuilderService.F90 gov_cca_ports_ComponentRepository.F90      \
  gov_cca_ports_ConnectionEvent.F90 gov_cca_ports_ConnectionEventListener.F90 \
  gov_cca_ports_ConnectionEventService.F90 gov_cca_ports_EventType.F90        \
  gov_cca_ports_GoPort.F90 gov_cca_ports_ParameterGetListener.F90             \
  gov_cca_ports_ParameterPort.F90 gov_cca_ports_ParameterPortFactory.F90      \
  gov_cca_ports_ParameterSetListener.F90 gov_cca_ports_ServiceProvider.F90    \
  gov_cca_ports_ServiceRegistry.F90
STUBSRCS = decaf_Framework_fStub.c gov_cca_AbstractFramework_fStub.c          \
  gov_cca_CCAExceptionType_fStub.c gov_cca_CCAException_fStub.c               \
  gov_cca_ComponentClassDescription_fStub.c gov_cca_ComponentID_fStub.c       \
  gov_cca_ComponentRelease_fStub.c gov_cca_Component_fStub.c                  \
  gov_cca_ConnectionID_fStub.c gov_cca_Port_fStub.c gov_cca_Services_fStub.c  \
  gov_cca_TypeMap_fStub.c gov_cca_TypeMismatchException_fStub.c               \
  gov_cca_Type_fStub.c gov_cca_ports_BasicParameterPort_fStub.c               \
  gov_cca_ports_BuilderService_fStub.c                                        \
  gov_cca_ports_ComponentRepository_fStub.c                                   \
  gov_cca_ports_ConnectionEventListener_fStub.c                               \
  gov_cca_ports_ConnectionEventService_fStub.c                                \
  gov_cca_ports_ConnectionEvent_fStub.c gov_cca_ports_EventType_fStub.c       \
  gov_cca_ports_GoPort_fStub.c gov_cca_ports_ParameterGetListener_fStub.c     \
  gov_cca_ports_ParameterPortFactory_fStub.c                                  \
  gov_cca_ports_ParameterPort_fStub.c                                         \
  gov_cca_ports_ParameterSetListener_fStub.c                                  \
  gov_cca_ports_ServiceProvider_fStub.c gov_cca_ports_ServiceRegistry_fStub.c
TYPEMODULESRCS = decaf_Framework_type.F90 gov_cca_AbstractFramework_type.F90  \
  gov_cca_CCAExceptionType_type.F90 gov_cca_CCAException_type.F90             \
  gov_cca_ComponentClassDescription_type.F90 gov_cca_ComponentID_type.F90     \
  gov_cca_ComponentRelease_type.F90 gov_cca_Component_type.F90                \
  gov_cca_ConnectionID_type.F90 gov_cca_Port_type.F90                         \
  gov_cca_Services_type.F90 gov_cca_TypeMap_type.F90                          \
  gov_cca_TypeMismatchException_type.F90 gov_cca_Type_type.F90                \
  gov_cca_ports_BasicParameterPort_type.F90                                   \
  gov_cca_ports_BuilderService_type.F90                                       \
  gov_cca_ports_ComponentRepository_type.F90                                  \
  gov_cca_ports_ConnectionEventListener_type.F90                              \
  gov_cca_ports_ConnectionEventService_type.F90                               \
  gov_cca_ports_ConnectionEvent_type.F90 gov_cca_ports_EventType_type.F90     \
  gov_cca_ports_GoPort_type.F90 gov_cca_ports_ParameterGetListener_type.F90   \
  gov_cca_ports_ParameterPortFactory_type.F90                                 \
  gov_cca_ports_ParameterPort_type.F90                                        \
  gov_cca_ports_ParameterSetListener_type.F90                                 \
  gov_cca_ports_ServiceProvider_type.F90                                      \
  gov_cca_ports_ServiceRegistry_type.F90
