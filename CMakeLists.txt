cmake_minimum_required(VERSION 3.5)
project(STLStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(STLStudy ${SOURCE_FILES})

add_subdirectory(STLPuzzlingConfig)
add_subdirectory(OtherPuzzlingPoints)
add_subdirectory(Allocator)