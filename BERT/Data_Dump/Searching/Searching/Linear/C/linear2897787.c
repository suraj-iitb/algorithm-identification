#include <stdio.h>
#include <stdbool.h>

static bool search(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;

    while (A[i] != key) {
        i++;
    }

    return i != n;
}

int main()
{
    int n;
    int A[10001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int q;
    int sum = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int key;
        scanf("%d", &key);
        if (search(A, n, key))
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
