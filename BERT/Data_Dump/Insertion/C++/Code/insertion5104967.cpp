#include<iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void insertSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        print(a, n);
    }
}

int main() {
    int n, v, a[101];
    for (int i = 0; i < 101; i++) a[i] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    print(a, n);
    insertSort(a, n);
    return 0;
}
