#include "renderer.h"

GLuint vao, vbo;
ShaderProgram* shaderProgram;

GLuint compileShader(const char* source, GLenum type) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		fprintf(stderr, "Shader compilation failed: %s", infoLog);
	}

	return shader;
}

GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader) {
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		fprintf(stderr, "Shader linking failed: %s", infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

void renderer_init(const char* vertexShaderSource, const char* fragmentShaderSource) {
	shaderProgram = shaderProgram_create(vertexShaderSource, fragmentShaderSource);
	glUseProgram(shaderProgram->programID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void renderer_shutdown() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	shaderProgram_destroy(shaderProgram);
}

ShaderProgram* shaderProgram_create(const char* vertexSource, const char* fragmentSource) {
	ShaderProgram* program = malloc(sizeof(ShaderProgram));
	if (!program) {
		// Handle memory allocation failure
		return NULL;
	}

	program->vertexShaderID = compileShader(vertexSource, GL_VERTEX_SHADER);
	if (program->vertexShaderID == 0) {
		// Handle vertex shader compilation failure
		free(program);
		return NULL;
	}

	program->fragmentShaderID = compileShader(fragmentSource, GL_FRAGMENT_SHADER);
	if (program->fragmentShaderID == 0) {
		// Handle fragment shader compilation failure
		glDeleteShader(program->vertexShaderID);
		free(program);
		return NULL;
	}

	program->programID = linkProgram(program->vertexShaderID, program->fragmentShaderID);
	if (program->programID == 0) {
		// Handle shader program linking failure
		glDeleteShader(program->vertexShaderID);
		glDeleteShader(program->fragmentShaderID);
		free(program);
		return NULL;
	}

	return program;
}


void shaderProgram_destroy(ShaderProgram* program) {
	glDeleteProgram(program->programID);
	free(program);
}