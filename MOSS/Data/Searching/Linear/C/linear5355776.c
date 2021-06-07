#include <stdio.h>

int main ()
{
    int count = 0, n, q, i, j;

    scanf ("%d", &n);
    int s [n];
    for (i = 0; i < n; i++) {
        scanf ("%d", &s [i]);
    }
    scanf ("%d", &q);
    int t [q];
    for (j = 0; j < q; j++) {
        scanf ("%d", &t [j]);
    }

    for (j = 0; j < q; j++) {
        for (i = 0; i < n; i++) {
            if (t [j] == s [i]) {
                count++;
                break;
            }
        }
    }
    printf ("%d\n", count);

    return 0;
}

