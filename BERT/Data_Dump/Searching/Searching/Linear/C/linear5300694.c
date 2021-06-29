#include <stdio.h>

int A[10000], n;

int search(int key) {
    A[n] = key;
    int i;
    for(i = 0; i <= n; i++) {
        if(A[i] == key) break;
    }
    if(i == n) return 0;
    return 1;
}

int main(void) {
    int i, q, key, sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &key);
        sum += search(key);
    }

    printf("%d\n", sum);

    return 0;
}
