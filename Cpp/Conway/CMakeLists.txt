cmake_minimum_required(VERSION 3.10)

project(conway)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)
set(CXX_EXTENSIONS false)

include_directories(include)
add_subdirectory(src)
add_executable(conway main.cpp)
target_link_libraries(conway game)


