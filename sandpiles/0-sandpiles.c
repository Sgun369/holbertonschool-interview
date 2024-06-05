#include <stdio.h>
# include "sandpiles.h"

/**
 * Function to print a 3*3 grid.
 *
 * @param grid The 3*3 grid to be printed
*/

void print_grid(int(grid[SIZE][SIZE]))
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * Function to check if the sandpile frid is stable.
 * @param grid The 3*3 grid to be checked
 * @return 1 if the grid is stable , 0 otherwise
*/
int is_stable(int grid[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > MAX_GRAINS)
			{
				return (0);
			}
		}
	}
	return (1);
}
/**
 * Function to topple the sandpile.
 *
 * @param grid The 3*3 grid to be toppled.
*/
void topple(int grid[SIZE][SIZE])
{
	int temp[SIZE][SIZE] = {0};

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > MAX_GRAINS)
			{
				temp[i][j] -= 4;
				if (i > 0)
				temp[i - 1][j] += 1;
				if (i < SIZE - 1)
				temp[i + 1][j] += 1;
                if (j > 0)
				temp[i][j - 1] += 1;
                if (j < SIZE - 1)
				temp[i][j + 1] += 1;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}
/**
 * Function to compute the sum of two sandpiles and stabilize the result.
 * 
 * @param grid1 The first 3*3 grid
 * @param grid2 The second 3*3 grid
*/
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}