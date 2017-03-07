IORHDRS = objarg_Basic_IOR.h objarg_EmployeeArray_IOR.h objarg_Employee_IOR.h \
  objarg_IOR.h
STUBHDRS = objarg_Basic_array_bindcdecls.h objarg_Basic_fAbbrev.h             \
  objarg_Basic_fStub.h objarg_Basic_mod_bindcdecls.h                          \
  objarg_EmployeeArray_array_bindcdecls.h objarg_EmployeeArray_fAbbrev.h      \
  objarg_EmployeeArray_fStub.h objarg_EmployeeArray_mod_bindcdecls.h          \
  objarg_Employee_array_bindcdecls.h objarg_Employee_fAbbrev.h                \
  objarg_Employee_fStub.h objarg_Employee_mod_bindcdecls.h
STUBMODULESRCS = objarg_Basic.F03 objarg_Employee.F03 objarg_EmployeeArray.F03
STUBSRCS = objarg_Basic_fStub.c objarg_EmployeeArray_fStub.c                  \
  objarg_Employee_fStub.c
TYPEMODULESRCS = objarg_Basic_type.F03 objarg_EmployeeArray_type.F03          \
  objarg_Employee_type.F03

