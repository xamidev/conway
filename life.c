#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Rules: go through the 2d grid
// If living cell:
//    If it has fewer than 2 living neighbor cells, it dies
//    If it has 2 or 3 living neighbor cells, it lives
//    If it has more than 3 living neighbor cells, it dies
// If dead cell:
//    If it has 3 living neighbor cells, it becomes alive

#define SIZE 20
#define GENERATIONS 10
#define DEAD 0
#define LIVE 1

void clear(void)
{
  printf("\e[1;1H\e[2J");
}

void printGrid(int grid[SIZE][SIZE])
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

int countLiveNeighbors(int grid[SIZE][SIZE], int i, int j)
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

void gridNewGeneration(int grid[SIZE][SIZE])
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
            grid[i][j] = LIVE;
            break; // Staying alive
          default:
            grid[i][j] = DEAD;
            break;
        }
      }
      else if (cell == DEAD && liveNeighbors == 3)
      {
        grid[i][j] = LIVE;
      }
    }
  }
}

int main(void)
{
  clear();
  int grid[SIZE][SIZE] = {0};
 
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
    gridNewGeneration(grid);
    sleep(1);
    clear();
    printf("Generation %d\n\n", i+1);
    printGrid(grid);
  }

  return EXIT_SUCCESS;
}

