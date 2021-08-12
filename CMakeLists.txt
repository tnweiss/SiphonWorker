project(siphon)
INCLUDE_DIRECTORIES(third_party third_party/boost)
cmake_minimum_required (VERSION 3.5)
add_definitions(-std=c++11)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

# Third party libraries
file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp ../third_party/json.hpp)
file(DOWNLOAD https://raw.githubusercontent.com/catchorg/Catch2/v2.13.7/single_include/catch2/catch.hpp ../third_party/catch2.hpp)

include(FetchContent)

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

# set(BOOST_LIBS_REQUIRED
#   # Header only libs
#   smart_ptr
# )

# foreach(lib ${BOOST_LIBS_REQUIRED})
#   add_subdirectory("${boost_SOURCE_DIR}/libs/${lib}")
# endforeach()

# add submodules
add_subdirectory(src)
