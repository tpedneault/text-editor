#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "gui/renderer.h"
#include "gui/graphics.h"
#include "utils/vector.h"

const char* vertexShaderSource =
	"#version 330 core\n"
	"layout (location = 0) in vec2 aPos;\n"
	"layout (location = 1) in vec3 aColor;\n"
	"out vec3 ourColor;\n"
	"void main() {\n"
	"   gl_Position = vec4(aPos, 0.0, 1.0);\n"
	"   ourColor = aColor;\n"
	"}\n";

const char* fragmentShaderSource =
	"#version 330 core\n"
	"in vec3 ourColor;\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	"   FragColor = vec4(ourColor, 1.0);\n"
	"}\n";

void window_glfwErrorCallback(int error, const char* description) {
	fprintf(stderr, description);
}

void window_framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char** argv) {
	glfwSetErrorCallback(window_glfwErrorCallback);
	
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW.");
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Text Editor", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to create GLFW window.");
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// Set the viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, window_framebufferResizeCallback);

	// Initialize GLEW
	glewExperimental = GL_TRUE; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW.");
		return 1;
	}

	renderer_init(vertexShaderSource, fragmentShaderSource);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Rendering happens here.
		graphics_drawRectangle(-1.0f, 1.0f, 0.5f, -2.0f, 1.0f, 0.0f, 0.0f, 1.0f);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}