#include <stdio.h>

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) printf("%d ", A[i]);
    printf("%d\n", A[N-1]);
}

int bubbleSort(int A[], int N) {
    int i, j, flag, count;
    i = 0; // 整列済み部分の末尾のインデックス
    count = 0; // 交換回数
    flag = 1;
    while (flag) {
        flag = 0;
        for (j = N - 1; j > i; j--) {
            if (A[j-1] > A[j]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
        i++;
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
    count = bubbleSort(A, N);
    trace(A, N);
    printf("%d\n", count);
    return 0;
}

