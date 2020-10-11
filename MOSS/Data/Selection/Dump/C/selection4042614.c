#include <stdio.h>

int main()
{
    int i, j, minj, N, A[100], tmp, count = 0, k;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < N; i++)
    {
        minj = i;
        for (j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        k = A[minj];
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if (k != A[minj])
            count++;
    }

    for (i = 0; i < N - 1; i++)
        printf("%d ", A[i]);

    printf("%d\n%d\n", A[N - 1], count);

    return 0;
}

