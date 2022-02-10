#include <iostream>
#include <string>
#include <exception>

#pragma once

class my_exception : public std::exception
        {
        public:
            explicit my_exception(const std::string& msg)
            : msg_(msg)
            {}

            virtual ~my_exception() throw() {}

            virtual const char* what() const throw()
            {
                return msg_.c_str();
            }

        private:
            std::string msg_;
        };