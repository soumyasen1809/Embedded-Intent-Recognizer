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

class Recognition
{
public:
    std::vector<std::string> words_from_string(const std::string& );
    std::string read_parameters(std::string&);
    std::vector<std::string> matching_to_intents(std::vector<std::string>&);
};



#endif