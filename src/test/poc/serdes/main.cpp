//
// Created by Tyler on 9/3/2021.
//
#include <string>
#include <iomanip>
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include "nlohmann/json.hpp"

#include "serdes_test.h"
#include "JSONSerdes.h"

const static int NUM_BYTES = 1000000;


//nlohmann::json deserializeJson(char* d) {
//    std::string a(d);
//    return nlohmann::json::parse(a);
//}


template <typename T>
std::vector<T> data(const int bytes, T d) {
    // calculate the vector length
    const int v_len = bytes / sizeof(T);

    // initialize the vector
    std::vector<long> data{};
    for (int i=0; i<v_len; i++) {
        data.push_back(d);
    }

    return data;
}


void endTest(const std::string& _type, int _size, long _durationUs, bool _test) {
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
    detailedResultsFile.open ("serdesPOCResults.json", std::ios_base::app);
    detailedResultsFile << testOutput.dump() << '\n';
    detailedResultsFile.close();
}


void startTest(const std::string& _type, int _size, unsigned int & currentCount, unsigned int total) {
    std::cout << std::setw(3) << std::right << currentCount << "/";
    std::cout << std::setw(3) << std::left << total;
    std::cout << " Running: " << std::setw(10) << std::left << _type << " with size " << std::setw(10) << _size << " ...";
    currentCount ++;
}


int main () {
    // add all the tests
    std::vector<std::unique_ptr<SerdesTest<long>>> tests{};
    tests.push_back(std::unique_ptr<SerdesTest<long>>(new JSONSerdes<long>()));

    //                1Kb   50kb   100kb   500kb   1Mb      5Mb      10Mb      50Mb
    int sizeTestsB[] {1000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000};

    // for logging
    unsigned int totalTests = (sizeof (sizeTestsB) / sizeof(int)) * tests.size();
    unsigned int currentTest = 1;

    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    nlohmann::json testOutput;

    // for each data set size, run each test
    for (const int testSize: sizeTestsB) {
        // generate the test data
        const std::vector<long> td = data<long>(testSize, 100L);

        for (const std::unique_ptr<SerdesTest<long>>& t: tests) {
            // log the start
            startTest(t->type(), testSize, currentTest, totalTests);

            // mark start, ser/des mark end
            start = std::chrono::steady_clock::now();
            const char* serializedData = t->serialize(td);
            t->deserialize(serializedData);
            end = std::chrono::steady_clock::now();

            // log the end
            endTest(t->type(), testSize, std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(),
                    t->test(td));
        }
    }
}