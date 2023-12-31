#include "graphics.h"

extern ShaderProgram* shaderProgram;
extern GLuint vao, vbo;

void graphics_drawRectangle(float x, float y, float width, float height, float r, float g, float b, float a) {
  // Rectangle vertices (x, y, r, g, b, a)
  GLfloat vertices[] = {
      x, y, r, g, b, a,
      x + width, y, r, g, b, a,
      x, y + height, r, g, b, a,
      x, y + height, r, g, b, a,
      x + width, y, r, g, b, a,
      x + width, y + height, r, g, b, a
  };

  // Use shader program
  glUseProgram(shaderProgram->programID);

  // Assuming you have VAO and VBO already created and set up for this purpose
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  // Update buffer data
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

  // Assuming position attribute is at location 0 and color attribute is at location 1
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);

  // Draw the rectangle
  glDrawArrays(GL_TRIANGLES, 0, 6);

  // Unbind VAO
  glBindVertexArray(0);
}