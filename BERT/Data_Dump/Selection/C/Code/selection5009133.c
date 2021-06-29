#include <stdio.h>
int n, a[105], sps = 0, temp, min, minpos;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        min = 999;
        minpos = 999;
        for (int j = i; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                minpos = j;
            }
        }
        if (minpos != i) {
            temp = a[i];
            a[i] = a[minpos];
            a[minpos] = temp;
            sps++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n%d\n", sps);
}

