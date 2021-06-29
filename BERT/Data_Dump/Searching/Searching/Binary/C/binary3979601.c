#include <stdio.h>


static int binarysearch(const int S[], int lo, int hi, int t) {
    int mid = (hi + lo) / 2;

    if ( hi == lo ) {
        return 0;
    }

    if ( t == S[mid] ) {
        return 1;
    }
    if ( t < S[mid] ) {
        return binarysearch(S, lo, mid, t);
    } else {
        return binarysearch(S, mid+1, hi, t);
    }
}


int main(int argc, char* argv[]) {
    int n, q, i;
    int S[100000+1];
    int T[50000+1];
    int c = 0;

    scanf("%d\n", &n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &S[i]);
    }

    scanf("%d\n", &q);
    for ( i = 0; i < q; i++ ) {
        scanf("%d", &T[i]);
    }

    for ( i = 0; i < q; i++ ) {
        c += binarysearch(S, 0, n, T[i]);
    }

    printf("%d\n", c);

    return 0;
}

