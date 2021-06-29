#include <stdio.h>

void printArray(int A[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}

void insertionSort(int A[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
    }
}

int main(void) {
    int i;
    int N; // 入力数
    int A[100]; // ソートする配列
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", A + i);
    printArray(A, N);
    insertionSort(A, N);
    return 0;
}

