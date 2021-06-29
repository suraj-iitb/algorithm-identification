#include<stdio.h>

void trace(int A[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N) {
    int i;
    for(i = 1; i < N; i++) {
        int t = A[i];
        int j = i - 1;
        while(j >= 0 && t < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = t;
        trace(A, N);
    }
}

int main() {
    int A[100], N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; i++) scanf("%d", &A[i]);

    trace(A, N);
    insertionSort(A, N);

    return 0;
}
