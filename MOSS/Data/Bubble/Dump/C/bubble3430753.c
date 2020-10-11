#include <stdio.h>

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A

#define swap(x, y)                                                             \
    x = x + y;                                                                 \
    y = x - y;                                                                 \
    x = x - y;

int main(int argc, char **argv) {
    int n, a[1024], i, j, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        // printf("%d\n", a[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                cnt++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i == n - 1)
            printf("\n");
        else
            printf(" ");
    }
    printf("%d\n", cnt);
    return 0;
}
