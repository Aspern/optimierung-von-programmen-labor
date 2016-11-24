cmake_minimum_required(VERSION 3.6)
project(opl)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#Compiler Flags for Chronometry
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g0 -Wall -Wpedantic -Werror -O3")

#Compiler Flags for Testing with Google Test and Cygwin
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=gnu++0x")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp src/alogrithms/MinimumSearch.h src/alogrithms/SelectionSort.h src/measurement/ArrayUtilities.h)
add_executable(opl ${SOURCE_FILES})

add_subdirectory(test)