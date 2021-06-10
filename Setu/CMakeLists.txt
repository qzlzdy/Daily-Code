cmake_minimum_required(VERSION 3.20)

project(setu)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_ENTENSIONS OFF)

add_compile_options(-fPIC -Wall)

add_subdirectory(sqlite3)

add_executable(pretty src/pretty.cpp)

target_link_libraries(pretty sqlite3)
