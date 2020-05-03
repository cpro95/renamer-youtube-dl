# Example CMake file for compiling & linking a project with the the SQLiteCpp wrapper
#
# Copyright (c) 2012-2020 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 
cmake_minimum_required(VERSION 3.1) # for "CMAKE_CXX_STANDARD" version
project(renamer-youtube-dl VERSION 2.0)

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

# SQLiteC++ 3.x now requires C++11 compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# add library myStringLIB
set(myLib myStringLib
)
add_library(${myLib} STATIC
    ${CMAKE_SOURCE_DIR}/src/lib/myStringLib.cpp
)

target_include_directories(${myLib}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/lib
    ${CMAKE_SOURCE_DIR}/external
)

# Add main.cpp example source code to the executable
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${myLib}
)

add_subdirectory(test)