#include <stdio.h>

void disp(int *a, int n) {
    for(int i=0; i<n; i++) {
        printf("%d", a[i]);
        if (i != n-1) putchar(' ');
        else puts("");
    }
}
void isort(int *a, int n) {
    int v, j;
    for (int i=1; i<n; i++) {
        disp(a, n);
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
    }
}

int main() {
    int n, a[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    isort(a, n);
    disp(a, n);
}

