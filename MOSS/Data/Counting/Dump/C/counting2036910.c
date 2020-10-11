#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
//============================================================================
//----------------------------------------------------------------------------
long *C;
//----------------------------------------------------------------------------
void CountingSort(long *A, long *B,  long n, long k)
{
    long i;

    /* C[i] ??? i ???????????°????¨?????????? */
    for (i = 0; i<n; i++)
        C[A[i]]++;
    /* C[i] ??? i ??\????????°???????????°????¨??????????*/
    for (i = 1; i<=k; i++)
        C[i] += C[i-1];
    for (i=n-1; 0<=i; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}
//----------------------------------------------------------------------------
/*
7
2 5 1 3 2 3 0
*/
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void input(FILE *file)
{
    long i,n; long *A,*B,max;

    fscanf(file, "%ld", &n);
    A = malloc(succ(n)*sizeof(long));
    B = malloc(succ(n)*sizeof(long));
    for (i=max=0; i<n; i++){
        fscanf(file, "%ld", &A[i]);
        if (max<A[i])
            max=A[i];
    }
    C = malloc(succ(max)*sizeof(long));
    memset(C, 0, sizeof(long)*succ(max));
    CountingSort(A, B, n, max);
    for (i=0; i<n; i++){
        if (i) printf(" ");
        printf("%ld", B[i]);
    }
    printf("\n");
    free(A);
    free(B);
    free(C);
}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif
