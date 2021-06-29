#define N 105
#include <stdio.h>

void showArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

int bubbleSort(int a [], int n) {
    int flag = 1;
    int times = 0;
    while (flag) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (a[i - 1] > a[i]) {
                int tmp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = tmp;
                times++;
                flag = 1;
            }
        }
    }
    return times;
}

int main() {
    int a[N];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int times = bubbleSort(a, n);
    showArray(a, n);
    printf("%d\n", times);
    return 0;
}
