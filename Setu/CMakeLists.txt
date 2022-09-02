cmake_minimum_required(VERSION 3.23)

project(setu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILE_LAUNCHER ccache)

add_compile_options(-Wall -Wpedantic)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(sqlite)
add_subdirectory(src)
