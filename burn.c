//
// Created by hoory on 2/21/2021.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISC_SIZE 500
#define N 7
#define FILES {270, 400, 220, 210, 360, 540, 489};


bool* init_bool_array(int n);

int best_burn(int* sizes, int n, int disc_size);

int main()
{
    int files[N] = FILES;
    printf("Best solution is: %d\n", best_burn(files, N, DISC_SIZE));
}
int best_burn_aux(int* sizes, int n, int disc_size, bool* chosen)
{
    if (n == 0)  //No files left, return size reached
    {
        return disc_size;
    }

    if (disc_size == 0)  //disc is full, return size 0
    {
        return 0;
    }

    // Calculate size without current file
    int size_left_without =
            best_burn_aux(sizes + 1, n - 1, disc_size, chosen + 1);

    // Calculate size with current file
    if (sizes[0] <= disc_size)
    {
        bool* chosen_with = init_bool_array(n);
        if (NULL == chosen_with)
        {
            return -1;
        }

        chosen_with[0] = true;
        int size_left_with = best_burn_aux(sizes + 1,
                                           n - 1,
                                           disc_size - sizes[0],
                                           chosen_with + 1);

        // If size left with is smaller (means better solution)
        if (size_left_with < size_left_without)
        {
            memcpy(chosen, chosen_with, n);
            free(chosen_with);
            return size_left_with;
        }
        free(chosen_with);
    }
    return size_left_without;
}

int best_burn(int* sizes, int n, int disc_size)
{
    int sol;

    // Array for solution (chosen marked with 1)
    bool* chosen = init_bool_array(n);
    if (NULL == chosen)
    {
        return -1;
    }

    // Find best solution ( returns space left, populates chosen)
    sol = best_burn_aux(sizes, n, disc_size, chosen);

    printf("Files in the solution are: ");
    for (int i = 0; i < n; ++i)
    {
        if (chosen[i])
        {
            printf("%d ", sizes[i]);
        }
    }
    printf("\n");

    free(chosen);

    return disc_size - sol;
}

bool* init_bool_array(int n)
{
    bool* ptr = malloc(sizeof(bool) * n);
    if (NULL == ptr)
    {
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        ptr[i] = false;
    }
    return ptr;
}