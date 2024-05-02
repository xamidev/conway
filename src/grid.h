#ifndef GRID_H
#define GRID_H

// Hardcoded constants
#define SIZE 40
#define GENERATIONS 200
#define DEAD 0
#define LIVE 1
#define SOUP_PROB 0.7
#define DELAY 50000

void clear(void);
void printGrid(const int grid[SIZE][2*SIZE]);
int countLiveNeighbors(const int grid[SIZE][2*SIZE], int i, int j);
void gridNewGeneration(int grid[SIZE][2*SIZE], int temp[SIZE][2*SIZE]);
void soup(int grid[SIZE][2*SIZE]);

#endif
