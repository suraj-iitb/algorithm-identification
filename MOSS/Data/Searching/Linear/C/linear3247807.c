#include <stdio.h>

int main () {

    int i, j, n, q, c;
    int a[10000], b[500];

    c = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);

    for (i = 0; i < q; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < q; i++) {
        for (j = 0; j < n; j++) {
            if (a[j] == b[i]) {
                c += 1;
                break;
            }
        }
    }

    printf("%d\n", c);

    return 0;

}

