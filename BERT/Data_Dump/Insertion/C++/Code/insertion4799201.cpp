#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array.at(i);
    for(int k = 0; k < n-1; k++) cout << array.at(k) << ' ';
    cout << array.at(n-1) << endl;
    for(int i = 1; i < n; i++) {
        int v = array.at(i);
        int j = i - 1;
        while( 0 <= j && array.at(j) > v ) {
            swap(array.at(j), array.at(j+1));
            j--;
        } 
        array.at(j+1) = v;
        for(int k = 0; k < n-1; k++) cout << array.at(k) << ' ';
        cout << array.at(n-1) << endl;
    }
    return 0;
}

