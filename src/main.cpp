#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#include "Recognition.h"
#include "Recognition_Driver.h"


int main(){
    std::string user_input;
    std::cout << "Enter your intent: " << std::endl;
    std::getline(std::cin, user_input);

    std::vector<std::string> intents_matched = Recognition_Driver().Intent_Recognition(user_input);

    // Print the output here
    std::cout << "Intent: Get ";
    for (const auto& intents:intents_matched)
    {
        std::cout << intents << " ";
    }
    std::cout << std::endl;

    return 0;
}
