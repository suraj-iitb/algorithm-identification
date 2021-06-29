#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using lint = long int;
using llint = long long int;
using namespace std;

void trace(int *array, int n) {
    rep(i, n) cout << array[i] << ((i != n - 1) ? " " : "\n");
}

void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        trace(array, n);
        int v = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;
    }
}

int main() {
    int n;
    cin >> n;
    int array[n];
    rep(i, n) cin >> array[i];
    insertionSort(array, n);
    trace(array, n);
}


