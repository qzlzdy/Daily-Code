cmake_minimum_required(VERSION 3.25)

project(setu)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILE_LAUNCHER ccache)

add_compile_options(-Wall)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(sqlite)
add_subdirectory(src)

