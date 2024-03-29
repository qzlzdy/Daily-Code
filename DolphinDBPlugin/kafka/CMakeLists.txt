cmake_minimum_required(VERSION 3.0)
project(kafka)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (WIN32)
    set(platform_macro "-DWINDOWS")
    set(plugin_file "${CMAKE_CURRENT_LIST_DIR}/PluginKafka.txt")
elseif (UNIX)
    set(platform_macro "-DLINUX")
    set(plugin_file "${CMAKE_CURRENT_LIST_DIR}/PluginKafka.txt")
    add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
endif ()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${platform_macro} -fPIC -std=c++11 -Wall -rdynamic ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG -fPIC -std=c++11 -Wall -rdynamic ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -std=c++11 -Wall -rdynamic ")

link_directories(${CMAKE_BINARY_DIR})
include_directories(../include ./include)
link_directories(./lib/linux)

aux_source_directory("./src" plugin_kafka_src)
#aux_source_directory("./cppkafka/src" cppkafka)

#add_subdirectory(cppkafka)

add_library(PluginKafka SHARED ${plugin_kafka_src})
target_link_libraries(PluginKafka librdkafka-static.a librdkafka++.a libcppkafka.a libavrocpp_s.a libz.a libboost_iostreams.a libsnappy.a DolphinDB)
#target_link_libraries(PluginKafka rdkafka++ cppkafka DolphinDB)