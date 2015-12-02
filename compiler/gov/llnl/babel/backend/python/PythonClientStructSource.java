//
// File:        PythonClientStructSource.java
// Package:     gov.llnl.babel.backend.python
// Copyright:   (c) 2007 Lawrence Livermore National Security, LLC
// Release:     $Name$
// Revision:    @(#) $Revision: 6482 $
// Date:        $Date: 2008-08-21 15:50:53 -0700 (Thu, 21 Aug 2008) $
// Description: Generate C source file for Python wrapper for struct
// 
// Copyright (c) 2007, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory.
// Written by the Components Team <components@llnl.gov>
// UCRL-CODE-2002-054
// All rights reserved.
// 
// This file is part of Babel. For more information, see
// http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
// for Our Notice and the LICENSE file for the GNU Lesser General Public
// License.
// 
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License (as published by
// the Free Software Foundation) version 2.1 dated February 1999.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
// conditions of the GNU Lesser General Public License for more details.
// 
// You should have recieved a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

package gov.llnl.babel.backend.python;

import gov.llnl.babel.Context;
import gov.llnl.babel.backend.CodeGenerationException;
import gov.llnl.babel.backend.IOR;
import gov.llnl.babel.backend.Utilities;
import gov.llnl.babel.symbols.Struct;
import gov.llnl.babel.symbols.Symbol;
import gov.llnl.babel.symbols.SymbolID;
import gov.llnl.babel.symbols.Type;
import java.util.Collection;
import java.util.Iterator;

public class PythonClientStructSource extends PythonClientC {

  private Struct d_struct = null;
  private String d_methodNames[] = new String[8];

  PythonClientStructSource(Struct strct, Context context) {
    super(strct, context);
    d_struct = strct;
    d_methodNames[0] = Python.getExtendableWrapper(d_sym);
    d_methodNames[1] = Python.getExtendableConverter(d_sym);
    d_methodNames[2] = Python.getStructSerialize(d_sym);
    d_methodNames[3] = Python.getStructDeserialize(d_sym);
    d_methodNames[4] = Python.getStructInit(d_sym);
    d_methodNames[5] = Python.getStructDestroy(d_sym);
    d_methodNames[6] = Python.getStructCopy(d_sym);
    d_methodNames[7] = Python.getStructBorrow(d_sym);
  }

  public synchronized void generateCode()
    throws CodeGenerationException
  {
    try {
      d_lw = Python.createStub
        (d_struct, "implement a C extension type for a SIDL struct",
         d_context);
      d_lw.enableLineBreak(78, null, "\\");
      explainExtensionSource();
      d_lw.writeComment(d_struct, true);
      
      d_lw.printlnUnformatted("#include <Python.h>");
      includeHeaderFiles();
      writeTypeDeclTest();
      writeInstanceStruct();
      writeMetadata();
      writeTypeMethods();
      writeExternalFuncs();
      writeModuleMethods();
      writePythonType(true);
      writePythonType(false);
      writeInitFunction();
    }
    finally {
      if (d_lw != null) {
        d_lw.close();
        d_lw = null;
      }
    }
  }

  private Collection referencedSymbols()
    throws CodeGenerationException
  {
    Collection symbols = 
      Utilities.convertIdsToSymbols(d_context,d_sym.getSymbolReferences());
    symbols.add(Utilities.lookupSymbol(d_context, "sidl.io.Serializer"));
    symbols.add(Utilities.lookupSymbol(d_context, "sidl.io.Deserializer"));
    symbols.add(Utilities.lookupSymbol(d_context, "sidl.RuntimeException"));
    if (d_struct.hasType(Type.CLASS) || d_struct.hasType(Type.INTERFACE)) {
      symbols.add(Utilities.lookupSymbol(d_context, "sidl.io.Serializable"));
    }
    return symbols;
  }

  private void includeHeaderFiles() 
    throws CodeGenerationException
  {
    Collection symbols = referencedSymbols();
    d_lw.printlnUnformatted("#define " + Python.getInternalGuard(d_sym) +
                            " 1");
    addInclude(Python.getCHeaderPath(d_struct, "Module"), false);
    addInclude(IOR.getHeaderFile(d_struct.getSymbolID()), true);
    addInclude(IOR.getHeaderFile
               (Utilities.lookupSymbol(d_context, "sidl.BaseInterface").
                getSymbolID()),
               true);
    addInclude("sidlStruct.h", true);
    addInclude("sidlOps.h", true);
    addInclude("sidlObjA.h", true);
    addInclude("sidl_Python.h", true);
    if (d_struct.hasType(Type.ARRAY)) {
      addInclude("sidlPyArrays.h", true);
    }
    if (d_struct.hasType(Type.STRING)) {
      addInclude("sidl_String.h", true);
    }
    Iterator i = symbols.iterator();
    while (i.hasNext()) {
      Symbol sym = (Symbol)i.next();
      if (!(Symbol.ENUM == sym.getSymbolType())) {
        addInclude(Python.getCHeaderPath(sym, "Module"), true);
      }
    }
    d_lw.printlnUnformatted("#include <string.h>");
    d_lw.printlnUnformatted("#include <stdlib.h>");
    d_lw.println();
  }

  private void writeInstanceStruct()
  {
    d_lw.beginBlockComment(true);
    d_lw.println("This struct is used to hold the Python representation");
    d_lw.println("of the SIDL struct " + d_sym.getFullName() + ".");
    d_lw.println("It consists of the normal Python object header and a copy");
    d_lw.println("of the IOR struct.");
    d_lw.endBlockComment(true);
    d_lw.println("struct " + Python.getPyStructType(d_sym) + " {");
    d_lw.tab();
    d_lw.println("struct sidl_Python_BasicStruct d_basic;");
    d_lw.println(IOR.getStructName(d_sym) + " d_ior;");
    d_lw.backTab();
    d_lw.println("};");
    d_lw.println();
  }

  private void writeTypeDeclTest()
  {
    d_lw.beginBlockComment(true);
    d_lw.println("Declare the Python type object for this struct.");
    d_lw.endBlockComment(true);
    d_lw.println("staticforward PyTypeObject sidlStructObjectType;");
    d_lw.println("staticforward PyTypeObject sidlStructObjectType_Ref;");
    d_lw.println();
    d_lw.printlnUnformatted("#define is_SIDLstruct(v) ((v) && PyType_IsSubtype((v)->ob_type, &sidlStructObjectType_Ref))");
  }

  private void writeMetadata()
  {
    final int numItems = d_struct.getItems().size();
    if (numItems > 0) {
      d_lw.println("static struct sidl_Python_StructInfo metadata[" +
                   Integer.toString(numItems) + "];");
      d_lw.println();
    }
    d_lw.println("static PyGetSetDef _getSetMethods[" +
                 Integer.toString(numItems + 1) + "];");
    d_lw.println();
  }

  private void writeInitDependencies()
    throws CodeGenerationException
  {
    d_lw.println("import_sidlStruct();");
    d_lw.println("import_SIDLObjA();");
    if (d_struct.hasType(Type.ARRAY)) {
      d_lw.println("import_SIDLPyArrays();");
    }
    Iterator i = referencedSymbols().iterator();
    while (i.hasNext()) {
      Symbol sym = (Symbol)i.next();
      if (!(Symbol.ENUM == sym.getSymbolType())) {
        d_lw.println(Python.getExtendableImport(sym) + "();");
      }
    }
    d_lw.println();
  }

  private void initMetadata()
    throws CodeGenerationException
  {
    final String name = IOR.getStructName(d_sym.getSymbolID());
    int j = 0;
    Iterator i = d_struct.getItems().iterator();
    while (i.hasNext()) {
      final String elem = "metadata[" + Integer.toString(j++) + "]";
      final Struct.Item item = (Struct.Item)i.next();
      d_lw.println(elem + ".d_get = (sidlGetStructMember)" + 
                   helperFunction(true, item.getType()) + ";");
      d_lw.println(elem + ".d_set = (sidlSetStructMember)" + 
                   helperFunction(false, item.getType()) + ";");
      d_lw.println(elem + ".d_offset = offsetof(" + name + ", " + 
                   item.getName() + ");");
      d_lw.println(elem + ".d_getDeref = (sidlGetStructMemberDeref)" +
                   derefFunction(item.getType())+ ";");
    }
    i = d_struct.getItems().iterator();
    j = 0;
    while(i.hasNext()) {
      final String elem = "metadata[" + Integer.toString(j) + "]";
      final String pygs = "_getSetMethods[" + Integer.toString(j) + "]";
      final Struct.Item item = (Struct.Item)i.next();
      d_lw.println(pygs + ".name = \"" + item.getName() + "\";");
      d_lw.println(pygs + ".get = (getter)sidlPyGetStructMember;");
      d_lw.println(pygs + ".set = (setter)sidlPySetStructMember;");
      d_lw.println(pygs + ".doc = NULL;");
      d_lw.println(pygs + ".closure = &" + elem + ";");
      ++j;
    }
    final String last = "_getSetMethods[" + Integer.toString(j) + "]";
    d_lw.println(last + ".name = NULL;");
    d_lw.println(last + ".get = NULL;");
    d_lw.println(last + ".set = NULL;");
    d_lw.println(last + ".doc = NULL;");
    d_lw.println(last + ".closure = NULL;");
  }

  private String helperFunction(boolean get,
                                Type t)
    throws CodeGenerationException
  {
    switch(t.getDetailedType()) {
    case Type.STRUCT:
      Symbol ssym = Utilities.lookupSymbol(d_context, t.getSymbolID());
      return (get ? Python.getStructBorrow(ssym)
              : Python.getExtendableConverter(ssym));
    case Type.CLASS:
    case Type.INTERFACE:
      Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
      return (get ? "sidlPyGetDeref"
              : Python.getExtendableConverter(sym));
    case Type.ARRAY:
      return (get ? "sidlPyGetDeref"
              : Python.getBorrowArrayFromPython(t.getArrayType()));
    default:
      return (get ? "sidlPyGet" : "sidlPySet") +
        Utilities.capitalize(typeName(t.getDetailedType()));
    }
  }

  private String derefFunction(Type t)
    throws CodeGenerationException
  {
    switch(t.getDetailedType()) {
    case Type.ARRAY:
      return Python.getBorrowArrayFromSIDL(t.getArrayType());
    case Type.CLASS:
    case Type.INTERFACE:
      Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
      return Python.getExtendableNewRef(sym);
    default:
      return "NULL";
    }
  }

  private void writeGetSet()
  {
    d_lw.tab();
    Iterator i = d_struct.getItems().iterator();
    int j = 0;
    while (i.hasNext()) {
      final Struct.Item item = (Struct.Item)i.next();
      d_lw.println(",");
      d_lw.print("{ \"" + item.getName() + "\", NULL, NULL, NULL, &metadata[" + Integer.toString(j++) + "] }");
    }
    d_lw.println();
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeTypeSerialize(boolean serialize)
    throws CodeGenerationException
  {
    final Symbol argType = Utilities.lookupSymbol
      (d_context, serialize ? "sidl.io.Serializer" : "sidl.io.Deserializer");
    final String name = (serialize ? "serialize" : "deserialize");
    final SymbolID runtime = IOR.getRuntimeException(d_context);
    d_lw.println("static PyObject *");
    d_lw.println(name + "Struct(struct " +
                 Python.getPyStructType(d_sym) + 
                 " *self, PyObject *args, PyObject *keywords) {");
    d_lw.tab();
    d_lw.println("static char *_kwlist[] = {\"pipe\", \"name\", \"copy\", NULL};");
    d_lw.println("char *name;");
    d_lw.println(IOR.getObjectName(argType.getSymbolID()) + " *pipe;");
    d_lw.println("int copyObj = 0; /* default false */");
    d_lw.println("int okay;");
    d_lw.println("PyObject *return_value = NULL;");
    d_lw.println(IOR.getExceptionFundamentalType() + "exception;");
    d_lw.println("okay = PyArg_ParseTupleAndKeywords(args, keywords,");
    d_lw.tab();
    d_lw.println("\"sO&|i\", _kwlist, &name,");
    d_lw.println("(void *)" + Python.getExtendableConverter(argType) +
                 ",");
    d_lw.println("&pipe, &copyObj);");
    d_lw.backTab();
    d_lw.println("if (okay) {");
    d_lw.tab();
    d_lw.println((serialize ? Python.getStructSerialize(d_sym) 
                  : Python.getStructDeserialize(d_sym)) +
                 "(&(self->d_ior), pipe, name, copyObj, &exception);");
    d_lw.println("if (exception) {");
    d_lw.tab();
    d_lw.println(IOR.getObjectName(runtime) + " *ex0;");
    d_lw.println("if ((ex0 = (" + IOR.getObjectName(runtime) +
                 "*)");
    d_lw.tab();
    d_lw.println("sidl_PyExceptionCast(exception, \"" +
                 runtime.getFullName() + "\")))");
    d_lw.backTab();
    d_lw.println("{");
    d_lw.tab();
    d_lw.println(IOR.getExceptionFundamentalType() +
                 "throwaway_exception;");
    d_lw.println("PyObject *_obj = " +
                 Python.getExtendableWrapper(IOR.getRuntimeExceptionSymbol(d_context)) +
                 "(ex0);");
    d_lw.println("PyObject *_eargs = PyTuple_New(1);");
    d_lw.println("PyTuple_SetItem(_eargs, 0, _obj);");
    d_lw.println("_obj = PyObject_CallObject(" +
                 Python.getExceptionType(IOR.getRuntimeExceptionSymbol(d_context)) +
                 ", _eargs);");
    d_lw.println("PyErr_SetObject(sidl_RuntimeException__type, _obj);");
    d_lw.println("Py_XDECREF(_obj);");
    Python.leavePython(d_lw);
    d_lw.println("(*(exception->d_epv->f_deleteRef))(exception->d_object,");
    d_lw.tab();
    d_lw.println("&throwaway_exception);");
    d_lw.backTab();
    Python.resumePython(d_lw);
    d_lw.println("Py_XDECREF(_eargs);");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("else {");
    d_lw.tab();
    d_lw.println("return_value = Py_None;");
    d_lw.println("Py_INCREF(return_value);");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return return_value;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeModuleMethods()
    throws CodeGenerationException
  {
    writeTypeSerialize(true);
    writeTypeSerialize(false);
    d_lw.println("static struct PyMethodDef strmod_methods[] = {");
    d_lw.tab();
    d_lw.println("{ \"_serialize\", (PyCFunction)serializeStruct,");
    d_lw.tab();
    d_lw.println("(METH_VARARGS | METH_KEYWORDS),");
    d_lw.println("\"_serialize(name, pipe)\\");
    d_lw.printlnUnformatted("Serialize named struct to the given pipe.\"");
    d_lw.backTab();
    d_lw.println("},");
    d_lw.println("{ \"_deserialize\", (PyCFunction)deserializeStruct,");
    d_lw.tab();
    d_lw.println("(METH_VARARGS | METH_KEYWORDS),");
    d_lw.println("\"_deserialize(name, pipe)\\");
    d_lw.printlnUnformatted("Deserialize named struct from the given pipe.\"");
    d_lw.backTab();
    d_lw.println("},");
    d_lw.println("{ NULL, NULL }");
    d_lw.backTab();
    d_lw.println("};");
    d_lw.println();
  }

  private void writeInitFunction()
    throws CodeGenerationException
  {
    writeInitHeader();
    d_lw.println("{");
    d_lw.tab();
    writeInitModule();
    writeInitDependencies();
    writeInitCAPI();
    writeInitType();
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeInitHeader()
  {
    d_lw.printlnUnformatted("#ifdef __cplusplus");
    d_lw.println("extern \"C\" void init" + d_shortName + "(void);");
    d_lw.printlnUnformatted("#else");
    d_lw.println("extern void init" + d_shortName + "(void);");
    d_lw.println("#endif");
    d_lw.println();
    d_lw.println("void");
    d_lw.println("init" + d_shortName + "(void)");
  }

  private void writeInitModule()
  {
    final boolean docComment = (d_sym.getComment() != null) && 
      (d_sym.getComment().getComment() != null);
    d_lw.println("PyObject *module, *dict, *c_api;");
    d_lw.println("static void *strmod_api[" +
                 Python.getAPIVarName(d_sym) + "_NUM];");
    d_lw.println();
    d_lw.print((docComment ? "module = Py_InitModule3(\"" 
                : "module = Py_InitModule(\"") + d_shortName + 
               "\", strmod_methods");
    if (docComment) {
      d_lw.println(", \"\\");
      copyComment(d_sym.getComment());
      d_lw.printlnUnformatted("\"");
    }
    d_lw.println(");");
    d_lw.println("dict = PyModule_GetDict(module);");
    d_lw.println();
  }

  private void writeInitType()
    throws CodeGenerationException
  {
    initMetadata();
    d_lw.println("sidlStructObjectType_Ref.tp_base = sidlPyGetStructBase();");
    d_lw.println("if (PyType_Ready(&sidlStructObjectType_Ref) < 0) return;");
    d_lw.println("Py_INCREF(&sidlStructObjectType_Ref);");
    d_lw.println("Py_INCREF(&sidlStructObjectType_Ref);");
    d_lw.println("sidlStructObjectType.tp_base = &sidlStructObjectType_Ref;");
    d_lw.println("if (PyType_Ready(&sidlStructObjectType) < 0) return;");
    d_lw.println("Py_INCREF(&sidlStructObjectType);");
    d_lw.println("PyModule_AddObject(module, \"" + d_shortName + "\",");
    d_lw.tab();
    d_lw.println("(PyObject *)&sidlStructObjectType);");
    d_lw.backTab();
    d_lw.println();
  }

  private void writeInitCAPI()
  {
    for(int i = 0; i < d_methodNames.length; ++i) {
      d_lw.println("strmod_api[" +
                   d_methodNames[i] + "_NUM] = (void *)"+
                   d_methodNames[i] + ";");
    }
    d_lw.println("c_api = PyCObject_FromVoidPtr((void *)strmod_api, NULL);");
    d_lw.println("PyDict_SetItemString(dict, \"_C_API\", c_api);");
    d_lw.println("Py_XDECREF(c_api);");
    d_lw.println();
  }

  private void writeExternalFuncs()
    throws CodeGenerationException
  {
    writeStructConvert();
    writeStructCopy();
    writeStructBorrow();
    writeStructWrap();
    writeStructInit();
    writeStructDestroy();
    writeStructSerialize(true);
    writeStructSerialize(false);
  }

  private void writeStructBorrow()
    throws CodeGenerationException
  {
    final String method = Python.getStructBorrow(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    d_lw.println("struct sidl_Python_BasicStruct *strct = NULL;");
    d_lw.println("if (owner && src) {");
    d_lw.tab();
    d_lw.println("strct = (struct sidl_Python_BasicStruct *)");
    d_lw.tab();
    d_lw.println("sidlStructNew_Ref(&sidlStructObjectType_Ref,0,0);");
    d_lw.backTab();
    d_lw.println("strct->d_dependency = owner;");
    d_lw.println("Py_INCREF(owner);");
    d_lw.println("strct->d_ior = (void *)src;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return (PyObject *)strct;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeStructCopy()
    throws CodeGenerationException
  {
    final String method = Python.getStructCopy(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    d_lw.println("if (src != dest) {");
    d_lw.tab();
    Iterator i = d_struct.getItems().iterator();
    while(i.hasNext()) {
      final Struct.Item item = (Struct.Item)i.next();
      final Type t = item.getType();
      final String name = item.getName();
      switch(t.getDetailedType()) {
      case Type.BOOLEAN:
      case Type.CHAR:
      case Type.DCOMPLEX:
      case Type.DOUBLE:
      case Type.FCOMPLEX:
      case Type.FLOAT:
      case Type.INT:
      case Type.LONG:
      case Type.OPAQUE:
      case Type.ENUM:
        d_lw.println("dest->" + name + " = src->" + name + ";");
        break;
      case Type.STRING:
        d_lw.println("sidl_String_free(dest->" + name + ");");
        d_lw.println("dest->" + name + 
                         " = sidl_String_strdup(src->" +
                         name + ");");
        break;
      case Type.ARRAY:
        Python.leavePython(d_lw);
        d_lw.println("sidl__array_deleteRef((struct sidl__array *)dest->" 
                     + name + ");");
        Python.resumePython(d_lw);
        d_lw.println("dest->" + name +  " = (" +
                         IOR.getReturnString(t, d_context) +
                         ")");
        d_lw.tab();
        d_lw.println("sidl__array_smartCopy((struct sidl__array *)(src->" +
                         name + "));");
        d_lw.backTab();
        break;
      case Type.INTERFACE:
      case Type.CLASS:
        Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
        d_lw.println(Python.getExtendableDeref(sym) +
                     "(dest->" + name + ");");
        d_lw.println("dest->" + name + " = (" +
                         IOR.getReturnString(t, d_context) + ")src->" +
                         name + ";");
        d_lw.println("if (dest->" + name + ") {");
        d_lw.tab();
        d_lw.println(Python.getExtendableAddRef(sym) +
                         "(dest->" + name + ");");
        d_lw.backTab();
        d_lw.println("}");
        break;
      case Type.STRUCT:
        d_lw.println(Python.getStructCopy
                         (Utilities.lookupSymbol(d_context, t.getSymbolID())) +
                         "(&(src->" + name + "), &(dest->" +
                         name + "));");
        break;
      }
    }
    d_lw.backTab();
    d_lw.println("}");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeStructConvert()
    throws CodeGenerationException
  {
    final String method = Python.getExtendableConverter(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    d_lw.println("if (obj && sidlobj) {");
    d_lw.tab();
    d_lw.println("if (is_SIDLstruct(obj)) {");
    d_lw.tab();
    d_lw.println(Python.getStructCopy(d_sym) + "((" +
                 IOR.getStructName(d_sym) + " *)");
    d_lw.tab();
    d_lw.println("(((struct sidl_Python_BasicStruct *)obj)->d_ior),");
    d_lw.println("sidlobj);");
    d_lw.backTab();
    d_lw.backTab();
    d_lw.println("}");
    if (!d_struct.getItems().isEmpty()) {
      d_lw.println("else {");
      d_lw.tab();
      d_lw.println("PyObject *tmp;");
      d_lw.println("int result;");
      Iterator i = d_struct.getItems().iterator();
      while (i.hasNext()) {
        final Struct.Item item = (Struct.Item)i.next();
        d_lw.println("tmp = PyObject_GetAttrString(obj, \"" +
                     item.getName() + "\");");
        d_lw.println("if (!tmp) return 0;");
        d_lw.println("result = " +
                     helperFunction(false, item.getType()) +
                     "(tmp, &(sidlobj->" + item.getName() +"));");
        d_lw.println("Py_DECREF(tmp);");
        d_lw.println("if (!result) return 0;");
      }
      d_lw.backTab();
      d_lw.println("}");
    }
    d_lw.println("return 1;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return 0;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeStructWrap()
  {
    final String method = Python.getExtendableWrapper(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    d_lw.println("PyObject *result = NULL;");
    d_lw.println("if (sidlobj) {");
    d_lw.tab();
    d_lw.println("struct " + Python.getPyStructType(d_sym) + " *strct;");
    d_lw.println("result = sidlStructObjectType.tp_new(&sidlStructObjectType, NULL, NULL);");
    d_lw.println("if (result) {");
    d_lw.println("strct = (struct " + Python.getPyStructType(d_sym) + 
                 " *)result;");
    d_lw.println(Python.getStructCopy(d_sym) +
                 "(sidlobj, &(strct->d_ior));");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return result;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private static String typeName(int t)
  {
    switch(t) {
    case Type.ENUM: return "Long";
    case Type.CLASS:
    case Type.INTERFACE:
      return "Serializable";
    default:
      return Type.getTypeName(t);
    }
  }

  private void writeFormatString(int t)
  {
    switch(t) {
    case Type.BOOLEAN:
      d_lw.println("\"i\",");
      break;
    case Type.CHAR:
      d_lw.println("\"c\",");
      break;
    case Type.DOUBLE:
      d_lw.println("\"d\",");
      break;
    case Type.FLOAT:
      d_lw.println("\"f\",");
      break;
    case Type.INT:
      d_lw.println("\"l\",");
      break;
    case Type.ENUM:
    case Type.LONG:
      d_lw.printlnUnformatted("#ifdef HAVE_LONG_LONG");
      d_lw.println("\"L\",");
      d_lw.printlnUnformatted("#else");
      d_lw.println("\"l\",");
      d_lw.printlnUnformatted("#endif");
      break;
    case Type.OPAQUE:
    case Type.DCOMPLEX:
    case Type.FCOMPLEX:
      d_lw.println("\"N\",");
      break;
    case Type.CLASS:
    case Type.INTERFACE:
      d_lw.println("\"O&\",");
      break;
    case Type.STRING:
      d_lw.println("\"s\",");
      break;
    }
  }

  private void writeValueString(Type ty, String name)
    throws CodeGenerationException
  {
    switch(ty.getDetailedType()) {
    case Type.BOOLEAN:
      d_lw.println("(int)arg->" + name);
      break;
    case Type.INT:
      d_lw.println("(long)arg->" + name);
      break;
    case Type.ENUM:
    case Type.LONG:
      d_lw.printlnUnformatted("#ifdef HAVE_LONG_LONG");
      d_lw.println("(long long)arg->" + name);
      d_lw.printlnUnformatted("#else");
      d_lw.println("(long)arg->" + name);
      d_lw.printlnUnformatted("#endif");
      break;
    case Type.OPAQUE:
        d_lw.println("PyCObject_FromVoidPtr(arg->" + name +  ", NULL)");
      break;
    case Type.DCOMPLEX:
    case Type.FCOMPLEX:
      d_lw.println("PyComplex_FromDoubles(arg->" + name + ".real,");
      d_lw.println("arg->" + name + ".imaginary)");
      break;
    case Type.INTERFACE:
    case Type.CLASS:
      d_lw.println(Python.getExtendableNewRef
                   (Utilities.lookupSymbol(d_context, ty.getSymbolID())) +
                   ", arg->" + name);
      break;
    default:
      d_lw.println("arg->" + name);
      break;
    }
  }

  private void writeStructSerialize(boolean serialize)
    throws CodeGenerationException
  {
    final String method = (serialize 
                           ? Python.getStructSerialize(d_sym)
                           : Python.getStructDeserialize(d_sym));
    final Symbol pipeSym = Utilities.lookupSymbol
      (d_context, serialize ? "sidl.io.Serializer" : "sidl.io.Deserializer");
                            
    final int maxName = Python.maxNameLength(d_struct.getItems());
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    if (!d_struct.getItems().isEmpty()) {
      d_lw.println("const size_t namelen = (name ? strlen(name) : 0);");
      d_lw.println("char * const namebuf = sidl_malloc(namelen + " +
                   Integer.toString(maxName + 2) + ","); 
      d_lw.tab();
      try {
        d_lw.pushLineBreak(false);
        d_lw.println("\"failed to allocate a small buffer. " +
                     d_struct.getFullName() +
                     (serialize ? " " : " de") +
                     "serialization failed.\",");
        d_lw.println("__FILE__, __LINE__,");
        d_lw.println("\"" + method + "\",");
        d_lw.println("exception);");
      }
      finally {
        d_lw.popLineBreak();
      }
      d_lw.backTab();
      d_lw.println("if (namebuf) {");
      d_lw.tab();
      d_lw.println("PyObject *pyPipe, *pyResult = NULL;");
      d_lw.println("char * const innerName = namebuf + namelen + 1;");
      d_lw.println("memcpy(namebuf, name, namelen);");
      d_lw.println("namebuf[namelen] = '.';");
      d_lw.println("namebuf[namelen + " + 
                   Integer.toString(maxName + 1) + "] = '\\0';");
      d_lw.println("*exception = NULL;");
      d_lw.println("pyPipe = " +
                   Python.getExtendableNewRef(pipeSym) +
                   "(pipe);");
      d_lw.println("if (pyPipe) {");
      d_lw.tab();
      Iterator i = d_struct.getItems().iterator();
      while(i.hasNext()) {
        final Struct.Item item = (Struct.Item)i.next();
        final Type t = item.getType();
        d_lw.println("strcpy(innerName, \"" +
                     item.getName() + "\");");
        switch(t.getDetailedType()) {
        case Type.BOOLEAN:
        case Type.CHAR:
        case Type.DOUBLE:
        case Type.DCOMPLEX:
        case Type.FCOMPLEX:
        case Type.FLOAT:
        case Type.INT:
        case Type.LONG:
        case Type.INTERFACE:
        case Type.CLASS:
        case Type.OPAQUE:
        case Type.STRING:
        case Type.ENUM:
          String typename = (t.getDetailedType() != Type.ENUM) ?
            Type.getTypeName(t.getDetailedType()) : "Long";
          d_lw.println("pyResult = PyObject_CallMethod(pyPipe, \"" +
                       (serialize ? "pack" : "unpack") +
                       Utilities.
                       capitalize(typename) +
                       "\", \"s\"");
          d_lw.tab();
          writeFormatString(t.getDetailedType());
          d_lw.println("namebuf,");
          writeValueString(t, item.getName());
          d_lw.println(");");
          d_lw.backTab();
          d_lw.println("if (!pyResult) goto EXIT;");
          d_lw.println("Py_DECREF(pyResult);");
          break;
        case Type.ARRAY:
          d_lw.println("/* TODO: serialize array */");
          break;
        case Type.STRUCT:
          d_lw.println((serialize ? 
                        Python.getStructSerialize
                        (Utilities.lookupSymbol(d_context, t.getSymbolID())) :
                        Python.getStructDeserialize
                        (Utilities.lookupSymbol(d_context, t.getSymbolID()))) +
                       "(&(arg->" + item.getName() + 
                       "), pipe, namebuf, copyArg, exception);");
          break;
        default:
          throw new CodeGenerationException("Unexpected type");
        }
        if (i.hasNext()) {
          d_lw.println("if (*exception) goto EXIT;");    
        }
      }
      d_lw.println("EXIT:");
      d_lw.println("Py_XDECREF(pyPipe);");
      d_lw.println("Py_XDECREF(pyResult);");
      d_lw.println("free(namebuf);");
      d_lw.backTab();
      d_lw.println("}");
      d_lw.println("/* TODO: add else */");
      d_lw.backTab();
      d_lw.println("}");
      d_lw.println("else {");
      d_lw.tab();
      d_lw.println("fprintf(stderr, \"babel: " +
                   method + " failed to allocate a small name buffer. " +
                   (serialize ? "Serialization" : "Deserialization") +
                   " failed.\\n\");");
      d_lw.backTab();
      d_lw.println("}");
    }
    else {
      d_lw.println("*exception = NULL;");
    }
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeStructInit()
    throws CodeGenerationException
  {
    final String method = Python.getStructInit(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    Iterator i = d_struct.getItems().iterator();
    while(i.hasNext()) {
      final Struct.Item item = (Struct.Item)i.next();
      final Type t = item.getType();
      switch(t.getDetailedType()) {
      case Type.STRING:
      case Type.INTERFACE:
      case Type.CLASS:
      case Type.ARRAY:
      case Type.OPAQUE:
        d_lw.println("strct->" + item.getName() + " = NULL;");
        break;
      case Type.STRUCT:
        Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
        d_lw.println(Python.getStructInit(sym) + "(&(strct->" +
                     item.getName() + "));");
        break;
      }
    }
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeStructDestroy()
    throws CodeGenerationException
  {
    final String method = Python.getStructDestroy(d_sym);
    d_lw.println("static " + method + "_RETURN");
    d_lw.println(method + " " + method + "_PROTO {");
    d_lw.tab();
    Iterator i = d_struct.getItems().iterator();
    while(i.hasNext()) {
      final Struct.Item item = (Struct.Item)i.next();
      final Type t = item.getType();
      switch(t.getDetailedType()) {
        
      case Type.STRING:
      case Type.INTERFACE:
      case Type.CLASS:
      case Type.ARRAY:
        d_lw.println("if (strct->" + item.getName() + ") {");
        d_lw.tab();
        releaseItem(item.getName(), t);
        d_lw.backTab();
        d_lw.println("}");
        break;
      case Type.STRUCT:
        Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
        d_lw.println(Python.getStructDestroy(sym) + "(&(strct->" +
                     item.getName() + "));");
        break;
      }
    }
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void releaseItem(String name, Type t)
    throws CodeGenerationException
  {
    switch(t.getDetailedType()) {
    case Type.STRING:
      d_lw.println("free(strct->" + name + ");");
      break;
    case Type.CLASS:
    case Type.INTERFACE:
      Symbol sym = Utilities.lookupSymbol(d_context, t.getSymbolID());
      d_lw.println(Python.getExtendableDeref(sym) + "(strct->" +
                   name + ");");
      break;
    case Type.ARRAY:
      d_lw.println("sidl__array_deleteRef((struct sidl__array*)(strct->" +
                   name + "));");
      break;
    }
    d_lw.println("strct->" + name + " = NULL;");
  }

  private void writeTypeMethods() {
    writeTypeNew();
    writeTypeDestroy();
    writeTypeRefNew();
    writeTypeRefDestroy();
  }

  private void writeTypeRefNew()
  {
    d_lw.println("static PyObject *");
    d_lw.println("sidlStructNew_Ref(PyTypeObject *type, PyObject *args, PyObject *kwds) {");
    d_lw.tab();
    d_lw.println("struct sidl_Python_BasicStruct *self =");
    d_lw.tab();
    d_lw.println("(struct sidl_Python_BasicStruct *)(type->tp_alloc(type,0));");
    d_lw.backTab();
    d_lw.println("if (self) {");
    d_lw.tab();
    d_lw.println("self->d_dependency = NULL;");
    d_lw.println("self->d_ior = NULL;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return (PyObject *)self;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeTypeNew()
  {
    d_lw.println("static PyObject *");
    d_lw.println("sidlStructNew(PyTypeObject *type, PyObject *args, PyObject *kwds) {");
    d_lw.tab();
    d_lw.println("struct " +
                 Python.getPyStructType(d_sym) + "* self = ");
    d_lw.tab();
    d_lw.println("(struct " +
                 Python.getPyStructType(d_sym) + 
                 "*)(type->tp_alloc(type, 0));");
    d_lw.backTab();
    d_lw.println("if (self) {");
    d_lw.tab();
    d_lw.println(Python.getStructInit(d_sym) + "(&(self->d_ior));");
    d_lw.println("self->d_basic.d_dependency = NULL;");
    d_lw.println("self->d_basic.d_ior = (void *)&(self->d_ior);");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println("return (PyObject *)self;");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeTypeDestroy() {
    d_lw.println("static void");
    d_lw.println("sidlStructDestroy(PyObject *obj) {");
    d_lw.tab();
    d_lw.println("struct " + 
                 Python.getPyStructType(d_sym) + "* _myObj = (struct " +
                 Python.getPyStructType(d_sym) + "*)obj;");
    d_lw.println(Python.getStructDestroy(d_sym) + "(&(_myObj->d_ior));");
    d_lw.println("obj->ob_type->tp_free(obj);");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writeTypeRefDestroy() {
    d_lw.println("static void");
    d_lw.println("sidlStructDestroy_Ref(PyObject *obj) {");
    d_lw.tab();
    d_lw.println("struct sidl_Python_BasicStruct *_myObj =");
    d_lw.tab();
    d_lw.println("(struct sidl_Python_BasicStruct *)obj;");
    d_lw.backTab();
    d_lw.println("Py_XDECREF(_myObj->d_dependency);");
    d_lw.println("_myObj->d_dependency = NULL;");
    d_lw.println("_myObj->d_ior = NULL;");
    d_lw.println("obj->ob_type->tp_free(obj);");
    d_lw.backTab();
    d_lw.println("}");
    d_lw.println();
  }

  private void writePythonType(boolean dependent)
  {
    final SymbolID id = d_struct.getSymbolID();
    final String suffix = (dependent ? "_Ref" : "");
    d_lw.println("static PyTypeObject sidlStructObjectType" +
                 suffix + " = {");
    d_lw.tab();
    d_lw.println("PyObject_HEAD_INIT(NULL)");
    d_lw.println("0,      /* ob_size */");
    d_lw.println("\"" + id.getFullName() + "." + id.getShortName() + 
                 suffix + "\", /* tp_name */");
    d_lw.println("sizeof(struct " + 
                 (dependent ? "sidl_Python_BasicStruct"
                  : Python.getPyStructType(d_sym)) + "), /* tp_basicsize */");
    d_lw.println("0,      /* tp_itemsize */");
    d_lw.println("sidlStructDestroy" + suffix +
                 ",      /* tp_dealloc */");
    d_lw.println("0,      /* tp_print */");
    d_lw.println("0,      /* tp_getattr */");
    d_lw.println("0,      /* tp_setattr */");
    d_lw.println("0,      /* tp_compare */");
    d_lw.println("0,      /* tp_repr */");
    d_lw.println("0,      /* tp_as_number */");
    d_lw.println("0,      /* tp_as_sequence */");
    d_lw.println("0,      /* tp_as_mapping */");
    d_lw.println("0,      /* tp_hash  */");
    d_lw.println("0,      /* tp_call */");
    d_lw.println("0,      /* tp_str */");
    d_lw.println("0,      /* tp_getattro */");
    d_lw.println("0,      /* tp_setattro */");
    d_lw.println("0,      /* tp_as_buffer */");
    d_lw.println("Py_TPFLAGS_DEFAULT, /* tp_flags */");
    d_lw.println("\"\\");
    pythonDocComment();
    d_lw.printlnUnformatted("\", /* tp_doc */");
    d_lw.println("0,      /* tp_traverse */");
    d_lw.println("0,       /* tp_clear */");
    d_lw.println("0,       /* tp_richcompare */");
    d_lw.println("0,       /* tp_weaklistoffset */");
    d_lw.println("0,       /* tp_iter */");
    d_lw.println("0,       /* tp_iternext */");
    d_lw.println("0,       /* tp_methods */");
    d_lw.println("0,       /* tp_members */");
    if (dependent) {
      d_lw.println("_getSetMethods, /* tp_getset */");
    }
    else {
      d_lw.println("0,       /* tp_getset */");
    }
    d_lw.println("0,       /* tp_base */");
    d_lw.println("0,       /* tp_dict */");
    d_lw.println("0,       /* tp_descr_get */");
    d_lw.println("0,       /* tp_descr_set */");
    d_lw.println("0,       /* tp_dictoffset */");
    d_lw.println("0,       /* tp_init */");
    d_lw.println("0,       /* tp_alloc */");
    d_lw.println("sidlStructNew" + suffix + " /* tp_new */");
    d_lw.backTab();
    d_lw.println("};");
    d_lw.println();
  }
}
