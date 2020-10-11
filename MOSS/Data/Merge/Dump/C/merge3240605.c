#include<stdio.h>

int count = 0, A[500000], L[2500000], R[2500000];

int merge(int *A, int left, int mid, int right){
    int i, j, k, n1, n2;
    
    n1 = mid - left;
    n2 = right - mid;
    for (i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = 10000000000;
    R[n2] = 10000000000;
    i = 0;
    j = 0;
    for (k = left; k < right; k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

int mergeSort(int *A, int left, int right){
    int mid;
    if (left + 1 < right){
        mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int i, q, n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);
    
    printf("%d", A[0]);
    for (i = 1; i < n; i++){
        printf(" %d", A[i]);
    }
    printf("\n%d\n", count);
    
    return 0;
}
