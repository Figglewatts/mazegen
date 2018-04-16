cmake_minimum_required(VERSION 3.1)
project(mazegen)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(mazegen ${SOURCES})