#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

void clear(void)
{
  printf("\e[1;1H\e[2J");
}

void printGrid(const int grid[SIZE][SIZE])
{
  for (int i=0; i<SIZE; i++)
  {
    for (int j=0; j<SIZE; j++)
    {
      (grid[i][j] == LIVE) ? printf("%d", grid[i][j]) : printf(" ");
    }
    printf("\n");
  }
}

int countLiveNeighbors(const int grid[SIZE][SIZE], int i, int j)
{
  int liveNeighbors = 0;
  
  for (int x=-1; x<=1; x++)
  {
    for (int y=-1; y<=1; y++)
    {
      if (x == 0 && y == 0) continue;

      int ni = i + x;
      int nj = j + y;

      if (ni >= 0 && ni < SIZE && nj >= 0) {
        if (grid[ni][nj] == LIVE) liveNeighbors++;
      }
    }
  }

  return liveNeighbors;
}

void gridNewGeneration(int grid[SIZE][SIZE], int temp[SIZE][SIZE])
{
  // Go through grid
  for (int i=0; i<SIZE; i++)
  {
    for (int j=0; j<SIZE; j++)
    {
      int cell = grid[i][j];
      
      int liveNeighbors = countLiveNeighbors(grid, i, j);

      if (cell == LIVE)
      {
        printf("liveNeighbors=%d\n", liveNeighbors);
        switch (liveNeighbors)
        {
          case 2:
          case 3:
            temp[i][j] = LIVE;
            break; // Staying alive
          default:
            temp[i][j] = DEAD;
            break;
        }
      }
      else if (cell == DEAD && liveNeighbors == 3)
      {
        temp[i][j] = LIVE;
      }
    }
  }

  // Transpose temporary data into new generation grid once calculations are complete
  for (int i=0; i<SIZE; i++)
  {
    for (int j=0; j<SIZE; j++)
    {
      grid[i][j] = temp[i][j];
      temp[i][j] = DEAD;
    }
  }
}


