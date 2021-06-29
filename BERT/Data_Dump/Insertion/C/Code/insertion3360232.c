#include <stdio.h>
void print(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
}
void InsertionSort(int A[], int n)
{
    int i, j, v;
    for (i = 1; i <= n - 1; i++)
    {
        v = A[i];
        j = i - 1;
        while (A[j] > v && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A, n);
    }
}

int main()
{
    int A[100], N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    print(A, N);
    InsertionSort(A, N);
    return 0;
}
