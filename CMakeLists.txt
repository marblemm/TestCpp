cmake_minimum_required(VERSION 2.8)
project(TestCpp)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(thread)
add_subdirectory(singleton)
add_subdirectory(chrono)
