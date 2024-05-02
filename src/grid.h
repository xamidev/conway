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
void printGrid(const unsigned char grid[SIZE][2*SIZE]);
int countLiveNeighbors(const unsigned char grid[SIZE][2*SIZE], int i, int j);
void gridNewGeneration(unsigned char grid[SIZE][2*SIZE], unsigned char temp[SIZE][2*SIZE]);
void soup(unsigned char grid[SIZE][2*SIZE]);

#endif
