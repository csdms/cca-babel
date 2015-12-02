//
// File:        Babel2BindCType.java
// Package:     gov.llnl.babel.backend.fortran
// Copyright:   (c) 2006 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision$
// Date:        $Date$
// Description: Convert a babel type to a bindC type.  Used 
// when building the derived data type in order to find the
// kind.

package gov.llnl.babel.backend.fortran;

import java.util.HashMap;
import gov.llnl.babel.symbols.Type;

public class Babel2BindCType {
  private static HashMap s_TypeToBindC;
  
  static {
    s_TypeToBindC = new HashMap();
    s_TypeToBindC.put(new Integer(Type.BOOLEAN),"integer(c_int32_t)");
    s_TypeToBindC.put(new Integer(Type.CHAR),"character(c_char)");
    s_TypeToBindC.put(new Integer(Type.INT),"integer(c_int32_t)");
    s_TypeToBindC.put(new Integer(Type.LONG),"integer(c_int64_t)");
    s_TypeToBindC.put(new Integer(Type.FLOAT),"real(c_float)");
    s_TypeToBindC.put(new Integer(Type.DOUBLE),"real(c_double)");
    s_TypeToBindC.put(new Integer(Type.FCOMPLEX),"complex(c_float_complex)");
    s_TypeToBindC.put(new Integer(Type.DCOMPLEX),"complex(c_double_complex)");
    s_TypeToBindC.put(new Integer(Type.OPAQUE),"type(c_ptr)");
    s_TypeToBindC.put(new Integer(Type.STRING),"type(c_ptr)");
    s_TypeToBindC.put(new Integer(Type.ENUM),"integer(c_int64_t)");
    s_TypeToBindC.put(new Integer(Type.INTERFACE),"type(c_ptr)");
    s_TypeToBindC.put(new Integer(Type.CLASS),"type(c_ptr)");
    s_TypeToBindC.put(new Integer(Type.STRUCT),"type(c_ptr)");
  }

  public Object getBindCType(Integer key){
    return s_TypeToBindC.get(key);
  }

}
