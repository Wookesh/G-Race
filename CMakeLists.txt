cmake_minimum_required(VERSION 2.8.11)

project(G-Race)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -ggdb")
set(EXECUTABLE_OUTPUT_PATH "${G-Race_SOURCE_DIR}/build/bin/")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
add_subdirectory(src)