cmake_minimum_required(VERSION 3.16)
project(DeltixTestTask)

set(CMAKE_CXX_STANDARD 11)

add_executable(DeltixTestTask SimpleTest/SimpleTest.cpp DiffProcessor/Processor.cpp
        DiffProcessor/Processor.h DiffProcessor/SortedLimitedList.h)