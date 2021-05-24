cmake_minimum_required(VERSION 3.0)
project(BloombergPlugin)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (WIN32)
    set(platform_macro "-DWINDOWS")
    set(plugin_file "${CMAKE_CURRENT_LIST_DIR}/PluginBloomberg.txt")
elseif (UNIX)
    set(platform_macro "-DLINUX")
    set(plugin_file "${CMAKE_CURRENT_LIST_DIR}/PluginBloomberg.txt")
    add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
endif ()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${platform_macro} -fPIC -std=c++11 -Wall -rdynamic ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fPIC -std=c++11 -Wall -rdynamic ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -std=c++11 -Wall -rdynamic ")

set(BLPAPI_VERSION "3.15.0.1")

# set the directory of BLPAPI
if(NOT BLPAPI_DIR)
    set(BLPAPI_DIR "/home/ypfan/software/blpapi_cpp_${BLPAPI_VERSION}")
endif()
set(BLPAPI_INCLUDE "${BLPAPI_DIR}/include/")
set(BLPAPI_SO "${BLPAPI_DIR}/Linux/")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include ${BLPAPI_INCLUDE})
link_directories(${CMAKE_BINARY_DIR} ${BLPAPI_SO})

aux_source_directory("./src" plugin_bloomberg_src)

add_library(PluginBloomberg SHARED ${plugin_bloomberg_src})
target_link_libraries(PluginBloomberg blpapi3_64)