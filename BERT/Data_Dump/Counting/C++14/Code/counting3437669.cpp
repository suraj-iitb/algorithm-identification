#include <iostream>
#include <cstdio>
using namespace std;

const int LEN = 2000001;
static const int K = 10001;
int C[K];
int A[LEN];

void countingSort(int A[], int n)
{
    for (int i = 0; i < K; ++i)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        ++C[A[i]];
    }

    for (int i = 1; i < K; ++i)
    {
        C[i] += C[i-1];
    }

    int *B = (int *)malloc(n * sizeof(int));

    for (int i = n-1; i >= 0; --i)
    {
        B[--C[A[i]]] = A[i];
    }

    for (int i = 0; i != n; ++i)
    {
        A[i] = B[i];
    }

    free(B);
}

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i != n; ++i)
    {
        scanf("%d", &A[i]);
    }

    countingSort(A, n);

    for (int i = 0; i != n; ++i)
    {
        if (i) printf(" ");
        printf("%d", A[i]);
    }

    printf("\n");

    return 0;
}
