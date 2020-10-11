#include <stdio.h>
int main()
{
    int A[100], i, min, sum = 0, N, temp, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                sum++;
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        printf("%c", i == N - 1 ? '\n' : ' ');
    }

    printf("%d\n", sum);
}

