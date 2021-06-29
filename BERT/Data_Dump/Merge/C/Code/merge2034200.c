//============================================================================
//  Search Allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
//============================================================================
//============================================================================
//============================================================================

//============================================================================
//============================================================================
//----------------------------------------------------------------------------
#define INFTY 0x7fffffff
long change,N;
void merge(long *A, long left, long mid, long right)
{
    long i,j,k,*L,*R;
    long n1 = mid - left;
    long n2 = right - mid;

    L=malloc(succ(n1)*sizeof(long));
    R=malloc(succ(n2)*sizeof(long));
    for (i=0; i<n1; i++)
        L[i] = A[left + i];
    for (i=0; i<n2; i++)
        R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    for (i=j=0, k = left; k<right; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
            change++;
        }else{
            A[k] = R[j];
            j++;
            change++;
        }
    }
    free(L);
    free(R);
}
//----------------------------------------------------------------------------
void mergeSort(long * A, long left, long right)
{
    long mid;

    //for (mid=0; mid<N; mid++)
    //    printf("%ld ", A[mid]);
    //printf("\n");
    if (succ(left) < right){
        mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
//----------------------------------------------------------------------------
void input(FILE *file)
{
    long i,n;
    long *ary;

    fscanf(file, "%ld", &N);
    ary=malloc(N*sizeof(long));
    for (n=change=0; n<N; n++){
        fscanf(file, "%ld", &ary[n]);
    }
    mergeSort(ary, 0, N);
    for (i=0; i<N; i++){
        if (i) printf(" ");
        printf("%ld", ary[i]);
    }
    printf("\n%ld\n", change);
    free(ary);
}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif
