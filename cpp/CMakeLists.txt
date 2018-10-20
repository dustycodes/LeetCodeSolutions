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
set (TARGET_NAME TwoSum)
include_directories (
    ${BASE_INCLUDES}
)

file(GLOB TWO_SUM_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/TwoSum.cpp
)

add_executable(${TARGET_NAME}
  ${TWO_SUM_SRC}
)

########################################################################
# AddTwoNumbers https://leetcode.com/problems/add-two-numbers/description/
########################################################################
set (TARGET_NAME AddTwoNumbers)
include_directories (
    ${BASE_INCLUDES}
)

file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AddTwoNumbers.cpp
)

add_executable(${TARGET_NAME}
  ${SRC}
)

########################################################################
# LengthOfLongestSubstring https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
########################################################################
set (TARGET_NAME LengthOfLongestSubstring)
include_directories (
    ${BASE_INCLUDES}
)

file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LongestSubstring.cpp
)

add_executable(${TARGET_NAME}
  ${SRC}
)
