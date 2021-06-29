#include <stdio.h>

int main()
{
    int N, i, j, t, v;
    int A[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (t = 0; t < N; t++)
    {
        if (t > 0)
            printf(" ");
        printf("%d", A[t]);
    }
    printf("\n");

    for (i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for (t = 0; t < N; t++)
        {
            if (t > 0)
                printf(" ");
            printf("%d", A[t]);
        }
        printf("\n");
    }
    return 0;
}
