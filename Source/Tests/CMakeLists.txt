project(Google_tests)

include(FetchContent)
FetchContent_Declare(gt # for shorting path. Google tests
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip)

FetchContent_MakeAvailable(gt)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${DataStructuresAndAlgorithms_SOURCE_DIR}/DataStructures
        ${DataStructuresAndAlgorithms_SOURCE_DIR}/Algorithms)

add_executable(Google_Tests_run
        StringTests/StringTests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main DataStructuresAndAlgorithms_lib)