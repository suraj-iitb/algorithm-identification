#include <stdio.h>

void trace(int A[], int N) {
    int i;
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertion_sort(int A[], int N) {
    int j, i, v;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}


int main(int argc, char const *argv[])
{
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    trace(A, N);
    insertion_sort(A, N);

    return 0;
}

