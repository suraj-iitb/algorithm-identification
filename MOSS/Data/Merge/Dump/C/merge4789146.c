#include<stdio.h>

int count = 0;

void merge(int *A, int left, int mid, int right){
    int n1 = mid -left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    int i = 0;
    int j = 0;
    L[n1] = 2000000000;
    R[n2] = 2000000000;
    for(int k = left; k < right; k++){
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

void mergeSort(int *A, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A, 0, n);
    for(int i = 0; i < n; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
