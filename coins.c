//
// Created by hoory on 2/21/2021.
//
#include <stdbool.h>
#include <stdio.h>

#define N 4
#define COINS {2,5,3,7};
#define SUM 10
#define COINS_LIMIT 2

void print_arr(int* arr, int n);

int get_partitions(int* coins,
                   int n,
                   int sum,
                   int coins_limit,
                   int* word,
                   int index);
int main()
{
    int coins[N] = COINS;
    int word[N] = {0};
    printf("%d \n", get_partitions(coins, N, SUM, COINS_LIMIT, word, 0));
}

bool valid(int* word,int index, int new)
{
    if (index > 0 && word[index - 1] > new) // Only ascending to prevent
                                            // duplicates
    {
        return false;
    }

    return true;
}

int get_partitions(int* coins,
                   int n,
                   int sum,
                   int coins_limit,
                   int* word,
                   int index)
{
    int sol = 0;
    if (sum == 0) // Requested sum
    {
        return 1;
    }

    if (index == coins_limit) // Can't add any more coins, and sum is
                              // not good - stop
    {
        return 0;
    }


    for (int i = 0; i < n; ++i)
    {
        if (!valid(word, index, coins[i])) //condition - only ascending
        {
            continue;
        }
        word[index] = coins[i]; //the change to the solution

        // the step
        sol += get_partitions(coins,
                              n,
                              sum - coins[i],
                              coins_limit,
                              word,
                              index + 1);

        word[index] = 0;
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