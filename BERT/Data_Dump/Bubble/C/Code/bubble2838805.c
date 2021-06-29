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

void bubbleSort(int N, int* A, int* count){
    int flag = 1;
    int i, v;
    while(flag){
        flag = 0;
        for(i = N - 1; i > 0; i--){
            if(A[i] < A[i - 1]){
                v = A[i];
                A[i] = A[i - 1];
                A[i - 1] = v;
                flag = 1;
                *count = *count + 1;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int* A;
    A = (int*)malloc(sizeof(A[0]) * N);
    scanArrayInt(N, A);
    int i = 0;
    int* count = &i;
    bubbleSort(N, A, count);
    printArray(N, A);
    printf("%d\n", *count);
    return 0;
}
