#include <cstdio>
using namespace std;

void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < n - 1; k++) {
            printf("%d%s", a[k], " ");
        }
        printf("%d", a[n - 1]);
        printf("\n");
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
    for (int k = 0; k < n - 1; k++) {
        printf("%d%s", a[k], " ");
    }
    printf("%d", a[n - 1]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    delete[] a;
    return 0;
}
