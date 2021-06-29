#include <stdio.h>

int main () {

    int i, j, n, q, c, left, right, mid;
    int a[100000], b[50000];

    c = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);

    for (i = 0; i < q; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < q; i++) {
        left = 0; right = n;
        for (; left < right; ) {
            mid = (left + right) / 2;
            if (b[i] == a[mid]) {
                c += 1;
                break;
            } else if (b[i] < a[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    printf("%d\n", c);

    return 0;

}

