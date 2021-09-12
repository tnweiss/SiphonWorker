//
// Created by Tyler on 9/8/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include "FrameSerDes.h"


const char* FrameSerDes::type() {
    return "Frame";
}


DataContainer FrameSerDes::serialize(PyObject* pyJson) {
    // get the list out of the object
    boost::python::list pyList = boost::python::extract<boost::python::list>(pyJson);

    // get the list len + data size to calculate the size of the buffer
    size_t pyListLen = boost::python::len(pyList);
    size_t dataSize = sizeof(long);
    size_t numElements = boost::python::len(pyList);
    DataContainer dc((pyListLen * dataSize) + sizeof(size_t));

    size_t offset = 0;

    // copy the number of elements on to the buffer
    dc.set(&numElements, offset, sizeof(size_t));
    offset += sizeof(size_t);

    long listItem;
    for (int i=0; i<pyListLen; i++, offset += dataSize) {
        boost::python::object t = boost::python::object(pyList[i]);

        listItem = PyLong_AsLong(t.ptr());

        if (listItem != 100L) {
            continue;
        }

        dc.set(&listItem, offset, dataSize);
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
