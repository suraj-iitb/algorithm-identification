#include <iostream>
#include <cstdio>
#include <algorithm>

void print_array(int N, int *array)
{
    for (int i = 0; i < N - 1; i++)
        printf("%d ", array[i]);
    printf("%d\n", array[N - 1]);
}

int selection_sort(int N, int *array)
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (array[j] < array[minj])
                minj = j;
        }
        if(i != minj)
        {
            std::swap(array[i], array[minj]);
            counter++;
        }
    }
    return counter;
}

int main()
{
    /* input process */
    int N;
    scanf("%d", &N);
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &array[i]);

    /* sort */
    int counter = selection_sort(N, array);

    /* print */
    print_array(N, array);
    printf("%d\n", counter);
}
