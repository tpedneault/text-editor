#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold shader program information
typedef struct {
  GLuint programID;
  GLuint vertexShaderID;
  GLuint fragmentShaderID;
} ShaderProgram;

// Function to initialize the renderer
void renderer_init(const char* vertexShaderSource, const char* fragmentShaderSource);

// Function to clean up resources used by the renderer
void renderer_shutdown();

// Function to compile and link shaders
ShaderProgram* shaderProgram_create(const char* vertexSource, const char* fragmentSource);

// Function to clean up shader program
void shaderProgram_destroy(ShaderProgram* program);

#endif // RENDERER_H
