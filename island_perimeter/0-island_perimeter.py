#!/usr/bin/python3
"""
Module to calculate the perimeter of an island.
"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.
    
    """
    perimeter = 0
    
    # Iterate through each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                # Check the four directions around the land cell
                if i == 0 or grid[i - 1][j] == 0:  # Check above
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:  # Check below
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:  # Check left
                    perimeter += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:  # Check right
                    perimeter += 1
    
    return perimeter
