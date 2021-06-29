#include <iostream>
#include <cstdio>

void DumpArray(int *A, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << A[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void CountingSort(int *A, int *B, int k, int n)
{
    int C[k+1];
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i-1];
    }

    for (int j = 0; j < n; j++) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main(int argc, char *argv[])
{
    int n;
    int *A = (int *) malloc(sizeof(int) * 2000000);
    int *B = (int *) malloc(sizeof(int) * 2000000);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    CountingSort(A, B, 10000, n);
    DumpArray(B, n);

    return 0;
}
