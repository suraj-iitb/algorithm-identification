#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array.at(i);
    bool flg = true;
    int cnt = 0;
    while( flg ) {
        flg = false;
        for(int i = 0; i < n-1; i++) {
            if(array.at(i) > array.at(i+1)) {
                swap(array.at(i), array.at(i+1));
                flg = true;
                cnt++;
            }
        }
    }
    for(int k = 0; k < n-1; k++) cout << array.at(k) << ' ';
    cout << array.at(n-1) << endl;
    cout << cnt << endl;
    return 0;
}

