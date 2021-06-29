#include<stdio.h>

int main() {
    int n;
    int a[1010];
    int i, j, minj;
    int tmp, cnt = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        minj = i;
        for(j = i + 1; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (minj != i) cnt++;
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
    }

    for(j = 0; j < n; j++) {
        printf("%d%c", a[j], ((j == n - 1) ? '\n' : ' '));
    }
    printf("%d\n", cnt);
    return 0;
}
