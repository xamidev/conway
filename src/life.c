#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "grid.h"

// Rules: go through the 2d grid
// If living cell:
//    If it has fewer than 2 living neighbor cells, it dies
//    If it has 2 or 3 living neighbor cells, it lives
//    If it has more than 3 living neighbor cells, it dies
// If dead cell:
//    If it has 3 living neighbor cells, it becomes alive

int main(void)
{
  clear();
  int grid[SIZE][SIZE] = {0};
  int temp[SIZE][SIZE] = {0};
 
  //Glider
  grid[1][2] = LIVE;
  grid[2][3] = LIVE;
  grid[3][1] = LIVE;
  grid[3][2] = LIVE;
  grid[3][3] = LIVE;

  puts("Generation 0\n");
  printGrid(grid);

  for (int i=0; i<GENERATIONS; i++)
  {
    gridNewGeneration(grid, temp);
    usleep(50000);
    clear();
    printf("Generation %d\n\n", i+1);
    printGrid(grid);
  }

  return EXIT_SUCCESS;
}

