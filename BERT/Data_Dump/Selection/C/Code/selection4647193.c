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

int SelectionSort(int A[], int N)
{
    int sw = 0;
    for (int i = 0; i < N; i++)
    {
        int mini = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }
        if (i != mini)
            sw++;
        int v = A[i];
        A[i] = A[mini];
        A[mini] = v;
    }
    return sw;
}
int main()
{
    int N, i, sw;
    int A[100];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    sw = SelectionSort(A, N);
    trace(A, N);
    printf("%d\n", sw);

    return 0;
}
