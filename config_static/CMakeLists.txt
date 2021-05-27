cmake_minimum_required(VERSION 3.19)
project(config_static)

set(CMAKE_CXX_STANDARD 20)

add_library(config_static
        libconfig.cpp libconfig.h
        config_part.cpp config_part.h
        config_file.cpp config_file.h
        utils.cpp utils.h
        config_value.cpp config_value.h
        config_file_c.cpp config_file_c.h
        config_part_c.cpp config_part_c.h
        config_value_c.cpp config_value_c.h)