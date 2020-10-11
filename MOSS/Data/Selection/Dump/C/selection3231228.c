#include <stdio.h>

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}

int selectionSort(int A[], int N) {
    int i, j, minj, count;
    count = 0;
    for (i = 0; i < N - 1; i++) {
        minj = i;
        for (j = i + 1; j <  N; j++) {
            if (A[minj] > A[j]) minj = j;
        }
        if (minj != i) {
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
    }
    return count;
}

int main(void) {
    int i;
    int N; // 入力数
    int A[100]; // ソートする配列
    int count;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", A + i);
    count = selectionSort(A, N);
    trace(A, N);
    printf("%d\n", count);
    return 0;
}

