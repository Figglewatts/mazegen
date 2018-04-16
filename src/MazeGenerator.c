#include "MazeGenerator.h"
#include "Stack.h"

int directions[] = { 0, 1, 2, 3 };

int* init_maze(unsigned width, unsigned height)
{
	int* maze = (int*) malloc(width * height * sizeof(int));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			maze[y * width + x] = 1;
		}
	}

	return maze;
}

void shuffle(int* array, size_t n)
{
	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

void carve_maze(int* maze, unsigned width, unsigned height, Stack* x_stack, Stack* y_stack)
{
	while (!stack_isempty(x_stack))
	{
		shuffle(directions, NUM_DIRS);

		int x = stack_pop(x_stack);
		int y = stack_pop(y_stack);

		for (int i = 0; i < NUM_DIRS; i++)
		{
			switch (directions[i])
			{
				case 0: // up
				{
					if (y - 2 <= 0) continue;

					if (maze[(y - 2) * width + x] != 0)
					{
						maze[(y - 2) * width + x] = 0;
						maze[(y - 1) * width + x] = 0;
						stack_push(x_stack, x);
						stack_push(y_stack, y - 2);
					}
					break;
				}
				case 1: // right
				{
					if (x + 2 >= width - 1) continue;

					if (maze[y * width + x + 2] != 0)
					{
						maze[y * width + x + 2] = 0;
						maze[y * width + x + 1] = 0;
						stack_push(x_stack, x + 2);
						stack_push(y_stack, y);
					}
					break;
				}
				case 2: // down
				{
					if (y + 2 >= height - 1) continue;

					if (maze[(y + 2) * width + x] != 0)
					{
						maze[(y + 2) * width + x] = 0;
						maze[(y + 1) * width + x] = 0;
						stack_push(x_stack, x);
						stack_push(y_stack, y + 2);
					}
					break;
				}
				case 3: // left
				{
					if (x - 2 <= 0) continue;

					if (maze[y * width + x - 2] != 0)
					{
						maze[y * width + x - 2] = 0;
						maze[y * width + x - 1] = 0;
						stack_push(x_stack, x - 2);
						stack_push(y_stack, y);
					}
					break;
				}
			}
		}
	}
}

int* generate_maze(unsigned width, unsigned height)
{
	int* maze = init_maze(width, height);
	if (!maze) return NULL;

	Stack* x_stack = stack_create(32);
	Stack* y_stack = stack_create(32);

	// start in top left
	int x = 1;
	int y = 1;

	stack_push(x_stack, x);
	stack_push(y_stack, y);

	maze[y * width + x] = 0; // start cell

	carve_maze(maze, width, height, x_stack, y_stack);

	free(x_stack);
	free(y_stack);

	return maze;
}