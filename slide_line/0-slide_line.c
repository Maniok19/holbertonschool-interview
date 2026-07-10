#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers (2048 game mechanics)
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, pos;
    int last_merged;

    if (!line || size == 0)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        pos = 0;
        last_merged = 0;

        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (!last_merged && pos > 0 && line[pos - 1] == line[i])
                {
                    line[pos - 1] *= 2;
                    last_merged = 1;
                }
                else
                {
                    line[pos] = line[i];
                    if (pos != i)
                        line[i] = 0;
                    last_merged = 0;
                    pos++;
                }
            }
        }

        /* Fill remaining positions with zeros */
        for (i = pos; i < size; i++)
            line[i] = 0;
    }
    else if (direction == SLIDE_RIGHT)
    {
        pos = size - 1;
        last_merged = 0;

        for (i = size; i > 0; i--)
        {
            if (line[i - 1] != 0)
            {
                if (!last_merged && pos < size - 1 && line[pos + 1] == line[i - 1])
                {
                    line[pos + 1] *= 2;
                    last_merged = 1;
                }
                else
                {
                    line[pos] = line[i - 1];
                    if (pos != i - 1)
                        line[i - 1] = 0;
                    last_merged = 0;
                    pos--;
                }
            }
        }

        /* Fill remaining positions with zeros */
        for (i = 0; i <= pos; i++)
            line[i] = 0;
    }
    else
    {
        return (0);
    }

    return (1);
}