cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(vcpkg_install)

project(raytrace_on_cpu)

#include(cmake_config)
#include(raytrace_on_cpu_config)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(raytrace_on_cpu src/main.cpp)

#VCPKG packages and libs
find_path(STB_INCLUDE_DIRS "stb.h")
target_include_directories(raytrace_on_cpu PRIVATE ${STB_INCLUDE_DIRS})