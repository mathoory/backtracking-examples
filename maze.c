//
// Created by hoory on 2/21/2021.
//

#include <stdbool.h>
#include <stdio.h>

#define N 8

bool solve_maze(int maze[N][N], int i, int j);

void print_maze(int maze[N][N]);


int main()
{
    int solved, maze[N][N] = {{1, 1, 0, 1, 0, 0, 0, 1},
                              {0, 1, 0, 1, 0, 0, 0, 1},
                              {0, 1, 1, 1, 1, 1, 0, 0},
                              {1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 1, 1, 0, 1, 1, 1},
                              {0, 1, 0, 1, 1, 1, 0, 1},
                              {0, 1, 0, 0, 0, 0, 1, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1}};

    solved = solve_maze(maze, 0, 0);

    if (solved)
    {
        print_maze(maze);
    }
    else
    {
        printf("No solution found!\n");
    }
}

bool solve_maze(int maze[N][N], int i, int j)
{

    bool up, down, left, right;
    up = down = left = right = false;

    if (maze[i][j] == 0 || maze[i][j] == 2)
    {
        return false;
    }
    maze[i][j] = 2;

    if (i == N - 1 && j == N - 1)
    {
        return true;
    }

    if (i + 1 < N)
    {
        down = solve_maze(maze, i + 1, j);
    }

    if (i - 1 >= 0)
    {
        up = solve_maze(maze, i - 1, j);
    }

    if (j + 1 < N)
    {
        right = solve_maze(maze, i, j + 1);
    }

    if (j - 1 >= 0)
    {
        left = solve_maze(maze, i, j - 1);
    }

    if (up || down || left || right)
    {
        return true;
    }

    maze[i][j] = 1;
    return false;
}


void print_maze(int maze[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}