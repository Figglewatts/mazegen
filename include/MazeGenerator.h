#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <stdlib.h>

typedef struct Stack Stack; // forward declaration

#define NUM_DIRS 4
extern int directions[];

int* init_maze(unsigned width, unsigned height);

void shuffle(int* array, size_t n);

void carve_maze(int* maze, unsigned width, unsigned height, Stack* x_stack, Stack* y_stack);

int* generate_maze(unsigned width, unsigned height);

#endif // MAZE_GENERATOR_H
