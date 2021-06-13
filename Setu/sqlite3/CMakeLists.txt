add_library(sqlite3 SHARED sqlite3.c)

add_compile_definitions(SQLITE_THREADSAFE=2)

target_link_libraries(sqlite3 pthread dl m)

target_include_directories(sqlite3 PRIVATE ${PROJECT_SOURCE_DIR}/sqlite3)
