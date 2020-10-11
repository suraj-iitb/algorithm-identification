#include<stdio.h>
#include<stdlib.h>
#define N 500000

int cnt=0;

void merge(int *A, int left, int mid, int right){
    int n1,n2;
    int i, j, k;
 
    n1 = mid - left;
    n2 = right - mid;
 
    int L[N/2+2], R[N/2+2];
 
    for(i=0; i<n1; i++)   L[i] = A[left + i];
    for(i=0; i<n2; i++)   R[i] = A[mid + i];
 
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    i = j = 0;
    for(k=left; k<right; k++){
        cnt++; 
        if( L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        } 
    }
}

void mergeSort(int *A, int left, int right){
    int mid;
    if(left+1 < right){
        mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, A[N];
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &A[i]);

    mergeSort(A, 0, n);

    printf("%d", A[0]);
    for(i=1;i<n;i++) printf(" %d", A[i]);
    printf("\n%d\n", cnt);
    return 0;
}
