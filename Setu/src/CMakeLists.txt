add_executable(encode encode.cpp)

include_directories(${CMAKE_SOURCE_DIR}/sqlite)

add_executable(pretty pretty.cpp)
target_link_libraries(pretty sqlite)

add_executable(dbinit dbinit.cpp)
target_link_libraries(dbinit sqlite)
