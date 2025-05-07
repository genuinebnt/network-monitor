cmake_minimum_required(VERSION 3.17)
project(network_monitor)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
