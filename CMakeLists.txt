cmake_minimum_required(VERSION 3.5)

add_library(clogger clogger.h clogger.c)
target_include_directories(clogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})