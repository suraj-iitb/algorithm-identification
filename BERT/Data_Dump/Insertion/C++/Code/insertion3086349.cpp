#include <stdio.h>

void print(int A[], int N) {
    for (int k = 0; k < N; k++) {
        if (k > 0) {
            printf(" ");
        }
        printf("%d", A[k]);
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    print(A, N);

    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        print(A, N);
    }
}
