#include <iostream>
#include <cstdio>
#include <algorithm>

void print_array(int N, int* array)
{
    for (int i = 0; i < N - 1; i++)
        printf("%d ", array[i]);
    printf("%d\n", array[N - 1]);
}

int bubble_sort(int N, int* array)
{
    int flag = 1;
    int counter = 0;
    while(flag)
    {
        flag = 0;
        for(int j=N-1; j>0; j--)
        {
            if(array[j] < array[j-1])
            {
                std::swap(array[j], array[j-1]);
                counter++;
                flag = 1;
            }
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
    int counter = bubble_sort(N, array);

    /* print */
    print_array(N, array);
    printf("%d\n", counter);
}
