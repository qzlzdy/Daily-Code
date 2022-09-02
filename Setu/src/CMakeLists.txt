add_executable(encode encode.cpp)

add_executable(pretty pretty.cpp)

target_link_libraries(pretty sqlite)

add_executable(dbinit dbinit.cpp)

target_link_libraries(dbinit sqlite)
