cmake_minimum_required(VERSION 3.16)
project(StableMatching)

set(CMAKE_CXX_STANDARD 14)

add_executable(StableMatching main.cpp Element.cpp Element.h StableMatchSet.cpp StableMatchSet.h SetOfElements.cpp SetOfElements.h)
