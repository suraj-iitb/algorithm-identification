#include <stdio.h>

int binarySearch(int A[], int n, int key)
{
    int left = 0, right = n, mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] == key)  return mid;
        if (key < A[mid])   right = mid;
        else                left = mid + 1;
    }

    return 0;
}

int main()
{
    int i, n, A[100000], q, key, sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        if (binarySearch(A, n, key)) sum++;
    }

    printf("%d\n", sum);

    return 0;
}
