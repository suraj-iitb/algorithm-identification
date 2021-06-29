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
    for (int i = 0; i < n-1; i++){
        for (int j = n-1; j > i; j--){
            if(a[j-1] > a[j]){
                swap(a[j],a[j-1]);
                cnt++;
            }
        }
    }
    rep(i,n){
        if (i == n-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    cout << cnt << endl;
    return 0;
}
