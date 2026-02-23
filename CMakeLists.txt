cmake_minimum_required(VERSION 3.28)
project(cppstg)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(cppstg main.cpp)
target_link_libraries(cppstg PRIVATE SDL3::SDL3)