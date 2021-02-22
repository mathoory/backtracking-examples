//
// Created by hoory on 2/21/2021.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5
#define SUM 16
#define ARR                                                               \
    {                                                                     \
        5, 3, 4, 7, 4                                                     \
    }


int sub_group_with_sum_simple(int* arr, int n, int sum);

int sub_group_with_sum_simple_aux(int* arr,
                                  int n,
                                  int sum,
                                  int* word,
                                  int index);

bool valid(bool* used, int* arr, int sum, int i);

void print_arr(int* arr, int n);

bool sub_group_with_sum(int* arr, int n, int sum);

int sub_group_with_sum_aux(int* word,
                           int* arr,
                           bool* used,
                           int n,
                           int sum,
                           int index);

int main()
{
    int arr[N] = ARR;
    printf("Is there a sub-group of the array with sum %d? %d\n",
           SUM,
           sub_group_with_sum(arr, N, SUM));

    printf("[SIMPLE] length of a sub-group of the array with sum %d "
           "is %d\n",
           SUM,
           sub_group_with_sum_simple(arr, N, SUM));
}

bool sub_group_with_sum(int* arr, int n, int sum)
{
    bool ret = false;

    // hold current solution
    int* word = malloc(sizeof(int) * n);
    if (NULL == word)
    {
        return ret;
    }


    // keep track of used numbers, so we don't use twice.
    bool* used = malloc(sizeof(int) * n);
    if (NULL == used)
    {
        return ret;
    }
    for (int i = 0; i < n; ++i)
    {
        used[i] = false;
    }

    ret = (bool) sub_group_with_sum_aux(word, arr, used, n, sum, 0);
    free(word);

    return ret;
}

int sub_group_with_sum_aux(int* word,
                           int* arr,
                           bool* used,
                           int n,
                           int sum,
                           int index)
{
    if (sum == 0)
    {
        print_arr(word, index);
        return 1;
    }
    if (index == n)
    {
        return 0;
    }

    int sol = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!valid(used, arr, sum, i))
        {
            continue;
        }

        used[i] = true;
        word[index] = arr[i];

        sol += sub_group_with_sum_aux(word,
                                      arr,
                                      used,
                                      n,
                                      sum - arr[i],
                                      index + 1);

        used[i] = false;
    }

    return sol;
}

bool valid(bool* used, int* arr, int sum, int i)
{
    if (used[i])
    {
        return false;
    }
    if (arr[i] > sum)
    {
        return false;
    }
    return true;
}

void print_arr(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sub_group_with_sum_simple(int* arr, int n, int sum)
{

    int ret = false;

    // hold current solution
    int* word = malloc(sizeof(int) * n);
    if (NULL == word)
    {
        return ret;
    }


    ret = sub_group_with_sum_simple_aux(arr, n, sum, word, 0);

    if (ret > -1)
    {
        printf("[SIMPLE} Array is:");
        print_arr(word, ret);
    }
    else
    {
        printf("No Solution");
    }


    free(word);

    return ret;
}

int sub_group_with_sum_simple_aux(int* arr,
                                  int n,
                                  int sum,
                                  int* word,
                                  int index)
{
    if (sum == 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return -1;
    }

    if (arr[0] <= sum)
    {

        int k = sub_group_with_sum_simple_aux(arr + 1,
                                              n - 1,
                                              sum - arr[0],
                                              word + 1,
                                              index + 1);
        if (k > -1)
        {
            word[0] = index;
            return k + 1;
        }
    }

    return sub_group_with_sum_simple_aux(arr + 1,
                                         n - 1,
                                         sum,
                                         word,
                                         index + 1);
}