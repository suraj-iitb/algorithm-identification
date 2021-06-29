#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
signed main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        for(int j = i; j>0 && a[j-1]>a[j]; j--) swap(a[j], a[j-1]);
        rep(i,n){
            if(i==n-1) cout << a[n-1] << endl;
            else cout << a[i] << " ";
        }
    }
    return 0;
}
