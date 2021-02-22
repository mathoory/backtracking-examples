//
// Created by hoory on 2/21/2021.
//
#include <stdio.h>

#define N 3

//Classroom
int CountParenthesesPairs_roe(int n);
int CountParentheses_aux_roe(int n, int open);


int main()
{
    printf("number of options is:%d \n", CountParenthesesPairs_roe(N));
}

int CountParenthesesPairs_roe(int n)
{
    return CountParentheses_aux_roe(n, 0);
}

int CountParentheses_aux_roe(int n, int open)
{
    if (n == 0 && open == 0) // Stop when all parentheses are closed and
                             // no more pairs to open
    {
        return 1;
    }

    int possible = 0;

    if (open) //close a pair
        possible += CountParentheses_aux_roe(n, open - 1);
    if (n) // open a new pair
        possible += CountParentheses_aux_roe(n - 1, open + 1);

    return possible;
}