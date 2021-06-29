#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int*, int);
void printArray(int*, int);

int main(void) {
    int n, *a, i = 0, count;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    while (i < n) {
        scanf("%d", &a[i]);
        i++;
    }
    count = bubbleSort(a, n);
    printArray(a, n);
    printf("%d\n", count);
    return 0;
}

int bubbleSort(int *a, int n) {
    int j, w, flag = 1, count = 0;
    // flag = 1: ????????£??\????´?????????¨??????
    while (flag) {
        flag = 0;
        for (j = n - 1; j > 0;j--) {
            if (a[j] < a[j - 1]) {
                w = a[j];
                a[j] = a[j - 1];
                a[j - 1] = w;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

void printArray(int *a, int n) {
    int i = 0;
    while (i < n - 1) {
        printf("%d ", a[i]);
        i++;
    }
    printf("%d\n", a[i]);
}
