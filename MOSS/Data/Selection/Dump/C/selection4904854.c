#include <stdio.h>

int main()
{
    int A[100], i, min, sum = 0, N;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < N; i++)
    {
        int temp, j;
        min = i;
        for (j = i; j < N; j++)
            if (A[j] < A[min])
                min = j;
        if (i != min)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            sum++;
        }
        printf("%d", A[i]);
        printf("%c", i == N - 1 ? '\n' : ' ');
    }

    printf("%d\n", sum);
}
