project(Google_benchmarks)

include(FetchContent)
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG master)

FetchContent_MakeAvailable(googlebenchmark)

include_directories(${benchmark_SOURCE_DIR}/include ${benchmark_SOURCE_DIR})
include_directories(${DataStructuresAndAlgorithms_SOURCE_DIR}/DataStructures
                    ${DataStructuresAndAlgorithms_SOURCE_DIR}/Algorithms)

add_executable(Google_benchmarks_run
        Benchmarks/StringBenchmarks.cpp)
target_link_libraries(Google_benchmarks_run benchmark::benchmark DataStructuresAndAlgorithms_lib)