#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Function to print a 3x3 grid.
 *
 * @grid: The 3x3 grid to be printed
*/
void print_grid(int grid[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
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
 * is_stable - Function to check if the sandpile grid is stable.
 *
 * @grid: The 3x3 grid to be checked
 * Return: 1 if the grid is stable, 0 otherwise
*/
int is_stable(int grid[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
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
 * topple - Function to topple the sandpile.
 *
 * @grid: The 3x3 grid to be toppled
*/
void topple(int grid[SIZE][SIZE])
{
	int i, j;
	int temp[SIZE][SIZE] = {{0}};

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
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
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Function to compute the sum of two sandpiles
 *
 * @grid1: The first 3x3 grid
 * @grid2: The second 3x3 grid
*/
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE])
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
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
