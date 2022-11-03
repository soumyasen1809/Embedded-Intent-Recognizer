#ifndef RECOGNITION_DRIVER_H
#define RECOGNITION_DRIVER_H

#include <iostream>
#include <vector>
#include <string>

#include "Recognition.h"

/*
* @brief The Recognition_Driver class controls the flow from taking the user_input and returning the intents
*/
class Recognition_Driver
{
public:
    /*
    * @brief Recognition_Driver::Intent_Recognition gets the user input sentence and uses the
    * Recognition class to match the corresponding intents
    */
    std::vector<std::string> Intent_Recognition(const std::string&);
};



#endif