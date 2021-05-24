cmake_minimum_required(VERSION 3.20)

project(orc)

set(plugin_file ${CMAKE_CURRENT_LIST_DIR}/PluginOrc.txt)
set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED true)
set(CXX_EXTENSIONS false)
add_compile_options(-DLINUX -Wall -D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(include ../include)
link_directories(lib/linux ${CMAKE_BINARY_DIR})

add_library(PluginOrc SHARED src/orc_plugin.cpp)
target_link_libraries(PluginOrc orc protobuf snappy lz4 z zstd hdfspp_static pthread sasl2 crypto DolphinDB)

add_custom_command(
    TARGET PluginOrc POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy ${plugin_file} ${CMAKE_BINARY_DIR}/PluginOrc.txt
    COMMENT "copy PluginOrc.txt"
)
