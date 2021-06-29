/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on June 15, 2018, 10:57 AM
 */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(
    int *A,
    int N
);

/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    int *A;
    
    scanf("%d", &size);
    A = (int *)malloc(sizeof(int) * size);
    if (A == NULL) return EXIT_FAILURE;
    for (int ix = 0; ix < size; ++ix)
    {
        scanf("%d", &A[ix]);
        if (ix > 0) printf(" ");
        printf("%d", A[ix]);
    }
    printf("\n");
    insertionSort(A, size);
    return (EXIT_SUCCESS);
}

void insertionSort(int *A, int N) // N個の要素を含む0-オリジンの配列A
{   
    int v, j;
    for (int i = 1; i <= N-1; ++i)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for (int p = 0; p < N; ++p) 
        {
            if (p > 0) printf(" ");
            printf("%d", A[p]);
        }
        printf("\n");
    }
}


