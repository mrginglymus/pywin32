// This file implements the IOleWindow Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIOleWindow.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIOleWindow::PyIOleWindow(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIOleWindow::~PyIOleWindow()
{
}

/* static */ IOleWindow *PyIOleWindow::GetI(PyObject *self)
{
	return (IOleWindow *)PyIUnknown::GetI(self);
}

// @pymethod |PyIOleWindow|GetWindow|Description of GetWindow.
PyObject *PyIOleWindow::GetWindow(PyObject *self, PyObject *args)
{
	IOleWindow *pIOW = GetI(self);
	if ( pIOW == NULL )
		return NULL;
	HWND hwnd;
	if ( !PyArg_ParseTuple(args, ":GetWindow") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOW->GetWindow( &hwnd );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOW, IID_IOleWindow);
	return PyWinLong_FromHANDLE(hwnd);
}

// @pymethod |PyIOleWindow|ContextSensitiveHelp|Description of ContextSensitiveHelp.
PyObject *PyIOleWindow::ContextSensitiveHelp(PyObject *self, PyObject *args)
{
	IOleWindow *pIOW = GetI(self);
	if ( pIOW == NULL )
		return NULL;
	// @pyparm int|fEnterMode||Description for fEnterMode
	BOOL fEnterMode;
	if ( !PyArg_ParseTuple(args, "i:ContextSensitiveHelp", &fEnterMode) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOW->ContextSensitiveHelp( fEnterMode );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIOW, IID_IOleWindow);
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIOleWindow|Description of the interface
static struct PyMethodDef PyIOleWindow_methods[] =
{
	{ "GetWindow", PyIOleWindow::GetWindow, 1 }, // @pymeth GetWindow|Description of GetWindow
	{ "ContextSensitiveHelp", PyIOleWindow::ContextSensitiveHelp, 1 }, // @pymeth ContextSensitiveHelp|Description of ContextSensitiveHelp
	{ NULL }
};

PyComTypeObject PyIOleWindow::type("PyIOleWindow",
		&PyIUnknown::type,
		sizeof(PyIOleWindow),
		PyIOleWindow_methods,
		GET_PYCOM_CTOR(PyIOleWindow));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGOleWindow::GetWindow(
		/* [out] */ HWND __RPC_FAR * phwnd)
{
	static const char *method_name = "GetWindow";
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyWinObject_AsHANDLE(result, (HANDLE *)phwnd))
		hr=MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGOleWindow::ContextSensitiveHelp(
		/* [in] */ BOOL fEnterMode)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("ContextSensitiveHelp", NULL, "i", fEnterMode);
	return hr;
}

