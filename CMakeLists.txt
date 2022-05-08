cmake_minimum_required(VERSION 3.19)
cmake_policy(SET CMP0048 NEW)
project(
    scftolus_root_project
    VERSION "1.0.0"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ROOT_DIRECTORY_EXTERNAL "${PROJECT_SOURCE_DIR}/external")

# google test library setup
set(GOOGLETEST_DIRECTORY "${ROOT_DIRECTORY_EXTERNAL}/googletest")
add_subdirectory(${GOOGLETEST_DIRECTORY})
message(STATUS "GoogleTest is included for testing purposes.")
enable_testing()
include(GoogleTest)

include(cmake/discovery.cmake)

# Implementation library
add_subdirectory("libraries/scftolus")

# Entry point executable
add_executable(scftolus_ext "${PROJECT_SOURCE_DIR}/source/main.cpp")

target_link_libraries(scftolus_ext PRIVATE scftolus_static)
target_include_directories(
    scftolus_ext PRIVATE "${PROJECT_SOURCE_DIR}/libraries/scftolus/include")
