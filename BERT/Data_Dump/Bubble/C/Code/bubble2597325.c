#include "stdio.h"
int main()
{
    int n, a[100], j, x, count, i;
    scanf("%d", &n);

    for (i = 0; i <= n - 1; i++)
        scanf("%d", &a[i]);

    for (i = 0; i<n; i++) {
        for (j = n - 1; j > 0; j--)
            if (a[j] < a[j - 1]) {
                x = a[j];
                a[j] = a[j - 1];
                a[j - 1] = x;
                count++;
            }

    }

    for (i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }

    printf("\n%d\n", count);

    return 0;
}
