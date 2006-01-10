#ifndef PY_DISPLACEATTRIBUTES_H
#define PY_DISPLACEATTRIBUTES_H
#include <Python.h>
#include <DisplaceAttributes.h>

//
// Functions exposed to the VisIt module.
//
void            PyDisplaceAttributes_StartUp(DisplaceAttributes *subj, void *data);
void            PyDisplaceAttributes_CloseDown();
PyMethodDef    *PyDisplaceAttributes_GetMethodTable(int *nMethods);
bool            PyDisplaceAttributes_Check(PyObject *obj);
DisplaceAttributes *PyDisplaceAttributes_FromPyObject(PyObject *obj);
PyObject       *PyDisplaceAttributes_NewPyObject();
PyObject       *PyDisplaceAttributes_WrapPyObject(const DisplaceAttributes *attr);
std::string     PyDisplaceAttributes_GetLogString();
void            PyDisplaceAttributes_SetDefaults(const DisplaceAttributes *atts);

#endif

