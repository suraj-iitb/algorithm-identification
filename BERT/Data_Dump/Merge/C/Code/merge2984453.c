#include <stdlib.h>
#include <stdio.h>

int INFTY = 1000000000;
int counter;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for(int i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0;
    int j = 0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
            counter = counter + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
            counter = counter + 1;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(int argc, char** argv) {
    int N = 0;
    scanf("%d",&N);
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, N);

    for(int k=0; k<N-1; k++){
        printf("%d ",arr[k]);
    }
    printf("%d\n", arr[N-1]);
    printf("%d\n", counter);
    return 0;
}

