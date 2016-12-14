project(test)

add_subdirectory(lib/gtest-1.8.0)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests
        MinimumSearchTest.cpp
        SelectionSortTest.cpp
        InsertionSortTest.cpp
        QuickSortTest.cpp
        MergeSortTest.cpp

        #../src/alogrithms/SelectionSort.h
        #../src/alogrithms/InsertionSort.h
        #../src/alogrithms/MergeSort.h
        #../src/alogrithms/QuickSort.h
        )

target_link_libraries(runUnitTests gtest gtest_main)

