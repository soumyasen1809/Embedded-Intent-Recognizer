# Embedded-Intent-Recognizer

Embedded-Intent-Recognizer is a small and simple command line tool built using modern C++17 that recognizes human intent.
The list of intents that this tool can understand can be found in `parameters/parameters.txt`. Users can modify this text file to add more intents.
The user doesn't need to modify any `src` or `header` files for new intents to start working. \\

A particular format needs to be followed to insert new intents: The first word is the name of the intent while the following words, seperated by commas, are the key words that are associated with the intent. For example, `Weather,Sunny,Rainy,Cloudy,Fog` in the `parameters.txt` file show that `Weather` is the intent while the others `Sunny, Rainy, Cloudy` and `Fog` are the words that the user wants to be matched to the intent `Weather`.
Suppose a new intent `Profession` needs to be added and the words that should associate to it are `Teacher, Banker, Scientist` and `Doctor`. To do so, simply append to the `parameters.txt` file, `Profession,Teacher,Banker,Scientist,Doctor`.

## Build and Compile

CMake and Make are used as build-management tools for this project. This code can be built as
```bash
mkdir build && cd build && cmake .. && make
```

# Use the program

An example to use the Intent Recognition Tool is:
```bash
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

As seen from the above examples, the tool is case-insensitive, i.e. the user can input `PARIS` or `parIS` and they will still be treated the same. Additionally the user can add punctuations and the code will handle it as well. Hence the user can input an excited greeting `HELLO!!!!` message to the tool and it can understand that the intent is `Greeting`.

# Testing framework

GoogleTest (also known as gtest) is Google's C++ testing and mocking framework. It is used in this project for writing unit tests. Using the `FetchContent_Declare()` in `CMakeLists.txt`, the content for GoogleTest is fetched and is stored in `/lib/googletest/` directory. The configuration declares a dependency on GoogleTest which is downloaded from GitHub. To fetch an up-to-date version of GoogleTest, the URL needs to be updated.


