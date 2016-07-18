cmake_minimum_required(VERSION 3.5)
project(viewr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    filetype.c
    filetype.h
    pandoc.c
    pandoc.h)

add_executable(viewr ${SOURCE_FILES})