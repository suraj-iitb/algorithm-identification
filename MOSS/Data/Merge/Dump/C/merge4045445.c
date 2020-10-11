#include<stdio.h>

#define N 2000000000

int n;
int count=0;
int A[500000];

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for(int i=0; i<n1; i++){
        L[i] = A[left+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid+i];
    }
    L[n1]=N;
    R[n2]=N;
    int i=0;
    int j=0;

    for(int k=left; k<right; k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeaSort(int A[], int left, int right){
    int mid;
    if(left+1 < right){
        mid = (left+right)/2;
        mergeaSort(A, left, mid);
        mergeaSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    mergeaSort(A, 0, n);

    for(int i=0; i<n-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n",A[n-1]);

    printf("%d\n", count);

    return 0;
}
