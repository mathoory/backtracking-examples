#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 2

#define UPTO_K 3

void print_arr(int* arr, int n);

int print_all_array_permutations_aux(int* word,
                                     int n,
                                     int upto_K,
                                     int index,
                                     bool* used);

int print_all_array_permutations(int n, int upto_K);

int main()
{
    printf("Number of permutations:%d\n",
           print_all_array_permutations(N, UPTO_K));
    return 0;
}

int print_all_array_permutations(int n, int upto_K)
{
    // Array for solution
    int* word = malloc(n * sizeof(int));
    if (NULL == word)
    {
        return -1;
    }

    // Array for validation of next num
    bool* used = malloc(upto_K * sizeof(bool));
    if (NULL == used)
    {
        return -1;
    }

    // init all to false
    for (int i = 0; i < upto_K; ++i)
    {
        used[i] = false;
    }

    return print_all_array_permutations_aux(word, n, upto_K, 0, used);
}


bool valid(bool* used, int num)
{
    return !used[num];
}

int print_all_array_permutations_aux(int* word,
                                     int n,
                                     int upto_K,
                                     int index,
                                     bool* used)
{
    if (n == index) //The stop condition - full solution
    {
        print_arr(word, n);
        return 1;
    }

    int sols = 0;

    for (int i = 0; i < upto_K; ++i)
    {
        if (!valid(used, i)) // The validation, make sure not in use.
        {
            continue;
        }
        used[i] = true;

        word[index] = i; //The change to solution + step
        sols += print_all_array_permutations_aux(word,
                                                 n,
                                                 upto_K,
                                                 index + 1,
                                                 used);
        used[i]=false;
    }

    return sols;
}

void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//
// Created by hoory on 2/21/2021.
//
