#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int A[], int n, int key) {
    int left = 0;
    int right = n;

    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if (A[mid] == key) {
            return 1;
        } else if (key < A[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main(void)
{
    int n, q, i, count;
    int S[100000] = {};
    int T[50000] = {};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    count = 0;
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
        if (binarySearch(S, n, T[i])) count++; 
    }
    
    printf("%d\n", count);

    return 0;
}
