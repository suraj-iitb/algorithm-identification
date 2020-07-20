#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int bubbleSort(int a[], int n) {
    int sw = 0;
    bool flag = 1;
    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = n-1; j >= i+1; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = 1;
                sw++;
            }
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

    int sw = bubbleSort(a, n);

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
