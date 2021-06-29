#include <iostream>
#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &array[i]);

    for (int k = 0; k < N - 1; k++)
        printf("%d ", array[k]);
    printf("%d\n", array[N - 1]);

    for (int i = 1; i < N; i++)
    {
        int v = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > v)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;

        for (int k = 0; k < N - 1; k++)
        {
            printf("%d ", array[k]);
        }
        printf("%d\n", array[N - 1]);
    }
}
