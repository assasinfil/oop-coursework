cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(coursework main.cpp graph.cpp graph.h)
file(COPY ${PROJECT_SOURCE_DIR}/input.txt
        DESTINATION ${PROJECT_BINARY_DIR})