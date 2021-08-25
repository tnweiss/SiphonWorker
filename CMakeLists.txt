project(siphon)

include(FetchContent)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
#add_definitions(-std=c++17 )
# -Wno-deprecated for windows / linux
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

####### Dependencies ##########
INCLUDE_DIRECTORIES(
        /home/tyler/anaconda3/include/python3.8
        third_party/json
        third_party/boost
        third_party/catch2
        third_party/pybind11_json
        third_party/pybind11/src/pybind11/include
        third_party/magic_enum
  )

# Get Magic enum
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/magic_enum)
file(DOWNLOAD https://raw.githubusercontent.com/Neargye/magic_enum/master/include/magic_enum.hpp ${CMAKE_CURRENT_SOURCE_DIR}/third_party/magic_enum/magic_enum.hpp)

# Get nholman json
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/json/nlohmann)
file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/third_party/json/nlohmann/json.hpp)

# Get catch2
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/catch2)
file(DOWNLOAD https://raw.githubusercontent.com/catchorg/Catch2/v2.13.7/single_include/catch2/catch.hpp ${CMAKE_CURRENT_SOURCE_DIR}/third_party/catch2/catch2.hpp)

# Get pybind11 json for json conversions
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/pybind11_json)
file(DOWNLOAD https://raw.githubusercontent.com/pybind/pybind11_json/master/include/pybind11_json/pybind11_json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/third_party/pybind11_json/pybind11_json.hpp)

# get pybind11
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/pybind11)
include(ExternalProject)
find_package(Git REQUIRED)
ExternalProject_Add(
    pybind11
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/third_party/pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    LOG_DOWNLOAD ON
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

# Get boost
set(BOOST_URL "https://boostorg.jfrog.io/artifactory/main/release/1.71.0/source/boost_1_71_0.tar.bz2" CACHE STRING "Boost download URL")
set(BOOST_URL_SHA256 "d73a8da01e8bf8c7eda40b4c84915071a8c8a0df4a6734537ddde4a8580524ee" CACHE STRING "Boost download URL SHA256 checksum")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/third_party/boost)
FetchContent_Declare(
  Boost
  URL ${BOOST_URL}
  URL_HASH SHA256=${BOOST_URL_SHA256}
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/boost
)
FetchContent_GetProperties(Boost)
if(NOT Boost_POPULATED)
  message(STATUS "Fetching Boost")
  FetchContent_Populate(Boost)
  message(STATUS "Fetching Boost - done")
  set(BOOST_SOURCE ${boost_SOURCE_DIR})
endif()

# Python 3.8
find_package(PythonLibs 3.8 REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIRS})
message(${PYTHON_INCLUDE_DIRS})


########## Include the src subdirectory ##########
add_subdirectory(src)