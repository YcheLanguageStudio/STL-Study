cmake_minimum_required(VERSION 3.5)
project(STLStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(STLPuzzlingConfig)
add_subdirectory(OtherPuzzlingPoints)
add_subdirectory(Allocator)
add_subdirectory(Meta-Programming)
add_subdirectory(Experiments)