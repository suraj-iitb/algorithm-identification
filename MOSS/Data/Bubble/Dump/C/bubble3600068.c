#include <stdio.h>

int bubble_sort(int A[], int N) {
    int key, swap = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = N-1; j >= i+1; --j) {
            if (A[j] < A[j-1]) {
                swap++;
                key = A[j];
                A[j] = A[j-1];
                A[j-1] = key;
            }
        }
    }
    return swap;
}

int main() {
    int N, swap;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    swap = bubble_sort(A, N);
    for (int j = 0; j < N; ++j) {
        if (j > 0) printf(" ");
        printf("%d", A[j]);
    }
    printf("\n");
    printf("%d\n", swap);

    return 0;

}
