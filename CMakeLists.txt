cmake_minimum_required(VERSION 3.17)
project(oop_kursach)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(oop-kursach main.cpp graph.cpp graph.h vertex.cpp vertex.h edge.cpp edge.h)
