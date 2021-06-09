cmake_minimum_required(VERSION 3.10)

project(rabbitmq)

if(WIN32)
    set(platform_macro "-DWINDOWS")
    set(plugin_file "PluginRabbitMQ_win.txt")
elseif(UNIX)
    set(platform_macro "-DLINUX")
    set(plugin_file "PluginRabbitMQ.txt")
endif()
add_compile_options(-std=c++11 -fPIC ${platform_macro} -Wall -g)

include_directories(../include include)
link_directories(${CMAKE_BINARY_DIR} lib)
aux_source_directory(src PluginSrc)

add_library(PluginRabbitMQ SHARED ${PluginSrc})
target_link_libraries(PluginRabbitMQ amqpcpp event pthread dl ssl protobuf DolphinDB)

add_custom_command(
    TARGET PluginRabbitMQ POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/${plugin_file} ${CMAKE_BINARY_DIR}/PluginRabbitMQ.txt
    COMMENT "copy PluginRabbitMQ.txt"
)