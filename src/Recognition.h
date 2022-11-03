#ifndef RECOGNITION_H
#define RECOGNITION_H

#include <iostream>
#include <vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

/*
* @brief The Recognition class finds the intent from the user input
*/
class Recognition
{
public:
    /*
    * @brief Recognition::words_from_string gets the individual words from a given sentence
    */
    std::vector<std::string> words_from_string(const std::string& );

    /*
    * @brief Recognition::read_parameters searches for a particular word in the parameters file
    */
    std::string read_parameters(std::string&);

    /*
    * @brief Recognition::matching_to_intents matches the vector of words to the intent in the parameter file
    */
    std::vector<std::string> matching_to_intents(std::vector<std::string>&);
};



#endif