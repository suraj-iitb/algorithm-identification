#include "bits/stdc++.h"

using namespace std;

void trace(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void bubbleSort(int a[], int n) {
    int count = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i- 1] = tmp;
                flag = true;
                count++;
            }
        }
    }
    trace(a, n);
    cout << count << endl;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bubbleSort(a, n);

    return 0;
}
