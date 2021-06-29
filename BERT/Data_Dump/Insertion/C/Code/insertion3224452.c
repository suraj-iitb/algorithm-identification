#include <stdio.h>
 
int main () {
 
    int N, i, c, j, k, d;
    int a[1000];
    c = 0;
 
    scanf("%d", &N);
 
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
 
    for (i = 1; i <= N; i++) {
        for (j = 0; j < N - 1; j++) {
            printf("%d ", a[j]);
        }

        printf("%d", a[N - 1]);
        puts("");
 
        for (k = 1; i - k >= 0; k++) {
            if (a[i + 1 - k] <= a[i - k]) {
                c = a[i - k];
                d = a[i + 1 - k];
                a[i + 1 - k] = c;
                a[i - k] = d;
            }
        }
 
    }
 
    return 0;
 
}
