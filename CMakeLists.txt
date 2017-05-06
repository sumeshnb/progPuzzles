cmake_minimum_required(VERSION 3.3)
project(cprograms)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY /Users/sumesh/Dropbox/cprograms)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /Users/sumesh/Dropbox/cprograms)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /Users/sumesh/Dropbox/cprograms)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES   copy_constructor.cpp)
add_executable(cprograms ${SOURCE_FILES})