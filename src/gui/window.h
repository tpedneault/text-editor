#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

typedef struct {
    uint8_t width;
    uint8_t height;
    const char* title;
    bool isInit;
} WindowModuleState;

typedef struct {
    uint8_t width;
    uint8_t height;
    const char* title;
} WindowProps;

/// @brief Initializes the libraries required for the window system.
void window_init_libraries(void);

/// @brief Creates a window with the specified properties.
void window_create(WindowProps);

#endif // WINDOW_H