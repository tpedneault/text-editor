cmake_minimum_required(VERSION 3.10)

project(text-editor C)

# Include the source and header files
include_directories(src)

# Glob source files from src directory
file(GLOB_RECURSE editor_src "src/*.c")

# Create a library for the reusable code (e.g., vector)
# Assuming 'vector.c' is part of your editor_src
add_library(editor_lib ${editor_src})

# Create the main executable
add_executable(text-editor ${editor_src})
target_link_libraries(text-editor editor_lib)

# Enable CTest testing
enable_testing()

# Include the vendor and tests directories
include_directories(vendor)
include_directories(tests)

# Glob test source files from tests directory
file(GLOB_RECURSE test_src "tests/*.c")

# For each test source file, create a test executable and add it as a test
foreach(testfile ${test_src})
    get_filename_component(testname ${testfile} NAME_WE)
    add_executable(${testname} ${testfile})
    target_link_libraries(${testname} editor_lib) # Link test with the library
    add_test(NAME ${testname} COMMAND ${testname})
endforeach()
