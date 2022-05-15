cmake_minimum_required(VERSION 3.19)
project(scftolus_library_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/external/CLI11")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/spdlog")
add_subdirectory("${PROJECT_SOURCE_DIR}/external/fmtlib")

# --------------------------------------------------------------------------
# create scftolus library binary
# --------------------------------------------------------------------------
file(GLOB_RECURSE scftolus_SOURCE "${PROJECT_SOURCE_DIR}/source/*.c*")

# https://pugixml.org/docs/manual.html https://pugixml.org/docs/quickstart.html

add_library(
    scftolus_static STATIC
    "${scftolus_SOURCE}"
    "${PROJECT_SOURCE_DIR}/external/pugixml/src/pugixml.cpp")
# Ensure that output static lib can be embedded into dynamic libraries
set_property(TARGET scftolus_static PROPERTY POSITION_INDEPENDENT_CODE ON)

set(scftolus_INCLUDE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/external/pugixml/src"
    "${PROJECT_SOURCE_DIR}/external/spdlog/include"
    "${PROJECT_SOURCE_DIR}/external/fmtlib/include")
target_include_directories(scftolus_static PUBLIC ${scftolus_INCLUDE})
# Placecholder for possible dependency libraries
set(scftolus_EXT_LIBS CLI11::CLI11)
target_link_libraries(scftolus_static "${scftolus_EXT_LIBS}")

# ----------------------------------------------------------------------------
# create test suite for scftolus
# ----------------------------------------------------------------------------

set(scftolus_TEST_LIBS scftolus_static "${scftolus_EXT_LIBS}")

create_tests("${scftolus_TEST_LIBS}" ${scftolus_INCLUDE})
