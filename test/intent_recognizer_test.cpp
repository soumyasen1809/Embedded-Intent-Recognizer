#include <gtest/gtest.h>
#include <iostream>
#include "Recognition.h"
#include "Recognition_Driver.h"

std::string convert_to_string(const std::vector<std::string>& inputLine){
    std::string intents;
    for (const auto& i:inputLine)
    {
        intents += i;
    }
    return intents;
}

TEST(Embedded_Intent_Recognizer_test, Weather_Test){
    auto intent = convert_to_string(Recognition_Driver().Intent_Recognition("What is the weather today?"));
    EXPECT_EQ("Weather",intent);
    intent = convert_to_string(Recognition_Driver().Intent_Recognition("Is today SUNNY?"));
    EXPECT_EQ("Weather",intent);
}

TEST(Embedded_Intent_Recognizer_test, City_Test){
    auto intent = convert_to_string(Recognition_Driver().Intent_Recognition("Where is Paris?"));
    EXPECT_EQ("City",intent);
    intent = convert_to_string(Recognition_Driver().Intent_Recognition("Where is paris?"));
    EXPECT_EQ("City",intent);
}

TEST(Embedded_Intent_Recognizer_test, Fact_Test){
    auto intent = convert_to_string(Recognition_Driver().Intent_Recognition("Tell me a fact."));
    EXPECT_EQ("Fact",intent);
    intent = convert_to_string(Recognition_Driver().Intent_Recognition("Can you share an interesting fACt?"));
    EXPECT_EQ("Fact",intent);
}

TEST(Embedded_Intent_Recognizer_test, NotFound_Test){
    auto intent = convert_to_string(Recognition_Driver().Intent_Recognition("Do you know a joke?"));
    EXPECT_EQ("No intents found!",intent);
}

TEST(Embedded_Intent_Recognizer_test, Multiple_Intent_Test){
    auto intent = convert_to_string(Recognition_Driver().Intent_Recognition("What's the weather today is Paris?"));
    EXPECT_EQ("WeatherCity",intent);
    intent = convert_to_string(Recognition_Driver().Intent_Recognition("Tokyo SUNNY?"));
    EXPECT_EQ("CityWeather",intent);
    intent = convert_to_string(Recognition_Driver().Intent_Recognition("HELLO!!! Can you share an interesting fact about SUnny days in paris?"));
    EXPECT_EQ("GreetingFactWeatherCity",intent);
}
