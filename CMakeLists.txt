cmake_minimum_required(VERSION 3.15...4.1)

project(CppSTG VERSION 1.0 LANGUAGES CXX)

find_package(SDL3 REQUIRED CONFIG)

add_executable(CppSTG main.cpp)
target_link_libraries(CppSTG PRIVATE SDL3::SDL3)