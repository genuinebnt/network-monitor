cmake_minimum_required(VERSION 4.0.1)

project(network-monitor)

# Set CMake policy for Conan compatibility
if(POLICY CMP0167)
   cmake_policy(SET CMP0167 OLD)
endif()

# Set policy needed for Conan Modern CMake integration
if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()

set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Boost using Conan-generated config
find_package(Boost REQUIRED COMPONENTS system)

add_executable(network-monitor ${SOURCES})

target_compile_features(network-monitor PRIVATE cxx_std_11)

# Link against Boost system component
target_link_libraries(network-monitor PRIVATE Boost::system)

# Output helpful info about where CMake is searching for packages
message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
