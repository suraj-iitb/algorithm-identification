#include <stdio.h>

int main () {

    int i, j, mini, N, k, l, m;
    int A[100];

    m = 0;

    scanf("%d", &N);

    for ( i = 0; i < N; i++ )
        scanf("%d", &A[i]);

    for ( i = 0; i < N; i++ ) {
        mini = 101;
        for ( j = i; j < N; j++ ) {
            if ( A[j] < mini ) {
                mini = A[j];
                k = j;
            }
        }
        if ( mini != A[i] ) {
            l = A[i];
            A[i] = A[k];
            A[k] = l;
            m += 1;
        }
    }

    for ( i = 0; i < N - 1; i++ )
        printf("%d ", A[i]);
        printf("%d", A[N - 1]);
        puts("");
        printf("%d\n", m);

    return 0;

}
