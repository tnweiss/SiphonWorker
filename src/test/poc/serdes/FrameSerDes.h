//
// Created by Tyler on 9/8/2021.
//

#ifndef SIPHON_FRAMESERDES_H
#define SIPHON_FRAMESERDES_H

#include "serdes_test.h"


class FrameSerDes: public SerDesTest {
public:
    const char* type() final;
    DataContainer serialize(PyObject*) final;
    void* deserialize(DataContainer&) final;
    DataContainer serialize(void*) final;
    void delete_deserialized_data(void*) final;

};

class Frame {
public:
    explicit Frame(void* buffer) {
        _data = new std::vector<long*>();
        _size = *(size_t*)buffer;

        // reserve as much space as needed for the number of incoming items
        _data->reserve(_size);

        _typeSize = sizeof(long);

        long* curBuff = (long*)((size_t*)buffer + 1);
        for (int i=0; i< _size; i++, curBuff += 1) {
            _data->push_back(curBuff);
        }
    }

    [[nodiscard]] DataContainer data_container() const {
        DataContainer dc((_size * sizeof(long)) + sizeof(size_t));

        size_t offset = 0;
        auto* s = new size_t(_size);  // TODO remove this crap
        dc.set(s, offset, sizeof(size_t));
        delete s;
        offset += sizeof(size_t);

        for (int i=0; i<_size; i++, offset += _typeSize) {
            dc.set(_data->at(i), offset, _typeSize);
        }

        return dc;
    }

    ~Frame() {
        delete _data;
    }

private:
    size_t _size;
    size_t _typeSize;
    std::vector<long*>* _data;
};


#endif //SIPHON_FRAMESERDES_H
