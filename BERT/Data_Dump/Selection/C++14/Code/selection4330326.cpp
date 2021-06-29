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
    rep(i, n) cin >> a[i];

    int cnt = 0;
    rep(i, n) {
        int min_i = i;
        FOR(j, i, n) {
            if (a[j] < a[min_i]) min_i = j;
        }
        if (i!=min_i) {
            swap(a[i], a[min_i]);
            cnt++;
        }
    }

    rep(i, n) cout << a[i] << ((i<n-1) ? " " : "\n");
    cout << cnt << endl;
}
