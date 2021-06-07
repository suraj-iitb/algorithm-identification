#include<stdio.h>

int LinearSearch(int A[], int n, int k) {
    A[n] = k;
    int i = 0;
    while (A[i] != k)
        i++;

    return i != n;
}
int main() {
    int n, q, k;
    int sum = 0;
    int A[10010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (LinearSearch(A, n, k))
            sum++;
    }
    printf("%d\n", sum);
}
