//
// Created by hoory on 2/21/2021.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUM 5
#define LENGTH 2

void print_arr(int* arr, int n);

int unique_sum_permutations(int sum, int length);

int unique_sum_permutations_aux(int* word, int length, int sum, int index);

bool valid(int* word, int index, int sum, int i);

int main()
{
    printf("There are %d permutations\n",
           unique_sum_permutations(SUM, LENGTH));
}

int unique_sum_permutations(int sum, int length)
{
    int ret;

    // Holds current solution
    int* word = malloc(sizeof(int) * length);
    if (NULL == word)
    {
        return -1;
    }

    ret = unique_sum_permutations_aux(word, length, sum, 0);
    free(word);
    return ret;
}

int unique_sum_permutations_aux(int* word, int length, int sum, int index)
{
    if (index == length)  // Stop when solution is complete
    {
        if (sum == 0)  // good solution, count it
        {
            print_arr(word, length);
            return 1;
        }

        //bad solution, give up
        return 0;
    }

    int sol = 0;

    for (int i = 0; i <= sum; ++i)  //Max number to try is the sum itself
    {
        if (!valid(word, index, sum, i))  //  Validate constraints
        {
            continue;
        }

        // The change to the solution.
        word[index] = i;

        // The step
        sol += unique_sum_permutations_aux(word,
                                           length,
                                           sum - i,
                                           index + 1);
    }

    return sol;
}

bool valid(int* word, int index, int sum, int i)
{
    if (i > sum)  // will exceed sum, no point in trying
    {
        return false;
    }

    if (index > 0 &&
        i < word[index - 1])  // must ascend to avoid duplicates
    {
        return false;
    }

    return true;  // all validations passed, OK.
}

void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}