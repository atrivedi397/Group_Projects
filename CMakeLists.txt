CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(Group_Projects)

set(CMAKE_CXX_STANDARD 17)

set(BUILD1 Simplex)
set(BUILD1_FILES main.cpp simplex.h)
add_executable(${BUILD1}  ${BUILD1_FILES})