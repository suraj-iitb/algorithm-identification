#include <stdio.h>

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B

#define swap(a, b)                                                             \
    a = a + b;                                                                 \
    b = a - b;                                                                 \
    a = a - b;

int main(int argc, char **argv) {
    int n, i, j, a[1024], min, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            swap(a[min], a[i]);
            cnt++;
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
