#include <stdio.h>

void trace(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    int A[100];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int v;
        trace(A, N);
    for (int i = 1; i <= N - 1; i++)
    {
        v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;
        trace(A, N);
    }

    return 0;
}
