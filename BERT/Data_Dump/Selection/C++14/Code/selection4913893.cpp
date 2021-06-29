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
    int cnt = 0;
    rep(i, n){
        int minj = i;
        for(int j = i; j < n; ++j){
            if(a[minj] > a[j]) minj = j;
        }
        if(i != minj){
            ++cnt;
            swap(a[i], a[minj]);
        }
    }
    rep(i, n){
        if(i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl << cnt << endl;
    return 0;
}
