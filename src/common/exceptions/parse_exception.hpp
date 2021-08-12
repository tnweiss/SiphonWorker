#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <exception>
#include <string>

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

# endif