# Embedded-Intent-Recognizer

Embedded-Intent-Recognizer is a small and simple command line tool built using modern C++17 that recognizes human intent.
The list of intents that this tool can understand can be found in `parameters/parameters.txt`. Users can modify this text file to add more intents.
The user doesn't need to modify any `src` or `header` files for new intents to start working.

A particular format needs to be followed to insert new intents: The first word is the name of the intent while the following words, seperated by commas, are the key words that are associated with the intent. For example, `Weather,Sunny,Rainy,Cloudy,Fog` in the `parameters.txt` file show that `Weather` is the intent while the others `Sunny, Rainy, Cloudy` and `Fog` are the words that the user wants to be matched to the intent `Weather`.
Suppose a new intent `Profession` needs to be added and the words that should associate to it are `Teacher, Banker, Scientist` and `Doctor`. To do so, simply append to the `parameters.txt` file, `Profession,Teacher,Banker,Scientist,Doctor`.

## Build and Compile

CMake and Make are used as build-management tools for this project. This code can be built as
```bash
mkdir build && cd build && cmake .. && make
```

# Use the program

An example to use the Intent Recognition Tool is:
```
$ ./src/Embedded_Intent_Recognizer
Enter your intent:
What is the weather like today?
Intent: Get Weather

$ ./src/Embedded_Intent_Recognizer
Enter your intent:
What is the weather like in Paris today?
Intent: Get Weather City

$ ./src/Embedded_Intent_Recognizer
Enter your intent:
Tell me an interesting fact.
Intent: Get Fact

$ ./src/Embedded_Intent_Recognizer
Enter your intent:
Hello!!! Can you tell me an interesting FAct about SUNNY days in PARIS?? 
Intent: Get Greeting Fact Weather City
```
\
__Generic handling of the input__ : As seen from the above examples, the tool is case-insensitive, i.e. the user can input `PARIS` or `parIS` and they will still be treated the same. Additionally the user can add punctuations and the code will handle it as well. Hence the user can input an excited greeting `HELLO!!!!` message to the tool and it can understand that the intent is `Greeting`.

# Structure of the code

```
Embedded-Intent_Recognizer
│
|─── parameters
│    │-   parameters.txt
│   
|─── src
|    │-   CMakeLists.txt
|    │-   main.cpp
|    │-   Recognition_Driver.(cpp,h)
|    │-   Recognition.(cpp,h)
|
|─── test
|    │-   CMakeLists.txt
|    │-   main.cpp
|    │-   intent_recognizer_test.cpp
|
|─── README.md
|─── CMakeLists.txt 
|─── .gitignore

```


# Testing framework

[GoogleTest](https://github.com/google/googletest) (also known as gtest) is Google's C++ testing and mocking framework. It is used in this project for writing unit tests. Using the `FetchContent_Declare()` in `CMakeLists.txt`, the content for GoogleTest is fetched and is stored in `/lib/googletest/` directory. The configuration declares a dependency on GoogleTest which is downloaded from GitHub. To fetch an up-to-date version of GoogleTest, the URL needs to be updated.
\
To get the gtest results, we can run as
```bash
$ ./test/Embedded_Intent_Recognizer_test
```
It runs 5 tests from 1 test suite `Embedded_Intent_Recognizer_test`. The tests include `Weather_Test, City_Test, Fact_Test, NotFound_Test` and `Multiple_Intent_Test`. 

