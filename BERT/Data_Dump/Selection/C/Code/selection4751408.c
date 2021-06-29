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

int SelectionSort(int a[], int n) {
    int sw = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;  //这里记录的是最小值的下标
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            int tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            sw++;
        }
    }
    return sw;
}

int main() {
    int a[N];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sw = SelectionSort(a, n);
    showArray(a, n);
    printf("%d\n", sw);
    return 0;
}
