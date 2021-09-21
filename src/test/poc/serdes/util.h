//
// Created by Tyler on 9/16/2021.
//
#ifndef UTIL_H_
#define UTIL_H_

#define BOOST_PYTHON_STATIC_LIB
#include <vector>
#include <chrono>
#include "boost/python.hpp"
#include "nlohmann/json.hpp"

#ifdef _WIN64
static const char* log_dir = R"(C:\Temp\logs\siphon\POC\SerDes\)";
#else
static const char* log_dir = "/tmp/logs/siphon/POC/SerDes/";
#endif

static const char *size_suffix[] = {"B", "KB", "MB", "GB", "TB"};
static const char *duration_suffix[] = {"us", "ms", "s"};

static const char* results_file = "SerDesPOCResults";
static const char* checkpoints_file = "SerDesPOCCheckPoints";
static const char* extension = ".json";

// pulled from https://gist.github.com/dgoguerra/7194777
static const char *humanSize(uint64_t bytes);

// pulled from https://gist.github.com/dgoguerra/7194777
static const char *humanDuration(uint64_t duration);

PyObject* data(unsigned int bytes);

void endTest(const std::string& _type, int _size, unsigned long _durationUs, bool _test, const char* test_id);

void startTest(const std::string& _type, int _size, unsigned int & currentCount, unsigned int total);

nlohmann::json checkpoint(const std::string& _type, unsigned int _size, const char* _checkpoint,
                          std::chrono::steady_clock::time_point& _start);

void writeCheckpoints(std::vector<nlohmann::json>& checkpoints, const char* test_id);

std::string generate_test_id();
#endif