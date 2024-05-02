#ifndef GRID_H
#define GRID_H

#define SIZE 40
#define GENERATIONS 200
#define DEAD 0
#define LIVE 1

void clear(void);
void printGrid(const int grid[SIZE][SIZE]);
int countLiveNeighbors(const int grid[SIZE][SIZE], int i, int j);
void gridNewGeneration(int grid[SIZE][SIZE], int temp[SIZE][SIZE]);

#endif
