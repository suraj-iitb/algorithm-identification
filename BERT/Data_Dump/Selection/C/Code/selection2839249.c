#include<stdio.h>
#include<stdlib.h>

//int型ポインタAのメモリ領域をN個確保し，int型の数をN個読み込みAを返す
int* scanArrayInt(int N){
    int* A;
    A = (int*)malloc(sizeof(A[0]) * N);
    int i;
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    return A;
}

//長さNの配列Aを，行末の空白はなし，改行ありで出力．
void printArray(int N, int* A){
    int i;
    for(i = 0; i < N - 1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N - 1]);
}

int selectionSort(int N, int* A){
    int i, j, v;
    int count = 0;
    for(i = 0; i < N - 1; i++){
        int minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[minj] < A[i]){
            v = A[i];
            A[i] = A[minj];
            A[minj] = v;
            count++;   
        }
    }
    return count;
}

int main(){
    int N;
    scanf("%d", &N);
    int* A = scanArrayInt(N);
    int count = selectionSort(N, A);
    printArray(N, A);
    printf("%d\n", count);
    return 0;
}
