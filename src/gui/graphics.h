#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GL/glew.h>

#include "renderer.h"

void graphics_drawRectangle(float x, float y, float width, float height, float r, float g, float b, float a);
void graphics_drawText(const char* text, float x, float y, float scale, float r, float g, float b);

#endif // GRAPHICS_H