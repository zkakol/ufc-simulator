cmake_minimum_required(VERSION 3.3)
project(ufc-simulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(simulator ${SOURCE_FILES})