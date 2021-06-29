#include <stdio.h>

static void PrintArray(int A[], int N) {
    int i;

    for ( i = 0; i < N; i++ ) {
        printf("%d", A[i]);

        if ( i < N - 1 ) {
            printf(" ");
        }
    }
    printf("\n");

    return;
}

static void InsersionSort(int A[], int N) {
    int i;

    for ( i = 1; i < N; i++ ) {
        int v = A[i];
        int j = i - 1;

        while ( (j >= 0) && (A[j] > v) ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        PrintArray(A, N);
    }

    return;
}

int main(int argc, char* argv[]) {
    int N;
    int A[1000];
    int i;

    fscanf(stdin, "%d\n", &N);
    for ( i = 0; i < N; i++ ) {
        fscanf(stdin, "%d", &A[i]);
    }

    PrintArray(A, N);

    InsersionSort(A, N);

    return 0;
}

