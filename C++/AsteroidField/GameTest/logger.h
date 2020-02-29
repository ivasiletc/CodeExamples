/// @author: Iaroslav Vasiletc
/// @date  : 27.08.2019

#pragma once

#include <iostream>
#include <sstream>
#include <string>

#define log logger(__FUNCTION__, __LINE__)

class logger
{
public:
    logger(std::string _function, int _line);
    ~logger();

    template<typename T>
    logger& operator<< (const T& t) {
        ss << t << " ";
        return *this;
    }

private:
    std::stringstream ss;

};