#include<stdio.h>

int main() {
    int n;
    int a[1010];
    int i, j, v;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        printf("%d%c", a[i], ((i == n - 1) ? '\n' : ' '));
    }

    for(i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for(j = 0; j < n; j++) {
            printf("%d%c", a[j], ((j == n - 1) ? '\n' : ' '));
        }
    }

    return 0;
}
