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
    bool test(void*, PyObject*) final;
};

class Frame {
public:
    // copy constructor
    Frame(const Frame& other): _typeSize(sizeof(long)), _size(other._size)
    {
        std::cout << "\n\n\nNO COPYING FRAME\n\n\n" << std::endl;
        _data = other._data;
    }

    // move constructor
    Frame(Frame&& other) noexcept : _typeSize(sizeof(long)), _size(other._size), _data(std::exchange(other._data, nullptr))
    {}

    // copy assignment
    Frame& operator=(const Frame& other)
    {
        std::cout << "\n\n\nNO COPYING FRAME\n\n\n" << std::endl;
        return *this = Frame(other);
    }

    // move assignment
    Frame& operator=(Frame&& other) noexcept
    {
        std::swap(_data, other._data);
        this->_size = other._size;
        return *this;
    }

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

    long* at(size_t index) {
        return _data->at(index);
    }

    size_t size() {
        return _size;
    }

private:
    size_t _size;
    size_t _typeSize;
    std::vector<long*>* _data;
};


#endif //SIPHON_FRAMESERDES_H
