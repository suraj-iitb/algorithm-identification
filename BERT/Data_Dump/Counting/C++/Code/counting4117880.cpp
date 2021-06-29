#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define N 2000000
#define MAX 10001
using namespace std;

void CountingSort(int *A, int *B, int k)
{
    int C[MAX] = {0};
    for (int j = 0; j < MAX; j++)
    {
        C[j] = 0;
    }

    for (int j = 1; j <= k; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }

    for (int j = 1; j < MAX; j++)
    {
        C[j] = C[j - 1] + C[j];
    }

    for (int j = k; j > 0; j--)
    {
        B[C[A[j]]]  = A[j];
        C[A[j]] = C[A[j]] - 1;

    }

}

int main(int argc, char *argv[])
{
    int *A = (int*)malloc(sizeof(int) * N);
    int *B = (int*)malloc(sizeof(int) * N);


    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &A[i]);
    }
    CountingSort(A, B, k);
    printf("%d", B[1]);
    for (int i = 2; i <= k; i++)
    {
        printf(" %d", B[i]);
    }
    printf("\n");

    return 0;
}

