#include <iostream>
#include <stdio.h>

using namespace std;
void insertSort(int a[], int n);
void printOut(int a[], int n);

int main() {
    const int MAX = 100;
    int n, a[MAX];
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printOut(a, n);
    insertSort(a, n);
    return 0;
}

void printOut(int a[], int n) {
    for (int k = 0; k < n; k++) cout << a[k] << (k < n - 1 ? " " : "\n");
}


void insertSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printOut(a, n);
    }
}


