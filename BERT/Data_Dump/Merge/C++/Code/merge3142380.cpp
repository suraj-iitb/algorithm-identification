#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001

int count = 0;
void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int * L = (int *)malloc((n1+1) * sizeof(int));
    int * R = (int *)malloc((n2+1) * sizeof(int));
    for (int i = 0; i < n1; i++){//n1-1 or n1?
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;

    int i = 0, j = 0;
    for (int k = left; k < right; k++){//if right=3, cicle=3
        count++;
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if (left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    int S[500001];
    scanf("%d", &n);
    for (int i = 0; i< n; i++){
        scanf ("%d", &S[i]);
    }
    mergeSort(S, 0, n);

    for (int i = 0; i < n; i++){
        if (i == n-1){
            printf("%d\n", S[i]);
            break;
        }
        printf("%d ", S[i]);
    }
    printf("%d\n", count);
    return 0;
}
