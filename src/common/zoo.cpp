#include "boost/python.hpp"
#include <string>

const std::string hello() {
    return std::string("hello, zoo");
}

BOOST_PYTHON_MODULE(zoo) {
    using namespace boost::python;
    def("hello", hello);
}