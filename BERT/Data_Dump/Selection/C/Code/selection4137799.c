#include <stdio.h>
#include <stdlib.h>

int selectionSort(int A[], int N) {
    int minj, sw = 0;
    int temp;
    int i, j;
    for ( i = 0; i < N - 1; i++ ) {
        minj = i;
        for ( j = i; j < N; j++ ) {
            if (A[j] < A[minj])
                minj = j;
        }
        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        if ( i != minj )
            sw++;
    }

    return sw;
}


int main()
{
    int N, A[100], sw;

    scanf("%d", &N);

    for ( int i = 0; i < N; i++ ) {
        scanf("%d", &A[i]);
    }

    sw = selectionSort(A, N);

    for (int i = 0; i < N; i++ ) {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);

    return 0;
}

