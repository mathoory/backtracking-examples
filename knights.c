//
// Created by hoory on 2/21/2021.
//
#include <stdbool.h>
#include <stdio.h>

#define N 7
#define KNIGHT_MOVE_NUM 8

void print_board(int board[N][N]);
bool inboard(int i, int j);
bool is_legal(int i, int j, int board[N][N]);
bool solve_knights(int board[N][N], int i, int j, int index);
bool solve_knight_prob(int board[N][N], int i_begin, int j_begin);

int main()
{
    int board[N][N];

    bool solved = solve_knight_prob(board, 0, 0);

    if (solved)
        print_board(board);
    else
        printf("No solution found!\n");

    return 0;
}

bool inboard(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}

bool is_legal(int i, int j, int board[N][N])
{
    return (inboard(i, j) && board[i][j] == 0);
}

bool solve_knights(int board[N][N], int i, int j, int index)
{
    int knight_moves[][2] = {{-2, -1},
                             {-2, +1},
                             {+2, -1},
                             {+2, +1},
                             {-1, -2},
                             {-1, +2},
                             {+1, -2},
                             {+1, +2}};

    board[i][j] = index + 1;
    if (board[i][j] == N * N)
    {
        return true;
    }

    for (int move = 0; move < KNIGHT_MOVE_NUM; ++move)
    {
        int next_i = i + knight_moves[move][0];
        int next_j = j + knight_moves[move][1];
        if (!is_legal(next_i, next_j, board))
        {
            continue;
        }
        if (solve_knights(board, next_i, next_j, index + 1))
        {
            return true;
        }
    }

    board[i][j] = 0;
    return false;
}

bool solve_knight_prob(int board[N][N], int i_begin, int j_begin)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            board[i][j] = 0;
    }
    return solve_knights(board, i_begin, j_begin, 0);
}

void print_board(int board[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
