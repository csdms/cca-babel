IMPLMODULESRCS = sort_CompInt_Mod.F90 sort_HeapSort_Mod.F90                   \
  sort_IntegerContainer_Mod.F90 sort_Integer_Mod.F90 sort_MergeSort_Mod.F90   \
  sort_QuickSort_Mod.F90 sort_SimpleCounter_Mod.F90 sort_SortTest_Mod.F90     \
  sort_SortingAlgorithm_Mod.F90
IMPLSRCS = sort_CompInt_Impl.F90 sort_HeapSort_Impl.F90                       \
  sort_IntegerContainer_Impl.F90 sort_Integer_Impl.F90                        \
  sort_MergeSort_Impl.F90 sort_QuickSort_Impl.F90 sort_SimpleCounter_Impl.F90 \
  sort_SortTest_Impl.F90 sort_SortingAlgorithm_Impl.F90
IORHDRS = sort_CompInt_IOR.h sort_Comparator_IOR.h sort_Container_IOR.h       \
  sort_Counter_IOR.h sort_HeapSort_IOR.h sort_IOR.h                           \
  sort_IntegerContainer_IOR.h sort_Integer_IOR.h sort_MergeSort_IOR.h         \
  sort_QuickSort_IOR.h sort_SimpleCounter_IOR.h sort_SortTest_IOR.h           \
  sort_SortingAlgorithm_IOR.h
IORSRCS = sort_CompInt_IOR.c sort_HeapSort_IOR.c sort_IntegerContainer_IOR.c  \
  sort_Integer_IOR.c sort_MergeSort_IOR.c sort_QuickSort_IOR.c                \
  sort_SimpleCounter_IOR.c sort_SortTest_IOR.c sort_SortingAlgorithm_IOR.c
SKELSRCS = sort_CompInt_fSkel.c sort_HeapSort_fSkel.c                         \
  sort_IntegerContainer_fSkel.c sort_Integer_fSkel.c sort_MergeSort_fSkel.c   \
  sort_QuickSort_fSkel.c sort_SimpleCounter_fSkel.c sort_SortTest_fSkel.c     \
  sort_SortingAlgorithm_fSkel.c
STUBHDRS = sort_CompInt_array_bindcdecls.h sort_CompInt_fAbbrev.h             \
  sort_CompInt_fStub.h sort_CompInt_mod_bindcdecls.h                          \
  sort_Comparator_array_bindcdecls.h sort_Comparator_fAbbrev.h                \
  sort_Comparator_fStub.h sort_Comparator_mod_bindcdecls.h                    \
  sort_Container_array_bindcdecls.h sort_Container_fAbbrev.h                  \
  sort_Container_fStub.h sort_Container_mod_bindcdecls.h                      \
  sort_Counter_array_bindcdecls.h sort_Counter_fAbbrev.h sort_Counter_fStub.h \
  sort_Counter_mod_bindcdecls.h sort_HeapSort_array_bindcdecls.h              \
  sort_HeapSort_fAbbrev.h sort_HeapSort_fStub.h                               \
  sort_HeapSort_mod_bindcdecls.h sort_IntegerContainer_array_bindcdecls.h     \
  sort_IntegerContainer_fAbbrev.h sort_IntegerContainer_fStub.h               \
  sort_IntegerContainer_mod_bindcdecls.h sort_Integer_array_bindcdecls.h      \
  sort_Integer_fAbbrev.h sort_Integer_fStub.h sort_Integer_mod_bindcdecls.h   \
  sort_MergeSort_array_bindcdecls.h sort_MergeSort_fAbbrev.h                  \
  sort_MergeSort_fStub.h sort_MergeSort_mod_bindcdecls.h                      \
  sort_QuickSort_array_bindcdecls.h sort_QuickSort_fAbbrev.h                  \
  sort_QuickSort_fStub.h sort_QuickSort_mod_bindcdecls.h                      \
  sort_SimpleCounter_array_bindcdecls.h sort_SimpleCounter_fAbbrev.h          \
  sort_SimpleCounter_fStub.h sort_SimpleCounter_mod_bindcdecls.h              \
  sort_SortTest_array_bindcdecls.h sort_SortTest_fAbbrev.h                    \
  sort_SortTest_fStub.h sort_SortTest_mod_bindcdecls.h                        \
  sort_SortingAlgorithm_array_bindcdecls.h sort_SortingAlgorithm_fAbbrev.h    \
  sort_SortingAlgorithm_fStub.h sort_SortingAlgorithm_mod_bindcdecls.h
STUBMODULESRCS = sort_CompInt.F90 sort_Comparator.F90 sort_Container.F90      \
  sort_Counter.F90 sort_HeapSort.F90 sort_Integer.F90                         \
  sort_IntegerContainer.F90 sort_MergeSort.F90 sort_QuickSort.F90             \
  sort_SimpleCounter.F90 sort_SortTest.F90 sort_SortingAlgorithm.F90
STUBSRCS = sort_CompInt_fStub.c sort_Comparator_fStub.c                       \
  sort_Container_fStub.c sort_Counter_fStub.c sort_HeapSort_fStub.c           \
  sort_IntegerContainer_fStub.c sort_Integer_fStub.c sort_MergeSort_fStub.c   \
  sort_QuickSort_fStub.c sort_SimpleCounter_fStub.c sort_SortTest_fStub.c     \
  sort_SortingAlgorithm_fStub.c
TYPEMODULESRCS = sort_CompInt_type.F90 sort_Comparator_type.F90               \
  sort_Container_type.F90 sort_Counter_type.F90 sort_HeapSort_type.F90        \
  sort_IntegerContainer_type.F90 sort_Integer_type.F90                        \
  sort_MergeSort_type.F90 sort_QuickSort_type.F90 sort_SimpleCounter_type.F90 \
  sort_SortTest_type.F90 sort_SortingAlgorithm_type.F90

_deps_sort_CompInt =  sort_CompInt_type sort_Comparator_type
sort_CompInt$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_CompInt))

_deps_sort_CompInt_Impl =  sort_CompInt
sort_CompInt_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_CompInt_Impl))

_deps_sort_Comparator =  sort_Comparator_type
sort_Comparator$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_Comparator))

_deps_sort_Container =  sort_Comparator_type sort_Container_type
sort_Container$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_Container))

_deps_sort_Counter =  sort_Counter_type
sort_Counter$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_Counter))

_deps_sort_HeapSort =  sort_Comparator_type sort_Counter_type                 \
  sort_Container_type sort_HeapSort_type sort_SortingAlgorithm_type
sort_HeapSort$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_HeapSort))

_deps_sort_HeapSort_Impl =  sort_HeapSort sort_Comparator sort_Container
sort_HeapSort_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_HeapSort_Impl))

_deps_sort_Integer =  sort_Integer_type
sort_Integer$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_Integer))

_deps_sort_IntegerContainer =  sort_Comparator_type                           \
  sort_IntegerContainer_type sort_Container_type
sort_IntegerContainer$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_IntegerContainer))

_deps_sort_IntegerContainer_Impl =  sort_IntegerContainer sort_Comparator
sort_IntegerContainer_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_IntegerContainer_Impl))

_deps_sort_Integer_Impl =  sort_Integer
sort_Integer_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_Integer_Impl))

_deps_sort_MergeSort =  sort_MergeSort_type sort_Comparator_type              \
  sort_Counter_type sort_Container_type sort_SortingAlgorithm_type
sort_MergeSort$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_MergeSort))

_deps_sort_MergeSort_Impl =  sort_MergeSort sort_Comparator sort_Container
sort_MergeSort_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_MergeSort_Impl))

_deps_sort_QuickSort =  sort_QuickSort_type sort_Comparator_type              \
  sort_Counter_type sort_Container_type sort_SortingAlgorithm_type
sort_QuickSort$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_QuickSort))

_deps_sort_QuickSort_Impl =  sort_QuickSort sort_Comparator sort_Container
sort_QuickSort_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_QuickSort_Impl))

_deps_sort_SimpleCounter =  sort_Counter_type sort_SimpleCounter_type
sort_SimpleCounter$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SimpleCounter))

_deps_sort_SimpleCounter_Impl =  sort_SimpleCounter
sort_SimpleCounter_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SimpleCounter_Impl))

_deps_sort_SortTest =  sort_SortTest_type sort_SortingAlgorithm_type
sort_SortTest$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SortTest))

_deps_sort_SortTest_Impl =  sort_SortTest sort_SortingAlgorithm
sort_SortTest_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SortTest_Impl))

_deps_sort_SortingAlgorithm =  sort_Comparator_type sort_Counter_type         \
  sort_Container_type sort_SortingAlgorithm_type
sort_SortingAlgorithm$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SortingAlgorithm))

_deps_sort_SortingAlgorithm_Impl =  sort_SortingAlgorithm sort_Counter
sort_SortingAlgorithm_Impl$(MOD_SUFFIX) : $(addsuffix $(MOD_SUFFIX), $(_deps_sort_SortingAlgorithm_Impl))

