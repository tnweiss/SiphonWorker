//
// Created by Tyler on 9/16/2021.
//

#include "util.h"

#include <string>
#include <iomanip>
#include <memory>
#include <iostream>
#include <fstream>
#include <ctime>


// pulled from https://gist.github.com/dgoguerra/7194777
static const char *humanSize(uint64_t bytes)
{
    char length = sizeof(size_suffix) / sizeof(size_suffix[0]);

    int i = 0;
    auto dblBytes = static_cast<double>(bytes);

    if (bytes > 1024) {
        for (i = 0; (bytes / 1024) > 0 && i<length-1; i++, bytes /= 1024)
            dblBytes = static_cast<double>(bytes) / 1024.0;
    }

    static char output[20];
    sprintf(output, "%.02lf %s", dblBytes, size_suffix[i]);
    return output;
}


// pulled from https://gist.github.com/dgoguerra/7194777
static const char *humanDuration(uint64_t duration)
{
    char length = sizeof(duration_suffix) / sizeof(duration_suffix[0]);

    int i = 0;
    auto dblDuration = static_cast<double>(duration);

    if (duration > 1000) {
        for (i = 0; (duration / 1000) > 0 && i<length-1; i++, duration /= 1000)
            dblDuration = static_cast<double>(duration) / 1000.0;
    }

    static char output[20];
    sprintf(output, "%4.02lf %2s", dblDuration, duration_suffix[i]);
    return output;
}


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


void endTest(const std::string& _type, int _size, unsigned long _durationUs, bool _test, const char* test_id) {
    // log progress
    std::cout << humanDuration(_durationUs) << std::endl;

    // output ndjson
    nlohmann::json testOutput{};
    testOutput["test"] = _type;
    testOutput["sizeMb"] = _size;
    testOutput["durationUs"] = _durationUs;
    testOutput["passed"] = _test;

    // write detailed results to file
    char f_name[100];
    std::sprintf(f_name, "%s%s-%s%s", log_dir, results_file, test_id, extension);

    std::ofstream detailedResultsFile;
    detailedResultsFile.open (f_name, std::ios_base::app);
    detailedResultsFile << testOutput.dump() << '\n';
    detailedResultsFile.close();
}


void startTest(const std::string& _type, int _size, unsigned int & currentCount, unsigned int total) {
    std::cout << std::setw(4) << std::right << currentCount << "/";
    std::cout << std::setw(4) << std::left << total;
    std::cout << std::setw(12) << std::left << _type << std::setw(16) << humanSize(_size);
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
                          std::chrono::steady_clock::time_point& _last_checkpoint) {
    // use dots to track progress
//    std::cout << ".";

    // calculate the duration since the start
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - _last_checkpoint).count();
    _last_checkpoint = end;

    // output ndjson
    nlohmann::json testOutput{};
    testOutput["test"] = _type;
    testOutput["sizeMb"] = _size;
    testOutput["durationSinceStartUs"] = duration;
    testOutput["checkpoint"] = _checkpoint;
    return testOutput;
}


void writeCheckpoints(std::vector<nlohmann::json>& checkpoints, const char* test_id) {
    char f_name[100];
    std::sprintf(f_name, "%s%s-%s%s", log_dir, checkpoints_file, test_id, extension);

    std::ofstream detailedResultsFile;
    detailedResultsFile.open (f_name, std::ios_base::app);

    for (nlohmann::json& c: checkpoints) {
        detailedResultsFile << c.dump() << '\n';
    }

    detailedResultsFile.close();
}


std::string generate_test_id() {
    auto now = std::chrono::system_clock::now();
    char buffer[30];
    std::sprintf(buffer, "%li", std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count());
    return (buffer);
}