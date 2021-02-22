//
// Created by hoory on 2/21/2021.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4
#define VALIDATIONS 3  //col and 2 diags
#define ROW 0
#define MAIN_DIAG 1
#define SECOND_DIAG 2


int n_queens(int n);

int n_queens_aux(int* solution, int n, int index, bool** board_state);

int main()
{
    printf("solutions:%d\n", n_queens(8));
    return 0;
}

int n_queens(int n)
{

    // current solutions array
    int* solution = malloc(sizeof(int) * n);
    if (NULL == solution)
    {
        return -1;
    }


    // board state for validations array
    bool** board_state = malloc(VALIDATIONS * sizeof(bool*));
    if (NULL == board_state)
    {
        return -1;
    }

    for (int i = 0; i < 3; ++i)
    {
        board_state[i] = malloc(sizeof(bool) * n * 2);  //bigger than diag
                // which is sqrt(2n^2)
        if (NULL == board_state[i])
        {
            return -1;
        }

        for (int j = 0; j < n * 2; ++j)
        {
            board_state[i][j] = false;
        }
    }


    return n_queens_aux(solution, n, 0, board_state);
}

void set_queen(int new_state,
               bool** board_state,
               int n,
               int row,
               int index)
{
    board_state[ROW][row] = new_state;
    board_state[MAIN_DIAG][index - row + n] = new_state;
    board_state[SECOND_DIAG][index + row + 1] = new_state;
}

bool is_valid(bool** board_state, int n, int row, int index)
{
    return (!board_state[ROW][row] &&
            !board_state[MAIN_DIAG][index - row + n] &&
            !board_state[SECOND_DIAG][index + row + 1]);
}

int n_queens_aux(int* solution, int n, int index, bool** board_state)
{
    if (index == n) // The stop condition - full solution
    {
        return 1;
    }

    int sols = 0; // Count solutions

    for (int row = 0; row < n; ++row)
    {
        if (!is_valid(board_state, n, row, index)) //The validation,
                                                   // stop bad branches
                                                   // from running
        {
            continue;
        }

        // The step, add queen to next col, update board state
        solution[index] = row; // udpate solution

        set_queen(1, board_state, n, row, index);

        // step
        sols += n_queens_aux(solution, n, index + 1, board_state);

        set_queen(0, board_state, n, row, index);
    }

    return sols;
}
