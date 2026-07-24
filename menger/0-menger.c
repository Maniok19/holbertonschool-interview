#include <stdio.h>
#include "menger.h"

/**
 * menger - Entry point
 *
 * @level: kjfgsekhb
 *
 * Return: setgrshdh
 */
void menger(int level)
{
	if (level < 0)
		return;

	int size = 1;
	int i = 0;
	int j = 0;
	int x;
	int y;
	char c = '#';

	for (i = 0; i < level; i++)
	{
		size *= 3;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			c = '#';
			x = i;
			y = j;
			while (x > 0 && y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					c = ' ';
					break;
				}
				x /= 3;
				y /= 3;
			}
			putchar(c);
		}
		if (i != size - 1)
			printf("\n");
	}
	printf("\n");
}
