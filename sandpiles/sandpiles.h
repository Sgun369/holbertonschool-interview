#ifndef SANDPILES_H
#define SANDPILES_H

#define SIZE 3
#define MAX_GRAINS 3
#define N SIZE
void print_grid(int grid[N][N]);  /* Remove 'static' */

int is_stable(int grid[N][N]);

void topple(int grid[N][N]);

void sandpiles_sum(int grid1[N][N], int grid2[N][N]);



#endif /* SANDPILES_H */