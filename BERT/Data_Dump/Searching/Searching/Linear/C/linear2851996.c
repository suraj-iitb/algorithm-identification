#include <stdio.h>

int search(int A[], int n, int key) {
    A[n] = key;
    int i = 0;
    while (A[i] != key) i++;
    return i != n;
}


int main(int argc, char const *argv[])
{
    int key, n, q, A[10000 + 1], sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        if (search(A, n, key)) {
            sum++;
        }
    }

    printf("%d\n", sum);

    return 0;
}


