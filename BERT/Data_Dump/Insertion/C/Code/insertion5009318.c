#include <stdio.h>
int n, a[105], temp;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d", a[i]);
            } else {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
        if (a[i] > a[i + 1]) {
            temp = a[i + 1];
            for (int j = i; j >= 0; j--) {
                if (a[j] > temp) {
                    a[j + 1] = a[j];
                    if (j == 0) {
                        a[j] = temp;
                    }
                } else {
                    a[j + 1] = temp;
                    j = -1;
                }
            }
        }
    }
}

