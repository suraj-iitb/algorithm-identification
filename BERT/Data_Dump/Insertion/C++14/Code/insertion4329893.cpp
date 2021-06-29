#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(j, n) cout << a[j] << ((j<n-1) ? " " : "");
    cout << endl;

    FOR(i, 1, n) {
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        rep(j, n) cout << a[j] << ((j<n-1) ? " " : "");
        cout << endl;
    }
}
