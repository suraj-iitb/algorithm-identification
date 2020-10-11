#include <stdio.h>
#include <limits.h>
 
#define INFTY INT_MAX
#define N 500000
 
int count = 0;
 
void merge(int A[], int left, int mid, int right){
    int i, j, k;
    int L[N], R[N];
    int L_elements = mid - left;
    int R_elements = right - mid;
 
    for(i=0; i<L_elements; i++)
        L[i] = A[left + i];
    L[i] = INFTY;
 
    for(i=0; i<R_elements; i++)
        R[i] = A[mid + i];
    R[i] = INFTY;
 
 
    i = j = k = 0;
    for(k=left; k<right; k++){
        if( L[i] <= R[j] )
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
    count += i + j;
}   
 
void mergeSort(int A[], int left, int right){
    int mid;
    if( left+1 < right ){
        mid = ( left + 1 + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
 
int main(void){
    int A[N], n, i;
 
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &A[i]);
 
    mergeSort(A, 0, n);
 
    for(i=0; i<n-1; i++)
        printf("%d ", A[i]);
    printf("%d\n%d\n", A[i], count);
 
    return 0;
}

