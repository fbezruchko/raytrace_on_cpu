cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(vcpkg_install)

project(raytrace_on_cpu)

#include(cmake_config)
#include(raytrace_on_cpu_config)

set(SOURCES src/vec3.cpp src/ray.cpp src/camera.cpp src/sphere.cpp src/hitableList.cpp src/main.cpp)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(raytrace_on_cpu ${SOURCES})

#VCPKG packages and libs
find_path(STB_INCLUDE_DIRS "stb.h")
#target_include_directories(raytrace_on_cpu PRIVATE ${STB_INCLUDE_DIRS})
target_include_directories(raytrace_on_cpu PRIVATE ${STB_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)