//
// Created by Tyler on 9/8/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include "FrameSerDes.h"

const char* FrameSerDes::type() {
    return "Frame";
}


DataContainer FrameSerDes::serialize(PyObject* pyJson) {
    // get the list len + data size to calculate the size of the buffer
    size_t pyListLen = PyList_Size(pyJson);
    size_t dataSize = sizeof(long);
    DataContainer dc((pyListLen * dataSize) + sizeof(size_t));

    size_t offset = 0;

    // copy the number of elements on to the buffer
    dc.set(&pyListLen, offset, sizeof(size_t));
    offset += sizeof(size_t);

    PyObject *value;
    for (int i=0; i<pyListLen; i++, offset += dataSize) {
        value = PyList_GetItem(pyJson, i);

        dc.set(PyLong_AsLong(value), offset, dataSize);
    }

    return dc;
}


void* FrameSerDes::deserialize(DataContainer& dc) {
    return new Frame(dc.v());
}


DataContainer FrameSerDes::serialize(void* vFrame) {
    // cast the data
    auto* frame = (Frame*)vFrame;

    return frame->data_container();
}


void FrameSerDes::delete_deserialized_data(void* frame) {
    delete (Frame*)frame;
}


bool FrameSerDes::test(void* actual, PyObject* expected) {
    auto* frame = (Frame*)actual;

    // get the list len + data size to calculate the size of the buffer
    size_t pyListLen = PyList_Size(expected);

    if (pyListLen != frame->size()) {
        return false;
    }



    long e;
    long * a;
    for (int i=0; i<pyListLen; i++) {
        e = PyLong_AsLong(PyList_GetItem(expected, i));
        a = frame->at(i);

        if (e != *a) {
            return false;
        }
    }
    return true;
}