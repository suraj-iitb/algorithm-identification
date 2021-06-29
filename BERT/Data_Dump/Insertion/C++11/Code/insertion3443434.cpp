#include <iostream>

using namespace std;

void trace(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        trace(a, n);
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

int main() {
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    trace(a, n);
    return 0;
}

