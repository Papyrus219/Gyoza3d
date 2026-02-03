cmake_minimum_required(VERSION 3.10)

project(gyoza)

add_executable(gyoza main.cpp)

install(TARGETS gyoza RUNTIME DESTINATION bin)
