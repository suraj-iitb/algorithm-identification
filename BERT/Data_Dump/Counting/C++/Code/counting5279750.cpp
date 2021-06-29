#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main()
{
    int n;
    unsigned short* A;
    unsigned short* B;

    scanf("%d", &n);

    A = (unsigned short*)malloc(sizeof(short) * n+1);
    B = (unsigned short*)malloc(sizeof(short) * n+1);

    int* C = (int*)malloc(sizeof(int) * VMAX + 1);
    for (int i = 0; i <= VMAX; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i+1]);
        C[A[i+1]]++;
    }

    // i以下の数を加算
    for (int i = 1; i <= VMAX; i++)
    {
        C[i] += C[i - 1];
    }

    for (int j = n; j > 0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d", B[i]);

        if (i < n) { printf(" "); }
    }
    printf("\n");
}
