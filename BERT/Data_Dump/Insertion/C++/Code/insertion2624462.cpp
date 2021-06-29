#include <iostream>

using namespace std;

int insertionSort(int a[1000], int n) {
    for (int i = 0; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        for (int u = 0; u < n; u++) {
            if (u == n - 1) {
                cout << a[u];
            } else {
                cout << a[u] << " ";
            }
        }
        cout << endl;
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
}
