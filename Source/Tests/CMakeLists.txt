project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${DataStructuresAndAlgorithms_SOURCE_DIR}/DataStructures ${DataStructuresAndAlgorithms_SOURCE_DIR}/Algorithms)

add_executable(Google_Tests_run
        StringTests/StringTests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main DataStructuresAndAlgorithms_lib)