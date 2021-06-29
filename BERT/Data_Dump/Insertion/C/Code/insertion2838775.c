#include<stdio.h>
#include<stdlib.h>

void scanArrayInt(int N, int* A){
    int i;
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
}

void printArray(int N, int* A){
    int i;
    for(i = 0; i < N - 1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N - 1]);
}

void insertionSort(int N, int* A){
    int i, j, v;
    for(i = 1; i < N; i++){
        printArray(N, A);

        v = A[i];
        j = i;
        while(v < A[j - 1] && j > 0){
            A[j] = A[j - 1];
            j--;
        }
        A[j] = v;
    }
}



int main(){
    int N;
    scanf("%d", &N);
    int* A;
    A = (int*)malloc(sizeof(A[0]) * N);
    scanArrayInt(N, A);
    insertionSort(N, A);
    printArray(N, A);
    return 0;
}
