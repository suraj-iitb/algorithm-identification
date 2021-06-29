#include <stdio.h>

int selection_sort(int A[], int N) {
    int key, mini, swap = 0;
    for (int i = 0; i < N; ++i) {
        mini = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap++;
            key = A[i];
            A[i] = A[mini];
            A[mini] = key;
        }
    }
    return swap;
}

int main() {
    int N, swap = 0;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    swap = selection_sort(A, N);
    for (int j = 0; j < N; ++j) {
        if (j > 0) printf(" ");
        printf("%d", A[j]);
    }
    printf("\n%d\n", swap);

    return 0;
}
