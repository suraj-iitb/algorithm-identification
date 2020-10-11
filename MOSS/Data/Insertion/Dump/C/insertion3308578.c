/*
 * ID: ALDS1_1_A
 * Problem: Insert sort
 */

#include <stdio.h>

int main(void)
{
    int a[100];
    int n;

    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    for (j = 0; j < n; j++)
        printf("%d%s", a[j], j == n - 1 ? "": " ");
    printf("\n");

    for (i = 1; i < n; i++) {
        int v = a[i];
        for (j = i - 1; j >= 0 && a[j] > v; j--)
            a[j + 1] = a[j];
        a[j + 1] = v;

        for (j = 0; j < n; j++)
            printf("%d%s", a[j], j == n - 1 ? "": " ");
        printf("\n");
    }

    return 0;
}

