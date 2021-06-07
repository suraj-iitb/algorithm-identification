#include <stdio.h>

int A[100000], n;

int binarySearch(int key) {
    int left = 0, right = n;
    int mid;
    while (left < right) {
        mid = (left + right ) / 2;
        if ( A[mid] == key ) {
            return mid;
        } else if ( key < A[mid] ) {
            right = mid;
        } else {
            left = mid + 1;
        }
        
    }
    return 0;
}

int main (void) {
    int i , j , q , k , sum = 0;

    scanf("%d", &n );
    for (i = 0 ; i <  n ; i++ ) {
        scanf("%d", &A[i] );
    }

    scanf("%d", &q );
    for (j = 0; j < q ; j ++ ) {
        scanf("%d", &k );
        if ( binarySearch( k )) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
