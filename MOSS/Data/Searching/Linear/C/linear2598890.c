#include<stdio.h>
int main(void){
    int n, S[10000], q, flag = 1, T[10000], i, count = 0, key, j, Q, N;
    scanf("%d", &n);
    i = 0;
    N = n;
    while ( n-- ) {
        scanf("%d", &S[i]);
        i++;
    }
    scanf("%d ", &q);
    Q = q;
    i = 0;
    while ( q-- ) {
        scanf("%d", &T[i]);
        i++;
    }
    while ( flag == 1) {
        flag = 0;
        for ( j = n - 1; j >= 1; j-- ) {
            if ( S[j] < S[j - 1] ) {
                key = S[j];
                S[j] = S[j - 1];
                S[j - 1] = key;
                flag = 1;
            }
        }
    }
    for ( i = 0; i < Q; i++ ) {
        for ( j = 0; j < N; j++ ) {
            if ( S[j] == T[i]) break;
        }
        if ( j < N ) count++;
    }
    printf("%d\n", count);
}
