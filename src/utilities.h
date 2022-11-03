#ifndef UTILITIES_H
#define UTILITIES_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

std::string read_parameters(std::string& parameter){
    // Clean the parameter by removing punctuations
    parameter.erase (std::remove_if (parameter.begin (), parameter.end (), ::ispunct), parameter.end ());

    std::vector<std::string> row;
    std::string line, word, temp;
    std::string parameter_intent = "None";

    std::ifstream fin("../parameters/parameters.txt");
    while (std::getline(fin, line))
    {
        row.clear();
        std::stringstream s(line);
        while (std::getline(s, word, ','))
        {
            row.push_back(word);
        }
        
        // Search for the intent parameter in the vector
        // This is case-sensitive
        // if (std::find(row.begin(), row.end(), parameter) != row.end())
        // {
        //     // Found the intent
        //     parameter_intent = row[0];
        // }
        // This is case-insensitive
        auto ret = std::find_if(row.begin(), row.end(),
            [&parameter](const std::string& s) {
                if (s.size() != parameter.size())
                    return false;
                return std::equal(s.cbegin(), s.cend(), parameter.cbegin(), parameter.cend(), [](auto c1, auto c2) { return std::tolower(c1) == std::tolower(c2); });
        });
        if (ret != row.end())
        {
            parameter_intent = row[0];
        }
        
    }
    

    fin.close();

    return parameter_intent;
    
}

std::vector<std::string> words_from_string(const std::string& user_input){
    std::vector<std::string> input_words;
    std::string word;
    std::stringstream ss(user_input);
    while (std::getline(ss, word, ' '))
    {
        input_words.push_back(word);
    }

    return input_words;
}

std::vector<std::string> matching_to_intents(std::vector<std::string>& input_words){
    std::vector<std::string> intent_matched;
    std::string recognized_intent;
    for (auto i = 0 ; i < input_words.size(); i++)
    {
        recognized_intent = read_parameters(input_words[i]);
        if (recognized_intent != "None")
        {
            intent_matched.push_back(recognized_intent);
        }
        
    }
    if (intent_matched.size() == 0)
    {
        intent_matched.push_back("No intents found!");
    }
    
    return intent_matched;
    
}

#endif