#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        if(i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    for(int i = 1; i < n; ++i){
        int v = a[i], j = i - 1;
        while(j >= 0 && v < a[j]){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = v;
        rep(i, n){
            if(i != 0) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
