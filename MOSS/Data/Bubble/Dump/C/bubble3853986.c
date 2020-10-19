#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void printOut(int A[], int N) {
    int i;

    for ( i = 0; i < N; i++ ) {
        printf("%u%s", A[i], i == N -1 ? "" : " ");
    }
    printf("\n");

    return;
}

static int bubbleSort(int A[], int N) {
    int i, j;
    int swap=0;

    for ( i = 0; i < N; i++) {
        for ( j = N - 1; j > i; j-- ) {
            if ( A[j] < A[j-1] ) {
                int t;
                t      = A[j];
                A[j]   = A[j-1];
                A[j-1] = t;
                swap++;
            }
        }
    }

    return swap;
}

int main(int argc, char* argv[]) {
    int ret;
    int i;
    int N;
    int *A;
    int c;

    ret = scanf("%d\n", &N);
    assert( ret == 1 );
    assert( (1 <= N) && N <= 100 );

    A = malloc(sizeof(int) * N);
    assert( A != NULL );

    memset(A, 0x00, sizeof(int) * N);
    i = 0;
    while ( ((ret = fgetc(stdin)) != EOF) && (i < N) ) {
        if ( ret == ' ' ) {
            assert( (0 <= A[i]) && (A[i] <= 1000) );
            i++;
            continue;
        }
        if ( isdigit(ret) ) {
            A[i] = A[i] * 10 + (ret - '0');
            continue;
        }
        break;
    }
    
    c = bubbleSort(A, N);

    printOut(A, N);

    printf("%d\n", c);

    free(A);

    return 0;
}
    
