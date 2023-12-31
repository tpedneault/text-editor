#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>

typedef struct {
	float x, y; // Position
	float width, height; // Size
	char* label; // Label
	bool isHovered; // Is the button being hovered?
	bool isPressed; // Is the button being pressed?
	void (*onClick)(void); // Callback 
} Button;

void button_draw(Button* button);
void button_update(Button* button, float mouseX, float mouseY, bool mousePressed);

#endif // BUTTON_H