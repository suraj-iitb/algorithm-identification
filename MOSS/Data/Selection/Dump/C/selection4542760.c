#include<stdio.h>

int selectionSort(int A[], int N) {
    int count = 0, i, j, v;
    for(i = 0; i < N - 1; i++) {
        int minj = i;
        for(j = i; j < N; j++) {
            if(A[minj] > A[j]) minj = j;
        }
        v = A[i];
        A[i] = A[minj];
        A[minj] = v;
        if(i != minj) count++;
    }
    return count;
}

int main() {
    int A[100], N, i, count;
    scanf("%d", &N);
    for(i = 0; i < N; i++) scanf("%d", &A[i]);

    count = selectionSort(A, N);

    for(i = 0; i < N; i++) {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);

    return 0; 
}
