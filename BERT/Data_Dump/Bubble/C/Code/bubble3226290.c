#include <stdio.h>

int main () {

    int i, j, c, N, t;
    int a[100];

    t = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < N; i++) {
        for (j = N - 1; j > 0; j--) {
             if (a[j] < a[j - 1]) {
                 c = a[j];
                 a[j] = a[j - 1];
                 a[j - 1] = c;
                 t += 1;
             }
        }
    }

    for (i = 0; i < N - 1; i++) 
        printf("%d ", a[i]);
        printf("%d", a[N - 1]);
        puts("");
        printf("%d\n", t);

    return 0;

}
