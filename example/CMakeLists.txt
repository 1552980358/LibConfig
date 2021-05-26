cmake_minimum_required(VERSION 3.19)
project(example)

set(CMAKE_CXX_STANDARD 20)

include_directories(library)
link_directories(library)
link_libraries(libconfig_static.a)

add_executable(example main.cpp)

target_link_libraries(example libconfig_static.a)