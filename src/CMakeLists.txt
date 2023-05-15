cmake_minimum_required(VERSION 3.8)

set(PATH ${CMAKE_SOURCE_DIR}/incl)
add_executable (Ex2 Classes3.1ex.cpp ${PATH}/Classes3.1ex.h)

target_include_directories(Ex2 PUBLIC ${PATH})