#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpile_eq - Print 3x3 grid
 * @grid1: 3x3 grid
 *
 */
void sandpile_eq(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int addgrid[3][3];

	for (i = 0; i < 3; i++)
	for (j = 0; j < 3; j++)
		addgrid[i][j] = grid1[i][j];

	for (i = 0; i < 3; i++)
	{
		j = 0;
		for (j = 0; j < 3; j++)
		{
			if (addgrid[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if ((i + 1) < 3)
					grid1[i + 1][j] += 1;
				if ((i - 1) >= 0)
					grid1[i - 1][j] += 1;
				if ((j + 1) < 3)
					grid1[i][j + 1] += 1;
				if ((j - 1) >= 0)
					grid1[i][j - 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Print 3x3 grid
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;
	int ctrl = 0;

	for (i = 0; i < 3; i++)
	{
		j = 0;
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				ctrl = 1;
		}
	}
	while (ctrl == 1)
	{
	
		printf("=\n");
		print_grid(grid1);
		sandpile_eq(grid1);
		ctrl = 0;
		for (i = 0; i < 3; i++)
		{
			j = 0;
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					ctrl = 1;
			}
		}
	}
}
