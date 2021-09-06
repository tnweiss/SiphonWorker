//
// Created by Tyler on 9/3/2021.
//
#define BOOST_PYTHON_STATIC_LIB
#include <string>
#include <iomanip>
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include "nlohmann/json.hpp"
#include "boost/python.hpp"

#include "serdes_test.h"
#include "JSONSerDes.h"
#include "BASESerDes.h"

const static int NUM_BYTES = 1000000;


//nlohmann::json deserializeJson(char* d) {
//    std::string a(d);
//    return nlohmann::json::parse(a);
//}


PyObject* data(const unsigned int bytes) {
    // create the list object
    PyObject* list = boost::python::incref(boost::python::list().ptr());

    // number of elements can be the total bytes / bytes of single element
    const size_t num_elements = bytes / sizeof(long);

    for (int i=0; i<num_elements; i++) {
        // create the object
        PyObject* element = boost::python::incref(boost::python::long_(100).ptr());

        // add it to the list
        PyList_Append(list, element);
    }

    return list;
}


void endTest(const std::string& _type, int _size, unsigned long _durationUs, bool _test) {
    // log progress
    std::cout << "Done -  " << _durationUs << "us" << std::endl;

    // output ndjson
    nlohmann::json testOutput{};
    testOutput["test"] = _type;
    testOutput["sizeMb"] = _size;
    testOutput["durationUs"] = _durationUs;
    testOutput["passed"] = _test;

    // write detailed results to file
    std::ofstream detailedResultsFile;
    detailedResultsFile.open ("SerDesPOCResults.json", std::ios_base::app);
    detailedResultsFile << testOutput.dump() << '\n';
    detailedResultsFile.close();
}


void startTest(const std::string& _type, int _size, unsigned int & currentCount, unsigned int total) {
    std::cout << std::setw(3) << std::right << currentCount << "/";
    std::cout << std::setw(3) << std::left << total;
    std::cout << " Running: " << std::setw(10) << std::left << _type << " with size " << std::setw(10) << _size;
    currentCount ++;
}

/**
 * Used to identify the duration of certain operations
 * @param _type
 * @param _size
 * @param _checkpoint
 * @param _start
 */
nlohmann::json checkpoint(const std::string& _type, unsigned int _size, const char* _checkpoint,
                std::chrono::steady_clock::time_point& _start) {
    // use dots to track progress
//    std::cout << ".";

    // calculate the duration since the start
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - _start).count();

    // output ndjson
    nlohmann::json testOutput{};
    testOutput["test"] = _type;
    testOutput["sizeMb"] = _size;
    testOutput["durationSinceStartUs"] = duration;
    testOutput["checkpoint"] = _checkpoint;
    return testOutput;
}


void writeCheckpoints(std::vector<nlohmann::json>& checkpoints) {
    std::ofstream detailedResultsFile;
    detailedResultsFile.open ("SerDesPOCCheckpoints.json", std::ios_base::app);

    for (nlohmann::json& c: checkpoints) {
        detailedResultsFile << c.dump() << '\n';
    }

    detailedResultsFile.close();
}


int main () {
    // start the python interpreter, so we can create python objects in test data
    Py_Initialize();

    // add all the tests
    std::vector<std::unique_ptr<SerDesTest>> tests{};
    tests.push_back(std::unique_ptr<SerDesTest>(new JSONSerDes())); // using nlohmann/json to serialize / deserialize to json
    tests.push_back(std::unique_ptr<SerDesTest>(new BASESerDes())); // used as a baseline to ensure measurements are not effected by copying resources

    //                1Kb   50kb   100kb   500kb   1Mb      5Mb      10Mb      50Mb
    int sizeTestsB[] {1000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000};

    // for logging
    unsigned int totalTests = (sizeof (sizeTestsB) / sizeof(int)) * tests.size();
    unsigned int currentTest = 1;

    // used to mark the start + checkpoints of tests
    std::chrono::steady_clock::time_point start, end;
    unsigned long duration;

    // output the checkpoints at the end of the test
    std::vector<nlohmann::json> checkpoints{};

    // declare intermediate data
    std::shared_ptr<char> serializedData;
    std::shared_ptr<void> deserializedData;

    // for each data set size, run each test
    for (const int testSize: sizeTestsB) {
        // generate the test data, imitate data coming from python program
        PyObject* td = data(testSize);

        for (const std::unique_ptr<SerDesTest>& t: tests) {
            // log the start
            startTest(t->type(), testSize, currentTest, totalTests);

            // mark start, ser/des mark end
            start = std::chrono::steady_clock::now();

            serializedData = t->serialize(td);                                      // Python -> Redis
            checkpoints.push_back(checkpoint(t->type(), testSize,  "PythonToRedis", start));

            deserializedData = t->deserialize(serializedData.get());            // Redis -> Container
            checkpoints.push_back(checkpoint(t->type(), testSize,  "RedisToContainer", start));

            t->serialize(deserializedData);                                                     // Container -> Redis
            checkpoints.push_back(checkpoint(t->type(), testSize,  "ContainerToRedis", start));

            // mark the end of the test
            end = std::chrono::steady_clock::now();

            // log the end
            // TODO add test to ensure proper serialization
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            endTest(t->type(), testSize, duration,true);

            // destroy the intermediate objects
            if (serializedData != nullptr) {
                serializedData.reset();
            }
            if (deserializedData != nullptr) {
                deserializedData.reset();
            }
        }

        // write the checkpoints
        writeCheckpoints(checkpoints);

        // delete the test data
        boost::python::decref(td);
    }
}