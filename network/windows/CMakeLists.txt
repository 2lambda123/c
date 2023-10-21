cmake_minimum_required(VERSION 3.26)
project(network_basic C)

set(CMAKE_C_STANDARD 11)

link_libraries(ws2_32)

add_executable(network_basic server.c)
