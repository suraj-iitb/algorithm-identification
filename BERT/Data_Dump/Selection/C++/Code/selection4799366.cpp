#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array.at(i);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int minj = i;
        for( int j = i + 1; j < n; j++ ) {
            if( array.at(j) < array.at(minj)) {
                minj = j;
            }
        }
        if( minj != i ) {
            swap(array.at(minj), array.at(i));
            cnt++;
        }
    }
    for(int k = 0; k < n-1; k++) cout << array.at(k) << ' ';
    cout << array.at(n-1) << endl;
    cout << cnt << endl;
    return 0;
}

