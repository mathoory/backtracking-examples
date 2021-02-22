//
// Created by hoory on 2/21/2021.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 2
#define UP_TO_K 3

void print_arr(int* arr, int n);

int unique_permutations(int n, int up_to_k);

int unique_permutations_aux(int* word,
                            bool* used,
                            int n,
                            int up_to_k,
                            int index);

bool valid(int* word, bool* used, int index, int i);

int main()
{
    printf("There are %d permutations\n", unique_permutations(N, UP_TO_K));
}

bool valid(int* word, bool* used, int index, int i)
{
    // Use each number once
    if (used[i])
    {
        return false;
    }

    // Each new number must be bigger than the one before
    if (index > 0 && i < word[index - 1])
    {
        return false;
    }


    // All validations passed, return true.
    return true;
}

int unique_permutations(int n, int up_to_k)
{
    // current solutions place holder
    int* word = malloc(sizeof(int) * n);
    if (word == NULL)
    {
        return -1;
    }

    // array to keep track of used nums for validation (can only use
    // each once)
    bool* used = malloc(sizeof(bool) * up_to_k);
    if (word == NULL)
    {
        return -1;
    }

    // init
    for (int i = 0; i < up_to_k; ++i)
    {
        used[i] = false;
    }

    return unique_permutations_aux(word, used, n, up_to_k, 0);
}
int unique_permutations_aux(int* word,
                            bool* used,
                            int n,
                            int up_to_k,
                            int index)
{
    if (index == n) // The stop condition - full solution
    {
        print_arr(word, n);
        return 1;
    }

    int sol = 0;

    for (int i = 0; i < up_to_k; ++i)
    {
        if (!valid(word, used, index, i)) // The validation step, no
                                          // returns, only ascending
        {
            continue;
        }

        // The change - add number to solution, update as used
        word[index] = i;
        used[i] = true;

        // The iteration
        sol += unique_permutations_aux(word, used, n, up_to_k, index + 1);

        used[i] = false;
    }

    return sol;
}

void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
