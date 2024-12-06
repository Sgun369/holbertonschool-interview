#include "menger.h"

/**
 * is_empty - Determines if a cell in the Menger Sponge grid should be empty.
 * @x: The x-coordinate of the cell
 * @y: The y-coordinate of the cell
 * Return: 1 if the cell should be empty, 0 otherwise
 */
int is_empty(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return (1);
        x /= 3;
        y /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger Sponge for a given level.
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size, x, y;

    /* Handle negative level */
    if (level < 0)
        return;

    /* Calculate the size of the sponge */
    size = pow(3, level);

    /* Loop through each row and column of the grid */
    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            if (is_empty(x, y))
                putchar(' '); /* Print space for empty cells */
            else
                putchar('#'); /* Print # for filled cells */
        }
        putchar('\n'); /* Move to the next line after each row */
	}
}
