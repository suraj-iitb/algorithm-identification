#include <stdio.h>

void trace(int A[], int N) {
    for (int j = 0; j < N; ++j) {
        if (j > 0) printf(" ");
        printf("%d", A[j]);
    }
    printf("\n");
}

void insertion_sort(int A[], int N) {
    int key, j;
    for (int i = 0; i < N; ++i) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        trace(A, N);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    insertion_sort(A, N);

    return 0;
}


