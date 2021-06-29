#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
signed main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int cnt = 0;
    rep(i,n){
        int mn = i;
        rep2(j,i,n){
            if(a[j] < a[mn]) mn = j;
        }
        if (i != mn){
            swap(a[i], a[mn]);
            cnt++;
        }
    }
    rep(i,n){
        if(i == n-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    cout << cnt << endl;
    return 0;
}
