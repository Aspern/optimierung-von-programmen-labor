cmake_minimum_required(VERSION 3.6)
project(opl)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXTERN_CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Vraussetzungen für das Projekt:
#   - Ohne Debuginformationen Zeit messen: -g0
#   - höchste Optimierstufe hinsichtlich Performanz: -O3
#   - Alle Warnungen anschalten und als Fehler behandeln: -Wpedantic -Werror
#
set(CMAKE_CXX_FLAGS "${EXTERN_CMAKE_CXX_FLAGS} -std=c++14 -g0 -O3 -Wall -Wpedantic -Werror")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

option(BUILD_TESTS "Build tests" OFF)

set(SOURCE_FILES main.cpp
        src/algorithm/MinimumSearch.h
        src/algorithm/SelectionSort.h
        src/algorithm/InsertionSort.h
        src/algorithm/MergeSort.h
        src/algorithm/QuickSort.h
        src/runtime/Constants.h
        src/util/Chronometry.h
        src/util/ArrayTools.h
)

add_executable(opl ${SOURCE_FILES})

if (BUILD_TESTS)
    add_subdirectory(test)
endif ()