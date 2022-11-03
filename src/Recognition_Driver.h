#ifndef RECOGNITION_DRIVER_H
#define RECOGNITION_DRIVER_H

#include <iostream>
#include <vector>
#include <string>

#include "Recognition.h"

class Recognition_Driver
{
public:
    std::vector<std::string> Intent_Recognition(const std::string&);
};



#endif