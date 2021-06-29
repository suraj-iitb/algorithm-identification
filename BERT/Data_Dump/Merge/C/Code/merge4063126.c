#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void merge(int *A, int left, int mid, int right, int *count){
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    int *L, *R;
    L = (int *)malloc(sizeof(int) * (n1 + 1));
    R = (int *)malloc(sizeof(int) * (n2 + 1));
    for(i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        (*count)++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}

void mergeSort(int *A, int left, int right, int *count){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A, left, mid, count);
        mergeSort(A, mid, right, count);
        merge(A, left, mid, right, count);
    }
}

int main(){
    int n, i, count = 0;
    int *A;
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    mergeSort(A, 0, n, &count);
    for(i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i != n - 1){
            printf(" ");
        }
    }
    printf("\n%d\n", count);
    free(A);
    return 0;
}
