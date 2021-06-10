add_library(sqlite3 sqlite3.c)

add_compile_options(-DSQLITE_ENABLE_FTS5)

target_link_libraries(sqlite3 pthread dl m)

target_include_directories(sqlite3 PRIVATE ${PROJECT_SOURCE_DIR}/sqlite3)
