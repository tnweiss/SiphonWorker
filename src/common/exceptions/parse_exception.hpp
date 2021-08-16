#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <exception>
#include <string>
#include "boost/format.hpp"

namespace siphon {
    class ParseException: public std::exception
    {
        public:
            ParseException(std::string msg) {
                this->msg = msg;
            }
            virtual const char* what() const throw()
            {
                return msg.c_str();
            }
        private:
            std::string msg;

    };

    class KeyNotFoundParseException: public std::exception
    {
        public:
            KeyNotFoundParseException(std::string key) {
                this->msg = (boost::format("Unable to find required parameter '%1%'") % key).str();
            }
            virtual const char* what() const throw()
            {
                return msg.c_str();
            }
        private:
            std::string msg;

    };

    class InvalidTypeParseException: public std::exception
    {
        public:
            InvalidTypeParseException(std::string key, std::string type_actual, std::string data, std::string type_expected) {
                this-> msg = (boost::format(
                    "Unable to parse '%1%' to a '%2%'. Actual type is '%3%'. Value is '%4%'") 
                    % key % type_expected % type_actual % data ).str();
            }
            virtual const char* what() const throw()
            {
                return msg.c_str();
            }
        private:
            std::string msg;

    };
}

# endif