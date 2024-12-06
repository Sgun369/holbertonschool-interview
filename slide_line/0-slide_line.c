#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 * Return: 1 if successful, 0 otherwise.
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, pos = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    int temp[size]; /* Temporary array for sliding */
    for (i = 0; i < size; i++)
        temp[i] = 0;

    /* Move non-zero values */
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                temp[pos++] = line[i];
    }
    else /* SLIDE_RIGHT */
    {
        pos = size - 1;
        for (i = size; i-- > 0;)
            if (line[i] != 0)
                temp[pos--] = line[i];
    }

    /* Merge adjacent equal values */
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size - 1; i++)
        {
            if (temp[i] == temp[i + 1] && temp[i] != 0)
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        for (i = size - 1; i > 0; i--)
        {
            if (temp[i] == temp[i - 1] && temp[i] != 0)
            {
                temp[i] *= 2;
                temp[i - 1] = 0;
            }
        }
    }

    /* Final sliding after merging */
    pos = 0;
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (temp[i] != 0)
                line[pos++] = temp[i];
    }
    else /* SLIDE_RIGHT */
    {
        pos = size - 1;
        for (i = size; i-- > 0;)
            if (temp[i] != 0)
                line[pos--] = temp[i];
    }

    /* Fill the remaining spaces with zeros */
    while (pos < size && direction == SLIDE_LEFT)
        line[pos++] = 0;
    while (pos < size && direction == SLIDE_RIGHT)
        line[++pos] = 0;

    return (1);
}
