#include <iostream>
#include <vector>
#include <string>
#include "Recognition.h"
#include "Recognition_Driver.h"

std::vector<std::string> Recognition_Driver::Intent_Recognition(const std::string& user_input){
    std::vector<std::string> input_words = Recognition().words_from_string(user_input);
    std::vector<std::string> intents_matched = Recognition().matching_to_intents(input_words);

    return intents_matched;
}