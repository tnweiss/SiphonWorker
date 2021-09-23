//
// Created by Tyler on 9/3/2021.
//
#include <memory>
#include <vector>
#include <chrono>
#include "boost/python.hpp"
#include "nlohmann/json.hpp"

#include "serdes_test.h"
#include "JSONSerDes.h"
#include "BASESerDes.h"
#include "FrameSerDes.h"
#include "PyJSON.h"
#include "PartitionedFrame.h"
#include "util.h"


int main () {
    // set the test id to the current timestamp
    std::string test_id = generate_test_id();

    // start the python interpreter, so we can create python objects in test data
    Py_Initialize();

    // add all the tests
    // TODO shuffle tests
    std::vector<std::unique_ptr<SerDesTest>> tests{};
    tests.push_back(std::unique_ptr<SerDesTest>(new BASESerDes())); // used as a baseline to ensure measurements are not effected by copying resources
    tests.push_back(std::unique_ptr<SerDesTest>(new JSONSerDes())); // using nlohmann/json to serialize / deserialize to json
    tests.push_back(std::unique_ptr<SerDesTest>(new PyJSON())); // uses python json to deserialize / serialize data
    tests.push_back(std::unique_ptr<SerDesTest>(new FrameSerDes())); // uses frame data structure
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(2))); // threaded frame with 2 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(3))); // threaded frame with 3 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(4))); // threaded frame with 4 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(5))); // threaded frame with 5 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(6))); // threaded frame with 6 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(7))); // threaded frame with 7 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(8))); // threaded frame with 8 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(9))); // threaded frame with 9 threads for SerDes

    //                1Kb   50kb   100kb   500kb   1Mb      5Mb      10Mb      50Mb
    //int sizeTestsB[] {1024, 51200, 102400, 512000, 1048576, 5242880, 10485760, 52428800};
    int sizeTestsB[] {1024, 51200, 102400, 512000, 1048576, 5242880, 10485760};

    // for logging
    unsigned int totalTests = (sizeof (sizeTestsB) / sizeof(int)) * tests.size();

    unsigned int currentTest = 1;

    // used to mark the start + checkpoints of tests
    std::chrono::steady_clock::time_point start, end, last_checkpoint;
    unsigned long duration;

    // output the checkpoints at the end of the test
    std::vector<nlohmann::json> checkpoints{};

    // declare intermediate data
    DataContainer serializedData, serializedData2;
    void* deserializedData;
    void* output;

    // for each data set size, run each test
    for (const int testSize: sizeTestsB) {
        // generate the test data, imitate data coming from python program
        PyObject* td = data(testSize);

        for (const std::unique_ptr<SerDesTest>& t: tests) {
            // log the start
            startTest(t->type(), testSize, currentTest, totalTests);

            // mark start, ser/des mark end
            last_checkpoint = std::chrono::steady_clock::now();
            start = std::chrono::steady_clock::now();

            serializedData = t->serialize(td);                                      // Python -> Redis
            checkpoints.push_back(checkpoint(t->type(), testSize,  "PythonToRedis", last_checkpoint));

            deserializedData = t->deserialize(serializedData);            // Redis -> Container
            checkpoints.push_back(checkpoint(t->type(), testSize,  "RedisToContainer", last_checkpoint));

            serializedData2 = t->serialize(deserializedData);                                                     // Container -> Redis
            checkpoints.push_back(checkpoint(t->type(), testSize,  "ContainerToRedis", last_checkpoint));

            // mark the end of the test
            end = std::chrono::steady_clock::now();

            // make sure there was no loss of data
            output = t->deserialize(serializedData2);
            if (!t->test(output, td)) {
                std::cout << "\n\nFaulty Test (" << t->type() << ") did not pass test" << std::endl;
                exit(1);
            }

            // log the end
            // TODO add test to ensure proper serialization
            duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            endTest(t->type(), testSize, duration,true, test_id.c_str());

            // cleanup
            t->delete_deserialized_data(deserializedData);
            t->delete_deserialized_data(output);
            serializedData.clear();
            serializedData2.clear();
        }

        // write the checkpoints
        writeCheckpoints(checkpoints, test_id.c_str());

        // delete the test data
        boost::python::decref(td);
    }
}