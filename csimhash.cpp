#include <Python.h>
#include <simhash/include/simhash/Simhasher.hpp>
using namespace simhash;

static PyObject* csimhash_simhash(PyObject* self, PyObject* args){
	char* s;
	if(!PyArg_ParseTuple(args, "s", &s))
		return NULL;
	size_t topN = 5;
    uint64_t u64 = 0;
	vector<pair<string ,double> > res;
    simhasher.extract(s, res, topN);
    simhasher.make(s, topN, u64);
    return (PyObject*)Py_BuildValue("K", fac(u64));
}

static PyObject* csimhash_isEqual(PyObject* self, PyObject* arg1, PyObject* arg2, PyObject* threshold){
	uint64_t u1, u2;
	unsigned short s;
	if(PyArg_ParseTuple(arg1, "K", &u1)&&PyArg_ParseTuple(arg2, "K", &u2)&&PyArg_ParseTuple(threshold, "H", &s))
		if(Simhasher::isEqual(u1, u2, s))
			return Py_BuildValue("i", 1);
		else
			return Py_BuildValue("i", 0);
	return NULL;

}

static PyMethodDef csimhashmethods[] = {
	{"simhash", csimhash_simhash, METH_VARARGS},
	{"isEqual", csimhash_isEqual, METH_VARARGS}
}

void initcsimhash(){
	Py_initModule("csimhash", csimhashmethods);
}