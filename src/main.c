#include <stdio.h>
#include <time.h>

#include "MazeGenerator.h"

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