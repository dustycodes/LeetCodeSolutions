if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree built. This is bad practice.")
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

########################################################################
# LeetCode Base
########################################################################
cmake_minimum_required(VERSION 2.8.9)
project(GenericSensorAPI CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE=Debug)
set(CMAKE_CXX_FLAGS "-Wall -Wno-reorder -std=c++11 -g")

set (BASE_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

########################################################################
# TwoSum https://leetcode.com/problems/two-sum/description/
########################################################################
include_directories (
    ${BASE_INCLUDES}
)

file(GLOB TWO_SUM_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/TwoSum.cpp
)

add_executable(TwoSum
  ${TWO_SUM_SRC}
)
