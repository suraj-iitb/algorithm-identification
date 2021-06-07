#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) {
            return true;
        } else if (key > A[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return false;
}

int main()
{
    int n, q, t;
    int A[100000];
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        if (binarySearch(A, n, t)) {
            sum++;
        }
    }

    printf("%d\n", sum);
    return 0;
}
