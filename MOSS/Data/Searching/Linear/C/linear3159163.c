#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int A[], int n, int key) {
    int i = 0;
    A[n] = key;  // 番兵を置く
    while (A[i] != key) i++;
    return i != n;
}

int main(void)
{
    int n, q, i, count;
    int S[10000] = {};
    int T[500] = {};

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    count = 0;
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
        if (linearSearch(S, n, T[i])) count++; 
    }
    
    printf("%d\n", count);

    return 0;
}
