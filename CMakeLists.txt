cmake_minimum_required(VERSION 3.10)

project(text-editor C)

# Only build the GLFW library.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Add build dependencies.
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glew-cmake)
add_subdirectory(vendor/glm)

# Include the source and header files
include_directories(src)

# Glob source files from src directory
file(GLOB_RECURSE editor_src "src/*.c")

# Create the main executable
add_executable(text-editor ${editor_src} "src/gui/button.h" "src/gui/button.c" "src/gui/graphics.h")
target_link_libraries(text-editor ${OPENGL_LIBRARIES} glfw libglew_static glm)