//
// Created by Tyler on 9/3/2021.
//
#include <memory>
#include "boost/any.hpp"
#include "boost/python.hpp"

#ifndef SIPHON_SERDES_TEST_H
#define SIPHON_SERDES_TEST_H


class SerDesTest {
public:
    /**
     * String representation of the test
     * @return
     */
    virtual const char* type() = 0;

    /**
     * Step 1. Python plugin -> redis
     * @return
     */
    virtual std::shared_ptr<char> serialize(PyObject*) = 0;

    /**
     * Step 2. redis -> container, read data in from redis to process
     * @return
     */
    virtual std::shared_ptr<void> deserialize(const char*) = 0;

    /**
     * Step 3. container -> redis, send data back to redis
     * @return
     */
    virtual std::shared_ptr<char> serialize(std::shared_ptr<void>) = 0;

};


#endif //SIPHON_SERDES_TEST_H
