project(Google_benchmarks)

SET(BENCHMARK_ENABLE_TESTING OFF)
SET(BENCHMARK_ENABLE_GTEST_TESTS OFF)
SET(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF)

include(FetchContent)
FetchContent_Declare(gb # for shorting path. Google benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG master)

FetchContent_MakeAvailable(gb)

include_directories(${benchmark_SOURCE_DIR}/include ${benchmark_SOURCE_DIR})
include_directories(${DataStructuresAndAlgorithms_SOURCE_DIR}/DataStructures
        ${DataStructuresAndAlgorithms_SOURCE_DIR}/Algorithms)

add_executable(Google_benchmarks_run
        Benchmarks/StringBenchmarks.cpp)
target_link_libraries(Google_benchmarks_run benchmark::benchmark DataStructuresAndAlgorithms_lib)