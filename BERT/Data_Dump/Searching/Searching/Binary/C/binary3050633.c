#include <stdio.h>

int binarySearch(int [], int, int);

int main(void)
{
    int n, q, S[100000], t, i, C;

    C = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", S + i);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &t);
        if (binarySearch(S, n, t) >= 0)
            C++;
    }

    printf("%d\n", C);
}

int binarySearch(int arr[], int size, int x)
{
    int low, mid, high;

    low = 0, high = size;

    while (low < high) {
        mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }

    return -1;
}
