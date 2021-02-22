#include <stdio.h>
#include <stdlib.h>

#define N 3

int print_all_binary_words(int n);

int print_all_binary_words_aux(int* word, int n, int index);

void print_arr(int* arr, int n);

int main()
{
    printf("Number of permutations:%d\n", print_all_binary_words(N));
    return 0;
}


int print_all_binary_words(int n)
{
    // Array for temp solutions
    int* word = (int*) malloc(sizeof(int) * n);
    if (NULL == word)
    {
        return -1;
    }

    // Call with index zero
    return print_all_binary_words_aux(word, n, 0);
}

int print_all_binary_words_aux(int* word, int n, int index)
{
    int sols = 0;

    if (index == n)
    {
        print_arr(word, n);
        return 1;
    }

    word[index] = 0;
    sols += print_all_binary_words_aux(word, n, index + 1);

    word[index] = 1;
    sols += print_all_binary_words_aux(word, n, index + 1);

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