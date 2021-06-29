#include <iostream>
#include <cstdio>

int n;

void counting_sort(int A[], int B[], int k)
{
    int C[k + 1];
    for(int i = 1; i <= k; i++)
        C[i] = 0;

    for(int j = 1; j <= n; j++)
        C[A[j]]++;

    for(int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    for(int j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    scanf("%d", &n);
    int A[n + 1];
    int B[n + 1];
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    counting_sort(A, B, 10000);
    for(int i = 1; i < n; i++)
        printf("%d ", B[i]);
    printf("%d\n", B[n]);
}
