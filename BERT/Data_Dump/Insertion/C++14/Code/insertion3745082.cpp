#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;

    for(int i=0; i<n; i++) {
        for(int j=i; j >= 1 && a[j-1] > a[j]; j--) {
            swap(a[j-1], a[j]);
        }
        
        for(int j=0; j<n; j++) {
            cout << a[j] << (j != n-1 ? " " : "\n");
        }
    }

    return 0;
}

