/********************************
  student id: 319003711
  course no: 234114
  question 4
 ********************************/

#include <stdbool.h>
#include <stdio.h>

#define N 3
#define SAME 1
#define DIFFERENT (-1)

bool validation_check(int color_map[N][N], int solution[N]);
int FindMinimumNumDressColors(int color_map[N][N]);

int main()
{
    // uncomment next line of you don't know
    // printf("I don't know\n");

    int color_map1[N][N] = {{1, -1, 1}, {-1, 1, -1}, {0, -1, 1}};
    printf("%d\n", FindMinimumNumDressColors(color_map1));
    //    int color_map2[N][N] = {{1, 1, 1}, {-1, 1, -1}, {0, -1, 1}};
    //  printf("%d\n", FindMinimumNumDressColors(color_map2));
    return 0;
}

void print_arr(int *word, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", word[i]);
    }
    printf("\n");
}

bool validation_check(int color_map[N][N], int solution[N])
{
    // iterate through guests.  check if all requirements fulfilled.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (color_map[i][j] == SAME)
            {
                //if not same - map is not valid
                if (!(solution[i] == solution[j]))
                {
                    return false;
                }
            }

            else if (color_map[i][j] == DIFFERENT)
            {
                //if requested different, but colors are  same - map is
                // not valid
                if ((solution[i] == solution[j]))
                {
                    return false;
                }
            }
        }
    }

    //all demands fulfilled (didn't return false if got here)
    return true;
}

int max(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int first_larger_than_0(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > 0)
        {
            return arr[i];
        }
    }
    return -1;
}
int min(int *arr, int n)
{
    int min = first_larger_than_0(arr, n);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > 0 && arr[i] < min)
        {
            min = arr[i];
        }
    }
    if (min != -1)
    {
        min++;
    }
    return min;
}

int solve(int color_map[N][N], int word[N], int index, int sol[N])
{
    if (index == N)
    {
        if (validation_check(color_map, word))
        {
            print_arr(word, N);
            sol[max(word, N)] = 1;
        }

        return 0;
    }


    for (int i = 0; i < N; ++i)
    {
        word[index] = i;
        solve(color_map, word, index + 1, sol);
    }

    return min(sol, N);
}

//
//int solve(int color_map[N][N],
//          int solution[N],
//          int solution_index,
//          int colors,
//          int iteration)
//{
//    if (solution_index == colors)
//    {
//        bool is_valid = validation_check(color_map, solution);
//        for (int j = 0; j < colors; j++)
//        {
//            printf("%d", solution[j]);
//        }
//        printf("\n");
//
//        printf("validate %d\n", (int) is_valid);
//        return 1;
//    }
//
//    if (iteration >= colors)
//    {
//        return 1;
//    }
//
//    solution[iteration] = iteration;
//
//    solve(color_map, solution, solution_index+1, colors, iteration+1);
//
//    solve(color_map, solution, solution_index, colors, iteration+1);
//
//    return 1;
//
//}
//

int FindMinimumNumDressColors(int color_map[N][N])
{
    int word[N] = {0};
    int sol[N] = {0};

    return solve(color_map, word, 0, sol);
}
