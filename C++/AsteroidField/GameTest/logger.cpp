/// @author: Iaroslav Vasiletc
/// @date  : 27.08.2019
/// @brief : Simple log class, to improve output

#pragma once
#include "logger.h"

logger::logger(std::string _function, int _line)
{
    ss << _function << "() " << "line " << _line << ": ";
}

logger::~logger()
{
    printf("%s\n", ss.str().c_str());
}