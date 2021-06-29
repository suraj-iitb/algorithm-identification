#include <stdio.h>

int main()
{
    int i, j, temp, count=0, N, A[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++)
    {
        for (j = N - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                count++;
            }
        }
    }

    for (j = 0; j < N; j++)
    {
        printf("%d", A[j]);
        if (j == N - 1)
            break;
        else
            printf(" ");
    }
    printf("\n%d\n", count);

    return 0;
}
