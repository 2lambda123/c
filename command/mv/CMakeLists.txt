# cmake .
cmake_minimum_required(VERSION 3.22)
project(. C)

set(CMAKE_C_STANDARD 11)

# /bin 디렉토리에 생성
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# add_executable()의 첫번째 인자는 CMAKE_RUNTIME_OUTPUT_DIRECTORY에 생성될 파일명
add_executable(mv mv.c)

