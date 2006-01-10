#ifndef PY_SLICEATTRIBUTES_H
#define PY_SLICEATTRIBUTES_H
#include <Python.h>
#include <SliceAttributes.h>

//
// Functions exposed to the VisIt module.
//
void            PySliceAttributes_StartUp(SliceAttributes *subj, void *data);
void            PySliceAttributes_CloseDown();
PyMethodDef    *PySliceAttributes_GetMethodTable(int *nMethods);
bool            PySliceAttributes_Check(PyObject *obj);
SliceAttributes *PySliceAttributes_FromPyObject(PyObject *obj);
PyObject       *PySliceAttributes_NewPyObject();
PyObject       *PySliceAttributes_WrapPyObject(const SliceAttributes *attr);
std::string     PySliceAttributes_GetLogString();
void            PySliceAttributes_SetDefaults(const SliceAttributes *atts);

#endif

