cmake_minimum_required(VERSION 3.23)
project(lms)

set(CMAKE_CXX_STANDARD 17)

include_directories(json/include)

add_executable(lms main.cpp Book.cpp Book.h)

