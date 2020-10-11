#include <stdio.h>

int select(int array[], int N);
int main()
{
    int array[100], N, i, sw;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &array[i]);

    sw = select(array, N);
    for (i = 0; i < N; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    return 0;
}
int select(int array[], int N)
{
    int i, j, k, temp, sw = 0;
    for (i = 0; i < N; i++)
    {
        k = i;
        for (j = i; j < N; j++)
        {
            if (array[j] < array[k])
                k = j;
        }
        temp = array[i];
        array[i] = array[k];
        array[k] = temp;
        if (i != k)
            sw++;
    }
    return sw;
}
