#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Stack.h"

#define NUM_DIRS 4

int* init_maze(unsigned width, unsigned height)
{
	/*if (!(width % 2) || !(height % 2))
	{
		printf("Width/height must be odd");
		return NULL;
	}*/

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

int directions[] = { 0, 1, 2, 3 };
void carve_maze(int x, int y, int* maze, unsigned width, unsigned height)
{
	shuffle(directions, NUM_DIRS);

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
					carve_maze(x, y - 2, maze, width, height);
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
					carve_maze(x + 2, y, maze, width, height);
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
					carve_maze(x, y + 2, maze, width, height);
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
					carve_maze(x - 2, y, maze, width, height);
				}
				break;
			}
		}
	}
}

int* generate_maze(unsigned width, unsigned height)
{
	int* maze = init_maze(width, height);
	if (!maze) return NULL;

	// start in top left
	int x = 1;
	int y = 1;

	maze[y * width + x] = 0; // start cell

	carve_maze(x, y, maze, width, height);
	return maze;
}

void print_maze(int* maze, unsigned width, unsigned height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (maze[y * width + x] != 0) printf("#");
			else printf(".");
		}
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));
	
	int* maze = generate_maze(45, 45);
	print_maze(maze, 45, 45);

	return 0;
}