project(test)

add_subdirectory(lib/gtest-1.8.0)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests
        MinimumSearchTest.cpp ../src/alogrithms/SelectionSort.h
        SelectionSortTest.cpp  ../src/measurement/ArrayUtilities.h ../src/alogrithms/InsertionSort.h ArrayTests.h
        InsertionSortTest.cpp ../src/alogrithms/MergeSort.h)

target_link_libraries(runUnitTests gtest gtest_main)

