project(test)

# Für die Tests müssen diese Compiler-Flags verwendet werden, da
# Google Tests sonst fehler wirft.
set(CMAKE_CXX_FLAGS "${EXTERN_CMAKE_CXX_FLAGS}  -std=gnu++14")

add_subdirectory(lib/gtest-1.8.0)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests
        util/TypedArrayTest.cpp
        util/SimpleArrays.h
        MinimumSearchTest.cpp
        SelectionSortTest.cpp
        InsertionSortTest.cpp
        QuickSortTest.cpp
        MergeSortTest.cpp
        TypedMinimumSearchTest.cpp
        TypedSelectionSortTest.cpp
        TypedInsertionSortTest.cpp
        TypedMergeSortTest.cpp
        TypedQuickSortTest.cpp)

target_link_libraries(runUnitTests gtest gtest_main)

