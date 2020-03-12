/// @author: Iaroslav Vasiletc
/// @date  : 27.08.2019
/// @brief : Simple log class, to improve output

#pragma once
#include "logger.h"

logger::logger(std::string _function, int _line, log_type _type)
{
    switch(_type)
    {
    case DEBUG:
        ss << _function << "() " << "line " << _line << ": ";
        break;

    case ERROR:
        ss << "ERROR " << _function << "() " << "line " << _line << ": ";
        break;

    case WARNING:
        ss << "WARNING " <<  _function << "() " << "line " << _line << ": ";
        break;
    }

}

logger::~logger()
{
    printf("%s\n", ss.str().c_str());
}