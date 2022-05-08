# Function for automatic recursive discovery of tests.
function(create_tests LIBRARIES_EX INCLUDES_EX)
    message(STATUS "")
    message(STATUS "Automatic test discovery for ${PROJECT_NAME}")
    list(APPEND CMAKE_MESSAGE_INDENT "  ")
    # ------------------------------------------------------------------------
    message(
        STATUS "Searching for test files in ${CMAKE_CURRENT_SOURCE_DIR}/tests")
    # Recursively acquire all test file paths from root folder.
    file(GLOB_RECURSE test_files
         "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_*.cpp")
    # ------------------------------------------------------------------------
    list(LENGTH test_files NUMBER_OF_TEST_FILES)
    message(STATUS "Found total of ${NUMBER_OF_TEST_FILES} test files.")

    # iterate all acquired paths and create executables for them
    foreach(file ${test_files})

        get_filename_component(TEST_NAME "${file}" NAME_WLE)

        # ensure we are not using empty match
        if(NOT ${TEST_NAME} STREQUAL "")
            # create target name with project name prefix
            set(TEST_TARGET_SYMBOL "${PROJECT_NAME}_${TEST_NAME}")
            message(
                STATUS
                    "- Creating tests out of ${file} with symbol ${TEST_TARGET_SYMBOL}"
            )
            list(APPEND CMAKE_MESSAGE_INDENT "  ")
            add_executable(${TEST_TARGET_SYMBOL} "${file}")

            # ----------------------------------------------------------------
            # add includes cumultated for logging
            set(TEST_INCLUDES
                ${ROOT}/include ${ROOT_DIRECTORY_EXTERNAL}/googletest/include
                ${INCLUDES_EX})

            message(STATUS "Includes for test: ${TEST_INCLUDES}")
            target_include_directories(${TEST_TARGET_SYMBOL}
                                       PRIVATE ${TEST_INCLUDES})
            # ----------------------------------------------------------------
            # add libraries cumultated for logging
            set(TEST_LIBRARIES gtest_main ${LIBRARIES_EX})

            message(STATUS "Libraries for test: ${TEST_LIBRARIES}")
            target_link_libraries(${TEST_TARGET_SYMBOL}
                                  PRIVATE ${TEST_LIBRARIES})
            # ----------------------------------------------------------------
            # use GoogleTest function to discover tests
            gtest_discover_tests(${TEST_TARGET_SYMBOL})

            message(STATUS "")
            list(POP_BACK CMAKE_MESSAGE_INDENT)
        endif()

    endforeach()
    list(POP_BACK CMAKE_MESSAGE_INDENT)
endfunction(create_tests)
