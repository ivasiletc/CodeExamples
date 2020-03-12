/// @author: Iaroslav Vasiletc
/// @date  : 27.08.2019

#pragma once

#include <iostream>
#include <sstream>
#include <string>

#define log logger(__FUNCTION__, __LINE__, DEBUG)
#define log_warn logger(__FUNCTION__, __LINE__, WARNING)
#define log_err logger(__FUNCTION__, __LINE__, ERROR)

enum log_type
{
    DEBUG,
    WARNING,
    ERROR
};

class logger
{
public:
    logger(std::string _function, int _line, log_type _type);
    ~logger();

    template<typename T>
    logger& operator<< (const T& t) {
        ss << t << " ";
        return *this;
    }

private:
    std::stringstream ss;

};