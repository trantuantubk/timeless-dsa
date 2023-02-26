cmake_minimum_required(VERSION 3.10)
project(editDistance)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED false)

#set source file
set(SOURCES
    src/editDistance.cpp
)
# add the executable
add_executable(editDistance ${SOURCES})
