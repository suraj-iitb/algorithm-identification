#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int selectionSort(int a[], int n) {
    int i, j, minj, t, sw = 0;
    for(i = 0; i < n-1; i++) {
        minj = i;
        for(j = i; j < n; j++) {
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        t = a[i];
        a[i] = a[minj];
        a[minj] = t;
        if(i != minj) {
            sw++;
        }
    } 
    
    return sw;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
    }

    int sw = selectionSort(a, n);

    rep(i, n) {
        if(i) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    
    cout << sw << endl;

    return 0;
}
