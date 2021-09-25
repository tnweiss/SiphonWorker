//
// Created by Tyler on 9/3/2021.
//

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
    //tests.push_back(std::unique_ptr<SerDesTest>(new BASESerDes())); // used as a baseline to ensure measurements are not effected by copying resources
    //tests.push_back(std::unique_ptr<SerDesTest>(new JSONSerDes())); // using nlohmann/json to serialize / deserialize to json
    //tests.push_back(std::unique_ptr<SerDesTest>(new PyJSON())); // uses python json to deserialize / serialize data
    tests.push_back(std::unique_ptr<SerDesTest>(new FrameSerDes())); // uses frame data structure
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(2))); // threaded frame with 2 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(3))); // threaded frame with 3 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(4))); // threaded frame with 4 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(5))); // threaded frame with 5 threads for SerDes
    tests.push_back(std::unique_ptr<SerDesTest>(new PartitionedFrame(6))); // threaded frame with 6 threads for SerDes

    //                1Kb   5kb   10kb   50kb   100kb   300kb   500kb   800kb   1Mb      3mb      5Mb      8mb      10Mb      25mb      50Mb      75mb
    int sizeTestsB[] {1024, 5120, 10240, 51200, 102400, 307200, 512000, 819200, 1048576, 3145728, 5242880, 8388608, 10485760, 26214400, 52428800, 78643200};
    //int sizeTestsB[] {5242880};

    // number of times to run the test
    static const short num_iterations = 5;

    // random number generator for shuffling the tests
    auto rng = std::default_random_engine (std::stoi(test_id));

    // for logging
    unsigned int totalTests = (sizeof (sizeTestsB) / sizeof(int)) * tests.size() * num_iterations;

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

    for (short iteration=0; iteration<num_iterations; iteration++) {
        // for each data set size, run each test
        for (const int testSize: sizeTestsB) {
            // generate the test data, imitate data coming from python program
            PyObject* td = data(testSize);

            std::shuffle( tests.begin(), tests.end(), rng);
            for (const std::unique_ptr<SerDesTest>& t: tests) {
                // log the start
                startTest(t->type(), testSize, currentTest, totalTests);

                // mark start, ser/des mark end
                last_checkpoint = std::chrono::steady_clock::now();
                start = std::chrono::steady_clock::now();

                serializedData = t->serialize(td);                                      // Python -> Redis
                checkpoints.push_back(checkpoint(t->type(), testSize,  "1-PythonToRedis", last_checkpoint));

                deserializedData = t->deserialize(serializedData);            // Redis -> Container
                checkpoints.push_back(checkpoint(t->type(), testSize,  "2-RedisToContainer", last_checkpoint));

                serializedData2 = t->serialize(deserializedData);                                                     // Container -> Redis
                checkpoints.push_back(checkpoint(t->type(), testSize,  "3-ContainerToRedis", last_checkpoint));

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
}