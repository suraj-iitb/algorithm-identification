#include<stdio.h>

void printresult(int n, int* a) {
    int i;
    for(i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
}

int main(void) {
    int i, j;
    int v = 0, n = 0;
    int a[1000];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printresult(n, a);

    for(i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printresult(n, a);
    }
}

