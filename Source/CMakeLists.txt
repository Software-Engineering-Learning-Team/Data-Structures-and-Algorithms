cmake_minimum_required(VERSION 3.20)

project(DataStructuresAndAlgorithms)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif ()

set(SOURCES
        DataStructures/String/String.hpp
        DataStructures/String/String.cpp
        DataStructures/String/StringIterator.hpp

        Algorithms/Copying/Copying.tpp)

add_executable(DataStructuresAndAlgorithms main.cpp ${SOURCES})
add_library(DataStructuresAndAlgorithms_lib ${SOURCES})
add_subdirectory(Tests)


