cmake_minimum_required(VERSION 3.19)
project(config_static)

set(CMAKE_CXX_STANDARD 20)

add_library(config_static libconfig.cpp libconfig.h)