#include <exception>
#include <string>
#include <utility>
#include "boost/format.hpp"

#ifndef SIPHON_PARSE_EXCEPTION_H
#define SIPHON_PARSE_EXCEPTION_H

namespace siphon {
    class ParseException: public std::exception
    {
        public:
            explicit ParseException(std::string msg) {
                this->msg = std::move(msg);
            }
            [[nodiscard]] const char* what() const noexcept override
            {
                return msg.c_str();
            }
        private:
            std::string msg;

    };

    class KeyNotFoundParseException: public std::exception
    {
        public:
            explicit KeyNotFoundParseException(std::string key) {
                this->msg = (boost::format("Unable to find required parameter '%1%'") % key).str();
            }
            KeyNotFoundParseException(std::string shortKey, std::string longKey) {
                this->msg = (boost::format("Unable to find required parameter S:'%1%' L:'%2%'") % shortKey % longKey).str();
            }
            [[nodiscard]] const char* what() const noexcept override
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
            [[nodiscard]] const char* what() const noexcept override
            {
                return msg.c_str();
            }
        private:
            std::string msg;

    };
}

#endif