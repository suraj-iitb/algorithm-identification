#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cout << a[j] << (j < n - 1 ? ' ' : '\n');

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        for (int j = 0; j < n; j++) cout << a[j] << (j < n - 1 ? ' ' : '\n');
    }
}
