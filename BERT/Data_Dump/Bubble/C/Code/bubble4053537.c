#include <stdio.h>

int main()
{
    int flag = 1, i, j;
    int A[100], N, k, count = 0;
    ;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    while (flag)
    {
        flag = 0;
        i = 0;
        for (j = N - 1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                k = A[j];
                A[j] = A[j - 1];
                A[j - 1] = k;
                flag = 1;
                count++;
            }
        }
        i++;
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
