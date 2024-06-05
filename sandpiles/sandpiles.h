#ifndef SANDPILES_H
#define SANDPILES_H

#define SIZE 3
#define MAX_GRAINS 3
void print_grid(int grid[SIZE][SIZE]);

int is_stable(int grid[SIZE][SIZE]);

void topple(int grid[SIZE][SIZE]);

void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]);



#endif /* SANDPILES_H */