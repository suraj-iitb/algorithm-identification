#include <stdio.h>
#define MAX 500010
#define INF 2000000000
 
int count = 0;
int A[MAX];
int L[MAX/2+2], R[MAX/2+2];
 
int merge(int A[], int l, int m, int r)
{
    int i;    
    for (i=0; i<m-l; i++) L[i] = A[l+i];
    for (i=0; i<r-m; i++) R[i] = A[m+i];
     
    L[m-l] = R[r-m] = INF;
     
    int p=0, q=0;
    for (i=l; i<r; i++) {
        if (L[p] <= R[q]) {
            A[i] = L[p++];
        }
        else {
            A[i] = R[q++];
        }
        count++;
    }
     
}
 
void mergeSort(int A[], int l, int r)
{
    if (l+1 < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m, r);
        merge(A, l, m, r);
    }
}
 
int main()
{
    int i;    
    int N;
     
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
     
    mergeSort(A, 0, N); // N?????§???
     
    for (i = 0; i < N-1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[i]);
    printf("%d\n", count);
     
    return 0;
}

