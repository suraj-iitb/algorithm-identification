#include<stdio.h>

void print(int a[],int n) {
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}

void insertsort(int a[], int n) {

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = a[i];
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        print(a, n);
    }
}
int main() {
    int n, a[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    print(a, n);
    insertsort(a, n);
    return 0;
}
