#include <stdio.h>

int A[10000000], n;

int binary (int key) {
    int mid;
    int left = 0;
    int right = n;
    while (left < right) {
        mid = (right + left) / 2;
        if ( key == A[mid]) return 1;
        if ( key > A[mid]) left = mid + 1;
        else if (key < A[mid]) right = mid;
    }
    return 0;
}

int main () {
    int i;
    int q, k;
    int sum = 0;

    scanf("%d",&n);
    for ( i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }

    scanf("%d",&q);
    for ( i = 0; i < q; i++) {
        scanf("%d",&k);
        if (binary(k)) sum++;
    }
    printf("%d\n",sum);
    return 0;
}

