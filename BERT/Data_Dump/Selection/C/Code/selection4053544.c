#include <stdio.h>

int main()
{
    int A[100], i, j, k, N;
    int minj, count = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 0; i <= N - 1; i++)
    {
        minj = i;
        for (j = i; j <= N - 1; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (A[i] > A[minj])
            count++;
        k = A[i];
        A[i] = A[minj];
        A[minj] = k;
    }

    for (i = 0; i < N; i++)
    {
        if (i)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);

    return 0;
}
