cmake_minimum_required(VERSION 3.26)
project(shizuku_kernel CXX)
add_subdirectory(lib)
add_library(shizuku_kernel OBJECT)
target_include_directories(shizuku_kernel PRIVATE include)
target_include_directories(shizuku_kernel PUBLIC interface)
add_subdirectory(src)