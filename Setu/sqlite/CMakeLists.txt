add_library(sqlite SHARED sqlite3.c)

add_compile_definitions(
    SQLITE_OMIT_LOAD_EXTENSION
    SQLITE_THREADSAFE=2
)

target_link_libraries(sqlite pthread)

target_include_directories(sqlite PUBLIC ${CMAKE_SOURCE_CURRENT_DIR})

