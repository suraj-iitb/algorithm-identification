#include <stdio.h>

int main () {

    int i, j, min, N, c, x, m;
    int a[100];

    m = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < N; i++) {
        min = 101;
        for (j = i; j < N; j++) {
            if (a[j] < min) {
                min = a[j];
                c = j;
            }
        }
        if (min != a[i]) {
            x = a[i];
            a[i] = a[c];
            a[c] = x;
            m += 1;
        }
    }

    for (i = 0; i < N - 1; i++)
        printf("%d ", a[i]);
        printf("%d", a[N - 1]);
        puts("");
        printf("%d\n", m);

    return 0;

}

