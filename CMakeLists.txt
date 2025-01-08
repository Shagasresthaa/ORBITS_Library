# Specify the minimum CMake version and project details
cmake_minimum_required(VERSION 3.10)
project(ORBITS_Library)
set(CMAKE_CXX_STANDARD 17)

# Include directories for header files
include_directories(include)

# Add executable target with all source files
add_executable(main
    src/main.cpp
    src/body.cpp
    src/cartesian_helper.cpp
    src/orbital_parameters.cpp
)
