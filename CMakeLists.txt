cmake_minimum_required(VERSION 3.6)
project(Pointers)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")


set(SOURCE_FILES main.c)

add_executable(Intel8080Emulator ${SOURCE_FILES})