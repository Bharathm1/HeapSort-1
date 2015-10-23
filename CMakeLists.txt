cmake_minimum_required(VERSION 3.3)
project(Heap_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Heap.cpp Heap.h)
add_executable(Heap_Sort ${SOURCE_FILES})