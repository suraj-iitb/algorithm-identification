#include <stdio.h>

int a[105];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
        for (int j = 0; j < n; j++) {
            printf("%d", a[j]);
            if (j == n - 1) printf("\n");
            else printf(" ");
        }
    }
}
