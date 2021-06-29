#include <stdio.h>

int search(int A[], int n, int key) {
    int i = 0;
    A[n] = key;
    while (A[i] != key) i++;
    return i != n;
}

int main()
{
    int n, q, i;
    int S[10001], T, ans = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        scanf("%d", &T);
        if (search(S, n, T))
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
