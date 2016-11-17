cmake_minimum_required(VERSION 3.6)
project(P6ED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Gitcode.h Gitcode.cpp fecha.cpp fecha.h Fichero.h Commit.h )
add_executable(P6ED ${SOURCE_FILES})