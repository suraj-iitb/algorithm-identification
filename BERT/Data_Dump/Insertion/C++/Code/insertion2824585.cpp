#include <iostream>
using namespace std;

static const int N = 100;

void trace(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

int insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        trace(a, n);
    }
}

int main() {
    int a[N], n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    trace(a, n);
    insertionSort(a, n);
    return 0;
}

