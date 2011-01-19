#ifndef WSGI_PYTHON_H
#define WSGI_PYTHON_H

/* ------------------------------------------------------------------------- */

/*
 * Copyright 2007-2011 GRAHAM DUMPLETON
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* ------------------------------------------------------------------------- */

#include <Python.h>

#if !defined(PY_VERSION_HEX)
#error Sorry, Python developer package does not appear to be installed.
#endif

#if PY_VERSION_HEX <= 0x02030000
#error Sorry, mod_wsgi requires at least Python 2.3.0 for Python 2.X.
#endif

#if PY_VERSION_HEX >= 0x03000000 && PY_VERSION_HEX < 0x03010000
#error Sorry, mod_wsgi requires at least Python 3.1.0 for Python 3.X.
#endif

#if !defined(WITH_THREAD)
#error Sorry, mod_wsgi requires that Python supporting thread.
#endif

#include "structmember.h"
#include "compile.h"
#include "node.h"
#include "osdefs.h"

#ifndef PyVarObject_HEAD_INIT
#define PyVarObject_HEAD_INIT(type, size)       \
        PyObject_HEAD_INIT(type) size,
#endif

#if PY_MAJOR_VERSION >= 3
#define PyStringObject PyBytesObject
#define PyString_Check PyBytes_Check
#define PyString_Size PyBytes_Size
#define PyString_AsString PyBytes_AsString
#define PyString_FromString PyBytes_FromString
#define PyString_FromStringAndSize PyBytes_FromStringAndSize
#define PyString_AS_STRING PyBytes_AS_STRING
#define PyString_GET_SIZE PyBytes_GET_SIZE
#define _PyString_Resize _PyBytes_Resize
#endif

#if PY_MAJOR_VERSION < 3
#ifndef PyBytesObject
#define PyBytesObject PyStringObject
#define PyBytes_Type PyString_Type

#define PyBytes_Check PyString_Check
#define PyBytes_CheckExact PyString_CheckExact 
#define PyBytes_CHECK_INTERNED PyString_CHECK_INTERNED
#define PyBytes_AS_STRING PyString_AS_STRING
#define PyBytes_GET_SIZE PyString_GET_SIZE
#define Py_TPFLAGS_BYTES_SUBCLASS Py_TPFLAGS_STRING_SUBCLASS

#define PyBytes_FromStringAndSize PyString_FromStringAndSize
#define PyBytes_FromString PyString_FromString
#define PyBytes_FromFormatV PyString_FromFormatV
#define PyBytes_FromFormat PyString_FromFormat
#define PyBytes_Size PyString_Size
#define PyBytes_AsString PyString_AsString
#define PyBytes_Repr PyString_Repr
#define PyBytes_Concat PyString_Concat
#define PyBytes_ConcatAndDel PyString_ConcatAndDel
#define _PyBytes_Resize _PyString_Resize
#define _PyBytes_Eq _PyString_Eq
#define PyBytes_Format PyString_Format
#define _PyBytes_FormatLong _PyString_FormatLong
#define PyBytes_DecodeEscape PyString_DecodeEscape
#define _PyBytes_Join _PyString_Join
#define PyBytes_AsStringAndSize PyString_AsStringAndSize
#define _PyBytes_InsertThousandsGrouping _PyString_InsertThousandsGrouping
#endif
#endif

/* ------------------------------------------------------------------------- */

#endif

/* vi: set sw=4 expandtab : */
