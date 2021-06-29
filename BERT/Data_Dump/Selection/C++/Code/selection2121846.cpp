#include<bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
    int i, j, minj, sw = 0;
    for ( i = 0; i < N - 1; i++ ) {
        minj = i;
        for ( j = i; j < N; j++ ) {
            if ( A[j] < A[minj]) {
                minj = j;
            }
        }
        if ( i != minj ) {
            swap(A[i], A[minj]);
            sw++;
        }
    }
    return sw;
}

main() {
    int A[100], N, i, sw;

    scanf("%d", &N);
    for ( i = 0; i < N; i++ ) {
        scanf("%d", &A[i]);
    }

    sw = selectionSort(A, N);

    for ( i = 0; i < N; i++ ) {
        if ( i != 0 ) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);

}
