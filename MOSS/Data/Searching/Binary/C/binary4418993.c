#include <stdio.h>

int binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;

    while ( left < right ) {
        mid = (left + right) / 2;
        if ( A[mid] == key ) {
            return 1;
        } else if ( key < A[mid] ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main(void)
{
    int n;
    int q;
    int S[100000];
    int T[50000];
    int C = 0;

    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    for ( int i = 0; i < q; i++ ) {
        scanf("%d", &T[i]);
    }

    for ( int i = 0; i < q; i++ ) {
        C += binarySearch(S, n, T[i]);        
    }

    printf("%d\n", C);

    return 0;
}
