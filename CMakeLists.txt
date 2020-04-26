cmake_minimum_required(VERSION 3.15)
project(PA9)

set(CMAKE_CXX_STANDARD 20)

#set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML REQUIRED COMPONENTS audio graphics window system main)
#if (NOT SFML_FOUND)
#    message(FATAL_ERROR "SFML could not be located")
#endif ()

add_executable(PA9 main.cpp dodger.cpp dodger.h entities.cpp entities.h)