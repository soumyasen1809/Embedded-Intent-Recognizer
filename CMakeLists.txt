cmake_minimum_required(VERSION 3.5)

project(Embedded_Intent_Recognizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        SOURCE_DIR "../lib/googletest/"
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(src)
include_directories(lib/googletest/googletest/include/ lib/googletest/googletest/)

add_subdirectory(src)
add_subdirectory(test)
