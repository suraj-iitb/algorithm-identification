#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>i; j--) {
            if(a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << (i != n-1 ? " " : "\n");
    }
    cout << cnt << endl;

    return 0;
}

