#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

void trace(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
}

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
    }

    trace(a, n);
    insertionSort(a, n);

    return 0;
}
