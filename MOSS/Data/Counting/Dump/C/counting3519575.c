#include <stdio.h>

void countingSort(int A[], int B[], int k, int num) {

    int C[k + 1];
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    // C[i] に i の出現数を記録する。
    for (int i = 0; i < num; i++) {
        C[A[i]]++;
    }

    // C[i] に i 以下の数の出現数を記録する。
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = num - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main() {

    int num;
    scanf("%d", &num);

    int max = 0;
    int A[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &A[i]);
        if (A[i] > max) {
            max = A[i];
        }
    }

    int B[num];
    countingSort(A, B, max, num);

    for (int i = 0; i < num; i++) {
        printf("%d", B[i]);
        if (i == num - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }

    return 0;
}

