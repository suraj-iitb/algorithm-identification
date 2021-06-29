/**
*    created: 10.05.2020 15:23:34
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int mx = 2000000;
    int c[mx];
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) c[a[i]]++;
    int sum = 0;
    rep(i,mx) {
        sum += c[i];
        c[i] = sum;
    }
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    rep(i,n) {
        if (i == 0) cout << b[0];
        else cout << " " << b[i];
    }
    cout << endl;
    return 0;
}

